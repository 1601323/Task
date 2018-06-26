#ifndef __Screen__TitleScene__
#define __Screen__TitleScene__

#include "cocos2d.h"

USING_NS_CC;

class TitleScene :public cocos2d::Layer
{
public:
	float angle;
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(TitleScene);
	std::vector<cocos2d::Node *> items;
	void TitleBackGroudn();

	// �X�^�[�g�{�^���������̏����錾 �߂� Object ���@Ref �ɕύX
	void pushStart(Ref *pSender);

private:
	Node* Top;				// �őO�ɂ�����̂̏��
	// �s���p�^�[�����
	Sprite *_Attack;		// �U��
	Sprite *_Defence;		// �h��
	Sprite *_Item;			// �A�C�e��
	Sprite *_Skill;			// �X�L��

	// �X�L���I��
	Sprite *_ChoiceSkill;	// �I���X�L��
	void ActSelectDraw();	// �\��
	void Arrange();			// �p�x����
	void SwipeRotation();	// ��]

	void RectDraw(const unsigned int x, const unsigned int y, const unsigned int _width, const unsigned int _height, const int posX, const int posY);

	// touch�C�x���g
	bool TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);	// �������u��
	void TouchMove(cocos2d::Touch* touch, cocos2d::Event* event);	// �X���C�v��
	void TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);	// �������u��
	EventListenerTouchOneByOne *_listener = EventListenerTouchOneByOne::create();
};

#endif // Title