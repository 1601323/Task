#ifndef __Screen__TitleScene__
#define __Screen__TitleScene__

#include "cocos2d.h"

USING_NS_CC;

enum class SelectName
{
	SELECT_ATTACK,		// �U��
	SELECT_SHIELD,		// �h��
	SELECT_ITEM,		// �A�C�e��
	SELECT_SKILL,		// �X�L��
};

class TitleScene :public cocos2d::Layer
{
public:
	float angle;
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(TitleScene);
	std::vector<cocos2d::Node *> items;
	void TitleBackGroudn();
	// �I�����ꂽ�I�����i�[
	static const std::vector<SelectName>& GetSelectData();

	// �X�^�[�g�{�^���������̏����錾 �߂� Object ���@Ref �ɕύX
	void pushStart(Ref *pSender);

private:
	int nowSelect;					// ���ݑI�΂�Ă���ԍ�
	unsigned int _clickCnt = 0;		// �N���b�N�񐔂�ۑ�
	unsigned int _pushCnt  = 0;		// �������u�ԗp�J�E���g
	Node* Top;						// �őO�ɂ�����̂̏��
	// �s���p�^�[�����
	Sprite *_Attack;				// �U��
	Sprite *_Defence;				// �h��
	Sprite *_Item;					// �A�C�e��
	Sprite *_Skill;					// �X�L��

	// �����蔻��p
	Vec2 _touchPos;					// ���ݍ��W
	Rect _swipeRect;				// �X���C�v�p�̔���͈�
	Rect _clickButtunRect;			// �{�^���̃N���b�N����
	Sprite *_swipe;					// �X���C�v�p�X�v���C�g
	Sprite *_clickButton;			// �N���b�N�p�X�v���C�g
	Sprite *_ChoiceSkill;			// �I���X�L��

	void ActSelectDraw();						// �\��
	void Arrange(const Vec2 _pos);				// �p�x����
	void Arrange(const Vec2 _pos, std::vector<Node*>& _sprite, const int _upSideCnt, const int _drawCnt, const float _defaultScale, const float _diffScale, const GLubyte _defaultOpacity, const GLubyte _diffOpacity, const Vec2 _offset);										// (�z�u���W,�X�v���C�g,��ɕ\�����鐔,���\����,�ʏ�g�嗦,�g�嗦,�ʏ퓧��,����,X���ւ̍L����)
	void SwipeRotation();						// ��]
	void SwipeRotation(const float roleYDist);	// ��]
	void RectDraw(const unsigned int x, const unsigned int y, const unsigned int _width, const unsigned int _height, const int posX, const int posY);		// �l�p�`��p(X,Y,��,����,�z�u���W)
	void ObjHit();								// �����蔻��p
	void TouchArrange(Touch* _touch);			// �^�b�`�����Ƃ���G�t�F�N�g

	// touch�C�x���g
	bool TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);	// �������u��
	void TouchMove(cocos2d::Touch* touch, cocos2d::Event* event);	// �X���C�v��
	void TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);	// �������u��
	EventListenerTouchOneByOne *_listener = EventListenerTouchOneByOne::create();

	static std::vector<SelectName> SelectData;	// �ۑ�����p�̃f�[�^
};

#endif // Title

