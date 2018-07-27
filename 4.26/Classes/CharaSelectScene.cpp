#include "CharaSelectScene.h"
#include "Geometry.h"
#include "FightScene.h"
#include "GameOver.h"
#include "TitleScene.h"
#include "Global.h"
#include "Imput.h"
#include <algorithm>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

#pragma execution_character_set("utf-8")

const int DIV_NUM		  = 4;
const int DIV_ANGLE		  = 360 / DIV_NUM;
const int DIV_ANGLE_HALF  = DIV_ANGLE / 2;

const unsigned int PL_TAG				= 101;		// �v���C���[�؂�ւ��p�^�O
const unsigned int TEXT_OFFSET			= 510;		// text�\���̃I�t�Z�b�g�l
const unsigned int FAST_CLICK			= 1;		// ���߂�click
const unsigned int SECOND_CLICK			= 2;		// 2���click
const unsigned int TEAM_MEMBER			= 3;		// �`�[���̐l��

const unsigned int NEXT_BUTTON_X		= 660;		// ���̉�ʑJ�ڂւ̃{�^���̔z�u���WX
const unsigned int NEXT_BUTTON_Y		= 65;		// ���̉�ʑJ�ڂւ̃{�^���̔z�u���WY

const unsigned int FONT_SIZE			= 38;		// �v���C���[�������p�̕�������
const unsigned int PL_TEXT_RECT_X		= 250;		// �v���C���[�p�̔̔z�u�ʒuX
const unsigned int PL_TEXT_RECT_Y		= 750;		// �v���C���[�p�̔̔z�u�ʒuY
const unsigned int TEAM_BOX_X			= 171;		// �`�[���Ґ��p��box�̔z�u�ʊJX 165
const unsigned int TEAM_BOX_Y			= 180;		// �`�[���Ґ��p��box�̔z�u�ʒuY
const unsigned int TEAM_BOX_OFFSET_X	= 225;		// �`�[���Ґ��p��box�̃I�t�Z�b�g

const unsigned int PLAYER_NAME_WIDTH	= 210;

// �p�x�֌W�Ŏg����
const int RADIUS						= 200;
const float PI							= 3.14159265359f;
const float FLATTEN_RATE				= 0.4f;
const unsigned int PL_POS_OFFSET_X		= 420;				// �v���C���[�\���̃I�t�Z�b�g
const unsigned int PL_POS_OFFSET_Y		= 820;				// �v���C���[�\���̃I�t�Z�b�g
// �g�k�p
const float LIMIT_TIME					= 0.9f;				// �b�w��[�߂��]
const float DOUBLE_SCALE				= 0.5f;				// ���{��[�g�嗦�w��]
const float WAIT_TIME					= 0.6f;				// �ҋ@����
const float BOX_SCALE					= 1.2;				// �`�[���Ґ��p��BOX�̊g�嗦

const float SOUND_VOLUME				= 0.5f;				// BGM���ʒ���

USING_NS_CC;

