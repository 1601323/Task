#include "FightScene.h"
#include "BossScene.h"
//#include "WalkScene.h"
#include "Geometry.h"


#pragma execution_character_set("utf-8")

Scene *FightScene::createScene()
{
	auto scene = Scene::create();
	auto layer = FightScene::create();
	scene->addChild(layer);
	return scene;
}

FightScene::FightScene() {}
FightScene::~FightScene() {}


// ������
bool FightScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();

	_damageDispTime = DAMAGE_DISPLAY_DURATION;
	_damageDispFlag = false;
	_enemyDeathFlg = true;
	_enemyDispFlag = false;
	_exp = EXP;
	_moveFlag = false;
	_hitCount = 0;
	_battleCounter = 1;
	_nextBattleTimer = NEXT_BATTLE_TIMER;

	// �o�b�N�O;�����h
	FightScene::FightBackGroudn();
	//�w�i�e���b�v
	auto _telopBackRect = Rect(0, 0, winSize.width, 100);
	auto _telopBack = Sprite::create();
	_telopBack->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);	//�A���J�[�|�C���g�������
	_telopBack->setTextureRect(_telopBackRect);
	_telopBack->setPosition(0, 1250);
	_telopBack->setColor(Color3B::BLACK);
	_telopBack->setOpacity(TEXT_BOX_OPACITY);
	this->addChild(_telopBack);

	//�e���b�v
	TTFConfig announceTelopConfig(ANNOUNCE_TELOP_LABEL_FONT_PATH, ANNOUNCE_TELOP_FONT_SIZE, GlyphCollection::DYNAMIC);
	announceTelopConfig.distanceFieldEnabled = true; //�����G�t�F�N�g���g�p����
	announceTelop = Label::createWithTTF(announceTelopConfig, "");
	announceTelop->setColor(Color3B::WHITE);
	announceTelop->enableGlow(Color4B::BLACK); //�F��ݒ�
	announceTelop->setPosition(Vec2(winSize.width / 2, 1200));
	this->addChild(announceTelop);
	announceTelop->setString("���������o�g�����n�܂邼�I");


	// �{�^���z�u
	// �ʏ펞,��������
	// ���������̱����
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(FightScene::ChangeBossScene, this));

	// �{�^���̔z�u
	startButton->setPosition(Point(winSize.width , 0));
	// ���j���[�쐬(����obj)
	auto menu = Menu::create(startButton, nullptr);
	menu->setPosition(Point::ZERO);
	// �ǉ�
	this->addChild(menu, 1);


	//�^�b�`�C�x���g-------------------------------------
	// �擾
	auto touchGet = EventListenerTouchOneByOne::create();
	touchGet->onTouchBegan = CC_CALLBACK_2(FightScene::TouchBegan, this);
	touchGet->onTouchMoved = CC_CALLBACK_2(FightScene::TouchMove, this);
	touchGet->onTouchEnded = CC_CALLBACK_2(FightScene::TouchEnd, this);
	//�^�b�`�C�x���g���X�i�[�̓o�^
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchGet, this);

	//�o�g������������
	_battleCounter = 1;

	//�G-------------------------------------------------
	//�G��HP���Z�b�g
	_enemyHpNow = ENEMY_HP_MAX;

	_enemySprite = Sprite::create();
	FightScene::EnemySelector();

	_enemySprite->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(_enemySprite, 0);
	//�G�摜��Rect���擾
	Rect rect;
	_enemySpriteRect = GetSpriteRect(_enemySprite,rect);

	this->scheduleUpdate();	//update�����t���[���Ăяo�����

	//�G�փ����^�b�v�ŗ^����_���[�W�����Z�b�g
	_giveDamage = INIT_GIVE_DAMAGE;

	//----------------------------------------------------

	////Label�N���X�̏�����
	//label = Label::create("�����񂾂�", "Arial", 40);
	////���W���w��
	//label->setPosition(Point(100,winSize.height-100));

	////����������
	//str = String::createWithFormat("Score : %d", giveDamage);
	////������������Label�ɐݒ�
	//label->setString(str->getCString());

	////�V�[���ɒǉ�
	//this->addChild(label);
	

	//auto draw = DrawNode::create();
	////���_���W�ݒ�
	//std::vector<Vec2>vecs;
	//vecs.push_back(Vec2(-300,  335));
	//vecs.push_back(Vec2(-300, -335));
	//vecs.push_back(Vec2(300,  -335));
	////drawPolygon( ���_���W�i�[�z�� , ���_�� , �F );
	//draw->drawPolygon(&vecs[0], 3, Color4F::WHITE, 1, Color4F::YELLOW);
	//draw->setPosition(Vec2(winSize.width / 2, winSize.height / 2));

	//auto clipping = ClippingNode::create();
	//clipping->setStencil(draw);
	//clipping->setInverted(false);
	//clipping->setAlphaThreshold(1.0);
	//addChild(clipping);

	//auto sprite = Sprite::create("HelloWorld.png");
	//sprite->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	//clipping->addChild(sprite);

	//auto text = Label::createWithSystemFont("Touch Layer", "arial", 48);
	//text->setPosition(Point(300, 200));
	//this->addChild(text);


	//�f�o�b�O�p
	auto skipButton = MenuItemImage::create("skipButton1.png", "skipButton2.png", CC_CALLBACK_0(FightScene::Skip, this));
	skipButton->setPosition(Point(100,100));
	auto skipMenu = Menu::create(skipButton, nullptr);
	skipMenu->setPosition(Point::ZERO);
	this->addChild(skipMenu, 1);

	FightScene::SpriteSwayUpDown(_enemySprite);
	FightScene::DrawChangeBossSceneMenu();
	return true;
}

