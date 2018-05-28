#include "GameOver.h"
#include "TitleScene.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "shader/Shaders.hpp"
#include "shader/shaderaction/ChangeColorBy.hpp"

// ���[�f�B���O���
/*�@https://www.indetail.co.jp/blog/cocos2d-x3/ �@*/

USING_NS_CC;

typedef void (GameOver::*SEL_SCHEDULE)(float);

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


	//keyData();
	// ���t���[���Ăяo���@/*�@https://qiita.com/s0hno/items/739b8da8d0ee1375c2cd�@*/
	this->scheduleUpdate();
	//scaling();
	MagicEffect();			// ���@�w�̂��
	//SwordEffect();			// touch�����Ƃ���ɒǏ]�����
	//Ripple();				// �g��
	//Shadow();				// �e
	//test();				// �A���t�@
	//particle();			// �p�[�e�B�N���\��
	//sampleSprite();		// �X�v���C�g�ԂɂȂ��Ă��
	//changeGradation();	// Gradation
	//glowSprite();			// �X�v���C�g�����点��
	//auraEffect();			// �I�[�� �~
	//blur();
	//objExtinctionEffect	// �G�t�F�N�g�������\��
	return true;
}

// �X�V
void GameOver::update(float delta)
{
	keyData();
//	test1();
	
}


//
void GameOver::scaling()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

}

// �e�X�g
void GameOver::test1()
{
	/* http://pierre-net.com/post-717/ */
	// ��ʃT�C�Y�擾
	Size visibleSize = Director::getInstance()->getVisibleSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	// Rect�摜�؂���֐�(�؂�����WX,Y,���A����)
	// �؂�Ă�Ƃ�
	if (keydown_flg == 0)
	{
		Sprite *enemyUp = Sprite::create("Enemy/EM_Zombi.png", Rect(0, 0, 335, 200));
		enemyUp->setColor(Color3B(255,0,0));
		enemyUp->setPosition(visibleSize.width / 2, visibleSize.height / 2 +100);
		this->addChild(enemyUp);
	}
	// �ʏ펞
	else
	{
		Sprite *enemy = Sprite::create("Enemy/EM_Zombi.png");
		enemy->setPosition(visibleSize.width/2 , visibleSize.height/2 );
		this->addChild(enemy);
		
	}
}

void GameOver::keyData()
{
	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* keyEvent) {
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_SPACE)
		{
			keydown_flg = 1;
			cocos2d::log("1");
		}
		else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_0)
		{
			keydown_flg = 0;
			cocos2d::log("0");
		}
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

// �I�[��
void GameOver::auraEffect()
{
	//�摜�T�C�Y�擾
	Size visibleSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	// �摜�o�^
	auto sprite = Sprite::create("HelloWorld.png");
	// �z�u(���S�ʒu)
	sprite->setPosition(visibleSize.width/2 ,visibleSize.height/2);
	
	Vec4 color(0.5f,0.5f,0.5f,1.0f);

	GLfloat ctime  = 1.0f;
	GLfloat gtime  = 1.0f;
	GLfloat radius = 5.0f;

	auto fileUtiles = FileUtils::getInstance();
	auto fragmentFullPath = fileUtiles->fullPathForFilename("shaders/glow.fsh");
	auto fragSource = fileUtiles->getStringFromFile(fragmentFullPath);

	auto glprogram = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, fragSource.c_str());
	auto glProgramState = GLProgramState::getOrCreateWithGLProgram(glprogram);

	glProgramState->setUniformVec4("u_outlineColor", color);
	glProgramState->setUniformFloat("u_ctime", ctime);
	glProgramState->setUniformFloat("u_threshold", gtime);
	glProgramState->setUniformFloat("u_radius", radius);

	sprite->setGLProgramState(glProgramState);

	glProgramState->setUniformCallback("u_outlineColor", CC_CALLBACK_2(GameOver::callbackColor, this));

	addChild(sprite,1);
}

