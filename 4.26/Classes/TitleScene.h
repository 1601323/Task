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
	// �����蔻��p
	Vec2 _touchPos;			// ���ݍ��W
	Rect _swipeRect;		// �X���C�v�p�̔���͈�
	Sprite *_swipe;
	// �X�L���I��
	Sprite *_ChoiceSkill;	// �I���X�L��
	void ActSelectDraw();	// �\��
	void Arrange();			// �p�x����
	void SwipeRotation();	// ��]
	void ObjHit();			// �����蔻��p
	void RectDraw(const unsigned int x, const unsigned int y, const unsigned int _width, const unsigned int _height, const int posX, const int posY);
	void TouchArrange(Touch* _touch);		// �^�b�`�����Ƃ���G�t�F�N�g

	// touch�C�x���g
	bool TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);	// �������u��
	void TouchMove(cocos2d::Touch* touch, cocos2d::Event* event);	// �X���C�v��
	void TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);	// �������u��
	EventListenerTouchOneByOne *_listener = EventListenerTouchOneByOne::create();
};

#endif // Title