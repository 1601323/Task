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
	Node* Top;
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

	void Update(float delta);		// �A�b�v�f�[�g
	void CharaDraw();				// �L�����\��
	void CharaText();				// ����������
	void TeamBoxDraw();				// �\��	
	void CharaSelectBackGroudn();	// �w�i
	void ObjHit();					// �����蔻��p
	void Arrange();					// �A�����W	
	void SwipeRotation();			// �X���C�v�ɍ��킹�ĉ�]
					
	// touch�C�x���g
	bool TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);	// �������u��
	void TouchMove(cocos2d::Touch* touch, cocos2d::Event* event);	// �X���C�v��
	void TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);	// �������u��

	//// �ۑ�����p�̃f�[�^
	static std::vector<CharaName> CharaData;
	// click����
	EventListenerTouchOneByOne *_listener = EventListenerTouchOneByOne::create();

	// ���ꂢ�ɕ��ׂȂ����Ă����Ă�
	CCSprite *_Box;
	unsigned int _clickCnt = 0;	// �N���b�N�񐔂�ۑ�

	Sprite *_Pl_BOX;
	SpriteBatchNode *_batchNode;

	void CharaSeveData();
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

/*
	// ������
	const unsigned int minCnt = 8;		// �ŏ�������
	const unsigned int maxCnt = 20;		// �ő吶����
										// ���s����	
	float minTime = 0.2f;
	float maxTime = 0.35;
	// ��ђ��˂鍂��
	float minHeight = 12.0f;
	float maxHeight = 22.0f;
	// �L���镝
	float minX = -18.0f;
	float maxX = 18.0;
	// �L���鍂��
	float minY = -14.0f;
	float maxY = 0;
	//Sprite *effect;

// �w�肵�����x�ŊJ�n
	void runEffect(Sprite *effect);
	// �A�j���[�V�������s
	void setStart(const float min,const float max);
	// ��ђ��˂鍂��
	void setJumpHeight(const float min,const float max);
	// �L����͈�X
	void setWidth(const float min,const float max);
	// �L����͈�Y
	void setHeight(const float min,const float max);
	// �Ō�Ɏ����폜
	void updateSelf();

void CharaSelectScene::runEffect(Sprite *effect)
{
int max = random(this->minTime,this->maxTime);
for (int i = 0; i < maxTime; i++)
{
effect = Sprite::create("effect_cure01_0000.png"); //"effect_cure01_0000.png"
float baseTime = random(minTime, maxTime);
float baseHeight = random(minHeight, maxHeight);
float baseVecX = random(minX, maxX);
float baseVecY = random(minY, maxY);

// ���񂾂�o�E���h������
// ���ԁA��(X,Y)�A�����A�v�f��
auto jump1 = JumpBy::create(baseTime,Vec2(baseVecX, baseVecY), baseHeight,1);
auto jump2 = JumpBy::create(baseTime*0.8, Vec2(baseVecX/2, baseVecY/2), baseHeight/2, 1);
auto jump3 = JumpBy::create(baseTime*0.6, Vec2(baseVecX/4, baseVecY/4), baseHeight/4, 1);

auto dele = DelayTime::create(1.0f);
auto lastFunc = CallFuncN::create([this](Node* node)
{
node->removeFromParentAndCleanup(true);
this->updateSelf();
});

effect->runAction(Sequence::create(jump1, jump2, jump3, dele,nullptr));

this->updateSelf();
}
}
//
void CharaSelectScene::updateSelf()
{
this->removeFromParentAndCleanup(true);
}
// �A�j���[�V�������s
void CharaSelectScene::setStart(float min, const float max)
{
this->minTime = min;
this->maxTime = max;
}
// ��ђ��˂鍂��
void CharaSelectScene::setJumpHeight(float min, const float max)
{
this->minHeight = min;
this->maxHeight = max;
}
// �L�����X
void CharaSelectScene::setWidth(float min, const float max)
{
this->minX = min;
this->maxX = max;
}
// �L�����Y
void CharaSelectScene::setHeight(float min, const float max)
{
this->minY = min;
this->maxY = max;
}
*/