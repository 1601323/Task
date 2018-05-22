#include "CharaSelectScene.h"
#include "FightScene.h"
#include "GameOver.h"
#include "Imput.h"
#include <algorithm>
#include "cocos2d.h"

#pragma execution_character_set("utf-8")

const int TEXT_OFFSET	 = 480;					// text�\���̃I�t�Z�b�g�l
const int DIV_NUM		 = 4;
const int DIV_ANGLE		 = 360 / DIV_NUM;
const int DIV_ANGLE_HALF = DIV_ANGLE / 2;
// �p�x�֌W�Ŏg����
const int RADIUS = 100;
const float PI = 3.14159265359f;
const float FLATTEN_RATE = 0.4f;
const unsigned int PL_POS_OFFSET_X = 420;		// �v���C���[�\���̃I�t�Z�b�g
const unsigned int PL_POS_OFFSET_Y = 650;		// �v���C���[�\���̃I�t�Z�b�g
// �g�k�p
const float LIMIT_TIME	 = 0.9f;					// �b�w��[�߂��]
const float DOUBLE_SCALE = 0.5f;					// ���{��[�g�嗦�w��]

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
	// �摜�T�C�Y�擾
	getSize();		

	// �{�^���z�u
	// �ʏ펞,��������
	// ���������̱����
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(CharaSelectScene::pushStart, this));

	// �{�^���̔z�u
	startButton->setPosition(50,1200);
	// ���j���[�쐬(����obj)
	auto menu = Menu::create(startButton, NULL);
	menu->setPosition(Point::ZERO);
	// �ǉ�
	this->addChild(menu, 8);

	// �L�����\��
	charaDraw();
	// �X���C�v�ɍ��킹�ĉ�]
	swipeRotation();
	// �l�p�`��
	DrawBox();
	fontsDraw();

	this->scheduleUpdate();
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

// �X�V
void CharaSelectScene::update(float delta)
{
	charaText();
}

// �v���C���[������
void CharaSelectScene::charaText()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();
	// �t�H���g�w��
	TTFConfig ttfConfig("fonts/HGRSGU.TTC", 45);
	// �F�w��
	auto textColor = Color3B(0,100,50);

	auto label1 = Label::createWithTTF(ttfConfig,
		"����{�ő��ʂȍU��\n�h����̂ĂĂł��Η͂��Ƃ�\n���n�̌��m");
	auto label2 = Label::createWithTTF(ttfConfig,
		"���@�Ő����������Ō��������\n������_���[�W���󂯂邪\n���Ԃ����B�ꖳ��̏�");
	auto label3 = Label::createWithTTF(ttfConfig,
		"���@�U���œG���U��������悵\n�������������ăT�|�[�g���Ă��悵\n��̊�����}�W�V����");
	auto label4 = Label::createWithTTF(ttfConfig,
		"�񕜂̃X�y�V�����X�g�Ǝv������\n�G�̎�̉������C��\n�f�o�t�n�q�[���[");

	// �A�^�b�J�[
	if (Top == PL_Attacker)
	{
		this->removeChildByTag(101);
		// �^�O�ݒ�
		label1->setTag(101);  
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
	else if (Top == PL_Shield)
	{
		this->removeChildByTag(101);
		// �^�O�ݒ�
		label2->setTag(101); 
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
	else if (Top == PL_Magic)
	{
		this->removeChildByTag(101);
		// �^�O�ݒ�
		label3->setTag(101); 
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
	else if (Top == PL_Healer)
	{
		this->removeChildByTag(101);
		// �^�O�ݒ�
		label4->setTag(101); 
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

// �摜�T�C�Y�擾
void CharaSelectScene::getSize()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();
}

// �L�����\��
void CharaSelectScene::charaDraw()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	PL_Attacker = Sprite::create("PL_Attacker.png");
	PL_Shield = Sprite::create("PL_Shield.png");
	PL_Magic = Sprite::create("PL_Magic.png");
	PL_Healer = Sprite::create("PL_Healer.png");

	this->items.clear();
	this->items.push_back(PL_Attacker);
	this->items.push_back(PL_Shield);
	this->items.push_back(PL_Magic);
	this->items.push_back(PL_Healer);
	//this->items.clear();
	//this->items.push_back(Sprite::create("PL_Attacker.png"));
	//this->items.push_back(Sprite::create("PL_Shield.png"));
	//this->items.push_back(Sprite::create("PL_Magic.png"));
	//this->items.push_back(Sprite::create("PL_Healer.png"));

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
	this->arrange();
}

// �A�����W�@��]�Ƃ�
void CharaSelectScene::arrange()
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

		this->items.at(i)->setPosition(Vec2(x+ PL_POS_OFFSET_X, y+ PL_POS_OFFSET_Y));
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
void CharaSelectScene::swipeRotation()
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
		this->arrange();
	};
	// ������
	listener->onTouchEnded = [&](Touch *touch, Event *event)
	{
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
		this->arrange();
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

// �����`��
void CharaSelectScene::fontsDraw()
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
	swipeLabel->setColor(Color3B(200,150,0));

	// Select�ǉ�
	this->addChild(swipeLabel, 1);
	auto act1 = ScaleTo::create(LIMIT_TIME, DOUBLE_SCALE);   // 0.9�b��0.5�{�Ɋg��
	auto act2 = ScaleTo::create(LIMIT_TIME, 1.0f);			 // 0.9�b�Ō��̃T�C�Y�ɖ߂�
	swipeLabel->runAction(RepeatForever::create(Sequence::create(act1, act2, NULL)));  //  ���X�J��Ԃ�
}

// �w�i
void CharaSelectScene::CharaSelectBackGroudn()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();
}

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
//				if (!Top)
//				{
//
//					/*�^�b�v�����z�@�g�嗦�ō��O�̂�𔻒f
//
//					���̔ԍ���pushback*/
//					//push_back
//					CharaData.push_back;
//				}
//	};
//}

