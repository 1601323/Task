#include "CharaSelectScene.h"
#include "FightScene.h"
#include "GameOver.h"
#include "TitleScene.h"
#include "Global.h"
#include "Imput.h"
#include <algorithm>
#include "cocos2d.h"

#pragma execution_character_set("utf-8")

const int DIV_NUM		  = 4;
const int DIV_ANGLE		  = 360 / DIV_NUM;
const int DIV_ANGLE_HALF  = DIV_ANGLE / 2;

const unsigned int PL_TAG		  = 101;		// �^�O�p
const unsigned int TEXT_OFFSET    = 510;		// text�\���̃I�t�Z�b�g�l

const unsigned int NEXT_BUTTON_X  = 660;		// ���̉�ʑJ�ڂւ̃{�^���̔z�u���WX
const unsigned int NEXT_BUTTON_Y  = 65;			// ���̉�ʑJ�ڂւ̃{�^���̔z�u���WY

const unsigned int FONT_SIZE	  = 38;			// �v���C���[�������p�̕�������
const unsigned int PL_TEXT_RECT_X = 250;		// �v���C���[�p�̔̔z�u�ʒuX
const unsigned int PL_TEXT_RECT_Y = 750;		// �v���C���[�p�̔̔z�u�ʒuY
const unsigned int TEAM_BOX_X	  = 165;		// �`�[���Ґ��p��box�̔z�u�ʊJX
const unsigned int TEAM_BOX_Y	  = 180;		// �`�[���Ґ��p��box�̔z�u�ʒuY
const unsigned int TEAM_BOX_OFFSET_X = 225;		// �`�[���Ґ��p��box�̃I�t�Z�b�g

// �p�x�֌W�Ŏg����
const int RADIUS		  = 200;
const float PI			  = 3.14159265359f;
const float FLATTEN_RATE  = 0.4f;
const unsigned int PL_POS_OFFSET_X = 420;		// �v���C���[�\���̃I�t�Z�b�g
const unsigned int PL_POS_OFFSET_Y = 820;		// �v���C���[�\���̃I�t�Z�b�g
// �g�k�p
const float LIMIT_TIME	  = 0.9f;				// �b�w��[�߂��]
const float DOUBLE_SCALE  = 0.5f;				// ���{��[�g�嗦�w��]
const float WAIT_TIME	  = 0.6f;				// �ҋ@����
const float BOX_SCALE	  = 1.2;				// �`�[���Ґ��p��BOX�̊g�嗦

USING_NS_CC;

// ���ԍ���
std::vector<CharaName> CharaSelectScene::CharaData;

Scene *CharaSelectScene::createScene()
{
	auto scene = Scene::create();
	auto layer = CharaSelectScene::create();
	scene->addChild(layer);
	return scene;
}

