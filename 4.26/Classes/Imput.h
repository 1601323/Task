#include "cocos2d.h"

class Imput :public cocos2d::Layer
{
public:
	virtual bool init();	// ����
	
	// �^�b�`�J�n
	virtual bool TouchBegan(cocos2d::Touch* touch,cocos2d::Event* event);
	// �X���C�v
	virtual void TouchMove(cocos2d::Touch* touch, cocos2d::Event* event);
	// �^�b�`�I��
	virtual void TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);
	// �L�����Z��
	virtual void TouchCansell(cocos2d::Touch* touch, cocos2d::Event* event);
};