//�i�f�o�b�O�p�j�X�L�b�v�{�^���̐ݒ�
void FightScene::Skip() {
	_enemyHpNow = ENEMY_HP_MAX;
	_battleCounter = BATTLE_MAX;
	_enemyDeathFlg = true;
	_enemyDispFlag = false;
	_nextBattleTimer = NEXT_BATTLE_TIMER;
	FightScene::ExpGetAnnounce();
	FightScene::EnemySelector();
}

// �w�i
void FightScene::FightBackGroudn()
{
	// ��ʃT�C�Y�擾
	Size winSize = Director::getInstance()->getVisibleSize();
	// �}���`�ꂼ�[�����Ή���
	Point origin = Director::getInstance()->getVisibleOrigin();
	// �w�i
	auto backGroundSprite = Sprite::create(BACK_GRAND_SPRITE_PATH);
	//������
	backGroundSprite->setPosition(Vec2(winSize.width / 2, winSize.height / 2));


	this->addChild(backGroundSprite, 0);

}


//�G�֗^�����_���[�W���l��\��
void FightScene::GiveDamageDisplay(unsigned int giveDamage)
{
	TTFConfig ttfConfigEffect(DAMAGE_LABEL_FONT_PATH, GIVE_ENEMY_DAMAGE_FONT_SIZE, GlyphCollection::DYNAMIC);
	ttfConfigEffect.distanceFieldEnabled = true; //�����G�t�F�N�g���g�p����
	damageLabel = Label::createWithTTF(ttfConfigEffect, "-" + StringUtils::toString(giveDamage));

	damageLabel->setColor(Color3B::RED);
	damageLabel->enableGlow(Color4B::BLACK); //�F��ݒ�

	/***** ������������}�W�b�N�i���o�[���߂Ȃ̋����ā�****/
	int num1 = random(0, 200) - 100;
	int num2 = random(0, 100) - 50;
	damageLabel->setPosition(Vec2(400 + num1, 760 + num2));
	damageLabel->enableShadow(Color4B::BLACK, Size(-2, -4), 2);
	this->addChild(damageLabel);

	int num3 = random(0, 50) - 25;
	auto *up = MoveBy::create(0.3f, Vec2(num3, 15));
	auto *fadeout = FadeOut::create(0.3f);
	auto seq = Sequence::create(up, fadeout, nullptr);
	damageLabel->runAction(seq);
}