// ������
bool CharaSelectScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	// �o�b�N�O�����h
	CharaSelectBackGroudn();
	// �{�^���z�u (�ʏ펞,��������,���������̱����)
	auto _buttunNext = MenuItemImage::create("UI/Command/UI_Button_Next.png", "UI/Command/UI_Button_Next.png", CC_CALLBACK_1(CharaSelectScene::pushStart, this));
	_buttunNext->setPosition(NEXT_BUTTON_X+30, NEXT_BUTTON_Y);		// ���W�w��
	_buttunNext->setScale(0.5);										// �傫������

	auto menu1 = Menu::create(_buttunNext, NULL);					// ���j���[�쐬(����obj)
	menu1->setPosition(Point::ZERO);								// ���W�z�u
	this->addChild(menu1, 8);										// �ǉ�

	auto _buttunBack = MenuItemImage::create("UI/Command/UI_Button_Back.png", "UI/Command/UI_Button_Back.png", CC_CALLBACK_1(CharaSelectScene::backStart, this));
	_buttunBack->setPosition(NEXT_BUTTON_X - 550, NEXT_BUTTON_Y);	// ���W�w��
	_buttunBack->setScale(0.5);										// �傫������	

	auto menu2 = Menu::create(_buttunBack, NULL);					// ���j���[�쐬(����obj)
	menu2->setPosition(Point::ZERO);								// ���W�z�u
	this->addChild(menu2, 8);										// �ǉ�

	// touch�C�x���g
	auto touchEventGet = EventListenerTouchOneByOne::create();
	touchEventGet->onTouchBegan = CC_CALLBACK_2(CharaSelectScene::TouchBegan, this);
	touchEventGet->onTouchMoved = CC_CALLBACK_2(CharaSelectScene::TouchMove, this);
	touchEventGet->onTouchEnded = CC_CALLBACK_2(CharaSelectScene::TouchEnd, this);
	// �o�^
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchEventGet, this);

	TeamBoxDraw();			// �\��(�L�����ȊO)
	CharaDraw();			// �L�����\��
	SwipeRotation();		// �X���C�v�ɍ��킹�ĉ�]
	ObjHit();				// �����蔻��

	this->scheduleUpdate();	// �X�V	

	CharaData.reserve(3);	// ���O�ɗ̈�m��[�`�[���Ґ��p]

	// �_���[�W�\���̂��
	/*srand((unsigned int)time(nullptr));

	auto listner = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [this](Touch* touch, Event* event)
	{
		DmEffect* effect = DmEffect::create();
		effect->setPosition(Vec2(touch->getLocation().x + 30 ,touch->getLocation().y));
		effect->showEffect(rand() % 9999);
		this->addChild(effect);

		return true;
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listner, this);*/

	return true;
}

// �������u��
bool CharaSelectScene::TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	_touchPos = touch->getLocation();

	return true;
}
// �X���C�v��
void CharaSelectScene::TouchMove(cocos2d::Touch* touch, cocos2d::Event* event)
{
	this->removeChildByTag(PL_TAG);
	// �����Ă���Ƃ��̓J�E���g���Ȃ�
	_clickCnt = 0;
}
// �������u��
void CharaSelectScene::TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event)
{
	_touchPos = touch->getLocation();

	//�w��Rect�����N���b�N������������\��
	if (_pl_rect.containsPoint(_touchPos))
	{
		_clickCnt += 1;
		if (_clickCnt > 1)
		{
			CharaText();	// �L����������
		}
		if (_clickCnt > 2)
		{
			log("�`�[�����Ґ����ꂽ��");
			_clickCnt = 1;
			int i = 0;
			for (i = 0; i < items.size(); i++)
			{
				if (items[i] != Top)
				{
					continue;
				}

				// ��O����[�v�f�ȏ�̏ꍇ]
				// �͈͓��̏ꍇ
				// �ǉ�
				//if (CharaData.size== 3)
				{
					//break;
					log("�����c����",CharaData);
				}
				CharaData.push_back(static_cast<CharaName> (i));
				log("�ǉ����܂�����%d", i);
	
			}
		}
	}

	//// �`�[���Ґ��̔����N���b�N�����Ƃ�[���͈�]
	//if (_box_rect.containsPoint(_touchPos))
	//{
	//	// �`�[���Ґ��L�����Z��
	//	//if (_clickCnt > 2)
	//	{
	//		log("�����o�[�Ґ������������叫!!");
	//		// No.4 click���ꂽ�L������CharaData�������
	//		// ����(��)�l�߂�
	//	}
	//}
}

// �`�[���Ґ��\��
void CharaSelectScene::CharaSeveData()
{
	// CahraData�̓ǂݎ��
	
}

// �X�V
void CharaSelectScene::Update(float delta)
{
}

