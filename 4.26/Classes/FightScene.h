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

	// �X�^�[�g�{�^���������̏����錾 �߂� Object ���@Ref �ɕύX
	void pushStart(Ref *pSender);
};

#endif //Select