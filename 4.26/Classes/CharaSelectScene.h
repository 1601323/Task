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
	void arrange();	// �A�����W
	// �w�i
	void CharaSelectBackGroudn();
	// �X�^�[�g�{�^���������̏����錾 �߂� Object ���@Ref �ɕύX
	void pushStart(Ref *pSender);
	// �I�����ꂽ�L�������i�[
	static const std::vector<CharaName>& GetCharaData();

private:
	Node* Top;
	Sprite* PL_Attacker;
	Sprite *PL_Shield;
	Sprite *PL_Magic;
	Sprite *PL_Healer;
	void CharaClick();
	// �ۑ�����p�̃f�[�^
	static std::vector<CharaName> CharaData;
	//bool onTouchBegan(Touch *touch, Event *unused_event);
};

#endif // Title