/*
#include "TitleScene.h"
#include "DiffSelectScene.h"
#include "CharaSelectScene.h"
#include "GameOver.h"
#include "TopScroll.h"
#include <algorithm>
#include "cocos2d.h"

const int DIV_NUM		 = 4;
const int DIV_CIRCLE	 = 360;
const int DIV_ANGLE		 = DIV_CIRCLE / DIV_NUM;
const int DIV_ANGLE_HALF = DIV_ANGLE / 2;

// �p�x����
const unsigned int RADIUS		   = 150;		// �~�̍L����
const float PI					   = 3.14159265359f;
const float FLATTEN_RATE		   = 0.1f;		// ���s
const unsigned int PL_POS_OFFSET_Y = 400;		// �v���C���[�\���̃I�t�Z�b�g
const unsigned int PL_POS_OFFSET_X = 600;		// �v���C���[�\���̃I�t�Z�b�g

// �g�啝
const float LIMIT_TIME			   = 0.9f;		// �b�w��[�߂��]
const float DOUBLE_SCALE		   = 0.5f;		// ���{��[�g�嗦�w��]
const float WAIT_TIME			   = 0.6f;		// �ҋ@����
const float BOX_SCALE			   = 0.9;		// �`�[���Ґ��p��BOX�̊g�嗦

const unsigned int BUTTON_POS_X	   = 50;		// �{�^���̔z�u���WX
const unsigned int BUTTON_POS_Y    = 1200;		// �{�^���̔z�u���WY

// �^�b�`��̃C�x���g�p
const float DELETE				   = 1.5f;		//
const unsigned int TOUCH_RADIUS    = 25;		//

// �A�����W�p
const Vec2 POS = Vec2(410, 650);	// �z�u���W
const int UPSIDECNT				= 3;						// ��ɕ\�������
const int DRAWCNT				= 6;						// �\�������(����)
const float DEFAULT_SCALE		= 1.f;						// �ʏ�g�嗦
const float DIFF_SCALE			= 0.15f;					// �g�嗦
const GLubyte DEFAULT_OPACITY	= 255;						// �ʏ�s�����x
const GLubyte DIFF_OPACITY		= 0;						// �s�����x
const Vec2 OFFSET				= Vec2(0, -100);			// �I�t�Z�b�g(���ւ̂Ђ낪�肩������)
const float ROLE_Y_DIST			= 80.f;						// ��]����ۂ̈ړ���(������傫������Ɨ]�v�ɓ���)



Scene *TitleScene::createScene()
{
	auto scene = Scene::create();
	auto layer = TitleScene::create();
	scene->addChild(layer);
	return scene;
}

// ������
bool TitleScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	// �o�b�N�O�����h
	TitleBackGroudn();

	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();

	// �{�^���z�u
	// �ʏ펞,��������
	// ���������̱����
	auto startButton = MenuItemImage::create("CloseNormal.png","CloseSelected.png", CC_CALLBACK_1(TitleScene::pushStart,this));

	// �{�^���̔z�u
	startButton->setPosition(BUTTON_POS_X, BUTTON_POS_Y);
	// ���j���[�쐬(����obj)
	auto menu = Menu::create(startButton,NULL);
	menu->setPosition(Point::ZERO);
	// �ǉ�
	this->addChild(menu,1);

	ActSelectDraw();		// �L�����\��
	SwipeRotation();		// �X���C�v�ɍ��킹�ĉ�]
	//Arrange(POS, items, UPSIDECNT, DRAWCNT, DEFAULT_SCALE, DIFF_SCALE, DEFAULT_OPACITY, DIFF_SCALE, OFFSET);
	Arrange();
	ObjHit();

	//RectDraw(0, 0, 280, 100, 410, 650);
	// touch�C�x���g
	auto touchEventGet = EventListenerTouchOneByOne::create();
	touchEventGet->onTouchBegan = CC_CALLBACK_2(TitleScene::TouchBegan, this);
	touchEventGet->onTouchMoved = CC_CALLBACK_2(TitleScene::TouchMove, this);
	touchEventGet->onTouchEnded = CC_CALLBACK_2(TitleScene::TouchEnd, this);

	// �o�^
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchEventGet, this);

	return true;
}

// �������u��
bool TitleScene::TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	TouchArrange(touch);
	_touchPos = touch->getLocation();
	if (_swipeRect.containsPoint(_touchPos))
	{
		_clickCnt += 1;
		if (_clickCnt > 1)
		{
			//Arrange(Vec2(800, PL_POS_OFFSET_Y), items, UPSIDECNT, DRAWCNT, DEFAULT_SCALE, DIFF_SCALE, DEFAULT_OPACITY, DIFF_SCALE, Vec2(0, -100));
		}
		//Arrange(Vec2(PL_POS_OFFSET_X, PL_POS_OFFSET_Y), items, UPSIDECNT, DRAWCNT, DEFAULT_SCALE, DIFF_SCALE, DEFAULT_OPACITY, DIFF_SCALE, Vec2(0, -100));
	}
	return true;
}

// �X���C�v��
void TitleScene::TouchMove(cocos2d::Touch* touch, cocos2d::Event* event)
{
	//TouchArrange(touch);
}

// �������u��
void TitleScene::TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event)
{
}

// �s���I��\��
void TitleScene::ActSelectDraw()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	_Attack  = Sprite::create("UI/Command/UI_Button_Attack01.png");
	_Defence = Sprite::create("UI/Command/UI_Button_Defence01.png");
	_Item	 = Sprite::create("UI/Command/UI_Button_Item01.png");
	_Skill	 = Sprite::create("UI/Command/UI_Button_Skill01.png");

	this->items.clear();
	this->items.push_back(_Attack);
	this->items.push_back(_Defence);
	this->items.push_back(_Item);
	this->items.push_back(_Skill);

	// �z�u
	for (auto& item :items)
	{
		this->addChild(item,0);
	}
	this->angle = 0.0f;
}

void TitleScene::Arrange()
{

	// �~��ɓ��Ԋu�Ŕz�u
	float theta = 360.0f / items.size() + (items.size() / 2);
	float baseAngle = this->angle + 270.0f;							// ���Z����Ɖ~�̉��s�������
	for (int i = 0; i < items.size(); i++)
	{
		// 270 �x�̈ʒu�����ʂɂ���悤��
		float angle = theta   * i + baseAngle;
		float radians = angle   * PI / 180.0f;
		float x = RADIUS  * cos(radians);
		float y = RADIUS  * sin(radians) * FLATTEN_RATE;	// �~�̊p�x�΂߂ɂ����
		float radiusY = RADIUS  * FLATTEN_RATE;
		float diameterY = radiusY * 2;
		float scale = (diameterY - y) / diameterY;				// y���W�ɉ����ĕω������
		GLubyte opacity = 255 - (y + radiusY);

		this->items.at(i)->setPosition(Vec2(x + PL_POS_OFFSET_X, y + PL_POS_OFFSET_Y + 20));
		this->items.at(i)->setScale(scale);
		this->items.at(i)->setOpacity(opacity);
		this->items.at(i)->setZOrder(diameterY - y);
	}
	//���[�Ƃ����(�L�E�ցE`)
	auto tmpVector = items;
	std::sort(tmpVector.begin(), tmpVector.end(), [](const Node* a, const Node* b)
		// ��ɑ傫����true /�@begin > end �����߂ɑ傫�����̗��遁�傫�����ɂȂ�
	{return a->getScale() > b->getScale(); });
	// TOP�Ɉ�ԑ������̂�����
	Top = tmpVector.front();
}
// �A�����W()
void TitleScene::Arrange(const Vec2 _pos, std::vector<Node*>& _sprite, const int _upSideCnt, const int _drawCnt, const float _defaultScale, const float _diffScale, const GLubyte _defaultOpacity, const GLubyte _diffOpacity, const Vec2 _offset)
{
	float tmp, tmp2;
	// �����l�𐮐������Ə��������ɕ�����
	auto tmpAngle = modf(angle, &tmp);
	tmpAngle = modf(tmpAngle, &tmp2);
	tmpAngle = -tmpAngle;
	// ������؂�̂Č^�L���X�g
	auto j = static_cast<int>(tmp) % _sprite.size();

	//
	for (int i= -_upSideCnt; i < _drawCnt - _upSideCnt; ++i)
	{
		// �������@% ������= ���݂̔ԍ��킩��
		auto index = ((i + j) + _sprite.size()) % _sprite.size();
		//
		_sprite[index]->setPosition(POS + Vec2(OFFSET.x * abs(i) , OFFSET.y * (i)));
		//
		//_sprite[index]->setScale(_defaultScale - (abs(i) * _diffScale));
		_sprite[index]->setScale(i == 0 ? _defaultScale : _defaultScale - _diffScale);
		//
		_sprite[index]->setOpacity(_defaultOpacity - (abs(i) * _diffOpacity));
		//
		_sprite[index]->setZOrder(_drawCnt - abs(i));
	}

	//���[�Ƃ����(�L�E�ցE`)
	auto tmpVector = _sprite;
	std::sort(tmpVector.begin(), tmpVector.end(), [](const Node* a, const Node* b)
	// ��ɑ傫����true /�@begin > end �����߂ɑ傫�����̗��遁�傫�����ɂȂ�
	{return a->getScale() > b->getScale(); });
	// TOP�Ɉ�ԑ������̂�����
	Top = tmpVector.front();


}

// �X���C�v(��]���x)
void TitleScene::SwipeRotation()
{
	// �X���C�v�ɍ��킹�ĉ�]
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	// �N���b�N�����Ƃ�
	listener->onTouchBegan = [](Touch *touch, Event *event) { return true; };
	// �ړ���[�X���C�v]
	listener->onTouchMoved = [](Touch *touch, Event *event)
	{
		float delta = touch->getLocation().y - touch->getPreviousLocation().y;
		angle += delta;
		//Arrange(POS, items, UPSIDECNT, DRAWCNT, DEFAULT_SCALE, DIFF_SCALE, DEFAULT_OPACITY, DIFF_SCALE, OFFSET);
		Arrange();
	};

	// ������
	listener->onTouchEnded = [](Touch *touch, Event *event)
	{
		this->angle = roundf(this->angle);
		//Arrange(POS, items, UPSIDECNT, DRAWCNT, DEFAULT_SCALE, DIFF_SCALE, DEFAULT_OPACITY, DIFF_SCALE, OFFSET);
		Arrange();
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

// �����蔻��p�͈�
void TitleScene::ObjHit()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();

	// �I����ʔ͈�
	_swipeRect = Rect(0, 0, 280, 100);
	_swipe = Sprite::create();
	_swipe->setTextureRect(_swipeRect);
	_swipe->setPosition(410, 650);

	_swipeRect = Rect(_swipe->getPosition().x - _swipe->getContentSize().width / 2,
					  _swipe->getPosition().y - _swipe->getContentSize().height / 2,
					  _swipe->getContentSize().width,
					  _swipe->getContentSize().height);
}

// �w�i
void TitleScene::TitleBackGroudn()
{
	// ��ʃT�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`���]�����[�V�����Ή����ǂ��Ƃ�
	Point origin = Director::getInstance()->getVisibleOrigin();

	// �^�C�g���z�u
	// �z�u����
	auto lbl_Title = Label::createWithSystemFont("Title","HiraKakuProN-W6",100);
	// �z�u�ꏊ
	lbl_Title->setPosition(Point(origin.x+winSize.width/2,
								 origin.y+winSize.height - lbl_Title->getContentSize().height));
	// Title�ǉ�
	this->addChild(lbl_Title,1);

	// �w�i�摜�ǉ�
	Sprite* bgsprite = Sprite::create("BackImage/ST_Boss.png");
	// �\�����W�w��
	bgsprite->setPosition(winSize.width/2, winSize.height/2);
	this->addChild(bgsprite,0);
}

// ��ʑJ��
void TitleScene::pushStart(Ref *pSender)
{
	// log�\��
	CCLOG("Push�{�^��");

	// �J�ڍ�̉�ʂ�ݽ�ݽ
	Scene *pScene = CharaSelectScene::createScene();

	// �͗l�����炾�񂾂�...
	Director::getInstance()->replaceScene(TransitionFadeTR::create(0.7f, CharaSelectScene::createScene()));
	CCDirector::sharedDirector()->replaceScene(CCTransitionFadeTR::create(2.0f, CharaSelectScene::createScene()));


}

// �l�p�`��
void TitleScene::RectDraw(const unsigned int x, const unsigned int y, const unsigned int _width, const unsigned int _height, const int posX, const int posY)
{
	Rect rect = Rect(x, y, _width, _height);
	Sprite *square = Sprite::create();
	square->setTextureRect(rect);
	square->setPosition(posX, posY);
	this->addChild(square, 5);
}

// �^�b�`�����Ƃ���G�t�F�N�g
void TitleScene::TouchArrange(Touch* _touch)
{
	// http://takachan.hatenablog.com/entry/2018/02/27/010443
	_touchPos = _touch->getLocation();
	// ��`�`��
	DrawNode* _circle = DrawNode::create();
	// drawDots(�`�������̒��S���W���܂ޔz��, ���a, �F);
	_circle->drawDot(Vec2::ZERO, TOUCH_RADIUS, Color4F(1.0f, 1.0f, 1.0f, 1.0f));
	// �z�u���W
	_circle->setPosition(_touchPos);

	Sprite *_effect = Sprite::create("effect_cure01_0001.png");
	_effect->setPosition(_touchPos);

	// �A�j���[�V�����ǉ�
	// �g�k
	ActionInterval* _scale = CCScaleTo::create(DELETE, 5.0f);
	// �t�F�C�h����
	ActionInterval* _fadeMove = CCScaleTo::create(DELETE, 0);
	// �����A�j���[�V���������Đ�
	Spawn* _spawn = CCSpawn::create(_scale, _fadeMove, nullptr);
	// 3�b�ҋ@
	auto _time = DelayTime::create(3);
	// �I��������������
	Sequence* seq = Sequence::create(_spawn, _time, nullptr);
	// ���s
	_effect->runAction(seq);
	// �ǉ�
	this->addChild(_effect, 10);
}
*/