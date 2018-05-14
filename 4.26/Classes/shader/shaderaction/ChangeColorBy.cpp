#include "../Shaders.hpp"
#include "ChangeColorBy.hpp"

USING_NS_CC;

// https://github.com/brbranch/cocos2dxv3Brightness
// http://pg-boxer.cocolog-nifty.com/nikukyu/cat21931722/index.html
// http://brbranch.jp/blog/201607/cocos2d-x/shader/

// 
ChangeColorBy *ChangeColorBy::create(const ChangeColorType &type,const cocos2d::Vec3 &color, bool doReverse,float duration) 
{	
	// �F�ϊ��̃N���X����
    auto ref = new ChangeColorBy();
    if (ref && ref->initWithDuration(type, color, doReverse, duration)) 
	{
		// autorelease:�I�u�W�F�N�g��AutoreleasePool�ɓo�^�B�����I�ɔj�������悤�ɂȂ�B
        ref->autorelease();
        return ref;
    }
	//���S�ɂ�delete���Ă����
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

void ChangeColorBy::update(float f) {
    auto diff = m_reverse ? sinf(f * M_PI) : f;
    auto color = m_color * diff;
    auto shader = getTarget()->getGLProgramState();
    if (shader) {
        shader->setUniformVec3("u_color", color);
    }
}

void ChangeColorBy::startWithTarget(cocos2d::Node *target) {
    if (m_type == ChangeColorType::RGB) {
        setShaderWithTarget(target, LightRgbShaderVert, LightRgbShaderFrag);
    } else {
        setShaderWithTarget(target, LightHsvShaderVert, LightHsvShaderFrag);
    }
    ActionInterval::startWithTarget(target);
}

ActionInterval *ChangeColorBy::clone() const {
    return ChangeColorBy::create(m_type, m_color, m_reverse, _duration);
}

void ChangeColorBy::setShaderWithTarget(cocos2d::Node *target,
                                        const GLchar *vert,
                                        const GLchar *flag) {
    if (target == nullptr) {
        return;
    }
    auto s = GLProgram::createWithByteArrays(vert, flag);
    auto state = GLProgramState::getOrCreateWithGLProgram(s);
    target->setGLProgramState(state);
}