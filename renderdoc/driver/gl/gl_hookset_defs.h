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


#pragma once

// it's recommended that you auto-generate this file with hookset.pl, but you can manually edit it
// if you prefer.
////////////////////////////////////////////////////

// dllexport functions
#define DLLExportHooks() \
    HookInit(glBindTexture); \
    HookInit(glBlendFunc); \
    HookInit(glClear); \
    HookInit(glClearColor); \
    HookInit(glClearDepth); \
    HookInit(glClearStencil); \
    HookInit(glColorMask); \
    HookInit(glCullFace); \
    HookInit(glDepthFunc); \
    HookInit(glDepthMask); \
    HookInit(glDepthRange); \
    HookInit(glStencilFunc); \
    HookInit(glStencilMask); \
    HookInit(glStencilOp); \
    HookInit(glDisable); \
    HookInit(glDrawBuffer); \
    HookInit(glDrawElements); \
    HookInit(glDrawArrays); \
    HookInit(glEnable); \
    HookInit(glFlush); \
    HookInit(glFinish); \
    HookInit(glFrontFace); \
    HookInit(glGenTextures); \
    HookInit(glDeleteTextures); \
    HookInit(glIsEnabled); \
    HookInit(glIsTexture); \
    HookInit(glGetError); \
    HookInit(glGetTexLevelParameteriv); \
    HookInit(glGetTexLevelParameterfv); \
    HookInit(glGetTexParameterfv); \
    HookInit(glGetTexParameteriv); \
    HookInit(glGetTexImage); \
    HookInit(glGetBooleanv); \
    HookInit(glGetFloatv); \
    HookInit(glGetDoublev); \
    HookInit(glGetIntegerv); \
    HookInit(glGetPointerv); \
    HookInit(glGetString); \
    HookInit(glHint); \
    HookInit(glLogicOp); \
    HookInit(glPixelStorei); \
    HookInit(glPixelStoref); \
    HookInit(glPolygonMode); \
    HookInit(glPolygonOffset); \
    HookInit(glPointSize); \
    HookInit(glLineWidth); \
    HookInit(glReadPixels); \
    HookInit(glReadBuffer); \
    HookInit(glScissor); \
    HookInit(glTexImage1D); \
    HookInit(glTexImage2D); \
    HookInit(glTexSubImage1D); \
    HookInit(glTexSubImage2D); \
    HookInit(glCopyTexImage1D); \
    HookInit(glCopyTexImage2D); \
    HookInit(glCopyTexSubImage1D); \
    HookInit(glCopyTexSubImage2D); \
    HookInit(glTexParameterf); \
    HookInit(glTexParameterfv); \
    HookInit(glTexParameteri); \
    HookInit(glTexParameteriv); \
    HookInit(glViewport); \



