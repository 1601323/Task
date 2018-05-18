#include "CharaSelectScene.h"
#include "FightScene.h"
#include "GameOver.h"
#include "Imput.h"
#include <algorithm>
#include "cocos2d.h"
#include "DmEffect.h"

#define PI 3.14159265359f  
#define RADIUS 100  
#define FLATTEN_RATE 0.4f  
#define PL_POS_OFFSET_X 420		// �v���C���[�\���̃I�t�Z�b�g
#define PL_POS_OFFSET_Y 650		// �v���C���[�\���̃I�t�Z�b�g

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
	PL_Attacker = Sprite::create("PL_Attacker.png");
	PL_Shield	= Sprite::create("PL_Shield.png");
	PL_Magic	= Sprite::create("PL_Magic.png");
	PL_Healer	= Sprite::create("PL_Healer.png");

	this->items.clear();
	this->items.push_back(PL_Attacker);
	this->items.push_back(PL_Shield);
	this->items.push_back(PL_Magic);
	this->items.push_back(PL_Healer);

	// �~��ɓ��Ԋu�Ŕz�u
	for (auto item : items)
		this->addChild(item,0);

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
	{return a->getScale() < b->getScale(); });
	Top = tmpVector.front();

}

// �X���C�v�ɍ��킹�ĉ�]
void CharaSelectScene::swipeRotation()
{
	// �X���C�v�ɍ��킹�ĉ�]
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [](Touch *touch, Event *event) { return true; };
	listener->onTouchMoved = [&](Touch *touch, Event *event)
	{
		float delta = touch->getLocation().x - touch->getPreviousLocation().x;
		this->angle += delta;
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

	// �w�肵���t�H���g�̕`��


	// �w��t�H���g�̓ǂݍ���(�t�H���g��,�T�C�Y,)
	TTFConfig ttfConfig("fonts/HGRSGU.TTC", 45, GlyphCollection::DYNAMIC);
	// �\��
	auto label = Label::createWithTTF(ttfConfig,
		"���@�U���œG���U��������悵\n�������������ăT�|�[�g������悵�A\n2�̊�����}�W�V����");
	// �F�w��
	label->setColor(Color3B(0, 0, 0));
	// ���W�w��
	label->setPosition(winSize.width / 2, winSize.height / 2 + 480);
	// �s�Ԋu����
	//label->setLineHeight(/*���̒l*/);

	// ���ʂ̂悤�ȃG�t�F�N�g������
	TTFConfig ttfConfigEffect(ttfConfig);
	ttfConfigEffect.distanceFieldEnabled = true; //true�ɂ���
	label->enableGlow(Color4B::GREEN); //�F��ݒ�
	// �ǉ�
	this->addChild(label, 6);
}

// �w�i
void CharaSelectScene::CharaSelectBackGroudn()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	// �^�C�g���z�u
	// �z�u����
	//auto lbl_Select = Label::createWithSystemFont("CharaSelect", "HiraKakuProN-W6", 100);
	// �z�u�ꏊ
	//lbl_Select->setPosition(Point(origin.x + winSize.width / 2,origin.y + winSize.height - lbl_Select->getContentSize().height));

	// Select�ǉ�
	//this->addChild(lbl_Select, 1);

	// x���W, y���W, width, height
	Rect rect = Rect(150,180, 1280, 280);
	Sprite* square = Sprite::create();
	square->setTextureRect(rect);
	square->setPosition(180,1120 );
	square->setColor(Color3B(82,162,197));
	this->addChild(square,2);

	Rect rect2 = Rect(150, 180, 1250, 250);
	Sprite* square2 = Sprite::create();
	square2->setTextureRect(rect2);
	square2->setPosition(180, 1120);
	square2->setColor(Color3B(255, 255, 255));
	this->addChild(square2, 5);
}

// �N���b�N�J�n���ɌĂ΂��
//bool CharaSelectScene::onTouchBegan(Touch *touch, Event *unused_event)
//{
//	cocos2d::CCSprite* m_pSprite;
//
//	// touch���W�擾
//	Vec2 touch_pos = touch->getLocation();
//	// �X�v���C�g��AABB���擾
//	Rect rect_spr = m_pSprite->getBoundingBox();
//
//	// �X�v���C�g��Touch���W���܂܂�Ă��邩�ǂ���
//	bool hit = rect_spr.containsPoint(touch_pos);
//
//	if (hit)
//	{
//		log("touch sprite!!!");
//	}
//	return true;
//}

// Click������f�[�^������
void CharaSelectScene::CharaClick()
{
	// �ǂꂪ��ԑO�ɂ���̂��𕪂���悤�ɒ��ׂ悤���Â����鏈���y����
	// 0123�ɂ��낦�܂��傤���@//static_cast<CharaData>(1234�̂��-1);

	//if()
	{
	// ������ӂ͈̔�2�����^�b�v������
		int i = 0;
		for (i = 0; i < items.size(); i++)
		{
			// 
			if (items[i] == Top)
			{
				break;
			}
			// �ǉ�
			CharaData.push_back(static_cast<CharaName> (i));
		}
			// �I���O�̎҂͈Â�����
			//	if ()
			//	{

			//		/*�^�b�v�����z�@�g�嗦�ō��O�̂�𔻒f

			//		���̔ԍ���pushback*/
			//		//push_back
			//		CharaData.push_back;
			//	}
	};
}

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
	// ��`
	// x���W, y���W, width, height
	/*Rect rect = Rect(10,10, 1500, 280);
	Sprite* square = Sprite::create();
	square->setTextureRect(rect);
	square->setPosition(100,100 );
	this->addChild(square,2);*/

	CCSprite *Box = CCSprite::create("nc25818.png");
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
	addChild(Box3, 2);

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
*/