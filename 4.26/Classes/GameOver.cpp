#include "GameOver.h"
#include "TitleScene.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene *GameOver::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOver::create();
	scene->addChild(layer);
	return scene;
}

// ������
bool GameOver::init()
{
	if (!Layer::init())
	{
		return false;
	}

	// �o�b�N�O�����h
	ClearBackGroudn();

	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	// �{�^���z�u
	// �ʏ펞,��������
	// ���������̱����
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(GameOver::pushStart, this));

	// �{�^���̔z�u
	startButton->setPosition(50, 1200);
	// ���j���[�쐬(����obj)
	auto menu = Menu::create(startButton, NULL);
	menu->setPosition(Point::ZERO);
	// �ǉ�
	this->addChild(menu, 1);

	// ���@�w�̂��
	//MagicEffect();
	// touch�����Ƃ���ɒǏ]�����
	//SwordEffect();

	LightEffect();
	return true;
}

// �w�i
void GameOver::ClearBackGroudn()
{
	// ��ʃT�C�Y�擾
	Size winSize = Director::getInstance()->getVisibleSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();


	// �^�C�g���z�u
	// �z�u����
	auto lbl_Select = Label::createWithSystemFont("(^^)/", "HiraKakuProN-W6", 100);
	// �z�u�ꏊ
	lbl_Select->setPosition(Point(origin.x + winSize.width / 2,
		origin.y + winSize.height - lbl_Select->getContentSize().height));

	// Select�ǉ�
	this->addChild(lbl_Select, 1);
}

// ��ʑJ��
void GameOver::pushStart(Ref * pSender)
{
	CCLOG("Push�{�^��");

	// �J�ڍ�̉�ʂ�ݽ�ݽ
	Scene *pScene = TitleScene::createScene();

	// 0.6�b�����Ď���ʂɑJ��
	// (����,�J�ڐ�,�F(�I�v�V����))
	TransitionFade *transition = TransitionFade::create(0.6, pScene);

	// �J�ڎ��s �A�j���[�V����
	Director::getInstance()->replaceScene(transition);
}

// ���@�w�\��
void GameOver::MagicEffect()
{
	// ���@�w�̂���܂����I�I
	// �Ԃ��ĉ��s�\��
	Node *fram = Node::create();
	fram->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	fram->setPosition(Director::getInstance()->getVisibleSize() / 2);
	fram->setScaleY(0.5);
	this->addChild(fram);
	// ���@�w
	Sprite *magic = Sprite::create("sample.png");		// �摜�ǂݍ���
	magic->setAnchorPoint(Vec2::ANCHOR_MIDDLE);			// �I�u�W�F�N�g�̊�_�𒆐S��
	magic->setPosition(fram->getContentSize() / 2);		// ���W�Z�b�g
	magic->setScale(0.0f);								// �傫���Z�b�g
	fram->addChild(magic);

	// �A�j���[�V����
	FiniteTimeAction *action1 = Spawn::create(RotateBy::create(0.2f, 90.0f),	/*�޽޽ނ��Ƒ傫��*/
		ScaleTo::create(0.2f, 1.7f), NULL);										/*���񂾂�傫��*/
	FiniteTimeAction *action2 = RotateBy::create(1.5f, 300.0f);					/*��]*/
	FiniteTimeAction *action3 = Spawn::create(RotateBy::create(0.2f, 90.0f),	/*�޽޽ނ��Ƒ傫��*/
		ScaleTo::create(0.2f, 3.0f),											/*���񂾂�傫��*/
		FadeOut::create(0.2f), NULL);											/*̪�ı��*/
																				// �J��Ԃ��Ă�
	CallFunc *reset = CallFunc::create([magic]() {
		// ���s�[�g�ׂ̈Ƀ��Z�b�g
		magic->setScale(0.0f);
		magic->setOpacity(255);
	});
	// �����̃A�j���[�V������A���ōs��
	magic->runAction(RepeatForever::create(Sequence::create(action1,
		action2,
		action3,
		reset,
		DelayTime::create(1.0f), NULL)));		// ��莞�Ԍ�ɐ���
}
// �񕜕\��
void GameOver::RecoveryEffect()
{
	// ��ʃT�C�Y�擾
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 orizin		 = Director::getInstance()->getVisibleOrigin();

	// �X�v���C�g���[�Ƃ̏���a
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites.plest");
	
	// �摜�̕\��
	Sprite* sprite = Sprite::createWithSpriteFrameName("effect_cure01_0000.png");
}
// touch�����Ƃ���ɒǏ]�����
void GameOver::SwordEffect()
{
	static int streak_tag = 1000;
	static int streak_layer = 10000;
	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [this](Touch *touch, Event *event) -> bool {
		this->removeChildByTag(streak_tag);

		auto streak = cocos2d::MotionStreak::create(0.8f, 1, 20, Color3B(200, 200, 250), "sample.png");
		streak->setBlendFunc(BlendFunc::ADDITIVE);
		streak->setPosition(800, 1200);
		this->addChild(streak, streak_layer, streak_tag);
		return true;
	};
	listener->onTouchMoved = [=](Touch *touch, Event *event) {
		auto streak = (cocos2d::MotionStreak*)this->getChildByTag(streak_tag);
		streak->setPosition(touch->getLocation());
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

//
void GameOver::LightEffect()
{
	auto light = DirectionLight::create(Vec3(-1.0f, -1.0f, 0.0f), Color3B::RED);
	light->setPosition(500,500);
	addChild(light);
}

