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

	void CharaSelectBackGroudn();

	// �X�^�[�g�{�^���������̏����錾 �߂� Object ���@Ref �ɕύX
	void pushStart(Ref *pSender);
};

#endif // Title