// gl extensions
#define HookCheckGLExtensions() \
    HookExtension(PFNGLACTIVETEXTUREPROC, glActiveTexture); \
    HookExtensionAlias(PFNGLACTIVETEXTUREPROC, glActiveTexture, glActiveTextureARB); \
    HookExtension(PFNGLTEXSTORAGE1DPROC, glTexStorage1D); \
    HookExtension(PFNGLTEXSTORAGE2DPROC, glTexStorage2D); \
    HookExtension(PFNGLTEXSTORAGE3DPROC, glTexStorage3D); \
    HookExtension(PFNGLTEXSTORAGE2DMULTISAMPLEPROC, glTexStorage2DMultisample); \
    HookExtension(PFNGLTEXSTORAGE3DMULTISAMPLEPROC, glTexStorage3DMultisample); \
    HookExtension(PFNGLTEXIMAGE3DPROC, glTexImage3D); \
    HookExtension(PFNGLTEXSUBIMAGE3DPROC, glTexSubImage3D); \
    HookExtension(PFNGLTEXBUFFERPROC, glTexBuffer); \
    HookExtension(PFNGLTEXIMAGE2DMULTISAMPLEPROC, glTexImage2DMultisample); \
    HookExtension(PFNGLTEXIMAGE3DMULTISAMPLEPROC, glTexImage3DMultisample); \
    HookExtension(PFNGLCOMPRESSEDTEXIMAGE1DPROC, glCompressedTexImage1D); \
    HookExtensionAlias(PFNGLCOMPRESSEDTEXIMAGE1DPROC, glCompressedTexImage1D, glCompressedTexImage1DARB); \
    HookExtension(PFNGLCOMPRESSEDTEXIMAGE2DPROC, glCompressedTexImage2D); \
    HookExtensionAlias(PFNGLCOMPRESSEDTEXIMAGE2DPROC, glCompressedTexImage2D, glCompressedTexImage2DARB); \
    HookExtension(PFNGLCOMPRESSEDTEXIMAGE3DPROC, glCompressedTexImage3D); \
    HookExtensionAlias(PFNGLCOMPRESSEDTEXIMAGE3DPROC, glCompressedTexImage3D, glCompressedTexImage3DARB); \
    HookExtension(PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC, glCompressedTexSubImage1D); \
    HookExtensionAlias(PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC, glCompressedTexSubImage1D, glCompressedTexSubImage1DARB); \
    HookExtension(PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC, glCompressedTexSubImage2D); \
    HookExtensionAlias(PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC, glCompressedTexSubImage2D, glCompressedTexSubImage2DARB); \
    HookExtension(PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC, glCompressedTexSubImage3D); \
    HookExtensionAlias(PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC, glCompressedTexSubImage3D, glCompressedTexSubImage3DARB); \
    HookExtension(PFNGLTEXBUFFERRANGEPROC, glTexBufferRange); \
    HookExtension(PFNGLTEXTUREVIEWPROC, glTextureView); \
    HookExtension(PFNGLTEXPARAMETERIIVPROC, glTexParameterIiv); \
    HookExtension(PFNGLTEXPARAMETERIUIVPROC, glTexParameterIuiv); \
    HookExtension(PFNGLGENERATEMIPMAPPROC, glGenerateMipmap); \
    HookExtensionAlias(PFNGLGENERATEMIPMAPPROC, glGenerateMipmap, glGenerateMipmapEXT); \
    HookExtension(PFNGLCOPYIMAGESUBDATAPROC, glCopyImageSubData); \
    HookExtension(PFNGLCOPYTEXSUBIMAGE3DPROC, glCopyTexSubImage3D); \
    HookExtension(PFNGLGETINTERNALFORMATIVPROC, glGetInternalformativ); \
    HookExtension(PFNGLGETINTERNALFORMATI64VPROC, glGetInternalformati64v); \
    HookExtension(PFNGLGETBUFFERPARAMETERIVPROC, glGetBufferParameteriv); \
    HookExtensionAlias(PFNGLGETBUFFERPARAMETERIVPROC, glGetBufferParameteriv, glGetBufferParameterivARB); \
    HookExtension(PFNGLGETBUFFERPARAMETERI64VPROC, glGetBufferParameteri64v); \
    HookExtension(PFNGLGETBUFFERPOINTERVPROC, glGetBufferPointerv); \
    HookExtensionAlias(PFNGLGETBUFFERPOINTERVPROC, glGetBufferPointerv, glGetBufferPointervARB); \
    HookExtension(PFNGLGETFRAGDATAINDEXPROC, glGetFragDataIndex); \
    HookExtension(PFNGLGETFRAGDATALOCATIONPROC, glGetFragDataLocation); \
    HookExtension(PFNGLGETSTRINGIPROC, glGetStringi); \
    HookExtension(PFNGLGETBOOLEANI_VPROC, glGetBooleani_v); \
    HookExtension(PFNGLGETINTEGERI_VPROC, glGetIntegeri_v); \
    HookExtension(PFNGLGETFLOATI_VPROC, glGetFloati_v); \
    HookExtensionAlias(PFNGLGETFLOATI_VPROC, glGetFloati_v, glGetFloati_vEXT); \
    HookExtension(PFNGLGETDOUBLEI_VPROC, glGetDoublei_v); \
    HookExtensionAlias(PFNGLGETDOUBLEI_VPROC, glGetDoublei_v, glGetDoublei_vEXT); \
    HookExtension(PFNGLGETINTEGER64I_VPROC, glGetInteger64i_v); \
    HookExtension(PFNGLGETINTEGER64VPROC, glGetInteger64v); \
    HookExtension(PFNGLGETSHADERIVPROC, glGetShaderiv); \
    HookExtension(PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog); \
    HookExtension(PFNGLGETSHADERPRECISIONFORMATPROC, glGetShaderPrecisionFormat); \
    HookExtension(PFNGLGETSHADERSOURCEPROC, glGetShaderSource); \
    HookExtension(PFNGLGETATTACHEDSHADERSPROC, glGetAttachedShaders); \
    HookExtension(PFNGLGETPROGRAMIVPROC, glGetProgramiv); \
    HookExtension(PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog); \
    HookExtension(PFNGLGETPROGRAMINTERFACEIVPROC, glGetProgramInterfaceiv); \
    HookExtension(PFNGLGETPROGRAMRESOURCEINDEXPROC, glGetProgramResourceIndex); \
    HookExtension(PFNGLGETPROGRAMRESOURCEIVPROC, glGetProgramResourceiv); \
    HookExtension(PFNGLGETPROGRAMRESOURCENAMEPROC, glGetProgramResourceName); \
    HookExtension(PFNGLGETPROGRAMPIPELINEIVPROC, glGetProgramPipelineiv); \
    HookExtension(PFNGLGETPROGRAMPIPELINEINFOLOGPROC, glGetProgramPipelineInfoLog); \
    HookExtension(PFNGLGETPROGRAMBINARYPROC, glGetProgramBinary); \
    HookExtension(PFNGLGETPROGRAMRESOURCELOCATIONPROC, glGetProgramResourceLocation); \
    HookExtension(PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC, glGetProgramResourceLocationIndex); \
    HookExtension(PFNGLGETPROGRAMSTAGEIVPROC, glGetProgramStageiv); \
    HookExtension(PFNGLGETGRAPHICSRESETSTATUSPROC, glGetGraphicsResetStatus); \
    HookExtensionAlias(PFNGLGETGRAPHICSRESETSTATUSPROC, glGetGraphicsResetStatus, glGetGraphicsResetStatusARB); \
    HookExtension(PFNGLGETOBJECTLABELPROC, glGetObjectLabel); \
    HookExtension(PFNGLGETOBJECTPTRLABELPROC, glGetObjectPtrLabel); \
    HookExtension(PFNGLGETDEBUGMESSAGELOGPROC, glGetDebugMessageLog); \
    HookExtensionAlias(PFNGLGETDEBUGMESSAGELOGPROC, glGetDebugMessageLog, glGetDebugMessageLogARB); \
    HookExtension(PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC, glGetFramebufferAttachmentParameteriv); \
    HookExtensionAlias(PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC, glGetFramebufferAttachmentParameteriv, glGetFramebufferAttachmentParameterivEXT); \
    HookExtension(PFNGLGETFRAMEBUFFERPARAMETERIVPROC, glGetFramebufferParameteriv); \
    HookExtension(PFNGLGETRENDERBUFFERPARAMETERIVPROC, glGetRenderbufferParameteriv); \
    HookExtensionAlias(PFNGLGETRENDERBUFFERPARAMETERIVPROC, glGetRenderbufferParameteriv, glGetRenderbufferParameterivEXT); \
    HookExtension(PFNGLGETMULTISAMPLEFVPROC, glGetMultisamplefv); \
    HookExtension(PFNGLGETQUERYINDEXEDIVPROC, glGetQueryIndexediv); \
    HookExtension(PFNGLGETQUERYOBJECTUI64VPROC, glGetQueryObjectui64v); \
    HookExtensionAlias(PFNGLGETQUERYOBJECTUI64VPROC, glGetQueryObjectui64v, glGetQueryObjectui64vEXT); \
    HookExtension(PFNGLGETQUERYOBJECTUIVPROC, glGetQueryObjectuiv); \
    HookExtensionAlias(PFNGLGETQUERYOBJECTUIVPROC, glGetQueryObjectuiv, glGetQueryObjectuivARB); \
    HookExtension(PFNGLGETQUERYOBJECTI64VPROC, glGetQueryObjecti64v); \
    HookExtensionAlias(PFNGLGETQUERYOBJECTI64VPROC, glGetQueryObjecti64v, glGetQueryObjecti64vEXT); \
    HookExtension(PFNGLGETQUERYOBJECTIVPROC, glGetQueryObjectiv); \
    HookExtensionAlias(PFNGLGETQUERYOBJECTIVPROC, glGetQueryObjectiv, glGetQueryObjectivARB); \
    HookExtension(PFNGLGETQUERYIVPROC, glGetQueryiv); \
    HookExtensionAlias(PFNGLGETQUERYIVPROC, glGetQueryiv, glGetQueryivARB); \
    HookExtension(PFNGLGETSYNCIVPROC, glGetSynciv); \
    HookExtension(PFNGLGETBUFFERSUBDATAPROC, glGetBufferSubData); \
    HookExtensionAlias(PFNGLGETBUFFERSUBDATAPROC, glGetBufferSubData, glGetBufferSubDataARB); \
    HookExtension(PFNGLGETVERTEXATTRIBIVPROC, glGetVertexAttribiv); \
    HookExtension(PFNGLGETVERTEXATTRIBPOINTERVPROC, glGetVertexAttribPointerv); \
    HookExtension(PFNGLGETCOMPRESSEDTEXIMAGEPROC, glGetCompressedTexImage); \
    HookExtensionAlias(PFNGLGETCOMPRESSEDTEXIMAGEPROC, glGetCompressedTexImage, glGetCompressedTexImageARB); \
    HookExtension(PFNGLGETNCOMPRESSEDTEXIMAGEPROC, glGetnCompressedTexImage); \
    HookExtensionAlias(PFNGLGETNCOMPRESSEDTEXIMAGEPROC, glGetnCompressedTexImage, glGetnCompressedTexImageARB); \
    HookExtension(PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC, glGetCompressedTextureImage); \
    HookExtension(PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC, glGetCompressedTextureSubImage); \
    HookExtension(PFNGLGETNTEXIMAGEPROC, glGetnTexImage); \
    HookExtensionAlias(PFNGLGETNTEXIMAGEPROC, glGetnTexImage, glGetnTexImageARB); \
    HookExtension(PFNGLGETTEXTUREIMAGEPROC, glGetTextureImage); \
    HookExtension(PFNGLGETTEXTURELEVELPARAMETERFVPROC, glGetTextureLevelParameterfv); \
    HookExtension(PFNGLGETTEXTURELEVELPARAMETERIVPROC, glGetTextureLevelParameteriv); \
    HookExtension(PFNGLGETTEXTUREPARAMETERIIVPROC, glGetTextureParameterIiv); \
    HookExtension(PFNGLGETTEXTUREPARAMETERIUIVPROC, glGetTextureParameterIuiv); \
    HookExtension(PFNGLGETTEXTUREPARAMETERFVPROC, glGetTextureParameterfv); \
    HookExtension(PFNGLGETTEXTUREPARAMETERIVPROC, glGetTextureParameteriv); \
    HookExtension(PFNGLGETTEXTURESUBIMAGEPROC, glGetTextureSubImage); \
    HookExtension(PFNGLGETTEXPARAMETERIIVPROC, glGetTexParameterIiv); \
    HookExtension(PFNGLGETTEXPARAMETERIUIVPROC, glGetTexParameterIuiv); \
    HookExtension(PFNGLCLAMPCOLORPROC, glClampColor); \
    HookExtensionAlias(PFNGLCLAMPCOLORPROC, glClampColor, glClampColorARB); \
    HookExtension(PFNGLREADNPIXELSPROC, glReadnPixels); \
    HookExtensionAlias(PFNGLREADNPIXELSPROC, glReadnPixels, glReadnPixelsARB); \
    HookExtension(PFNGLGETSAMPLERPARAMETERIIVPROC, glGetSamplerParameterIiv); \
    HookExtension(PFNGLGETSAMPLERPARAMETERIUIVPROC, glGetSamplerParameterIuiv); \
    HookExtension(PFNGLGETSAMPLERPARAMETERFVPROC, glGetSamplerParameterfv); \
    HookExtension(PFNGLGETSAMPLERPARAMETERIVPROC, glGetSamplerParameteriv); \
    HookExtension(PFNGLGETTRANSFORMFEEDBACKVARYINGPROC, glGetTransformFeedbackVarying); \
    HookExtension(PFNGLGETTRANSFORMFEEDBACKI64_VPROC, glGetTransformFeedbacki64_v); \
    HookExtension(PFNGLGETTRANSFORMFEEDBACKI_VPROC, glGetTransformFeedbacki_v); \
    HookExtension(PFNGLGETTRANSFORMFEEDBACKIVPROC, glGetTransformFeedbackiv); \
    HookExtension(PFNGLGETSUBROUTINEINDEXPROC, glGetSubroutineIndex); \
    HookExtension(PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC, glGetSubroutineUniformLocation); \
    HookExtension(PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC, glGetActiveAtomicCounterBufferiv); \
    HookExtension(PFNGLGETACTIVESUBROUTINENAMEPROC, glGetActiveSubroutineName); \
    HookExtension(PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC, glGetActiveSubroutineUniformName); \
    HookExtension(PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC, glGetActiveSubroutineUniformiv); \
    HookExtension(PFNGLGETUNIFORMLOCATIONPROC, glGetUniformLocation); \
    HookExtension(PFNGLGETUNIFORMINDICESPROC, glGetUniformIndices); \
    HookExtension(PFNGLGETUNIFORMSUBROUTINEUIVPROC, glGetUniformSubroutineuiv); \
    HookExtension(PFNGLGETUNIFORMBLOCKINDEXPROC, glGetUniformBlockIndex); \
    HookExtension(PFNGLGETATTRIBLOCATIONPROC, glGetAttribLocation); \
    HookExtension(PFNGLGETACTIVEUNIFORMPROC, glGetActiveUniform); \
    HookExtension(PFNGLGETACTIVEUNIFORMNAMEPROC, glGetActiveUniformName); \
    HookExtension(PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC, glGetActiveUniformBlockName); \
    HookExtension(PFNGLGETACTIVEUNIFORMBLOCKIVPROC, glGetActiveUniformBlockiv); \
    HookExtension(PFNGLGETACTIVEUNIFORMSIVPROC, glGetActiveUniformsiv); \
    HookExtension(PFNGLGETACTIVEATTRIBPROC, glGetActiveAttrib); \
    HookExtension(PFNGLGETUNIFORMFVPROC, glGetUniformfv); \
    HookExtension(PFNGLGETUNIFORMIVPROC, glGetUniformiv); \
    HookExtension(PFNGLGETUNIFORMUIVPROC, glGetUniformuiv); \
    HookExtension(PFNGLGETUNIFORMDVPROC, glGetUniformdv); \
    HookExtension(PFNGLGETNUNIFORMDVPROC, glGetnUniformdv); \
    HookExtensionAlias(PFNGLGETNUNIFORMDVPROC, glGetnUniformdv, glGetnUniformdvARB); \
    HookExtension(PFNGLGETNUNIFORMFVPROC, glGetnUniformfv); \
    HookExtensionAlias(PFNGLGETNUNIFORMFVPROC, glGetnUniformfv, glGetnUniformfvARB); \
    HookExtension(PFNGLGETNUNIFORMIVPROC, glGetnUniformiv); \
    HookExtensionAlias(PFNGLGETNUNIFORMIVPROC, glGetnUniformiv, glGetnUniformivARB); \
    HookExtension(PFNGLGETNUNIFORMUIVPROC, glGetnUniformuiv); \
    HookExtensionAlias(PFNGLGETNUNIFORMUIVPROC, glGetnUniformuiv, glGetnUniformuivARB); \
    HookExtension(PFNGLGETVERTEXARRAYIVPROC, glGetVertexArrayiv); \
    HookExtension(PFNGLGETVERTEXARRAYINDEXED64IVPROC, glGetVertexArrayIndexed64iv); \
    HookExtension(PFNGLGETVERTEXARRAYINDEXEDIVPROC, glGetVertexArrayIndexediv); \
    HookExtension(PFNGLGETVERTEXATTRIBIIVPROC, glGetVertexAttribIiv); \
    HookExtension(PFNGLGETVERTEXATTRIBIUIVPROC, glGetVertexAttribIuiv); \
    HookExtension(PFNGLGETVERTEXATTRIBLDVPROC, glGetVertexAttribLdv); \
    HookExtension(PFNGLGETVERTEXATTRIBDVPROC, glGetVertexAttribdv); \
    HookExtension(PFNGLGETVERTEXATTRIBFVPROC, glGetVertexAttribfv); \
    HookExtension(PFNGLGETNAMEDBUFFERPARAMETERI64VPROC, glGetNamedBufferParameteri64v); \
    HookExtension(PFNGLGETNAMEDBUFFERPOINTERVPROC, glGetNamedBufferPointerv); \
    HookExtension(PFNGLCHECKFRAMEBUFFERSTATUSPROC, glCheckFramebufferStatus); \
    HookExtensionAlias(PFNGLCHECKFRAMEBUFFERSTATUSPROC, glCheckFramebufferStatus, glCheckFramebufferStatusEXT); \
    HookExtension(PFNGLBLENDCOLORPROC, glBlendColor); \
    HookExtension(PFNGLBLENDFUNCIPROC, glBlendFunci); \
    HookExtensionAlias(PFNGLBLENDFUNCIPROC, glBlendFunci, glBlendFunciARB); \
    HookExtension(PFNGLBLENDFUNCSEPARATEPROC, glBlendFuncSeparate); \
    HookExtensionAlias(PFNGLBLENDFUNCSEPARATEPROC, glBlendFuncSeparate, glBlendFuncSeparateARB); \
    HookExtension(PFNGLBLENDFUNCSEPARATEIPROC, glBlendFuncSeparatei); \
    HookExtensionAlias(PFNGLBLENDFUNCSEPARATEIPROC, glBlendFuncSeparatei, glBlendFuncSeparateiARB); \
    HookExtension(PFNGLBLENDEQUATIONPROC, glBlendEquation); \
    HookExtension(PFNGLBLENDEQUATIONIPROC, glBlendEquationi); \
    HookExtensionAlias(PFNGLBLENDEQUATIONIPROC, glBlendEquationi, glBlendEquationiARB); \
    HookExtension(PFNGLBLENDEQUATIONSEPARATEPROC, glBlendEquationSeparate); \
    HookExtensionAlias(PFNGLBLENDEQUATIONSEPARATEPROC, glBlendEquationSeparate, glBlendEquationSeparateARB); \
    HookExtension(PFNGLBLENDEQUATIONSEPARATEIPROC, glBlendEquationSeparatei); \
    HookExtensionAlias(PFNGLBLENDEQUATIONSEPARATEIPROC, glBlendEquationSeparatei, glBlendEquationSeparateiARB); \
    HookExtension(PFNGLSTENCILFUNCSEPARATEPROC, glStencilFuncSeparate); \
    HookExtension(PFNGLSTENCILMASKSEPARATEPROC, glStencilMaskSeparate); \
    HookExtension(PFNGLSTENCILOPSEPARATEPROC, glStencilOpSeparate); \
    HookExtension(PFNGLCOLORMASKIPROC, glColorMaski); \
    HookExtension(PFNGLSAMPLEMASKIPROC, glSampleMaski); \
    HookExtension(PFNGLSAMPLECOVERAGEPROC, glSampleCoverage); \
    HookExtension(PFNGLMINSAMPLESHADINGPROC, glMinSampleShading); \
    HookExtensionAlias(PFNGLMINSAMPLESHADINGPROC, glMinSampleShading, glMinSampleShadingARB); \
    HookExtension(PFNGLDEPTHRANGEFPROC, glDepthRangef); \
    HookExtension(PFNGLDEPTHRANGEINDEXEDPROC, glDepthRangeIndexed); \
    HookExtension(PFNGLDEPTHRANGEARRAYVPROC, glDepthRangeArrayv); \
    HookExtension(PFNGLDEPTHBOUNDSEXTPROC, glDepthBoundsEXT); \
    HookExtension(PFNGLCLIPCONTROLPROC, glClipControl); \
    HookExtension(PFNGLPROVOKINGVERTEXPROC, glProvokingVertex); \
    HookExtension(PFNGLPRIMITIVERESTARTINDEXPROC, glPrimitiveRestartIndex); \
    HookExtension(PFNGLCREATESHADERPROC, glCreateShader); \
    HookExtension(PFNGLDELETESHADERPROC, glDeleteShader); \
    HookExtension(PFNGLSHADERSOURCEPROC, glShaderSource); \
    HookExtension(PFNGLCOMPILESHADERPROC, glCompileShader); \
    HookExtension(PFNGLCREATESHADERPROGRAMVPROC, glCreateShaderProgramv); \
    HookExtension(PFNGLCREATEPROGRAMPROC, glCreateProgram); \
    HookExtension(PFNGLDELETEPROGRAMPROC, glDeleteProgram); \
    HookExtension(PFNGLATTACHSHADERPROC, glAttachShader); \
    HookExtension(PFNGLDETACHSHADERPROC, glDetachShader); \
    HookExtension(PFNGLRELEASESHADERCOMPILERPROC, glReleaseShaderCompiler); \
    HookExtension(PFNGLLINKPROGRAMPROC, glLinkProgram); \
    HookExtension(PFNGLPROGRAMPARAMETERIPROC, glProgramParameteri); \
    HookExtension(PFNGLUSEPROGRAMPROC, glUseProgram); \
    HookExtension(PFNGLSHADERBINARYPROC, glShaderBinary); \
    HookExtension(PFNGLPROGRAMBINARYPROC, glProgramBinary); \
    HookExtension(PFNGLUSEPROGRAMSTAGESPROC, glUseProgramStages); \
    HookExtension(PFNGLVALIDATEPROGRAMPROC, glValidateProgram); \
    HookExtension(PFNGLGENPROGRAMPIPELINESPROC, glGenProgramPipelines); \
    HookExtension(PFNGLBINDPROGRAMPIPELINEPROC, glBindProgramPipeline); \
    HookExtension(PFNGLACTIVESHADERPROGRAMPROC, glActiveShaderProgram); \
    HookExtension(PFNGLDELETEPROGRAMPIPELINESPROC, glDeleteProgramPipelines); \
    HookExtension(PFNGLVALIDATEPROGRAMPIPELINEPROC, glValidateProgramPipeline); \
    HookExtension(PFNGLDEBUGMESSAGECALLBACKPROC, glDebugMessageCallback); \
    HookExtensionAlias(PFNGLDEBUGMESSAGECALLBACKPROC, glDebugMessageCallback, glDebugMessageCallbackARB); \
    HookExtension(PFNGLDEBUGMESSAGECONTROLPROC, glDebugMessageControl); \
    HookExtensionAlias(PFNGLDEBUGMESSAGECONTROLPROC, glDebugMessageControl, glDebugMessageControlARB); \
    HookExtension(PFNGLDEBUGMESSAGEINSERTPROC, glDebugMessageInsert); \
    HookExtensionAlias(PFNGLDEBUGMESSAGEINSERTPROC, glDebugMessageInsert, glDebugMessageInsertARB); \
    HookExtension(PFNGLPUSHDEBUGGROUPPROC, glPushDebugGroup); \
    HookExtension(PFNGLPOPDEBUGGROUPPROC, glPopDebugGroup); \
    HookExtension(PFNGLOBJECTLABELPROC, glObjectLabel); \
    HookExtension(PFNGLOBJECTPTRLABELPROC, glObjectPtrLabel); \
    HookExtension(PFNGLENABLEIPROC, glEnablei); \
    HookExtensionAlias(PFNGLENABLEIPROC, glEnablei, glEnableIndexedEXT); \
    HookExtension(PFNGLDISABLEIPROC, glDisablei); \
    HookExtensionAlias(PFNGLDISABLEIPROC, glDisablei, glDisableIndexedEXT); \
    HookExtension(PFNGLISENABLEDIPROC, glIsEnabledi); \
    HookExtensionAlias(PFNGLISENABLEDIPROC, glIsEnabledi, glIsEnabledIndexedEXT); \
    HookExtension(PFNGLISBUFFERPROC, glIsBuffer); \
    HookExtensionAlias(PFNGLISBUFFERPROC, glIsBuffer, glIsBufferARB); \
    HookExtension(PFNGLISFRAMEBUFFERPROC, glIsFramebuffer); \
    HookExtensionAlias(PFNGLISFRAMEBUFFERPROC, glIsFramebuffer, glIsFramebufferEXT); \
    HookExtension(PFNGLISPROGRAMPROC, glIsProgram); \
    HookExtension(PFNGLISPROGRAMPIPELINEPROC, glIsProgramPipeline); \
    HookExtension(PFNGLISQUERYPROC, glIsQuery); \
    HookExtensionAlias(PFNGLISQUERYPROC, glIsQuery, glIsQueryARB); \
    HookExtension(PFNGLISRENDERBUFFERPROC, glIsRenderbuffer); \
    HookExtensionAlias(PFNGLISRENDERBUFFERPROC, glIsRenderbuffer, glIsRenderbufferEXT); \
    HookExtension(PFNGLISSAMPLERPROC, glIsSampler); \
    HookExtension(PFNGLISSHADERPROC, glIsShader); \
    HookExtension(PFNGLISSYNCPROC, glIsSync); \
    HookExtension(PFNGLISTRANSFORMFEEDBACKPROC, glIsTransformFeedback); \
    HookExtension(PFNGLISVERTEXARRAYPROC, glIsVertexArray); \
    HookExtension(PFNGLGENBUFFERSPROC, glGenBuffers); \
    HookExtensionAlias(PFNGLGENBUFFERSPROC, glGenBuffers, glGenBuffersARB); \
    HookExtension(PFNGLBINDBUFFERPROC, glBindBuffer); \
    HookExtensionAlias(PFNGLBINDBUFFERPROC, glBindBuffer, glBindBufferARB); \
    HookExtension(PFNGLDRAWBUFFERSPROC, glDrawBuffers); \
    HookExtension(PFNGLGENFRAMEBUFFERSPROC, glGenFramebuffers); \
    HookExtensionAlias(PFNGLGENFRAMEBUFFERSPROC, glGenFramebuffers, glGenFramebuffersEXT); \
    HookExtension(PFNGLBINDFRAMEBUFFERPROC, glBindFramebuffer); \
    HookExtensionAlias(PFNGLBINDFRAMEBUFFERPROC, glBindFramebuffer, glBindFramebufferEXT); \
    HookExtension(PFNGLFRAMEBUFFERTEXTUREPROC, glFramebufferTexture); \
    HookExtension(PFNGLFRAMEBUFFERTEXTURE1DPROC, glFramebufferTexture1D); \
    HookExtensionAlias(PFNGLFRAMEBUFFERTEXTURE1DPROC, glFramebufferTexture1D, glFramebufferTexture1DEXT); \
    HookExtension(PFNGLFRAMEBUFFERTEXTURE2DPROC, glFramebufferTexture2D); \
    HookExtensionAlias(PFNGLFRAMEBUFFERTEXTURE2DPROC, glFramebufferTexture2D, glFramebufferTexture2DEXT); \
    HookExtension(PFNGLFRAMEBUFFERTEXTURE3DPROC, glFramebufferTexture3D); \
    HookExtensionAlias(PFNGLFRAMEBUFFERTEXTURE3DPROC, glFramebufferTexture3D, glFramebufferTexture3DEXT); \
    HookExtension(PFNGLFRAMEBUFFERRENDERBUFFERPROC, glFramebufferRenderbuffer); \
    HookExtensionAlias(PFNGLFRAMEBUFFERRENDERBUFFERPROC, glFramebufferRenderbuffer, glFramebufferRenderbufferEXT); \
    HookExtension(PFNGLFRAMEBUFFERTEXTURELAYERPROC, glFramebufferTextureLayer); \
    HookExtension(PFNGLFRAMEBUFFERPARAMETERIPROC, glFramebufferParameteri); \
    HookExtension(PFNGLDELETEFRAMEBUFFERSPROC, glDeleteFramebuffers); \
    HookExtensionAlias(PFNGLDELETEFRAMEBUFFERSPROC, glDeleteFramebuffers, glDeleteFramebuffersEXT); \
    HookExtension(PFNGLGENRENDERBUFFERSPROC, glGenRenderbuffers); \
    HookExtensionAlias(PFNGLGENRENDERBUFFERSPROC, glGenRenderbuffers, glGenRenderbuffersEXT); \
    HookExtension(PFNGLRENDERBUFFERSTORAGEPROC, glRenderbufferStorage); \
    HookExtensionAlias(PFNGLRENDERBUFFERSTORAGEPROC, glRenderbufferStorage, glRenderbufferStorageEXT); \
    HookExtension(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC, glRenderbufferStorageMultisample); \
    HookExtension(PFNGLDELETERENDERBUFFERSPROC, glDeleteRenderbuffers); \
    HookExtensionAlias(PFNGLDELETERENDERBUFFERSPROC, glDeleteRenderbuffers, glDeleteRenderbuffersEXT); \
    HookExtension(PFNGLBINDRENDERBUFFERPROC, glBindRenderbuffer); \
    HookExtensionAlias(PFNGLBINDRENDERBUFFERPROC, glBindRenderbuffer, glBindRenderbufferEXT); \
    HookExtension(PFNGLFENCESYNCPROC, glFenceSync); \
    HookExtension(PFNGLCLIENTWAITSYNCPROC, glClientWaitSync); \
    HookExtension(PFNGLWAITSYNCPROC, glWaitSync); \
    HookExtension(PFNGLDELETESYNCPROC, glDeleteSync); \
    HookExtension(PFNGLGENQUERIESPROC, glGenQueries); \
    HookExtensionAlias(PFNGLGENQUERIESPROC, glGenQueries, glGenQueriesARB); \
    HookExtension(PFNGLBEGINQUERYPROC, glBeginQuery); \
    HookExtensionAlias(PFNGLBEGINQUERYPROC, glBeginQuery, glBeginQueryARB); \
    HookExtension(PFNGLBEGINQUERYINDEXEDPROC, glBeginQueryIndexed); \
    HookExtension(PFNGLENDQUERYPROC, glEndQuery); \
    HookExtensionAlias(PFNGLENDQUERYPROC, glEndQuery, glEndQueryARB); \
    HookExtension(PFNGLENDQUERYINDEXEDPROC, glEndQueryIndexed); \
    HookExtension(PFNGLBEGINCONDITIONALRENDERPROC, glBeginConditionalRender); \
    HookExtension(PFNGLENDCONDITIONALRENDERPROC, glEndConditionalRender); \
    HookExtension(PFNGLQUERYCOUNTERPROC, glQueryCounter); \
    HookExtension(PFNGLDELETEQUERIESPROC, glDeleteQueries); \
    HookExtensionAlias(PFNGLDELETEQUERIESPROC, glDeleteQueries, glDeleteQueriesARB); \
    HookExtension(PFNGLBUFFERDATAPROC, glBufferData); \
    HookExtensionAlias(PFNGLBUFFERDATAPROC, glBufferData, glBufferDataARB); \
    HookExtension(PFNGLBUFFERSTORAGEPROC, glBufferStorage); \
    HookExtension(PFNGLBUFFERSUBDATAPROC, glBufferSubData); \
    HookExtensionAlias(PFNGLBUFFERSUBDATAPROC, glBufferSubData, glBufferSubDataARB); \
    HookExtension(PFNGLCOPYBUFFERSUBDATAPROC, glCopyBufferSubData); \
    HookExtension(PFNGLBINDBUFFERBASEPROC, glBindBufferBase); \
    HookExtension(PFNGLBINDBUFFERRANGEPROC, glBindBufferRange); \
    HookExtension(PFNGLBINDBUFFERSBASEPROC, glBindBuffersBase); \
    HookExtension(PFNGLBINDBUFFERSRANGEPROC, glBindBuffersRange); \
    HookExtension(PFNGLMAPBUFFERPROC, glMapBuffer); \
    HookExtensionAlias(PFNGLMAPBUFFERPROC, glMapBuffer, glMapBufferARB); \
    HookExtension(PFNGLMAPBUFFERRANGEPROC, glMapBufferRange); \
    HookExtension(PFNGLFLUSHMAPPEDBUFFERRANGEPROC, glFlushMappedBufferRange); \
    HookExtension(PFNGLUNMAPBUFFERPROC, glUnmapBuffer); \
    HookExtensionAlias(PFNGLUNMAPBUFFERPROC, glUnmapBuffer, glUnmapBufferARB); \
    HookExtension(PFNGLTRANSFORMFEEDBACKVARYINGSPROC, glTransformFeedbackVaryings); \
    HookExtension(PFNGLGENTRANSFORMFEEDBACKSPROC, glGenTransformFeedbacks); \
    HookExtension(PFNGLDELETETRANSFORMFEEDBACKSPROC, glDeleteTransformFeedbacks); \
    HookExtension(PFNGLBINDTRANSFORMFEEDBACKPROC, glBindTransformFeedback); \
    HookExtension(PFNGLBEGINTRANSFORMFEEDBACKPROC, glBeginTransformFeedback); \
    HookExtension(PFNGLPAUSETRANSFORMFEEDBACKPROC, glPauseTransformFeedback); \
    HookExtension(PFNGLRESUMETRANSFORMFEEDBACKPROC, glResumeTransformFeedback); \
    HookExtension(PFNGLENDTRANSFORMFEEDBACKPROC, glEndTransformFeedback); \
    HookExtension(PFNGLDRAWTRANSFORMFEEDBACKPROC, glDrawTransformFeedback); \
    HookExtension(PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC, glDrawTransformFeedbackInstanced); \
    HookExtension(PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC, glDrawTransformFeedbackStream); \
    HookExtension(PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC, glDrawTransformFeedbackStreamInstanced); \
    HookExtension(PFNGLDELETEBUFFERSPROC, glDeleteBuffers); \
    HookExtensionAlias(PFNGLDELETEBUFFERSPROC, glDeleteBuffers, glDeleteBuffersARB); \
    HookExtension(PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays); \
    HookExtension(PFNGLBINDVERTEXARRAYPROC, glBindVertexArray); \
    HookExtension(PFNGLDELETEVERTEXARRAYSPROC, glDeleteVertexArrays); \
    HookExtension(PFNGLVERTEXATTRIB1DPROC, glVertexAttrib1d); \
    HookExtensionAlias(PFNGLVERTEXATTRIB1DPROC, glVertexAttrib1d, glVertexAttrib1dARB); \
    HookExtension(PFNGLVERTEXATTRIB1DVPROC, glVertexAttrib1dv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB1DVPROC, glVertexAttrib1dv, glVertexAttrib1dvARB); \
    HookExtension(PFNGLVERTEXATTRIB1FPROC, glVertexAttrib1f); \
    HookExtensionAlias(PFNGLVERTEXATTRIB1FPROC, glVertexAttrib1f, glVertexAttrib1fARB); \
    HookExtension(PFNGLVERTEXATTRIB1FVPROC, glVertexAttrib1fv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB1FVPROC, glVertexAttrib1fv, glVertexAttrib1fvARB); \
    HookExtension(PFNGLVERTEXATTRIB1SPROC, glVertexAttrib1s); \
    HookExtensionAlias(PFNGLVERTEXATTRIB1SPROC, glVertexAttrib1s, glVertexAttrib1sARB); \
    HookExtension(PFNGLVERTEXATTRIB1SVPROC, glVertexAttrib1sv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB1SVPROC, glVertexAttrib1sv, glVertexAttrib1svARB); \
    HookExtension(PFNGLVERTEXATTRIB2DPROC, glVertexAttrib2d); \
    HookExtensionAlias(PFNGLVERTEXATTRIB2DPROC, glVertexAttrib2d, glVertexAttrib2dARB); \
    HookExtension(PFNGLVERTEXATTRIB2DVPROC, glVertexAttrib2dv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB2DVPROC, glVertexAttrib2dv, glVertexAttrib2dvARB); \
    HookExtension(PFNGLVERTEXATTRIB2FPROC, glVertexAttrib2f); \
    HookExtensionAlias(PFNGLVERTEXATTRIB2FPROC, glVertexAttrib2f, glVertexAttrib2fARB); \
    HookExtension(PFNGLVERTEXATTRIB2FVPROC, glVertexAttrib2fv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB2FVPROC, glVertexAttrib2fv, glVertexAttrib2fvARB); \
    HookExtension(PFNGLVERTEXATTRIB2SPROC, glVertexAttrib2s); \
    HookExtensionAlias(PFNGLVERTEXATTRIB2SPROC, glVertexAttrib2s, glVertexAttrib2sARB); \
    HookExtension(PFNGLVERTEXATTRIB2SVPROC, glVertexAttrib2sv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB2SVPROC, glVertexAttrib2sv, glVertexAttrib2svARB); \
    HookExtension(PFNGLVERTEXATTRIB3DPROC, glVertexAttrib3d); \
    HookExtensionAlias(PFNGLVERTEXATTRIB3DPROC, glVertexAttrib3d, glVertexAttrib3dARB); \
    HookExtension(PFNGLVERTEXATTRIB3DVPROC, glVertexAttrib3dv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB3DVPROC, glVertexAttrib3dv, glVertexAttrib3dvARB); \
    HookExtension(PFNGLVERTEXATTRIB3FPROC, glVertexAttrib3f); \
    HookExtensionAlias(PFNGLVERTEXATTRIB3FPROC, glVertexAttrib3f, glVertexAttrib3fARB); \
    HookExtension(PFNGLVERTEXATTRIB3FVPROC, glVertexAttrib3fv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB3FVPROC, glVertexAttrib3fv, glVertexAttrib3fvARB); \
    HookExtension(PFNGLVERTEXATTRIB3SPROC, glVertexAttrib3s); \
    HookExtensionAlias(PFNGLVERTEXATTRIB3SPROC, glVertexAttrib3s, glVertexAttrib3sARB); \
    HookExtension(PFNGLVERTEXATTRIB3SVPROC, glVertexAttrib3sv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB3SVPROC, glVertexAttrib3sv, glVertexAttrib3svARB); \
    HookExtension(PFNGLVERTEXATTRIB4NBVPROC, glVertexAttrib4Nbv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB4NBVPROC, glVertexAttrib4Nbv, glVertexAttrib4NbvARB); \
    HookExtension(PFNGLVERTEXATTRIB4NIVPROC, glVertexAttrib4Niv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB4NIVPROC, glVertexAttrib4Niv, glVertexAttrib4NivARB); \
    HookExtension(PFNGLVERTEXATTRIB4NSVPROC, glVertexAttrib4Nsv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB4NSVPROC, glVertexAttrib4Nsv, glVertexAttrib4NsvARB); \
    HookExtension(PFNGLVERTEXATTRIB4NUBPROC, glVertexAttrib4Nub); \
    HookExtension(PFNGLVERTEXATTRIB4NUBVPROC, glVertexAttrib4Nubv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB4NUBVPROC, glVertexAttrib4Nubv, glVertexAttrib4NubvARB); \
    HookExtension(PFNGLVERTEXATTRIB4NUIVPROC, glVertexAttrib4Nuiv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB4NUIVPROC, glVertexAttrib4Nuiv, glVertexAttrib4NuivARB); \
    HookExtension(PFNGLVERTEXATTRIB4NUSVPROC, glVertexAttrib4Nusv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB4NUSVPROC, glVertexAttrib4Nusv, glVertexAttrib4NusvARB); \
    HookExtension(PFNGLVERTEXATTRIB4BVPROC, glVertexAttrib4bv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB4BVPROC, glVertexAttrib4bv, glVertexAttrib4bvARB); \
    HookExtension(PFNGLVERTEXATTRIB4DPROC, glVertexAttrib4d); \
    HookExtensionAlias(PFNGLVERTEXATTRIB4DPROC, glVertexAttrib4d, glVertexAttrib4dARB); \
    HookExtension(PFNGLVERTEXATTRIB4DVPROC, glVertexAttrib4dv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB4DVPROC, glVertexAttrib4dv, glVertexAttrib4dvARB); \
    HookExtension(PFNGLVERTEXATTRIB4FPROC, glVertexAttrib4f); \
    HookExtensionAlias(PFNGLVERTEXATTRIB4FPROC, glVertexAttrib4f, glVertexAttrib4fARB); \
    HookExtension(PFNGLVERTEXATTRIB4FVPROC, glVertexAttrib4fv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB4FVPROC, glVertexAttrib4fv, glVertexAttrib4fvARB); \
    HookExtension(PFNGLVERTEXATTRIB4IVPROC, glVertexAttrib4iv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB4IVPROC, glVertexAttrib4iv, glVertexAttrib4ivARB); \
    HookExtension(PFNGLVERTEXATTRIB4SPROC, glVertexAttrib4s); \
    HookExtensionAlias(PFNGLVERTEXATTRIB4SPROC, glVertexAttrib4s, glVertexAttrib4sARB); \
    HookExtension(PFNGLVERTEXATTRIB4SVPROC, glVertexAttrib4sv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB4SVPROC, glVertexAttrib4sv, glVertexAttrib4svARB); \
    HookExtension(PFNGLVERTEXATTRIB4UBVPROC, glVertexAttrib4ubv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB4UBVPROC, glVertexAttrib4ubv, glVertexAttrib4ubvARB); \
    HookExtension(PFNGLVERTEXATTRIB4UIVPROC, glVertexAttrib4uiv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB4UIVPROC, glVertexAttrib4uiv, glVertexAttrib4uivARB); \
    HookExtension(PFNGLVERTEXATTRIB4USVPROC, glVertexAttrib4usv); \
    HookExtensionAlias(PFNGLVERTEXATTRIB4USVPROC, glVertexAttrib4usv, glVertexAttrib4usvARB); \
    HookExtension(PFNGLVERTEXATTRIBI1IPROC, glVertexAttribI1i); \
    HookExtension(PFNGLVERTEXATTRIBI1IVPROC, glVertexAttribI1iv); \
    HookExtension(PFNGLVERTEXATTRIBI1UIPROC, glVertexAttribI1ui); \
    HookExtension(PFNGLVERTEXATTRIBI1UIVPROC, glVertexAttribI1uiv); \
    HookExtension(PFNGLVERTEXATTRIBI2IPROC, glVertexAttribI2i); \
    HookExtension(PFNGLVERTEXATTRIBI2IVPROC, glVertexAttribI2iv); \
    HookExtension(PFNGLVERTEXATTRIBI2UIPROC, glVertexAttribI2ui); \
    HookExtension(PFNGLVERTEXATTRIBI2UIVPROC, glVertexAttribI2uiv); \
    HookExtension(PFNGLVERTEXATTRIBI3IPROC, glVertexAttribI3i); \
    HookExtension(PFNGLVERTEXATTRIBI3IVPROC, glVertexAttribI3iv); \
    HookExtension(PFNGLVERTEXATTRIBI3UIPROC, glVertexAttribI3ui); \
    HookExtension(PFNGLVERTEXATTRIBI3UIVPROC, glVertexAttribI3uiv); \
    HookExtension(PFNGLVERTEXATTRIBI4BVPROC, glVertexAttribI4bv); \
    HookExtension(PFNGLVERTEXATTRIBI4IPROC, glVertexAttribI4i); \
    HookExtension(PFNGLVERTEXATTRIBI4IVPROC, glVertexAttribI4iv); \
    HookExtension(PFNGLVERTEXATTRIBI4SVPROC, glVertexAttribI4sv); \
    HookExtension(PFNGLVERTEXATTRIBI4UBVPROC, glVertexAttribI4ubv); \
    HookExtension(PFNGLVERTEXATTRIBI4UIPROC, glVertexAttribI4ui); \
    HookExtension(PFNGLVERTEXATTRIBI4UIVPROC, glVertexAttribI4uiv); \
    HookExtension(PFNGLVERTEXATTRIBI4USVPROC, glVertexAttribI4usv); \
    HookExtension(PFNGLVERTEXATTRIBL1DPROC, glVertexAttribL1d); \
    HookExtension(PFNGLVERTEXATTRIBL1DVPROC, glVertexAttribL1dv); \
    HookExtension(PFNGLVERTEXATTRIBL2DPROC, glVertexAttribL2d); \
    HookExtension(PFNGLVERTEXATTRIBL2DVPROC, glVertexAttribL2dv); \
    HookExtension(PFNGLVERTEXATTRIBL3DPROC, glVertexAttribL3d); \
    HookExtension(PFNGLVERTEXATTRIBL3DVPROC, glVertexAttribL3dv); \
    HookExtension(PFNGLVERTEXATTRIBL4DPROC, glVertexAttribL4d); \
    HookExtension(PFNGLVERTEXATTRIBL4DVPROC, glVertexAttribL4dv); \
    HookExtension(PFNGLVERTEXATTRIBP1UIPROC, glVertexAttribP1ui); \
    HookExtension(PFNGLVERTEXATTRIBP1UIVPROC, glVertexAttribP1uiv); \
    HookExtension(PFNGLVERTEXATTRIBP2UIPROC, glVertexAttribP2ui); \
    HookExtension(PFNGLVERTEXATTRIBP2UIVPROC, glVertexAttribP2uiv); \
    HookExtension(PFNGLVERTEXATTRIBP3UIPROC, glVertexAttribP3ui); \
    HookExtension(PFNGLVERTEXATTRIBP3UIVPROC, glVertexAttribP3uiv); \
    HookExtension(PFNGLVERTEXATTRIBP4UIPROC, glVertexAttribP4ui); \
    HookExtension(PFNGLVERTEXATTRIBP4UIVPROC, glVertexAttribP4uiv); \
    HookExtension(PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer); \
    HookExtensionAlias(PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer, glVertexAttribPointerARB); \
    HookExtension(PFNGLVERTEXATTRIBIPOINTERPROC, glVertexAttribIPointer); \
    HookExtension(PFNGLVERTEXATTRIBLPOINTERPROC, glVertexAttribLPointer); \
    HookExtension(PFNGLVERTEXATTRIBBINDINGPROC, glVertexAttribBinding); \
    HookExtension(PFNGLVERTEXATTRIBFORMATPROC, glVertexAttribFormat); \
    HookExtension(PFNGLVERTEXATTRIBIFORMATPROC, glVertexAttribIFormat); \
    HookExtension(PFNGLVERTEXATTRIBLFORMATPROC, glVertexAttribLFormat); \
    HookExtension(PFNGLVERTEXATTRIBDIVISORPROC, glVertexAttribDivisor); \
    HookExtension(PFNGLBINDATTRIBLOCATIONPROC, glBindAttribLocation); \
    HookExtension(PFNGLBINDFRAGDATALOCATIONPROC, glBindFragDataLocation); \
    HookExtension(PFNGLBINDFRAGDATALOCATIONINDEXEDPROC, glBindFragDataLocationIndexed); \
    HookExtension(PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray); \
    HookExtensionAlias(PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray, glEnableVertexAttribArrayARB); \
    HookExtension(PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray); \
    HookExtensionAlias(PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray, glDisableVertexAttribArrayARB); \
    HookExtension(PFNGLBINDVERTEXBUFFERPROC, glBindVertexBuffer); \
    HookExtension(PFNGLBINDVERTEXBUFFERSPROC, glBindVertexBuffers); \
    HookExtension(PFNGLVERTEXBINDINGDIVISORPROC, glVertexBindingDivisor); \
    HookExtension(PFNGLBINDIMAGETEXTUREPROC, glBindImageTexture); \
    HookExtension(PFNGLBINDIMAGETEXTURESPROC, glBindImageTextures); \
    HookExtension(PFNGLGENSAMPLERSPROC, glGenSamplers); \
    HookExtension(PFNGLBINDSAMPLERPROC, glBindSampler); \
    HookExtension(PFNGLBINDSAMPLERSPROC, glBindSamplers); \
    HookExtension(PFNGLBINDTEXTURESPROC, glBindTextures); \
    HookExtension(PFNGLDELETESAMPLERSPROC, glDeleteSamplers); \
    HookExtension(PFNGLSAMPLERPARAMETERIPROC, glSamplerParameteri); \
    HookExtension(PFNGLSAMPLERPARAMETERFPROC, glSamplerParameterf); \
    HookExtension(PFNGLSAMPLERPARAMETERIVPROC, glSamplerParameteriv); \
    HookExtension(PFNGLSAMPLERPARAMETERFVPROC, glSamplerParameterfv); \
    HookExtension(PFNGLSAMPLERPARAMETERIIVPROC, glSamplerParameterIiv); \
    HookExtension(PFNGLSAMPLERPARAMETERIUIVPROC, glSamplerParameterIuiv); \
    HookExtension(PFNGLPATCHPARAMETERIPROC, glPatchParameteri); \
    HookExtension(PFNGLPATCHPARAMETERFVPROC, glPatchParameterfv); \
    HookExtension(PFNGLPOINTPARAMETERFPROC, glPointParameterf); \
    HookExtensionAlias(PFNGLPOINTPARAMETERFPROC, glPointParameterf, glPointParameterfARB); \
    HookExtension(PFNGLPOINTPARAMETERFVPROC, glPointParameterfv); \
    HookExtensionAlias(PFNGLPOINTPARAMETERFVPROC, glPointParameterfv, glPointParameterfvARB); \
    HookExtension(PFNGLPOINTPARAMETERIPROC, glPointParameteri); \
    HookExtension(PFNGLPOINTPARAMETERIVPROC, glPointParameteriv); \
    HookExtension(PFNGLDISPATCHCOMPUTEPROC, glDispatchCompute); \
    HookExtension(PFNGLDISPATCHCOMPUTEINDIRECTPROC, glDispatchComputeIndirect); \
    HookExtension(PFNGLMEMORYBARRIERPROC, glMemoryBarrier); \
    HookExtension(PFNGLMEMORYBARRIERBYREGIONPROC, glMemoryBarrierByRegion); \
    HookExtension(PFNGLTEXTUREBARRIERPROC, glTextureBarrier); \
    HookExtension(PFNGLCLEARDEPTHFPROC, glClearDepthf); \
    HookExtension(PFNGLCLEARBUFFERFVPROC, glClearBufferfv); \
    HookExtension(PFNGLCLEARBUFFERIVPROC, glClearBufferiv); \
    HookExtension(PFNGLCLEARBUFFERUIVPROC, glClearBufferuiv); \
    HookExtension(PFNGLCLEARBUFFERFIPROC, glClearBufferfi); \
    HookExtension(PFNGLCLEARBUFFERDATAPROC, glClearBufferData); \
    HookExtension(PFNGLCLEARBUFFERSUBDATAPROC, glClearBufferSubData); \
    HookExtension(PFNGLCLEARTEXIMAGEPROC, glClearTexImage); \
    HookExtension(PFNGLCLEARTEXSUBIMAGEPROC, glClearTexSubImage); \
    HookExtension(PFNGLINVALIDATEBUFFERDATAPROC, glInvalidateBufferData); \
    HookExtension(PFNGLINVALIDATEBUFFERSUBDATAPROC, glInvalidateBufferSubData); \
    HookExtension(PFNGLINVALIDATEFRAMEBUFFERPROC, glInvalidateFramebuffer); \
    HookExtension(PFNGLINVALIDATESUBFRAMEBUFFERPROC, glInvalidateSubFramebuffer); \
    HookExtension(PFNGLINVALIDATETEXIMAGEPROC, glInvalidateTexImage); \
    HookExtension(PFNGLINVALIDATETEXSUBIMAGEPROC, glInvalidateTexSubImage); \
    HookExtension(PFNGLSCISSORARRAYVPROC, glScissorArrayv); \
    HookExtension(PFNGLSCISSORINDEXEDPROC, glScissorIndexed); \
    HookExtension(PFNGLSCISSORINDEXEDVPROC, glScissorIndexedv); \
    HookExtension(PFNGLVIEWPORTINDEXEDFPROC, glViewportIndexedf); \
    HookExtension(PFNGLVIEWPORTINDEXEDFVPROC, glViewportIndexedfv); \
    HookExtension(PFNGLVIEWPORTARRAYVPROC, glViewportArrayv); \
    HookExtension(PFNGLUNIFORMBLOCKBINDINGPROC, glUniformBlockBinding); \
    HookExtension(PFNGLSHADERSTORAGEBLOCKBINDINGPROC, glShaderStorageBlockBinding); \
    HookExtension(PFNGLUNIFORMSUBROUTINESUIVPROC, glUniformSubroutinesuiv); \
    HookExtension(PFNGLUNIFORM1FPROC,   glUniform1f); \
    HookExtension(PFNGLUNIFORM1IPROC,   glUniform1i); \
    HookExtension(PFNGLUNIFORM1UIPROC,  glUniform1ui); \
    HookExtension(PFNGLUNIFORM1DPROC,   glUniform1d); \
    HookExtension(PFNGLUNIFORM2FPROC,   glUniform2f); \
    HookExtension(PFNGLUNIFORM2IPROC,   glUniform2i); \
    HookExtension(PFNGLUNIFORM2UIPROC,  glUniform2ui); \
    HookExtension(PFNGLUNIFORM2DPROC,   glUniform2d); \
    HookExtension(PFNGLUNIFORM3FPROC,   glUniform3f); \
    HookExtension(PFNGLUNIFORM3IPROC,   glUniform3i); \
    HookExtension(PFNGLUNIFORM3UIPROC,  glUniform3ui); \
    HookExtension(PFNGLUNIFORM3DPROC,   glUniform3d); \
    HookExtension(PFNGLUNIFORM4FPROC,   glUniform4f); \
    HookExtension(PFNGLUNIFORM4IPROC,   glUniform4i); \
    HookExtension(PFNGLUNIFORM4UIPROC,  glUniform4ui); \
    HookExtension(PFNGLUNIFORM4DPROC,   glUniform4d); \
    HookExtension(PFNGLUNIFORM1FVPROC,  glUniform1fv); \
    HookExtension(PFNGLUNIFORM1IVPROC,  glUniform1iv); \
    HookExtension(PFNGLUNIFORM1UIVPROC, glUniform1uiv); \
    HookExtension(PFNGLUNIFORM1DVPROC,  glUniform1dv); \
    HookExtension(PFNGLUNIFORM2FVPROC,  glUniform2fv); \
    HookExtension(PFNGLUNIFORM2IVPROC,  glUniform2iv); \
    HookExtension(PFNGLUNIFORM2UIVPROC, glUniform2uiv); \
    HookExtension(PFNGLUNIFORM2DVPROC,  glUniform2dv); \
    HookExtension(PFNGLUNIFORM3FVPROC,  glUniform3fv); \
    HookExtension(PFNGLUNIFORM3IVPROC,  glUniform3iv); \
    HookExtension(PFNGLUNIFORM3UIVPROC, glUniform3uiv); \
    HookExtension(PFNGLUNIFORM3DVPROC,  glUniform3dv); \
    HookExtension(PFNGLUNIFORM4FVPROC,  glUniform4fv); \
    HookExtension(PFNGLUNIFORM4IVPROC,  glUniform4iv); \
    HookExtension(PFNGLUNIFORM4UIVPROC, glUniform4uiv); \
    HookExtension(PFNGLUNIFORM4DVPROC,  glUniform4dv); \
    HookExtension(PFNGLUNIFORMMATRIX2FVPROC,   glUniformMatrix2fv); \
    HookExtension(PFNGLUNIFORMMATRIX2X3FVPROC, glUniformMatrix2x3fv); \
    HookExtension(PFNGLUNIFORMMATRIX2X4FVPROC, glUniformMatrix2x4fv); \
    HookExtension(PFNGLUNIFORMMATRIX3FVPROC,   glUniformMatrix3fv); \
    HookExtension(PFNGLUNIFORMMATRIX3X2FVPROC, glUniformMatrix3x2fv); \
    HookExtension(PFNGLUNIFORMMATRIX3X4FVPROC, glUniformMatrix3x4fv); \
    HookExtension(PFNGLUNIFORMMATRIX4FVPROC,   glUniformMatrix4fv); \
    HookExtension(PFNGLUNIFORMMATRIX4X2FVPROC, glUniformMatrix4x2fv); \
    HookExtension(PFNGLUNIFORMMATRIX4X3FVPROC, glUniformMatrix4x3fv); \
    HookExtension(PFNGLUNIFORMMATRIX2DVPROC,   glUniformMatrix2dv); \
    HookExtension(PFNGLUNIFORMMATRIX2X3DVPROC, glUniformMatrix2x3dv); \
    HookExtension(PFNGLUNIFORMMATRIX2X4DVPROC, glUniformMatrix2x4dv); \
    HookExtension(PFNGLUNIFORMMATRIX3DVPROC,   glUniformMatrix3dv); \
    HookExtension(PFNGLUNIFORMMATRIX3X2DVPROC, glUniformMatrix3x2dv); \
    HookExtension(PFNGLUNIFORMMATRIX3X4DVPROC, glUniformMatrix3x4dv); \
    HookExtension(PFNGLUNIFORMMATRIX4DVPROC,   glUniformMatrix4dv); \
    HookExtension(PFNGLUNIFORMMATRIX4X2DVPROC, glUniformMatrix4x2dv); \
    HookExtension(PFNGLUNIFORMMATRIX4X3DVPROC, glUniformMatrix4x3dv); \
    HookExtension(PFNGLPROGRAMUNIFORM1FPROC,   glProgramUniform1f); \
    HookExtension(PFNGLPROGRAMUNIFORM1IPROC,   glProgramUniform1i); \
    HookExtension(PFNGLPROGRAMUNIFORM1UIPROC,  glProgramUniform1ui); \
    HookExtension(PFNGLPROGRAMUNIFORM1DPROC,   glProgramUniform1d); \
    HookExtension(PFNGLPROGRAMUNIFORM2FPROC,   glProgramUniform2f); \
    HookExtension(PFNGLPROGRAMUNIFORM2IPROC,   glProgramUniform2i); \
    HookExtension(PFNGLPROGRAMUNIFORM2UIPROC,  glProgramUniform2ui); \
    HookExtension(PFNGLPROGRAMUNIFORM2DPROC,   glProgramUniform2d); \
    HookExtension(PFNGLPROGRAMUNIFORM3FPROC,   glProgramUniform3f); \
    HookExtension(PFNGLPROGRAMUNIFORM3IPROC,   glProgramUniform3i); \
    HookExtension(PFNGLPROGRAMUNIFORM3UIPROC,  glProgramUniform3ui); \
    HookExtension(PFNGLPROGRAMUNIFORM3DPROC,   glProgramUniform3d); \
    HookExtension(PFNGLPROGRAMUNIFORM4FPROC,   glProgramUniform4f); \
    HookExtension(PFNGLPROGRAMUNIFORM4IPROC,   glProgramUniform4i); \
    HookExtension(PFNGLPROGRAMUNIFORM4UIPROC,  glProgramUniform4ui); \
    HookExtension(PFNGLPROGRAMUNIFORM4DPROC,   glProgramUniform4d); \
    HookExtension(PFNGLPROGRAMUNIFORM1FVPROC,  glProgramUniform1fv); \
    HookExtension(PFNGLPROGRAMUNIFORM1IVPROC,  glProgramUniform1iv); \
    HookExtension(PFNGLPROGRAMUNIFORM1UIVPROC, glProgramUniform1uiv); \
    HookExtension(PFNGLPROGRAMUNIFORM1DVPROC,  glProgramUniform1dv); \
    HookExtension(PFNGLPROGRAMUNIFORM2FVPROC,  glProgramUniform2fv); \
    HookExtension(PFNGLPROGRAMUNIFORM2IVPROC,  glProgramUniform2iv); \
    HookExtension(PFNGLPROGRAMUNIFORM2UIVPROC, glProgramUniform2uiv); \
    HookExtension(PFNGLPROGRAMUNIFORM2DVPROC,  glProgramUniform2dv); \
    HookExtension(PFNGLPROGRAMUNIFORM3FVPROC,  glProgramUniform3fv); \
    HookExtension(PFNGLPROGRAMUNIFORM3IVPROC,  glProgramUniform3iv); \
    HookExtension(PFNGLPROGRAMUNIFORM3UIVPROC, glProgramUniform3uiv); \
    HookExtension(PFNGLPROGRAMUNIFORM3DVPROC,  glProgramUniform3dv); \
    HookExtension(PFNGLPROGRAMUNIFORM4FVPROC,  glProgramUniform4fv); \
    HookExtension(PFNGLPROGRAMUNIFORM4IVPROC,  glProgramUniform4iv); \
    HookExtension(PFNGLPROGRAMUNIFORM4UIVPROC, glProgramUniform4uiv); \
    HookExtension(PFNGLPROGRAMUNIFORM4DVPROC,  glProgramUniform4dv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX2FVPROC,   glProgramUniformMatrix2fv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC, glProgramUniformMatrix2x3fv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC, glProgramUniformMatrix2x4fv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX3FVPROC,   glProgramUniformMatrix3fv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC, glProgramUniformMatrix3x2fv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC, glProgramUniformMatrix3x4fv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX4FVPROC,   glProgramUniformMatrix4fv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC, glProgramUniformMatrix4x2fv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC, glProgramUniformMatrix4x3fv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX2DVPROC,   glProgramUniformMatrix2dv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC, glProgramUniformMatrix2x3dv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC, glProgramUniformMatrix2x4dv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX3DVPROC,   glProgramUniformMatrix3dv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC, glProgramUniformMatrix3x2dv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC, glProgramUniformMatrix3x4dv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX4DVPROC,   glProgramUniformMatrix4dv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC, glProgramUniformMatrix4x2dv); \
    HookExtension(PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC, glProgramUniformMatrix4x3dv); \
    HookExtension(PFNGLDRAWRANGEELEMENTSPROC, glDrawRangeElements); \
    HookExtension(PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC, glDrawRangeElementsBaseVertex); \
    HookExtension(PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC, glDrawArraysInstancedBaseInstance); \
    HookExtension(PFNGLDRAWARRAYSINSTANCEDPROC, glDrawArraysInstanced); \
    HookExtension(PFNGLDRAWELEMENTSINSTANCEDPROC, glDrawElementsInstanced); \
    HookExtension(PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC, glDrawElementsInstancedBaseInstance); \
    HookExtension(PFNGLDRAWELEMENTSBASEVERTEXPROC, glDrawElementsBaseVertex); \
    HookExtension(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC, glDrawElementsInstancedBaseVertex); \
    HookExtension(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC, glDrawElementsInstancedBaseVertexBaseInstance); \
    HookExtension(PFNGLMULTIDRAWARRAYSPROC, glMultiDrawArrays); \
    HookExtension(PFNGLMULTIDRAWELEMENTSPROC, glMultiDrawElements); \
    HookExtension(PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC, glMultiDrawElementsBaseVertex); \
    HookExtension(PFNGLMULTIDRAWARRAYSINDIRECTPROC, glMultiDrawArraysIndirect); \
    HookExtension(PFNGLMULTIDRAWELEMENTSINDIRECTPROC, glMultiDrawElementsIndirect); \
    HookExtension(PFNGLDRAWARRAYSINDIRECTPROC, glDrawArraysIndirect); \
    HookExtension(PFNGLDRAWELEMENTSINDIRECTPROC, glDrawElementsIndirect); \
    HookExtension(PFNGLBLITFRAMEBUFFERPROC, glBlitFramebuffer); \
    HookExtension(PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC, glCheckNamedFramebufferStatusEXT); \
    HookExtension(PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC, glCompressedTextureImage1DEXT); \
    HookExtension(PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC, glCompressedTextureImage2DEXT); \
    HookExtension(PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC, glCompressedTextureImage3DEXT); \
    HookExtension(PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC, glCompressedTextureSubImage1DEXT); \
    HookExtension(PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC, glCompressedTextureSubImage2DEXT); \
    HookExtension(PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC, glCompressedTextureSubImage3DEXT); \
    HookExtension(PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC, glFramebufferDrawBuffersEXT); \
    HookExtension(PFNGLGENERATETEXTUREMIPMAPEXTPROC, glGenerateTextureMipmapEXT); \
    HookExtension(PFNGLGETPOINTERI_VEXTPROC, glGetPointeri_vEXT); \
    HookExtension(PFNGLGETDOUBLEINDEXEDVEXTPROC, glGetDoubleIndexedvEXT); \
    HookExtension(PFNGLGETPOINTERINDEXEDVEXTPROC, glGetPointerIndexedvEXT); \
    HookExtension(PFNGLGETINTEGERINDEXEDVEXTPROC, glGetIntegerIndexedvEXT); \
    HookExtension(PFNGLGETBOOLEANINDEXEDVEXTPROC, glGetBooleanIndexedvEXT); \
    HookExtension(PFNGLGETFLOATINDEXEDVEXTPROC, glGetFloatIndexedvEXT); \
    HookExtension(PFNGLGETMULTITEXIMAGEEXTPROC, glGetMultiTexImageEXT); \
    HookExtension(PFNGLGETMULTITEXPARAMETERFVEXTPROC, glGetMultiTexParameterfvEXT); \
    HookExtension(PFNGLGETMULTITEXPARAMETERIVEXTPROC, glGetMultiTexParameterivEXT); \
    HookExtension(PFNGLGETMULTITEXPARAMETERIIVEXTPROC, glGetMultiTexParameterIivEXT); \
    HookExtension(PFNGLGETMULTITEXPARAMETERIUIVEXTPROC, glGetMultiTexParameterIuivEXT); \
    HookExtension(PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC, glGetMultiTexLevelParameterfvEXT); \
    HookExtension(PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC, glGetMultiTexLevelParameterivEXT); \
    HookExtension(PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC, glGetCompressedMultiTexImageEXT); \
    HookExtension(PFNGLGETNAMEDBUFFERPOINTERVEXTPROC, glGetNamedBufferPointervEXT); \
    HookExtension(PFNGLGETNAMEDPROGRAMIVEXTPROC, glGetNamedProgramivEXT); \
    HookExtension(PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC, glGetNamedFramebufferAttachmentParameterivEXT); \
    HookExtensionAlias(PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC, glGetNamedFramebufferAttachmentParameterivEXT, glGetNamedFramebufferAttachmentParameteriv); \
    HookExtension(PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC, glGetNamedBufferParameterivEXT); \
    HookExtensionAlias(PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC, glGetNamedBufferParameterivEXT, glGetNamedBufferParameteriv); \
    HookExtension(PFNGLGETNAMEDBUFFERSUBDATAEXTPROC, glGetNamedBufferSubDataEXT); \
    HookExtensionAlias(PFNGLGETNAMEDBUFFERSUBDATAEXTPROC, glGetNamedBufferSubDataEXT, glGetNamedBufferSubData); \
    HookExtension(PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC, glGetNamedFramebufferParameterivEXT); \
    HookExtensionAlias(PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC, glGetNamedFramebufferParameterivEXT, glGetFramebufferParameterivEXT); \
    HookExtensionAlias(PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC, glGetNamedFramebufferParameterivEXT, glGetNamedFramebufferParameteriv); \
    HookExtension(PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC, glGetNamedRenderbufferParameterivEXT); \
    HookExtensionAlias(PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC, glGetNamedRenderbufferParameterivEXT, glGetNamedRenderbufferParameteriv); \
    HookExtension(PFNGLGETVERTEXARRAYINTEGERVEXTPROC, glGetVertexArrayIntegervEXT); \
    HookExtension(PFNGLGETVERTEXARRAYPOINTERVEXTPROC, glGetVertexArrayPointervEXT); \
    HookExtension(PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC, glGetVertexArrayIntegeri_vEXT); \
    HookExtension(PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC, glGetVertexArrayPointeri_vEXT); \
    HookExtension(PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC, glGetCompressedTextureImageEXT); \
    HookExtension(PFNGLGETTEXTUREIMAGEEXTPROC, glGetTextureImageEXT); \
    HookExtension(PFNGLGETTEXTUREPARAMETERIVEXTPROC, glGetTextureParameterivEXT); \
    HookExtension(PFNGLGETTEXTUREPARAMETERFVEXTPROC, glGetTextureParameterfvEXT); \
    HookExtension(PFNGLGETTEXTUREPARAMETERIIVEXTPROC, glGetTextureParameterIivEXT); \
    HookExtension(PFNGLGETTEXTUREPARAMETERIUIVEXTPROC, glGetTextureParameterIuivEXT); \
    HookExtension(PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC, glGetTextureLevelParameterivEXT); \
    HookExtension(PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC, glGetTextureLevelParameterfvEXT); \
    HookExtension(PFNGLBINDMULTITEXTUREEXTPROC, glBindMultiTextureEXT); \
    HookExtension(PFNGLMAPNAMEDBUFFEREXTPROC, glMapNamedBufferEXT); \
    HookExtension(PFNGLMAPNAMEDBUFFERRANGEEXTPROC, glMapNamedBufferRangeEXT); \
    HookExtension(PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC, glFlushMappedNamedBufferRangeEXT); \
    HookExtension(PFNGLUNMAPNAMEDBUFFEREXTPROC, glUnmapNamedBufferEXT); \
    HookExtension(PFNGLCLEARNAMEDBUFFERDATAEXTPROC, glClearNamedBufferDataEXT); \
    HookExtension(PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC, glClearNamedBufferSubDataEXT); \
    HookExtension(PFNGLNAMEDBUFFERDATAEXTPROC, glNamedBufferDataEXT); \
    HookExtension(PFNGLNAMEDBUFFERSTORAGEEXTPROC, glNamedBufferStorageEXT); \
    HookExtension(PFNGLNAMEDBUFFERSUBDATAEXTPROC, glNamedBufferSubDataEXT); \
    HookExtension(PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC, glNamedCopyBufferSubDataEXT); \
    HookExtension(PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC, glNamedFramebufferTextureEXT); \
    HookExtension(PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC, glNamedFramebufferTexture1DEXT); \
    HookExtension(PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC, glNamedFramebufferTexture2DEXT); \
    HookExtension(PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC, glNamedFramebufferTexture3DEXT); \
    HookExtension(PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC, glNamedFramebufferRenderbufferEXT); \
    HookExtension(PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC, glNamedFramebufferTextureLayerEXT); \
    HookExtension(PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC, glNamedFramebufferParameteriEXT); \
    HookExtension(PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC, glNamedRenderbufferStorageEXT); \
    HookExtension(PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC, glNamedRenderbufferStorageMultisampleEXT); \
    HookExtension(PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC, glFramebufferDrawBufferEXT); \
    HookExtension(PFNGLFRAMEBUFFERREADBUFFEREXTPROC, glFramebufferReadBufferEXT); \
    HookExtension(PFNGLTEXTUREBUFFEREXTPROC, glTextureBufferEXT); \
    HookExtension(PFNGLTEXTUREBUFFERRANGEEXTPROC, glTextureBufferRangeEXT); \
    HookExtension(PFNGLTEXTUREIMAGE1DEXTPROC, glTextureImage1DEXT); \
    HookExtension(PFNGLTEXTUREIMAGE2DEXTPROC, glTextureImage2DEXT); \
    HookExtension(PFNGLTEXTUREIMAGE3DEXTPROC, glTextureImage3DEXT); \
    HookExtension(PFNGLTEXTUREPARAMETERFEXTPROC, glTextureParameterfEXT); \
    HookExtension(PFNGLTEXTUREPARAMETERFVEXTPROC, glTextureParameterfvEXT); \
    HookExtension(PFNGLTEXTUREPARAMETERIEXTPROC, glTextureParameteriEXT); \
    HookExtension(PFNGLTEXTUREPARAMETERIVEXTPROC, glTextureParameterivEXT); \
    HookExtension(PFNGLTEXTUREPARAMETERIIVEXTPROC, glTextureParameterIivEXT); \
    HookExtension(PFNGLTEXTUREPARAMETERIUIVEXTPROC, glTextureParameterIuivEXT); \
    HookExtension(PFNGLTEXTURESTORAGE1DEXTPROC, glTextureStorage1DEXT); \
    HookExtension(PFNGLTEXTURESTORAGE2DEXTPROC, glTextureStorage2DEXT); \
    HookExtension(PFNGLTEXTURESTORAGE3DEXTPROC, glTextureStorage3DEXT); \
    HookExtension(PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC, glTextureStorage2DMultisampleEXT); \
    HookExtension(PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC, glTextureStorage3DMultisampleEXT); \
    HookExtension(PFNGLTEXTURESUBIMAGE1DEXTPROC, glTextureSubImage1DEXT); \
    HookExtension(PFNGLTEXTURESUBIMAGE2DEXTPROC, glTextureSubImage2DEXT); \
    HookExtension(PFNGLTEXTURESUBIMAGE3DEXTPROC, glTextureSubImage3DEXT); \
    HookExtension(PFNGLCOPYTEXTUREIMAGE1DEXTPROC, glCopyTextureImage1DEXT); \
    HookExtension(PFNGLCOPYTEXTUREIMAGE2DEXTPROC, glCopyTextureImage2DEXT); \
    HookExtension(PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC, glCopyTextureSubImage1DEXT); \
    HookExtension(PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC, glCopyTextureSubImage2DEXT); \
    HookExtension(PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC, glCopyTextureSubImage3DEXT); \
    HookExtension(PFNGLMULTITEXPARAMETERIEXTPROC, glMultiTexParameteriEXT); \
    HookExtension(PFNGLMULTITEXPARAMETERIVEXTPROC, glMultiTexParameterivEXT); \
    HookExtension(PFNGLMULTITEXPARAMETERFEXTPROC, glMultiTexParameterfEXT); \
    HookExtension(PFNGLMULTITEXPARAMETERFVEXTPROC, glMultiTexParameterfvEXT); \
    HookExtension(PFNGLMULTITEXIMAGE1DEXTPROC, glMultiTexImage1DEXT); \
    HookExtension(PFNGLMULTITEXIMAGE2DEXTPROC, glMultiTexImage2DEXT); \
    HookExtension(PFNGLMULTITEXSUBIMAGE1DEXTPROC, glMultiTexSubImage1DEXT); \
    HookExtension(PFNGLMULTITEXSUBIMAGE2DEXTPROC, glMultiTexSubImage2DEXT); \
    HookExtension(PFNGLCOPYMULTITEXIMAGE1DEXTPROC, glCopyMultiTexImage1DEXT); \
    HookExtension(PFNGLCOPYMULTITEXIMAGE2DEXTPROC, glCopyMultiTexImage2DEXT); \
    HookExtension(PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC, glCopyMultiTexSubImage1DEXT); \
    HookExtension(PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC, glCopyMultiTexSubImage2DEXT); \
    HookExtension(PFNGLMULTITEXIMAGE3DEXTPROC, glMultiTexImage3DEXT); \
    HookExtension(PFNGLMULTITEXSUBIMAGE3DEXTPROC, glMultiTexSubImage3DEXT); \
    HookExtension(PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC, glCopyMultiTexSubImage3DEXT); \
    HookExtension(PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC, glCompressedMultiTexImage3DEXT); \
    HookExtension(PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC, glCompressedMultiTexImage2DEXT); \
    HookExtension(PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC, glCompressedMultiTexImage1DEXT); \
    HookExtension(PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC, glCompressedMultiTexSubImage3DEXT); \
    HookExtension(PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC, glCompressedMultiTexSubImage2DEXT); \
    HookExtension(PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC, glCompressedMultiTexSubImage1DEXT); \
    HookExtension(PFNGLMULTITEXBUFFEREXTPROC, glMultiTexBufferEXT); \
    HookExtension(PFNGLMULTITEXPARAMETERIIVEXTPROC, glMultiTexParameterIivEXT); \
    HookExtension(PFNGLMULTITEXPARAMETERIUIVEXTPROC, glMultiTexParameterIuivEXT); \
    HookExtension(PFNGLGENERATEMULTITEXMIPMAPEXTPROC, glGenerateMultiTexMipmapEXT); \
    HookExtension(PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC, glVertexArrayVertexAttribOffsetEXT); \
    HookExtension(PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC, glVertexArrayVertexAttribIOffsetEXT); \
    HookExtension(PFNGLENABLEVERTEXARRAYATTRIBEXTPROC, glEnableVertexArrayAttribEXT); \
    HookExtension(PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC, glDisableVertexArrayAttribEXT); \
    HookExtension(PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC, glVertexArrayBindVertexBufferEXT); \
    HookExtension(PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC, glVertexArrayVertexAttribFormatEXT); \
    HookExtension(PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC, glVertexArrayVertexAttribIFormatEXT); \
    HookExtension(PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC, glVertexArrayVertexAttribLFormatEXT); \
    HookExtension(PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC, glVertexArrayVertexAttribBindingEXT); \
    HookExtension(PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC, glVertexArrayVertexBindingDivisorEXT); \
    HookExtension(PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC, glVertexArrayVertexAttribLOffsetEXT); \
    HookExtension(PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC, glVertexArrayVertexAttribDivisorEXT); \
    HookExtension(PFNGLBINDTEXTUREPROC, glBindTexture); \
    HookExtension(PFNGLBLENDFUNCPROC, glBlendFunc); \
    HookExtension(PFNGLCLEARPROC, glClear); \
    HookExtension(PFNGLCLEARCOLORPROC, glClearColor); \
    HookExtension(PFNGLCLEARDEPTHPROC, glClearDepth); \
    HookExtension(PFNGLCLEARSTENCILPROC, glClearStencil); \
    HookExtension(PFNGLCOLORMASKPROC, glColorMask); \
    HookExtension(PFNGLCULLFACEPROC, glCullFace); \
    HookExtension(PFNGLDEPTHFUNCPROC, glDepthFunc); \
    HookExtension(PFNGLDEPTHMASKPROC, glDepthMask); \
    HookExtension(PFNGLDEPTHRANGEPROC, glDepthRange); \
    HookExtension(PFNGLSTENCILFUNCPROC, glStencilFunc); \
    HookExtension(PFNGLSTENCILMASKPROC, glStencilMask); \
    HookExtension(PFNGLSTENCILOPPROC, glStencilOp); \
    HookExtension(PFNGLDISABLEPROC, glDisable); \
    HookExtension(PFNGLDRAWBUFFERPROC, glDrawBuffer); \
    HookExtension(PFNGLDRAWELEMENTSPROC, glDrawElements); \
    HookExtension(PFNGLDRAWARRAYSPROC, glDrawArrays); \
    HookExtension(PFNGLENABLEPROC, glEnable); \
    HookExtension(PFNGLFLUSHPROC, glFlush); \
    HookExtension(PFNGLFINISHPROC, glFinish); \
    HookExtension(PFNGLFRONTFACEPROC, glFrontFace); \
    HookExtension(PFNGLGENTEXTURESPROC, glGenTextures); \
    HookExtension(PFNGLDELETETEXTURESPROC, glDeleteTextures); \
    HookExtension(PFNGLISENABLEDPROC, glIsEnabled); \
    HookExtension(PFNGLISTEXTUREPROC, glIsTexture); \
    HookExtension(PFNGLGETERRORPROC, glGetError); \
    HookExtension(PFNGLGETTEXLEVELPARAMETERIVPROC, glGetTexLevelParameteriv); \
    HookExtension(PFNGLGETTEXLEVELPARAMETERFVPROC, glGetTexLevelParameterfv); \
    HookExtension(PFNGLGETTEXPARAMETERFVPROC, glGetTexParameterfv); \
    HookExtension(PFNGLGETTEXPARAMETERIVPROC, glGetTexParameteriv); \
    HookExtension(PFNGLGETTEXIMAGEPROC, glGetTexImage); \
    HookExtension(PFNGLGETBOOLEANVPROC, glGetBooleanv); \
    HookExtension(PFNGLGETFLOATVPROC, glGetFloatv); \
    HookExtension(PFNGLGETDOUBLEVPROC, glGetDoublev); \
    HookExtension(PFNGLGETINTEGERVPROC, glGetIntegerv); \
    HookExtension(PFNGLGETPOINTERVPROC, glGetPointerv); \
    HookExtension(PFNGLGETSTRINGPROC, glGetString); \
    HookExtension(PFNGLHINTPROC, glHint); \
    HookExtension(PFNGLLOGICOPPROC, glLogicOp); \
    HookExtension(PFNGLPIXELSTOREIPROC, glPixelStorei); \
    HookExtension(PFNGLPIXELSTOREFPROC, glPixelStoref); \
    HookExtension(PFNGLPOLYGONMODEPROC, glPolygonMode); \
    HookExtension(PFNGLPOLYGONOFFSETPROC, glPolygonOffset); \
    HookExtension(PFNGLPOINTSIZEPROC, glPointSize); \
    HookExtension(PFNGLLINEWIDTHPROC, glLineWidth); \
    HookExtension(PFNGLREADPIXELSPROC, glReadPixels); \
    HookExtension(PFNGLREADBUFFERPROC, glReadBuffer); \
    HookExtension(PFNGLSCISSORPROC, glScissor); \
    HookExtension(PFNGLTEXIMAGE1DPROC, glTexImage1D); \
    HookExtension(PFNGLTEXIMAGE2DPROC, glTexImage2D); \
    HookExtension(PFNGLTEXSUBIMAGE1DPROC, glTexSubImage1D); \
    HookExtension(PFNGLTEXSUBIMAGE2DPROC, glTexSubImage2D); \
    HookExtension(PFNGLCOPYTEXIMAGE1DPROC, glCopyTexImage1D); \
    HookExtension(PFNGLCOPYTEXIMAGE2DPROC, glCopyTexImage2D); \
    HookExtension(PFNGLCOPYTEXSUBIMAGE1DPROC, glCopyTexSubImage1D); \
    HookExtension(PFNGLCOPYTEXSUBIMAGE2DPROC, glCopyTexSubImage2D); \
    HookExtension(PFNGLTEXPARAMETERFPROC, glTexParameterf); \
    HookExtension(PFNGLTEXPARAMETERFVPROC, glTexParameterfv); \
    HookExtension(PFNGLTEXPARAMETERIPROC, glTexParameteri); \
    HookExtension(PFNGLTEXPARAMETERIVPROC, glTexParameteriv); \
    HookExtension(PFNGLVIEWPORTPROC, glViewport); \



