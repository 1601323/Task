#ifndef __Screen__CharaSelectScene__
#define __Screen__CharaSelectScene__

#include "cocos2d.h"

USING_NS_CC;

class CharaSelectScene :public cocos2d::Layer
{
public:
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(CharaSelectScene);
	cocos2d::Vector<cocos2d::Node *> items;
	float angle;
	void arrange();	// アレンジ
	// 背景
	void CharaSelectBackGroudn();

	void Effect();

	// スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
	void pushStart(Ref *pSender);
};

#endif // Title