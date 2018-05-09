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
	int m_iCount;
	// ���@�w�\��
	void MagicEffect();
	// ��
	void RecoveryEffect();
	// ��
	void SwordEffect();
	// ��
	void LightEffect();
	
};

#endif //Select