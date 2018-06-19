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

	// �X�^�[�g�{�^���������̏����錾 �߂� Object ���@Ref �ɕύX
	void pushStart(Ref *pSender);
	// �I�����ꂽ�L�������i�[
	static const std::vector<CharaName>& GetCharaData();


private:
	Node* Top;
	// �L�������
	Sprite* PL_Attacker;			// �����(���j)
	Sprite *PL_Shield;				// ���(��j)
	Sprite *PL_Magic;				// ���@�g��(�c�C��)
	Sprite *PL_Healer;				// ��(����)
	// �����蔻��p
	Vec2 touchPos;					// ���݂̍��W
	Rect pl_rect;					// �v���C���[��Rect
	Rect box_rect;					// �`�[���Ґ��p
	Sprite *pl_square;				// �v���C���[�̃X�v���C�g
	Sprite *teamBox;				// �`�[���Ґ��p

	void update(float delta);		// �A�b�v�f�[�g
	void charaDraw();				// �L�����\��
	void fontsDraw();				// �����`��
	void charaText();				// ����������
	void Draw();					// �\��	
	void CharaSelectBackGroudn();	// �w�i
	void testChara();
	void objHit();					// �����蔻��p
	void arrange();					// �A�����W	
	void swipeRotation();			// �X���C�v�ɍ��킹�ĉ�]
					
	// touch�C�x���g
	bool TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);	// �������u��
	void TouchMove(cocos2d::Touch* touch, cocos2d::Event* event);	// �X���C�v��
	void TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);	// �������u��

	// �ۑ�����p�̃f�[�^
	static std::vector<CharaName> CharaData;
	// click����
	EventListenerTouchOneByOne *_listener = EventListenerTouchOneByOne::create();
	CCSprite *Box;
	CCSprite *Box1;
	unsigned int clickCnt = 0;	// �N���b�N�񐔂�ۑ�

	Sprite *Pl_BOX;

};

#endif // Title

/*
_listener->onTouchBegan = [&](Touch * touch, Event *event)
{
}
listener->onTouchMoved = [&](Touch *touch, Event *event)
{
	this->removeChildByTag(PL_TAG);
};
// ������
_listener->onTouchEnded = [&](Touch *touch, Event *event)
{
};
this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_listener, this);

*/