// �L�����\��
void CharaSelectScene::CharaDraw()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	_PL_Attacker = Sprite::create("Player/PL_Attacker.png");
	_PL_Shield   = Sprite::create("Player/PL_Shield.png");
	_PL_Magic    = Sprite::create("Player/PL_Magic.png");
	_PL_Healer   = Sprite::create("Player/PL_Healer.png");

	this->items.clear();
	this->items.push_back(_PL_Attacker);
	this->items.push_back(_PL_Shield);
	this->items.push_back(_PL_Magic);
	this->items.push_back(_PL_Healer);
	//this->items.clear();
	//this->items.push_back(Sprite::create("PL_Attacker.png"));
	//this->items.push_back(Sprite::create("PL_Shield.png"));
	//this->items.push_back(Sprite::create("PL_Magic.png"));
	//this->items.push_back(Sprite::create("PL_Healer.png"));

	// �I������ĂȂ����̔�������
	if (!Top)
	{
		////�����l�p�`�X�v���C�g
		Sprite* shadowSprite = Sprite::create();
		shadowSprite->setTextureRect(Rect(0.0f, 0.0f, winSize.width, winSize.height));
		shadowSprite->setColor(Color3B::BLACK);
		shadowSprite->setOpacity(200);
		shadowSprite->setPosition(Point(winSize.width / 2, winSize.height / 2));
	}

	// �~��ɓ��Ԋu�Ŕz�u
	for (auto& item : items)
	{
		this->addChild(item, 0);
	}
	this->angle = 0.0f;
	this->Arrange();
}

// �v���C���[������
void CharaSelectScene::CharaText()
{
	// �ǉ��Ńv���C���[�̖������ǉ����Ăق�����
	// Label��2�Ł@1�̓L�����̐�����,1�̓L�������\���p

	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();
	// �t�H���g�w��
	TTFConfig ttfConfig("fonts/HGRSGU.TTC", FONT_SIZE);
	// �F�w��
	auto textColor = Color3B(0,0,50);
	// �e�L�X�g
	auto label1 = Label::createWithTTF(ttfConfig,
		"����{�ő��ʂȍU��\n�h����̂ĂĂł��Η͂��Ƃ�\n���n�̌��m");
	auto label2 = Label::createWithTTF(ttfConfig,
		"���@�Ő����������Ō��������\n������_���[�W���󂯂邪\n���Ԃ����B�ꖳ��̏�");
	auto label3 = Label::createWithTTF(ttfConfig,
		"���@�U���œG���U��������悵\n�������������ăT�|�[�g���Ă��悵\n��̊�����}�W�V����");
	auto label4 = Label::createWithTTF(ttfConfig,
		"�񕜂̃X�y�V�����X�g�Ǝv������\n�G�̎�̉������C��\n�f�o�t�n�q�[���[");
	
	// �A�^�b�J�[
	if (Top == _PL_Attacker)
	{
		this->removeChildByTag(PL_TAG);
		// �^�O�ݒ�
		label1->setTag(PL_TAG);
		label1->setColor(textColor);
		// ���W�ݒ�
		label1->setPosition(winSize.width / 2, winSize.height / 2 + TEXT_OFFSET);
		// �^�O�`�F�b�N
		if (int tag = label1->getTag() != 1)
		{
			this->addChild(label1, 6);
		}
	}
	// �V�[���h
	else if (Top == _PL_Shield)
	{
		this->removeChildByTag(PL_TAG);
		// �^�O�ݒ�
		label2->setTag(PL_TAG);
		// �F�ݒ�
		label2->setColor(textColor);
		// ���W�ݒ�
		label2->setPosition(winSize.width / 2, winSize.height / 2 + TEXT_OFFSET);
		// �^�O�`�F�b�N
		if (int tag = label2->getTag() != 1)
		{
			this->addChild(label2, 6);
		}
	}
	// ���@
	else if (Top == _PL_Magic)
	{
		this->removeChildByTag(PL_TAG);
		// �^�O�ݒ�
		label3->setTag(PL_TAG);
		// �F�ݒ�
		label3->setColor(textColor);
		// ���W�ݒ�
		label3->setPosition(winSize.width / 2, winSize.height / 2 + TEXT_OFFSET);
		// �^�O�`�F�b�N
		if (int tag = label3->getTag() != 1)
		{
			this->addChild(label3, 6);
		}

	}
	// ��
	else if (Top == _PL_Healer)
	{
		this->removeChildByTag(PL_TAG);
		// �^�O�ݒ�
		label4->setTag(PL_TAG);
		// �F�ݒ�
		label4->setColor(textColor);
		// ���W�ݒ�
		label4->setPosition(winSize.width / 2, winSize.height / 2 + TEXT_OFFSET);
		// �^�O�`�F�b�N
		if (int tag = label4->getTag() != 1)
		{
			this->addChild(label4, 6);
		}
	}
	else
	{
		log("�װ�N���Ă܂���");
	}
}

