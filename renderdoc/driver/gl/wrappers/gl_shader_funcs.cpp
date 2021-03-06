/******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014 Crytek
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

#include "common/common.h"
#include "serialise/string_utils.h"

#include "../gl_driver.h"
#include "../gl_shader_refl.h"

#pragma region Shaders

bool WrappedOpenGL::Serialise_glCreateShader(GLuint shader, GLenum type)
{
	SERIALISE_ELEMENT(GLenum, Type, type);
	SERIALISE_ELEMENT(ResourceId, id, GetResourceManager()->GetID(ShaderRes(GetCtx(), shader)));

	if(m_State == READING)
	{
		GLuint real = m_Real.glCreateShader(Type);
		
		GLResource res = ShaderRes(GetCtx(), real);

		ResourceId liveId = GetResourceManager()->RegisterResource(res);

		m_Shaders[liveId].type = Type;

		GetResourceManager()->AddLiveResource(id, res);
	}

	return true;
}

GLuint WrappedOpenGL::glCreateShader(GLenum type)
{
	GLuint real = m_Real.glCreateShader(type);

	GLResource res = ShaderRes(GetCtx(), real);
	ResourceId id = GetResourceManager()->RegisterResource(res);

	if(m_State >= WRITING)
	{
		Chunk *chunk = NULL;

		{
			SCOPED_SERIALISE_CONTEXT(CREATE_SHADER);
			Serialise_glCreateShader(real, type);

			chunk = scope.Get();
		}

		GLResourceRecord *record = GetResourceManager()->AddResourceRecord(id);
		RDCASSERT(record);

		record->AddChunk(chunk);
	}
	else
	{
		GetResourceManager()->AddLiveResource(id, res);
	}

	return real;
}

bool WrappedOpenGL::Serialise_glShaderSource(GLuint shader, GLsizei count, const GLchar* const *source, const GLint *length)
{
	SERIALISE_ELEMENT(ResourceId, id, GetResourceManager()->GetID(ShaderRes(GetCtx(), shader)));
	SERIALISE_ELEMENT(uint32_t, Count, count);

	vector<string> srcs;

	for(uint32_t i=0; i < Count; i++)
	{
		string s;
		if(source)
			s = length ? string(source[i], source[i] + length[i]) : string(source[i]);
		
		m_pSerialiser->SerialiseString("source", s);

		if(m_State == READING)
			srcs.push_back(s);
	}
	
	if(m_State == READING)
	{
		size_t numStrings = srcs.size();

		const char **strings = new const char*[numStrings];
		for(size_t i=0; i < numStrings; i++)
			strings[i] = srcs[i].c_str();

		ResourceId liveId = GetResourceManager()->GetLiveID(id);

		m_Shaders[liveId].sources.clear();
		m_Shaders[liveId].sources.reserve(Count);

		for(uint32_t i=0; i < Count; i++)
			m_Shaders[liveId].sources.push_back(strings[i]);

		m_Real.glShaderSource(GetResourceManager()->GetLiveResource(id).name, Count, strings, NULL);
	}

	return true;
}

void WrappedOpenGL::glShaderSource(GLuint shader, GLsizei count, const GLchar* const *string, const GLint *length)
{
	m_Real.glShaderSource(shader, count, string, length);
	
	if(m_State >= WRITING)
	{
		GLResourceRecord *record = GetResourceManager()->GetResourceRecord(ShaderRes(GetCtx(), shader));
		RDCASSERT(record);
		{
			SCOPED_SERIALISE_CONTEXT(SHADERSOURCE);
			Serialise_glShaderSource(shader, count, string, length);

			record->AddChunk(scope.Get());
		}
	}
}

bool WrappedOpenGL::Serialise_glCompileShader(GLuint shader)
{
	SERIALISE_ELEMENT(ResourceId, id, GetResourceManager()->GetID(ShaderRes(GetCtx(), shader)));
	
	if(m_State == READING)
	{
		ResourceId liveId = GetResourceManager()->GetLiveID(id);

		auto &shadDetails = m_Shaders[liveId];

		GLuint sepProg = MakeSeparableShaderProgram(m_Real, shadDetails.type, shadDetails.sources);

		if(sepProg == 0)
		{
			RDCERR("Couldn't make separable program for shader via patching - functionality will be broken.");
		}
		else
		{
			shadDetails.prog = sepProg;
			MakeShaderReflection(m_Real, shadDetails.type, sepProg, shadDetails.reflection);
			
			create_array_uninit(shadDetails.reflection.DebugInfo.files, shadDetails.sources.size());
			for(size_t i=0; i < shadDetails.sources.size(); i++)
			{
				shadDetails.reflection.DebugInfo.files[i].first = StringFormat::Fmt("source%u.glsl", (uint32_t)i);
				shadDetails.reflection.DebugInfo.files[i].second = shadDetails.sources[i];
			}
		}

		m_Real.glCompileShader(GetResourceManager()->GetLiveResource(id).name);
	}

	return true;
}

void WrappedOpenGL::glCompileShader(GLuint shader)
{
	m_Real.glCompileShader(shader);
	
	if(m_State >= WRITING)
	{
		GLResourceRecord *record = GetResourceManager()->GetResourceRecord(ShaderRes(GetCtx(), shader));
		RDCASSERT(record);
		{
			SCOPED_SERIALISE_CONTEXT(COMPILESHADER);
			Serialise_glCompileShader(shader);

			record->AddChunk(scope.Get());
		}
	}
}

void WrappedOpenGL::glReleaseShaderCompiler()
{
	m_Real.glReleaseShaderCompiler();
}

void WrappedOpenGL::glDeleteShader(GLuint shader)
{
	m_Real.glDeleteShader(shader);
	
	GLResource res = ShaderRes(GetCtx(), shader);
	if(GetResourceManager()->HasCurrentResource(res))
	{
		if(GetResourceManager()->HasResourceRecord(res))
				GetResourceManager()->GetResourceRecord(res)->Delete(GetResourceManager());
		GetResourceManager()->UnregisterResource(res);
	}
}

bool WrappedOpenGL::Serialise_glAttachShader(GLuint program, GLuint shader)
{
	SERIALISE_ELEMENT(ResourceId, progid, GetResourceManager()->GetID(ProgramRes(GetCtx(), program)));
	SERIALISE_ELEMENT(ResourceId, shadid, GetResourceManager()->GetID(ShaderRes(GetCtx(), shader)));

	if(m_State == READING)
	{
		ResourceId liveProgId = GetResourceManager()->GetLiveID(progid);
		ResourceId liveShadId = GetResourceManager()->GetLiveID(shadid);

		m_Programs[liveProgId].shaders.push_back(liveShadId);
		
		m_Real.glAttachShader(GetResourceManager()->GetLiveResource(progid).name,
								GetResourceManager()->GetLiveResource(shadid).name);
	}

	return true;
}

void WrappedOpenGL::glAttachShader(GLuint program, GLuint shader)
{
	m_Real.glAttachShader(program, shader);
	
	if(m_State >= WRITING && program != 0 && shader != 0)
	{
		GLResourceRecord *progRecord = GetResourceManager()->GetResourceRecord(ProgramRes(GetCtx(), program));
		GLResourceRecord *shadRecord = GetResourceManager()->GetResourceRecord(ShaderRes(GetCtx(), shader));
		RDCASSERT(progRecord && shadRecord);
		{
			SCOPED_SERIALISE_CONTEXT(ATTACHSHADER);
			Serialise_glAttachShader(program, shader);

			progRecord->AddParent(shadRecord);
			progRecord->AddChunk(scope.Get());
		}
	}
}

bool WrappedOpenGL::Serialise_glDetachShader(GLuint program, GLuint shader)
{
	SERIALISE_ELEMENT(ResourceId, progid, GetResourceManager()->GetID(ProgramRes(GetCtx(), program)));
	SERIALISE_ELEMENT(ResourceId, shadid, GetResourceManager()->GetID(ShaderRes(GetCtx(), shader)));

	if(m_State == READING)
	{
		ResourceId liveProgId = GetResourceManager()->GetLiveID(progid);
		ResourceId liveShadId = GetResourceManager()->GetLiveID(shadid);

		if(!m_Programs[liveProgId].linked)
		{
			for(auto it = m_Programs[liveProgId].shaders.begin();
				   it != m_Programs[liveProgId].shaders.end(); ++it)
			{
				if(*it == liveShadId)
				{
					m_Programs[liveProgId].shaders.erase(it);
					break;
				}
			}
		}
		
		m_Real.glDetachShader(GetResourceManager()->GetLiveResource(progid).name,
								GetResourceManager()->GetLiveResource(shadid).name);
	}

	return true;
}

void WrappedOpenGL::glDetachShader(GLuint program, GLuint shader)
{
	m_Real.glDetachShader(program, shader);
	
	// check that shader still exists, it might have been deleted. If it has, it's not too important
	// that we detach the shader (only important if the program will attach it elsewhere).
	if(m_State >= WRITING && program != 0 && shader != 0 && GetResourceManager()->HasCurrentResource(ShaderRes(GetCtx(), shader)))
	{
		GLResourceRecord *progRecord = GetResourceManager()->GetResourceRecord(ProgramRes(GetCtx(), program));
		RDCASSERT(progRecord);
		{
			SCOPED_SERIALISE_CONTEXT(DETACHSHADER);
			Serialise_glDetachShader(program, shader);

			progRecord->AddChunk(scope.Get());
		}
	}
}

#pragma endregion

#pragma region Programs

bool WrappedOpenGL::Serialise_glCreateShaderProgramv(GLuint program, GLenum type, GLsizei count, const GLchar *const*strings)
{
	SERIALISE_ELEMENT(GLenum, Type, type);
	SERIALISE_ELEMENT(int32_t, Count, count);
	SERIALISE_ELEMENT(ResourceId, id, GetResourceManager()->GetID(ProgramRes(GetCtx(), program)));

	vector<string> src;

	for(int32_t i=0; i < Count; i++)
	{
		string s;
		if(m_State >= WRITING) s = strings[i];
		m_pSerialiser->SerialiseString("Source", s);
		if(m_State < WRITING) src.push_back(s);
	}

	if(m_State == READING)
	{
		char **sources = new char*[Count];
		
		for(int32_t i=0; i < Count; i++)
			sources[i] = &src[i][0];

		GLuint real = m_Real.glCreateShaderProgramv(Type, Count, sources);

		delete[] sources;
		
		GLResource res = ProgramRes(GetCtx(), real);

		ResourceId liveId = m_ResourceManager->RegisterResource(res);
	
		auto &progDetails = m_Programs[liveId];
	
		progDetails.linked = true;
		progDetails.shaders.push_back(liveId);

		auto &shadDetails = m_Shaders[liveId];

		shadDetails.type = Type;
		shadDetails.sources.swap(src);
		shadDetails.prog = real;
		MakeShaderReflection(m_Real, Type, real, shadDetails.reflection);

		create_array_uninit(shadDetails.reflection.DebugInfo.files, shadDetails.sources.size());
		for(size_t i=0; i < shadDetails.sources.size(); i++)
		{
			shadDetails.reflection.DebugInfo.files[i].first = StringFormat::Fmt("source%u.glsl", (uint32_t)i);
			shadDetails.reflection.DebugInfo.files[i].second = shadDetails.sources[i];
		}

		GetResourceManager()->AddLiveResource(id, res);
	}

	return true;
}

GLuint WrappedOpenGL::glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const*strings)
{
	GLuint real = m_Real.glCreateShaderProgramv(type, count, strings);
	
	GLResource res = ProgramRes(GetCtx(), real);
	ResourceId id = GetResourceManager()->RegisterResource(res);
		
	if(m_State >= WRITING)
	{
		Chunk *chunk = NULL;

		{
			SCOPED_SERIALISE_CONTEXT(CREATE_SHADERPROGRAM);
			Serialise_glCreateShaderProgramv(real, type, count, strings);

			chunk = scope.Get();
		}

		GLResourceRecord *record = GetResourceManager()->AddResourceRecord(id);
		RDCASSERT(record);

		// we always want to mark programs as dirty so we can serialise their
		// locations as initial state (and form a remapping table)
		GetResourceManager()->MarkDirtyResource(id);

		record->AddChunk(chunk);
	}
	else
	{
		GetResourceManager()->AddLiveResource(id, res);
	}

	return real;
}

bool WrappedOpenGL::Serialise_glCreateProgram(GLuint program)
{
	SERIALISE_ELEMENT(ResourceId, id, GetResourceManager()->GetID(ProgramRes(GetCtx(), program)));

	if(m_State == READING)
	{
		GLuint real = m_Real.glCreateProgram();
		
		GLResource res = ProgramRes(GetCtx(), real);

		ResourceId liveId = m_ResourceManager->RegisterResource(res);
		
		m_Programs[liveId].linked = false;

		GetResourceManager()->AddLiveResource(id, res);
	}

	return true;
}

GLuint WrappedOpenGL::glCreateProgram()
{
	GLuint real = m_Real.glCreateProgram();
	
	GLResource res = ProgramRes(GetCtx(), real);
	ResourceId id = GetResourceManager()->RegisterResource(res);
		
	if(m_State >= WRITING)
	{
		Chunk *chunk = NULL;

		{
			SCOPED_SERIALISE_CONTEXT(CREATE_PROGRAM);
			Serialise_glCreateProgram(real);

			chunk = scope.Get();
		}

		GLResourceRecord *record = GetResourceManager()->AddResourceRecord(id);
		RDCASSERT(record);
		
		// we always want to mark programs as dirty so we can serialise their
		// locations as initial state (and form a remapping table)
		GetResourceManager()->MarkDirtyResource(id);

		record->AddChunk(chunk);
	}
	else
	{
		GetResourceManager()->AddLiveResource(id, res);
	}

	return real;
}

bool WrappedOpenGL::Serialise_glLinkProgram(GLuint program)
{
	SERIALISE_ELEMENT(ResourceId, id, GetResourceManager()->GetID(ProgramRes(GetCtx(), program)));

	if(m_State == READING)
	{
		ResourceId progid = GetResourceManager()->GetLiveID(id);
		
		ProgramData &progDetails = m_Programs[progid];

		progDetails.linked = true;
		
		for(size_t s=0; s < 6; s++)
		{
			for(size_t sh=0; sh < progDetails.shaders.size(); sh++)
			{
				if(m_Shaders[ progDetails.shaders[sh] ].type == ShaderEnum(s))
					progDetails.stageShaders[s] = progDetails.shaders[sh];
			}
		}

		m_Real.glLinkProgram(GetResourceManager()->GetLiveResource(id).name);
	}

	return true;
}

void WrappedOpenGL::glLinkProgram(GLuint program)
{
	m_Real.glLinkProgram(program);
	
	if(m_State >= WRITING)
	{
		GLResourceRecord *record = GetResourceManager()->GetResourceRecord(ProgramRes(GetCtx(), program));
		RDCASSERT(record);
		{
			SCOPED_SERIALISE_CONTEXT(LINKPROGRAM);
			Serialise_glLinkProgram(program);

			record->AddChunk(scope.Get());
		}
	}
}

bool WrappedOpenGL::Serialise_glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)
{
	SERIALISE_ELEMENT(ResourceId, id, GetResourceManager()->GetID(ProgramRes(GetCtx(), program)));
	SERIALISE_ELEMENT(uint32_t, index, uniformBlockIndex);
	SERIALISE_ELEMENT(uint32_t, binding, uniformBlockBinding);

	if(m_State == READING)
	{
		m_Real.glUniformBlockBinding(GetResourceManager()->GetLiveResource(id).name, index, binding);
	}

	return true;
}

void WrappedOpenGL::glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)
{
	m_Real.glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
	
	if(m_State >= WRITING)
	{
		GLResourceRecord *record = GetResourceManager()->GetResourceRecord(ProgramRes(GetCtx(), program));
		RDCASSERT(record);
		{
			SCOPED_SERIALISE_CONTEXT(UNIFORM_BLOCKBIND);
			Serialise_glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);

			record->AddChunk(scope.Get());
		}
	}
}

bool WrappedOpenGL::Serialise_glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding)
{
	SERIALISE_ELEMENT(ResourceId, id, GetResourceManager()->GetID(ProgramRes(GetCtx(), program)));
	SERIALISE_ELEMENT(uint32_t, index, storageBlockIndex);
	SERIALISE_ELEMENT(uint32_t, binding, storageBlockBinding);

	if(m_State == READING)
	{
		m_Real.glShaderStorageBlockBinding(GetResourceManager()->GetLiveResource(id).name, index, binding);
	}

	return true;
}

void WrappedOpenGL::glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding)
{
	m_Real.glShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding);
	
	if(m_State >= WRITING)
	{
		GLResourceRecord *record = GetResourceManager()->GetResourceRecord(ProgramRes(GetCtx(), program));
		RDCASSERT(record);
		{
			SCOPED_SERIALISE_CONTEXT(STORAGE_BLOCKBIND);
			Serialise_glShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding);

			record->AddChunk(scope.Get());
		}
	}
}

bool WrappedOpenGL::Serialise_glBindAttribLocation(GLuint program, GLuint index, const GLchar *name_)
{
	SERIALISE_ELEMENT(ResourceId, id, GetResourceManager()->GetID(ProgramRes(GetCtx(), program)));
	SERIALISE_ELEMENT(uint32_t, idx, index);
	
	string name = name_ ? name_ : "";
	m_pSerialiser->Serialise("Name", name);

	if(m_State == READING)
	{
		m_Real.glBindAttribLocation(GetResourceManager()->GetLiveResource(id).name, idx, name.c_str());
	}

	return true;
}

void WrappedOpenGL::glBindAttribLocation(GLuint program, GLuint index, const GLchar *name)
{
	m_Real.glBindAttribLocation(program, index, name);
	
	if(m_State >= WRITING)
	{
		GLResourceRecord *record = GetResourceManager()->GetResourceRecord(ProgramRes(GetCtx(), program));
		RDCASSERT(record);
		{
			SCOPED_SERIALISE_CONTEXT(BINDATTRIB_LOCATION);
			Serialise_glBindAttribLocation(program, index, name);

			record->AddChunk(scope.Get());
		}
	}
}

bool WrappedOpenGL::Serialise_glBindFragDataLocation(GLuint program, GLuint color, const GLchar *name_)
{
	SERIALISE_ELEMENT(ResourceId, id, GetResourceManager()->GetID(ProgramRes(GetCtx(), program)));
	SERIALISE_ELEMENT(uint32_t, col, color);
	
	string name = name_ ? name_ : "";
	m_pSerialiser->Serialise("Name", name);

	if(m_State == READING)
	{
		m_Real.glBindFragDataLocation(GetResourceManager()->GetLiveResource(id).name, col, name.c_str());
	}

	return true;
}

void WrappedOpenGL::glBindFragDataLocation(GLuint program, GLuint color, const GLchar *name)
{
	m_Real.glBindFragDataLocation(program, color, name);
	
	if(m_State >= WRITING)
	{
		GLResourceRecord *record = GetResourceManager()->GetResourceRecord(ProgramRes(GetCtx(), program));
		RDCASSERT(record);
		{
			SCOPED_SERIALISE_CONTEXT(BINDFRAGDATA_LOCATION);
			Serialise_glBindFragDataLocation(program, color, name);

			record->AddChunk(scope.Get());
		}
	}
}

bool WrappedOpenGL::Serialise_glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices)
{
	SERIALISE_ELEMENT(GLenum, sh, shadertype);
	SERIALISE_ELEMENT(uint32_t, Count, count);
	SERIALISE_ELEMENT_ARR(uint32_t, Idxs, indices, Count);

	if(m_State <= EXECUTING)
		m_Real.glUniformSubroutinesuiv(sh, Count, Idxs);
	
	SAFE_DELETE_ARRAY(Idxs);

	return true;
}

void WrappedOpenGL::glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices)
{
	m_Real.glUniformSubroutinesuiv(shadertype, count, indices);
	
	if(m_State >= WRITING_CAPFRAME)
	{
		SCOPED_SERIALISE_CONTEXT(UNIFORM_SUBROUTINE);
		Serialise_glUniformSubroutinesuiv(shadertype, count, indices);

		m_ContextRecord->AddChunk(scope.Get());
	}
}

bool WrappedOpenGL::Serialise_glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name_)
{
	SERIALISE_ELEMENT(ResourceId, id, GetResourceManager()->GetID(ProgramRes(GetCtx(), program)));
	SERIALISE_ELEMENT(uint32_t, colNum, colorNumber);
	SERIALISE_ELEMENT(uint32_t, idx, index);
	
	string name = name_ ? name_ : "";
	m_pSerialiser->Serialise("Name", name);

	if(m_State == READING)
	{
		m_Real.glBindFragDataLocationIndexed(GetResourceManager()->GetLiveResource(id).name, colNum, idx, name.c_str());
	}

	return true;
}

void WrappedOpenGL::glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name)
{
	m_Real.glBindFragDataLocationIndexed(program, colorNumber, index, name);
	
	if(m_State >= WRITING)
	{
		GLResourceRecord *record = GetResourceManager()->GetResourceRecord(ProgramRes(GetCtx(), program));
		RDCASSERT(record);
		{
			SCOPED_SERIALISE_CONTEXT(BINDFRAGDATA_LOCATION_INDEXED);
			Serialise_glBindFragDataLocationIndexed(program, colorNumber, index, name);

			record->AddChunk(scope.Get());
		}
	}
}

bool WrappedOpenGL::Serialise_glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode)
{
	SERIALISE_ELEMENT(ResourceId, id, GetResourceManager()->GetID(ProgramRes(GetCtx(), program)));
	SERIALISE_ELEMENT(uint32_t, Count, count);
	SERIALISE_ELEMENT(GLenum, Mode, bufferMode);

	string *vars = m_State >= WRITING ? NULL : new string[Count];
	char **varstrs = m_State >= WRITING ? NULL : new char*[Count];

	for(uint32_t c=0; c < Count; c++)
	{
		string v = varyings && varyings[c] ? varyings[c] : "";
		m_pSerialiser->Serialise("Varying", v);
		if(vars) { vars[c] = v; varstrs[c] = (char *)vars[c].c_str(); }
	}
	
	if(m_State == READING)
	{
		m_Real.glTransformFeedbackVaryings(GetResourceManager()->GetLiveResource(id).name, Count, varstrs, Mode);
	}

	SAFE_DELETE_ARRAY(vars);
	SAFE_DELETE_ARRAY(varstrs);
	
	return true;
}

void WrappedOpenGL::glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode)
{
	m_Real.glTransformFeedbackVaryings(program, count, varyings, bufferMode);
	
	if(m_State >= WRITING)
	{
		GLResourceRecord *record = GetResourceManager()->GetResourceRecord(ProgramRes(GetCtx(), program));
		RDCASSERT(record);
		{
			SCOPED_SERIALISE_CONTEXT(FEEDBACK_VARYINGS);
			Serialise_glTransformFeedbackVaryings(program, count, varyings, bufferMode);

			record->AddChunk(scope.Get());
		}
	}
}

bool WrappedOpenGL::Serialise_glProgramParameteri(GLuint program, GLenum pname, GLint value)
{
	SERIALISE_ELEMENT(ResourceId, id, GetResourceManager()->GetID(ProgramRes(GetCtx(), program)));
	SERIALISE_ELEMENT(GLenum, PName, pname);
	SERIALISE_ELEMENT(int32_t, Value, value);

	if(m_State == READING)
	{
		m_Real.glProgramParameteri(GetResourceManager()->GetLiveResource(id).name, PName, Value);
	}

	return true;
}

void WrappedOpenGL::glProgramParameteri(GLuint program, GLenum pname, GLint value)
{
	m_Real.glProgramParameteri(program, pname, value);
	
	if(m_State >= WRITING)
	{
		GLResourceRecord *record = GetResourceManager()->GetResourceRecord(ProgramRes(GetCtx(), program));
		RDCASSERT(record);
		{
			SCOPED_SERIALISE_CONTEXT(PROGRAMPARAMETER);
			Serialise_glProgramParameteri(program, pname, value);

			record->AddChunk(scope.Get());
		}
	}
}

void WrappedOpenGL::glDeleteProgram(GLuint program)
{
	m_Real.glDeleteProgram(program);
	
	GLResource res = ProgramRes(GetCtx(), program);
	if(GetResourceManager()->HasCurrentResource(res))
	{
		GetResourceManager()->MarkCleanResource(res);
		if(GetResourceManager()->HasResourceRecord(res))
				GetResourceManager()->GetResourceRecord(res)->Delete(GetResourceManager());
		GetResourceManager()->UnregisterResource(res);
	}
}

bool WrappedOpenGL::Serialise_glUseProgram(GLuint program)
{
	SERIALISE_ELEMENT(ResourceId, id, GetResourceManager()->GetID(ProgramRes(GetCtx(), program)));

	if(m_State <= EXECUTING)
	{
		if(id == ResourceId())
			m_Real.glUseProgram(0);
		else
			m_Real.glUseProgram(GetResourceManager()->GetLiveResource(id).name);
	}

	return true;
}

void WrappedOpenGL::glUseProgram(GLuint program)
{
	m_Real.glUseProgram(program);

	GetCtxData().m_Program = program;

	if(m_State == WRITING_CAPFRAME)
	{
		SCOPED_SERIALISE_CONTEXT(USEPROGRAM);
		Serialise_glUseProgram(program);

		m_ContextRecord->AddChunk(scope.Get());
	}
}

void WrappedOpenGL::glValidateProgram(GLuint program)
{
	m_Real.glValidateProgram(program);
}

void WrappedOpenGL::glValidateProgramPipeline(GLuint pipeline)
{
	m_Real.glValidateProgramPipeline(pipeline);
}

void WrappedOpenGL::glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length)
{
	// deliberately don't forward on this call when writing, since we want to coax the app into providing non-binary shaders.
	if(m_State < WRITING)
	{
		m_Real.glShaderBinary(count, shaders, binaryformat, binary, length);
	}
}

void WrappedOpenGL::glProgramBinary(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length)
{
	// deliberately don't forward on this call when writing, since we want to coax the app into providing non-binary shaders.
	if(m_State < WRITING)
	{
		m_Real.glProgramBinary(program, binaryFormat, binary, length);
	}
}

#pragma endregion

#pragma region Program Pipelines

bool WrappedOpenGL::Serialise_glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program)
{
	SERIALISE_ELEMENT(ResourceId, pipe, GetResourceManager()->GetID(ProgramPipeRes(GetCtx(), pipeline)));
	SERIALISE_ELEMENT(uint32_t, Stages, stages);
	SERIALISE_ELEMENT(ResourceId, prog, GetResourceManager()->GetID(ProgramRes(GetCtx(), program)));

	if(m_State < WRITING)
	{
		ResourceId livePipeId = GetResourceManager()->GetLiveID(pipe);
		ResourceId liveProgId = GetResourceManager()->GetLiveID(prog);

		PipelineData &pipeDetails = m_Pipelines[livePipeId];
		ProgramData &progDetails = m_Programs[liveProgId];

		pipeDetails.programs.push_back(PipelineData::ProgramUse(liveProgId, Stages));

		for(size_t s=0; s < 6; s++)
		{
			if(Stages & ShaderBit(s))
			{
				for(size_t sh=0; sh < progDetails.shaders.size(); sh++)
				{
					if(m_Shaders[ progDetails.shaders[sh] ].type == ShaderEnum(s))
					{
						pipeDetails.stagePrograms[s] = liveProgId;
						pipeDetails.stageShaders[s] = progDetails.shaders[sh];
						break;
					}
				}
			}
		}
		
		m_Real.glUseProgramStages(GetResourceManager()->GetLiveResource(pipe).name,
															Stages,
															GetResourceManager()->GetLiveResource(prog).name);
	}

	return true;
}

void WrappedOpenGL::glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program)
{
	m_Real.glUseProgramStages(pipeline, stages, program);

	if(m_State > WRITING)
	{
		SCOPED_SERIALISE_CONTEXT(USE_PROGRAMSTAGES);
		Serialise_glUseProgramStages(pipeline, stages, program);
		
		GLResourceRecord *record = GetResourceManager()->GetResourceRecord(ProgramPipeRes(GetCtx(), pipeline));
		RDCASSERT(record);
		record->AddChunk(scope.Get());

		GLResourceRecord *progrecord = GetResourceManager()->GetResourceRecord(ProgramRes(GetCtx(), program));
		record->AddParent(progrecord);
	}
}

bool WrappedOpenGL::Serialise_glGenProgramPipelines(GLsizei n, GLuint* pipelines)
{
	SERIALISE_ELEMENT(ResourceId, id, GetResourceManager()->GetID(ProgramPipeRes(GetCtx(), *pipelines)));

	if(m_State == READING)
	{
		GLuint real = 0;
		m_Real.glGenProgramPipelines(1, &real);
		
		GLResource res = ProgramPipeRes(GetCtx(), real);

		ResourceId live = m_ResourceManager->RegisterResource(res);
		GetResourceManager()->AddLiveResource(id, res);
	}

	return true;
}

void WrappedOpenGL::glGenProgramPipelines(GLsizei n, GLuint *pipelines)
{
	m_Real.glGenProgramPipelines(n, pipelines);

	for(GLsizei i=0; i < n; i++)
	{
		GLResource res = ProgramPipeRes(GetCtx(), pipelines[i]);
		ResourceId id = GetResourceManager()->RegisterResource(res);

		if(m_State >= WRITING)
		{
			Chunk *chunk = NULL;

			{
				SCOPED_SERIALISE_CONTEXT(GEN_PROGRAMPIPE);
				Serialise_glGenProgramPipelines(1, pipelines+i);

				chunk = scope.Get();
			}

			GLResourceRecord *record = GetResourceManager()->AddResourceRecord(id);
			RDCASSERT(record);

			record->AddChunk(chunk);
		}
		else
		{
			GetResourceManager()->AddLiveResource(id, res);
		}
	}
}

bool WrappedOpenGL::Serialise_glBindProgramPipeline(GLuint pipeline)
{
	SERIALISE_ELEMENT(ResourceId, id, (pipeline ? GetResourceManager()->GetID(ProgramPipeRes(GetCtx(), pipeline)) : ResourceId()));

	if(m_State <= EXECUTING)
	{
		if(id == ResourceId())
		{
			m_Real.glBindProgramPipeline(0);
		}
		else
		{
			GLuint live = GetResourceManager()->GetLiveResource(id).name;
			m_Real.glBindProgramPipeline(live);
		}
	}

	return true;
}

void WrappedOpenGL::glBindProgramPipeline(GLuint pipeline)
{
	m_Real.glBindProgramPipeline(pipeline);

	GetCtxData().m_ProgramPipeline = pipeline;

	if(m_State == WRITING_CAPFRAME)
	{
		SCOPED_SERIALISE_CONTEXT(BIND_PROGRAMPIPE);
		Serialise_glBindProgramPipeline(pipeline);

		m_ContextRecord->AddChunk(scope.Get());
	}
}

void WrappedOpenGL::glActiveShaderProgram(GLuint pipeline, GLuint program)
{
	m_Real.glActiveShaderProgram(pipeline, program);
}

GLuint WrappedOpenGL::GetUniformProgram()
{
	ContextData &cd = GetCtxData();

	// program gets first dibs, if one is bound then that's where glUniform* calls go.
	if(cd.m_Program != 0)
	{
		return cd.m_Program;
	}
	else if(cd.m_ProgramPipeline != 0)
	{
		GLuint ret = 0;
		
		// otherwise, query the active program for the pipeline (could cache this above in glActiveShaderProgram)
		// we do this query every time instead of caching the result, since I think it's unlikely that we'll ever
		// hit this path (most people using separable programs will use the glProgramUniform* interface).
		// That way we don't pay the cost of a potentially expensive query unless we really need it.
		m_Real.glGetProgramPipelineiv(cd.m_ProgramPipeline, eGL_ACTIVE_PROGRAM, (GLint *)&ret);

		return ret;
	}

	return 0;
}

void WrappedOpenGL::glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines)
{
	for(GLsizei i=0; i < n; i++)
	{
		GLResource res = ProgramPipeRes(GetCtx(), pipelines[i]);
		if(GetResourceManager()->HasCurrentResource(res))
		{
			if(GetResourceManager()->HasResourceRecord(res))
				GetResourceManager()->GetResourceRecord(res)->Delete(GetResourceManager());
			GetResourceManager()->UnregisterResource(res);
		}
	}
	
	m_Real.glDeleteProgramPipelines(n, pipelines);
}

#pragma endregion
