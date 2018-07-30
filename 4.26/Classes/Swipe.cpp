#include "Swipe.h"
#include "CharaSelectScene.h"
#include <algorithm>
#include "cocos2d.h"

#pragma execution_character_set("utf-8")

const int DIV_NUM = 4;
const int DIV_CIRCLE = 360;
const int DIV_ANGLE = DIV_CIRCLE / DIV_NUM;
const int DIV_ANGLE_HALF = DIV_ANGLE / 2;

// �p�x����
const unsigned int RADIUS = 150;				// �~�̍L����
const float PI = 3.14159265359f;
const float FLATTEN_RATE = 0.1f;				// ���s
const unsigned int PL_POS_OFFSET_Y = 400;		// �v���C���[�\���̃I�t�Z�b�g
const unsigned int PL_POS_OFFSET_X = 600;		// �v���C���[�\���̃I�t�Z�b�g
// �g�啝
const float LIMIT_TIME = 0.9f;				// �b�w��[�߂��]
const float DOUBLE_SCALE = 0.5f;				// ���{��[�g�嗦�w��]
const float WAIT_TIME = 0.6f;				// �ҋ@����
const float BOX_SCALE = 0.9;				// �`�[���Ґ��p��BOX�̊g�嗦

const unsigned int BUTTON_POS_X = 50;				// �{�^���̔z�u���WX
const unsigned int BUTTON_POS_Y = 1200;				// �{�^���̔z�u���WY

													// �^�b�`��̃C�x���g�p
const float DELETE = 1.5f;
const unsigned int TOUCH_RADIUS = 25;

// �A�����W�p
const int SCALE = 5;					// ����(���W)�p�̃X�P�[��
const int UPSIDECNT = 3;					// ��ɕ\�������
const int DRAWCNT = 6;					// �\�������(����)
const float DEFAULT_SCALE = 1.f;					// �ʏ�g�嗦
const float DIFF_SCALE = 0.15;					// �g�嗦0.15
const float ROLE_Y_DIST = 0.05f;				// ��]����ۂ̈ړ���(������傫������Ɨ]�v�ɓ���)
const GLubyte DEFAULT_OPACITY = 255;					// �ʏ�s�����x			
const GLubyte DIFF_OPACITY = 0;					// �s�����x
const Vec2 POS = Vec2(600, 650);		// �z�u���W410�A650
const Vec2 OFFSET = Vec2(0, -100);		// �I�t�Z�b�g(���ւ̂Ђ낪�肩������)

										// ���S
const Vec2 POS2 = Vec2(410, 650);		// �z�u���W410�A650
const Vec2 POS3 = Vec2(5, 650);		// click�㏉�߂̕�_�z�u���W410�A650�@
const Vec2 POS4 = Vec2(40, 650);		// �ύX��̍��W
const Vec2 POSKILL = Vec2(490, 550);		// �z�u���W410�A650		�X�L���p�̂��


											// ���Ԑ���
std::vector<SelectName> Swipe::SelectData;

Scene *Swipe::createScene()
{
	auto scene = Scene::create();
	auto layer = Swipe::create();
	scene->addChild(layer);
	return scene;
}

// ������
bool Swipe::init()
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
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(Swipe::pushStart, this));

	// �{�^���̔z�u
	startButton->setPosition(BUTTON_POS_X, BUTTON_POS_Y);
	// ���j���[�쐬(����obj)
	auto menu = Menu::create(startButton, NULL);
	menu->setPosition(Point::ZERO);
	// �ǉ�
	this->addChild(menu, 1);

	flag = false;

	TestPLDraw();			// ���{�X�\��(��ŏ����Ă����Ă�)
	ActSelectDraw();		// �L�����\��
	SwipeRotation();		// �X���C�v�ɍ��킹�ĉ�]
	ObjHit();				// �����蔻��p
	Arrange(POS2);

	// touch�C�x���g
	auto touchEventGet = EventListenerTouchOneByOne::create();
	touchEventGet->onTouchBegan = CC_CALLBACK_2(Swipe::TouchBegan, this);
	touchEventGet->onTouchMoved = CC_CALLBACK_2(Swipe::TouchMove, this);
	touchEventGet->onTouchEnded = CC_CALLBACK_2(Swipe::TouchEnd, this);

	// �o�^
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchEventGet, this);



	return true;
}

