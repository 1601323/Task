#ifndef Shaders_hpp
#define Shaders_hpp

#include <stdio.h>
#include "cocos2d.h"

namespace cocos2d
{ // フラグメントシェーダー（GLSL）を読込んでリンクする
	extern const GLchar* LightRgbShaderVert;
	extern const GLchar* LightRgbShaderFrag;
	extern const GLchar* LightHsvShaderVert;
	extern const GLchar* LightHsvShaderFrag;
};

#endif /*Shaders_hpp*/