/***** ������������}�W�b�N�i���o�[���߂Ȃ̋����ā�****/
//HIT���l��\��
void FightScene::HitDisplay() {

	TTFConfig ttfConfigEffect(DAMAGE_LABEL_FONT_PATH, 60, GlyphCollection::DYNAMIC);
	ttfConfigEffect.distanceFieldEnabled = true; //�����G�t�F�N�g���g�p����
	
	int offset = 0;
	if (_hitCount < 8) 
	{
		offset = _hitCount*60;
	}
	else if (_hitCount > 8) 
	{
		offset = (int)(_hitCount % 8) * 60;
	}

	hitLabel = Label::createWithTTF(ttfConfigEffect, StringUtils::toString(_hitCount) + "HIT!");
	hitLabel->setColor(Color3B::RED);
	hitLabel->setPosition(Vec2(650 , 600 + offset));
	hitLabel->enableGlow(Color4B::WHITE); //�F��ݒ�
	this->addChild(hitLabel);

	FightScene::ScalingAndFadeout(hitLabel, 0.1f, 1.5f, 0.1f, 1.0f, 2.0f, 0.4f);
	//hitLabel->pause();
	//virtual
}

//void FightScene::DrawGlowLabel(const char *fontFilePath, Vec2 &position, std::string& text, Color3B textCololr, int fontSize, Color4B glowColor) {
//	TTFConfig ttfConfigEffect(fontFilePath, fontSize, GlyphCollection::DYNAMIC);
//	ttfConfigEffect.distanceFieldEnabled = true; //�����G�t�F�N�g���g�p����
//
//	auto label = Label::createWithTTF(ttfConfigEffect, text);
//
//	label->setColor(textCololr);
//	label->setPosition(position);
//	label->enableGlow(glowColor); //�F��ݒ�
//	this->addChild(label);
//
//}


//�������g��k���̌�Ƀt�F�[�h�A�E�g����A�j���[�V����
//ScalingAndFadeout(���x��, ���b�����Ċg�傷�邩, ���{�Ɋg�傷�邩, ���b�����ďk�����邩, ���{�ɏk����, ���b�ԕ\�������邩, �t�F�[�h�A�E�g�͉��b�����čs����)
void FightScene::ScalingAndFadeout(Label* label, float largeTime, float multiple, float backTime, float backMultiple, float delay, float fadeOutTime) {
	auto enlargement = ScaleTo::create(largeTime, multiple);		//�@�g��
	auto reducing = ScaleTo::create(backTime, backMultiple);		//�A�k��
	auto displayTime = DelayTime::create(delay);					//�B�\������
	auto fadeout = FadeOut::create(fadeOutTime);					//�C�t�F�[�h�A�E�g
	auto seq = Sequence::create(enlargement, reducing, displayTime, fadeout, NULL);
	label->runAction(seq);
}


