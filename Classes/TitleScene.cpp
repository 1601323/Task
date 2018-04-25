#include "TitleScene.h"
#include "DiffSelectScene.h"
//�����Ȃ炷���߂�include
#include "SimpleAudioEngine.h"

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
	startButton->setPosition(Point(winSize.width/2,winSize.height/2));
	// ���j���[�쐬(����obj)
	auto menu = Menu::create(startButton,NULL);
	menu->setPosition(Point::ZERO);
	// �ǉ�
	this->addChild(menu,1);
	
	return true;
}

// �w�i
void TitleScene::TitleBackGroudn()
{
	// ��ʃT�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`���]�����[�V�����Ή����ǂ��Ƃ�
	Point origin = Director::getInstance()->getVisibleOrigin();

	//// �o�b�N�J���[
	//auto groundCollar = LayerColor::create(Color4B::BLUE,winSize.width,winSize.height);
	//// �o�b�N�O�����hCollar��2:�\����
	//this->addChild(groundCollar,0);

	// �^�C�g���z�u
	// �z�u����
	auto lbl_Title = Label::createWithSystemFont("Title","HiraKakuProN-W6",100);
	// �z�u�ꏊ
	lbl_Title->setPosition(Point(origin.x+winSize.width/2,
								 origin.y+winSize.height - lbl_Title->getContentSize().height));
	// Title�ǉ�
	this->addChild(lbl_Title,1);

	// �w�i�摜�ǉ�
	Sprite* bgsprite = Sprite::create("Title.png");
	// �\�����W�w��
	bgsprite->setPosition(ccp(320, 190));
	this->addChild(bgsprite,0);
}

// ��ʑJ��
void TitleScene::pushStart(Ref *pSender)
{
	// log�\��
	CCLOG("Push�{�^��");

	// �J�ڍ�̉�ʂ�ݽ�ݽ
	Scene *pScene = DiffSelectScene::createScene();

	/* 0.5�b�����Ď���ʂɑJ��
	// (����,�J�ڐ�,�F(�I�v�V����))
	//TransitionFade *transition = TransitionFade::create(0.6, pScene);
	// �J�ڎ��s �A�j���[�V����
	Director::getInstance()->replaceScene(transition);*/

	// �͗l�����炾�񂾂�...
	Director::getInstance()->replaceScene(TransitionFadeTR::create(0.7f, DiffSelectScene::createScene()));
	CCDirector::sharedDirector()->replaceScene(CCTransitionFadeTR::create(2.0f, DiffSelectScene::createScene()));


}