// ���ԍ���
std::vector<CharaName> CharaSelectScene::CharaData;
std::map<CharaName, Sprite *> CharaSelectScene::teamData;

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
	auto _buttunNext = MenuItemImage::create(UI_BUTTON_NEXT, UI_BUTTON_NEXT_PUSH, CC_CALLBACK_1(CharaSelectScene::pushStart, this));
	_buttunNext->setPosition(NEXT_BUTTON_X+30, NEXT_BUTTON_Y);		// ���W�w��
	_buttunNext->setScale(0.5);										// �傫������

	auto menu1 = Menu::create(_buttunNext, NULL);					// ���j���[�쐬(����obj)
	menu1->setPosition(Point::ZERO);								// ���W�z�u
	this->addChild(menu1, 8);										// �ǉ�

	auto _buttunBack = MenuItemImage::create(UI_BUTTON_BUCK, UI_BUTTON_BUCK, CC_CALLBACK_1(CharaSelectScene::backStart, this));
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

	//�L�����f�[�^�̏�����
	teamData[CharaName::CHARA_ATTACKER]		= Sprite::create(PL_ATTACKER_FACE);
	teamData[CharaName::CHARA_SHIELD]		= Sprite::create(PL_SHIELD_FACE);
	teamData[CharaName::CHARA_MAGIC]		= Sprite::create(PL_MAGIC_FACE);
	teamData[CharaName::CHARA_HEALER]		= Sprite::create(PL_HEALER_FACE);

	//�傫��
	//teamData[CharaName::CHARA_ATTACKER]->setScale(BOX_SCALE);
	//teamData[CharaName::CHARA_SHIELD]->setScale(BOX_SCALE);
	//teamData[CharaName::CHARA_MAGIC]->setScale(BOX_SCALE);
	//teamData[CharaName::CHARA_HEALER]->setScale(BOX_SCALE);

	//_s_teamAttacker = Sprite::create(PL_ATTACKER_FACE);
	//teamData = _s_teamAttacker;
	
