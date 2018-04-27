#ifndef __Screen__DiffSelectScene__
#define __Screen__DiffSelectScene__

#include "cocos2d.h"

USING_NS_CC;

class DiffSelectScene :public cocos2d::Layer
{
public:
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(DiffSelectScene);

	void SelectBackGroudn();

	// スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
	void pushStart(Ref *pSender);
};

#endif //Select