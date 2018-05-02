#include "CharaSelectScene.h"
#include "FightScene.h"
#include "Imput.h"

#define PI 3.14159265359f  
#define RADIUS 100  
#define FLATTEN_RATE 0.4f  

USING_NS_CC;

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


	// �����\��  
	/*http://developer.wonderpla.net/entry/blog/engineer/Cocos2dx_Carousel/*/
	//http://hayateasdf.hatenablog.com/entry/2017/12/21/190434#10-%E6%95%B5%E3%81%AE%E4%BD%9C%E6%88%90
	//https://iscene.jimdo.com/2015/02/23/cocos2d-x-ver-3-x-top%E3%83%9A%E3%83%BC%E3%82%B8-tableview-%E7%94%BB%E5%83%8F%E8%A1%A8%E7%A4%BA%E7%B7%A8/
	// cocos �����Ȃ̂��ڂ��Ă�T�C�g
	// https://iscene.jimdo.com/2015/02/04/cocos2d-x-ver-3-x-c-iphone-android-%E3%81%AE%E9%96%8B%E7%99%BA%E5%9F%BA%E7%A4%8E%E8%AC%9B%E5%BA%A7-%E7%9B%AE-%E6%AC%A1/

 	this->items.clear();
	this->items.pushBack(Label::createWithSystemFont("1", "Arial", 80));
	this->items.pushBack(Label::createWithSystemFont("2", "Arial", 80));
	this->items.pushBack(Label::createWithSystemFont("3", "Arial", 80));
	this->items.pushBack(Label::createWithSystemFont("4", "Arial", 80));

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


	return true;
}

// �A�����W�@��]�Ƃ�
void CharaSelectScene::arrange()
{
	// �~��ɓ��Ԋu�Ŕz�u
	float theta = 360.0f / items.size();
	float baseAngle = this->angle + 270.0f;
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

		this->items.at(i)->setPosition(Vec2(x+420, y+420));
		this->items.at(i)->setScale(scale);
		this->items.at(i)->setOpacity(opacity);
		this->items.at(i)->setZOrder(diameterY - y);
	}
}

// �w�i
void CharaSelectScene::CharaSelectBackGroudn()
{
	// ��ʃT�C�Y�擾
	Size winSize = Director::getInstance()->getVisibleSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	//// �w�i�摜 //////
	CCSprite* pSprite = CCSprite::create("haikei.png");
	// �\�����W�w��
	pSprite->setPosition(ccp(winSize.width / 2, winSize.height / 2));
	// �ǉ�
	this->addChild(pSprite, 0);

	CCSprite* frame = CCSprite::create("frame.png");
	// �\�����W�w��
	frame->setPosition(ccp(400,1150));
	// �ǉ�
	//this->addChild(frame, 0);

	////// �L�����ǉ��@//////
	// ���m
	CCSprite* pl_Attac = CCSprite::create("PL_Attacker.png");
	pl_Attac->setPosition(ccp(120, winSize.height / 2));
	this->addChild(pl_Attac, 2);
	// ��j
	CCSprite* pl_Shield = CCSprite::create("PL_Shield.png");
	pl_Shield->setPosition(ccp(300, winSize.height / 2));
	this->addChild(pl_Shield, 2);
	// ���@�g��
	CCSprite* pl_Magic = CCSprite::create("PL_Magic.png");
	pl_Magic->setPosition(ccp(500, winSize.height / 2));
	this->addChild(pl_Magic, 2);
	// �q�[���[
	CCSprite* pl_Heal = CCSprite::create("PL_Healer.png");
	pl_Heal->setPosition(ccp(680, winSize.height / 2));
	this->addChild(pl_Heal, 2);


	// �^�C�g���z�u
	// �z�u����
	auto lbl_Select = Label::createWithSystemFont("CharaSelect", "HiraKakuProN-W6", 100);
	// �z�u�ꏊ
	lbl_Select->setPosition(Point(origin.x + winSize.width / 2,
		origin.y + winSize.height - lbl_Select->getContentSize().height));

	// Select�ǉ�
	this->addChild(lbl_Select, 1);
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