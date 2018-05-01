#include "cocos2d.h"

class Imput :public cocos2d::Layer
{
public:
	virtual bool init();	// 初期
	
	// タッチ開始
	virtual bool TouchBegan(cocos2d::Touch* touch,cocos2d::Event* event);
	// スワイプ
	virtual void TouchMove(cocos2d::Touch* touch, cocos2d::Event* event);
	// タッチ終了
	virtual void TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);
	// キャンセル
	virtual void TouchCansell(cocos2d::Touch* touch, cocos2d::Event* event);
};

