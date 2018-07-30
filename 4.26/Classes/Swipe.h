#pragma once
#ifndef __Screen__SwipeScene__
#define __Screen__SwipeScene__

#include "cocos2d.h"


USING_NS_CC;

enum class SelectName
{
	SELECT_ATTACK,		// �U��
	SELECT_SHIELD,		// �h��
	SELECT_ITEM,		// �A�C�e��
	SELECT_SKILL,		// �X�L��
};

class Swipe :public cocos2d::Layer
{
public:
	float angle;
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(Swipe);
	std::vector<cocos2d::Node *> items;
	std::vector<cocos2d::Node *> selects;
	void TitleBackGroudn();
	// �I�����ꂽ�I�����i�[
	static const std::vector<SelectName>& GetSelectData();

	// �X�^�[�g�{�^���������̏����錾 �߂� Object ���@Ref �ɕύX
	void pushStart(Ref *pSender);

private:
	int nowSelect;					// ���ݑI�΂�Ă���ԍ�
	unsigned int _clickCnt = 0;		// �N���b�N�񐔂�ۑ�
	unsigned int _pushCnt = 0;		// �������u�ԗp�J�E���g
	bool flag;						// �؂�ւ��p��Flag
	Node* Top;						// �őO�ɂ�����̂̏��
									// �s���p�^�[�����
	Sprite *_s_Attack;				// �U��
	Sprite *_s_Defence;				// �h��
	Sprite *_s_Item;				// �A�C�e��
	Sprite *_s_Skill;				// �X�L��
	Sprite *_s_Top;					// �擪
	Sprite *_s_Belpw;				// ��
	Sprite *_s_Belpw1;				// ��
	Sprite *_s_Belpw2;				// ��
									// �����蔻��p
	Vec2 _touchPos;					// ���ݍ��W
	Rect _r_swipeRect;				// �X���C�v�p�̔���͈�
	Rect _r_clickButtunRect;		// �{�^���̃N���b�N����
	Sprite *_s_swipe;				// �X���C�v�p�X�v���C�g
	Sprite *_s_clickButton;			// �N���b�N�p�X�v���C�g
	Sprite *_s_ChoiceSkill;			// �I���X�L��
	Vec2 _pos;						// ���W

	void ActSelectDraw();						// �\��
	void SkillDraw();							// �X�L���\��
	void Arrange(const Vec2 _pos);				// �p�x����
	void Arrange(const Vec2 _pos, std::vector<Node*>& _sprite, const int _upSideCnt, const int _drawCnt, const float _defaultScale, const float _diffScale, const GLubyte _defaultOpacity, const GLubyte _diffOpacity, const Vec2 _offset);										// (�z�u���W,�X�v���C�g,��ɕ\�����鐔,���\����,�ʏ�g�嗦,�g�嗦,�ʏ퓧��,����,X���ւ̍L����)
	void SwipeRotation();						// ��]
	void SwipeRotation(const float roleYDist);	// ��]
	void RectDraw(const unsigned int x, const unsigned int y, const unsigned int _width, const unsigned int _height, const int posX, const int posY);		// �l�p�`��p(X,Y,��,����,�z�u���W)
	void ObjHit();								// �����蔻��p
	void TouchArrange(Touch* _touch);			// �^�b�`�����Ƃ���G�t�F�N�g
	void SelectMove();							// �I�����

	static std::vector<SelectName> SelectData;	// �ۑ�����p�̃f�[�^

												// touch�C�x���g
	bool TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);	// �������u��
	void TouchMove(cocos2d::Touch* touch, cocos2d::Event* event);	// �X���C�v��
	void TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);	// �������u��
	EventListenerTouchOneByOne *_listener = EventListenerTouchOneByOne::create();


	/*//////////
	///���\��///
	//////////*/
	void TestPLDraw();							// ���{�X

};

#endif // Swipe