#ifndef __Screen__BossScene__
#define __Screen__BossScene__

#include "cocos2d.h"

USING_NS_CC;

class BossScene :public cocos2d::Layer
{
public:
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(BossScene);

	void BossBackGroudn();

	// スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
	void pushStart(Ref *pSender);
};

#endif //Select