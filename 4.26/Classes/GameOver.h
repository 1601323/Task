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
	int m_iCount  = 0;
	float m_ctime = 0;
	// ���@�w�\��
	void MagicEffect();
	// ��
	void RecoveryEffect();
	// ��
	void SwordEffect();
	float fadeSpeed		    = 0.8f;	// �t�F�[�h����
	unsigned int startSpeed = 1;	// �\���J�n�܂ł̈ړ����x
	unsigned int imageSize	= 20;	// �摜�T�C�Y
	// �F
	// �j��
	void Ripple();
	// test
	void Shadow();
	// grow�\��
	bool glow();
	void callBackTime(GLProgram* glProgram,Uniform* uniform);
	void callbackColor(GLProgram* glProgram, Uniform* uniform);
	//�A���t�@
	void test();
	// �p�[�e�B�N���\��
	void particle();
	// �X�v���C�g��
	void sampleSprite();
	// �O���f�[�V����
	void changeGradation();
	// shader�X�v���C�g�����点��
	void glowSprite();
	// ��޼ު�ď���������
	// �I�[���o������
	void auraEffect();
	void objExtinctionEffect();
	//
	void test1();
	int keydown_flg = 1;
	void keyData();
	// �A�b�v�f�[�g
	void update(float delta);

	void scaling();
};

#endif //Select