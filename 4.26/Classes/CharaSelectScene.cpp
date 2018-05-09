#include "CharaSelectScene.h"
#include "FightScene.h"
#include "Imput.h"
#include <algorithm>
#include "cocos2d.h"
#include "DmEffect.h"

#define PI 3.14159265359f  
#define RADIUS 100  
#define FLATTEN_RATE 0.4f  

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

	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();

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
	this->addChild(menu, 3);

	PL_Attacker = Sprite::create("PL_Attacker.png");

 	this->items.clear();
	this->items.push_back(PL_Attacker);
	this->items.push_back(CCSprite::create("PL_Shield.png"));
	this->items.push_back(CCSprite::create("PL_Magic.png"));
	this->items.push_back(CCSprite::create("PL_Healer.png"));

	// �~��ɓ��Ԋu�Ŕz�u
	for (auto item : items)
		this->addChild(item);

	this->angle = 0.0f;
	this->arrange();
	// �X���C�v�ɍ��킹�ĉ�]

	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [ ](Touch *touch, Event *event) { return true; };
	listener->onTouchMoved = [&](Touch *touch, Event *event) 
	{
		float delta  = touch->getLocation().x - touch->getPreviousLocation().x;
		this->angle += delta;
		this->arrange();
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

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

		this->items.at(i)->setPosition(Vec2(x+420, y+450));
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

// �w�i
void CharaSelectScene::CharaSelectBackGroudn()
{
	// ��ʃT�C�Y�擾
	Size winSize = Director::getInstance()->getVisibleSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	// �^�C�g���z�u
	// �z�u����
	auto lbl_Select = Label::createWithSystemFont("CharaSelect", "HiraKakuProN-W6", 100);
	// �z�u�ꏊ
	lbl_Select->setPosition(Point(origin.x + winSize.width / 2,
		origin.y + winSize.height - lbl_Select->getContentSize().height));

	// Select�ǉ�
	this->addChild(lbl_Select, 1);
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
	Scene *pScene = FightScene::createScene();

	// 0.6�b�����Ď���ʂɑJ��
	// (����,�J�ڐ�,�F(�I�v�V����))
	TransitionFade *transition = TransitionFade::create(0.6, pScene);

	// �J�ڎ��s �A�j���[�V����
	Director::getInstance()->replaceScene(transition);
}



/*
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