// �\�� �`�[���Ґ��̔�
void CharaSelectScene::TeamBoxDraw()
{
	_batchNode = SpriteBatchNode::create("PL_CharFlame01.png");
	_batchNode->setPosition(TEAM_BOX_OFFSET_X, 0);

	// �`�[���Ґ���Box���\��
	for (int n = 0; n<3; n++) 
	{
		//batchNode����e�N�X�`�����擾
		_Box = Sprite::createWithTexture(_batchNode->getTexture());
		_Box->setScale(BOX_SCALE);
		
		//�ʒu�ɐݒ�
		_Box->setPosition((TEAM_BOX_X+16)*n, (TEAM_BOX_Y));

		//SpriteBatchNode�ɓ\��t����
		_batchNode->addChild(_Box);
	}
	//�ꊇ�\��t��
	this->addChild(_batchNode);
}

// �w�i
void CharaSelectScene::CharaSelectBackGroudn()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	// �������̔z�u
	Sprite *_fontBoard = Sprite::create("UI/Status/UI_Status_Inters.png");
	// �z�u
	_fontBoard->setPosition(winSize.width / 2, 1130);
	this->addChild(_fontBoard, 1);

	// �w�i�摜�ǉ�
	Sprite* _backImage = Sprite::create("BackImage/ST_CharSerect2.png");
	// �z�u���W
	_backImage->setPosition(winSize.width / 2, winSize.height / 2);
	// �ǉ�
	this->addChild(_backImage,0);
}

// �����蔻��p
void CharaSelectScene::ObjHit()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();

	// �v���C���[�p�̃N���b�N����p��
	_pl_rect   = Rect(0, 0, PL_TEXT_RECT_X, PL_TEXT_RECT_Y);	// �͈�
	_pl_square = Sprite::create();								// ����
	_pl_square->setTextureRect(_pl_rect);						// �e�N�X�`���w��
	_pl_square->setPosition(430, winSize.height / 2);			// ���W�z�u
	//this->addChild(pl_square);								// �ǉ�

	// �v���C���[�N���b�N����͈�
	_pl_rect = Rect(_pl_square->getPosition().x - _pl_square->getContentSize().width /  2,
				    _pl_square->getPosition().y - _pl_square->getContentSize().height / 2,
				    _pl_square->getContentSize().width,
				    _pl_square->getContentSize().height);

	// �`�[���Ґ��p�g����
	//_box_rect = Rect(_Box->getPosition().x - _Box->getContentSize().width / 2,
	//				 _Box->getPosition().y - _Box->getContentSize().height / 2,
	//			     _Box->getContentSize().width * BOX_SCALE ,
	//				 _Box->getContentSize().height * BOX_SCALE );


	// No.1�����蔻���������ƃ`�[���Ґ��̕�������ƑΉ�������
	// �Ȃ񂩂��܂������ĂȂ������낵����
	_box_rect = Rect(0, 0, _Box->getContentSize().width * BOX_SCALE, _Box->getContentSize().height * BOX_SCALE);	// �͈�
	for (int i = 0; i< 3;i++)
	{
		_Box = Sprite::create();													// ����
		_Box->setTextureRect(_box_rect);											// �e�N�X�`���w��
		_Box->setPosition((TEAM_BOX_X + 16)*i + TEAM_BOX_OFFSET_X, (TEAM_BOX_Y));	// ���W�z�u
		//this->addChild(_Box);
	}
}