// �G�t�F�N�g���������̂��
void GameOver::objExtinctionEffect()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	CCParticleExplosion* p = CCParticleExplosion::create(); // �����I�ȃG�t�F�N�g�̏�����
	p->setDuration(0.05);									// �G�t�F�N�g����~����܂ł̎��� 
	p->setScale(0.2f);										// �G�t�F�N�g�傫��
	p->setSpeed(800);										// �G�t�F�N�g�̓�������
	p->setPosition(winSize.width / 2, winSize.height / 2);  // �G�t�F�N�g�̔����n�_
	// �G�t�F�N�g�̕\��
	this->addChild(p, 8); // addChild ����Ƃ����\��
}

// �X�v���C�g�����点��
/* http://brbranch.jp/blog/201607/cocos2d-x/shader/ */
void GameOver::glowSprite()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	// �V�F�[�_�������������}���[�[�[

	// �摜�̒ǉ�(�ω��Ȃ�)
	auto sprite = Sprite::create("HelloWorld.png");
	// ���W�w��
	sprite->setPosition(Vec2(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y - 200));
	// �摜�̒ǉ�(�ω�����)
	auto spr2 = Sprite::create("HelloWorld.png");
	// ���W�w��
	spr2->setPosition(Vec2(winSize.width / 2, winSize.height / 2 + origin.y + 200));


	auto change = ChangeColorBy::create(ChangeColorType::HSV, Vec3(1.0, -1.0, 1.0), false, 1.0);
	sprite->runAction(Sequence::create(DelayTime::create(5.0), change, FadeOut::create(0.5), NULL));
	{
		// shader�̍쐬
		// �Ăяo��(shader�t�@�C���̓ǂݍ���)
		auto readShader = GLProgram::createWithByteArrays(cocos2d::LightHsvShaderVert, cocos2d::LightHsvShaderFrag);
		auto state = GLProgramState::getOrCreateWithGLProgram(readShader);
		// ���ײĂɐݒ�
		spr2->setGLProgramState(state);
		// �ϐ��̐ݒ�(u_color���ɐݒ肳����)
		state->setUniformVec3("u_color", Vec3(0.0, 0.0, 0.0));
	}

	// �ǉ�
	this->addChild(sprite, 0);
	this->addChild(spr2, 1);
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
	auto lbl_Select = Label::createWithSystemFont("Nemui!!!!!!!!!!!!!!!!!!", "HiraKakuProN-W6", 100);
	// �z�u�ꏊ
	lbl_Select->setPosition(Point(origin.x + winSize.width / 2,origin.y + winSize.height - lbl_Select->getContentSize().height));

	// Select�ǉ�
	this->addChild(lbl_Select, 1);

	//// player�\��
	//Sprite *plyaer = Sprite::create("EM_Zombi.png");
	//plyaer->setPosition(winSize.width/2,winSize.height/2-100);
	//addChild(plyaer,1);
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
	// ��ʃT�C�Y�擾
	Size winSize = Director::getInstance()->getVisibleSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	// ���@�w�̂���܂����I�I
	// �Ԃ��ĉ��s�\��
	Node *fram = Node::create();
	fram->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	fram->setPosition(winSize.width / 2-200, winSize.height / 2 -450);
	fram->setScaleY(0.5);
	this->addChild(fram);
	// ���@�w
	Sprite *magic = Sprite::create("sample1.png");						// �摜�ǂݍ���
	magic->setAnchorPoint(Vec2::ANCHOR_MIDDLE);							// �I�u�W�F�N�g�̊�_�𒆐S��
	magic->setPosition(winSize.width/2-200, winSize.height/2 -450);		// ���W�Z�b�g
	magic->setScale(0.0f);												// �傫���Z�b�g

	// �X�v���C�g�����点��
	auto change = ChangeColorBy::create(ChangeColorType::HSV, Vec3(1.0, -1.0, 1.0), false, 1.0);
	magic->runAction(Sequence::create(DelayTime::create(1.0), change, FadeOut::create(0.5), NULL));
	{
		// shader�̍쐬
		// �Ăяo��(shader�t�@�C���̓ǂݍ���)
		auto readShader = GLProgram::createWithByteArrays(cocos2d::LightHsvShaderVert, cocos2d::LightHsvShaderFrag);
		auto state = GLProgramState::getOrCreateWithGLProgram(readShader);
		// ���ײĂɐݒ�
		magic->setGLProgramState(state);
		// �ϐ��̐ݒ�(u_color���ɐݒ肳����)
		state->setUniformVec3("u_color", Vec3(0.0, 0.0, 0.0));
	}

	fram->addChild(magic,0);

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
	magic->setColor(Color3B(0, 255, 90));

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
//�@�@https://qiita.com/edo_m18/items/c2db0bc42dcc59975889
void GameOver::SwordEffect()
{
	static int streak_tag   = 1000;		// �w����ޗp
	static int streak_layer = 10000;	// ����ڲ԰

	// ����
	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	// touch����
	listener->onTouchBegan = [this](Touch *touch, Event *event) -> bool {
		this->removeChildByTag(streak_tag);		// removeChildByTag:�I�u�W�F�N�g�̍폜�p
		// �g�p����摜�̓o�^
		// MotionStreak�N���X�O�Օ\���p(�g�p����ƌ��̋O�ՃG�t�F�N�g�\����)
		// �t�F�[�h���ԁA�\�����n�܂邽�߂̈ړ����x�A�摜�T�C�Y�A�F�A�t�@�C��
		auto streak = MotionStreak::create(fadeSpeed, startSpeed, imageSize, Color3B(200, 200, 250), "sample.png");
		// ���Z�̃u�����h�ݒ� ADDITIVE{G_SRC_ALPHA,GL_ONE}
		streak->setBlendFunc(BlendFunc::ADDITIVE);
		// ���W�Z�b�g
		streak->setPosition(800, 1200);
		// �ǉ�
		this->addChild(streak, streak_layer, streak_tag);
		return true;
	};
	listener->onTouchMoved = [=](Touch *touch, Event *event) {
		auto streak = (MotionStreak*)this->getChildByTag(streak_tag);
		streak->setPosition(touch->getLocation());
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}
// �g��̂�[��
void GameOver::Ripple()
{
	//	�F�̉��Z���� �ォ������イ������

	// �g��̃X�s�[�h
	unsigned int rippleSpeed  = 7;
	// ���S�̔g��̃X�s�[�h
	unsigned int rippleCenter = 500;

	Ripple3D* action;
	// �X�v���C�g���쐬
	Sprite *fish = Sprite::create("sample.png");
	fish->setPosition(Vec2(320, 568));

	// �g����L����A�j���[�V�����쐬()�@
	//CCRipple3D::create ((float)����,(CCSize)�O���b�h�T�C�Y,(CCPoint)�g��̒��S�ʒu,(float)���a,(int)�g�̐�,(float)�U�� );
	
	action = Ripple3D::create(10, cocos2d::Size(150, 150), Vec2(640 / 2, 1136 / 2), rippleCenter, rippleSpeed, 100);
	// NodeGrid�쐬
	NodeGrid *nodeGrid = NodeGrid::create();
	nodeGrid->addChild(fish);
	nodeGrid->runAction(action);

	this->addChild(nodeGrid);
}
// �ۂ��e
void GameOver::Shadow()
{
	//// ��ʃT�C�Y�擾
	//Size VisibleSize = Director::getInstance()->getVisibleSize();
	//// �h��Ԃ����~�i���傫�ȓ_�j
	//DrawNode *dot = DrawNode::create();
	//dot->drawDot(Vec2::ZERO, 50, Color4F::YELLOW);
	//dot->setPosition(VisibleSize.width/2,VisibleSize.height/2 + 200);
	//this->addChild(dot,2);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	Size winSize = Director::getInstance()->getWinSize();

	//cocos2dx�̉摜
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	sprite->setScale(1.5f, 3.0f);
	this->addChild(sprite, 0);

	////�����l�p�`�X�v���C�g
	Sprite* shadowSprite = Sprite::create();
	shadowSprite->setTextureRect(Rect(0.0f, 0.0f, winSize.width, winSize.height));
	shadowSprite->setColor(Color3B::BLACK);
	shadowSprite->setOpacity(200);
	shadowSprite->setPosition(Point(winSize.width / 2, winSize.height / 2));
	//this->addChild(shadowSprite, 1);

	//�؂蔲���~��`��
	DrawNode *light = DrawNode::create();
	light->drawDot(Point(winSize.width / 2, winSize.height / 2), 100, Color4F::WHITE);

	//�N���b�s���O�쐬
	ClippingNode* clipping = ClippingNode::create();
	clipping->setStencil(light);						//�؂蔲���͈͂�ݒ�
	clipping->addChild(shadowSprite);					//�N���b�s���O�̏�ɐ؂蔲��Sprite��z�u
	clipping->setInverted(true);						//�؂蔲���������ȊO��\�����邩(true)�؂蔲����������\�����邩(false)
	clipping->setAlphaThreshold(0.1f);					//�A���t�@�̂������l��ݒ�
	this->addChild(clipping, 1);
}

// grow�\��
/* https://qiita.com/isaoeka/items/dee8159e2a0c2a37a662�@*/
bool GameOver::glow()
{
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(winSize.width / 2, winSize.height / 2);

	Vec4 color(0.5f, 0.5f, 0.5f, 1.0f);

	m_ctime = 0.01f;  // �����o�ϐ�
	GLfloat gtime = 1.0f;
	GLfloat radius = 5.0f;

	auto fileUtiles = FileUtils::getInstance();

	auto fragmentFullPath = fileUtiles->fullPathForFilename("shader/shaders/glow.fsh");
	auto fragSource = fileUtiles->getStringFromFile(fragmentFullPath);

	auto glprogram = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, fragSource.c_str());
	auto glProgramState = GLProgramState::getOrCreateWithGLProgram(glprogram);

	glProgramState->setUniformVec4("u_outlineColor", color);
	glProgramState->setUniformFloat("u_ctime", m_ctime);
	glProgramState->setUniformFloat("u_threshold", gtime);
	glProgramState->setUniformFloat("u_radius", radius);

	sprite->setGLProgramState(glProgramState);

	glProgramState->setUniformCallback("u_ctime", CC_CALLBACK_2(GameOver::callbackColor, this));

	this->addChild(sprite, 3);

	return false;
}
void GameOver::callBackTime(GLProgram * glProgram, Uniform * uniform)
{
	m_ctime += 0.05;
	glProgram->setUniformLocationWith1f(uniform->location,(sin(m_ctime) + 1 ) / 2);
}
void GameOver::callbackColor(GLProgram* glProgram, Uniform* uniform)
{
	float r = CCRANDOM_0_1();
	float g = CCRANDOM_0_1();
	float b = CCRANDOM_0_1();
	float a = 1.0f;

	glProgram->setUniformLocationWith4f(uniform->location, r, g, b, a);
}