// �L�������擾
const std::vector<CharaName>& CharaSelectScene::GetCharaData()
{
	return CharaData;
}

// ��ʑJ��
void CharaSelectScene::pushStart(Ref * pSender)
{
	CCLOG("Push�{�^��");

	// �J�ڍ�̉�ʂ�ݽ�ݽ
	Scene *pScene = GameOver::createScene();

	// 0.6�b�����Ď���ʂɑJ��
	// (����,�J�ڐ�,�F(�I�v�V����))
	TransitionFade *transition = TransitionFade::create(0.6, pScene);

	// �J�ڎ��s �A�j���[�V����
	Director::getInstance()->replaceScene(transition);
}

// �l�p�\��
void CharaSelectScene::DrawBox()
{
	/*CCSprite *Box = CCSprite::create("nc25818.png");
	Box->setScale(2);
	Box->setPosition(130,130);
	addChild(Box,2);

	CCSprite *Box1 = CCSprite::create("nc25818.png");
	Box1->setScale(2);
	Box1->setPosition(310, 130);
	addChild(Box1, 2);

	CCSprite *Box2 = CCSprite::create("nc25818.png");
	Box2->setScale(2);
	Box2->setPosition(490, 130);
	addChild(Box2, 2);

	CCSprite *Box3 = CCSprite::create("nc25818.png");
	Box3->setScale(2);
	Box3->setPosition(670, 130);
	addChild(Box3, 2);*/


	CCSprite *Box = CCSprite::create("nc25818.png");
	Box->setScale(2);
	Box->setPosition(210, 130);
	addChild(Box, 2);

	CCSprite *Box1 = CCSprite::create("nc25818.png");
	Box1->setScale(2);
	Box1->setPosition(390, 130);
	addChild(Box1, 2);

	CCSprite *Box2 = CCSprite::create("nc25818.png");
	Box2->setScale(2);
	Box2->setPosition(570, 130);
	addChild(Box2, 2);
}

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


*/