//	Sound();
	TeamBoxDraw();						// �\��(�L�����ȊO)
	CharaDraw();						// �L�����\��
	SwipeRotation();					// �X���C�v�ɍ��킹�ĉ�]
	ObjHit();							// �����蔻��
	this->scheduleUpdate();				// �X�V
	_s_fontBoard->setVisible(false);	// ���\��
	CharaData.reserve(TEAM_MEMBER);		// ���O�ɗ̈�m��[�`�[���̐l����]
	

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
	_clickCnt = 0;						// �����Ă���Ƃ��̓J�E���g���Ȃ�
	// �X���C�v���ɂ͔͕\�����Ȃ�
	if (_s_fontBoard->isVisible())
	{
		_s_fontBoard->setVisible(false);
	}	
}
// �������u��
void CharaSelectScene::TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event)
{
	_touchPos = touch->getLocation();
	Top->pause();

	//�w��Rect�����N���b�N������������\��
	if (_r_pl_rect.containsPoint(_touchPos))
	{
		_clickCnt += 1;
		
		if (_clickCnt == FAST_CLICK)
		{
			_s_fontBoard->setVisible(true);	// �������̔\��
			CharaText();					// �L����������
		}
		else if (_clickCnt == SECOND_CLICK)
		{
			AddTeam();						// �`�[���ǉ��p
			_clickCnt = FAST_CLICK;
		}
		else if (_clickCnt < FAST_CLICK)
		{
			// �����Ȃ�
		}
	}
	else
	{
		_s_fontBoard->setVisible(false);	// �������̔�\��
	}
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

	_s_Attacker = Sprite::create(PL_ATTACKER);
	_s_Shield   = Sprite::create(PL_SHIELD);
	_s_Magic    = Sprite::create(PL_MAGIC);
	_s_Healer   = Sprite::create(PL_HEALER);

	this->items.clear();
	this->items.push_back(_s_Attacker);
	this->items.push_back(_s_Shield);
	this->items.push_back(_s_Magic);
	this->items.push_back(_s_Healer);

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
	TTFConfig ttfConfig(FONT_PL_TEXT, FONT_SIZE);
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

	auto plName1 = Label::createWithTTF(ttfConfig, "���m");
	auto plName2 = Label::createWithTTF(ttfConfig, "�R�m");
	auto plName3 = Label::createWithTTF(ttfConfig, "���p�t");
	auto plName4 = Label::createWithTTF(ttfConfig, "���E��");

	// �A�^�b�J�[
	if (Top == _s_Attacker)
	{
		this->removeChildByTag(PL_TAG);
		// �^�O�ݒ�
		label1->setTag(PL_TAG);
		label1->setColor(textColor);
		label1->setPosition(winSize.width / 2, winSize.height / 2 + TEXT_OFFSET);
		// �^�O�ݒ�
		plName1->setTag(PL_TAG);
		plName1->setColor(textColor);
		plName1->setScale(0.9);
		plName1->setPosition(winSize.width / 2- PLAYER_NAME_WIDTH, winSize.height / 2 + TEXT_OFFSET-100);
		// �^�O�`�F�b�N
		if (int tag = label1->getTag() != 1)
		{
			this->addChild(label1 ,6);
			this->addChild(plName1,6);
		}
	}
	// �V�[���h
	else if (Top == _s_Shield)
	{
		this->removeChildByTag(PL_TAG);
		// �^�O�ݒ�
		label2->setTag(PL_TAG);
		label2->setColor(textColor);
		label2->setPosition(winSize.width / 2, winSize.height / 2 + TEXT_OFFSET);
		// �^�O�ݒ�
		plName2->setTag(PL_TAG);
		plName2->setColor(textColor);
		plName2->setScale(0.9);
		plName2->setPosition(winSize.width / 2 - PLAYER_NAME_WIDTH, winSize.height / 2 + TEXT_OFFSET - 100);
		if (int tag = label2->getTag() != 1)
		{
			this->addChild(label2 , 6);
			this->addChild(plName2, 6);
		}
	}
	// ���@
	else if (Top == _s_Magic)
	{
		this->removeChildByTag(PL_TAG);
		// �^�O�ݒ�
		label3->setTag(PL_TAG);
		label3->setColor(textColor);
		label3->setPosition(winSize.width / 2, winSize.height / 2 + TEXT_OFFSET);
		// �^�O�ݒ�
		plName3->setTag(PL_TAG);
		plName3->setColor(textColor);
		plName3->setScale(0.9);
		plName3->setPosition(winSize.width / 2 - PLAYER_NAME_WIDTH, winSize.height / 2 + TEXT_OFFSET - 100);
		// �^�O�`�F�b�N
		if (int tag = label3->getTag() != 1)
		{
			this->addChild(label3 , 6);
			this->addChild(plName3, 6);
		}

	}
	// ��
	else if (Top == _s_Healer)
	{
		this->removeChildByTag(PL_TAG);
		// �^�O�ݒ�
		label4->setTag(PL_TAG);
		label4->setColor(textColor);
		label4->setPosition(winSize.width / 2, winSize.height / 2 + TEXT_OFFSET);
		// �^�O�ݒ�
		plName4->setTag(PL_TAG);
		plName4->setColor(textColor);
		plName4->setScale(0.9);
		plName4->setPosition(winSize.width / 2 - PLAYER_NAME_WIDTH, winSize.height / 2 + TEXT_OFFSET - 100);
		// �^�O�`�F�b�N
		if (int tag = label4->getTag() != 1)
		{
			this->addChild(label4 , 6);
			this->addChild(plName4, 6);
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
	_batchNode = SpriteBatchNode::create(UI_PL_CHRA_FLAME);
	_batchNode->setPosition(TEAM_BOX_OFFSET_X, 0);

	// �`�[���Ґ���Box���\��
	for (int n = 0; n<TEAM_MEMBER; n++)
	{
		//batchNode����e�N�X�`�����擾
		_ccp_Box = Sprite::createWithTexture(_batchNode->getTexture());
		_ccp_Box->setScale(BOX_SCALE);
		
		_ccp_Box->setPosition((TEAM_BOX_X+16)*n, (TEAM_BOX_Y));

		//SpriteBatchNode�ɓ\��t��
		_batchNode->addChild(_ccp_Box);
	}
	this->addChild(_batchNode);
}

// �w�i
void CharaSelectScene::CharaSelectBackGroudn()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	
	// �w�i�摜�ǉ�
	Sprite* _backImage = Sprite::create(BACK_GRAND_SPRITE_CHRASELECT);
	_backImage->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(_backImage,0);

	//�������̔z�u
	_s_fontBoard = Sprite::create(UI_FONT_BOARD);
	_s_fontBoard->setPosition(winSize.width / 2, 1130);
	this->addChild(_s_fontBoard, 1);
}

// �����蔻��p
void CharaSelectScene::ObjHit()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();

	// �v���C���[�p�̃N���b�N����p��
	_r_pl_rect   = Rect(0, 0, PL_TEXT_RECT_X, PL_TEXT_RECT_Y);	// �͈�
	_s_pl_square = Sprite::create();								// ����
	_s_pl_square->setTextureRect(_r_pl_rect);						// �e�N�X�`���w��
	_s_pl_square->setPosition(430, winSize.height / 2);			// ���W�z�u
	//this->addChild(pl_square);								// �ǉ�

	// �v���C���[�N���b�N����͈�
	_r_pl_rect = Rect(_s_pl_square->getPosition().x - _s_pl_square->getContentSize().width /  2,
				    _s_pl_square->getPosition().y - _s_pl_square->getContentSize().height / 2,
				    _s_pl_square->getContentSize().width,
				    _s_pl_square->getContentSize().height);

	// No.1�����蔻���������ƃ`�[���Ґ��̕�������ƑΉ�������
	// �Ȃ񂩂��܂������ĂȂ������낵����
	_r_box_rect = Rect(0, 0, _ccp_Box->getContentSize().width * BOX_SCALE, _ccp_Box->getContentSize().height * BOX_SCALE);	// �͈�
	for (int i = 0; i< 3;i++)
	{
		_ccp_Box = Sprite::create();													// ����
		_ccp_Box->setTextureRect(_r_box_rect);											// �e�N�X�`���w��
		_ccp_Box->setPosition((TEAM_BOX_X + 16)*i + TEAM_BOX_OFFSET_X, (TEAM_BOX_Y));	// ���W�z�u
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
	// �\�[�g
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

// �`�[���ǉ��p
void CharaSelectScene::AddTeam()
{
	int i = 0;
	for (i = 0; i < items.size(); i++)
	{
		if (items[i] != Top)
		{
			continue;
		}
	
		log("�ǉ�����܂����B%d", i);
		// ��O��������Ăˁ@����Ȃ��L�����I�ׂȂ��Ƃ�
		//�T�C�Y�����Ă��Ȃ���
		if (CharaData.size() == TEAM_MEMBER)
		{
			log("�����o�[�������܂���", CharaData);
			//TeamDraw();		
			break;
		}
		CharaData.push_back(static_cast<CharaName> (i));
		//addChild����
		teamData[static_cast<CharaName>(i)]->setPosition(TEAM_BOX_OFFSET_X + (TEAM_BOX_X * i), (TEAM_BOX_Y));
		this->addChild(teamData[static_cast<CharaName>(i)]);
	}
}

// BGM
void CharaSelectScene::Sound()
{
	// ���Ƃ�SoundManager������Ă�蒼���Ă�
	// ���y�t�@�C���̓ǂݍ���
	auto _sound = SimpleAudioEngine::getInstance();
	_sound->setBackgroundMusicVolume(SOUND_VOLUME);
	_sound->preloadBackgroundMusic("BGM/BGM_PartyCreate_Main.mp3");

	_sound->playBackgroundMusic("BGM/BGM_PartyCreate_Main.mp3", true);
}

// ����ʑJ��
void CharaSelectScene::pushStart(Ref * pSender)
{
	CCLOG("Push�{�^��");

	// �J�ڍ�̉�ʂ�ݽ�ݽ
	Scene *pScene = FightScene::createScene();

	// 0.6�b�����Ď���ʂɑJ��(����,�J�ڐ�,�F(�I�v�V����))
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

	// 0.6�b�����Ď���ʂɑJ�� (����,�J�ڐ�,�F(�I�v�V����))
	TransitionFade *transition = TransitionFade::create(WAIT_TIME, pScene);

	// �J�ڎ��s �A�j���[�V����
	Director::getInstance()->replaceScene(transition);
}