// �A�����W�@��]�Ƃ�
void CharaSelectScene::Arrange()
{
	// �~��ɓ��Ԋu�Ŕz�u
	float theta = 360.0f / items.size()+(items.size()/2);
	float baseAngle = this->angle + 270.0f;							// ���Z����Ɖ~�̉��s�������
	for (int i = 0; i < items.size(); i++)
	{
		// 270 �x�̈ʒu�����ʂɂ���悤��  
		float angle		= theta   * i + baseAngle;
		float radians	= angle   * PI / 180.0f;
		float x		    = RADIUS  * cos(radians);
		float y	        = RADIUS  * sin(radians) * FLATTEN_RATE;	// �~�̊p�x�΂߂ɂ����
		float radiusY   = RADIUS  * FLATTEN_RATE;
		float diameterY = radiusY * 2;
		float scale		= (diameterY - y) / diameterY;				// y���W�ɉ����ĕω������
		GLubyte opacity = 255 - (y + radiusY);

		this->items.at(i)->setPosition(Vec2(x+ PL_POS_OFFSET_X, y+ PL_POS_OFFSET_Y + 20));
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

// �X���C�v�ɍ��킹�ĉ�]
void CharaSelectScene::SwipeRotation()
{
	// �X���C�v�ɍ��킹�ĉ�]
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	// �N���b�N�����Ƃ�
	listener->onTouchBegan = [](Touch *touch, Event *event) { return true; };
	// �ړ���[�X���C�v]
	listener->onTouchMoved = [&](Touch *touch, Event *event)
	{
		float delta = touch->getLocation().x - touch->getPreviousLocation().x;
		this->angle += delta;
		this->Arrange();
	};
	// ������
	listener->onTouchEnded = [&](Touch *touch, Event *event)
	{
		// No.2 SwipeRotation���̗�����,������������������,�����������̊֐����ɓ����̂�

		// �␳���܂���
		// ���̒l
		if (angle>0.f)
		{
			this->angle = (((((static_cast<int>(this->angle)) + DIV_ANGLE_HALF) % 360) / DIV_ANGLE) * DIV_ANGLE);
		}
		// ���̒l
		else
		{
			this->angle = ((((static_cast<int>(this->angle - 360) % 360 - DIV_ANGLE_HALF) % 360) / DIV_ANGLE) * DIV_ANGLE);
		}
		this->Arrange();
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

// �L�������擾
const std::vector<CharaName>& CharaSelectScene::GetCharaData()
{
	return CharaData;
}

// ����ʑJ��
void CharaSelectScene::pushStart(Ref * pSender)
{
	CCLOG("Push�{�^��");

	// �J�ڍ�̉�ʂ�ݽ�ݽ
	Scene *pScene = FightScene::createScene();

	// 0.6�b�����Ď���ʂɑJ��
	// (����,�J�ڐ�,�F(�I�v�V����))
	TransitionFade *transition = TransitionFade::create(WAIT_TIME, pScene);

	// �J�ڎ��s �A�j���[�V����
	Director::getInstance()->replaceScene(transition);
}
// �O��ʑJ��
void CharaSelectScene::backStart(Ref * pSender)
{
	CCLOG("Push�{�^��");

	// �J�ڍ�̉�ʂ�ݽ�ݽ
	Scene *pScene = TitleScene::createScene();

	// 0.6�b�����Ď���ʂɑJ��
	// (����,�J�ڐ�,�F(�I�v�V����))
	TransitionFade *transition = TransitionFade::create(WAIT_TIME, pScene);

	// �J�ڎ��s �A�j���[�V����
	Director::getInstance()->replaceScene(transition);
}

/*
// Click������f�[�^������
//void CharaSelectScene::CharaClick()
//{
//	// �ǂꂪ��ԑO�ɂ���̂��𕪂���悤�ɒ��ׂ悤���Â����鏈���y����
//	// 0123�ɂ��낦�܂��傤���@//static_cast<CharaData>(1234�̂��-1);
//
//	if(Top)
//	{
//	// ������ӂ͈̔�2�����^�b�v������
//		int i = 0;
//		for (i = 0; i < items.size(); i++)
//		{
//			//
//			if (items[i] == Top)
//			{
//				break;
//			}
//			// �ǉ�
//			CharaData.push_back(static_cast<CharaName> (i));
//		}
//			// �I���O�̎҂͈Â�����
//			if (!Top)
//			{
//
//				�^�b�v�����z�@�g�嗦�ō��O�̂�𔻒f
//
//				���̔ԍ���pushback
//					//push_back
//					CharaData.push_back;
//				}
//	};
//}*/

/*�@URL
http://takachan.hatenablog.com/entry/2017/08/08/002844
https://iscene.jimdo.com/2015/02/04/cocos2d-x-ver-3-x-c-iphone-android-%E3%81%AE%E9%96%8B%E7%99%BA%E5%9F%BA%E7%A4%8E%E8%AC%9B%E5%BA%A7-%E7%9B%AE-%E6%AC%A1/
http://hayateasdf.hatenablog.com/entry/2017/12/21/190434#10-%E6%95%B5%E3%81%AE%E4%BD%9C%E6%88%90
https://qiita.com/isaoeka/items/dee8159e2a0c2a37a662
http://brbranch.jp/blog/201607/cocos2d-x/shader/
http://buildman.xyz/blog/cocos2dx-beginner-10/
https://teratail.com/questions/72658
http://www.fujimi-labo.com/2016/11/29/cocos2d-x8_1/
http://rinov.jp/cocos-doujo-dx/index.html
https://qiita.com/HamachiTaro/items/f7df7fc101e7e1222afc
http://brbranch.jp/blog/201312/cocos2d-x/convert_to_node_space/

// �����\��
//http://developer.wonderpla.net/entry/blog/engineer/Cocos2dx_Carousel
//http://hayateasdf.hatenablog.com/entry/2017/12/21/190434#10-%E6%95%B5%E3%81%AE%E4%BD%9C%E6%88%90
//https://iscene.jimdo.com/2015/02/23/cocos2d-x-ver-3-x-top%E3%83%9A%E3%83%BC%E3%82%B8-tableview-%E7%94%BB%E5%83%8F%E8%A1%A8%E7%A4%BA%E7%B7%A8/
// cocos �����Ȃ̂��ڂ��Ă�T�C�g
// https://iscene.jimdo.com/2015/02/04/cocos2d-x-ver-3-x-c-iphone-android-%E3%81%AE%E9%96%8B%E7%99%BA%E5%9F%BA%E7%A4%8E%E8%AC%9B%E5%BA%A7-%E7%9B%AE-%E6%AC%A1/


http://vivi.dyndns.org/blog/archives/605
https://freegame-mugen.jp/roleplaying/game_6860.html
https://qiita.com/s0hno/items/739b8da8d0ee1375c2cd

// �R�C���G�t�F�N�g�\��
http://takachan.hatenablog.com/entry/2017/08/28/213842

// �����`��
void CharaSelectScene::FontsDraw()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	// �X���C�v�̓����Ă���Ƃ�
	// �z�u����
	auto swipeLabel = Label::createWithSystemFont("�X���C�v�œ�����", "fonts/HGRSGU.TTC", 30);
	// �z�u�ꏊ
	swipeLabel->setPosition(100, 300);
	swipeLabel->setColor(Color3B(200, 150, 0));

	// Select�ǉ�
	this->addChild(swipeLabel, 1);
	auto act1 = ScaleTo::create(LIMIT_TIME, DOUBLE_SCALE);   // 0.9�b��0.5�{�Ɋg��
	auto act2 = ScaleTo::create(LIMIT_TIME, 1.0f);			 // 0.9�b�Ō��̃T�C�Y�ɖ߂�
	swipeLabel->runAction(RepeatForever::create(Sequence::create(act1, act2, NULL)));  //  ���X�J��Ԃ�
}

*/