//���ȂɃo�g���ڂł���[�I���Ă��������\�L
void FightScene::BattleAnnounce() {
	Label* battleLabel;
	Label* battleCntLabel;
	Vec2 battleLabel_pos;
	Vec2 battleCntLabel_pos;

	TTFConfig ttfConfigEffect(BAL_FONT_PATH, BATTLE_LABEL_FONT_SIZE, GlyphCollection::DYNAMIC);
	ttfConfigEffect.distanceFieldEnabled = true;

	unsigned int labelSize = (_battleCounter == BATTLE_MAX) ? BATTLE_LABEL_FONT_SIZE : BNL_FONT_SIZE;
	TTFConfig ttfConfigEffect2(BAL_FONT_PATH, labelSize, GlyphCollection::DYNAMIC);
	ttfConfigEffect2.distanceFieldEnabled = true;
	
	//�o�g���T�ȉ��ƍŌ�̃o�g���ł̓t�H���g�T�C�Y�ƃ|�W�V�������قȂ�
	if (_battleCounter < BATTLE_MAX)
	{
		battleLabel		   = Label::createWithTTF(ttfConfigEffect, "Battle");
		battleCntLabel	   = Label::createWithTTF(ttfConfigEffect2, StringUtils::toString(_battleCounter));
		battleLabel_pos	   = Vec2(OTHER_BL_POS_X,  OTHER_BL_POS_Y );
		battleCntLabel_pos = Vec2(OTHER_BNL_POS_X, OTHER_BNL_POS_Y);
	}
	else if (_battleCounter == BATTLE_MAX)
	{
		battleLabel		   = Label::createWithTTF(ttfConfigEffect, "Final");
		battleCntLabel	   = Label::createWithTTF(ttfConfigEffect2, "Battle");
		battleLabel_pos	   = Vec2(FINAL_BL_POS_X,  FINAL_BL_POS_Y );
		battleCntLabel_pos = Vec2(FINAL_BNL_POS_X, FINAL_BNL_POS_Y);
	}

	//battleLabel->enableGlow(Color4B::WHITE);
	battleLabel->enableShadow(Color4B::WHITE, Size(-2, -4), 2);
	battleLabel->setColor(Color3B::BLACK);
	battleLabel->setPosition(battleLabel_pos);

	//battleCntLabel->enableGlow(Color4B::WHITE);
	battleCntLabel->enableShadow(Color4B::WHITE, Size(-2, -4), 2);
	battleCntLabel->setColor(Color3B::BLACK);
	battleCntLabel->setPosition(battleCntLabel_pos);

	this->addChild(battleLabel);
	this->addChild(battleCntLabel);

	//�����̃��x�������������\����
	battleLabel->setOpacity(0.0f);
	battleCntLabel->setOpacity(0.0f);

	//@param bl battleLabel
	//@param bcl battleCntLabel

	//�o�g�����x���p�t�F�[�h�A�E�g�ƃC���̐ݒ�
	auto *bl_fadein = FadeIn::create(BL_FADE_IN_DURATION);
	auto *bl_fadeout = FadeOut::create(BNL_FADE_OUT_DURATION);
	//�o�g���i���o�[���x���p�t�F�[�h�A�E�g�ƃC���̐ݒ�
	auto *bcl_fadein = FadeIn::create(BNL_FADE_IN_DURATION);
	auto *bcl_fadeout = FadeOut::create(BNL_FADE_OUT_DURATION);
	//���̑���move�B�͋��p����
	auto *down = MoveBy::create(BAL_SLIDE_UP_DURATION, Vec2(0,BAL_SLIDE_DOWN_VOLUME));
	auto *up = MoveBy::create(BAL_SLIDE_DOWN_DURATION, Vec2(0, BAL_SLIDE_UP_VOLUME));
	auto *delay = DelayTime::create(BAL_DISPLAY_TIME);
	//Spawn�ŕ����̃A�N�V�����𓯎��Ɏ��s����ݒ���s��
	auto bl_fastMoves = Spawn::createWithTwoActions(bl_fadein, down);
	auto bl_lastMoves = Spawn::createWithTwoActions(bl_fadeout, down);
	auto bcl_fastMoves = Spawn::createWithTwoActions(bcl_fadein, up);
	auto bcl_lastMoves = Spawn::createWithTwoActions(bcl_fadeout, up);
	//���ԂɃA�N�V���������s���邽�߂̐ݒ���s��
	auto battleLabelMoves = Sequence::create(bl_fastMoves, delay, bl_lastMoves, nullptr);
	auto battleCntLabelMoves = Sequence::create(bcl_fastMoves, delay, bcl_lastMoves, nullptr);
	//�A�N�V�����̎��s
	battleLabel->runAction(battleLabelMoves);
	battleCntLabel->runAction(battleCntLabelMoves);
}

