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

	// �X�^�[�g�{�^���������̏����錾 �߂� Object ���@Ref �ɕύX
	void pushStart(Ref *pSender);
};

#endif //Select