#include "Imput.h"

USING_NS_CC;

// 初期化
bool Imput::init()
{
	if (!Layer::init())
	{
		return false;
	}

	// 取得
	auto touchGet = EventListenerTouchOneByOne::create();

	touchGet->onTouchBegan = CC_CALLBACK_2(Imput::TouchBegan, this);
	touchGet->onTouchMoved = CC_CALLBACK_2(Imput::TouchMove, this);
	touchGet->onTouchEnded = CC_CALLBACK_2(Imput::TouchEnd, this);
	touchGet->onTouchCancelled = CC_CALLBACK_2(Imput::TouchCansell, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchGet, this);
}

// Touch開始
bool Imput::TouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	return true;
}

// Touch移動
void Imput::TouchMove(cocos2d::Touch * touch, cocos2d::Event * event)
{
	
}

// Touch終わり
void Imput::TouchEnd(cocos2d::Touch * touch, cocos2d::Event * event)
{
	
}

// Touchキャンセル
void Imput::TouchCansell(cocos2d::Touch * touch, cocos2d::Event * event)
{
	onTouchEnded(touch,event);
}
