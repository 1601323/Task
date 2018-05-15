
#include "Shaders.hpp"
// STRINGIFYマクロを登録(frag,vert)
#define STRINGIFY(A) #A
namespace cocos2d 
{
	// ファイル読み込み
#include "shaders/light_rgb.frag"
#include "shaders/light_rgb.vert"

#include "shaders/light_hsv.frag"
#include "shaders/light_hsv.vert"
};