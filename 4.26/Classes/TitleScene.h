#ifndef __Screen__TitleScene__
#define __Screen__TitleScene__

#include "cocos2d.h"

USING_NS_CC;

class TitleScene :public cocos2d::Layer
{
public:
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(TitleScene);

	void TitleBackGroudn();

	// �X�^�[�g�{�^���������̏����錾 �߂� Object ���@Ref �ɕύX
	void pushStart(Ref *pSender);
};

#endif // Title