// �^�b�`�����u��
bool FightScene::TouchBegan(Touch * touch, Event * event)
{
	//�^�b�`���W���擾
	_touchLocation = touch->getLocation();

	//�G���\������Ă��Ă��AenemySpriteRect�����N���b�N����Ă���΁E�E�E
	if (_enemyDispFlag) 
	{
		//enemySpriteRect�����N���b�N���Ă�����
		if (_enemySpriteRect.containsPoint(_touchLocation))
		{
			FightScene::GiveDamageDisplay(_giveDamage);
			_damageDispFlag = true;
			_damageDispTime = DAMAGE_DISPLAY_DURATION;

			_enemyHpNow -= _giveDamage;		//�G��HP�����炷�^�C�~���O�͎w��b�����u��
			FightScene::SpriteTremble(_enemySprite);
			//�G�摜��Rect���擾
			Rect rect;
			_enemySpriteRect = GetSpriteRect(_enemySprite, rect);

			FightScene::ReloadEnemyHp();	//Hp���X�V
		}
	}

	//�G��Hp��0�ȉ��ɂȂ����Ƃ�
	if (_enemyHpNow <= 0)
	{
		_enemyHpNow = ENEMY_HP_MAX;
		_enemyDeathFlg = true;
		_enemyDispFlag = false;
		_nextBattleTimer = NEXT_BATTLE_TIMER;
		FightScene::ExpGetAnnounce();
		//�o�g�������C���N�������g���Ă���G�̉摜��؂�ւ���
		if (++_battleCounter > 5)
		{
			FightScene::DisplayBossButton();
		}
		FightScene::EnemyHpGageFadeOut();
		FightScene::EnemySelector();
	}



	return true;
}

// �X���C�v��
void FightScene::TouchMove(Touch * touch, Event * event)
{

}

// �w�𗣂����u��
void FightScene::TouchEnd(Touch * touch, Event * event)
{

}


//�摜��U��������
void FightScene::SpriteTremble(Sprite* sprite)
{
	auto *right = MoveBy::create(SPRITE_TREMBLE_SPEED, Vec2(0,SPRITE_DEFLECTION_WIDTH));
	auto *left  = MoveBy::create(SPRITE_TREMBLE_SPEED, Vec2(0, -SPRITE_DEFLECTION_WIDTH));
	auto *up    = MoveBy::create(SPRITE_TREMBLE_SPEED, Vec2(SPRITE_DEFLECTION_WIDTH, 0));
	auto *down  = MoveBy::create(SPRITE_TREMBLE_SPEED, Vec2(-SPRITE_DEFLECTION_WIDTH, 0));
	auto *moves = Sequence::create(right, left, up, down, nullptr);
	sprite->runAction(moves);
}

//�G���㉺�ɂ����Ɨh���
void FightScene::SpriteSwayUpDown(Sprite* sprite)
{
	auto *up	   = MoveBy::create(SPRITE_SWAY_SPEED, Vec2(0, SPRITE_SWAY_DEFLECTION_WIDTH));
	auto *upEase   = EaseInOut::create(up, 2);
	auto *down	   = MoveBy::create(SPRITE_SWAY_SPEED, Vec2(0, -SPRITE_SWAY_DEFLECTION_WIDTH));
	auto *downEase = EaseInOut::create(down, 2);
	auto *moves	   = Sequence::create(upEase, downEase, nullptr);
	sprite->runAction(RepeatForever::create(moves));

}
//�摜��Rect���擾����
Rect FightScene::GetSpriteRect(Sprite* sprite, Rect rect)
{
	 rect = Rect((sprite->getPosition().x - sprite->getContentSize().width / 2) + TOUCH_SPRITE_HITBOX_OFFSET,
				 (sprite->getPosition().y - sprite->getContentSize().height / 2) + TOUCH_SPRITE_HITBOX_OFFSET,
				 sprite->getContentSize().width - TOUCH_SPRITE_HITBOX_OFFSET*2,
				 sprite->getContentSize().height - TOUCH_SPRITE_HITBOX_OFFSET*2);
	 return rect;
}