void GameOver::test()
{
	//CCSize size = CCDirector::sharedDirector()->getWinSize();

	//CCLayerColor* background = CCLayerColor::create(ccc4(0, 255, 0, 255), size.width, size.height);
	//this->addChild(background, 10);

	//CCLayerColor* foreground = CCLayerColor::create(ccc4(0, 0, 255, 127), size.width, size.height);
	//this->addChild(foreground, 20);

	//ccBlendFunc blend;
	//blend.src = GL_SRC_ALPHA;
	//blend.dst = GL_ONE_MINUS_SRC_ALPHA;

	//foreground->setBlendFunc(blend);



	/*Size size = Director::getInstance()->getVisibleSize();
	Vec2 orizin = Director::getInstance()->getVisibleOrigin();
	CCLayerColor* mask = CCLayerColor::create(ccc4(0, 0, 0, 128), size.width, size.height);
	this->addChild(mask, 30);

	srand((unsigned int)time(NULL));

	CCDrawNode* dot = CCDrawNode::create();
	dot->drawDot(ccp(rand() % (int)size.width, rand() % (int)size.height), rand() % 100, ccc4f(1, 1, 1, 1));
	dot->drawDot(ccp(rand() % (int)size.width, rand() % (int)size.height), rand() % 100, ccc4f(1, 1, 1, 1));
	dot->drawDot(ccp(rand() % (int)size.width, rand() % (int)size.height), rand() % 100, ccc4f(1, 1, 1, 1));
	dot->drawDot(ccp(rand() % (int)size.width, rand() % (int)size.height), rand() % 100, ccc4f(1, 1, 1, 1));
	dot->drawDot(ccp(rand() % (int)size.width, rand() % (int)size.height), rand() % 100, ccc4f(1, 1, 1, 1));
	dot->drawDot(ccp(rand() % (int)size.width, rand() % (int)size.height), rand() % 100, ccc4f(1, 1, 1, 1));
	dot->drawDot(ccp(rand() % (int)size.width, rand() % (int)size.height), rand() % 100, ccc4f(1, 1, 1, 1));
	dot->drawDot(ccp(rand() % (int)size.width, rand() % (int)size.height), rand() % 100, ccc4f(1, 1, 1, 1));
	this->addChild(dot, 40);

	ccBlendFunc blend;
	blend.src = GL_DST_COLOR;
	blend.dst = GL_ONE;

	dot->setBlendFunc(blend);*/


}

