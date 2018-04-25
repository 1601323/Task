#ifndef __Screen__FightScene__
#define __Screen__FightScene__

#include "cocos2d.h"

USING_NS_CC;

class FightScene :public cocos2d::Layer
{
public:
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(FightScene);

	void FightBackGroudn();

	// スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
	void pushStart(Ref *pSender);
};

#endif //Select