//�G��Hp�o�[
void FightScene::EnemyHpGage() 
{
	Size winSize = Director::getInstance()->getWinSize();
	//�w�i�Q�[�W
	_backHpRect = Rect(0, 0, HP_GAGE_SIZE_WIDTH, HP_GAGE_SIZE_HEIGHT);
	_backGage = Sprite::create();
	_backGage->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);	//�A���J�[�|�C���g�������
	_backGage->setTextureRect(_backHpRect);
	_backGage->setPosition(winSize.width / 3, 900);
	_backGage->setColor(Color3B::BLACK);
	this->addChild(_backGage);
	//�Q�[�W
	_enemyHpRect = Rect(0, 0, (_enemyHpNow / ENEMY_HP_MAX) * HP_GAGE_SIZE_WIDTH, HP_GAGE_SIZE_HEIGHT);
	_blueGage = Sprite::create();
	_blueGage->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);	//�A���J�[�|�C���g�������
	_blueGage->setTextureRect(_enemyHpRect);
	_blueGage->setPosition(winSize.width / 3, 900);
	_blueGage->setColor(Color3B::BLUE);
	this->addChild(_blueGage);
}

//�G�̃Q�[�W���t�F�[�h�C��������
void FightScene::EnemyHpGageFadeIn() 
{
	//�w�i�Q�[�W
	_backGage->setOpacity(0.0f);												//���������\���Ɂi255�ɂ���ƕ\������j
	auto *redGageDelay = DelayTime::create(BACK_GAGE_DISPLAY_INTERVAL_TIME);	//���b���҂�
	auto redGageFadein = FadeIn::create(BACK_GAGE_FADE_IN_DURATION);			//�t�F�[�h�C��
	auto redGageActs = Sequence::create(redGageDelay, redGageFadein, nullptr);
	_backGage->runAction(redGageActs);
	//�Q�[�W
	_blueGage->setOpacity(0.0f);												 //���������\���Ɂi255�ɂ���ƕ\������j
	auto *blueGageDelay = DelayTime::create(BLUE_GAGE_DISPLAY_INTERVAL_TIME);	//���b���҂�
	auto blueGageFadein = FadeIn::create(BLUE_GAGE__FADE_IN_DURATION);			//�t�F�[�h�C��
	auto blueGageActs = Sequence::create(blueGageDelay, blueGageFadein, nullptr);
	_blueGage->runAction(blueGageActs);
}

//�G�̃Q�[�W���t�F�[�h�A�E�g������
void FightScene::EnemyHpGageFadeOut()
{
	//�ԃQ�[�W
	auto redGageFadeout = FadeOut::create(BACK_GAGE_FADE_OUT_DURATION);
	_backGage->runAction(redGageFadeout);
	//�Q�[�W
	auto blueGageFadeout = FadeOut::create(BULE_GAGE_FADE_OUT_DURATION);
	_blueGage->runAction(blueGageFadeout);
}

void FightScene::EnemyFadeIn()
{
	_enemySprite->setOpacity(0.0f);	//���������\���Ɂi255�ɂ���ƕ\������j
	auto *delay = DelayTime::create(ENEMY_DISPLAY_UNTIL_TIME);
	auto fadein = FadeIn::create(ENEMY_FADEIN_DURATION);
	auto acts = Sequence::create(delay, fadein, nullptr);
	_enemySprite->runAction(acts);
}

//�G��Hp�o�[�����X�V
void FightScene::ReloadEnemyHp() 
{
	_enemyHpRect = Rect(0, 0, _enemyHpNow, HP_GAGE_SIZE_HEIGHT);
	_blueGage->setTextureRect(_enemyHpRect);
}

// Boss��ʂ֑J��
void FightScene::ChangeBossScene(Ref * pSender)
{
	log("Push�{�^��");
	// �J�ڍ�̉�ʂ�ݽ�ݽ
	Scene *pScene = BossScene::createScene();
	// (����,�J�ڐ�,�F(�I�v�V����))
	TransitionFade *transition = TransitionFade::create(CHANGE_FIGHT_SCENE_TO_BOSS_SCENE_DURATION, pScene);
	// �J�ڎ��s �A�j���[�V����
	Director::getInstance()->replaceScene(transition);
}