// dllexport functions
#define DefineDLLExportHooks() \
    HookWrapper2(void, glBindTexture, GLenum, target, GLuint, texture); \
    HookWrapper2(void, glBlendFunc, GLenum, sfactor, GLenum, dfactor); \
    HookWrapper1(void, glClear, GLbitfield, mask); \
    HookWrapper4(void, glClearColor, GLfloat, red, GLfloat, green, GLfloat, blue, GLfloat, alpha); \
    HookWrapper1(void, glClearDepth, GLdouble, depth); \
    HookWrapper1(void, glClearStencil, GLint, s); \
    HookWrapper4(void, glColorMask, GLboolean, red, GLboolean, green, GLboolean, blue, GLboolean, alpha); \
    HookWrapper1(void, glCullFace, GLenum, mode); \
    HookWrapper1(void, glDepthFunc, GLenum, func); \
    HookWrapper1(void, glDepthMask, GLboolean, flag); \
    HookWrapper2(void, glDepthRange, GLdouble, near, GLdouble, far); \
    HookWrapper3(void, glStencilFunc, GLenum, func, GLint, ref, GLuint, mask); \
    HookWrapper1(void, glStencilMask, GLuint, mask); \
    HookWrapper3(void, glStencilOp, GLenum, fail, GLenum, zfail, GLenum, zpass); \
    HookWrapper1(void, glDisable, GLenum, cap); \
    HookWrapper1(void, glDrawBuffer, GLenum, buf); \
    HookWrapper4(void, glDrawElements, GLenum, mode, GLsizei, count, GLenum, type, const void *, indices); \
    HookWrapper3(void, glDrawArrays, GLenum, mode, GLint, first, GLsizei, count); \
    HookWrapper1(void, glEnable, GLenum, cap); \
    HookWrapper0(void, glFlush); \
    HookWrapper0(void, glFinish); \
    HookWrapper1(void, glFrontFace, GLenum, mode); \
    HookWrapper2(void, glGenTextures, GLsizei, n, GLuint *, textures); \
    HookWrapper2(void, glDeleteTextures, GLsizei, n, const GLuint *, textures); \
    HookWrapper1(GLboolean, glIsEnabled, GLenum, cap); \
    HookWrapper1(GLboolean, glIsTexture, GLuint, texture); \
    HookWrapper0(GLenum, glGetError); \
    HookWrapper4(void, glGetTexLevelParameteriv, GLenum, target, GLint, level, GLenum, pname, GLint *, params); \
    HookWrapper4(void, glGetTexLevelParameterfv, GLenum, target, GLint, level, GLenum, pname, GLfloat *, params); \
    HookWrapper3(void, glGetTexParameterfv, GLenum, target, GLenum, pname, GLfloat *, params); \
    HookWrapper3(void, glGetTexParameteriv, GLenum, target, GLenum, pname, GLint *, params); \
    HookWrapper5(void, glGetTexImage, GLenum, target, GLint, level, GLenum, format, GLenum, type, void *, pixels); \
    HookWrapper2(void, glGetBooleanv, GLenum, pname, GLboolean *, data); \
    HookWrapper2(void, glGetFloatv, GLenum, pname, GLfloat *, data); \
    HookWrapper2(void, glGetDoublev, GLenum, pname, GLdouble *, data); \
    HookWrapper2(void, glGetIntegerv, GLenum, pname, GLint *, data); \
    HookWrapper2(void, glGetPointerv, GLenum, pname, void **, params); \
    HookWrapper1(const GLubyte *, glGetString, GLenum, name); \
    HookWrapper2(void, glHint, GLenum, target, GLenum, mode); \
    HookWrapper1(void, glLogicOp, GLenum, opcode); \
    HookWrapper2(void, glPixelStorei, GLenum, pname, GLint, param); \
    HookWrapper2(void, glPixelStoref, GLenum, pname, GLfloat, param); \
    HookWrapper2(void, glPolygonMode, GLenum, face, GLenum, mode); \
    HookWrapper2(void, glPolygonOffset, GLfloat, factor, GLfloat, units); \
    HookWrapper1(void, glPointSize, GLfloat, size); \
    HookWrapper1(void, glLineWidth, GLfloat, width); \
    HookWrapper7(void, glReadPixels, GLint, x, GLint, y, GLsizei, width, GLsizei, height, GLenum, format, GLenum, type, void *, pixels); \
    HookWrapper1(void, glReadBuffer, GLenum, src); \
    HookWrapper4(void, glScissor, GLint, x, GLint, y, GLsizei, width, GLsizei, height); \
    HookWrapper8(void, glTexImage1D, GLenum, target, GLint, level, GLint, internalformat, GLsizei, width, GLint, border, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper9(void, glTexImage2D, GLenum, target, GLint, level, GLint, internalformat, GLsizei, width, GLsizei, height, GLint, border, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper7(void, glTexSubImage1D, GLenum, target, GLint, level, GLint, xoffset, GLsizei, width, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper9(void, glTexSubImage2D, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLsizei, width, GLsizei, height, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper7(void, glCopyTexImage1D, GLenum, target, GLint, level, GLenum, internalformat, GLint, x, GLint, y, GLsizei, width, GLint, border); \
    HookWrapper8(void, glCopyTexImage2D, GLenum, target, GLint, level, GLenum, internalformat, GLint, x, GLint, y, GLsizei, width, GLsizei, height, GLint, border); \
    HookWrapper6(void, glCopyTexSubImage1D, GLenum, target, GLint, level, GLint, xoffset, GLint, x, GLint, y, GLsizei, width); \
    HookWrapper8(void, glCopyTexSubImage2D, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLint, x, GLint, y, GLsizei, width, GLsizei, height); \
    HookWrapper3(void, glTexParameterf, GLenum, target, GLenum, pname, GLfloat, param); \
    HookWrapper3(void, glTexParameterfv, GLenum, target, GLenum, pname, const GLfloat *, params); \
    HookWrapper3(void, glTexParameteri, GLenum, target, GLenum, pname, GLint, param); \
    HookWrapper3(void, glTexParameteriv, GLenum, target, GLenum, pname, const GLint *, params); \
    HookWrapper4(void, glViewport, GLint, x, GLint, y, GLsizei, width, GLsizei, height); \



// gl extensions
#define DefineGLExtensionHooks() \
    HookWrapper1(void, glActiveTexture, GLenum, texture); \
    HookWrapper4(void, glTexStorage1D, GLenum, target, GLsizei, levels, GLenum, internalformat, GLsizei, width); \
    HookWrapper5(void, glTexStorage2D, GLenum, target, GLsizei, levels, GLenum, internalformat, GLsizei, width, GLsizei, height); \
    HookWrapper6(void, glTexStorage3D, GLenum, target, GLsizei, levels, GLenum, internalformat, GLsizei, width, GLsizei, height, GLsizei, depth); \
    HookWrapper6(void, glTexStorage2DMultisample, GLenum, target, GLsizei, samples, GLenum, internalformat, GLsizei, width, GLsizei, height, GLboolean, fixedsamplelocations); \
    HookWrapper7(void, glTexStorage3DMultisample, GLenum, target, GLsizei, samples, GLenum, internalformat, GLsizei, width, GLsizei, height, GLsizei, depth, GLboolean, fixedsamplelocations); \
    HookWrapper10(void, glTexImage3D, GLenum, target, GLint, level, GLint, internalformat, GLsizei, width, GLsizei, height, GLsizei, depth, GLint, border, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper11(void, glTexSubImage3D, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLint, zoffset, GLsizei, width, GLsizei, height, GLsizei, depth, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper3(void, glTexBuffer, GLenum, target, GLenum, internalformat, GLuint, buffer); \
    HookWrapper6(void, glTexImage2DMultisample, GLenum, target, GLsizei, samples, GLenum, internalformat, GLsizei, width, GLsizei, height, GLboolean, fixedsamplelocations); \
    HookWrapper7(void, glTexImage3DMultisample, GLenum, target, GLsizei, samples, GLenum, internalformat, GLsizei, width, GLsizei, height, GLsizei, depth, GLboolean, fixedsamplelocations); \
    HookWrapper7(void, glCompressedTexImage1D, GLenum, target, GLint, level, GLenum, internalformat, GLsizei, width, GLint, border, GLsizei, imageSize, const void *, data); \
    HookWrapper8(void, glCompressedTexImage2D, GLenum, target, GLint, level, GLenum, internalformat, GLsizei, width, GLsizei, height, GLint, border, GLsizei, imageSize, const void *, data); \
    HookWrapper9(void, glCompressedTexImage3D, GLenum, target, GLint, level, GLenum, internalformat, GLsizei, width, GLsizei, height, GLsizei, depth, GLint, border, GLsizei, imageSize, const void *, data); \
    HookWrapper7(void, glCompressedTexSubImage1D, GLenum, target, GLint, level, GLint, xoffset, GLsizei, width, GLenum, format, GLsizei, imageSize, const void *, data); \
    HookWrapper9(void, glCompressedTexSubImage2D, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLsizei, width, GLsizei, height, GLenum, format, GLsizei, imageSize, const void *, data); \
    HookWrapper11(void, glCompressedTexSubImage3D, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLint, zoffset, GLsizei, width, GLsizei, height, GLsizei, depth, GLenum, format, GLsizei, imageSize, const void *, data); \
    HookWrapper5(void, glTexBufferRange, GLenum, target, GLenum, internalformat, GLuint, buffer, GLintptr, offset, GLsizeiptr, size); \
    HookWrapper8(void, glTextureView, GLuint, texture, GLenum, target, GLuint, origtexture, GLenum, internalformat, GLuint, minlevel, GLuint, numlevels, GLuint, minlayer, GLuint, numlayers); \
    HookWrapper3(void, glTexParameterIiv, GLenum, target, GLenum, pname, const GLint *, params); \
    HookWrapper3(void, glTexParameterIuiv, GLenum, target, GLenum, pname, const GLuint *, params); \
    HookWrapper1(void, glGenerateMipmap, GLenum, target); \
    HookWrapper15(void, glCopyImageSubData, GLuint, srcName, GLenum, srcTarget, GLint, srcLevel, GLint, srcX, GLint, srcY, GLint, srcZ, GLuint, dstName, GLenum, dstTarget, GLint, dstLevel, GLint, dstX, GLint, dstY, GLint, dstZ, GLsizei, srcWidth, GLsizei, srcHeight, GLsizei, srcDepth); \
    HookWrapper9(void, glCopyTexSubImage3D, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLint, zoffset, GLint, x, GLint, y, GLsizei, width, GLsizei, height); \
    HookWrapper5(void, glGetInternalformativ, GLenum, target, GLenum, internalformat, GLenum, pname, GLsizei, bufSize, GLint *, params); \
    HookWrapper5(void, glGetInternalformati64v, GLenum, target, GLenum, internalformat, GLenum, pname, GLsizei, bufSize, GLint64 *, params); \
    HookWrapper3(void, glGetBufferParameteriv, GLenum, target, GLenum, pname, GLint *, params); \
    HookWrapper3(void, glGetBufferParameteri64v, GLenum, target, GLenum, pname, GLint64 *, params); \
    HookWrapper3(void, glGetBufferPointerv, GLenum, target, GLenum, pname, void **, params); \
    HookWrapper2(GLint, glGetFragDataIndex, GLuint, program, const GLchar *, name); \
    HookWrapper2(GLint, glGetFragDataLocation, GLuint, program, const GLchar *, name); \
    HookWrapper2(const GLubyte *, glGetStringi, GLenum, name, GLuint, index); \
    HookWrapper3(void, glGetBooleani_v, GLenum, target, GLuint, index, GLboolean *, data); \
    HookWrapper3(void, glGetIntegeri_v, GLenum, target, GLuint, index, GLint *, data); \
    HookWrapper3(void, glGetFloati_v, GLenum, target, GLuint, index, GLfloat *, data); \
    HookWrapper3(void, glGetDoublei_v, GLenum, target, GLuint, index, GLdouble *, data); \
    HookWrapper3(void, glGetInteger64i_v, GLenum, target, GLuint, index, GLint64 *, data); \
    HookWrapper2(void, glGetInteger64v, GLenum, pname, GLint64 *, data); \
    HookWrapper3(void, glGetShaderiv, GLuint, shader, GLenum, pname, GLint *, params); \
    HookWrapper4(void, glGetShaderInfoLog, GLuint, shader, GLsizei, bufSize, GLsizei *, length, GLchar *, infoLog); \
    HookWrapper4(void, glGetShaderPrecisionFormat, GLenum, shadertype, GLenum, precisiontype, GLint *, range, GLint *, precision); \
    HookWrapper4(void, glGetShaderSource, GLuint, shader, GLsizei, bufSize, GLsizei *, length, GLchar *, source); \
    HookWrapper4(void, glGetAttachedShaders, GLuint, program, GLsizei, maxCount, GLsizei *, count, GLuint *, shaders); \
    HookWrapper3(void, glGetProgramiv, GLuint, program, GLenum, pname, GLint *, params); \
    HookWrapper4(void, glGetProgramInfoLog, GLuint, program, GLsizei, bufSize, GLsizei *, length, GLchar *, infoLog); \
    HookWrapper4(void, glGetProgramInterfaceiv, GLuint, program, GLenum, programInterface, GLenum, pname, GLint *, params); \
    HookWrapper3(GLuint, glGetProgramResourceIndex, GLuint, program, GLenum, programInterface, const GLchar *, name); \
    HookWrapper8(void, glGetProgramResourceiv, GLuint, program, GLenum, programInterface, GLuint, index, GLsizei, propCount, const GLenum *, props, GLsizei, bufSize, GLsizei *, length, GLint *, params); \
    HookWrapper6(void, glGetProgramResourceName, GLuint, program, GLenum, programInterface, GLuint, index, GLsizei, bufSize, GLsizei *, length, GLchar *, name); \
    HookWrapper3(void, glGetProgramPipelineiv, GLuint, pipeline, GLenum, pname, GLint *, params); \
    HookWrapper4(void, glGetProgramPipelineInfoLog, GLuint, pipeline, GLsizei, bufSize, GLsizei *, length, GLchar *, infoLog); \
    HookWrapper5(void, glGetProgramBinary, GLuint, program, GLsizei, bufSize, GLsizei *, length, GLenum *, binaryFormat, void *, binary); \
    HookWrapper3(GLint, glGetProgramResourceLocation, GLuint, program, GLenum, programInterface, const GLchar *, name); \
    HookWrapper3(GLint, glGetProgramResourceLocationIndex, GLuint, program, GLenum, programInterface, const GLchar *, name); \
    HookWrapper4(void, glGetProgramStageiv, GLuint, program, GLenum, shadertype, GLenum, pname, GLint *, values); \
    HookWrapper0(GLenum, glGetGraphicsResetStatus); \
    HookWrapper5(void, glGetObjectLabel, GLenum, identifier, GLuint, name, GLsizei, bufSize, GLsizei *, length, GLchar *, label); \
    HookWrapper4(void, glGetObjectPtrLabel, const void *, ptr, GLsizei, bufSize, GLsizei *, length, GLchar *, label); \
    HookWrapper8(GLuint, glGetDebugMessageLog, GLuint, count, GLsizei, bufSize, GLenum *, sources, GLenum *, types, GLuint *, ids, GLenum *, severities, GLsizei *, lengths, GLchar *, messageLog); \
    HookWrapper4(void, glGetFramebufferAttachmentParameteriv, GLenum, target, GLenum, attachment, GLenum, pname, GLint *, params); \
    HookWrapper3(void, glGetFramebufferParameteriv, GLenum, target, GLenum, pname, GLint *, params); \
    HookWrapper3(void, glGetRenderbufferParameteriv, GLenum, target, GLenum, pname, GLint *, params); \
    HookWrapper3(void, glGetMultisamplefv, GLenum, pname, GLuint, index, GLfloat *, val); \
    HookWrapper4(void, glGetQueryIndexediv, GLenum, target, GLuint, index, GLenum, pname, GLint *, params); \
    HookWrapper3(void, glGetQueryObjectui64v, GLuint, id, GLenum, pname, GLuint64 *, params); \
    HookWrapper3(void, glGetQueryObjectuiv, GLuint, id, GLenum, pname, GLuint *, params); \
    HookWrapper3(void, glGetQueryObjecti64v, GLuint, id, GLenum, pname, GLint64 *, params); \
    HookWrapper3(void, glGetQueryObjectiv, GLuint, id, GLenum, pname, GLint *, params); \
    HookWrapper3(void, glGetQueryiv, GLenum, target, GLenum, pname, GLint *, params); \
    HookWrapper5(void, glGetSynciv, GLsync, sync, GLenum, pname, GLsizei, bufSize, GLsizei *, length, GLint *, values); \
    HookWrapper4(void, glGetBufferSubData, GLenum, target, GLintptr, offset, GLsizeiptr, size, void *, data); \
    HookWrapper3(void, glGetVertexAttribiv, GLuint, index, GLenum, pname, GLint *, params); \
    HookWrapper3(void, glGetVertexAttribPointerv, GLuint, index, GLenum, pname, void **, pointer); \
    HookWrapper3(void, glGetCompressedTexImage, GLenum, target, GLint, level, void *, img); \
    HookWrapper4(void, glGetnCompressedTexImage, GLenum, target, GLint, lod, GLsizei, bufSize, void *, pixels); \
    HookWrapper4(void, glGetCompressedTextureImage, GLuint, texture, GLint, level, GLsizei, bufSize, void *, pixels); \
    HookWrapper10(void, glGetCompressedTextureSubImage, GLuint, texture, GLint, level, GLint, xoffset, GLint, yoffset, GLint, zoffset, GLsizei, width, GLsizei, height, GLsizei, depth, GLsizei, bufSize, void *, pixels); \
    HookWrapper6(void, glGetnTexImage, GLenum, target, GLint, level, GLenum, format, GLenum, type, GLsizei, bufSize, void *, pixels); \
    HookWrapper6(void, glGetTextureImage, GLuint, texture, GLint, level, GLenum, format, GLenum, type, GLsizei, bufSize, void *, pixels); \
    HookWrapper4(void, glGetTextureLevelParameterfv, GLuint, texture, GLint, level, GLenum, pname, GLfloat *, params); \
    HookWrapper4(void, glGetTextureLevelParameteriv, GLuint, texture, GLint, level, GLenum, pname, GLint *, params); \
    HookWrapper3(void, glGetTextureParameterIiv, GLuint, texture, GLenum, pname, GLint *, params); \
    HookWrapper3(void, glGetTextureParameterIuiv, GLuint, texture, GLenum, pname, GLuint *, params); \
    HookWrapper3(void, glGetTextureParameterfv, GLuint, texture, GLenum, pname, GLfloat *, params); \
    HookWrapper3(void, glGetTextureParameteriv, GLuint, texture, GLenum, pname, GLint *, params); \
    HookWrapper12(void, glGetTextureSubImage, GLuint, texture, GLint, level, GLint, xoffset, GLint, yoffset, GLint, zoffset, GLsizei, width, GLsizei, height, GLsizei, depth, GLenum, format, GLenum, type, GLsizei, bufSize, void *, pixels); \
    HookWrapper3(void, glGetTexParameterIiv, GLenum, target, GLenum, pname, GLint *, params); \
    HookWrapper3(void, glGetTexParameterIuiv, GLenum, target, GLenum, pname, GLuint *, params); \
    HookWrapper2(void, glClampColor, GLenum, target, GLenum, clamp); \
    HookWrapper8(void, glReadnPixels, GLint, x, GLint, y, GLsizei, width, GLsizei, height, GLenum, format, GLenum, type, GLsizei, bufSize, void *, data); \
    HookWrapper3(void, glGetSamplerParameterIiv, GLuint, sampler, GLenum, pname, GLint *, params); \
    HookWrapper3(void, glGetSamplerParameterIuiv, GLuint, sampler, GLenum, pname, GLuint *, params); \
    HookWrapper3(void, glGetSamplerParameterfv, GLuint, sampler, GLenum, pname, GLfloat *, params); \
    HookWrapper3(void, glGetSamplerParameteriv, GLuint, sampler, GLenum, pname, GLint *, params); \
    HookWrapper7(void, glGetTransformFeedbackVarying, GLuint, program, GLuint, index, GLsizei, bufSize, GLsizei *, length, GLsizei *, size, GLenum *, type, GLchar *, name); \
    HookWrapper4(void, glGetTransformFeedbacki64_v, GLuint, xfb, GLenum, pname, GLuint, index, GLint64 *, param); \
    HookWrapper4(void, glGetTransformFeedbacki_v, GLuint, xfb, GLenum, pname, GLuint, index, GLint *, param); \
    HookWrapper3(void, glGetTransformFeedbackiv, GLuint, xfb, GLenum, pname, GLint *, param); \
    HookWrapper3(GLuint, glGetSubroutineIndex, GLuint, program, GLenum, shadertype, const GLchar *, name); \
    HookWrapper3(GLint, glGetSubroutineUniformLocation, GLuint, program, GLenum, shadertype, const GLchar *, name); \
    HookWrapper4(void, glGetActiveAtomicCounterBufferiv, GLuint, program, GLuint, bufferIndex, GLenum, pname, GLint *, params); \
    HookWrapper6(void, glGetActiveSubroutineName, GLuint, program, GLenum, shadertype, GLuint, index, GLsizei, bufsize, GLsizei *, length, GLchar *, name); \
    HookWrapper6(void, glGetActiveSubroutineUniformName, GLuint, program, GLenum, shadertype, GLuint, index, GLsizei, bufsize, GLsizei *, length, GLchar *, name); \
    HookWrapper5(void, glGetActiveSubroutineUniformiv, GLuint, program, GLenum, shadertype, GLuint, index, GLenum, pname, GLint *, values); \
    HookWrapper2(GLint, glGetUniformLocation, GLuint, program, const GLchar *, name); \
    HookWrapper4(void, glGetUniformIndices, GLuint, program, GLsizei, uniformCount, const GLchar *const*, uniformNames, GLuint *, uniformIndices); \
    HookWrapper3(void, glGetUniformSubroutineuiv, GLenum, shadertype, GLint, location, GLuint *, params); \
    HookWrapper2(GLuint, glGetUniformBlockIndex, GLuint, program, const GLchar *, uniformBlockName); \
    HookWrapper2(GLint, glGetAttribLocation, GLuint, program, const GLchar *, name); \
    HookWrapper7(void, glGetActiveUniform, GLuint, program, GLuint, index, GLsizei, bufSize, GLsizei *, length, GLint *, size, GLenum *, type, GLchar *, name); \
    HookWrapper5(void, glGetActiveUniformName, GLuint, program, GLuint, uniformIndex, GLsizei, bufSize, GLsizei *, length, GLchar *, uniformName); \
    HookWrapper5(void, glGetActiveUniformBlockName, GLuint, program, GLuint, uniformBlockIndex, GLsizei, bufSize, GLsizei *, length, GLchar *, uniformBlockName); \
    HookWrapper4(void, glGetActiveUniformBlockiv, GLuint, program, GLuint, uniformBlockIndex, GLenum, pname, GLint *, params); \
    HookWrapper5(void, glGetActiveUniformsiv, GLuint, program, GLsizei, uniformCount, const GLuint *, uniformIndices, GLenum, pname, GLint *, params); \
    HookWrapper7(void, glGetActiveAttrib, GLuint, program, GLuint, index, GLsizei, bufSize, GLsizei *, length, GLint *, size, GLenum *, type, GLchar *, name); \
    HookWrapper3(void, glGetUniformfv, GLuint, program, GLint, location, GLfloat *, params); \
    HookWrapper3(void, glGetUniformiv, GLuint, program, GLint, location, GLint *, params); \
    HookWrapper3(void, glGetUniformuiv, GLuint, program, GLint, location, GLuint *, params); \
    HookWrapper3(void, glGetUniformdv, GLuint, program, GLint, location, GLdouble *, params); \
    HookWrapper4(void, glGetnUniformdv, GLuint, program, GLint, location, GLsizei, bufSize, GLdouble *, params); \
    HookWrapper4(void, glGetnUniformfv, GLuint, program, GLint, location, GLsizei, bufSize, GLfloat *, params); \
    HookWrapper4(void, glGetnUniformiv, GLuint, program, GLint, location, GLsizei, bufSize, GLint *, params); \
    HookWrapper4(void, glGetnUniformuiv, GLuint, program, GLint, location, GLsizei, bufSize, GLuint *, params); \
    HookWrapper3(void, glGetVertexArrayiv, GLuint, vaobj, GLenum, pname, GLint *, param); \
    HookWrapper4(void, glGetVertexArrayIndexed64iv, GLuint, vaobj, GLuint, index, GLenum, pname, GLint64 *, param); \
    HookWrapper4(void, glGetVertexArrayIndexediv, GLuint, vaobj, GLuint, index, GLenum, pname, GLint *, param); \
    HookWrapper3(void, glGetVertexAttribIiv, GLuint, index, GLenum, pname, GLint *, params); \
    HookWrapper3(void, glGetVertexAttribIuiv, GLuint, index, GLenum, pname, GLuint *, params); \
    HookWrapper3(void, glGetVertexAttribLdv, GLuint, index, GLenum, pname, GLdouble *, params); \
    HookWrapper3(void, glGetVertexAttribdv, GLuint, index, GLenum, pname, GLdouble *, params); \
    HookWrapper3(void, glGetVertexAttribfv, GLuint, index, GLenum, pname, GLfloat *, params); \
    HookWrapper3(void, glGetNamedBufferParameteri64v, GLuint, buffer, GLenum, pname, GLint64 *, params); \
    HookWrapper3(void, glGetNamedBufferPointerv, GLuint, buffer, GLenum, pname, void **, params); \
    HookWrapper1(GLenum, glCheckFramebufferStatus, GLenum, target); \
    HookWrapper4(void, glBlendColor, GLfloat, red, GLfloat, green, GLfloat, blue, GLfloat, alpha); \
    HookWrapper3(void, glBlendFunci, GLuint, buf, GLenum, src, GLenum, dst); \
    HookWrapper4(void, glBlendFuncSeparate, GLenum, sfactorRGB, GLenum, dfactorRGB, GLenum, sfactorAlpha, GLenum, dfactorAlpha); \
    HookWrapper5(void, glBlendFuncSeparatei, GLuint, buf, GLenum, srcRGB, GLenum, dstRGB, GLenum, srcAlpha, GLenum, dstAlpha); \
    HookWrapper1(void, glBlendEquation, GLenum, mode); \
    HookWrapper2(void, glBlendEquationi, GLuint, buf, GLenum, mode); \
    HookWrapper2(void, glBlendEquationSeparate, GLenum, modeRGB, GLenum, modeAlpha); \
    HookWrapper3(void, glBlendEquationSeparatei, GLuint, buf, GLenum, modeRGB, GLenum, modeAlpha); \
    HookWrapper4(void, glStencilFuncSeparate, GLenum, face, GLenum, func, GLint, ref, GLuint, mask); \
    HookWrapper2(void, glStencilMaskSeparate, GLenum, face, GLuint, mask); \
    HookWrapper4(void, glStencilOpSeparate, GLenum, face, GLenum, sfail, GLenum, dpfail, GLenum, dppass); \
    HookWrapper5(void, glColorMaski, GLuint, index, GLboolean, r, GLboolean, g, GLboolean, b, GLboolean, a); \
    HookWrapper2(void, glSampleMaski, GLuint, maskNumber, GLbitfield, mask); \
    HookWrapper2(void, glSampleCoverage, GLfloat, value, GLboolean, invert); \
    HookWrapper1(void, glMinSampleShading, GLfloat, value); \
    HookWrapper2(void, glDepthRangef, GLfloat, n, GLfloat, f); \
    HookWrapper3(void, glDepthRangeIndexed, GLuint, index, GLdouble, n, GLdouble, f); \
    HookWrapper3(void, glDepthRangeArrayv, GLuint, first, GLsizei, count, const GLdouble *, v); \
    HookWrapper2(void, glDepthBoundsEXT, GLclampd, zmin, GLclampd, zmax); \
    HookWrapper2(void, glClipControl, GLenum, origin, GLenum, depth); \
    HookWrapper1(void, glProvokingVertex, GLenum, mode); \
    HookWrapper1(void, glPrimitiveRestartIndex, GLuint, index); \
    HookWrapper1(GLuint, glCreateShader, GLenum, type); \
    HookWrapper1(void, glDeleteShader, GLuint, shader); \
    HookWrapper4(void, glShaderSource, GLuint, shader, GLsizei, count, const GLchar *const*, string, const GLint *, length); \
    HookWrapper1(void, glCompileShader, GLuint, shader); \
    HookWrapper3(GLuint, glCreateShaderProgramv, GLenum, type, GLsizei, count, const GLchar *const*, strings); \
    HookWrapper0(GLuint, glCreateProgram); \
    HookWrapper1(void, glDeleteProgram, GLuint, program); \
    HookWrapper2(void, glAttachShader, GLuint, program, GLuint, shader); \
    HookWrapper2(void, glDetachShader, GLuint, program, GLuint, shader); \
    HookWrapper0(void, glReleaseShaderCompiler); \
    HookWrapper1(void, glLinkProgram, GLuint, program); \
    HookWrapper3(void, glProgramParameteri, GLuint, program, GLenum, pname, GLint, value); \
    HookWrapper1(void, glUseProgram, GLuint, program); \
    HookWrapper5(void, glShaderBinary, GLsizei, count, const GLuint *, shaders, GLenum, binaryformat, const void *, binary, GLsizei, length); \
    HookWrapper4(void, glProgramBinary, GLuint, program, GLenum, binaryFormat, const void *, binary, GLsizei, length); \
    HookWrapper3(void, glUseProgramStages, GLuint, pipeline, GLbitfield, stages, GLuint, program); \
    HookWrapper1(void, glValidateProgram, GLuint, program); \
    HookWrapper2(void, glGenProgramPipelines, GLsizei, n, GLuint *, pipelines); \
    HookWrapper1(void, glBindProgramPipeline, GLuint, pipeline); \
    HookWrapper2(void, glActiveShaderProgram, GLuint, pipeline, GLuint, program); \
    HookWrapper2(void, glDeleteProgramPipelines, GLsizei, n, const GLuint *, pipelines); \
    HookWrapper1(void, glValidateProgramPipeline, GLuint, pipeline); \
    HookWrapper2(void, glDebugMessageCallback, GLDEBUGPROC, callback, const void *, userParam); \
    HookWrapper6(void, glDebugMessageControl, GLenum, source, GLenum, type, GLenum, severity, GLsizei, count, const GLuint *, ids, GLboolean, enabled); \
    HookWrapper6(void, glDebugMessageInsert, GLenum, source, GLenum, type, GLuint, id, GLenum, severity, GLsizei, length, const GLchar *, buf); \
    HookWrapper4(void, glPushDebugGroup, GLenum, source, GLuint, id, GLsizei, length, const GLchar *, message); \
    HookWrapper0(void, glPopDebugGroup); \
    HookWrapper4(void, glObjectLabel, GLenum, identifier, GLuint, name, GLsizei, length, const GLchar *, label); \
    HookWrapper3(void, glObjectPtrLabel, const void *, ptr, GLsizei, length, const GLchar *, label); \
    HookWrapper2(void, glEnablei, GLenum, target, GLuint, index); \
    HookWrapper2(void, glDisablei, GLenum, target, GLuint, index); \
    HookWrapper2(GLboolean, glIsEnabledi, GLenum, target, GLuint, index); \
    HookWrapper1(GLboolean, glIsBuffer, GLuint, buffer); \
    HookWrapper1(GLboolean, glIsFramebuffer, GLuint, framebuffer); \
    HookWrapper1(GLboolean, glIsProgram, GLuint, program); \
    HookWrapper1(GLboolean, glIsProgramPipeline, GLuint, pipeline); \
    HookWrapper1(GLboolean, glIsQuery, GLuint, id); \
    HookWrapper1(GLboolean, glIsRenderbuffer, GLuint, renderbuffer); \
    HookWrapper1(GLboolean, glIsSampler, GLuint, sampler); \
    HookWrapper1(GLboolean, glIsShader, GLuint, shader); \
    HookWrapper1(GLboolean, glIsSync, GLsync, sync); \
    HookWrapper1(GLboolean, glIsTransformFeedback, GLuint, id); \
    HookWrapper1(GLboolean, glIsVertexArray, GLuint, array); \
    HookWrapper2(void, glGenBuffers, GLsizei, n, GLuint *, buffers); \
    HookWrapper2(void, glBindBuffer, GLenum, target, GLuint, buffer); \
    HookWrapper2(void, glDrawBuffers, GLsizei, n, const GLenum *, bufs); \
    HookWrapper2(void, glGenFramebuffers, GLsizei, n, GLuint *, framebuffers); \
    HookWrapper2(void, glBindFramebuffer, GLenum, target, GLuint, framebuffer); \
    HookWrapper4(void, glFramebufferTexture, GLenum, target, GLenum, attachment, GLuint, texture, GLint, level); \
    HookWrapper5(void, glFramebufferTexture1D, GLenum, target, GLenum, attachment, GLenum, textarget, GLuint, texture, GLint, level); \
    HookWrapper5(void, glFramebufferTexture2D, GLenum, target, GLenum, attachment, GLenum, textarget, GLuint, texture, GLint, level); \
    HookWrapper6(void, glFramebufferTexture3D, GLenum, target, GLenum, attachment, GLenum, textarget, GLuint, texture, GLint, level, GLint, zoffset); \
    HookWrapper4(void, glFramebufferRenderbuffer, GLenum, target, GLenum, attachment, GLenum, renderbuffertarget, GLuint, renderbuffer); \
    HookWrapper5(void, glFramebufferTextureLayer, GLenum, target, GLenum, attachment, GLuint, texture, GLint, level, GLint, layer); \
    HookWrapper3(void, glFramebufferParameteri, GLenum, target, GLenum, pname, GLint, param); \
    HookWrapper2(void, glDeleteFramebuffers, GLsizei, n, const GLuint *, framebuffers); \
    HookWrapper2(void, glGenRenderbuffers, GLsizei, n, GLuint *, renderbuffers); \
    HookWrapper4(void, glRenderbufferStorage, GLenum, target, GLenum, internalformat, GLsizei, width, GLsizei, height); \
    HookWrapper5(void, glRenderbufferStorageMultisample, GLenum, target, GLsizei, samples, GLenum, internalformat, GLsizei, width, GLsizei, height); \
    HookWrapper2(void, glDeleteRenderbuffers, GLsizei, n, const GLuint *, renderbuffers); \
    HookWrapper2(void, glBindRenderbuffer, GLenum, target, GLuint, renderbuffer); \
    HookWrapper2(GLsync, glFenceSync, GLenum, condition, GLbitfield, flags); \
    HookWrapper3(GLenum, glClientWaitSync, GLsync, sync, GLbitfield, flags, GLuint64, timeout); \
    HookWrapper3(void, glWaitSync, GLsync, sync, GLbitfield, flags, GLuint64, timeout); \
    HookWrapper1(void, glDeleteSync, GLsync, sync); \
    HookWrapper2(void, glGenQueries, GLsizei, n, GLuint *, ids); \
    HookWrapper2(void, glBeginQuery, GLenum, target, GLuint, id); \
    HookWrapper3(void, glBeginQueryIndexed, GLenum, target, GLuint, index, GLuint, id); \
    HookWrapper1(void, glEndQuery, GLenum, target); \
    HookWrapper2(void, glEndQueryIndexed, GLenum, target, GLuint, index); \
    HookWrapper2(void, glBeginConditionalRender, GLuint, id, GLenum, mode); \
    HookWrapper0(void, glEndConditionalRender); \
    HookWrapper2(void, glQueryCounter, GLuint, id, GLenum, target); \
    HookWrapper2(void, glDeleteQueries, GLsizei, n, const GLuint *, ids); \
    HookWrapper4(void, glBufferData, GLenum, target, GLsizeiptr, size, const void *, data, GLenum, usage); \
    HookWrapper4(void, glBufferStorage, GLenum, target, GLsizeiptr, size, const void *, data, GLbitfield, flags); \
    HookWrapper4(void, glBufferSubData, GLenum, target, GLintptr, offset, GLsizeiptr, size, const void *, data); \
    HookWrapper5(void, glCopyBufferSubData, GLenum, readTarget, GLenum, writeTarget, GLintptr, readOffset, GLintptr, writeOffset, GLsizeiptr, size); \
    HookWrapper3(void, glBindBufferBase, GLenum, target, GLuint, index, GLuint, buffer); \
    HookWrapper5(void, glBindBufferRange, GLenum, target, GLuint, index, GLuint, buffer, GLintptr, offset, GLsizeiptr, size); \
    HookWrapper4(void, glBindBuffersBase, GLenum, target, GLuint, first, GLsizei, count, const GLuint *, buffers); \
    HookWrapper6(void, glBindBuffersRange, GLenum, target, GLuint, first, GLsizei, count, const GLuint *, buffers, const GLintptr *, offsets, const GLsizeiptr *, sizes); \
    HookWrapper2(void *, glMapBuffer, GLenum, target, GLenum, access); \
    HookWrapper4(void *, glMapBufferRange, GLenum, target, GLintptr, offset, GLsizeiptr, length, GLbitfield, access); \
    HookWrapper3(void, glFlushMappedBufferRange, GLenum, target, GLintptr, offset, GLsizeiptr, length); \
    HookWrapper1(GLboolean, glUnmapBuffer, GLenum, target); \
    HookWrapper4(void, glTransformFeedbackVaryings, GLuint, program, GLsizei, count, const GLchar *const*, varyings, GLenum, bufferMode); \
    HookWrapper2(void, glGenTransformFeedbacks, GLsizei, n, GLuint *, ids); \
    HookWrapper2(void, glDeleteTransformFeedbacks, GLsizei, n, const GLuint *, ids); \
    HookWrapper2(void, glBindTransformFeedback, GLenum, target, GLuint, id); \
    HookWrapper1(void, glBeginTransformFeedback, GLenum, primitiveMode); \
    HookWrapper0(void, glPauseTransformFeedback); \
    HookWrapper0(void, glResumeTransformFeedback); \
    HookWrapper0(void, glEndTransformFeedback); \
    HookWrapper2(void, glDrawTransformFeedback, GLenum, mode, GLuint, id); \
    HookWrapper3(void, glDrawTransformFeedbackInstanced, GLenum, mode, GLuint, id, GLsizei, instancecount); \
    HookWrapper3(void, glDrawTransformFeedbackStream, GLenum, mode, GLuint, id, GLuint, stream); \
    HookWrapper4(void, glDrawTransformFeedbackStreamInstanced, GLenum, mode, GLuint, id, GLuint, stream, GLsizei, instancecount); \
    HookWrapper2(void, glDeleteBuffers, GLsizei, n, const GLuint *, buffers); \
    HookWrapper2(void, glGenVertexArrays, GLsizei, n, GLuint *, arrays); \
    HookWrapper1(void, glBindVertexArray, GLuint, array); \
    HookWrapper2(void, glDeleteVertexArrays, GLsizei, n, const GLuint *, arrays); \
    HookWrapper2(void, glVertexAttrib1d, GLuint, index, GLdouble, x); \
    HookWrapper2(void, glVertexAttrib1dv, GLuint, index, const GLdouble *, v); \
    HookWrapper2(void, glVertexAttrib1f, GLuint, index, GLfloat, x); \
    HookWrapper2(void, glVertexAttrib1fv, GLuint, index, const GLfloat *, v); \
    HookWrapper2(void, glVertexAttrib1s, GLuint, index, GLshort, x); \
    HookWrapper2(void, glVertexAttrib1sv, GLuint, index, const GLshort *, v); \
    HookWrapper3(void, glVertexAttrib2d, GLuint, index, GLdouble, x, GLdouble, y); \
    HookWrapper2(void, glVertexAttrib2dv, GLuint, index, const GLdouble *, v); \
    HookWrapper3(void, glVertexAttrib2f, GLuint, index, GLfloat, x, GLfloat, y); \
    HookWrapper2(void, glVertexAttrib2fv, GLuint, index, const GLfloat *, v); \
    HookWrapper3(void, glVertexAttrib2s, GLuint, index, GLshort, x, GLshort, y); \
    HookWrapper2(void, glVertexAttrib2sv, GLuint, index, const GLshort *, v); \
    HookWrapper4(void, glVertexAttrib3d, GLuint, index, GLdouble, x, GLdouble, y, GLdouble, z); \
    HookWrapper2(void, glVertexAttrib3dv, GLuint, index, const GLdouble *, v); \
    HookWrapper4(void, glVertexAttrib3f, GLuint, index, GLfloat, x, GLfloat, y, GLfloat, z); \
    HookWrapper2(void, glVertexAttrib3fv, GLuint, index, const GLfloat *, v); \
    HookWrapper4(void, glVertexAttrib3s, GLuint, index, GLshort, x, GLshort, y, GLshort, z); \
    HookWrapper2(void, glVertexAttrib3sv, GLuint, index, const GLshort *, v); \
    HookWrapper2(void, glVertexAttrib4Nbv, GLuint, index, const GLbyte *, v); \
    HookWrapper2(void, glVertexAttrib4Niv, GLuint, index, const GLint *, v); \
    HookWrapper2(void, glVertexAttrib4Nsv, GLuint, index, const GLshort *, v); \
    HookWrapper5(void, glVertexAttrib4Nub, GLuint, index, GLubyte, x, GLubyte, y, GLubyte, z, GLubyte, w); \
    HookWrapper2(void, glVertexAttrib4Nubv, GLuint, index, const GLubyte *, v); \
    HookWrapper2(void, glVertexAttrib4Nuiv, GLuint, index, const GLuint *, v); \
    HookWrapper2(void, glVertexAttrib4Nusv, GLuint, index, const GLushort *, v); \
    HookWrapper2(void, glVertexAttrib4bv, GLuint, index, const GLbyte *, v); \
    HookWrapper5(void, glVertexAttrib4d, GLuint, index, GLdouble, x, GLdouble, y, GLdouble, z, GLdouble, w); \
    HookWrapper2(void, glVertexAttrib4dv, GLuint, index, const GLdouble *, v); \
    HookWrapper5(void, glVertexAttrib4f, GLuint, index, GLfloat, x, GLfloat, y, GLfloat, z, GLfloat, w); \
    HookWrapper2(void, glVertexAttrib4fv, GLuint, index, const GLfloat *, v); \
    HookWrapper2(void, glVertexAttrib4iv, GLuint, index, const GLint *, v); \
    HookWrapper5(void, glVertexAttrib4s, GLuint, index, GLshort, x, GLshort, y, GLshort, z, GLshort, w); \
    HookWrapper2(void, glVertexAttrib4sv, GLuint, index, const GLshort *, v); \
    HookWrapper2(void, glVertexAttrib4ubv, GLuint, index, const GLubyte *, v); \
    HookWrapper2(void, glVertexAttrib4uiv, GLuint, index, const GLuint *, v); \
    HookWrapper2(void, glVertexAttrib4usv, GLuint, index, const GLushort *, v); \
    HookWrapper2(void, glVertexAttribI1i, GLuint, index, GLint, x); \
    HookWrapper2(void, glVertexAttribI1iv, GLuint, index, const GLint *, v); \
    HookWrapper2(void, glVertexAttribI1ui, GLuint, index, GLuint, x); \
    HookWrapper2(void, glVertexAttribI1uiv, GLuint, index, const GLuint *, v); \
    HookWrapper3(void, glVertexAttribI2i, GLuint, index, GLint, x, GLint, y); \
    HookWrapper2(void, glVertexAttribI2iv, GLuint, index, const GLint *, v); \
    HookWrapper3(void, glVertexAttribI2ui, GLuint, index, GLuint, x, GLuint, y); \
    HookWrapper2(void, glVertexAttribI2uiv, GLuint, index, const GLuint *, v); \
    HookWrapper4(void, glVertexAttribI3i, GLuint, index, GLint, x, GLint, y, GLint, z); \
    HookWrapper2(void, glVertexAttribI3iv, GLuint, index, const GLint *, v); \
    HookWrapper4(void, glVertexAttribI3ui, GLuint, index, GLuint, x, GLuint, y, GLuint, z); \
    HookWrapper2(void, glVertexAttribI3uiv, GLuint, index, const GLuint *, v); \
    HookWrapper2(void, glVertexAttribI4bv, GLuint, index, const GLbyte *, v); \
    HookWrapper5(void, glVertexAttribI4i, GLuint, index, GLint, x, GLint, y, GLint, z, GLint, w); \
    HookWrapper2(void, glVertexAttribI4iv, GLuint, index, const GLint *, v); \
    HookWrapper2(void, glVertexAttribI4sv, GLuint, index, const GLshort *, v); \
    HookWrapper2(void, glVertexAttribI4ubv, GLuint, index, const GLubyte *, v); \
    HookWrapper5(void, glVertexAttribI4ui, GLuint, index, GLuint, x, GLuint, y, GLuint, z, GLuint, w); \
    HookWrapper2(void, glVertexAttribI4uiv, GLuint, index, const GLuint *, v); \
    HookWrapper2(void, glVertexAttribI4usv, GLuint, index, const GLushort *, v); \
    HookWrapper2(void, glVertexAttribL1d, GLuint, index, GLdouble, x); \
    HookWrapper2(void, glVertexAttribL1dv, GLuint, index, const GLdouble *, v); \
    HookWrapper3(void, glVertexAttribL2d, GLuint, index, GLdouble, x, GLdouble, y); \
    HookWrapper2(void, glVertexAttribL2dv, GLuint, index, const GLdouble *, v); \
    HookWrapper4(void, glVertexAttribL3d, GLuint, index, GLdouble, x, GLdouble, y, GLdouble, z); \
    HookWrapper2(void, glVertexAttribL3dv, GLuint, index, const GLdouble *, v); \
    HookWrapper5(void, glVertexAttribL4d, GLuint, index, GLdouble, x, GLdouble, y, GLdouble, z, GLdouble, w); \
    HookWrapper2(void, glVertexAttribL4dv, GLuint, index, const GLdouble *, v); \
    HookWrapper4(void, glVertexAttribP1ui, GLuint, index, GLenum, type, GLboolean, normalized, GLuint, value); \
    HookWrapper4(void, glVertexAttribP1uiv, GLuint, index, GLenum, type, GLboolean, normalized, const GLuint *, value); \
    HookWrapper4(void, glVertexAttribP2ui, GLuint, index, GLenum, type, GLboolean, normalized, GLuint, value); \
    HookWrapper4(void, glVertexAttribP2uiv, GLuint, index, GLenum, type, GLboolean, normalized, const GLuint *, value); \
    HookWrapper4(void, glVertexAttribP3ui, GLuint, index, GLenum, type, GLboolean, normalized, GLuint, value); \
    HookWrapper4(void, glVertexAttribP3uiv, GLuint, index, GLenum, type, GLboolean, normalized, const GLuint *, value); \
    HookWrapper4(void, glVertexAttribP4ui, GLuint, index, GLenum, type, GLboolean, normalized, GLuint, value); \
    HookWrapper4(void, glVertexAttribP4uiv, GLuint, index, GLenum, type, GLboolean, normalized, const GLuint *, value); \
    HookWrapper6(void, glVertexAttribPointer, GLuint, index, GLint, size, GLenum, type, GLboolean, normalized, GLsizei, stride, const void *, pointer); \
    HookWrapper5(void, glVertexAttribIPointer, GLuint, index, GLint, size, GLenum, type, GLsizei, stride, const void *, pointer); \
    HookWrapper5(void, glVertexAttribLPointer, GLuint, index, GLint, size, GLenum, type, GLsizei, stride, const void *, pointer); \
    HookWrapper2(void, glVertexAttribBinding, GLuint, attribindex, GLuint, bindingindex); \
    HookWrapper5(void, glVertexAttribFormat, GLuint, attribindex, GLint, size, GLenum, type, GLboolean, normalized, GLuint, relativeoffset); \
    HookWrapper4(void, glVertexAttribIFormat, GLuint, attribindex, GLint, size, GLenum, type, GLuint, relativeoffset); \
    HookWrapper4(void, glVertexAttribLFormat, GLuint, attribindex, GLint, size, GLenum, type, GLuint, relativeoffset); \
    HookWrapper2(void, glVertexAttribDivisor, GLuint, index, GLuint, divisor); \
    HookWrapper3(void, glBindAttribLocation, GLuint, program, GLuint, index, const GLchar *, name); \
    HookWrapper3(void, glBindFragDataLocation, GLuint, program, GLuint, color, const GLchar *, name); \
    HookWrapper4(void, glBindFragDataLocationIndexed, GLuint, program, GLuint, colorNumber, GLuint, index, const GLchar *, name); \
    HookWrapper1(void, glEnableVertexAttribArray, GLuint, index); \
    HookWrapper1(void, glDisableVertexAttribArray, GLuint, index); \
    HookWrapper4(void, glBindVertexBuffer, GLuint, bindingindex, GLuint, buffer, GLintptr, offset, GLsizei, stride); \
    HookWrapper5(void, glBindVertexBuffers, GLuint, first, GLsizei, count, const GLuint *, buffers, const GLintptr *, offsets, const GLsizei *, strides); \
    HookWrapper2(void, glVertexBindingDivisor, GLuint, bindingindex, GLuint, divisor); \
    HookWrapper7(void, glBindImageTexture, GLuint, unit, GLuint, texture, GLint, level, GLboolean, layered, GLint, layer, GLenum, access, GLenum, format); \
    HookWrapper3(void, glBindImageTextures, GLuint, first, GLsizei, count, const GLuint *, textures); \
    HookWrapper2(void, glGenSamplers, GLsizei, count, GLuint *, samplers); \
    HookWrapper2(void, glBindSampler, GLuint, unit, GLuint, sampler); \
    HookWrapper3(void, glBindSamplers, GLuint, first, GLsizei, count, const GLuint *, samplers); \
    HookWrapper3(void, glBindTextures, GLuint, first, GLsizei, count, const GLuint *, textures); \
    HookWrapper2(void, glDeleteSamplers, GLsizei, count, const GLuint *, samplers); \
    HookWrapper3(void, glSamplerParameteri, GLuint, sampler, GLenum, pname, GLint, param); \
    HookWrapper3(void, glSamplerParameterf, GLuint, sampler, GLenum, pname, GLfloat, param); \
    HookWrapper3(void, glSamplerParameteriv, GLuint, sampler, GLenum, pname, const GLint *, param); \
    HookWrapper3(void, glSamplerParameterfv, GLuint, sampler, GLenum, pname, const GLfloat *, param); \
    HookWrapper3(void, glSamplerParameterIiv, GLuint, sampler, GLenum, pname, const GLint *, param); \
    HookWrapper3(void, glSamplerParameterIuiv, GLuint, sampler, GLenum, pname, const GLuint *, param); \
    HookWrapper2(void, glPatchParameteri, GLenum, pname, GLint, value); \
    HookWrapper2(void, glPatchParameterfv, GLenum, pname, const GLfloat *, values); \
    HookWrapper2(void, glPointParameterf, GLenum, pname, GLfloat, param); \
    HookWrapper2(void, glPointParameterfv, GLenum, pname, const GLfloat *, params); \
    HookWrapper2(void, glPointParameteri, GLenum, pname, GLint, param); \
    HookWrapper2(void, glPointParameteriv, GLenum, pname, const GLint *, params); \
    HookWrapper3(void, glDispatchCompute, GLuint, num_groups_x, GLuint, num_groups_y, GLuint, num_groups_z); \
    HookWrapper1(void, glDispatchComputeIndirect, GLintptr, indirect); \
    HookWrapper1(void, glMemoryBarrier, GLbitfield, barriers); \
    HookWrapper1(void, glMemoryBarrierByRegion, GLbitfield, barriers); \
    HookWrapper0(void, glTextureBarrier); \
    HookWrapper1(void, glClearDepthf, GLfloat, d); \
    HookWrapper3(void, glClearBufferfv, GLenum, buffer, GLint, drawbuffer, const GLfloat *, value); \
    HookWrapper3(void, glClearBufferiv, GLenum, buffer, GLint, drawbuffer, const GLint *, value); \
    HookWrapper3(void, glClearBufferuiv, GLenum, buffer, GLint, drawbuffer, const GLuint *, value); \
    HookWrapper4(void, glClearBufferfi, GLenum, buffer, GLint, drawbuffer, GLfloat, depth, GLint, stencil); \
    HookWrapper5(void, glClearBufferData, GLenum, target, GLenum, internalformat, GLenum, format, GLenum, type, const void *, data); \
    HookWrapper7(void, glClearBufferSubData, GLenum, target, GLenum, internalformat, GLintptr, offset, GLsizeiptr, size, GLenum, format, GLenum, type, const void *, data); \
    HookWrapper5(void, glClearTexImage, GLuint, texture, GLint, level, GLenum, format, GLenum, type, const void *, data); \
    HookWrapper11(void, glClearTexSubImage, GLuint, texture, GLint, level, GLint, xoffset, GLint, yoffset, GLint, zoffset, GLsizei, width, GLsizei, height, GLsizei, depth, GLenum, format, GLenum, type, const void *, data); \
    HookWrapper1(void, glInvalidateBufferData, GLuint, buffer); \
    HookWrapper3(void, glInvalidateBufferSubData, GLuint, buffer, GLintptr, offset, GLsizeiptr, length); \
    HookWrapper3(void, glInvalidateFramebuffer, GLenum, target, GLsizei, numAttachments, const GLenum *, attachments); \
    HookWrapper7(void, glInvalidateSubFramebuffer, GLenum, target, GLsizei, numAttachments, const GLenum *, attachments, GLint, x, GLint, y, GLsizei, width, GLsizei, height); \
    HookWrapper2(void, glInvalidateTexImage, GLuint, texture, GLint, level); \
    HookWrapper8(void, glInvalidateTexSubImage, GLuint, texture, GLint, level, GLint, xoffset, GLint, yoffset, GLint, zoffset, GLsizei, width, GLsizei, height, GLsizei, depth); \
    HookWrapper3(void, glScissorArrayv, GLuint, first, GLsizei, count, const GLint *, v); \
    HookWrapper5(void, glScissorIndexed, GLuint, index, GLint, left, GLint, bottom, GLsizei, width, GLsizei, height); \
    HookWrapper2(void, glScissorIndexedv, GLuint, index, const GLint *, v); \
    HookWrapper5(void, glViewportIndexedf, GLuint, index, GLfloat, x, GLfloat, y, GLfloat, w, GLfloat, h); \
    HookWrapper2(void, glViewportIndexedfv, GLuint, index, const GLfloat *, v); \
    HookWrapper3(void, glViewportArrayv, GLuint, first, GLsizei, count, const GLfloat *, v); \
    HookWrapper3(void, glUniformBlockBinding, GLuint, program, GLuint, uniformBlockIndex, GLuint, uniformBlockBinding); \
    HookWrapper3(void, glShaderStorageBlockBinding, GLuint, program, GLuint, storageBlockIndex, GLuint, storageBlockBinding); \
    HookWrapper3(void, glUniformSubroutinesuiv, GLenum, shadertype, GLsizei, count, const GLuint *, indices); \
    HookWrapper2(void,   glUniform1f, GLint, location, GLfloat, v0); \
    HookWrapper2(void,   glUniform1i, GLint, location, GLint, v0); \
    HookWrapper2(void,  glUniform1ui, GLint, location, GLuint, v0); \
    HookWrapper2(void,   glUniform1d, GLint, location, GLdouble, x); \
    HookWrapper3(void,   glUniform2f, GLint, location, GLfloat, v0, GLfloat, v1); \
    HookWrapper3(void,   glUniform2i, GLint, location, GLint, v0, GLint, v1); \
    HookWrapper3(void,  glUniform2ui, GLint, location, GLuint, v0, GLuint, v1); \
    HookWrapper3(void,   glUniform2d, GLint, location, GLdouble, x, GLdouble, y); \
    HookWrapper4(void,   glUniform3f, GLint, location, GLfloat, v0, GLfloat, v1, GLfloat, v2); \
    HookWrapper4(void,   glUniform3i, GLint, location, GLint, v0, GLint, v1, GLint, v2); \
    HookWrapper4(void,  glUniform3ui, GLint, location, GLuint, v0, GLuint, v1, GLuint, v2); \
    HookWrapper4(void,   glUniform3d, GLint, location, GLdouble, x, GLdouble, y, GLdouble, z); \
    HookWrapper5(void,   glUniform4f, GLint, location, GLfloat, v0, GLfloat, v1, GLfloat, v2, GLfloat, v3); \
    HookWrapper5(void,   glUniform4i, GLint, location, GLint, v0, GLint, v1, GLint, v2, GLint, v3); \
    HookWrapper5(void,  glUniform4ui, GLint, location, GLuint, v0, GLuint, v1, GLuint, v2, GLuint, v3); \
    HookWrapper5(void,   glUniform4d, GLint, location, GLdouble, x, GLdouble, y, GLdouble, z, GLdouble, w); \
    HookWrapper3(void,  glUniform1fv, GLint, location, GLsizei, count, const GLfloat *, value); \
    HookWrapper3(void,  glUniform1iv, GLint, location, GLsizei, count, const GLint *, value); \
    HookWrapper3(void, glUniform1uiv, GLint, location, GLsizei, count, const GLuint *, value); \
    HookWrapper3(void,  glUniform1dv, GLint, location, GLsizei, count, const GLdouble *, value); \
    HookWrapper3(void,  glUniform2fv, GLint, location, GLsizei, count, const GLfloat *, value); \
    HookWrapper3(void,  glUniform2iv, GLint, location, GLsizei, count, const GLint *, value); \
    HookWrapper3(void, glUniform2uiv, GLint, location, GLsizei, count, const GLuint *, value); \
    HookWrapper3(void,  glUniform2dv, GLint, location, GLsizei, count, const GLdouble *, value); \
    HookWrapper3(void,  glUniform3fv, GLint, location, GLsizei, count, const GLfloat *, value); \
    HookWrapper3(void,  glUniform3iv, GLint, location, GLsizei, count, const GLint *, value); \
    HookWrapper3(void, glUniform3uiv, GLint, location, GLsizei, count, const GLuint *, value); \
    HookWrapper3(void,  glUniform3dv, GLint, location, GLsizei, count, const GLdouble *, value); \
    HookWrapper3(void,  glUniform4fv, GLint, location, GLsizei, count, const GLfloat *, value); \
    HookWrapper3(void,  glUniform4iv, GLint, location, GLsizei, count, const GLint *, value); \
    HookWrapper3(void, glUniform4uiv, GLint, location, GLsizei, count, const GLuint *, value); \
    HookWrapper3(void,  glUniform4dv, GLint, location, GLsizei, count, const GLdouble *, value); \
    HookWrapper4(void,   glUniformMatrix2fv, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper4(void, glUniformMatrix2x3fv, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper4(void, glUniformMatrix2x4fv, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper4(void,   glUniformMatrix3fv, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper4(void, glUniformMatrix3x2fv, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper4(void, glUniformMatrix3x4fv, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper4(void,   glUniformMatrix4fv, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper4(void, glUniformMatrix4x2fv, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper4(void, glUniformMatrix4x3fv, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper4(void,   glUniformMatrix2dv, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper4(void, glUniformMatrix2x3dv, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper4(void, glUniformMatrix2x4dv, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper4(void,   glUniformMatrix3dv, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper4(void, glUniformMatrix3x2dv, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper4(void, glUniformMatrix3x4dv, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper4(void,   glUniformMatrix4dv, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper4(void, glUniformMatrix4x2dv, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper4(void, glUniformMatrix4x3dv, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper3(void,   glProgramUniform1f, GLuint, program, GLint, location, GLfloat, v0); \
    HookWrapper3(void,   glProgramUniform1i, GLuint, program, GLint, location, GLint, v0); \
    HookWrapper3(void,  glProgramUniform1ui, GLuint, program, GLint, location, GLuint, v0); \
    HookWrapper3(void,   glProgramUniform1d, GLuint, program, GLint, location, GLdouble, v0); \
    HookWrapper4(void,   glProgramUniform2f, GLuint, program, GLint, location, GLfloat, v0, GLfloat, v1); \
    HookWrapper4(void,   glProgramUniform2i, GLuint, program, GLint, location, GLint, v0, GLint, v1); \
    HookWrapper4(void,  glProgramUniform2ui, GLuint, program, GLint, location, GLuint, v0, GLuint, v1); \
    HookWrapper4(void,   glProgramUniform2d, GLuint, program, GLint, location, GLdouble, v0, GLdouble, v1); \
    HookWrapper5(void,   glProgramUniform3f, GLuint, program, GLint, location, GLfloat, v0, GLfloat, v1, GLfloat, v2); \
    HookWrapper5(void,   glProgramUniform3i, GLuint, program, GLint, location, GLint, v0, GLint, v1, GLint, v2); \
    HookWrapper5(void,  glProgramUniform3ui, GLuint, program, GLint, location, GLuint, v0, GLuint, v1, GLuint, v2); \
    HookWrapper5(void,   glProgramUniform3d, GLuint, program, GLint, location, GLdouble, v0, GLdouble, v1, GLdouble, v2); \
    HookWrapper6(void,   glProgramUniform4f, GLuint, program, GLint, location, GLfloat, v0, GLfloat, v1, GLfloat, v2, GLfloat, v3); \
    HookWrapper6(void,   glProgramUniform4i, GLuint, program, GLint, location, GLint, v0, GLint, v1, GLint, v2, GLint, v3); \
    HookWrapper6(void,  glProgramUniform4ui, GLuint, program, GLint, location, GLuint, v0, GLuint, v1, GLuint, v2, GLuint, v3); \
    HookWrapper6(void,   glProgramUniform4d, GLuint, program, GLint, location, GLdouble, v0, GLdouble, v1, GLdouble, v2, GLdouble, v3); \
    HookWrapper4(void,  glProgramUniform1fv, GLuint, program, GLint, location, GLsizei, count, const GLfloat *, value); \
    HookWrapper4(void,  glProgramUniform1iv, GLuint, program, GLint, location, GLsizei, count, const GLint *, value); \
    HookWrapper4(void, glProgramUniform1uiv, GLuint, program, GLint, location, GLsizei, count, const GLuint *, value); \
    HookWrapper4(void,  glProgramUniform1dv, GLuint, program, GLint, location, GLsizei, count, const GLdouble *, value); \
    HookWrapper4(void,  glProgramUniform2fv, GLuint, program, GLint, location, GLsizei, count, const GLfloat *, value); \
    HookWrapper4(void,  glProgramUniform2iv, GLuint, program, GLint, location, GLsizei, count, const GLint *, value); \
    HookWrapper4(void, glProgramUniform2uiv, GLuint, program, GLint, location, GLsizei, count, const GLuint *, value); \
    HookWrapper4(void,  glProgramUniform2dv, GLuint, program, GLint, location, GLsizei, count, const GLdouble *, value); \
    HookWrapper4(void,  glProgramUniform3fv, GLuint, program, GLint, location, GLsizei, count, const GLfloat *, value); \
    HookWrapper4(void,  glProgramUniform3iv, GLuint, program, GLint, location, GLsizei, count, const GLint *, value); \
    HookWrapper4(void, glProgramUniform3uiv, GLuint, program, GLint, location, GLsizei, count, const GLuint *, value); \
    HookWrapper4(void,  glProgramUniform3dv, GLuint, program, GLint, location, GLsizei, count, const GLdouble *, value); \
    HookWrapper4(void,  glProgramUniform4fv, GLuint, program, GLint, location, GLsizei, count, const GLfloat *, value); \
    HookWrapper4(void,  glProgramUniform4iv, GLuint, program, GLint, location, GLsizei, count, const GLint *, value); \
    HookWrapper4(void, glProgramUniform4uiv, GLuint, program, GLint, location, GLsizei, count, const GLuint *, value); \
    HookWrapper4(void,  glProgramUniform4dv, GLuint, program, GLint, location, GLsizei, count, const GLdouble *, value); \
    HookWrapper5(void,   glProgramUniformMatrix2fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper5(void, glProgramUniformMatrix2x3fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper5(void, glProgramUniformMatrix2x4fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper5(void,   glProgramUniformMatrix3fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper5(void, glProgramUniformMatrix3x2fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper5(void, glProgramUniformMatrix3x4fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper5(void,   glProgramUniformMatrix4fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper5(void, glProgramUniformMatrix4x2fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper5(void, glProgramUniformMatrix4x3fv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLfloat *, value); \
    HookWrapper5(void,   glProgramUniformMatrix2dv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper5(void, glProgramUniformMatrix2x3dv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper5(void, glProgramUniformMatrix2x4dv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper5(void,   glProgramUniformMatrix3dv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper5(void, glProgramUniformMatrix3x2dv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper5(void, glProgramUniformMatrix3x4dv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper5(void,   glProgramUniformMatrix4dv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper5(void, glProgramUniformMatrix4x2dv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper5(void, glProgramUniformMatrix4x3dv, GLuint, program, GLint, location, GLsizei, count, GLboolean, transpose, const GLdouble *, value); \
    HookWrapper6(void, glDrawRangeElements, GLenum, mode, GLuint, start, GLuint, end, GLsizei, count, GLenum, type, const void *, indices); \
    HookWrapper7(void, glDrawRangeElementsBaseVertex, GLenum, mode, GLuint, start, GLuint, end, GLsizei, count, GLenum, type, const void *, indices, GLint, basevertex); \
    HookWrapper5(void, glDrawArraysInstancedBaseInstance, GLenum, mode, GLint, first, GLsizei, count, GLsizei, instancecount, GLuint, baseinstance); \
    HookWrapper4(void, glDrawArraysInstanced, GLenum, mode, GLint, first, GLsizei, count, GLsizei, instancecount); \
    HookWrapper5(void, glDrawElementsInstanced, GLenum, mode, GLsizei, count, GLenum, type, const void *, indices, GLsizei, instancecount); \
    HookWrapper6(void, glDrawElementsInstancedBaseInstance, GLenum, mode, GLsizei, count, GLenum, type, const void *, indices, GLsizei, instancecount, GLuint, baseinstance); \
    HookWrapper5(void, glDrawElementsBaseVertex, GLenum, mode, GLsizei, count, GLenum, type, const void *, indices, GLint, basevertex); \
    HookWrapper6(void, glDrawElementsInstancedBaseVertex, GLenum, mode, GLsizei, count, GLenum, type, const void *, indices, GLsizei, instancecount, GLint, basevertex); \
    HookWrapper7(void, glDrawElementsInstancedBaseVertexBaseInstance, GLenum, mode, GLsizei, count, GLenum, type, const void *, indices, GLsizei, instancecount, GLint, basevertex, GLuint, baseinstance); \
    HookWrapper4(void, glMultiDrawArrays, GLenum, mode, const GLint *, first, const GLsizei *, count, GLsizei, drawcount); \
    HookWrapper5(void, glMultiDrawElements, GLenum, mode, const GLsizei *, count, GLenum, type, const void *const*, indices, GLsizei, drawcount); \
    HookWrapper6(void, glMultiDrawElementsBaseVertex, GLenum, mode, const GLsizei *, count, GLenum, type, const void *const*, indices, GLsizei, drawcount, const GLint *, basevertex); \
    HookWrapper4(void, glMultiDrawArraysIndirect, GLenum, mode, const void *, indirect, GLsizei, drawcount, GLsizei, stride); \
    HookWrapper5(void, glMultiDrawElementsIndirect, GLenum, mode, GLenum, type, const void *, indirect, GLsizei, drawcount, GLsizei, stride); \
    HookWrapper2(void, glDrawArraysIndirect, GLenum, mode, const void *, indirect); \
    HookWrapper3(void, glDrawElementsIndirect, GLenum, mode, GLenum, type, const void *, indirect); \
    HookWrapper10(void, glBlitFramebuffer, GLint, srcX0, GLint, srcY0, GLint, srcX1, GLint, srcY1, GLint, dstX0, GLint, dstY0, GLint, dstX1, GLint, dstY1, GLbitfield, mask, GLenum, filter); \
    HookWrapper2(GLenum, glCheckNamedFramebufferStatusEXT, GLuint, framebuffer, GLenum, target); \
    HookWrapper8(void, glCompressedTextureImage1DEXT, GLuint, texture, GLenum, target, GLint, level, GLenum, internalformat, GLsizei, width, GLint, border, GLsizei, imageSize, const void *, bits); \
    HookWrapper9(void, glCompressedTextureImage2DEXT, GLuint, texture, GLenum, target, GLint, level, GLenum, internalformat, GLsizei, width, GLsizei, height, GLint, border, GLsizei, imageSize, const void *, bits); \
    HookWrapper10(void, glCompressedTextureImage3DEXT, GLuint, texture, GLenum, target, GLint, level, GLenum, internalformat, GLsizei, width, GLsizei, height, GLsizei, depth, GLint, border, GLsizei, imageSize, const void *, bits); \
    HookWrapper8(void, glCompressedTextureSubImage1DEXT, GLuint, texture, GLenum, target, GLint, level, GLint, xoffset, GLsizei, width, GLenum, format, GLsizei, imageSize, const void *, bits); \
    HookWrapper10(void, glCompressedTextureSubImage2DEXT, GLuint, texture, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLsizei, width, GLsizei, height, GLenum, format, GLsizei, imageSize, const void *, bits); \
    HookWrapper12(void, glCompressedTextureSubImage3DEXT, GLuint, texture, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLint, zoffset, GLsizei, width, GLsizei, height, GLsizei, depth, GLenum, format, GLsizei, imageSize, const void *, bits); \
    HookWrapper3(void, glFramebufferDrawBuffersEXT, GLuint, framebuffer, GLsizei, n, const GLenum *, bufs); \
    HookWrapper2(void, glGenerateTextureMipmapEXT, GLuint, texture, GLenum, target); \
    HookWrapper3(void, glGetPointeri_vEXT, GLenum, pname, GLuint, index, void **, params); \
    HookWrapper3(void, glGetDoubleIndexedvEXT, GLenum, target, GLuint, index, GLdouble *, data); \
    HookWrapper3(void, glGetPointerIndexedvEXT, GLenum, target, GLuint, index, void **, data); \
    HookWrapper3(void, glGetIntegerIndexedvEXT, GLenum, target, GLuint, index, GLint *, data); \
    HookWrapper3(void, glGetBooleanIndexedvEXT, GLenum, target, GLuint, index, GLboolean *, data); \
    HookWrapper3(void, glGetFloatIndexedvEXT, GLenum, target, GLuint, index, GLfloat *, data); \
    HookWrapper6(void, glGetMultiTexImageEXT, GLenum, texunit, GLenum, target, GLint, level, GLenum, format, GLenum, type, void *, pixels); \
    HookWrapper4(void, glGetMultiTexParameterfvEXT, GLenum, texunit, GLenum, target, GLenum, pname, GLfloat *, params); \
    HookWrapper4(void, glGetMultiTexParameterivEXT, GLenum, texunit, GLenum, target, GLenum, pname, GLint *, params); \
    HookWrapper4(void, glGetMultiTexParameterIivEXT, GLenum, texunit, GLenum, target, GLenum, pname, GLint *, params); \
    HookWrapper4(void, glGetMultiTexParameterIuivEXT, GLenum, texunit, GLenum, target, GLenum, pname, GLuint *, params); \
    HookWrapper5(void, glGetMultiTexLevelParameterfvEXT, GLenum, texunit, GLenum, target, GLint, level, GLenum, pname, GLfloat *, params); \
    HookWrapper5(void, glGetMultiTexLevelParameterivEXT, GLenum, texunit, GLenum, target, GLint, level, GLenum, pname, GLint *, params); \
    HookWrapper4(void, glGetCompressedMultiTexImageEXT, GLenum, texunit, GLenum, target, GLint, lod, void *, img); \
    HookWrapper3(void, glGetNamedBufferPointervEXT, GLuint, buffer, GLenum, pname, void **, params); \
    HookWrapper4(void, glGetNamedProgramivEXT, GLuint, program, GLenum, target, GLenum, pname, GLint *, params); \
    HookWrapper4(void, glGetNamedFramebufferAttachmentParameterivEXT, GLuint, framebuffer, GLenum, attachment, GLenum, pname, GLint *, params); \
    HookWrapper3(void, glGetNamedBufferParameterivEXT, GLuint, buffer, GLenum, pname, GLint *, params); \
    HookWrapper4(void, glGetNamedBufferSubDataEXT, GLuint, buffer, GLintptr, offset, GLsizeiptr, size, void *, data); \
    HookWrapper3(void, glGetNamedFramebufferParameterivEXT, GLuint, framebuffer, GLenum, pname, GLint *, params); \
    HookWrapper3(void, glGetNamedRenderbufferParameterivEXT, GLuint, renderbuffer, GLenum, pname, GLint *, params); \
    HookWrapper3(void, glGetVertexArrayIntegervEXT, GLuint, vaobj, GLenum, pname, GLint *, param); \
    HookWrapper3(void, glGetVertexArrayPointervEXT, GLuint, vaobj, GLenum, pname, void **, param); \
    HookWrapper4(void, glGetVertexArrayIntegeri_vEXT, GLuint, vaobj, GLuint, index, GLenum, pname, GLint *, param); \
    HookWrapper4(void, glGetVertexArrayPointeri_vEXT, GLuint, vaobj, GLuint, index, GLenum, pname, void **, param); \
    HookWrapper4(void, glGetCompressedTextureImageEXT, GLuint, texture, GLenum, target, GLint, lod, void *, img); \
    HookWrapper6(void, glGetTextureImageEXT, GLuint, texture, GLenum, target, GLint, level, GLenum, format, GLenum, type, void *, pixels); \
    HookWrapper4(void, glGetTextureParameterivEXT, GLuint, texture, GLenum, target, GLenum, pname, GLint *, params); \
    HookWrapper4(void, glGetTextureParameterfvEXT, GLuint, texture, GLenum, target, GLenum, pname, GLfloat *, params); \
    HookWrapper4(void, glGetTextureParameterIivEXT, GLuint, texture, GLenum, target, GLenum, pname, GLint *, params); \
    HookWrapper4(void, glGetTextureParameterIuivEXT, GLuint, texture, GLenum, target, GLenum, pname, GLuint *, params); \
    HookWrapper5(void, glGetTextureLevelParameterivEXT, GLuint, texture, GLenum, target, GLint, level, GLenum, pname, GLint *, params); \
    HookWrapper5(void, glGetTextureLevelParameterfvEXT, GLuint, texture, GLenum, target, GLint, level, GLenum, pname, GLfloat *, params); \
    HookWrapper3(void, glBindMultiTextureEXT, GLenum, texunit, GLenum, target, GLuint, texture); \
    HookWrapper2(void *, glMapNamedBufferEXT, GLuint, buffer, GLenum, access); \
    HookWrapper4(void *, glMapNamedBufferRangeEXT, GLuint, buffer, GLintptr, offset, GLsizeiptr, length, GLbitfield, access); \
    HookWrapper3(void, glFlushMappedNamedBufferRangeEXT, GLuint, buffer, GLintptr, offset, GLsizeiptr, length); \
    HookWrapper1(GLboolean, glUnmapNamedBufferEXT, GLuint, buffer); \
    HookWrapper5(void, glClearNamedBufferDataEXT, GLuint, buffer, GLenum, internalformat, GLenum, format, GLenum, type, const void *, data); \
    HookWrapper7(void, glClearNamedBufferSubDataEXT, GLuint, buffer, GLenum, internalformat, GLsizeiptr, offset, GLsizeiptr, size, GLenum, format, GLenum, type, const void *, data); \
    HookWrapper4(void, glNamedBufferDataEXT, GLuint, buffer, GLsizeiptr, size, const void *, data, GLenum, usage); \
    HookWrapper4(void, glNamedBufferStorageEXT, GLuint, buffer, GLsizeiptr, size, const void *, data, GLbitfield, flags); \
    HookWrapper4(void, glNamedBufferSubDataEXT, GLuint, buffer, GLintptr, offset, GLsizeiptr, size, const void *, data); \
    HookWrapper5(void, glNamedCopyBufferSubDataEXT, GLuint, readBuffer, GLuint, writeBuffer, GLintptr, readOffset, GLintptr, writeOffset, GLsizeiptr, size); \
    HookWrapper4(void, glNamedFramebufferTextureEXT, GLuint, framebuffer, GLenum, attachment, GLuint, texture, GLint, level); \
    HookWrapper5(void, glNamedFramebufferTexture1DEXT, GLuint, framebuffer, GLenum, attachment, GLenum, textarget, GLuint, texture, GLint, level); \
    HookWrapper5(void, glNamedFramebufferTexture2DEXT, GLuint, framebuffer, GLenum, attachment, GLenum, textarget, GLuint, texture, GLint, level); \
    HookWrapper6(void, glNamedFramebufferTexture3DEXT, GLuint, framebuffer, GLenum, attachment, GLenum, textarget, GLuint, texture, GLint, level, GLint, zoffset); \
    HookWrapper4(void, glNamedFramebufferRenderbufferEXT, GLuint, framebuffer, GLenum, attachment, GLenum, renderbuffertarget, GLuint, renderbuffer); \
    HookWrapper5(void, glNamedFramebufferTextureLayerEXT, GLuint, framebuffer, GLenum, attachment, GLuint, texture, GLint, level, GLint, layer); \
    HookWrapper3(void, glNamedFramebufferParameteriEXT, GLuint, framebuffer, GLenum, pname, GLint, param); \
    HookWrapper4(void, glNamedRenderbufferStorageEXT, GLuint, renderbuffer, GLenum, internalformat, GLsizei, width, GLsizei, height); \
    HookWrapper5(void, glNamedRenderbufferStorageMultisampleEXT, GLuint, renderbuffer, GLsizei, samples, GLenum, internalformat, GLsizei, width, GLsizei, height); \
    HookWrapper2(void, glFramebufferDrawBufferEXT, GLuint, framebuffer, GLenum, mode); \
    HookWrapper2(void, glFramebufferReadBufferEXT, GLuint, framebuffer, GLenum, mode); \
    HookWrapper4(void, glTextureBufferEXT, GLuint, texture, GLenum, target, GLenum, internalformat, GLuint, buffer); \
    HookWrapper6(void, glTextureBufferRangeEXT, GLuint, texture, GLenum, target, GLenum, internalformat, GLuint, buffer, GLintptr, offset, GLsizeiptr, size); \
    HookWrapper9(void, glTextureImage1DEXT, GLuint, texture, GLenum, target, GLint, level, GLint, internalformat, GLsizei, width, GLint, border, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper10(void, glTextureImage2DEXT, GLuint, texture, GLenum, target, GLint, level, GLint, internalformat, GLsizei, width, GLsizei, height, GLint, border, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper11(void, glTextureImage3DEXT, GLuint, texture, GLenum, target, GLint, level, GLint, internalformat, GLsizei, width, GLsizei, height, GLsizei, depth, GLint, border, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper4(void, glTextureParameterfEXT, GLuint, texture, GLenum, target, GLenum, pname, GLfloat, param); \
    HookWrapper4(void, glTextureParameterfvEXT, GLuint, texture, GLenum, target, GLenum, pname, const GLfloat *, params); \
    HookWrapper4(void, glTextureParameteriEXT, GLuint, texture, GLenum, target, GLenum, pname, GLint, param); \
    HookWrapper4(void, glTextureParameterivEXT, GLuint, texture, GLenum, target, GLenum, pname, const GLint *, params); \
    HookWrapper4(void, glTextureParameterIivEXT, GLuint, texture, GLenum, target, GLenum, pname, const GLint *, params); \
    HookWrapper4(void, glTextureParameterIuivEXT, GLuint, texture, GLenum, target, GLenum, pname, const GLuint *, params); \
    HookWrapper5(void, glTextureStorage1DEXT, GLuint, texture, GLenum, target, GLsizei, levels, GLenum, internalformat, GLsizei, width); \
    HookWrapper6(void, glTextureStorage2DEXT, GLuint, texture, GLenum, target, GLsizei, levels, GLenum, internalformat, GLsizei, width, GLsizei, height); \
    HookWrapper7(void, glTextureStorage3DEXT, GLuint, texture, GLenum, target, GLsizei, levels, GLenum, internalformat, GLsizei, width, GLsizei, height, GLsizei, depth); \
    HookWrapper7(void, glTextureStorage2DMultisampleEXT, GLuint, texture, GLenum, target, GLsizei, samples, GLenum, internalformat, GLsizei, width, GLsizei, height, GLboolean, fixedsamplelocations); \
    HookWrapper8(void, glTextureStorage3DMultisampleEXT, GLuint, texture, GLenum, target, GLsizei, samples, GLenum, internalformat, GLsizei, width, GLsizei, height, GLsizei, depth, GLboolean, fixedsamplelocations); \
    HookWrapper8(void, glTextureSubImage1DEXT, GLuint, texture, GLenum, target, GLint, level, GLint, xoffset, GLsizei, width, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper10(void, glTextureSubImage2DEXT, GLuint, texture, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLsizei, width, GLsizei, height, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper12(void, glTextureSubImage3DEXT, GLuint, texture, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLint, zoffset, GLsizei, width, GLsizei, height, GLsizei, depth, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper8(void, glCopyTextureImage1DEXT, GLuint, texture, GLenum, target, GLint, level, GLenum, internalformat, GLint, x, GLint, y, GLsizei, width, GLint, border); \
    HookWrapper9(void, glCopyTextureImage2DEXT, GLuint, texture, GLenum, target, GLint, level, GLenum, internalformat, GLint, x, GLint, y, GLsizei, width, GLsizei, height, GLint, border); \
    HookWrapper7(void, glCopyTextureSubImage1DEXT, GLuint, texture, GLenum, target, GLint, level, GLint, xoffset, GLint, x, GLint, y, GLsizei, width); \
    HookWrapper9(void, glCopyTextureSubImage2DEXT, GLuint, texture, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLint, x, GLint, y, GLsizei, width, GLsizei, height); \
    HookWrapper10(void, glCopyTextureSubImage3DEXT, GLuint, texture, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLint, zoffset, GLint, x, GLint, y, GLsizei, width, GLsizei, height); \
    HookWrapper4(void, glMultiTexParameteriEXT, GLenum, texunit, GLenum, target, GLenum, pname, GLint, param); \
    HookWrapper4(void, glMultiTexParameterivEXT, GLenum, texunit, GLenum, target, GLenum, pname, const GLint *, params); \
    HookWrapper4(void, glMultiTexParameterfEXT, GLenum, texunit, GLenum, target, GLenum, pname, GLfloat, param); \
    HookWrapper4(void, glMultiTexParameterfvEXT, GLenum, texunit, GLenum, target, GLenum, pname, const GLfloat *, params); \
    HookWrapper9(void, glMultiTexImage1DEXT, GLenum, texunit, GLenum, target, GLint, level, GLint, internalformat, GLsizei, width, GLint, border, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper10(void, glMultiTexImage2DEXT, GLenum, texunit, GLenum, target, GLint, level, GLint, internalformat, GLsizei, width, GLsizei, height, GLint, border, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper8(void, glMultiTexSubImage1DEXT, GLenum, texunit, GLenum, target, GLint, level, GLint, xoffset, GLsizei, width, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper10(void, glMultiTexSubImage2DEXT, GLenum, texunit, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLsizei, width, GLsizei, height, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper8(void, glCopyMultiTexImage1DEXT, GLenum, texunit, GLenum, target, GLint, level, GLenum, internalformat, GLint, x, GLint, y, GLsizei, width, GLint, border); \
    HookWrapper9(void, glCopyMultiTexImage2DEXT, GLenum, texunit, GLenum, target, GLint, level, GLenum, internalformat, GLint, x, GLint, y, GLsizei, width, GLsizei, height, GLint, border); \
    HookWrapper7(void, glCopyMultiTexSubImage1DEXT, GLenum, texunit, GLenum, target, GLint, level, GLint, xoffset, GLint, x, GLint, y, GLsizei, width); \
    HookWrapper9(void, glCopyMultiTexSubImage2DEXT, GLenum, texunit, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLint, x, GLint, y, GLsizei, width, GLsizei, height); \
    HookWrapper11(void, glMultiTexImage3DEXT, GLenum, texunit, GLenum, target, GLint, level, GLint, internalformat, GLsizei, width, GLsizei, height, GLsizei, depth, GLint, border, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper12(void, glMultiTexSubImage3DEXT, GLenum, texunit, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLint, zoffset, GLsizei, width, GLsizei, height, GLsizei, depth, GLenum, format, GLenum, type, const void *, pixels); \
    HookWrapper10(void, glCopyMultiTexSubImage3DEXT, GLenum, texunit, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLint, zoffset, GLint, x, GLint, y, GLsizei, width, GLsizei, height); \
    HookWrapper10(void, glCompressedMultiTexImage3DEXT, GLenum, texunit, GLenum, target, GLint, level, GLenum, internalformat, GLsizei, width, GLsizei, height, GLsizei, depth, GLint, border, GLsizei, imageSize, const void *, bits); \
    HookWrapper9(void, glCompressedMultiTexImage2DEXT, GLenum, texunit, GLenum, target, GLint, level, GLenum, internalformat, GLsizei, width, GLsizei, height, GLint, border, GLsizei, imageSize, const void *, bits); \
    HookWrapper8(void, glCompressedMultiTexImage1DEXT, GLenum, texunit, GLenum, target, GLint, level, GLenum, internalformat, GLsizei, width, GLint, border, GLsizei, imageSize, const void *, bits); \
    HookWrapper12(void, glCompressedMultiTexSubImage3DEXT, GLenum, texunit, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLint, zoffset, GLsizei, width, GLsizei, height, GLsizei, depth, GLenum, format, GLsizei, imageSize, const void *, bits); \
    HookWrapper10(void, glCompressedMultiTexSubImage2DEXT, GLenum, texunit, GLenum, target, GLint, level, GLint, xoffset, GLint, yoffset, GLsizei, width, GLsizei, height, GLenum, format, GLsizei, imageSize, const void *, bits); \
    HookWrapper8(void, glCompressedMultiTexSubImage1DEXT, GLenum, texunit, GLenum, target, GLint, level, GLint, xoffset, GLsizei, width, GLenum, format, GLsizei, imageSize, const void *, bits); \
    HookWrapper4(void, glMultiTexBufferEXT, GLenum, texunit, GLenum, target, GLenum, internalformat, GLuint, buffer); \
    HookWrapper4(void, glMultiTexParameterIivEXT, GLenum, texunit, GLenum, target, GLenum, pname, const GLint *, params); \
    HookWrapper4(void, glMultiTexParameterIuivEXT, GLenum, texunit, GLenum, target, GLenum, pname, const GLuint *, params); \
    HookWrapper2(void, glGenerateMultiTexMipmapEXT, GLenum, texunit, GLenum, target); \
    HookWrapper8(void, glVertexArrayVertexAttribOffsetEXT, GLuint, vaobj, GLuint, buffer, GLuint, index, GLint, size, GLenum, type, GLboolean, normalized, GLsizei, stride, GLintptr, offset); \
    HookWrapper7(void, glVertexArrayVertexAttribIOffsetEXT, GLuint, vaobj, GLuint, buffer, GLuint, index, GLint, size, GLenum, type, GLsizei, stride, GLintptr, offset); \
    HookWrapper2(void, glEnableVertexArrayAttribEXT, GLuint, vaobj, GLuint, index); \
    HookWrapper2(void, glDisableVertexArrayAttribEXT, GLuint, vaobj, GLuint, index); \
    HookWrapper5(void, glVertexArrayBindVertexBufferEXT, GLuint, vaobj, GLuint, bindingindex, GLuint, buffer, GLintptr, offset, GLsizei, stride); \
    HookWrapper6(void, glVertexArrayVertexAttribFormatEXT, GLuint, vaobj, GLuint, attribindex, GLint, size, GLenum, type, GLboolean, normalized, GLuint, relativeoffset); \
    HookWrapper5(void, glVertexArrayVertexAttribIFormatEXT, GLuint, vaobj, GLuint, attribindex, GLint, size, GLenum, type, GLuint, relativeoffset); \
    HookWrapper5(void, glVertexArrayVertexAttribLFormatEXT, GLuint, vaobj, GLuint, attribindex, GLint, size, GLenum, type, GLuint, relativeoffset); \
    HookWrapper3(void, glVertexArrayVertexAttribBindingEXT, GLuint, vaobj, GLuint, attribindex, GLuint, bindingindex); \
    HookWrapper3(void, glVertexArrayVertexBindingDivisorEXT, GLuint, vaobj, GLuint, bindingindex, GLuint, divisor); \
    HookWrapper7(void, glVertexArrayVertexAttribLOffsetEXT, GLuint, vaobj, GLuint, buffer, GLuint, index, GLint, size, GLenum, type, GLsizei, stride, GLintptr, offset); \
    HookWrapper3(void, glVertexArrayVertexAttribDivisorEXT, GLuint, vaobj, GLuint, index, GLuint, divisor); \