// ���{�X�\��
void Swipe::TestPLDraw()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();

	Sprite *Boss = Sprite::create("Enemy/EM_Valkyrie.png");
	Boss->setPosition(winSize.width / 2, winSize.height / 2 + 100
	);
	addChild(Boss, 2);
}

// �������u��
bool Swipe::TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	_touchPos = touch->getLocation();
	TouchArrange(touch);

	_pushCnt++;

	//if (_clickButtunRect.containsPoint(_touchPos))
	{
		// �{�^�����N���b�N���ꂽ��I�����ɂ���ĕς��
		if (_pushCnt>1)
		{
			int i = 0;
			for (i = 0; i<selects.size(); i++)
			{
				if (selects[i] != Top)
				{
					break;
				}
				// �ǉ�
				SelectData.push_back(static_cast<SelectName> (i));
			}
			_pushCnt = 0;
		}
	}
	return true;
}

// �X���C�v��
void Swipe::TouchMove(cocos2d::Touch* touch, cocos2d::Event* event)
{
}

// �������u��
void Swipe::TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event)
{
	_touchPos = touch->getLocation();

	_clickCnt++;

	if (_clickCnt>2)
	{
		if (_r_clickButtunRect.containsPoint(_touchPos))
		{
			SelectMove();		// ���I��������

								// Arrange1�̍��W��POS3�̍��W�ɕύX
								// Arrange2�̕\��
								// Arrange1�̃X���C�v��؂�
		}
		_clickCnt = 0;
	}
}

// �s���I��\��
void Swipe::ActSelectDraw()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	_s_Attack = Sprite::create("UI/Command/UI_Button_Attack01.png");
	_s_Defence = Sprite::create("UI/Command/UI_Button_Defence01.png");
	_s_Item = Sprite::create("UI/Command/UI_Button_Item01.png");
	_s_Skill = Sprite::create("UI/Command/UI_Button_Skill01.png");

	this->items.clear();
	this->items.push_back(_s_Attack);
	this->items.push_back(_s_Defence);
	this->items.push_back(_s_Item);
	this->items.push_back(_s_Skill);

	// �z�u
	for (auto& item : items)
	{
		this->addChild(item, 0);
	}
	this->angle = 0.0f;
}

// �X�L���\��
void Swipe::SkillDraw()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	_s_Top = Sprite::create("UI/Status/UI_Button_Choice01.png");
	_s_Belpw = Sprite::create("UI/Status/UI_Button_Wait01.png");
	_s_Belpw1 = Sprite::create("UI/Status/UI_Button_Wait01.png");
	_s_Belpw2 = Sprite::create("UI/Status/UI_Button_Wait01.png");

	this->selects.clear();
	this->selects.push_back(_s_Top);
	this->selects.push_back(_s_Belpw);
	this->selects.push_back(_s_Belpw1);
	this->selects.push_back(_s_Belpw2);

	// �z�u
	for (auto& item : selects)
	{
		this->addChild(item, 0);
	}
	this->angle = 0.0f;
}

// �I�����
void Swipe::SelectMove()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();

	// �U��
	if (Top == _s_Attack)
	{
		log("�U��");
		flag = false;
	}
	// �h��
	else if (Top == _s_Defence)
	{
		log("�h��");
		flag = false;
	}
	// �A�C�e��
	else if (Top == _s_Item)
	{
		log("�A�C�e��");
		flag = false;
	}
	// 
	else if (Top == _s_Skill)
	{
		flag = true;
		SkillDraw();		// �X�L���ꗗ�\��
		SwipeRotation(ROLE_Y_DIST);
		Arrange(POSKILL, selects, UPSIDECNT, DRAWCNT, DEFAULT_SCALE, DIFF_SCALE, DEFAULT_OPACITY, DIFF_SCALE, OFFSET);
		log("�X�L���ꗗ�\�����܂�");
	}
	// �����Ȃ�
	else
	{
		log("�װ�N���Ă��܂���");
	}
}