//�{�X��֍s���֌W�̃{�^���̃h���[
void FightScene::DrawChangeBossSceneMenu()
{
	//�{�X�֌������{�^��
	auto bossButtonImage = MenuItemImage::create(BOSS_BUTTON_PATH, PUSH_BOSS_BUTTON_PATH, CC_CALLBACK_0(FightScene::DisplayYesNoButton, this));
	bossButtonImage->setPosition(Vec2(600, 1000));
	_bossButton = Menu::create(bossButtonImage, nullptr);
	_bossButton->setPosition(Vec2::ZERO);
	this->addChild(_bossButton, 1);
	
	//�u�͂��v�{�^��
	auto yesButtonImage = MenuItemImage::create(YES_BUTTON_PATH, PUSH_YES_BUTTON_PATH, CC_CALLBACK_1(FightScene::ChangeBossScene, this));
	yesButtonImage->setPosition(Vec2(200, 500));
	_yesButton = Menu::create(yesButtonImage, nullptr);
	_yesButton->setPosition(Vec2::ZERO);
	this->addChild(_yesButton, 1);

	//�u�������v�{�^��
	auto noButtonImage = MenuItemImage::create(NO_BUTTON_PATH, PUSH_NO_BUTTON_PATH, CC_CALLBACK_0(FightScene::NonDisplayYesNoButton, this));
	noButtonImage->setPosition(Vec2(500, 500));
	_noButton = Menu::create(noButtonImage, nullptr);
	_noButton->setPosition(Vec2::ZERO);
	this->addChild(_noButton, 1);

	//���ׂĔ�\����
	_bossButton->setVisible(false);
	_yesButton->setVisible(false);
	_noButton->setVisible(false);
}

//�{�X��֍s���{�^����\������
void FightScene::DisplayBossButton()
{
	_bossButton->setVisible(true);
}

//�u�͂��v�Ɓu�������v�{�^����\������
void FightScene::DisplayYesNoButton()
{
	_bossButtonPushFlag = true;

	if (_yesNoButtonUseFlag)
	{
		_yesButton->setVisible(true);
		_noButton->setVisible(true);
	}


	// �w�i���Â����邽�߂̋�`
	auto rect = Rect(0, 0, 800, 1280);
	auto square = Sprite::create();
	square->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);	//�A���J�[�|�C���g�������
	square->setTextureRect(rect);
	square->setPosition(0, 1280);
	square->setColor(Color3B::BLACK);
	square->setOpacity(80.0f);
	this->addChild(square);

	auto changeBossDialogSprite = Sprite::create("UI/changeBoss_dialog.png");
	changeBossDialogSprite->setPosition(Vec2(800 / 2, 1280+changeBossDialogSprite->getContentSize().height / 2));
	this->addChild(changeBossDialogSprite);

	//����
	auto *firstDown = MoveTo::create(0.2f, Vec2(800 / 2, 1280 / 2));
	auto *up = MoveBy::create(0.07f, Vec2(0, 30.f));
	auto *firstDownToUp = Sequence::create(firstDown, up, nullptr);

	changeBossDialogSprite->runAction(firstDownToUp);


	//_yesButton->setOpacity(0.0f);
	//_noButton->setOpacity(0.0f);;
	auto delay = DelayTime::create(0.4f);
	auto fcadein = FadeIn::create(0.3f);	
	auto *delayToFadein = Sequence::create(delay, fcadein, nullptr);

	_yesButton->runAction(delayToFadein);
	_noButton ->runAction(delayToFadein);



}

//�u�͂��v�Ɓu�������v�{�^�����\���ɂ���
void FightScene::NonDisplayYesNoButton()
{
	_yesButton->setVisible(false);
	_noButton->setVisible(false);

	//auto *lastDown = MoveTo::create(0.2f, Vec2(800 / 2, -(changeBossDialogSprite->getContentSize().height / 2)));

}

