#ifndef __Screen__GameOver__
#define __Screen__GameOver__

#include "cocos2d.h"

USING_NS_CC;

class GameOver :public cocos2d::Layer
{
public:
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(GameOver);

	void ClearBackGroudn();

	// スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
	void pushStart(Ref *pSender);
private:
	int m_iCount = 0;
	// 魔法陣表示
	void MagicEffect();
	// 回復
	void RecoveryEffect();
	// 剣
	void SwordEffect();
	// 破門
	void Ripple();
	// test
	void Test();
	
};

#endif //Select