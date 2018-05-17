#ifndef Shaders_hpp
#define Shaders_hpp

#include <stdio.h>
#include "cocos2d.h"
namespace cocos2d {
	// shaderで定義した名前をここで定義
	extern const GLchar* LightRgbShaderVert;
	extern const GLchar* LightRgbShaderFrag;
	extern const GLchar* LightHsvShaderVert;
	extern const GLchar* LightHsvShaderFrag;
	// auraのやつ
	extern const GLchar* GlowFsh;

	extern const GLchar* RainbowFrag;
	// ブラー用
	extern const GLchar* BlurShaderVert;
	extern const GLchar* BlurShaderFrag;
};

#endif