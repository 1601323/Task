#ifndef __Screen__GameClear__
#define __Screen__GameClear__

#include "cocos2d.h"

USING_NS_CC;

class GameClear :public cocos2d::Layer
{
public:
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(GameClear);

	void ClearBackGroudn();

	// スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
	void pushStart(Ref *pSender);
};

#endif //Select