//�o���l�l���A�i�E���X�̕\��
void FightScene::ExpGetAnnounce() 
{
	//Size winSize = Director::getInstance()->getWinSize();
	//TTFConfig ttfConfigEffect(EXP_LABEL_FONT_PATH, EXP_LABEL_FONT_SIZE, GlyphCollection::DYNAMIC);
	//ttfConfigEffect.distanceFieldEnabled = true; //�����G�t�F�N�g���g�p����
	//expLabel = Label::createWithTTF(ttfConfigEffect, "+" + StringUtils::toString(_exp) + "EXP");
	//expLabel->setColor(Color3B::RED);
	//expLabel->enableGlow(Color4B::BLACK); //�F��ݒ�
	//expLabel->setPosition(Vec2(winSize.width / 2, 1100));
	//this->addChild(expLabel);
	//FightScene::ScalingAndFadeout(expLabel, 0.1f, 1.3f, 0.1f, 1.0f, 2.0f, 0.4f);
	announceTelop->setString(StringUtils::toString(_exp) + "�̌o���l���l�������I");

	//this->runAction(Sequence::create(DelayTime::create(3), CallFunc::create([this]()
	//{
	//	announceTelop->setVisible(false);
	//}), nullptr));
}

//

void FightScene::update(float delta) 
{
	//�_���[�W�\���͈�莞�ԂŃI�t��
	if (_damageDispFlag)
	{
		if (--_damageDispTime < 1) 
		{
			damageLabel->setVisible(false);
			_damageDispFlag = false;
		}
		else
		{
			damageLabel->setVisible(true);
			_damageDispFlag = true;
		}
	}

	//�G�����S���Ă����玟�̃o�g�����n�܂�܂ł̃J�E���g�_�E�����X�^�[�g
	//�J�E���g���O�ɂȂ�����G�̎��S��ԃt���O�������āA�G�̕\���t���O�𗧂Ă�B
	if (_enemyDeathFlg) 
	{
		if (--_nextBattleTimer < 1)
		{
			_enemyDispFlag = true;
			_enemyDeathFlg = false;
			announceTelop->setString("�G�����ꂽ�I�^�b�v���X���C�v�ōU�����I");

		}
	}

	//�͂��Ƃ������{�^�����g����悤�ɂȂ�܂ł̃^�C�}�[
	if (_bossButtonPushFlag)
	{
		if (_yesNoButtonUseTimer -= 0.1f < 0)
		{
			_yesNoButtonUseFlag = true;
		}
	}

	//MoveBy *move = MoveBy::create(0.02f, Vec2(0, _vel));
	//_enemySprite->runAction(move);


	//log("dispCnt = %i", _damageDispTime);
	//log("dispflag = %i", _damageDispFlag);
	//log("EPointDispTimeCnt = %i", EPointDispTime);

	//log("_enemyDeathFlg = %i", _enemyDeathFlg);
	//log("_nextBattleTimer = %i", _nextBattleTimer);
	//log("_enemyDispFlag = %i", _enemyDispFlag);
	log("_yesNoButtonUseTimer = %f", _yesNoButtonUseTimer);
	log("_bossButtonPushFlag = %i", _bossButtonPushFlag);
	log("_yesNoButtonUseFlag = %i", _yesNoButtonUseFlag);


}

//�G�̐؂�ւ�
void FightScene::EnemySelector()
{
	switch ((BattleNumber)_battleCounter)
	{
	case BattleNumber::Battle1:
		_enemySprite->setTexture(FIELD_ENEMY_FOLDER_PATH + "EM_Cat.png");
		break;							
	case BattleNumber::Battle2:			
		_enemySprite->setTexture(FIELD_ENEMY_FOLDER_PATH + "EM_Devil.png");
		break;					
	case BattleNumber::Battle3:	
		_enemySprite->setTexture(FIELD_ENEMY_FOLDER_PATH + "EM_Exp.png");
		break;					
	case BattleNumber::Battle4:	
		_enemySprite->setTexture(FIELD_ENEMY_FOLDER_PATH + "EM_Moja.png");
		break;					
	case BattleNumber::Battle5:	
		_enemySprite->setTexture(FIELD_ENEMY_FOLDER_PATH + "EM_Shark.png");
		break;					
	case BattleNumber::Battle6:	
		_enemySprite->setTexture(FIELD_ENEMY_FOLDER_PATH + "EM_Zombi01.png");
		break;
	}

	FightScene::EnemyFadeIn();
	if (_battleCounter <= BATTLE_MAX) FightScene::BattleAnnounce();

	FightScene::EnemyHpGage();
	FightScene::EnemyHpGageFadeIn();

}
