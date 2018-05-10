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

	// �X�^�[�g�{�^���������̏����錾 �߂� Object ���@Ref �ɕύX
	void pushStart(Ref *pSender);
private:
	int m_iCount = 0;
	// ���@�w�\��
	void MagicEffect();
	// ��
	void RecoveryEffect();
	// ��
	void SwordEffect();
	// �j��
	void Ripple();
	// test
	void Test();
	
};

#endif //Select