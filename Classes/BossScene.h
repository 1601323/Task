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

	// �X�^�[�g�{�^���������̏����錾 �߂� Object ���@Ref �ɕύX
	void pushStart(Ref *pSender);
};

#endif //Select