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

	// �X�^�[�g�{�^���������̏����錾 �߂� Object ���@Ref �ɕύX
	void pushStart(Ref *pSender);
};

#endif //Select