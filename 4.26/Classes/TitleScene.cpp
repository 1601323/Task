#include "TitleScene.h"
#include "DiffSelectScene.h"
#include "CharaSelectScene.h"
#include "GameOver.h"
#include "TopScroll.h"

const int DIV_NUM = 4;
const int DIV_ANGLE = 360 / DIV_NUM;
const int DIV_ANGLE_HALF = DIV_ANGLE / 2;

// �p�x����
const unsigned int RADIUS		   = 210;
const float PI					   = 3.14159265359f;
const float FLATTEN_RATE		   = 0.4f;
const unsigned int PL_POS_OFFSET_X = 420;		// �v���C���[�\���̃I�t�Z�b�g
const unsigned int PL_POS_OFFSET_Y = 820;		// �v���C���[�\���̃I�t�Z�b�g

// �g�啝
const float LIMIT_TIME			   = 0.9f;		// �b�w��[�߂��]
const float DOUBLE_SCALE		   = 0.5f;		// ���{��[�g�嗦�w��]
const float WAIT_TIME			   = 0.6f;		// �ҋ@����
const float BOX_SCALE			   = 0.9;		// �`�[���Ґ��p��BOX�̊g�嗦


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
	
	ActSelectDraw();			// �L�����\��
	SwipeRotation();		// �X���C�v�ɍ��킹�ĉ�]

	return true;
}

// �s���I��\��
void TitleScene::ActSelectDraw()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	_Attack  = Sprite::create("UI/Command/UI_Button_Attack01.png");
	_Defence = Sprite::create("UI/Command/UI_Button_Defence01.png");
	_Item	 = Sprite::create("UI/Command/UI_Button_Item01.png");
	_Skill	 = Sprite::create("UI/Command/UI_Button_Skill01.png");

	this->items.clear();
	this->items.push_back(_Attack);
	this->items.push_back(_Defence);
	this->items.push_back(_Item);
	this->items.push_back(_Skill);

	// �I������ĂȂ���

	//if ()
	//{

	//}

	// �z�u
	for (auto& item :items)
	{
		this->addChild(item,0);
	}
	this->angle = 0.0f;
	this->Arrange();
}

void TitleScene::Arrange()
{
	// �c�ɉ��悤�Ȃ�
	float theta = 360.0f / items.size() + (items.size()/2);
	float baseAngle = this->angle + 100.0;							// ���Z����Ɖ~�̉��s�������
	for (int i = 0; i < items.size(); i++)
	{
		// 270 �x�̈ʒu�����ʂɂ���悤��  
		float angle = theta   * i + baseAngle;
		float radians = angle   * PI / 180.0f;
		float x = RADIUS  * cos(radians);
		float y = RADIUS  * sin(radians) * FLATTEN_RATE;	// �~�̊p�x�΂߂ɂ����
		float radiusY = RADIUS  * FLATTEN_RATE;
		float radiusX = RADIUS  * 0.9;
		float diameterY = radiusY * 2;
		float scale = (radiusX - x) / radiusX;				// y���W�ɉ����ĕω������
		GLubyte opacity = 100- (y + radiusY);

		this->items.at(i)->setPosition(Vec2(x + PL_POS_OFFSET_X, y + PL_POS_OFFSET_Y));
		this->items.at(i)->setScale(scale);
		this->items.at(i)->setOpacity(opacity);
		this->items.at(i)->setZOrder(diameterY - x);
	}
	//���[�Ƃ����(�L�E�ցE`)
	auto tmpVector = items;
	std::sort(tmpVector.begin(), tmpVector.end(), [](const Node* a, const Node* b)
		// ��ɑ傫����true /�@begin > end �����߂ɑ傫�����̗��遁�傫�����ɂȂ�  
	{return a->getScale() > b->getScale(); });
	// TOP�Ɉ�ԑ������̂�����
	Top = tmpVector.front();
}

void TitleScene::SwipeRotation()
{
	// �X���C�v�ɍ��킹�ĉ�]
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	// �N���b�N�����Ƃ�
	listener->onTouchBegan = [](Touch *touch, Event *event) { return true; };
	// �ړ���[�X���C�v]
	listener->onTouchMoved = [&](Touch *touch, Event *event)
	{
		float delta = touch->getLocation().y - touch->getPreviousLocation().y;
		this->angle += delta;
		this->Arrange();
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
		this->Arrange();
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
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
	Sprite* bgsprite = Sprite::create("BackImage/Title.png");
	// �\�����W�w��
	bgsprite->setPosition(winSize.width/2, winSize.height/2);
	//this->addChild(bgsprite,0);
}

// ��ʑJ��
void TitleScene::pushStart(Ref *pSender)
{
	// log�\��
	CCLOG("Push�{�^��");

	// �J�ڍ�̉�ʂ�ݽ�ݽ
	Scene *pScene = CharaSelectScene::createScene();

	/* 0.5�b�����Ď���ʂɑJ��
	// (����,�J�ڐ�,�F(�I�v�V����))
	//TransitionFade *transition = TransitionFade::create(0.6, pScene);
	// �J�ڎ��s �A�j���[�V����
	Director::getInstance()->replaceScene(transition);*/

	// �͗l�����炾�񂾂�...
	Director::getInstance()->replaceScene(TransitionFadeTR::create(0.7f, CharaSelectScene::createScene()));
	CCDirector::sharedDirector()->replaceScene(CCTransitionFadeTR::create(2.0f, CharaSelectScene::createScene()));


}
