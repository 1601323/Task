#include "TitleScene.h"
//�����Ȃ炷���߂�include
#include "SimpleAudioEngine.h"
#include "CharaSelectScene.h"

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
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(TitleScene::pushStart, this));

	// �{�^���̔z�u
	startButton->setPosition(Point(winSize.width / 2, winSize.height / 2));
	// ���j���[�쐬(����obj)
	auto menu = Menu::create(startButton, NULL);
	menu->setPosition(Point::ZERO);
	// �ǉ�
	this->addChild(menu, 1);

	return true;
}

// �w�i
void TitleScene::TitleBackGroudn()
{
	// ��ʃT�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`���]�����[�V�����Ή����ǂ��Ƃ�
	Point origin = Director::getInstance()->getVisibleOrigin();

	// �w�i�摜�ǉ�
	Sprite* bgsprite = Sprite::create("BackImage/Title.png");
	// �\�����W�w��
	bgsprite->setPosition(winSize.width/2,winSize.height/2);
	this->addChild(bgsprite, 0);
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
