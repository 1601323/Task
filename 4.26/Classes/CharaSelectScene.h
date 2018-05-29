#ifndef __Screen__CharaSelectScene__
#define __Screen__CharaSelectScene__
#include "cocos2d.h"
#include <Vector>

USING_NS_CC;

enum class CharaName
{
	CHARA_ATTACKER,		// ���j
	CHARA_SHIELD,		// ��j
	CHARA_MAGIC,		// �c�C��
	CHARA_GEALER,		// �P���~�~
};

class CharaSelectScene :public cocos2d::Layer
{
public:
	float angle;
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(CharaSelectScene);
	std::vector<cocos2d::Node *> items;

	// �w�i
	void CharaSelectBackGroudn();
	// �X�^�[�g�{�^���������̏����錾 �߂� Object ���@Ref �ɕύX
	void pushStart(Ref *pSender);
	// �I�����ꂽ�L�������i�[
	static const std::vector<CharaName>& GetCharaData();


private:
	Node* Top;
	// �L�������
	Sprite* PL_Attacker;	 // �����(���j)
	Sprite *PL_Shield;		 // ���(��j)
	Sprite *PL_Magic;		 // ���@�g��(�c�C��)
	Sprite *PL_Healer;		 // ��(����)
	void update(float delta);// �A�b�v�f�[�g
	void charaDraw();		 // �L�����\��
	void swipeRotation();	 // �X���C�v�ɍ��킹�ĉ�]
	void drawBox();			 // ���\��
	void fontsDraw();		 // �����`��
	void arrange();			 // �A�����W						
	void charaText();		 // ����������
	void clickCheck();			 // click���ꂽ��Ă΂��
	// �ۑ�����p�̃f�[�^
	static std::vector<CharaName> CharaData;
	// click����
	EventListenerTouchOneByOne *_listener = EventListenerTouchOneByOne::create();
};

#endif // Title