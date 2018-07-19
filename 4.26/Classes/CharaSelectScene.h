#ifndef __Screen__CharaSelectScene__
#define __Screen__CharaSelectScene__
#include "cocos2d.h"
#include <Vector>
#include "Global.h"

USING_NS_CC;

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
	void backStart(Ref *pSender);
	// �I�����ꂽ�L�������i�[
	static const std::vector<CharaName>& GetCharaData();


private:
	unsigned int _clickCnt = 0;		// �N���b�N�񐔂�ۑ�
	bool _changeFlag;				// �L�����N�^�[�؂�ւ��pFlag
	Node* Top;
	Sprite *_fontBoard;				// �������̔w�i��
	SpriteBatchNode *_batchNode;
	// �L�������
	Sprite *_PL_Attacker;			// �����(���j)
	Sprite *_PL_Shield;				// ���(��j)
	Sprite *_PL_Magic;				// ���@�g��(�c�C��)
	Sprite *_PL_Healer;				// ��(����)
	// �����蔻��p
	Vec2 _touchPos;					// ���݂̍��W
	Rect _pl_rect;					// �v���C���[��Rect
	Rect _box_rect;					// �`�[���Ґ��p
	Rect _ok_rect;					// 
	Sprite *_pl_square;				// �v���C���[�̃X�v���C�g
	Sprite *_teamBox;				// �`�[���Ґ��p
	Sprite *_okButton;
	CCSprite *_Box;					// �`�[���p��Sprite

	void Update(float delta);		// �A�b�v�f�[�g
	void CharaDraw();				// �L�����\��
	void CharaText();				// �L����������
	void TeamBoxDraw();				// �\��	
	void CharaSelectBackGroudn();	// �w�i
	void ObjHit();					// �����蔻��p
	void Arrange();					// �A�����W	
	void SwipeRotation();			// �X���C�v�ɍ��킹�ĉ�]
	void AddTeam();					// �`�[���Ґ��p
	void CharaSeveData();
					
	// touch�C�x���g
	bool TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);	// �������u��
	void TouchMove(cocos2d::Touch* touch, cocos2d::Event* event);	// �X���C�v��
	void TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);	// �������u��

	//// �ۑ�����p�̃f�[�^
	static std::vector<CharaName> CharaData;
	// click����
	EventListenerTouchOneByOne *_listener = EventListenerTouchOneByOne::create();

	// ���ꂢ�ɕ��ׂȂ����Ă����Ă�
	// �e�X�g�p
};

#endif // Title