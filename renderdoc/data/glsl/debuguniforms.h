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

// use some preprocessor hacks to compile the same header in both GLSL and C++ so we can define
// classes that represent a whole cbuffer
#if defined(__cplusplus)

#define uniform struct
#define vec2 Vec2f
#define vec3 Vec3f
#define vec4 Vec4f
#define uint uint32_t

#define BINDING(b)

#else

#version 420 core

#define BINDING(b) layout (binding = b, std140) 

#endif

BINDING(0) uniform texdisplay
{
  vec2  Position;
  float Scale;
  float HDRMul;

  vec4  Channels;

  float RangeMinimum;
  float InverseRangeSize;
  float MipLevel;
  int   FlipY;

  vec3  TextureResolutionPS;
  int   OutputDisplayFormat;

  vec2  OutputRes;
  int   RawOutput;
  float Slice;

	int   SampleIdx;
	int   NumSamples;
	vec2  Padding;
};

BINDING(0) uniform FontUniforms
{
	vec2  TextPosition;
	float txtpadding;
	float TextSize;

	vec2  CharacterSize;
	vec2  FontScreenAspect;
};

BINDING(0) uniform HistogramCBufferData
{
	uint HistogramChannels;
	float HistogramMin;
	float HistogramMax;
	uint HistogramFlags;
	
	float HistogramSlice;
	int HistogramMip;
	int HistogramSample;
	int HistogramNumSamples;

	vec3 HistogramTextureResolution;
	float Padding3;
};

// some constants available to both C++ and GLSL for configuring display
#define CUBEMAP_FACE_POS_X 0
#define CUBEMAP_FACE_NEG_X 1
#define CUBEMAP_FACE_POS_Y 2
#define CUBEMAP_FACE_NEG_Y 3
#define CUBEMAP_FACE_POS_Z 4
#define CUBEMAP_FACE_NEG_Z 5

#define RESTYPE_TEX1D          0x1
#define RESTYPE_TEX2D          0x2
#define RESTYPE_TEX3D          0x3
#define RESTYPE_TEXCUBE        0x4
#define RESTYPE_TEX1DARRAY     0x5
#define RESTYPE_TEX2DARRAY     0x6
#define RESTYPE_TEXCUBEARRAY   0x7
#define RESTYPE_TEXRECT        0x8
#define RESTYPE_TEXBUFFER      0x9
#define RESTYPE_TEX2DMS        0xA
#define RESTYPE_TEXTYPEMAX     0xA

#define TEXDISPLAY_TYPEMASK    0xF
#define TEXDISPLAY_UINT_TEX    0x10
#define TEXDISPLAY_SINT_TEX    0x20
#define TEXDISPLAY_DEPTH_TEX   0x40
#define TEXDISPLAY_NANS        0x80
#define TEXDISPLAY_CLIPPING    0x100
#define TEXDISPLAY_GAMMA_CURVE 0x200

#ifndef FLT_EPSILON
#define FLT_EPSILON 1.192092896e-07f
#endif

// histogram/minmax is calculated in blocks of NxN each with MxM tiles.
// e.g. a tile is 32x32 pixels, then this is arranged in blocks of 32x32 tiles.
// 1 compute thread = 1 tile, 1 compute group = 1 block
//
// NOTE because of this a block can cover more than the texture (think of a 1280x720
// texture covered by 2x1 blocks)
//
// these values are in each dimension
#define HGRAM_PIXELS_PER_TILE  64
#define HGRAM_TILES_PER_BLOCK  32

#define HGRAM_NUM_BUCKETS	   256