// �A�����W1(�z�u���W)
void Swipe::Arrange(const Vec2 _pos)
{	// �c�ɉ��悤�Ȃ�
	float theta = 360.0f / items.size() + (items.size() / 2);
	float baseAngle = this->angle;									// ���Z����Ɖ~�̉��s�������

	for (int i = 0; i < items.size(); i++)
	{
		// 270 �x�̈ʒu�����ʂɂ���悤��  
		float angle = theta   * i + baseAngle;
		float radians = angle   * PI / 180.0;
		float x = RADIUS  * cos(radians);
		float y = RADIUS  * sin(radians) * FLATTEN_RATE;	// �~�̊p�x�΂߂ɂ����
		float radiusY = RADIUS  * FLATTEN_RATE;
		float diameterY = radiusY * 2;
		float scale = (diameterY - y - SCALE) / diameterY;		// y���W�ɉ����ĕω������
		GLubyte opacity = 255 - (y + radiusY);

		this->items.at(i)->setPosition(Vec2(_pos.x, _pos.y + x));	// �z�u���W
		this->items.at(i)->setScale(scale);							// �g�嗦
		this->items.at(i)->setOpacity(opacity);						// �s�����x
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

// �A�����W2(�z�u���W,�g�嗦,��]�p�x,�S�̌�,�\����)
void Swipe::Arrange(const Vec2 _pos, std::vector<Node*>& _sprite, const int _upSideCnt, const int _drawCnt, const float _defaultScale, const float _diffScale, const GLubyte _defaultOpacity, const GLubyte _diffOpacity, const Vec2 _offset)
{
	float tmp, tmp2;
	// �����l�𐮐������Ə��������ɕ�����
	auto tmpAngle = modf(angle, &tmp);
	tmpAngle = modf(tmpAngle, &tmp2);
	tmpAngle = -tmpAngle;
	// ������؂�̂Č^�L���X�g
	auto j = static_cast<int>(tmp) % _sprite.size();
	// 
	for (int i = -_upSideCnt; i < _drawCnt - _upSideCnt; ++i)
	{
		// �������@% ������= ���݂̔ԍ��킩��
		auto index = ((i + j) + _sprite.size()) % _sprite.size();
		// _pos[�\���������ʒu] + �I�t�Z�b�g�@*�@��Βl(-2~2) ���������邱�Ƃ�2,1,0,1,2�Ƃ������ɕ���,y���W��-2-1,1,2�Ƃ������ɂȂ�
		_sprite[index]->setPosition(_pos + Vec2(OFFSET.x * abs(i), OFFSET.y * (i)));
		// ���ʂɗ����ꍇ�̂ݎw�肵���g�廲�ނɂȂ�,���̑��͏������Ȃ�
		//_sprite[index]->setScale(_defaultScale - (abs(i) * _diffScale));
		_sprite[index]->setScale(i == 0 ? _defaultScale : _defaultScale - _diffScale);
		// �s�����x
		_sprite[index]->setOpacity(_defaultOpacity - (abs(i) * _diffOpacity));
		// ���s�@�\���������� - ��
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

// �X���C�v
void Swipe::SwipeRotation()
{
	// �X���C�v�ɍ��킹�ĉ�]
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	// �N���b�N�����Ƃ�
	listener->onTouchBegan = [](Touch *touch, Event *event)
	{	return true; };
	// �ړ���[�X���C�v]
	listener->onTouchMoved = [&](Touch *touch, Event *event)
	{
		// �X�L�����I������Ă��Ȃ��ꍇ
		if (flag == false)
		{
			if (_r_swipeRect.containsPoint(_touchPos))
			{
				float delta = touch->getLocation().y - touch->getPreviousLocation().y;
				this->angle += delta;
				Arrange(POS2);
			}
		}
		// �X�L�����I������Ă���ꍇ
		else
		{
			//Arrange(POS4);
		}

	};
	// ������
	listener->onTouchEnded = [&](Touch *touch, Event *event)
	{
		// ���̒l
		if (angle > 0.f)
		{
			this->angle = (((((static_cast<int>(this->angle)) + DIV_ANGLE_HALF) % 360) / DIV_ANGLE) * DIV_ANGLE);
		}
		// ���̒l
		else
		{
			this->angle = ((((static_cast<int>(this->angle - 360) % 360 - DIV_ANGLE_HALF) % 360) / DIV_ANGLE) * DIV_ANGLE);
		}
		if (flag == false)
		{
			Arrange(POS2);
		}
		else
		{
			Arrange(POS4);
		}
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

// �X���C�v(��]����ۂ̈ړ���(������傫������Ɨ]�v�ɓ���))
void Swipe::SwipeRotation(const float roleYDist)
{
	// �X���C�v�ɍ��킹�ĉ�]
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	// �N���b�N�����Ƃ�
	listener->onTouchBegan = [](Touch *touch, Event *event) { return true; };
	// �ړ���[�X���C�v]
	listener->onTouchMoved = [&, roleYDist](Touch *touch, Event *event)
	{
		float delta = touch->getLocation().y - touch->getPreviousLocation().y;
		this->angle += delta / roleYDist;
		if (flag == true)
		{
			Arrange(POS, selects, UPSIDECNT, DRAWCNT, DEFAULT_SCALE, DIFF_SCALE, DEFAULT_OPACITY, DIFF_SCALE, OFFSET);
		}

	};

	// ������
	listener->onTouchEnded = [&, roleYDist](Touch *touch, Event *event)
	{
		this->angle = roundf(this->angle);
		if (flag == true)
		{
			Arrange(POS, selects, UPSIDECNT, DRAWCNT, DEFAULT_SCALE, DIFF_SCALE, DEFAULT_OPACITY, DIFF_SCALE, OFFSET);
		}
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

// �����蔻��p�͈�
void Swipe::ObjHit()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();

	// �X���C�v�͈̔�
	_r_swipeRect = Rect(0, 0, 550, 490);
	_s_swipe = Sprite::create();
	_s_swipe->setTextureRect(_r_swipeRect);
	_s_swipe->setPosition(winSize.width / 2 - 10, winSize.height / 2 - 30);

	_r_swipeRect = Rect(_s_swipe->getPosition().x - _s_swipe->getContentSize().width / 2,
		_s_swipe->getPosition().y - _s_swipe->getContentSize().height / 2,
		_s_swipe->getContentSize().width,
		_s_swipe->getContentSize().height);

	// �{�^����click�p
	_r_clickButtunRect = Rect(0, 0, 490, 180);
	_s_clickButton = Sprite::create();
	_s_clickButton->setTextureRect(_r_clickButtunRect);
	_s_clickButton->setPosition(winSize.width / 2 - 10, winSize.height / 2 - 30);

	_r_clickButtunRect = Rect(_s_clickButton->getPosition().x - _s_clickButton->getContentSize().width / 2,
		_s_clickButton->getPosition().y - _s_clickButton->getContentSize().height / 2,
		_s_clickButton->getContentSize().width,
		_s_clickButton->getContentSize().height);

	// �X�L���̃{�^���p

}

// �w�i
void Swipe::TitleBackGroudn()
{
	// ��ʃT�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// �^�C�g���z�u
	// �z�u����
	auto lbl_Title = Label::createWithSystemFont("Title", "HiraKakuProN-W6", 100);
	lbl_Title->setPosition(Point(origin.x + winSize.width / 2,
		origin.y + winSize.height - lbl_Title->getContentSize().height));
	// Title�ǉ�
	this->addChild(lbl_Title, 1);

	// �w�i�摜�ǉ�
	Sprite* bgsprite = Sprite::create("BackImage/ST_Boss.png");
	bgsprite->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(bgsprite, 0);
}

const std::vector<SelectName>& Swipe::GetSelectData()
{
	return SelectData;
}

// ��ʑJ��
void Swipe::pushStart(Ref *pSender)
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
void Swipe::RectDraw(const unsigned int x, const unsigned int y, const unsigned int _width, const unsigned int _height, const int posX, const int posY)
{
	Rect rect = Rect(x, y, _width, _height);
	Sprite *square = Sprite::create();
	square->setTextureRect(rect);
	square->setPosition(posX, posY);
	this->addChild(square, 5);
}

// �^�b�`�����Ƃ���G�t�F�N�g
void Swipe::TouchArrange(Touch* _touch)
{
	// http://takachan.hatenablog.com/entry/2018/02/27/010443
	_touchPos = _touch->getLocation();
	// ��`�`��
	DrawNode* _circle = DrawNode::create();
	// drawDots(�`�������̒��S���W���܂ޔz��, ���a, �F);
	_circle->drawDot(Vec2::ZERO, TOUCH_RADIUS, Color4F(1.0f, 1.0f, 1.0f, 1.0f));
	// �z�u���W
	_circle->setPosition(_touchPos);

	Sprite *_effect = Sprite::create("Touch/effect_cure01_0001.png");
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
	_effect->runAction(seq);
	this->addChild(_effect, 10);
}