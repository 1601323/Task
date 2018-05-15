#include "../Shaders.hpp"
#include "ChangeColorBy.hpp"

/*http://glslsandbox.com/e#46939.4
*/

USING_NS_CC;

// https://github.com/brbranch/cocos2dxv3Brightness
// http://pg-boxer.cocolog-nifty.com/nikukyu/cat21931722/index.html
// http://brbranch.jp/blog/201607/cocos2d-x/shader/

// 
ChangeColorBy *ChangeColorBy::create(const ChangeColorType &type,const cocos2d::Vec3 &color, bool doReverse,float duration)
{	
	// 色変換のクラス生成
    auto ref = new ChangeColorBy();
    if (ref && ref->initWithDuration(type, color, doReverse, duration)) 
	{
		// autorelease:オブジェクトをAutoreleasePoolに登録。自動的に破棄されるようになる。
        ref->autorelease();
        return ref;
    }
	//安全ににdeleteしてくれる
	// http://brbranch.jp/blog/201308/cocos2d-x/cocos2dxmacros/
    CC_SAFE_DELETE(ref);
    return nullptr;
}

// 
bool ChangeColorBy::initWithDuration(const ChangeColorType &type,const cocos2d::Vec3 &color, bool doReverse,float duration) 
{
	// 
    if (!ActionInterval::initWithDuration(duration)) 
	{
        return false;
    }
    m_type	  = type;
    m_color   = color;
    m_reverse = doReverse;
    return true;
}

// 更新
void ChangeColorBy::update(float f)
{
	// 違い true: /false: 
    auto diff   = m_reverse ? sinf(f * M_PI) : f;
    auto color  = m_color * diff;
    auto shader = getTarget()->getGLProgramState();
    if (shader)
	{
		// 色セット
        shader->setUniformVec3("u_color", color);
    }
}

void ChangeColorBy::startWithTarget(cocos2d::Node *target) 
{
	// RGBの場合
    if (m_type == ChangeColorType::RGB) 
	{
        setShaderWithTarget(target, LightRgbShaderVert, LightRgbShaderFrag);
    } 
	// HSVの場合
	else 
	{
        setShaderWithTarget(target, LightHsvShaderVert, LightHsvShaderFrag);
    }
	// アクション実行
    ActionInterval::startWithTarget(target);
}

// 複製
ActionInterval *ChangeColorBy::clone() const 
{
    return ChangeColorBy::create(m_type, m_color, m_reverse, _duration);
}

// ターゲットの設定
void ChangeColorBy::setShaderWithTarget(cocos2d::Node *target,const GLchar *vert,const GLchar *flag) 
{
    if (target == nullptr) 
	{
        return;
    }
	// バイト配列をもつ頂点とフラグメントで初期化
    auto s	   = GLProgram::createWithByteArrays(vert, flag);
	// 作成
    auto state = GLProgramState::getOrCreateWithGLProgram(s);
    target->setGLProgramState(state);
}