#include "DiffSelectScene.h"
#include "CharaSelectScene.h"

Scene *DiffSelectScene::createScene()
{
	auto scene = Scene::create();
	auto layer = DiffSelectScene::create();
	scene->addChild(layer);
	return scene;
}

// ������
bool DiffSelectScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	// �o�b�N�O�����h
	SelectBackGroudn();

	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();

	// �{�^���z�u (�ʏ펞,��������)
	// ���������̱����
	auto diffButton = MenuItemImage::create("01.png", "02.png", CC_CALLBACK_1(DiffSelectScene::pushStart, this));
	auto EasyButton = MenuItemImage::create("03.png", "04.png", CC_CALLBACK_1(DiffSelectScene::pushStart, this));

	// �{�^���̔z�u
	diffButton->setPosition(Point(winSize.width / 2 + 80, winSize.height / 2));
	EasyButton->setPosition(Point(winSize.width / 2 - 80, winSize.height / 2));

	// ���j���[�쐬(����obj)
	auto menu1 = Menu::create(diffButton, NULL);
	auto menu2 = Menu::create(EasyButton, NULL);
	menu1->setPosition(Point::ZERO);
	menu2->setPosition(Point::ZERO);

	// �ǉ�
	this->addChild(menu1, 1);
	this->addChild(menu2, 2);

	return true;
}

// 

// �w�i
void DiffSelectScene::SelectBackGroudn()
{
	// �w�i
	// �T�C�Y�擾
	CCSize rightSize = CCDirector::sharedDirector()->getWinSize();
	// �摜�w��
	CCSprite* pSprite = CCSprite::create("haikei.png");
	// �\�����W�w��
	pSprite->setPosition(ccp(rightSize.width / 2, rightSize.height / 2));
	// �ǉ�
	this->addChild(pSprite, 0);

	// ���w�i�̂��
	//CCSize rightSize = CCDirector::sharedDirector()->getWinSize();
	//CCSprite* pSprite = CCSprite::create("miku.png");
	//pSprite->setPosition(ccp(rightSize.width/2,rightSize.height/2));
	//pSprite->setOpacity(85);
	//this->addChild(pSprite,1);
	// �������ܰ�
	//CCActionInterval* actionRate = CCRotateBy::create(4.0f,360);
	//CCRepeatForever*  actionRepeatForver = CCRepeatForever::create(actionRate);
	//pSprite->runAction(actionRepeatForver);

	// ��ʃT�C�Y�擾
	Size winSize = Director::getInstance()->getVisibleSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	// �^�C�g���z�u
	// �z�u����
	auto lbl_Select = Label::createWithSystemFont("Select", "HiraKakuProN-W6", 100);
	// �z�u�ꏊ
	lbl_Select->setPosition(Point(origin.x + winSize.width / 2,
								  origin.y + winSize.height - lbl_Select->getContentSize().height));

	// Select�ǉ�
	this->addChild(lbl_Select, 2);

	// �L�����\��
	// �摜�w��
	CCSprite* pPlayer = CCSprite::create("Player.png");
	// �\�����W�w��
	pPlayer->setPosition(ccp(rightSize.width / 2, rightSize.height / 2));
	// �ǉ�
	this->addChild(pPlayer, 1);

}

// ��ʑJ��
void DiffSelectScene::pushStart(Ref * pSender)
{
	CCLOG("Push�{�^��");

	// �J�ڍ�̉�ʂ�ݽ�ݽ
	Scene *pScene = CharaSelectScene::createScene();

	// 0.6�b�����Ď���ʂɑJ��
	// (����,�J�ڐ�,�F(�I�v�V����))
	TransitionFade *transition = TransitionFade::create(0.6, pScene);

	// �J�ڎ��s �A�j���[�V����
	Director::getInstance()->replaceScene(transition);
}