// �p�[�e�B�N���\��
/*void GameOver::particle()
{
	// �ԉ�
	CCParticleFireworks* pParticle = CCParticleFireworks::createWithTotalParticles(1000);
	// ����
	CCParticleExplosion* pParticle = CCParticleExplosion::createWithTotalParticles(1000);
	// ��
	CCParticleSnow* pParticle	   = CCParticleSnow::createWithTotalParticles(1000);
	// �J
	CCParticleRain* pParticle	   = CCParticleRain::createWithTotalParticles(1000);
	// ��
	CCParticleSmoke* pParticle	   = CCParticleSmoke::createWithTotalParticles(1000);
	// ��
	CCParticleFire* pParticle	   = CCParticleFire::createWithTotalParticles(1000);
	// ��
	CCParticleFlower* pParticle    = CCParticleFlower::createWithTotalParticles(1000);
	// ���
	CCParticleGalaxy* pParticle    = CCParticleGalaxy::createWithTotalParticles(1000);
	// �Q��
	CCParticleSpiral* pParticle    = CCParticleSpiral::createWithTotalParticles(1000);
	// ����
	CCParticleMeteor* pParticle    = CCParticleMeteor::createWithTotalParticles(1000);
	// ���z
	CCParticleSun* pParticle	   = CCParticleSun::createWithTotalParticles(1000);

	// �ǉ�
	this->addChild(pParticle,0);
}*/

//CCActionInterval* MyTownTopScene::getAddAction(float base,float scale)
//{
//	CCFadeIn *ac_fadein = CCFadeIn::create(0);
//	CCScaleTo *ac_scale1 = CCScaleTo::create(0.2,scale);
//	CCScaleTo *ac_scale2 = CCScaleTo::create(0.2,base);
//
//	CCFiniteTimeAction *seq = CCSequence::create(ac_fadein, ac_scale1, ac_scale2,NULL);
//	// �����
//	CCActionInterval *action = static_cast<CCActionInterval*>(seq);
//}

// �X�v���C�g�ԂɂȂ��Ă��
//�@https://www.drjiro.com/game-engine/cocos2dx/sprite/
void GameOver::sampleSprite()
{
	// ��ʃT�C�Y�擾
	Size visibleSize = Director::getInstance()->getVisibleSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();
	// �X�v���C�g���쐬����B
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	sprite->setColor(Color3B(255, 0, 0));

	// �X�v���C�g���V�[���ɒǉ�����B
	this->addChild(sprite, 0);
}

// Gradation
//�@http://surfrog.net/2016/04/20/cocos2dgradient/
void GameOver::changeGradation()
{
	// ��ʃT�C�Y�擾
	Size visibleSize = Director::getInstance()->getVisibleSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();

	static float thete = 0.0f;	// Gradation�ύX���x�p
	thete += 0.05;				// �ǉ����x�X�V
	GLubyte cener = 128, widh = 127;			// �F�̊�l�Ƒ����n

	GLubyte r = sin(thete)* widh +cener;						// �Ԑ���
	GLubyte g = sin(thete + 2.0f / 3.0f*M_PI) *widh + cener;	// �ΐ���
	GLubyte b = sin(thete + 4.0f / 3.0f*M_PI) *widh + cener;	// ����

	//_layer - &gt; setColor(Color3B(r, g, b));	// �F�̍X�V
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	sprite->setColor(Color3B(r,g,b));

	this->addChild(sprite, 0);
}




