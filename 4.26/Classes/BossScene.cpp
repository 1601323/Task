#include "BossScene.h"
#include "GameClear.h"
#include <ui/CocosGUI.h>
#pragma execution_character_set("utf-8")

using namespace ui;
using namespace std; // String*

Scene *BossScene::createScene()
{
	auto scene = Scene::create();
	auto layer = BossScene::create();
	scene->addChild(layer);
	return scene;
}

// ������
bool BossScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	//�L�����g�P�i�A�^�b�J�[�̏ꍇ�j
	pl1frame.hp = 115;					//HP
	pl1frame.hpmax = pl1frame.hp;		//HPMAX
	pl1frame.mana = 38;					//MP
	pl1frame.manamax = pl1frame.mana;	//MPMAX
	pl1frame.atk = 90;					//ATK
	pl1frame.atkmax = pl1frame.atk;		//ATKMAX
	pl1frame.def = 78;					//DEF
	pl1frame.defmax = pl1frame.def;		//DEFMAX
	pl1frame.matk = 57;					//MATK
	pl1frame.matkmax = pl1frame.matk;	//MATKMAX
	pl1frame.mdef = 78;					//MDEF
	pl1frame.mdefmax = pl1frame.mdef;	//MDEFMAX
	pl1frame.choicejob = HEALER;		//���m
	//�L�����g2�i�q�[���[�ȏꍇ�j
	pl2frame.hp = 86;					//HP
	pl2frame.hpmax = pl2frame.hp;		//HPMAX
	pl2frame.mana = 75;					//MP
	pl2frame.manamax = pl2frame.mana;	//MPMAX
	pl2frame.atk = 61;					//ATK
	pl2frame.atkmax = pl2frame.atk;		//ATKMAX
	pl2frame.def = 74;					//DEF
	pl2frame.defmax = pl2frame.def;		//DEFMAX
	pl2frame.matk = 57;					//MATK
	pl2frame.matkmax = pl2frame.matk;	//MATKMAX
	pl2frame.mdef = 69;					//MDEF
	pl2frame.mdefmax = pl2frame.mdef;	//MDEFMAX
	pl2frame.choicejob = SHIELD;		//���E��
	//�L�����g3�i�}�W�b�N�̏ꍇ�j
	pl3frame.hp = 93;					//HP
	pl3frame.hpmax = pl3frame.hp;		//HPMAX
	pl3frame.mana = 69;					//MP
	pl3frame.manamax = pl3frame.mana;	//MPMAX
	pl3frame.atk = 61;					//ATK
	pl3frame.atkmax = pl3frame.atk;		//ATKMAX
	pl3frame.def = 69;					//DEF
	pl3frame.defmax = pl3frame.def;		//DEFMAX
	pl3frame.matk = 90;					//MATK
	pl3frame.matkmax = pl3frame.matk;	//MATKMAX
	pl3frame.mdef = 74;					//MDEF
	pl3frame.mdefmax = pl3frame.mdef;	//MDEFMAX
	pl3frame.choicejob = ATTACKER;		//���p�t

	//���m
	if (pl1frame.choicejob == ATTACKER) {
		attacker.hp = pl1frame.hp;		//HP
		attacker.hpmax = attacker.hp;	//HPMAX
		attacker.mana = pl1frame.mana;	//MP
		attacker.manamax = attacker.mana;//MPMAX
		attacker.atk = pl1frame.atk;	//ATK
		attacker.atkmax = attacker.atk;	//ATKMAX
		attacker.def = pl1frame.def;	//DEF
		attacker.defmax = attacker.def;	//DEFMAX
		attacker.matk = pl1frame.matk;	//MATK
		attacker.matkmax = attacker.matk;//MATKMAX
		attacker.mdef = pl1frame.mdef;	//MDEF
		attacker.mdefmax = attacker.mdef;//MDEFMAX
	}
	if (pl2frame.choicejob == ATTACKER) {
		attacker.hp = pl2frame.hp;		//HP
		attacker.hpmax = attacker.hp;	//HPMAX
		attacker.mana = pl2frame.mana;	//MP
		attacker.manamax = attacker.mana;//MPMAX
		attacker.atk = pl2frame.atk;	//ATK
		attacker.atkmax = attacker.atk;	//ATKMAX
		attacker.def = pl2frame.def;	//DEF
		attacker.defmax = attacker.def;	//DEFMAX
		attacker.matk = pl2frame.matk;	//MATK
		attacker.matkmax = attacker.matk;//MATKMAX
		attacker.mdef = pl2frame.mdef;	//MDEF
		attacker.mdefmax = attacker.mdef;//MDEFMAX
	}
	if (pl3frame.choicejob == ATTACKER) {
		attacker.hp = pl3frame.hp;		//HP
		attacker.hpmax = attacker.hp;	//HPMAX
		attacker.mana = pl3frame.mana;	//MP
		attacker.manamax = attacker.mana;//MPMAX
		attacker.atk = pl3frame.atk;	//ATK
		attacker.atkmax = attacker.atk;	//ATKMAX
		attacker.def = pl3frame.def;	//DEF
		attacker.defmax = attacker.def;	//DEFMAX
		attacker.matk = pl3frame.matk;	//MATK
		attacker.matkmax = attacker.matk;//MATKMAX
		attacker.mdef = pl3frame.mdef;	//MDEF
		attacker.mdefmax = attacker.mdef;//MDEFMAX
	}
	//�R�m
	if (pl1frame.choicejob == SHIELD) {
		shield.hp = pl1frame.hp;		//HP
		shield.hpmax = shield.hp;		//HPMAX
		shield.mana = pl1frame.mana;	//MP
		shield.manamax = shield.mana;	//MPMAX
		shield.atk = pl1frame.atk;		//ATK
		shield.atkmax = shield.atk;		//ATKMAX
		shield.def = pl1frame.def;		//DEF
		shield.defmax = shield.def;		//DEFMAX
		shield.matk = pl1frame.matk;	//MATK
		shield.matkmax = shield.matk;	//MATKMAX
		shield.mdef = pl1frame.mdef;	//MDEF
		shield.mdefmax = shield.mdef;	//MDEFMAX
	}
	if (pl2frame.choicejob == SHIELD) {
		shield.hp = pl2frame.hp;		//HP
		shield.hpmax = shield.hp;		//HPMAX
		shield.mana = pl2frame.mana;	//MP
		shield.manamax = shield.mana;	//MPMAX
		shield.atk = pl2frame.atk;		//ATK
		shield.atkmax = shield.atk;		//ATKMAX
		shield.def = pl2frame.def;		//DEF
		shield.defmax = shield.def;		//DEFMAX
		shield.matk = pl2frame.matk;	//MATK
		shield.matkmax = shield.matk;	//MATKMAX
		shield.mdef = pl2frame.mdef;	//MDEF
		shield.mdefmax = shield.mdef;	//MDEFMAX
	}
	if (pl3frame.choicejob == SHIELD) {
		shield.hp = pl3frame.hp;		//HP
		shield.hpmax = shield.hp;		//HPMAX
		shield.mana = pl3frame.mana;	//MP
		shield.manamax = shield.mana;	//MPMAX
		shield.atk = pl3frame.atk;		//ATK
		shield.atkmax = shield.atk;		//ATKMAX
		shield.def = pl3frame.def;		//DEF
		shield.defmax = shield.def;		//DEFMAX
		shield.matk = pl3frame.matk;	//MATK
		shield.matkmax = shield.matk;	//MATKMAX
		shield.mdef = pl3frame.mdef;	//MDEF
		shield.mdefmax = shield.mdef;	//MDEFMAX
	}
	//���p�t
	if (pl1frame.choicejob == MAGIC) {
		magic.hp = pl1frame.hp;		//HP
		magic.hpmax = magic.hp;		//HPMAX
		magic.mana = pl1frame.mana;	//MP
		magic.manamax = magic.mana;	//MPMAX
		magic.atk = pl1frame.atk;	//ATK
		magic.atkmax = magic.atk;	//ATKMAX
		magic.def = pl1frame.def;	//DEF
		magic.defmax = magic.def;	//DEFMAX
		magic.matk = pl1frame.matk;	//MATK
		magic.matkmax = magic.matk;	//MATKMAX
		magic.mdef = pl1frame.mdef;	//MDEF
		magic.mdefmax = magic.mdef;	//MDEFMAX
	}
	if (pl2frame.choicejob == MAGIC) {
		magic.hp = pl2frame.hp;		//HP
		magic.hpmax = magic.hp;		//HPMAX
		magic.mana = pl2frame.mana;	//MP
		magic.manamax = magic.mana;	//MPMAX
		magic.atk = pl2frame.atk;	//ATK
		magic.atkmax = magic.atk;	//ATKMAX
		magic.def = pl2frame.def;	//DEF
		magic.defmax = magic.def;	//DEFMAX
		magic.matk = pl2frame.matk;	//MATK
		magic.matkmax = magic.matk;	//MATKMAX
		magic.mdef = pl2frame.mdef;	//MDEF
		magic.mdefmax = magic.mdef;	//MDEFMAX
	}
	if (pl3frame.choicejob == MAGIC) {
		magic.hp = pl3frame.hp;		//HP
		magic.hpmax = magic.hp;		//HPMAX
		magic.mana = pl3frame.mana;	//MP
		magic.manamax = magic.mana;	//MPMAX
		magic.atk = pl3frame.atk;	//ATK
		magic.atkmax = magic.atk;	//ATKMAX
		magic.def = pl3frame.def;	//DEF
		magic.defmax = magic.def;	//DEFMAX
		magic.matk = pl3frame.matk;	//MATK
		magic.matkmax = magic.matk;	//MATKMAX
		magic.mdef = pl3frame.mdef;	//MDEF
		magic.mdefmax = magic.mdef;	//MDEFMAX
	}
	//���E��
	if (pl1frame.choicejob == HEALER) {
		healer.hp = pl1frame.hp;	//HP
		healer.hpmax = healer.hp;	//HPMAX
		healer.mana = pl1frame.mana;//MP
		healer.manamax = healer.mana;//MPMAX
		healer.atk = pl1frame.atk;	//ATK
		healer.atkmax = healer.atk;	//ATKMAX
		healer.def = pl1frame.def;	//DEF
		healer.defmax = healer.def;	//DEFMAX
		healer.matk = pl1frame.matk;//MATK
		healer.matkmax = healer.matk;//MATKMAX
		healer.mdef = pl1frame.mdef;//MDEF
		healer.mdefmax = healer.mdef;//MDEFMAX
	}
	if (pl2frame.choicejob == HEALER) {
		healer.hp = pl2frame.hp;	//HP
		healer.hpmax = healer.hp;	//HPMAX
		healer.mana = pl2frame.mana;//MP
		healer.manamax = healer.mana;//MPMAX
		healer.atk = pl2frame.atk;	//ATK
		healer.atkmax = healer.atk;	//ATKMAX
		healer.def = pl2frame.def;	//DEF
		healer.defmax = healer.def;	//DEFMAX
		healer.matk = pl2frame.matk;//MATK
		healer.matkmax = healer.matk;//MATKMAX
		healer.mdef = pl2frame.mdef;//MDEF
		healer.mdefmax = healer.mdef;//MDEFMAX
	}
	if (pl3frame.choicejob == HEALER) {
		healer.hp = pl3frame.hp;	//HP
		healer.hpmax = healer.hp;	//HPMAX
		healer.mana = pl3frame.mana;//MP
		healer.manamax = healer.mana;//MPMAX
		healer.atk = pl3frame.atk;	//ATK
		healer.atkmax = healer.atk;	//ATKMAX
		healer.def = pl3frame.def;	//DEF
		healer.defmax = healer.def;	//DEFMAX
		healer.matk = pl3frame.matk;//MATK
		healer.matkmax = healer.matk;//MATKMAX
		healer.mdef = pl3frame.mdef;//MDEF
		healer.mdefmax = healer.mdef;//MDEFMAX
	}
	//���@���L���[
	valkyrie.hp = 800;					//HP
	valkyrie.hpmax = valkyrie.hp;		//HPMAX
	valkyrie.mana = 10;					//MP
	valkyrie.manamax = valkyrie.mana;	//MPMAX
	valkyrie.atk = 120;					//ATK
	valkyrie.atkmax = valkyrie.atk;		//ATKMAX
	valkyrie.def = 128;					//DEF
	valkyrie.defmax = valkyrie.def;		//DEFMAX
	valkyrie.matk = 70;					//MATK
	valkyrie.matkmax = valkyrie.matk;	//MATKMAX
	valkyrie.mdef = 88;					//MDEF
	valkyrie.mdefmax = valkyrie.mdef;	//MDEFMAX

	//�����ݒ�
	turn = PLAYER;			//�N�̃^�[���H
	battle = START;			//�o�g��
	choices = CHAR1;		//�R�}���h��I�ԍŏ��̃L����
	bsact = PICK;			//�{�X�̓���
	job = NON;				//�L�����I��
	bufft = ASKILL2T;		//�o�t�E�f�o�t�̃^�[�������̍ŏ�
	
	//�摜�T�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();

	// �{�^���z�u
	// �ʏ펞,��������
	// ���������̱����
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(BossScene::pushStart, this));

	// �{�^���̔z�u
	startButton->setPosition(Point(winSize.width / 16, winSize.height / 2));
	// ���j���[�쐬(����obj)
	auto menu = Menu::create(startButton, NULL);
	menu->setPosition(Point::ZERO);
	// �ǉ�
	this->addChild(menu, backdepth);

	//�^�b�`���[�h�ݒ�
	this->setTouchMode(kCCTouchesOneByOne);
	this->setTouchEnabled(true);

	// �o�b�N�O�����h
	BossBackGroudn();

	//�A�b�v�f�[�g�X�V
	this->scheduleUpdate();

	return true;
}

//�{�X��̗���̏���
void BossScene::update(float flame)
{
	if (turn == PLAYER) {
		switch (battle){
			battle = START;
		case BossScene::START: {
			state = false;
			battleturn += 1;
			battle = WAIT;
			break;
		}
		//�X�e�[�^�X�A�b�v��_�E���Ȃǂ��Ǘ�����Ƃ���
		case BossScene::WAIT: {
			gameflame++;					//�Q�[���t���[����i�߂�			
			Skillturn();					//�X�L���̌��ʂ��؂ꂽ���ǂ����𔻒f���邽�߂̏���

			//���S�ݒ�
			//���m�̃L������HP��0�ɂȂ�����
			if (pl1frame.choicejob == ATTACKER || pl2frame.choicejob == ATTACKER || pl3frame.choicejob == ATTACKER) {
				if (attacker.hp == 0) {
					attacker.deathflag = true;
				}
			}
			//�R�m�̃L������HP��0�ɂȂ�����
			if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD || pl3frame.choicejob == SHIELD) {
				if (shield.hp == 0) {
					shield.deathflag = true;
				}
			}
			//���p�t�̃L������HP��0�ɂȂ�����
			if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC || pl3frame.choicejob == MAGIC) {
				if (magic.hp == 0) {
					magic.deathflag = true;
				}
			}
			//���E�҂̃L������HP��0�ɂȂ�����
			if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER || pl3frame.choicejob == HEALER) {
				if (healer.hp == 0) {
					healer.deathflag = true;
				}
			}
				
			//�O����
			//PL1
			if (pl1frame.choicejob == ATTACKER && attacker.hp == 0) {
				pl1 = PL1DEATH;
			}
			else if (pl1frame.choicejob == SHIELD && shield.hp == 0) {
				pl1 = PL1DEATH;
			}
			else if (pl1frame.choicejob == MAGIC && magic.hp == 0) {
				pl1 = PL1DEATH;
			}
			else if (pl1frame.choicejob == HEALER && healer.hp == 0) {
				pl1 = PL1DEATH;
			}
			//PL2
			if (pl2frame.choicejob == ATTACKER && attacker.hp == 0) {
				pl2 = PL2DEATH;
			}
			else if (pl2frame.choicejob == SHIELD && shield.hp == 0) {
				pl2 = PL2DEATH;
			}
			else if (pl2frame.choicejob == MAGIC && magic.hp == 0) {
				pl2 = PL2DEATH;
				}
			else if (pl2frame.choicejob == HEALER && healer.hp == 0) {
				pl2 = PL2DEATH;
			}
			//PL3
			if (pl3frame.choicejob == ATTACKER && attacker.hp == 0) {
				pl3 = PL3DEATH;
			}
			else if (pl3frame.choicejob == SHIELD && shield.hp == 0) {
				pl3 = PL3DEATH;
			}
			else if (pl3frame.choicejob == MAGIC && magic.hp == 0) {
				pl3 = PL3DEATH;
			}
			else if (pl3frame.choicejob == HEALER && healer.hp == 0) {
				pl3 = PL3DEATH;
			}
			
			//HP���[���ɂȂ������ʑJ��
			//���m�����Ȃ��Ƃ�
			if (shield.deathflag == true && magic.deathflag == true && healer.deathflag == true) {
				Scene *pScene = GameClear::createScene();							// �J�ڍ�̉�ʂ�ݽ�ݽ
				TransitionFade *transition = TransitionFade::create(1.0, pScene);	// 0.6�b�����Ď���ʂɑJ��(����,�J�ڐ�,�F(�I�v�V����))
				Director::getInstance()->replaceScene(transition);					// �J�ڎ��s �A�j���[�V����
			}
			//�R�m�����Ȃ��Ƃ�
			else if (attacker.deathflag == true && magic.deathflag == true && healer.deathflag == true) {
				Scene *pScene = GameClear::createScene();							// �J�ڍ�̉�ʂ�ݽ�ݽ
				TransitionFade *transition = TransitionFade::create(1.0, pScene);	// 0.6�b�����Ď���ʂɑJ��(����,�J�ڐ�,�F(�I�v�V����))
				Director::getInstance()->replaceScene(transition);					// �J�ڎ��s �A�j���[�V����
			}
			//���p�t�����Ȃ��Ƃ�
			else if (attacker.deathflag == true && shield.deathflag == true && healer.deathflag == true) {
				Scene *pScene = GameClear::createScene();							// �J�ڍ�̉�ʂ�ݽ�ݽ
				TransitionFade *transition = TransitionFade::create(1.0, pScene);	// 0.6�b�����Ď���ʂɑJ��(����,�J�ڐ�,�F(�I�v�V����))
				Director::getInstance()->replaceScene(transition);					// �J�ڎ��s �A�j���[�V����
			}
			//���E�҂����Ȃ��Ƃ�
			else if (attacker.deathflag == true && shield.deathflag == true && magic.deathflag == true) {
				Scene *pScene = GameClear::createScene();							// �J�ڍ�̉�ʂ�ݽ�ݽ
				TransitionFade *transition = TransitionFade::create(1.0, pScene);	// 0.6�b�����Ď���ʂɑJ��(����,�J�ڐ�,�F(�I�v�V����))
				Director::getInstance()->replaceScene(transition);					// �J�ڎ��s �A�j���[�V����
			}

			if (allworkendflag == true) {
				battle = CHOICE;			//�I���ɍs��
				choices = CHAR1;			//�I�����ŏ�����ɖ߂�
				bufft = ASKILL2T;			//�ŏ��ɖ߂�
				gameflame = 0;				//���Ԃ������l�ɖ߂�
				skillflame = 0;				//�X�L���̎��Ԃ������l��
				allworkendflag = false;		//���ɖ߂��Ă���


				//�U���R�}���h�{�^��
				AttackButton1 = CCSprite::create("UI/Command/UI_Button_Attack01.png");	 //�摜�w��
				AttackButton1->setPosition(rightSize.width / 3, rightSize.height / 2.1f);//�z�u�ꏊ
				this->addChild(AttackButton1, middledepth, attackbuttonaI);				//�ǉ�		

				//�U���R�}���h�{�^��(������Ă���Ƃ�)
				AttackButton2 = CCSprite::create("UI/Command/UI_Button_Attack02.png");	 //�摜�w��
				AttackButton2->setPosition(rightSize.width / 3, rightSize.height / 2.1f);//�z�u�ꏊ
				this->addChild(AttackButton2, backdepth, attackbuttonbI);				//�ǉ�

				//�X�L���R�}���h�{�^��
				SkillButton1 = CCSprite::create("UI/Command/UI_Button_Skill01.png");	//�摜�w��
				SkillButton1->setPosition(rightSize.width / 3, rightSize.height / 2.7f);//�z�u�ꏊ
				this->addChild(SkillButton1, middledepth, skillbuttonaI);				//�ǉ�

				//�X�L���R�}���h�{�^��(������Ă���Ƃ�)
				SkillButton2 = CCSprite::create("UI/Command/UI_Button_Skill02.png");	//�摜�w��
				SkillButton2->setPosition(rightSize.width / 3, rightSize.height / 2.7f);//�z�u�ꏊ
				this->addChild(SkillButton2, backdepth, skillbuttonbI);						//�ǉ�

				//PLTURN(�E��)															
				plturn = CCSprite::create("Description/PL.png");						//�z�u����
				plturn->setPosition(rightSize.width / 1.1f, rightSize.height / 1.25f);	//�ꏊ�z�u
				this->addChild(plturn, backdepth, playertrunI);							//�ǉ�
			}
			break;
		}
		//�v���C���[�����̃R�}���h��I�����邩�����߂�
		case BossScene::CHOICE: {
			// ��ʃT�C�Y�擾�B
			Size visibleSize = Director::getInstance()->getVisibleSize();
			//�^�b�`�C�x���g�擾
			auto Atouchget = EventListenerTouchOneByOne::create();	//�A�^�b�N�{�^��
			auto S1touchget = EventListenerTouchOneByOne::create();	//�X�L���{�^��

			choicetime++;			//�{�^�����A���ŉ�����Ȃ��悤�ɂ��邽�߂̏���
			//�^�b�`����
			auto Abutton = AttackButton1;
			auto Sbutton = SkillButton1;

			//�A�^�b�N�{�^��
			Atouchget->onTouchBegan = [this, visibleSize, Abutton](Touch* touch, Event* event) {
				Vec2 point1 = touch->getLocation();					//�^�b�`�����|�C���g�B
				Rect rectButton1 = Abutton->getBoundingBox();		//�{�^���摜�͈̔́B
				switch (choices) {
				//�L����1
				case BossScene::CHAR1: {
					if (!(pl1 == PL1DEATH)) {
						if (choicetime > flame15) {
							//�{�^���摜�͈͓̔����^�b�`�����ꍇ�B
							if (rectButton1.containsPoint(point1)) {
								AttackButton1->setVisible(false);		//��̃{�^��������
								pl1 = PL1ATTACK;						//�A�^�b�N�ɂ���
								this->removeChildByTag(choiceS);
								choicetime = 0;
								choices = CHAR2;						//���̃L������
								return true;
							}
							else {
								CCLOG("NO TOUCH");
								return false;
							}
						}
					}
					//���S��ԂȂ玟�̃L������
					if (pl1 == PL1DEATH) {
						this->removeChildByTag(choiceS);
						choicetime = 0;
						choices = CHAR2;						//���̃L������
					}
					break;
				}
				//�L����2
				case BossScene::CHAR2: {
					if (!(pl2 == PL2DEATH)) {
						if (choicetime > flame15) {
							//�{�^���摜�͈͓̔����^�b�`�����ꍇ�B
							if (rectButton1.containsPoint(point1)) {
								this->removeChildByTag(choiceS);
								AttackButton1->setVisible(false);	//��̃{�^��������
								pl2 = PL2ATTACK;					//�A�^�b�N�ɂ���
								choicetime = 0;
								choices = CHAR3;					//���̃L������
								return true;
							}
							else {
								CCLOG("NO TOUCH");
								return false;
							}
						}
					}
					//���S��ԂȂ炻�̂܂܎��̃L������
					if (pl2 == PL2DEATH) {
						this->removeChildByTag(choiceS);
						choicetime = 0;
						choices = CHAR3;							//���̃L������
					}
					break;
				}
				 //�L����3
				case BossScene::CHAR3: {
					if (!(pl3 == PL3DEATH)) {
						if (choicetime > flame15) {
							//�{�^���摜�͈͓̔����^�b�`�����ꍇ
							if (rectButton1.containsPoint(point1)) {
								pick_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�v���C���[�̃L������I��)
								act_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�{�X�̓�����)
								decide_rnd = random(rndmin, rndmax);	//�w�肵���͈͓��̗������擾(�{�X�̓���)
								skill_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�X�L��)
								state = true;							//�������Ԃɂ���
								Abutton->removeFromParentAndCleanup(true);//�R�}���h�{�^��(attack)������
								this->removeChildByTag(attackbuttonbI);
								this->removeChildByTag(skillbuttonaI);
								this->removeChildByTag(skillbuttonbI);
								this->removeChildByTag(choiceS);
								pl3 = PL3ATTACK;						//�A�^�b�N�ɂ���
								choicetime = 0;
								battle = ACTION;						//�G�t�F�N�g�Ȃ�
								choices = CHAR1;
								return true;
							}
							else {
								CCLOG("NO TOUCH");
								return false;
							}
						}
					}
					if (pl3 == PL3DEATH) {
						pick_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�v���C���[�̃L������I��)
						act_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�{�X�̓�����)
						decide_rnd = random(rndmin, rndmax);	//�w�肵���͈͓��̗������擾(�{�X�̓���)
						skill_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�X�L��)
						state = true;							//�������Ԃɂ���
						Abutton->removeFromParentAndCleanup(true);//�R�}���h�{�^��(attack)������
						this->removeChildByTag(attackbuttonbI);
						this->removeChildByTag(skillbuttonaI);
						this->removeChildByTag(skillbuttonbI);
						this->removeChildByTag(choiceS);
						choicetime = 0;
						battle = ACTION;						//�G�t�F�N�g�Ȃ�
						choices = CHAR1;
					}
					break;
				}
				default: {
					break;
				}
				}
				return true;
			};
			//�X�L���{�^��
			S1touchget->onTouchBegan = [this, visibleSize, Sbutton](Touch* touch, Event* event) {
				Vec2 point2 = touch->getLocation();								//�^�b�`�����|�C���g�B
				Rect rectButton1 = Sbutton->getBoundingBox();					//�{�^���摜�͈̔́B
				switch (choices) {
					//�L����1
				case BossScene::CHAR1: {
					if (!(pl1 == PL1DEATH)) {
						if (choicetime > flame15) {
							//�{�^���摜�͈͓̔����^�b�`�����ꍇ�B
							if (rectButton1.containsPoint(point2)) {
								SkillButton1->setVisible(false);					//��̃{�^��������
								pl1 = PL1SKILL;										//�X�L�����g��
								//PL1�̐E�Ƃɂ������X�L�����g��
								if (pl1frame.choicejob == ATTACKER)askill = ASKILL5;	//���m�̃X�L��
								if (pl1frame.choicejob == SHIELD)sskill = SSKILL1;	//�R�m�̃X�L��
								if (pl1frame.choicejob == MAGIC)mskill = MSKILL1;	//���p�t�̃X�L��
								if (pl1frame.choicejob == HEALER)hskill = HSKILL4;	//���E�҂̃X�L��
								this->removeChildByTag(choiceS);

								//�R�m�̑I���n�X�L���������ꍇ
								if (pl1frame.choicejob == SHIELD) {
									if (sskill == SSKILL4) {
										choices = CHOICETIME;
										choicetime = 0;
										this->removeChildByTag(choiceS);
									}
								}
								//���p�t�̑I���n�X�L���̏ꍇ
								//���E�҂̒P�̃X�L���n���������ꍇ�Ȃ�
								if (pl1frame.choicejob == HEALER) {
									//���E�҂̉񕜌n�X�L���̉񕜗ʂ����߂�
									if (hskill == HSKILL4) {
										recovery_rnd = random(recoverylittlemin, recoverylittlemax);
									}
									else if (hskill == HSKILL5) {
										recovery_rnd = random(recoverylargemin, recoverylargemax);
									}
									else if (hskill == HSKILL6) {
										recovery_rnd = random(recoverymediummin, recoverymediummax);
									}
									//���E�҂̒P�̑I���n�X�L���������ꍇ�A�񕜂��鑊���I��
									if (hskill == HSKILL1 || hskill == HSKILL4
										|| hskill == HSKILL5 || hskill == HSKILL8) {
										choices = CHOICETIME;
										choicetime = 0;
										this->removeChildByTag(choiceS);
									}
								}
								//�P�̑I���n�̃X�L������Ȃ��ꍇ
								if (!(pl1frame.choicejob == HEALER && hskill == HSKILL1 || hskill == HSKILL4 || hskill == HSKILL5 || hskill == HSKILL8)) {
									if (!(pl1frame.choicejob == SHIELD && sskill == SSKILL4)) {
										if (!(pl1frame.choicejob == MAGIC && mskill == MSKILL7)) {
											choices = CHAR2;
											choicetime = 0;
											choiceendflag = false;
											this->removeChildByTag(choiceS);
										}
									}
								}
								return true;
							}
							if (pl1 == PL1DEATH) {
								choices = CHAR2;
								choicetime = 0;
								choiceendflag = false;
								this->removeChildByTag(choiceS);
							}
							else {
								CCLOG("NO TOUCH");
								return false;
							}
						}
					}
					break;
				}
									   //�L����2
				case BossScene::CHAR2: {
					if (!(pl2 == PL2DEATH)) {
						if (choicetime > flame15) {
							//�{�^���摜�͈͓̔����^�b�`�����ꍇ�B
							if (rectButton1.containsPoint(point2)) {
								SkillButton1->setVisible(false);					//��̃{�^��������
								pl2 = PL2SKILL;										//�X�L���g��
								//PL2�̐E�Ƃɂ������X�L�����g��
								if (pl2frame.choicejob == ATTACKER)askill = ASKILL2;//���m�̃X�L��
								if (pl2frame.choicejob == SHIELD)sskill = SSKILL4;	//�R�m�̃X�L��
								if (pl2frame.choicejob == MAGIC)mskill = MSKILL3;	//���p�t�̃X�L��
								if (pl2frame.choicejob == HEALER)hskill = HSKILL4;	//���E�҂̃X�L��

								//�R�m�̑I���n�X�L���������ꍇ
								if (pl2frame.choicejob == SHIELD) {
									if (sskill == SSKILL4) {
										choices = CHOICETIME;
										choicetime = 0;
										this->removeChildByTag(choiceS);
									}
								}
								//���E�҂̒P�̃X�L���n���������ꍇ�Ȃ�
								if (pl2frame.choicejob == HEALER) {
									//���E�҂̉񕜌n�X�L���̉񕜗ʂ����߂�
									if (hskill == HSKILL4) {
										recovery_rnd = random(recoverylittlemin, recoverylittlemax);
									}
									else if (hskill == HSKILL5) {
										recovery_rnd = random(recoverylargemin, recoverylargemax);
									}
									else if (hskill == HSKILL6) {
										recovery_rnd = random(recoverymediummin, recoverymediummax);
									}
									//���E�҂̒P�̑I���n�X�L���������ꍇ�A�񕜂��鑊���I��
									if (hskill == HSKILL1 || hskill == HSKILL4
										|| hskill == HSKILL5 || hskill == HSKILL8) {
										choices = CHOICETIME;
										choicetime = 0;
										this->removeChildByTag(choiceS);
									}
								}
								//�P�̑I���n�̃X�L������Ȃ��ꍇ
								if (!(pl2frame.choicejob == HEALER && hskill == HSKILL1 || hskill == HSKILL4 || hskill == HSKILL5 || hskill == HSKILL8)) {
									if (!(pl2frame.choicejob == SHIELD && sskill == SSKILL4)) {
										if (!(pl2frame.choicejob == MAGIC && mskill == MSKILL7)) {
											choices = CHAR3;			//���̃L������
											choicetime = 0;
											choiceendflag = false;
											this->removeChildByTag(choiceS);
										}
									}
								}
								return true;
							}
							else {
								CCLOG("NO TOUCH");
								return false;
							}
						}
					}
					if (pl2 == PL2DEATH) {
						choices = CHAR3;			//���̃L������
						choicetime = 0;
						choiceendflag = false;
						this->removeChildByTag(choiceS);
					}
					break;
				}
									   //�L����3
				case BossScene::CHAR3: {
					if (!(pl3 == PL3DEATH)) {
						if (choicetime > flame15) {
							//�{�^���摜�͈͓̔����^�b�`�����ꍇ�B
							if (rectButton1.containsPoint(point2)) {
								pick_rnd = random(rndmin, rndmax);			//�w�肵���͈͓��̗������擾(�v���C���[�̃L������I��)
								act_rnd = random(rndmin, rndmax);			//�w�肵���͈͓��̗������擾(�{�X�̓�����)
								decide_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�{�X�̓���)
								skill_rnd = random(rndmin, rndmax);			//�w�肵���͈͓��̗������擾(�X�L��)
								state = true;								//�������Ԃɂ���
								Sbutton->removeFromParentAndCleanup(true);	//�R�}���h�{�^��(attack)������
								this->removeChildByTag(attackbuttonaI);
								this->removeChildByTag(attackbuttonbI);
								this->removeChildByTag(skillbuttonbI);
								pl3 = PL3SKILL;										//�X�L���ɂ���
								//PL3�̐E�Ƃɂ������X�L�����g��
								if (pl3frame.choicejob == ATTACKER)askill = ASKILL1;//���m�̃X�L��
								if (pl3frame.choicejob == SHIELD)sskill = SSKILL3;	//�R�m�̃X�L��
								if (pl3frame.choicejob == MAGIC)mskill = MSKILL1;	//���p�t�̃X�L��
								if (pl3frame.choicejob == HEALER)hskill = HSKILL1;	//���E�҂̃X�L��

								//�R�m�̑I���n�X�L���������ꍇ
								if (pl3frame.choicejob == SHIELD && sskill == SSKILL4) {
									choices = CHOICETIME;
									choicetime = 0;
									this->removeChildByTag(choiceS);
								}
								//���E�҂̒P�̃X�L���n���������ꍇ�Ȃ�
								if (pl3frame.choicejob == HEALER) {
									//���E�҂̉񕜌n�X�L���̉񕜗ʂ����߂�
									if (hskill == HSKILL4) {
										recovery_rnd = random(recoverylittlemin, recoverylittlemax);
									}
									else if (hskill == HSKILL5) {
										recovery_rnd = random(recoverylargemin, recoverylargemax);
									}
									else if (hskill == HSKILL6) {
										recovery_rnd = random(recoverymediummin, recoverymediummax);
									}
									//���E�҂̒P�̑I���n�X�L���������ꍇ�A�񕜂��鑊���I��
									if (hskill == HSKILL1 || hskill == HSKILL4
										|| hskill == HSKILL5 || hskill == HSKILL8) {
										choices = CHOICETIME;
										choicetime = 0;
										this->removeChildByTag(choiceS);
									}
								}
								//�P�̑I���n�̃X�L������Ȃ��ꍇ
								if (!(pl3frame.choicejob == HEALER && hskill == HSKILL1 || hskill == HSKILL4 || hskill == HSKILL5 || hskill == HSKILL8)) {
									if (!(pl3frame.choicejob == SHIELD && sskill == SSKILL4)) {
										if (!(pl3frame.choicejob == MAGIC && mskill == MSKILL7)) {
											choicetime = 0;										//�^�C����0
											battle = ACTION;									//�G�t�F�N�g�Ȃǂ�S��
											choices = CHAR1;
											choiceendflag = false;
											this->removeChildByTag(choiceS);
										}
									}
								}

								return true;
							}
							else {
								CCLOG("NO TOUCH");
								return false;
							}
						}
					}
					if (pl3 == PL3DEATH) {
						choicetime = 0;										//�^�C����0
						battle = ACTION;									//�G�t�F�N�g�Ȃǂ�S��
						choices = CHAR1;
						choiceendflag = false;
						this->removeChildByTag(choiceS);
					}
					break;
				}
									   //�X�L���ȂǂŃL������I�����鏊
				case BossScene::CHOICETIME: {
					//�R�m�̏ꍇ
					if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD || pl3frame.choicejob == SHIELD) {
						if (sskill == SSKILL4) {
							//�^�b�`�C�x���g�擾
							auto attackerframetouch = EventListenerTouchOneByOne::create();	//���m�^�b�`
							auto magicframetouch = EventListenerTouchOneByOne::create();	//���p�t�^�b�`
							auto healerframetouch = EventListenerTouchOneByOne::create();	//���E�҃^�b�`

							//�^�b�`����
							auto attackerbutton = PLattacker;	//���m
							auto magicbutton = PLmagic;			//���p�t
							auto healerbutton = PLhealer;		//���E��

							//���m���^�b�`�����ꍇ
							attackerframetouch->onTouchBegan = [this, visibleSize, attackerbutton](Touch* touch, Event* event) {
								Vec2 attackerpoint = touch->getLocation();					//�^�b�`�����|�C���g�B
								Rect attackerrectButton = attackerbutton->getBoundingBox();	//�{�^���摜�͈̔́B
								if (attackerrectButton.containsPoint(attackerpoint)) {
									//PL1���R�m�̏ꍇ
									if (pl1frame.choicejob == SHIELD) {
										sskillchoice = ATTACKER;
										choices = CHAR2;
										choicetime = 0;
										this->removeChildByTag(choiceplS);
									}
									//PL2���R�m�̏ꍇ
									else if (pl2frame.choicejob == SHIELD) {
										sskillchoice = ATTACKER;
										choices = CHAR3;
										choicetime = 0;
										this->removeChildByTag(choiceplS);
									}
									//PL3���R�m�̏ꍇ
									else if (pl3frame.choicejob == SHIELD) {
										sskillchoice = ATTACKER;
										battle = ACTION;			//�G�t�F�N�g�Ȃǂ�S��
										choicetime = 0;				//�^�C����0
										choices = CHAR1;
										choiceendflag = false;
										this->removeChildByTag(choiceplS);
									}
								}
								return true;
							};
							//���p�t���^�b�`�����ꍇ
							magicframetouch->onTouchBegan = [this, visibleSize, magicbutton](Touch* touch, Event* event) {
								Vec2 magicpoint = touch->getLocation();					//�^�b�`�����|�C���g�B
								Rect magicrectButton = magicbutton->getBoundingBox();	//�{�^���摜�͈̔́B
								if (magicrectButton.containsPoint(magicpoint)) {
									if (pl1frame.choicejob == SHIELD) {
										sskillchoice = MAGIC;
										choices = CHAR2;
										choicetime = 0;
										this->removeChildByTag(choiceplS);
									}
									else if (pl2frame.choicejob == SHIELD) {
										sskillchoice = MAGIC;
										choices = CHAR3;
										choicetime = 0;
										this->removeChildByTag(choiceplS);
									}
									else if (pl3frame.choicejob == SHIELD) {
										sskillchoice = MAGIC;
										battle = ACTION;			//�G�t�F�N�g�Ȃǂ�S��
										choicetime = 0;				//�^�C����0
										choices = CHAR1;
										choiceendflag = false;
										this->removeChildByTag(choiceplS);
									}
								}
								return true;
							};
							//���E�҂��^�b�`�����ꍇ
							healerframetouch->onTouchBegan = [this, visibleSize, healerbutton](Touch* touch, Event* event) {
								Vec2 healerpoint = touch->getLocation();					//�^�b�`�����|�C���g�B
								Rect healerrectButton = healerbutton->getBoundingBox();	//�{�^���摜�͈̔́B
								if (healerrectButton.containsPoint(healerpoint)) {
									if (pl1frame.choicejob == SHIELD) {
										sskillchoice = HEALER;
										choices = CHAR2;
										choicetime = 0;
										this->removeChildByTag(choiceplS);
									}
									else if (pl2frame.choicejob == SHIELD) {
										sskillchoice = HEALER;
										choices = CHAR3;
										choicetime = 0;
										this->removeChildByTag(choiceplS);
									}
									else if (pl3frame.choicejob == SHIELD) {
										sskillchoice = HEALER;
										battle = ACTION;			//�G�t�F�N�g�Ȃǂ�S��
										choicetime = 0;				//�^�C����0
										choices = CHAR1;
										choiceendflag = false;
										this->removeChildByTag(choiceplS);
									}
								}
								return true;
							};
							//���m touchget, button���C�x���g�o�^����B
							auto attackerdirector = Director::getInstance();
							attackerdirector->getEventDispatcher()->addEventListenerWithSceneGraphPriority(attackerframetouch, attackerbutton);
							//���p�t touchget, button���C�x���g�o�^����B
							auto magicdirector = Director::getInstance();
							magicdirector->getEventDispatcher()->addEventListenerWithSceneGraphPriority(magicframetouch, magicbutton);
							//���E�� touchget, button���C�x���g�o�^����B
							auto healerdirector = Director::getInstance();
							healerdirector->getEventDispatcher()->addEventListenerWithSceneGraphPriority(healerframetouch, healerbutton);
						}
					}

					//���E�҂̏ꍇ
					if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER || pl3frame.choicejob == HEALER) {
						if (hskill == HSKILL1 || hskill == HSKILL4 || hskill == HSKILL5 || hskill == HSKILL8) {
							//�^�b�`�C�x���g�擾
							auto attackerframetouch = EventListenerTouchOneByOne::create();	//���m�^�b�`
							auto shieldframetouch = EventListenerTouchOneByOne::create();	//�R�m�^�b�`
							auto magicframetouch = EventListenerTouchOneByOne::create();	//���p�t�^�b�`
							auto healerframetouch = EventListenerTouchOneByOne::create();	//���E�҃^�b�`

							//�^�b�`����
							auto attackerbutton = PLattacker;	//���m
							auto shieldbutton = PLshield;		//�R�m
							auto magicbutton = PLmagic;			//���p�t
							auto healerbutton = PLhealer;		//���E��

							//���m���^�b�`�����ꍇ
							if (attacker.deathflag == false) {
								attackerframetouch->onTouchBegan = [this, visibleSize, attackerbutton](Touch* touch, Event* event) {
									Vec2 attackerpoint = touch->getLocation();					//�^�b�`�����|�C���g�B
									Rect attackerrectButton = attackerbutton->getBoundingBox();	//�{�^���摜�͈̔́B
									if (attackerrectButton.containsPoint(attackerpoint)) {
										hskillchoice = ATTACKER;
										choicetime = 0;
										this->removeChildByTag(choiceplS);
										if (pl1frame.choicejob == HEALER) {
											choices = CHAR2;
										}
										else if (pl2frame.choicejob == HEALER) {
											choices = CHAR3;
										}
										else if (pl3frame.choicejob == HEALER) {
											battle = ACTION;			//�G�t�F�N�g�Ȃǂ�S��
											choices = CHAR1;
											choiceendflag = false;
										}
									}
									return true;
								};
							}
							//�R�m���^�b�`�����ꍇ
							if (shield.deathflag == false) {
								shieldframetouch->onTouchBegan = [this, visibleSize, shieldbutton](Touch* touch, Event* event) {
									Vec2 shieldpoint = touch->getLocation();				//�^�b�`�����|�C���g�B
									Rect shieldrectButton = shieldbutton->getBoundingBox();	//�{�^���摜�͈̔́B
									if (shieldrectButton.containsPoint(shieldpoint)) {
										hskillchoice = SHIELD;
										choicetime = 0;
										this->removeChildByTag(choiceplS);
										if (pl1frame.choicejob == HEALER) {
											choices = CHAR2;
										}
										else if (pl2frame.choicejob == HEALER) {
											choices = CHAR3;
										}
										else if (pl3frame.choicejob == HEALER) {
											battle = ACTION;			//�G�t�F�N�g�Ȃǂ�S��
											choices = CHAR1;
											choiceendflag = false;
										}
									}
									return true;
								};
							}
							//���p�t���^�b�`�����ꍇ
							magicframetouch->onTouchBegan = [this, visibleSize, magicbutton](Touch* touch, Event* event) {
								Vec2 magicpoint = touch->getLocation();					//�^�b�`�����|�C���g�B
								Rect magicrectButton = magicbutton->getBoundingBox();	//�{�^���摜�͈̔́B
								if (magicrectButton.containsPoint(magicpoint)) {
									hskillchoice = MAGIC;
									hskillchoice = ATTACKER;
									choicetime = 0;
									this->removeChildByTag(choiceplS);
									if (pl1frame.choicejob == HEALER) {
										choices = CHAR2;
									}
									else if (pl2frame.choicejob == HEALER) {
										choices = CHAR3;
									}
									else if (pl3frame.choicejob == HEALER) {
										battle = ACTION;			//�G�t�F�N�g�Ȃǂ�S��
										choices = CHAR1;
										choiceendflag = false;
									}
								}
								return true;
							};
							//���E�҂��^�b�`�����ꍇ
							healerframetouch->onTouchBegan = [this, visibleSize, healerbutton](Touch* touch, Event* event) {
								Vec2 healerpoint = touch->getLocation();					//�^�b�`�����|�C���g�B
								Rect healerrectButton = healerbutton->getBoundingBox();	//�{�^���摜�͈̔́B
								if (healerrectButton.containsPoint(healerpoint)) {
									hskillchoice = HEALER;
									hskillchoice = ATTACKER;
									choicetime = 0;
									this->removeChildByTag(choiceplS);
									if (pl1frame.choicejob == HEALER) {
										choices = CHAR2;
									}
									else if (pl2frame.choicejob == HEALER) {
										choices = CHAR3;
									}
									else if (pl3frame.choicejob == HEALER) {
										battle = ACTION;			//�G�t�F�N�g�Ȃǂ�S��
										choices = CHAR1;
										choiceendflag = false;
									}
								}
								return true;
							};
							//���m touchget, button���C�x���g�o�^����B
							auto attackerdirector = Director::getInstance();
							attackerdirector->getEventDispatcher()->addEventListenerWithSceneGraphPriority(attackerframetouch, attackerbutton);
							//�R�m touchget, button���C�x���g�o�^����B
							auto shielddirector = Director::getInstance();
							shielddirector->getEventDispatcher()->addEventListenerWithSceneGraphPriority(shieldframetouch, shieldbutton);
							//���p�t touchget, button���C�x���g�o�^����B
							auto magicdirector = Director::getInstance();
							magicdirector->getEventDispatcher()->addEventListenerWithSceneGraphPriority(magicframetouch, magicbutton);
							//���E�� touchget, button���C�x���g�o�^����B
							auto healerdirector = Director::getInstance();
							healerdirector->getEventDispatcher()->addEventListenerWithSceneGraphPriority(healerframetouch, healerbutton);
						}
					}

					//�I�𒆂͐F�����ǂ�
					if (!(hskill == HSKILL8)) {
						if (attacker.deathflag == false) {
							PLattacker->setColor(ccc3(colormax, colormax, colormax));
						}
						if (shield.deathflag == false) {
							PLshield->setColor(ccc3(colormax, colormax, colormax));
						}
						if (magic.deathflag == false) {
							PLmagic->setColor(ccc3(colormax, colormax, colormax));
						}
						if (healer.deathflag == false) {
							PLhealer->setColor(ccc3(colormax, colormax, colormax));
						}
					}
					else if (hskill == HSKILL8) {
						if (attacker.deathflag == true) {
							PLattacker->setColor(ccc3(colormax, colormax, colormax));
						}
						if (shield.deathflag == true) {
							PLshield->setColor(ccc3(colormax, colormax, colormax));
						}
						if (magic.deathflag == true) {
							PLmagic->setColor(ccc3(colormax, colormax, colormax));
						}
						if (healer.deathflag == true) {
							PLhealer->setColor(ccc3(colormax, colormax, colormax));
						}
					}

					break;
				}
				default: {
					break;
				}
				}
				return true;
			};
			//�I������Ƃ��ɏo�镶��
			if (choicetime == flame15) {
				//������
				//���m
				auto lo = CCLabelTTF::create("���m�͂ǂ�����", "HGRSGU.TTC", fontsizeL);
				lo->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				//�R�m
				auto ls = CCLabelTTF::create("�R�m�͂ǂ�����", "HGRSGU.TTC", fontsizeL);
				ls->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				//���p�t
				auto lw = CCLabelTTF::create("���p�t�͂ǂ�����", "HGRSGU.TTC", fontsizeL);
				lw->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				//���E��
				auto ll = CCLabelTTF::create("���E�҂͂ǂ�����", "HGRSGU.TTC", fontsizeL);
				ll->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

				//���ꂼ���PL�̑I������Ă���L������I��
				if (choices == CHAR1) {
					if (pl1frame.choicejob == ATTACKER) {
						this->addChild(lo, backdepth, choiceS);	//���m
					}
					else if (pl1frame.choicejob == SHIELD) {
						this->addChild(ll, backdepth, choiceS);	//�R�m
					}
					else if (pl1frame.choicejob == MAGIC) {
						this->addChild(lw, backdepth, choiceS);	//���p�t
					}
					else if (pl1frame.choicejob == HEALER) {
						this->addChild(ll, backdepth, choiceS); //���E��
					}
				}
				else if (choices == CHAR2) {
					if (pl2frame.choicejob == ATTACKER) {
						this->addChild(lo, backdepth, choiceS);
					}
					else if (pl2frame.choicejob == SHIELD) {
						this->addChild(ls, backdepth, choiceS);
					}
					else if (pl2frame.choicejob == MAGIC) {
						this->addChild(lw, backdepth, choiceS);
					}
					else if (pl2frame.choicejob == HEALER) {
						this->addChild(ll, backdepth, choiceS);
					}
				}
				else if (choices == CHAR3) {
					if (pl3frame.choicejob == ATTACKER) {
						this->addChild(lo, backdepth, choiceS);
					}
					else if (pl3frame.choicejob == SHIELD) {
						this->addChild(ls, backdepth, choiceS);
					}
					else if (pl3frame.choicejob == MAGIC) {
						this->addChild(lw, backdepth, choiceS);
					}
					else if (pl3frame.choicejob == HEALER) {
						this->addChild(ll, backdepth, choiceS);
					}
				}
				else if (choices == CHOICETIME) {
					cho = CCLabelTTF::create("�ǂ̃L������I�����܂���", "HGRSGU.TTC", fontsizeL);
					cho->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
					this->addChild(cho, backdepth, choiceplS);
				}
			}
			//�I���L�����𖾊m�ɂ���(�I������ĂȂ��L�����͏����Â�����)
			if (choices == CHAR1) {
				//pl1frame�̎�
				//���m
				if (pl1frame.choicejob == ATTACKER) {
					PLattacker->setColor(ccc3(colormax, colormax, colormax));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//�R�m
				else if (pl1frame.choicejob == SHIELD) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colormax, colormax, colormax));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//���p�t
				else if (pl1frame.choicejob == MAGIC) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colormax, colormax, colormax));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//���E��
				else if (pl1frame.choicejob == HEALER) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colormax, colormax, colormax));
				}
			}
			if (choices == CHAR2) {
				//pl2frame�̎�
				if (pl2frame.choicejob == ATTACKER) {
					PLattacker->setColor(ccc3(colormax, colormax, colormax));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//�R�m
				else if (pl2frame.choicejob == SHIELD) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colormax, colormax, colormax));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//���p�t
				else if (pl2frame.choicejob == MAGIC) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colormax, colormax, colormax));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//���E��
				else if (pl2frame.choicejob == HEALER) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colormax, colormax, colormax));
				}
			}
			if (choices == CHAR3) {
				//pl3frame�̎�
				if (pl3frame.choicejob == ATTACKER) {
					PLattacker->setColor(ccc3(colormax, colormax, colormax));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//�R�m
				else if (pl3frame.choicejob == SHIELD) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colormax, colormax, colormax));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//���p�t
				else if (pl3frame.choicejob == MAGIC) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colormax, colormax, colormax));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//���E��
				else if (pl3frame.choicejob == HEALER) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colormax, colormax, colormax));
				}
			}
			

			// touchget, button���C�x���g�o�^����B
			auto director = Director::getInstance();
			director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(Atouchget, Abutton);
			auto director2 = Director::getInstance();
			director2->getEventDispatcher()->addEventListenerWithSceneGraphPriority(S1touchget, Sbutton);
			break;
		}
		//�v���C���[�̃A�N�V����(�G�t�F�N�g�Ȃ�)
		case BossScene::ACTION: {
			//�v���C���[�����̉摜�̐F��߂�
			PLattacker->setColor(ccc3(colormax, colormax, colormax));
			PLshield->setColor(ccc3(colormax, colormax, colormax));
			PLhealer->setColor(ccc3(colormax, colormax, colormax));
			PLmagic->setColor(ccc3(colormax, colormax, colormax));

			if (state == true) {
				gameflame++;							//�J�E���g�J�n
				skillflame++;							//�X�L���J�E���g�J�n
				PLturn();								//��ȏ���
				if (gameflame == flame0) {
					this->removeChildByTag(choiceS);
				}
			}
			break;
		}
		default: {
			break;
		}
		}
	}
	else if (turn == BOSS) {
		//������//

		//���m�̃_���[�W�\�������̏�����
		if(pl1frame.choicejob == ATTACKER){
			//���m�_���[�W�\��
			attackerdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			attackerdmf->setPosition(rightSize.width / 4, rightSize.height / 5.3f);
			attackerdmf->setColor(ccc3(colormax, colormin, colormin));
			//���m�_���[�W�\���̃t�F�[�h�A�E�g����
			attackerfadeout = CCFadeOut::create(2.0f);											//���b�ŏ�����H
			attackerfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 4, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}
		else if (pl2frame.choicejob == ATTACKER) {
			//���m�_���[�W�\��
			attackerdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			attackerdmf->setPosition(rightSize.width / 2, rightSize.height / 5.3f);
			attackerdmf->setColor(ccc3(colormax, colormin, colormin));
			//���m�_���[�W�\���̃t�F�[�h�A�E�g����
			attackerfadeout = CCFadeOut::create(2.0f);											//���b�ŏ�����H
			attackerfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 2, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}
		else if (pl3frame.choicejob == ATTACKER) {
			//���m�_���[�W�\��
			attackerdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			attackerdmf->setPosition(rightSize.width / 1.3f, rightSize.height / 5.3f);
			attackerdmf->setColor(ccc3(colormax, colormin, colormin));
			//���m�_���[�W�\���̃t�F�[�h�A�E�g����
			attackerfadeout = CCFadeOut::create(2.0f);												//���b�ŏ�����H
			attackerfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 1.3f, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}

		//�R�m�̃_���[�W�\�������̏�����
		if (pl1frame.choicejob == SHIELD) {
			//�R�m�_���[�W�\��
			shielddmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			shielddmf->setPosition(rightSize.width / 4, rightSize.height / 5.3f);
			shielddmf->setColor(ccc3(colormax, colormin, colormin));
			//�R�m�_���[�W�\���̃t�F�[�h�A�E�g����
			shieldfadeout = CCFadeOut::create(2.0f);									//���b�ŏ�����H
			shieldfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 4, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}
		else if (pl2frame.choicejob == SHIELD) {
			//�R�m�_���[�W�\��
			shielddmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			shielddmf->setPosition(rightSize.width / 2, rightSize.height / 5.3f);
			shielddmf->setColor(ccc3(colormax, colormin, colormin));
			//�R�m�_���[�W�\���̃t�F�[�h�A�E�g����
			shieldfadeout = CCFadeOut::create(2.0f);									//���b�ŏ�����H
			shieldfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 2, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}
		else if (pl3frame.choicejob == SHIELD) {
			//�R�m�_���[�W�\��
			shielddmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			shielddmf->setPosition(rightSize.width / 1.3f, rightSize.height / 5.3f);
			shielddmf->setColor(ccc3(colormax, colormin, colormin));
			//�R�m�_���[�W�\���̃t�F�[�h�A�E�g����
			shieldfadeout = CCFadeOut::create(2.0f);									//���b�ŏ�����H
			shieldfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 1.3f, rightSize.height / 5.3f + moverange)), NULL);//�_���[�W�\�����ړ�������
		}

		//���p�t�̃_���[�W�\�������̏�����
		if (pl1frame.choicejob == MAGIC) {
			//���p�t�_���[�W�\��
			magicdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			magicdmf->setPosition(rightSize.width / 4, rightSize.height / 5.3f);
			magicdmf->setColor(ccc3(colormax, colormin, colormin));
			//���p�t�_���[�W�\���̃t�F�[�h�A�E�g����
			magicfadeout = CCFadeOut::create(2.0f);											//���b�ŏ�����H
			magicfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 4, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}
		else if (pl2frame.choicejob == MAGIC) {
			//���p�t�_���[�W�\��
			magicdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			magicdmf->setPosition(rightSize.width / 2, rightSize.height / 5.3f);
			magicdmf->setColor(ccc3(colormax, colormin, colormin));
			//���p�t�_���[�W�\���̃t�F�[�h�A�E�g����
			magicfadeout = CCFadeOut::create(2.0f);											//���b�ŏ�����H
			magicfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 2, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}
		else if (pl3frame.choicejob == MAGIC) {
			//���p�t�_���[�W�\��
			magicdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			magicdmf->setPosition(rightSize.width / 1.3f, rightSize.height / 5.3f);
			magicdmf->setColor(ccc3(colormax, colormin, colormin));
			//���p�t�_���[�W�\���̃t�F�[�h�A�E�g����
			magicfadeout = CCFadeOut::create(2.0f);											//���b�ŏ�����H
			magicfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 1.3f, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}

		//���E�҂̃_���[�W�\�������̏�����
		if (pl1frame.choicejob == HEALER) {
			//���E�҃_���[�W�\��
			healerdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			healerdmf->setPosition(rightSize.width / 4, rightSize.height / 5.3f);
			healerdmf->setColor(ccc3(colormax, colormin, colormin));
			//���E�҃_���[�W�\���̃t�F�[�h�A�E�g����
			healerfadeout = CCFadeOut::create(2.0f);											//���b�ŏ�����H
			healerfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 4, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}
		else if (pl2frame.choicejob == HEALER) {
			//���E�҃_���[�W�\��
			healerdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			healerdmf->setPosition(rightSize.width / 2, rightSize.height / 5.3f);
			healerdmf->setColor(ccc3(colormax, colormin, colormin));
			//���E�҃_���[�W�\���̃t�F�[�h�A�E�g����
			healerfadeout = CCFadeOut::create(2.0f);											//���b�ŏ�����H
			healerfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 2, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}
		else if (pl3frame.choicejob == HEALER) {
			//���E�҃_���[�W�\��
			healerdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			healerdmf->setPosition(rightSize.width / 1.3f, rightSize.height / 5.3f);
			healerdmf->setColor(ccc3(colormax, colormin, colormin));
			//���E�҃_���[�W�\���̃t�F�[�h�A�E�g����
			healerfadeout = CCFadeOut::create(2.0f);											//���b�ŏ�����H
			healerfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 1.3f, rightSize.height / 5.3f + moverange)), NULL);	//�_���[�W�\�����ړ�������
		}

		flag = false;									//�t���O��false��
		gameflame++;									//�J�E���g�J�n
		BSturn();										//��ȏ���
		
		if (gameflame == flame170) {
			//����������
			this->removeChildByTag(normalattackS);		//�ʏ�U��
			this->removeChildByTag(bossskill1S);		//�X�L��1			
			this->removeChildByTag(bossskill2S);		//�X�L��2
			this->removeChildByTag(bossskill3S);		//�X�L��3
			this->removeChildByTag(bossskill4S);		//�X�L��4
		}
		if (gameflame > flamemax) {
			if (act_rnd < tenpercent) {
				//����������
				this->removeChildByTag(bossturnI);				//BSTURN
				this->removeChildByTag(damageS);				//���ʕ\�L(�ʏ�U��)
				this->removeChildByTag(bossskill1E);			//�p�[�e�B�N��
				this->removeChildByTag(bossskill1damageS);		//���ʕ\�L(�X�L��1)
				this->removeChildByTag(bossskill2damageS);		//���ʕ\�L(�X�L��2)
				this->removeChildByTag(bossskill3damageS);		//���ʕ\�L(�X�L��3)
				this->removeChildByTag(bossskill4damageS);		//���ʕ\�L(�X�L��4)

				gameflame = 0;									//���Ԃ�0��
				actcnt = 0;										//�J�E���g��0��
				fntflag = false;								//�_���[�W�\���t���O��false��
				job = NON;										//�I�񂾃L�����������̏�Ԃɖ߂�
				battle = START;									//�o�g���������̏�Ԃɖ߂�
				choices = CHAR1;								//�I���L�������ŏ���
				turn = PLAYER;									//�v���C���[�̃^�[����
			}
			if (act_rnd >= tenpercent && act_rnd <= rndmax) {
				if (actcnt < 1) {
					//����������
					this->removeChildByTag(damageS);			//���ʕ\�L(�ʏ�U��)
					this->removeChildByTag(bossskill1E);		//�p�[�e�B�N��
					this->removeChildByTag(bossskill1damageS);	//���ʕ\�L(�X�L��1)
					this->removeChildByTag(bossskill2damageS);	//���ʕ\�L(�X�L��2)
					this->removeChildByTag(bossskill3damageS);	//���ʕ\�L(�X�L��3)
					this->removeChildByTag(bossskill4damageS);	//���ʕ\�L(�X�L��4)

					pick_rnd = random(rndmin, rndmax);			//�w�肵���͈͓��̗������擾(�v���C���[�̃L������I��)
					act_rnd = random(rndmin, rndmax);			//�w�肵���͈͓��̗������擾(�{�X�̓�����)
					decide_rnd = random(rndmin, rndmax);		//�w�肵���͈͓��̗������擾(�{�X�̓���)
					skill_rnd = random(rndmin, rndmax);			//�w�肵���͈͓��̗������擾(�X�L��)

					actcnt += 1;								//�U���J�E���g�𑝂₵��2��ȏ�U�����Ȃ��悤�ɂ���
					gameflame = 0;								//���Ԃ�0��
					fntflag = false;							//�_���[�W�\���t���O��false��
					bsact = PICK;								//�{�X�̓����������ɖ߂�
					turn = BOSS;								//�������{�X�̍s����
				}
				else {
					//����������
					this->removeChildByTag(bossturnI);			//BSTURN
					this->removeChildByTag(damageS);			//���ʕ\�L(�ʏ�U��)
					this->removeChildByTag(bossskill1E);		//�p�[�e�B�N��
					this->removeChildByTag(bossskill1damageS);	//���ʕ\�L(�X�L��1)
					this->removeChildByTag(bossskill2damageS);	//���ʕ\�L(�X�L��2)
					this->removeChildByTag(bossskill3damageS);	//���ʕ\�L(�X�L��3)
					this->removeChildByTag(bossskill4damageS);	//���ʕ\�L(�X�L��4)

					gameflame = 0;								//���Ԃ�0��
					actcnt = 0;									//�J�E���g��0��
					fntflag = false;							//�_���[�W�\���t���O��false��
					job = NON;									//�I�񂾃L�����������̏�Ԃɖ߂�
					battle = START;								//�o�g���������̏�Ԃɖ߂�
					choices = CHAR1;							//�I���L�������ŏ���
					turn = PLAYER;								//�v���C���[�̃^�[����
				}
			}
		}
	}

	//���m��HP�Q�[�W�����炷
	attackerHP->setTextureRect(Rect(HPbar.x, HPbar.y,
		attackerhpgaugewidth * attacker.hp / attacker.hpmax,
		attackerHP->getContentSize().height));
	//���m��MANA�Q�[�W�ɕω�������
	attackerMN->setTextureRect(Rect(MNbar.x, MNbar.y,
		attackermngaugewidth * attacker.mana / attacker.manamax,
		attackerMN->getContentSize().height));
	//�R�m��HP�Q�[�W�����炷
	shieldHP->setTextureRect(Rect(HPbar.x, HPbar.y,
		shieldhpgaugewidth * shield.hp / shield.hpmax,
		shieldHP->getContentSize().height));
	//�R�m��MANA�Q�[�W�ɕω�������
	shieldMN->setTextureRect(Rect(MNbar.x, MNbar.y,
		shieldmngaugewidth * shield.mana / shield.manamax,
		shieldMN->getContentSize().height));
	//���p�t��HP�Q�[�W�����炷
	magicHP->setTextureRect(Rect(HPbar.x, HPbar.y,
		healerhpgaugewidth * magic.hp / magic.hpmax,
		magicHP->getContentSize().height));
	//���p�t��MANA�Q�[�W�ɕω�������
	magicMN->setTextureRect(Rect(MNbar.x, MNbar.y,
		healermngaugewidth * magic.mana / magic.manamax,
		magicMN->getContentSize().height));
	//���E�҂�HP�Q�[�W�����炷
	healerHP->setTextureRect(Rect(HPbar.x, HPbar.y,
		healerhpgaugewidth * healer.hp / healer.hpmax,
		healerHP->getContentSize().height));
	//���E�҂�MANA�Q�[�W�ɕω�������
	healerMN->setTextureRect(Rect(MNbar.x, MNbar.y,
		healermngaugewidth * healer.mana / healer.manamax,
		healerMN->getContentSize().height));
	//�{�X��HP�Q�[�W�ɕω�������
	HPboss->setTextureRect(Rect(HPbar.x, HPbar.y,
		bosshpgaugewidth * valkyrie.hp / valkyrie.hpmax,
		HPboss->getContentSize().height));

	//���ꂼ��̃L������HP�AMANA��MAX�ȏ�̎�MAX�ɂ���
	//���m
	if (attacker.hp >= attacker.hpmax) {
		attackerhpal->setString(std::to_string(attacker.hpmax));
		attacker.hp = attacker.hpmax;
	}
	if (attacker.mana >= attacker.manamax) {
		attackermnal->setString(std::to_string(attacker.manamax));
		attacker.mana = attacker.manamax;
	}
	//�R�m
	if (shield.hp >= shield.hpmax) {
		shieldhpal->setString(std::to_string(shield.hpmax));
		shield.hp = shield.hpmax;
	}
	if (shield.mana >= shield.manamax) {
		shieldmnal->setString(std::to_string(shield.manamax));
		shield.mana = shield.manamax;
	}
	//���p�t
	if (magic.hp >= magic.hpmax) {
		magichpal->setString(std::to_string(magic.hpmax));
		magic.hp = magic.hpmax;
	}
	if (magic.mana >= magic.manamax) {
		magicmnal->setString(std::to_string(magic.manamax));
		magic.mana = magic.manamax;
	}
	//���E��
	if (healer.hp >= healer.hpmax) {
		healerhpal->setString(std::to_string(healer.hpmax));
		healer.hp = healer.hpmax;
	}
	if (healer.mana >= healer.manamax) {
		healermnal->setString(std::to_string(healer.manamax));
		healer.mana = healer.manamax;
	}
	//���@���L�����[
	if (valkyrie.hp >= valkyrie.hpmax) {
		valkyrie.hp = valkyrie.hpmax;
	}
	if (valkyrie.mana >= valkyrie.manamax) {
		valkyrie.mana = valkyrie.manamax;
	}
	//���ꂼ��̃v���C���[��HP�AMANA��0�ȉ��̎�0�ɂ���
	//���m
	if (attacker.hp <= hpmin) {
		attackerhpal->setString(std::to_string(hpmin));
		attacker.hp = hpmin;
	}
	if (attacker.mana <= hpmin) {
		attackermnal->setString(std::to_string(hpmin));
		attacker.mana = hpmin;
	}
	//�R�m
	if (shield.hp <= hpmin) {
		shieldhpal->setString(std::to_string(hpmin));
		shield.hp = hpmin;
	}
	if (shield.mana <= hpmin) {
		shieldmnal->setString(std::to_string(hpmin));
		shield.mana = hpmin;
	}
	//���p�t
	if (magic.hp <= hpmin) {
		magichpal->setString(std::to_string(hpmin));
		magic.hp = hpmin;
	}
	if (magic.mana <= hpmin) {
		magicmnal->setString(std::to_string(hpmin));
		magic.mana = hpmin;
	}
	//���E��
	if (healer.hp <= hpmin) {
		healerhpal->setString(std::to_string(hpmin));
		healer.hp = hpmin;
	}
	if (healer.mana <= hpmin) {
		healermnal->setString(std::to_string(hpmin));
		healer.mana = hpmin;
	}
	//���S�����Ƃ�
	//PL1
	if (pl1 == PL1DEATH) {
		if (pl1frame.choicejob == ATTACKER) {
			PLattacker->setColor(ccc3(colordown, colordown, colordown));
		}
		else if (pl1frame.choicejob == SHIELD) {
			PLshield->setColor(ccc3(colordown, colordown, colordown));
		}
		else if (pl1frame.choicejob == MAGIC) {
			PLmagic->setColor(ccc3(colordown, colordown, colordown));
		}
		else if (pl1frame.choicejob == HEALER) {
			PLhealer->setColor(ccc3(colordown, colordown, colordown));
		}
	}
	//PL2
	else if (pl2 == PL2DEATH) {
		if (pl2frame.choicejob == ATTACKER) {
			PLattacker->setColor(ccc3(colordown, colordown, colordown));
		}
		else if (pl2frame.choicejob == SHIELD) {
			PLshield->setColor(ccc3(colordown, colordown, colordown));
		}
		else if (pl2frame.choicejob == MAGIC) {
			PLmagic->setColor(ccc3(colordown, colordown, colordown));
		}
		else if (pl2frame.choicejob == HEALER) {
			PLhealer->setColor(ccc3(colordown, colordown, colordown));
		}
	}
	//PL3
	else if (pl3 == PL3DEATH) {
		if (pl3frame.choicejob == ATTACKER) {
			PLattacker->setColor(ccc3(colordown, colordown, colordown));
		}
		else if (pl3frame.choicejob == SHIELD) {
			PLshield->setColor(ccc3(colordown, colordown, colordown));
		}
		else if (pl3frame.choicejob == MAGIC) {
			PLmagic->setColor(ccc3(colordown, colordown, colordown));
		}
		else if (pl3frame.choicejob == HEALER) {
			PLhealer->setColor(ccc3(colordown, colordown, colordown));
		}
	}
 }

void BossScene::PLturn()
{
	switch (choices)
	{
	case BossScene::CHAR1: {
		//�v���C���[1�̍s��

		if (pl1frame.choicejob == ATTACKER) {
			job = ATTACKER;
		}
		if (pl1frame.choicejob == SHIELD) {
			job = SHIELD;
		}
		if (pl1frame.choicejob == MAGIC) {
			job = MAGIC;
		}
		if (pl1frame.choicejob == HEALER) {
			job = HEALER;
		}
		//�ʏ�U���֘A
		if (pl1 == PL1ATTACK) {
			Plattacks();
		}
		//�v���C���[�X�L���֘A
		if (pl1 == PL1SKILL) {
			Plskills();
		}
		//�U���E�X�L�����I�������
		if (!(pl1 == PL1DEATH)) {
			if (attackendflag == true || skillendflag == true) {
				choices = CHAR2;								//���̃L������
				pl1 = PL1NON;									//pl1�͉������Ȃ��悤�ɂ���
				gameflame = 0;									//���Ԃ������l�ɖ߂�
				skillflame = 0;									//�X�L���̎��Ԃ������l��
				skillendflag = false;							//�t���O�����l�ɖ߂�
				attackendflag = false;							//�t���O��߂�
			}
		}
		if (pl1 == PL1DEATH) {
			choices = CHAR2;								//���̃L������
			gameflame = 0;									//���Ԃ������l�ɖ߂�
			skillflame = 0;									//�X�L���̎��Ԃ������l��
			skillendflag = false;							//�t���O�����l�ɖ߂�
			attackendflag = false;							//�t���O��߂�
		}
		break;
	}
	case BossScene::CHAR2: {
		//�v���C���[2�̍s��
		if (pl2frame.choicejob == ATTACKER) {
			job = ATTACKER;
		}
		if (pl2frame.choicejob == SHIELD) {
			job = SHIELD;
		}
		if (pl2frame.choicejob == MAGIC) {
			job = MAGIC;
		}
		if (pl2frame.choicejob == HEALER) {
			job = HEALER;
		}
		//�ʏ�U���֘A
		if (pl2 == PL2ATTACK) {
			Plattacks();
		}
		//�v���C���[�X�L���֘A
		if (pl2 == PL2SKILL) {
			Plskills();
		}
		if (!(pl2 == PL2DEATH)) {
			if (attackendflag == true || skillendflag == true) {
				choices = CHAR3;
				pl2 = PL2NON;
				gameflame = 0;									//���Ԃ������l�ɖ߂�
				skillflame = 0;									//�X�L���̎��Ԃ������l��
				skillendflag = false;							//�t���O�����l�ɖ߂�
				attackendflag = false;							//�t���O��߂�
			}
		}
		if (pl2 == PL2DEATH) {
			choices = CHAR3;
			gameflame = 0;									//���Ԃ������l�ɖ߂�
			skillflame = 0;									//�X�L���̎��Ԃ������l��
			skillendflag = false;							//�t���O�����l�ɖ߂�
			attackendflag = false;
		}
		break;
	}
	case BossScene::CHAR3: {
		//�v���C���[3�̍s��
		if (pl3frame.choicejob == ATTACKER) {
			job = ATTACKER;
		}
		if (pl3frame.choicejob == SHIELD) {
			job = SHIELD;
		}
		if (pl3frame.choicejob == MAGIC) {
			job = MAGIC;
		}
		if (pl3frame.choicejob == HEALER) {
			job = HEALER;
		}
		//�ʏ�U���֘A
		if (pl3 == PL3ATTACK) {
			Plattacks();
		}
		//�v���C���[�X�L���֘A
		if (pl3 == PL3SKILL) {
			Plskills();
		}
		if (!(pl3 == PL3DEATH)) {
			if (attackendflag == true || skillendflag == true) {
				turn = BOSS;								//�{�X�̃^�[���ɂ���
				bsact = PICK;								//�{�X�̓�����������
				choices = CHAR1;							//�I�����ŏ�����ɖ߂�
				pl3 == PL3NON;
				this->removeChildByTag(playertrunI);		//PLTURN������1
				gameflame = 0;								//���Ԃ������l�ɖ߂�
				skillflame = 0;								//�X�L���̎��Ԃ������l��
				skillendflag = false;						//�t���O�����l�ɖ߂�
				attackendflag = false;						//�t���O��߂�

				//BSTURN�����\��
				emturn = CCSprite::create("Description/BS.png");							// �z�u����
				emturn->setPosition(rightSize.width / 1.13, rightSize.height / 1.25f);		// �z�u�ꏊ
				this->addChild(emturn, backdepth, bossturnI);								// �ǉ�
			}
		}
		if (pl3 == PL3DEATH) {
			turn = BOSS;								//�{�X�̃^�[���ɂ���
			bsact = PICK;								//�{�X�̓�����������
			choices = CHAR1;							//�I�����ŏ�����ɖ߂�
			this->removeChildByTag(playertrunI);		//PLTURN������
			gameflame = 0;								//���Ԃ������l�ɖ߂�
			skillflame = 0;								//�X�L���̎��Ԃ������l��
			skillendflag = false;						//�t���O�����l�ɖ߂�
			attackendflag = false;						//�t���O��߂�
		}
		break;
	}
	default: {
		break;
	}
	}
	//HP��0�ɂȂ�����
	if (valkyrie.hp <= 0) {
		// �J�ڍ�̉�ʂ�ݽ�ݽ
		Scene *pScene = GameClear::createScene();
		// 0.6�b�����Ď���ʂɑJ��(����,�J�ڐ�,�F(�I�v�V����))
		TransitionFade *transition = TransitionFade::create(1.0, pScene);
		// �J�ڎ��s �A�j���[�V����
		Director::getInstance()->replaceScene(transition);
	}
}

void BossScene::Plattacks()
{
	//���m
	if (job == ATTACKER) {
		if (gameflame == flame50) {
			//�ʏ�U��
			//�{�X��HP�����炷
			Damage();
			Boss->runAction(bossrepeat);
			hpcut = (attacker.atk - valkyrie.def);
			//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
			if (hpcut <= 1) {
				hpcut = 1;
			}
			valkyrie.hp -= hpcut;
			//�_���[�W�\�L
			String *attackeratk = String::createWithFormat("���m��%i�_���[�W�^����", hpcut);
			string _attackeratk = attackeratk->getCString();
			auto attackeralabel = Label::createWithSystemFont(_attackeratk, "HGRSGU.TTC", fontsizeL);
			attackeralabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(attackeralabel, backdepth, attackerdamageS);
		}
		//�U���I���
		if (gameflame == flame80) {
			this->removeChildByTag(attackerdamageS);
			attackendflag = true;
		}
	}
	//�R�m
	if (job == SHIELD) {
		if (gameflame == flame50) {
			//�ʏ�U��
			//�{�X��HP�����炷
			hpcut = (shield.atk - valkyrie.def);
			//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
			if (hpcut <= 1) {
				hpcut = 1;
			}
			valkyrie.hp -= hpcut;
			//�_���[�W�\�L
			String *shieldatk = String::createWithFormat("�R�m��%i�_���[�W�^����", hpcut);
			string _shieldatk = shieldatk->getCString();
			auto shieldalabel = Label::createWithSystemFont(_shieldatk, "HGRSGU.TTC", fontsizeL);
			shieldalabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(shieldalabel, backdepth, shielddamageS);
		}
		//�U���I���
		if (gameflame == flame80) {
			this->removeChildByTag(shielddamageS);
			attackendflag = true;
		}
	}
	//���p�t
	if (job == MAGIC) {
		if (gameflame == flame50) {
			//�ʏ�U��
			//�{�X��HP�����炷
			hpcut = (magic.atk - valkyrie.def);
			//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
			if (hpcut <= 1) {
				hpcut = 1;
			}
			valkyrie.hp -= hpcut;
			//�_���[�W�\�L
			String *magicatk = String::createWithFormat("���p�t��%i�_���[�W�^����", hpcut);
			string _magicatk = magicatk->getCString();
			auto magicalabel = Label::createWithSystemFont(_magicatk, "HGRSGU.TTC", fontsizeL);
			magicalabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(magicalabel, backdepth, magicdamageS);

		}
		//�U���I���
		if (gameflame == flame80) {
			this->removeChildByTag(magicdamageS);
			attackendflag = true;
		}
	}
	//���E��
	if (job == HEALER) {
		if (gameflame == flame50) {
			//�ʏ�U��
			//�{�X��HP�����炷
			hpcut = (healer.atk - valkyrie.def);
			//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
			if (hpcut <= 1) {
				hpcut = 1;
			}
			valkyrie.hp -= hpcut;
			//�_���[�W�\�L
			String *healeratk = String::createWithFormat("���E�҂�%i�_���[�W�^����", hpcut);
			string _healeratk = healeratk->getCString();
			auto healeralabel = Label::createWithSystemFont(_healeratk, "HGRSGU.TTC", fontsizeL);
			healeralabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(healeralabel, backdepth, healerdamageS);
		}
		//�U���I���
		if (gameflame == flame80) {
			this->removeChildByTag(healerdamageS);
			attackendflag = true;
		}
	}
}

void BossScene::Plskills()
{
//���m
	if (job == ATTACKER) {
		//�c�C���t���[��
		if (askill == ASKILL1) {
			if (gameflame == flame50) {
				//�G�P�̂ɏ��_���[�W2��U��
				//�v���C���[�P�̌��炷MANA
				attacker.mana -= 3;
				//MANA�̐��l��ς���
				attackermnal->setString(std::to_string(attacker.mana));
				//�{�X��HP�����炷
				hpcut = attacker.atk * skilluplittle - valkyrie.def;
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//���ʏ���
				valkyrie.hp -= hpcut;
				//�_���[�W�\�L
				String *attackerskl = String::createWithFormat("���m��%i�_���[�W�^����", hpcut);
				string _attackerskl = attackerskl->getCString();
				auto p1slabel = Label::createWithSystemFont(_attackerskl, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame80) {
				this->removeChildByTag(attackerdamageS);		//�_���[�W�\�L������
			}
			//2��ڂ̃_���[�W��^����
			if (skillflame == flame150) {
				//���ʏ���
				valkyrie.hp -= hpcut;
				//�_���[�W�\�L
				String *attackerskl = String::createWithFormat("���m��%i�_���[�W�^����", hpcut);
				string _attackerskl = attackerskl->getCString();
				auto attackerslabel = Label::createWithSystemFont(_attackerskl, "HGRSGU.TTC", fontsizeL);
				attackerslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerslabel, backdepth, attackerdamageS);
			}
			//�X�L���I���
			if (skillflame == flame200) {
				this->removeChildByTag(askill1E);				//�G�t�F�N�g������
				this->removeChildByTag(attackerdamageS);		//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�A�[�}�[�u���C�N
		if (askill == ASKILL2) {
			if (skillflame == flame50) {
				//�G�P�̂ɏ��_���[�W+�h��̓_�E��
				//�v���C���[�P�̌��炷MANA
				attacker.mana -= 2;

				//MANA�̐��l��ς���
				attackermnal->setString(std::to_string(attacker.mana));
				//�{�X��HP�����炷
				hpcut = (attacker.atk - valkyrie.def);
				//�G�̃X�e�[�^�X(�h���)��������l�����߂�
				//���̖h��͂�2�����炷
				buffdown = valkyrie.def * buffdownlittle;
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//���ʏ���
				valkyrie.hp -= hpcut;
				valkyrie.def -= buffdown;
				//�X�L�����ʃ^�[���ɂ�鏈��
				if (askill2.buffturn1 == 0) {
					askill2.buffturn1 = 1;
					askill2.buffdownefect1 = buffdown;
				}
				else if (askill2.buffturn2 == 0) {
					askill2.buffturn2 = 1;
					askill2.buffdownefect2 = buffdown;
				}
				else if (askill2.buffturn3 == 0) {
					askill2.buffturn3 = 1;
					askill2.buffdownefect3 = buffdown;
				}
				//�_���[�W�\�L
				String *attackerskl = String::createWithFormat("���m��%i�_���[�W�^����", hpcut);
				string _attackerskl = attackerskl->getCString();
				auto attackerslabel = Label::createWithSystemFont(_attackerskl, "HGRSGU.TTC", fontsizeL);
				attackerslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerslabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame100) {
				this->removeChildByTag(askill1E);				//�G�t�F�N�g������
				this->removeChildByTag(attackerdamageS);		//�_���[�W�\�L������
				auto pl1buffdown = CCLabelTTF::create("���@���L�����[�̖h��͂�������������", "HGRSGU.TTC", fontsizeM);
				pl1buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl1buffdown, backdepth, buffdownS);
			}
			if (skillflame == flame150) {
				this->removeChildByTag(askill1E);				//�G�t�F�N�g������
				this->removeChildByTag(buffdownS);				//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//���C�t�\�[�h
		if (askill == ASKILL3) {
			if (skillflame == flame50) {
				//�G�P�̂ɏ��_���[�W�{���g��HP������
				//�v���C���[�P�̌��炷MANA
				attacker.mana -= 2;

				//MANA�̐��l��ς���
				attackermnal->setString(std::to_string(attacker.mana));
				//�{�X��HP�����炷
				hpcut = (attacker.atk - valkyrie.def);
				//�񕜂���l�����߂�
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//����HP��2����
				recovery = hpcut * buffdownlittle;
				//���ʏ���
				valkyrie.hp -= hpcut;
				attacker.hp += recovery;
				attackerhpal->setString(std::to_string(attacker.hp));
				//�_���[�W�\�L
				String *attackerskl = String::createWithFormat("���m��%i�_���[�W�^����", hpcut);
				string _attackerskl = attackerskl->getCString();
				auto attackerslabel = Label::createWithSystemFont(_attackerskl, "HGRSGU.TTC", fontsizeL);
				attackerslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerslabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//�G�t�F�N�g������
				this->removeChildByTag(attackerdamageS);				//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�C���p�N�g�X���b�V��
		if (askill == ASKILL4) {
			if (skillflame == flame50) {
				//�G�P�̂ɏ��_���[�W+�U���̓_�E��
				//�v���C���[�P�̌��炷MANA
				attacker.mana -= 2;

				//MANA�̐��l��ς���
				attackermnal->setString(std::to_string(attacker.mana));
				//�{�X��HP�����炷
				hpcut = (attacker.atk - valkyrie.def);
				//�G�̃X�e�[�^�X(�U����)��������l�����߂�
				//���̍U���͂�2�����炷
				buffdown = valkyrie.atk * buffdownlittle;
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//���ʏ���
				valkyrie.hp -= hpcut;
				valkyrie.atk -= buffdown;
				//�X�L�����ʃ^�[���ɂ�鏈��
				if (askill4.buffturn1 == 0) {
					askill4.buffturn1 = 1;
					askill4.buffdownefect1 = buffdown;
				}
				else if (askill4.buffturn2 == 0) {
					askill4.buffturn2 = 1;
					askill4.buffdownefect2 = buffdown;
				}
				else if (askill4.buffturn3 == 0) {
					askill4.buffturn3 = 1;
					askill4.buffdownefect3 = buffdown;
				}
				//�_���[�W�\�L
				String *attackerskl = String::createWithFormat("���m��%i�_���[�W�^����", hpcut);
				string _attackerskl = attackerskl->getCString();
				auto attackerslabel = Label::createWithSystemFont(_attackerskl, "HGRSGU.TTC", fontsizeL);
				attackerslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerslabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame100) {
				this->removeChildByTag(attackerdamageS);	//�_���[�W�\�L������
				auto pl1buffdown = CCLabelTTF::create("���@���L�����[�̍U���͂�������������", "HGRSGU.TTC", fontsizeM);
				pl1buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl1buffdown, backdepth, buffdownS);
				
			}
			if (skillflame == flame150) {
				this->removeChildByTag(askill1E);			//�G�t�F�N�g������
				this->removeChildByTag(buffdownS);			//�_���[�W�\�L������
				skillendflag = true;
			
			}
		}
		//�\�[�h�X���[
		if (askill == ASKILL5) {
			if (skillflame == flame50) {
				//�G�P�̂ɖh��͖����̒��_���[�W
				//�G�t�F�N�g�̕\��
				//�G�t�F�N�g�̗�����w��
				CCParticleSystemQuad* plparticle = CCParticleSystemQuad::create("Effect/plskill2.plist");
				plparticle->setAutoRemoveOnFinish(true);
				//�G�t�F�N�g����
				plparticle->resetSystem();								//�p�[�e�B�N���J�n
				plparticle->setPosition(ccp(rightSize.width / 2,
					rightSize.height / 1.7f));							//�p�[�e�B�N����\������ꏊ�̐ݒ�
				this->addChild(plparticle, backdepth, askill1E);		//�p�[�e�B�N����z�u
				//�v���C���[�P�̌��炷MANA
				attacker.mana -= 4;

				//MANA�̐��l��ς���
				attackermnal->setString(std::to_string(attacker.mana));
				//�{�X��HP�����炷
				//�h�䖳���Ȃ̂œG�̖h��͂������Ȃ�
				hpcut = attacker.atkmax * skillupmedium;
				//���ʏ���
				valkyrie.hp -= hpcut;
				//�_���[�W�\�L
				String *attackerskl = String::createWithFormat("���m��%i�_���[�W�^����", hpcut);
				string _attackerskl = attackerskl->getCString();
				auto attackerslabel = Label::createWithSystemFont(_attackerskl, "HGRSGU.TTC", fontsizeL);
				attackerslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerslabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//�G�t�F�N�g������
				this->removeChildByTag(attackerdamageS);		//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�g�@��
		if (askill == ASKILL6) {
			if (skillflame == flame50) {
				//�G�P�̂ɑ�_���[�W
				//�v���C���[�P�̌��炷MANA
				attacker.mana -= 5;

				//MANA�̐��l��ς���
				attackermnal->setString(std::to_string(attacker.mana));
				//�{�X��HP�����炷
				//���̍U���͂̔{�̃_���[�W��^����
				hpcut = (attacker.atk * skilluplarge) - valkyrie.def;
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//���ʏ���
				valkyrie.hp -= hpcut;
				//�_���[�W�\�L
				String *attackerskl = String::createWithFormat("���m��%i�_���[�W�^����", hpcut);
				string _attackerskl = attackerskl->getCString();
				auto attackerslabel = Label::createWithSystemFont(_attackerskl, "HGRSGU.TTC", fontsizeL);
				attackerslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerslabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//�G�t�F�N�g������
				this->removeChildByTag(attackerdamageS);				//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�R���f�B�N�V����
		if (askill == ASKILL7) {
			if (skillflame == flame50) {
				//3�^�[���̊ԁA���g�̍U���͂����A�b�v
				//�v���C���[�P�̌��炷MANA
				attacker.mana -= 3;

				//MANA�̐��l��ς���
				attackermnal->setString(std::to_string(attacker.mana));
				//�A�^�b�J�[�̌��̍U���͂�2���قǍU���͂��グ��
				buffup = attacker.atkmax * buffdownlittle;
				//���ʏ���
				attacker.atk += buffup;
				//�X�L�����ʃ^�[���ɂ�鏈��
				if (askill7.buffturn1 == 0) {
					askill7.buffturn1 = 4;
					askill7.buffupefect1 = buffup;
				}
				else if (askill7.buffturn2 == 0) {
					askill7.buffturn2 = 4;
					askill7.buffupefect2 = buffup;
				}
				else if (askill7.buffturn3 == 0) {
					askill7.buffturn3 = 4;
					askill7.buffupefect3 = buffup;
				}
				else if (askill7.buffturn4 == 0) {
					askill7.buffturn4 = 4;
					askill7.buffupefect4 = buffup;
				}
				//�_���[�W�\�L
				String *attackerbuff = String::createWithFormat("���m��%i�U���͂������A�b�v����", buffup);
				string _attackerbuff = attackerbuff->getCString();
				auto attackerslabel = Label::createWithSystemFont(_attackerbuff, "HGRSGU.TTC", fontsizeL);
				attackerslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerslabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//�G�t�F�N�g������
				this->removeChildByTag(attackerdamageS);		//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�E�H���A�[�E�H�[�N���C
		if (askill == ASKILL8) {
			if (skillflame == flame50) {
				//3�^�[���̊ԁA���g�̍U���͂��A�b�v�E�h��͏��_�E��
				//�v���C���[�P�̌��炷MANA
				attacker.mana -= 7;
				//MANA�̐��l��ς���
				attackermnal->setString(std::to_string(attacker.mana));
				//�A�^�b�J�[�̍U���͂��グ��
				//�A�^�b�J�[�̌��̍U���͂Ԃ�U���͂��グ��
				buffup = attacker.atkmax;
				//�A�^�b�J�[�̖h��͂�������
				buffdown = attacker.def * buffdownlarge;
				//���ʏ���
				attacker.atk += buffup;
				attacker.def -= buffdown;
				//�X�L�����ʃ^�[���ɂ�鏈��
				if (askill8.buffturn1 == 0) {
					askill8.buffturn1 = 5;				//��������^�[��
					askill8.buffupefect1 = buffup;		//�オ�������̃X�e�[�^�X���L��
					askill8.buffdownefect1 = buffdown;	//�����������̃X�e�[�^�X���L��
				}
				else if (askill8.buffturn2 == 0) {
					askill8.buffturn2 = 5;
					askill8.buffupefect2 = buffup;
					askill8.buffdownefect2 = buffdown;
				}
				else if (askill8.buffturn3 == 0) {
					askill8.buffturn3 = 5;
					askill8.buffupefect3 = buffup;
					askill8.buffdownefect3 = buffdown;
				}
				else if (askill8.buffturn4 == 0) {
					askill8.buffturn4 = 5;
					askill8.buffupefect4 = buffup;
					askill8.buffdownefect4 = buffdown;
				}

				//�_���[�W�\�L
				String *attackerbuf = String::createWithFormat("���m�͍U���͂��啝�ɃA�b�v����", buffup);
				string _attackerbuf = attackerbuf->getCString();
				auto attackerslabel = Label::createWithSystemFont(_attackerbuf, "HGRSGU.TTC", fontsizeL);
				attackerslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerslabel, backdepth, attackerdamageS);
			}
			//�X�e�[�^�X�ω��\�L
			if (skillflame == flame100) {
				this->removeChildByTag(attackerdamageS);
				auto pl1buffdown = CCLabelTTF::create("���m�̖h��͂�������������", "HGRSGU.TTC", fontsizeL);
				pl1buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl1buffdown, backdepth, buffdownS);
			}
			if (skillflame == flame150) {
				this->removeChildByTag(askill1E);				//�G�t�F�N�g������
				this->removeChildByTag(buffdownS);				//�X�e�[�^�X�ω��\�L������
				skillendflag = true;
			}
		}
	}
//�R�m
	if (job == SHIELD) {
		//�A�C���X�]�C��
		if (sskill == SSKILL1) {
			//�G�P�̂ɏ��_���[�W�̂Q��U��
			if (gameflame == flame50) {
				//�G�P�̂ɏ��_���[�W2��U��
				//�v���C���[�P�̌��炷MANA
				shield.mana -= 3;
				//MANA�̐��l��ς���
				attackermnal->setString(std::to_string(attacker.mana));
				//�{�X��HP�����炷
				hpcut = attacker.atk * skilluplittle - valkyrie.def;
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//���ʏ���
				valkyrie.hp -= hpcut;
				//�_���[�W�\�L
				String *shieldskl = String::createWithFormat("�R�m��%i�_���[�W�^����", hpcut);
				string _shieldskl = shieldskl->getCString();
				auto shieldslabel = Label::createWithSystemFont(_shieldskl, "HGRSGU.TTC", fontsizeL);
				shieldslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(shieldslabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame80) {
				this->removeChildByTag(attackerdamageS);		//�_���[�W�\�L������
			}
			//2��ڂ̃_���[�W��^����
			if (skillflame == flame150) {
				//���ʏ���
				valkyrie.hp -= hpcut;
				//�_���[�W�\�L
				String *shieldskl = String::createWithFormat("�R�m��%i�_���[�W�^����", hpcut);
				string _shieldskl = shieldskl->getCString();
				auto shieldslabel = Label::createWithSystemFont(_shieldskl, "HGRSGU.TTC", fontsizeL);
				shieldslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(shieldslabel, backdepth, attackerdamageS);
			}
			//�X�L���I���
			if (skillflame == flame200) {
				this->removeChildByTag(askill1E);				//�G�t�F�N�g������
				this->removeChildByTag(attackerdamageS);		//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�J�E���^�[
		if (sskill == SSKILL2) {
			//�U�����󂯂��Ƃ��A�G���U������
		}
		//�őO��
		if (sskill == SSKILL3) {
			//�G�̍U�������g�ɏW��������
			if (gameflame == flame50) {
				//�R�m�̏����}�i�����߂�
				shield.mana -= 2;
				//MANA�̐��l��ς���
				shieldmnal->setString(std::to_string(shield.mana));

				// �X�L�����ʃ^�[���ɂ�鏈��
					if (sskill3.buffturn1 == 0) {
						sskill3.buffturn1 = 2;	//�X�L���̌��ʂ���������^�[�������߂�
						coverflag1 = true;		//�^�Q�W���t���O���I���ɂ���
					}
					else if (sskill3.buffturn3 == 0) {
						sskill3.buffturn2= 2;	//�X�L���̌��ʂ���������^�[�������߂�
						coverflag2= true;		//�^�Q�W���t���O���I���ɂ���
					}

				//���ʕ\�L
				auto shieldcover = CCLabelTTF::create("�R�m�ɍU�����W������", "HGRSGU.TTC", fontsizeL);
				shieldcover->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(shieldcover, backdepth, coverS);
			}
			if (gameflame == flame100) {
				this->removeChildByTag(coverS);	//�X�e�[�^�X�ω��\�L������
				skillendflag = true;			//�X�L���I���
			}

		}
		//�g����̕X��
		if (sskill == SSKILL4) {
			//�����P�̂ւ̃_���[�W�����Ɏ󂯂�
			if (gameflame == flame50) {
				//�R�m�̏����}�i�����߂�
				shield.mana -= 2;
				//MANA�̐��l��ς���
				shieldmnal->setString(std::to_string(shield.mana));

				// �X�L�����ʃ^�[���ɂ�鏈��
				if (sskill4.buffturn1 == 0) {
					sskill4.buffturn1 = 1;	//�X�L���̌��ʂ���������^�[�������߂�
					insteadflag = true;		//�g����t���O���I���ɂ���
				}

				//���m��I�񂾏ꍇ
				if (sskillchoice == ATTACKER) {
					//���ʕ\�L
					auto shieldinstead = CCLabelTTF::create("���m�̑���ɍU�����󂯂�", "HGRSGU.TTC", fontsizeL);
					shieldinstead->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
					this->addChild(shieldinstead, backdepth, insteadS);
				}
				//���p�t��I�񂾏ꍇ
				else if (sskillchoice == MAGIC) {
					auto shieldinstead = CCLabelTTF::create("���p�t�̑���ɍU�����󂯂�", "HGRSGU.TTC", fontsizeL);
					shieldinstead->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
					this->addChild(shieldinstead, backdepth, insteadS);
				}
				//���E�҂�I�񂾏ꍇ
				else if (sskillchoice == HEALER) {
					auto shieldinstead = CCLabelTTF::create("���E�҂̑���ɍU�����󂯂�", "HGRSGU.TTC", fontsizeL);
					shieldinstead->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
					this->addChild(shieldinstead, backdepth, insteadS);
				}


			}
			if (gameflame == flame100) {
				this->removeChildByTag(insteadS);	//�X�e�[�^�X�ω��\�L������
				skillendflag = true;				//�X�L���I���
			}
		}
		//�Q���X��
		if (sskill == SSKILL5) {
			//�����S���ւ̃_���[�W�����Ɏ󂯂�
			if (gameflame == flame50) {
				//�R�m�̏����}�i�����߂�
				shield.mana -= 3;
				//MANA�̐��l��ς���
				shieldmnal->setString(std::to_string(shield.mana));

				// �X�L�����ʃ^�[���ɂ�鏈��
				if (sskill5.buffturn1 == 0) {
					sskill5.buffturn1 = 1;	//�X�L���̌��ʂ���������^�[�������߂�
					allinsteadflag = true;		//�g����t���O���I���ɂ���
				}

				//���ʕ\�L
				auto shieldinstead = CCLabelTTF::create("�S���̑���ɍU�����󂯂�", "HGRSGU.TTC", fontsizeL);
				shieldinstead->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(shieldinstead, backdepth, insteadS);
			}
			if (gameflame == flame100) {
				this->removeChildByTag(insteadS);	//�X�e�[�^�X�ω��\�L������
				skillendflag = true;			//�X�L���I���
			}
		}
		//�ە�����Y����
		if (sskill == SSKILL6) {
			//�퓬�s�\���P�x�������g��HP�P�ŕ�������
		}
		//�X�̌��
		if (sskill == SSKILL7) {
			if (skillflame == flame50) {
				//5�^�[���̊ԁA���g�̖h��͂����A�b�v
				//�v���C���[�P�̌��炷MANA
				shield.mana -= 2;

				//MANA�̐��l��ς���
				shieldmnal->setString(std::to_string(shield.mana));
				//�A�^�b�J�[�̌��̍U���͂�2���قǍU���͂��グ��
				buffup = shield.defmax * buffdownlittle;
				//���ʏ���
				shield.atk += buffup;
				//�X�L�����ʃ^�[���ɂ�鏈��
				if (sskill7.buffturn1 == 0) {
					sskill7.buffturn1 = 5;
					sskill7.buffupefect1 = buffup;
				}
				else if (sskill7.buffturn2 == 0) {
					sskill7.buffturn2 = 5;
					sskill7.buffupefect2 = buffup;
				}
				else if (sskill7.buffturn3 == 0) {
					sskill7.buffturn3 = 5;
					sskill7.buffupefect3 = buffup;
				}
				else if (sskill7.buffturn4 == 0) {
					sskill7.buffturn4 = 5;
					sskill7.buffupefect4 = buffup;
				}
				else if (sskill7.buffturn5 == 0) {
					sskill7.buffturn5 = 5;
					sskill7.buffupefect5 = buffup;
				}
				//�_���[�W�\�L
				String *shieldbuff = String::createWithFormat("�R�m��%i�h��͂������A�b�v����", buffup);
				string _shieldbuff = shieldbuff->getCString();
				auto shieldslabel = Label::createWithSystemFont(_shieldbuff, "HGRSGU.TTC", fontsizeL);
				shieldslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(shieldslabel, backdepth, shielddamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);			//�G�t�F�N�g������
				this->removeChildByTag(shielddamageS);		//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�R�m������
		if (sskill == SSKILL8) {
			if (skillflame == flame50) {
				//4�^�[���̊ԁA���g�̖h��͂��A�b�v�E�U���͏��_�E��
				//�v���C���[�P�̌��炷MANA
				shield.mana -= 6;

				//MANA�̐��l��ς���
				shieldmnal->setString(std::to_string(shield.mana));
				//�R�m�̌��̖h��͂�2���قǍU���͂��グ��
				buffup = shield.defmax;
				buffdown = shield.atk * buffdownlarge;
				//���ʏ���
				shield.def += buffup;
				shield.atk -= buffdown;
				//�X�L�����ʃ^�[���ɂ�鏈��
				if (sskill8.buffturn1 == 0) {
					sskill8.buffturn1 = 4;
					sskill8.buffupefect1 = buffup;
					sskill8.buffdownefect1 = buffdown;
				}
				else if (sskill8.buffturn2 == 0) {
					sskill8.buffturn2 = 4;
					sskill8.buffupefect2 = buffup;
					sskill8.buffdownefect1 = buffdown;
				}
				else if (sskill8.buffturn3 == 0) {
					sskill8.buffturn3 = 4;
					sskill8.buffupefect3 = buffup;
					sskill8.buffdownefect1 = buffdown;
				}
				else if (sskill8.buffturn4 == 0) {
					sskill8.buffturn4 = 4;
					sskill8.buffupefect4 = buffup;
					sskill8.buffdownefect1 = buffdown;
				}
				//�X�e�[�^�X�ω��\�L
				String *shieldbuff = String::createWithFormat("�R�m�͖h��͂��啝�ɃA�b�v����", buffup);
				string _shieldbuff = shieldbuff->getCString();
				auto shieldslabel = Label::createWithSystemFont(_shieldbuff, "HGRSGU.TTC", fontsizeL);
				shieldslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(shieldslabel, backdepth, shielddamageS);
			}
			//�X�e�[�^�X�ω��\�L
			if (skillflame == flame100) {
				this->removeChildByTag(shielddamageS);		//�_���[�W�\�L������
				auto shieldbuffdown = CCLabelTTF::create("�R�m�̍U���͂�������������", "HGRSGU.TTC", fontsizeL);
				shieldbuffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(shieldbuffdown, backdepth, buffdownS);
			}
			if (skillflame == flame150) {
				this->removeChildByTag(buffdownS);				//�X�e�[�^�X�ω��\�L������
				skillendflag = true;
			}
		}
	}
//���p�t
	if (job == MAGIC) {
		//�}�W�b�N�~�T�C��
		if (mskill == MSKILL1) {
			if (gameflame == flame50) {
				//�G�P�̂ɏ��_���[�W
				//�G�t�F�N�g�̕\��
				//�G�t�F�N�g�̗�����w��
				CCParticleSystemQuad* plparticle3 = CCParticleSystemQuad::create("Effect/plskill3.plist");
				plparticle3->setAutoRemoveOnFinish(true);

				//�G�t�F�N�g����
				plparticle3->resetSystem();								//�p�[�e�B�N���J�n
				plparticle3->setPosition(ccp(rightSize.width / 2,
					rightSize.height / 1.7f));							//�p�[�e�B�N����\������ꏊ�̐ݒ�
				this->addChild(plparticle3, backdepth, mskill1E);		//�p�[�e�B�N����z�u

				//�v���C���[3��MANA�����炷
				magic.mana -= 5;
				//MANA�̐��l��ς���
				magicmnal->setString(std::to_string(magic.mana));
				//�{�X��HP�����炷
				hpcut = (magic.matk - valkyrie.mdef);
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				//�_���[�W�\�L
				String *p3skl = String::createWithFormat("���p�t��%i�_���[�W�^����", hpcut);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			//�X�L���I���
			if (skillflame == flame250) {
				this->removeChildByTag(mskill1E);			//���邮�邵�Ă���
				this->removeChildByTag(magicdamageS);			//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�A�[�}�[�V���b�g
		if(mskill == MSKILL2) {
			if (gameflame == flame50) {
				//�G�P�̂ɏ��_���[�W+���g�̖h�䏬�A�b�v
				//�v���C���[3��MANA�����炷
				magic.mana -= 3;
				//MANA�̐��l��ς���
				magicmnal->setString(std::to_string(magic.mana));
				//�{�X��HP�����炷
				hpcut = (magic.matk - valkyrie.mdef);
				buffup = magic.def / skilluplarge;
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				magic.def += buffup;
				//�X�L�����ʃ^�[���ɂ�鏈��
				if (mskill2.buffturn1 == 0) {
					mskill2.buffturn1 = 1;
					mskill2.buffupefect1 = buffup;
				}
				else if (mskill2.buffturn2 == 0) {
					mskill2.buffturn2 = 1;
					mskill2.buffupefect2 = buffup;
				}
				

				//�_���[�W�\�L
				String *p3skl = String::createWithFormat("���p�t��%i�_���[�W�^����", hpcut);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			if (skillflame == flame100) {
				this->removeChildByTag(magicdamageS);
				auto pl3buffdown = CCLabelTTF::create("���p�t�̖h��͂������オ����", "HGRSGU.TTC", fontsizeL);
				pl3buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl3buffdown, backdepth, buffdownS);
			}
			if (skillflame == flame150) {
				this->removeChildByTag(mskill1E);			//���邮�邵�Ă���
				this->removeChildByTag(magicdamageS);			//�_���[�W�\�L������
				this->removeChildByTag(buffdownS);
				skillendflag = true;
			}
		}
		//�}�W�b�N�o�[�X�g
		if (mskill == MSKILL3) {
			if (gameflame == flame50) {
				//�G�P�̂ɒ��_���[�W + �G�̍U���_�E��
				//�v���C���[3��MANA�����炷
				magic.mana -= 3;
				//MANA�̐��l��ς���
				magicmnal->setString(std::to_string(magic.mana));
				//�{�X��HP�����炷
				hpcut = (magic.matk * skillupmedium) - valkyrie.mdef;
				//���p�t�̍��̍U���͂̂T���̍U���͂�������
				buffdown = valkyrie.atk * buffdownlittle;
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				valkyrie.atk -= buffdown;
				//�X�L�����ʃ^�[���ɂ�鏈��
				if (mskill3.buffturn1 == 0) {
					mskill3.buffturn1 = 1;
					mskill3.buffdownefect1 = buffdown;
				}
				else if (mskill3.buffturn2 == 0) {
					mskill3.buffturn2 = 1;
					mskill3.buffdownefect2 = buffdown;
				}

				//�_���[�W�\�L
				String *p3skl = String::createWithFormat("���p�t��%i�_���[�W�^����", buffdown);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			if (skillflame == flame100) {
				this->removeChildByTag(magicdamageS);
				auto pl3buffdown = CCLabelTTF::create("�G�̍U���͂���������", "HGRSGU.TTC", fontsizeL);
				pl3buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl3buffdown, backdepth, buffdownS);
			}
			if (skillflame == flame150) {
				this->removeChildByTag(mskill1E);			//���邮�邵�Ă���
				this->removeChildByTag(magicdamageS);			//�_���[�W�\�L������
				this->removeChildByTag(buffdownS);
				skillendflag = true;
			}
		}
		//VFD
		if (mskill == MSKILL4) {
			if (gameflame == flame50) {
				//�G�P�̂ɓ���_���[�W
				//�v���C���[3��MANA�����炷
				magic.mana -= 7;
				//MANA�̐��l��ς���
				magicmnal->setString(std::to_string(magic.mana));
				//�{�X��HP�����炷
				hpcut = (magic.matk * skilluplarge) - valkyrie.mdef;
				//�������炷HP��1�ȉ��̏ꍇ���炷HP��1�ɂ���
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				//�_���[�W�\�L
				String *p3skl = String::createWithFormat("���p�t��%i�_���[�W�^����", hpcut);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			//�X�L���I���
			if (skillflame == flame250) {
				this->removeChildByTag(mskill1E);			//���邮�邵�Ă���
				this->removeChildByTag(magicdamageS);			//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�O�����c
		if (mskill == MSKILL5) {
			if (gameflame == flame50) {
				//3�^�[���̊ԁA�����S�̂̍U���͂Ɩh��͏��A�b�v
				//�v���C���[3��MANA�����炷
				magic.mana -= 3;
				//MANA�̐��l��ς���
				magicmnal->setString(std::to_string(magic.mana));
				//�����S���̃X�e�[�^�X���グ��
				//���m�̍U���Ɩh����グ��
				attackeratkbuffup = attacker.atk * buffuplittle;
				attackerdefbuffup = attacker.def * buffuplittle;
				attacker.atk += attackeratkbuffup;
				attacker.def += attackerdefbuffup;
				//�R�m��ry
				shieldatkbuffup = shield.atk * buffuplittle;
				shielddefbuffup = shield.def * buffuplittle;
				shield.atk += shieldatkbuffup;
				shield.def += shielddefbuffup;
				//���p�t��ry
				magicatkbuffup = magic.atk * buffuplittle;
				magicdefbuffup = magic.def * buffuplittle;
				magic.atk += magicatkbuffup;
				magic.def += magicdefbuffup;
				//���E�҂�ry
				healeratkbuffup = healer.atk * buffuplittle;
				healerdefbuffup = healer.def * buffuplittle;
				healer.atk += healeratkbuffup;
				healer.def += healerdefbuffup;

				//�X�L�����ʃ^�[���ɂ�鏈��
				if (mskill5.buffturn1 == 0) {
					mskill5.buffturn1 = 4;							//��������^�[��
					mskill5.attackeratkbuff1 = attackeratkbuffup;	//�オ�������̃X�e�[�^�X���L��(���m)
					mskill5.attackerdefbuff1 = attackerdefbuffup;	//�オ�������̃X�e�[�^�X���L��(���m)
					mskill5.shieldatkbuff1 = shieldatkbuffup;		//�オ�������̃X�e�[�^�X���L��(�R�m)
					mskill5.shielddefbuff1 = shielddefbuffup;		//�オ�������̃X�e�[�^�X���L��(�R�m)
					mskill5.magicatkbuff1 = magicatkbuffup;			//�オ�������̃X�e�[�^�X���L��(���p�t)
					mskill5.magicdefbuff1 = magicdefbuffup;			//�オ�������̃X�e�[�^�X���L��(���p�t)
					mskill5.healeratkbuff1 = healeratkbuffup;		//�オ�������̃X�e�[�^�X���L��(���E��)
					mskill5.healerdefbuff1 = healerdefbuffup;		//�オ�������̃X�e�[�^�X���L��(���E��)
				}
				else if (mskill5.buffturn2 == 0) {
					mskill5.buffturn2 = 4;
					mskill5.attackeratkbuff2 = attackeratkbuffup;	//�オ�������̃X�e�[�^�X���L��(���m)
					mskill5.attackerdefbuff2 = attackerdefbuffup;	//�オ�������̃X�e�[�^�X���L��(���m)
					mskill5.shieldatkbuff2 = shieldatkbuffup;		//�オ�������̃X�e�[�^�X���L��(�R�m)
					mskill5.shielddefbuff2 = shielddefbuffup;		//�オ�������̃X�e�[�^�X���L��(�R�m)
					mskill5.magicatkbuff2 = magicatkbuffup;			//�オ�������̃X�e�[�^�X���L��(���p�t)
					mskill5.magicdefbuff2 = magicdefbuffup;			//�オ�������̃X�e�[�^�X���L��(���p�t)
					mskill5.healeratkbuff2 = healeratkbuffup;		//�オ�������̃X�e�[�^�X���L��(���E��)
					mskill5.healerdefbuff2 = healerdefbuffup;		//�オ�������̃X�e�[�^�X���L��(���E��)
				}
				else if (mskill5.buffturn3 == 0) {
					mskill5.buffturn3 = 4;
					mskill5.attackeratkbuff3 = attackeratkbuffup;	//�オ�������̃X�e�[�^�X���L��(���m)
					mskill5.attackerdefbuff3 = attackerdefbuffup;	//�オ�������̃X�e�[�^�X���L��(���m)
					mskill5.shieldatkbuff3 = shieldatkbuffup;		//�オ�������̃X�e�[�^�X���L��(�R�m)
					mskill5.shielddefbuff3 = shielddefbuffup;		//�オ�������̃X�e�[�^�X���L��(�R�m)
					mskill5.magicatkbuff3 = magicatkbuffup;			//�オ�������̃X�e�[�^�X���L��(���p�t)
					mskill5.magicdefbuff3 = magicdefbuffup;			//�オ�������̃X�e�[�^�X���L��(���p�t)
					mskill5.healeratkbuff3 = healeratkbuffup;		//�オ�������̃X�e�[�^�X���L��(���E��)
					mskill5.healerdefbuff3 = healerdefbuffup;		//�オ�������̃X�e�[�^�X���L��(���E��)
				}
				else if (mskill5.buffturn4 == 0) {
					mskill5.buffturn4 = 4;
					mskill5.attackeratkbuff4 = attackeratkbuffup;	//�オ�������̃X�e�[�^�X���L��(���m)
					mskill5.attackerdefbuff4 = attackerdefbuffup;	//�オ�������̃X�e�[�^�X���L��(���m)
					mskill5.shieldatkbuff4 = shieldatkbuffup;		//�オ�������̃X�e�[�^�X���L��(�R�m)
					mskill5.shielddefbuff4 = shielddefbuffup;		//�オ�������̃X�e�[�^�X���L��(�R�m)
					mskill5.magicatkbuff4 = magicatkbuffup;			//�オ�������̃X�e�[�^�X���L��(���p�t)
					mskill5.magicdefbuff4 = magicdefbuffup;			//�オ�������̃X�e�[�^�X���L��(���p�t)
					mskill5.healeratkbuff4 = healeratkbuffup;		//�オ�������̃X�e�[�^�X���L��(���E��)
					mskill5.healerdefbuff4 = healerdefbuffup;		//�オ�������̃X�e�[�^�X���L��(���E��)
				}
				
				//�X�e�[�^�X�A�b�v�\�L
				auto pl3buffup = CCLabelTTF::create("�����̍U���͂Ɩh��͂������オ����", "HGRSGU.TTC", fontsizeM);
				pl3buffup->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl3buffup, backdepth, buffupS);
			}
			//�X�L���I���
			if (skillflame == flame150) {
				this->removeChildByTag(mskill1E);			//���邮�邵�Ă���
				this->removeChildByTag(magicdamageS);		//�_���[�W�\�L������
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//�_�̌䌕
		if (mskill == MSKILL6) {
			if (gameflame == flame50) {
				//2�^�[���̊ԁA�����S�̂̍U���͂Ɩh��͑�A�b�v
				//�v���C���[3��MANA�����炷
				magic.mana -= 5;
				//MANA�̐��l��ς���
				magicmnal->setString(std::to_string(magic.mana));
				//�����S���̃X�e�[�^�X���グ��
				//���m�̍U���Ɩh����グ��
				attackeratkbuffup = attacker.atkmax;
				attackerdefbuffup = attacker.defmax;
				attacker.atk += attackeratkbuffup;
				attacker.def += attackerdefbuffup;
				//�R�m��ry
				shieldatkbuffup = shield.atkmax;
				shielddefbuffup = shield.defmax;
				shield.atk += shieldatkbuffup;
				shield.def += shielddefbuffup;
				//���p�t��ry
				magicatkbuffup = magic.atkmax;
				magicdefbuffup = magic.defmax;
				magic.atk += magicatkbuffup;
				magic.def += magicdefbuffup;
				//���E�҂�ry
				healeratkbuffup = healer.atkmax;
				healerdefbuffup = healer.defmax;
				healer.atk += healeratkbuffup;
				healer.def += healerdefbuffup;

				//�X�L�����ʃ^�[���ɂ�鏈��
				if (mskill6.buffturn1 == 0) {
					mskill6.buffturn1 = 3;							//��������^�[��
					mskill6.attackeratkbuff1 = attackeratkbuffup;	//�オ�������̃X�e�[�^�X���L��(���m)
					mskill6.attackerdefbuff1 = attackerdefbuffup;	//�オ�������̃X�e�[�^�X���L��(���m)
					mskill6.shieldatkbuff1 = shieldatkbuffup;		//�オ�������̃X�e�[�^�X���L��(�R�m)
					mskill6.shielddefbuff1 = shielddefbuffup;		//�オ�������̃X�e�[�^�X���L��(�R�m)
					mskill6.magicatkbuff1 = magicatkbuffup;			//�オ�������̃X�e�[�^�X���L��(���p�t)
					mskill6.magicdefbuff1 = magicdefbuffup;			//�オ�������̃X�e�[�^�X���L��(���p�t)
					mskill6.healeratkbuff1 = healeratkbuffup;		//�オ�������̃X�e�[�^�X���L��(���E��)
					mskill6.healerdefbuff1 = healerdefbuffup;		//�オ�������̃X�e�[�^�X���L��(���E��)
				}
				else if (mskill6.buffturn2 == 0) {
					mskill6.buffturn2 = 3;
					mskill6.attackeratkbuff2 = attackeratkbuffup;	//�オ�������̃X�e�[�^�X���L��(���m)
					mskill6.attackerdefbuff2 = attackerdefbuffup;	//�オ�������̃X�e�[�^�X���L��(���m)
					mskill6.shieldatkbuff2 = shieldatkbuffup;		//�オ�������̃X�e�[�^�X���L��(�R�m)
					mskill6.shielddefbuff2 = shielddefbuffup;		//�オ�������̃X�e�[�^�X���L��(�R�m)
					mskill6.magicatkbuff2 = magicatkbuffup;			//�オ�������̃X�e�[�^�X���L��(���p�t)
					mskill6.magicdefbuff2 = magicdefbuffup;			//�オ�������̃X�e�[�^�X���L��(���p�t)
					mskill6.healeratkbuff2 = healeratkbuffup;		//�オ�������̃X�e�[�^�X���L��(���E��)
					mskill6.healerdefbuff2 = healerdefbuffup;		//�オ�������̃X�e�[�^�X���L��(���E��)
				}
				else if (mskill6.buffturn3 == 0) {
					mskill6.buffturn3 = 3;
					mskill6.attackeratkbuff3 = attackeratkbuffup;	//�オ�������̃X�e�[�^�X���L��(���m)
					mskill6.attackerdefbuff3 = attackerdefbuffup;	//�オ�������̃X�e�[�^�X���L��(���m)
					mskill6.shieldatkbuff3 = shieldatkbuffup;		//�オ�������̃X�e�[�^�X���L��(�R�m)
					mskill6.shielddefbuff3 = shielddefbuffup;		//�オ�������̃X�e�[�^�X���L��(�R�m)
					mskill6.magicatkbuff3 = magicatkbuffup;			//�オ�������̃X�e�[�^�X���L��(���p�t)
					mskill6.magicdefbuff3 = magicdefbuffup;			//�オ�������̃X�e�[�^�X���L��(���p�t)
					mskill6.healeratkbuff3 = healeratkbuffup;		//�オ�������̃X�e�[�^�X���L��(���E��)
					mskill6.healerdefbuff3 = healerdefbuffup;		//�オ�������̃X�e�[�^�X���L��(���E��)
				}
				else if (mskill6.buffturn4 == 0) {
					mskill6.buffturn4 = 3;
					mskill6.attackeratkbuff4 = attackeratkbuffup;	//�オ�������̃X�e�[�^�X���L��(���m)
					mskill6.attackerdefbuff4 = attackerdefbuffup;	//�オ�������̃X�e�[�^�X���L��(���m)
					mskill6.shieldatkbuff4 = shieldatkbuffup;		//�オ�������̃X�e�[�^�X���L��(�R�m)
					mskill6.shielddefbuff4 = shielddefbuffup;		//�オ�������̃X�e�[�^�X���L��(�R�m)
					mskill6.magicatkbuff4 = magicatkbuffup;			//�オ�������̃X�e�[�^�X���L��(���p�t)
					mskill6.magicdefbuff4 = magicdefbuffup;			//�オ�������̃X�e�[�^�X���L��(���p�t)
					mskill6.healeratkbuff4 = healeratkbuffup;		//�オ�������̃X�e�[�^�X���L��(���E��)
					mskill6.healerdefbuff4 = healerdefbuffup;		//�オ�������̃X�e�[�^�X���L��(���E��)
				}

				//�X�e�[�^�X�A�b�v�\�L
				auto pl3buffup = CCLabelTTF::create("�����̍U���͂Ɩh��͂��啝�ɏオ����", "HGRSGU.TTC", fontsizeL);
				pl3buffup->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl3buffup, backdepth, buffupS);
			}
			//�X�L���I���
			if (skillflame == flame150) {
				this->removeChildByTag(mskill1E);			//���邮�邵�Ă���
				this->removeChildByTag(magicdamageS);			//�_���[�W�\�L������
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//���͋z��
		if (mskill == MSKILL7) {
			//�����P�̂�MP��10%�z�������g��MP���񕜂���
		}
		//�S�ċz
		if (mskill == MSKILL8) {
			if (gameflame == flame50) {
				//3�^�[���̊ԁA���g��MP������
				//�v���C���[3��MANA�����炷
				magic.mana -= 4;
				//MANA�̐��l��ς���
				magicmnal->setString(std::to_string(magic.mana));
				//���p�t��mana���񕜂�����
				recovery = magic.manamax / skilluplittle;
		
				//�_���[�W�\�L
				String *p3skl = String::createWithFormat("���p�t��%i�_���[�W�^����", recovery);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			//�X�L���I���
			if (skillflame == flame250) {
				this->removeChildByTag(mskill1E);			//���邮�邵�Ă���
				this->removeChildByTag(magicdamageS);			//�_���[�W�\�L������
				skillendflag = true;
			}
		}
	}
//���E��
	if (job == HEALER) {
		//���͋���
		if (hskill == HSKILL1) {
			if (gameflame == flame50) {
				//�����P�̂Ɏ��g��MP�����^����
				//���E�҂�MANA�����炷
				recovery = manarecovery;
				healer.mana -= recovery;
				//MANA�̐��l��ς���
				healermnal->setString(std::to_string(healer.mana));
				//�I�񂾃L�������񕜂�����
				if (hskillchoice == ATTACKER) {
					attacker.mana += recovery;								//�}�i��
					attackermnal->setString(std::to_string(attacker.mana));	//�}�i�̐�����ς���
				}
				else if (hskillchoice == HEALER) {
					healer.mana += recovery;
					healermnal->setString(std::to_string(healer.mana));
				}
				else if (hskillchoice == MAGIC) {
					magic.mana += recovery;
					magicmnal->setString(std::to_string(magic.mana));
				}
				//�_���[�W�\�L
				String *healerskl = String::createWithFormat("���E�҂�%i�񕜂�����", recovery);
				string _healerskl = healerskl->getCString();
				auto p3slabel = Label::createWithSystemFont(_healerskl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, healerdamageS);
			}
			//�X�L���I���
			if (skillflame == flame80) {
				this->removeChildByTag(hskill1E);				//�G�t�F�N�g������
				this->removeChildByTag(healerdamageS);				//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//���҂̌o�T
		if (hskill == HSKILL2) {
			if (gameflame == flame50) {
				//�G�P�̂̍U���͒��_�E��
				//�v���C���[�P��MANA�����炷
				healer.mana -= 5;
				//MANA�̐��l��ς���
				healermnal->setString(std::to_string(healer.mana));
				//�{�X�̍U���͂𒆃_�E��
				buffdown = valkyrie.atk * buffdownlarge;
				valkyrie.atk = buffdown;

				//�X�L�����ʃ^�[���ɂ�鏈��
				if (hskill2.buffturn1 == 0) {
					hskill2.buffturn1 = 4;
					hskill2.buffdownefect1 = buffdown;
				}
				else if (hskill2.buffturn2 == 0) {
					hskill2.buffturn2 = 4;
					hskill2.buffdownefect2 = buffdown;
				}
				else if (hskill2.buffturn3 == 0) {
					hskill2.buffturn3 = 4;
					hskill2.buffdownefect3 = buffdown;
				}
				else if (hskill2.buffturn4 == 0) {
					hskill2.buffturn4 = 4;
					hskill2.buffdownefect4 = buffdown;
				}

				//�X�e�[�^�X�A�b�v�\�L
				auto pl2buffdown = CCLabelTTF::create("�G�̍U���͂�������", "HGRSGU.TTC", fontsizeL);
				pl2buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl2buffdown, backdepth, buffupS);
				
			}
			//�X�L���I���
			if (skillflame == flame80) {
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//���҂̌o�T
		if (hskill == HSKILL3) {
			if (gameflame == flame50) {
				//�G�P�̖̂h��͒��_�E��
				//�v���C���[�P��MANA�����炷
				healer.mana -= 5;
				//MANA�̐��l��ς���
				healermnal->setString(std::to_string(healer.mana));
				//�{�X�̍U���͂𒆃_�E��
				buffdown = valkyrie.def * buffdownlarge;
				valkyrie.def = buffdown;

				//�X�L�����ʃ^�[���ɂ�鏈��
				if (hskill3.buffturn1 == 0) {
					hskill3.buffturn1 = 4;
					hskill3.buffdownefect1 = buffdown;
				}
				else if (hskill3.buffturn2 == 0) {
					hskill3.buffturn2 = 4;
					hskill3.buffdownefect2 = buffdown;
				}
				else if (hskill3.buffturn3 == 0) {
					hskill3.buffturn3 = 4;
					hskill3.buffdownefect3 = buffdown;
				}
				else if (hskill3.buffturn4 == 0) {
					hskill3.buffturn4 = 4;
					hskill3.buffdownefect4 = buffdown;
				}

				//�X�e�[�^�X�A�b�v�\�L
				auto pl2buffdown = CCLabelTTF::create("�G�̖h��͂�������", "HGRSGU.TTC", fontsizeL);
				pl2buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl2buffdown, backdepth, buffupS);

			}
			//�X�L���I���
			if (skillflame == flame80) {
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//�Z�C���g���[�O
		if (hskill == HSKILL4) {
			if (gameflame == flame50) {
				//�����P�̂�HP������
				//�G�t�F�N�g�̕\��
				//�G�t�F�N�g�̗�����w��
				CCParticleSystemQuad* plparticle2 = CCParticleSystemQuad::create("Effect/plskill1.plist");

				plparticle2->setAutoRemoveOnFinish(true);

				//�G�t�F�N�g����
				//�p�[�e�B�N���J�n
				plparticle2->resetSystem();								

				//���m��I�ԏꍇ
				if (hskillchoice == ATTACKER) {
					if (pl1frame.choicejob == ATTACKER) {
						plparticle2->setPosition(ccp(rightSize.width / 4.1f,
							rightSize.height / 5));							//�p�[�e�B�N����\������ꏊ�̐ݒ�
					}
					else if (pl2frame.choicejob == ATTACKER) {
						plparticle2->setPosition(ccp(rightSize.width / 2,
							rightSize.height / 5));							//�p�[�e�B�N����\������ꏊ�̐ݒ�
					}
					else if (pl3frame.choicejob == ATTACKER) {
						plparticle2->setPosition(ccp(rightSize.width / 1.32f,
							rightSize.height / 5));							//�p�[�e�B�N����\������ꏊ�̐ݒ�
					}
				}
				//�R�m��I�ԏꍇ
				if (hskillchoice == SHIELD) {
					if (pl1frame.choicejob == SHIELD) {
						plparticle2->setPosition(ccp(rightSize.width / 4.1f,
							rightSize.height / 5));							//�p�[�e�B�N����\������ꏊ�̐ݒ�
					}
					else if (pl2frame.choicejob == SHIELD) {
						plparticle2->setPosition(ccp(rightSize.width / 2,
							rightSize.height / 5));							//�p�[�e�B�N����\������ꏊ�̐ݒ�
					}
					else if (pl3frame.choicejob == SHIELD) {
						plparticle2->setPosition(ccp(rightSize.width / 1.32f,
							rightSize.height / 5));							//�p�[�e�B�N����\������ꏊ�̐ݒ�
					}
				}
				//���p�t��I�ԏꍇ
				if (hskillchoice == MAGIC) {
					if (pl1frame.choicejob == MAGIC) {
						plparticle2->setPosition(ccp(rightSize.width / 4.1f,
							rightSize.height / 5));							//�p�[�e�B�N����\������ꏊ�̐ݒ�
					}
					else if (pl2frame.choicejob == MAGIC) {
						plparticle2->setPosition(ccp(rightSize.width / 2,
							rightSize.height / 5));							//�p�[�e�B�N����\������ꏊ�̐ݒ�
					}
					else if (pl3frame.choicejob == MAGIC) {
						plparticle2->setPosition(ccp(rightSize.width / 1.32f,
							rightSize.height / 5));							//�p�[�e�B�N����\������ꏊ�̐ݒ�
					}
				}
				//���E��
				if (hskillchoice == HEALER) {
					if (pl1frame.choicejob == HEALER) {
						plparticle2->setPosition(ccp(rightSize.width / 4.1f,
							rightSize.height / 5));							//�p�[�e�B�N����\������ꏊ�̐ݒ�
					}
					else if (pl2frame.choicejob == HEALER) {
						plparticle2->setPosition(ccp(rightSize.width / 2,
							rightSize.height / 5));							//�p�[�e�B�N����\������ꏊ�̐ݒ�
					}
					else if (pl3frame.choicejob == HEALER) {
						plparticle2->setPosition(ccp(rightSize.width / 1.32f,
							rightSize.height / 5));							//�p�[�e�B�N����\������ꏊ�̐ݒ�
					}
				}
				//�p�[�e�B�N����z�u
				this->addChild(plparticle2, backdepth, hskill1E);		


				//���E�҂�MANA�����炷
				healer.mana -= 2;
				//MANA�̐��l��ς���
				healermnal->setString(std::to_string(healer.mana));
				//�I�񂾃L�������񕜂�����
				//���m
				if (hskillchoice == ATTACKER) {
					attacker.hp += recovery_rnd;						//��
					attackerhpal->setString(std::to_string(attacker.hp));		//HP�̐�����ς���
				}
				//�R�m
				else if (hskillchoice == SHIELD) {
					shield.hp += recovery_rnd;
					shieldhpal->setString(std::to_string(shield.hp));
				}
				//���p�t
				else if (hskillchoice == MAGIC) {
					magic.hp += recovery_rnd;
					magichpal->setString(std::to_string(magic.hp));
				}
				//���E��
				else if (hskillchoice == HEALER) {
					healer.hp += recovery_rnd;
					healerhpal->setString(std::to_string(healer.hp));
				}
				//�_���[�W�\�L
				String *healerskl = String::createWithFormat("���E�҂�%i�񕜂�����", recovery_rnd);
				string _healerskl = healerskl->getCString();
				auto p3slabel = Label::createWithSystemFont(_healerskl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, healerdamageS);
			}
			//�X�L���I���
			if (skillflame == flame100) {
				this->removeChildByTag(hskill1E);				//�G�t�F�N�g������
				this->removeChildByTag(healerdamageS);			//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//�����m�؁[�p�[
		if (hskill == HSKILL5) {
			if (gameflame == flame50) {
				//�����P�̂�HP�𒆉�
				//���E�҂�MANA�����炷
				healer.mana -= 3;
				//MANA�̐��l��ς���
				healermnal->setString(std::to_string(healer.mana));
				//�I�񂾃L�������񕜂�����
				//���m
				if (hskillchoice == ATTACKER) {
					attacker.hp += recovery_rnd;							//��
					attackerhpal->setString(std::to_string(attacker.hp));	//HP�̐�����ς���
				}
				//�R�m
				else if (hskillchoice == SHIELD) {
					shield.hp += recovery_rnd;
					shieldhpal->setString(std::to_string(shield.hp));
				}
				//���E��
				else if (hskillchoice == HEALER) {
					healer.hp += recovery_rnd;
					healerhpal->setString(std::to_string(healer.hp));
				}
				//���p�t
				else if (hskillchoice == MAGIC) {
					magic.hp += recovery_rnd;
					magichpal->setString(std::to_string(magic.hp));
				}
				//�_���[�W�\�L
				String *healerskl = String::createWithFormat("���E�҂�%i�񕜂�����", recovery_rnd);
				string _healerskl = healerskl->getCString();
				auto p3slabel = Label::createWithSystemFont(_healerskl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, healerdamageS);
			}
			//�X�L���I���
			if (skillflame == flame80) {
				this->removeChildByTag(hskill1E);				//�G�t�F�N�g������
				this->removeChildByTag(healerdamageS);			//�_���[�W�\�L������
				skillendflag = true;
			}
		}
		//���҂̋F��
		if (hskill == HSKILL6) {
			if (gameflame == flame50) {
				//�����S�̂�HP������
				//�v���C���[�P��MANA�����炷
				healer.mana -= 4;
				//MANA�̐��l��ς���
				healermnal->setString(std::to_string(healer.mana));
				//�v���C���[�S����HP������
				attacker.hp += recovery_rnd;
				healer.hp += recovery_rnd;
				magic.hp += recovery_rnd;
				//�v���C���[��HP�̐��l��ς���
				attackerhpal->setString(std::to_string(attacker.hp));
				healerhpal->setString(std::to_string(healer.hp));
				magichpal->setString(std::to_string(magic.hp));

				//�X�e�[�^�X�A�b�v�\�L
				auto pl2buffdown = CCLabelTTF::create("������HP�������񕜂���", "HGRSGU.TTC", fontsizeL);
				pl2buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl2buffdown, backdepth, buffupS);

			}
			//�X�L���I���
			if (skillflame == flame80) {
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//�Z�C���g�I�[�_�[
		if (hskill == HSKILL7) {
			if (gameflame == flame50) {
				//�����S�̂�HP����
				//�v���C���[�P��MANA�����炷
				healer.mana -= 7;
				//MANA�̐��l��ς���
				healermnal->setString(std::to_string(healer.mana));
				//�v���C���[�S����HP����
				attacker.hp += recoveryall;
				shield.hp += recoveryall;
				healer.hp += recoveryall;
				magic.hp += recoveryall;
				//�v���C���[��HP�̐��l��ς���
				attackerhpal->setString(std::to_string(attacker.hp));
				shieldhpal->setString(std::to_string(shield.hp));
				healerhpal->setString(std::to_string(healer.hp));
				magichpal->setString(std::to_string(magic.hp));

				//�X�e�[�^�X�A�b�v�\�L
				auto pl2buffdown = CCLabelTTF::create("������HP�������񕜂���", "HGRSGU.TTC", fontsizeL);
				pl2buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl2buffdown, backdepth, buffupS);

			}
			//�X�L���I���
			if (skillflame == flame80) {
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//�_�̌[��
		if (hskill == HSKILL8) {
			if (gameflame == flame50) {
				//�����P�̂�퓬�s�\��Ԃ��畜��������

				//���E�҂�MANA�����炷
				healer.mana -= 7;
				//MANA�̐��l��ς���
				healermnal->setString(std::to_string(healer.mana));
				//�I�񂾃L�����𕜊�������
				//���m
				if (hskillchoice == ATTACKER) {
					attacker.hp += attacker.hpmax;							//��
					attackerhpal->setString(std::to_string(attacker.hp));	//HP�̐�����ς���
					if (pl1frame.choicejob == ATTACKER) {
						pl1 = PL1NON;
					}
					else if (pl2frame.choicejob == ATTACKER) {
						pl2 = PL2NON;
					}
					else if (pl3frame.choicejob == ATTACKER) {
						pl3 = PL3NON;
					}
				}
				//�R�m
				else if (hskillchoice == SHIELD) {
					shield.hp += shield.hpmax;
					shieldhpal->setString(std::to_string(shield.hp));
					if (pl1frame.choicejob == SHIELD) {
						pl1 = PL1NON;
					}
					else if (pl2frame.choicejob == SHIELD) {
						pl2 = PL2NON;
					}
					else if (pl3frame.choicejob == SHIELD) {
						pl3 = PL3NON;
					}
				}
				//���E��
				else if (hskillchoice == HEALER) {
					healer.hp += healer.hpmax;
					healerhpal->setString(std::to_string(healer.hp));
					if (pl1frame.choicejob == MAGIC) {
						pl1 = PL1NON;
					}
					else if (pl2frame.choicejob == MAGIC) {
						pl2 = PL2NON;
					}
					else if (pl3frame.choicejob == MAGIC) {
						pl3 = PL3NON;
					}
				}
				//���p�t
				else if (hskillchoice == MAGIC) {
					magic.hp += magic.hpmax;
					magichpal->setString(std::to_string(magic.hp));
					if (pl1frame.choicejob == HEALER) {
						pl1 = PL1NON;
					}
					else if (pl2frame.choicejob == HEALER) {
						pl2 = PL2NON;
					}
					else if (pl3frame.choicejob == HEALER) {
						pl3 = PL3NON;
					}
				}
				//���m��I�񂾏ꍇ
				if (sskillchoice == ATTACKER) {
					//���ʕ\�L
					auto revival = CCLabelTTF::create("���m�̑���ɍU�����󂯂�", "HGRSGU.TTC", fontsizeL);
					revival->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
					this->addChild(revival, backdepth, insteadS);
				}
				//�R�m��I�񂾏ꍇ
				else if (sskillchoice == SHIELD) {
					auto revival = CCLabelTTF::create("�R�m�̑���ɍU�����󂯂�", "HGRSGU.TTC", fontsizeL);
					revival->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
					this->addChild(revival, backdepth, insteadS);
				}
				//���p�t��I�񂾏ꍇ
				else if (sskillchoice == MAGIC) {
					auto revival = CCLabelTTF::create("���p�t�̑���ɍU�����󂯂�", "HGRSGU.TTC", fontsizeL);
					revival->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
					this->addChild(revival, backdepth, insteadS);
				}
			}
			//�X�L���I���
			if (skillflame == flame80) {
				this->removeChildByTag(hskill1E);			//�G�t�F�N�g������
				this->removeChildByTag(insteadS);			//�_���[�W�\�L������
				skillendflag = true;
			}
		}
	}
}

void BossScene::BSturn()
{
	//�_���v���C���[�����߂�
	if (bsact == PICK) {
		//���E�҂����Ȃ��Ƃ�
		if (pl1frame.choicejob == ATTACKER || pl2frame.choicejob == ATTACKER || pl3frame.choicejob == ATTACKER) {
			if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD || pl3frame.choicejob == SHIELD) {
				if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC || pl3frame.choicejob == MAGIC) {
					if (coverflag1 == false && coverflag2 == false && allinsteadflag == false) {
						if (pick_rnd < fortypercent) {
							job = ATTACKER;
						}
						if (pick_rnd >= fortypercent && pick_rnd < seventypercent) {
							job = SHIELD;
						}
						if (pick_rnd >= seventypercent && pick_rnd < rndmax) {
							job = MAGIC;
						}
					}
					//�^�Q�W���������Ă���̂Ȃ�
					else if (coverflag1 == true || coverflag2 == true || allinsteadflag == true) {
						job = SHIELD;
					}
				}
			}
		}
		//���m�����Ȃ��Ƃ�
		if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER || pl3frame.choicejob == HEALER) {
			if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD || pl3frame.choicejob == SHIELD) {
				if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC || pl3frame.choicejob == MAGIC) {
					if (coverflag1 == false && coverflag2 == false && allinsteadflag == false) {
						if (pick_rnd < fortypercent) {
							job = SHIELD;
						}
						if (pick_rnd >= fortypercent && pick_rnd < seventypercent) {
							job = MAGIC;
						}
						if (pick_rnd >= seventypercent && pick_rnd < rndmax) {
							job = HEALER;
						}
					}
					//�^�Q�W���������Ă���̂Ȃ�
					else if (coverflag1 == true || coverflag2 == true || allinsteadflag == true) {
						job = SHIELD;
					}
				}
			}
		}
		//�R�m�����Ȃ��Ƃ�
		if (pl1frame.choicejob == ATTACKER || pl2frame.choicejob == ATTACKER || pl3frame.choicejob == ATTACKER) {
			if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER || pl3frame.choicejob == HEALER) {
				if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC || pl3frame.choicejob == MAGIC) {
					if (coverflag1 == false && coverflag2 == false && allinsteadflag == false) {
						if (pick_rnd < fortypercent) {
							job = ATTACKER;
						}
						if (pick_rnd >= fortypercent && pick_rnd < seventypercent) {
							job = MAGIC;
						}
						if (pick_rnd >= seventypercent && pick_rnd < rndmax) {
							job = HEALER;
						}
					}
					//�^�Q�W���������Ă���̂Ȃ�
					else if (coverflag1 == true || coverflag2 == true || allinsteadflag == true) {
						job = SHIELD;
					}
				}
			}
		}
		//���p�t�����Ȃ��Ƃ�
		if (pl1frame.choicejob == ATTACKER || pl2frame.choicejob == ATTACKER || pl3frame.choicejob == ATTACKER) {
			if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD || pl3frame.choicejob == SHIELD) {
				if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER || pl3frame.choicejob == HEALER) {
					if (coverflag1 == false && coverflag2 == false && allinsteadflag == false) {
						if (pick_rnd < fortypercent) {
							job = ATTACKER;
						}
						if (pick_rnd >= fortypercent && pick_rnd < seventypercent) {
							job = SHIELD;
						}
						if (pick_rnd >= seventypercent && pick_rnd < rndmax) {
							job = HEALER;
						}
					}
					//�^�Q�W���������Ă���̂Ȃ�
					else if (coverflag1 == true || coverflag2 == true || allinsteadflag == true) {
						job = SHIELD;
					}
				}
			}
		}
		bsact = DECIDE;
	}

	//�ʏ�U�����X�L���������߂�
	if (bsact == DECIDE) {
		if (decide_rnd < sixtypercent) {
			bsact = BOSSATTACK;
		}
		if (decide_rnd >= sixtypercent && decide_rnd <= rndmax) {
			bsact = BOSSSKILL;
		}
	}

	//�ǂ̃X�L���ōU�����邩�����߂�
	if (bsact == BOSSSKILL) {
		if (skill_rnd < fiftypercent) {
			bskill = BSKILL1;
		}
		if (skill_rnd >= fiftypercent && skill_rnd < eightypercent) {
			bskill = BSKILL2;
		}
		if (skill_rnd >= eightypercent && skill_rnd < ninetypercent) {
			bskill = BSKILL3;
		}
		if (skill_rnd >= ninetypercent && skill_rnd <= rndmax) {
			bskill = BSKILL4;
		}
	}

	//�I�񂾃L�������o�͂ɕ\��
	log("job %i", job);
	//�J�E���g���o�͂ɕ\��
	log("skill_rnd %i", skill_rnd);
	//�v���C���[1��HP��\��
	CCString *hpstr1 = CCString::createWithFormat("����PL1HP��%d�ł�", attacker.hp);
	log("%s", hpstr1->getCString());
	//�v���C���[2��HP��\��
	CCString *hpstr2 = CCString::createWithFormat("����PL2HP��%d�ł�", healer.hp);
	log("%s", hpstr2->getCString());
	//�v���C���[3��HP��\��
	CCString *hpstr3 = CCString::createWithFormat("����PL3HP��%d�ł�", magic.hp);
	log("%s", hpstr3->getCString());
	//�{�X��HP��\��
	CCString *hpstrBS = CCString::createWithFormat("���݃��@���L���[HP��%d�ł�", valkyrie.hp);
	log("%s", hpstrBS->getCString());

	//�U�����[�h�̎�
	if (bsact == BOSSATTACK) {
		if (gameflame == flame80) {
			//�t���[����80(��)�ɂȂ����當����\������
			auto atk = CCLabelTTF::create("�u�₠���I(�ʏ�U��)�v", "HGRSGU.TTC", fontsizeL);
			atk->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(atk, backdepth, normalattackS);
			//�{�X�̉摜��h�炷����
			auto move = CCSequence::create(
				CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f + moverange)),
				CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f)),
				NULL
			);
			//�h�炷
			auto repeat = Repeat::create(move, 1);
			Boss->runAction(repeat);

			//�_���[�W���󂯂����ɗh�炷����
			Damage();				

			//�R�m�̒P�̐g����X�L�����������Ă��Ȃ��Ƃ�
			if (insteadflag == false) {
				//���m
				if (job == ATTACKER) {
					hpcut = (valkyrie.atk - attacker.def);					//���炷HP���v�Z
					//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
					if (hpcut <= 1) {
						hpcut = 1;
					}
					attacker.hp -= hpcut;										//HP�����炷
					PLattacker->setColor(ccc3(colormax, colordown, colordown));	//�_���[�W���󂯂�v���C���[�͐Ԃ�����
					attackerhpal->setString(std::to_string(attacker.hp));		//�_���[�W���󂯂�v���C���[��HP�����炷
					attackerdmf->setString(std::to_string(hpcut));	//�_���[�W��ω�������
					this->addChild(attackerdmf, onece);				//�_���[�W�������o��
					attackerdmf->runAction(attackerfadeout);		//�_���[�W�������t�F�[�h�A�E�g������
					attackerdmf->runAction(attackerfdoutmov);		//�_���[�W��������ɓ�����
					PLattacker->runAction(attacker_repeat_smallquake[0]);
					attackerHP->runAction(attacker_repeat_smallquake[1]);
					attackerMN->runAction(attacker_repeat_smallquake[2]);
					attackerhpal->runAction(attacker_repeat_smallquake[3]);
					attackerhpmaxal->runAction(attacker_repeat_smallquake[4]);
					attackermnal->runAction(attacker_repeat_smallquake[5]);
					attackermnmaxal->runAction(attacker_repeat_smallquake[6]);
				}
				//�R�m
				else if (job == SHIELD) {
					hpcut = (valkyrie.atk - shield.def);
					//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
					if (hpcut <= 1) {
						hpcut = 1;
					}
					shield.hp -= hpcut;
					PLshield->setColor(ccc3(colormax, colordown, colordown));
					shieldhpal->setString(std::to_string(shield.hp));
					shielddmf->setString(std::to_string(hpcut));	//�_���[�W��ω�������
					this->addChild(shielddmf, onece);				//�_���[�W�������o��
					shielddmf->runAction(shieldfadeout);			//�_���[�W�������t�F�[�h�A�E�g������
					shielddmf->runAction(shieldfdoutmov);			//�_���[�W��������ɓ�����
					PLshield->runAction(shieldrepeat1b);
					shieldHP->runAction(shieldrepeat2b);
					shieldMN->runAction(shieldrepeat3b);
					shieldhpal->runAction(shieldrepeat4b);
					shieldhpmaxal->runAction(shieldrepeat5b);
					shieldmnal->runAction(shieldrepeat6b);
					shieldmnmaxal->runAction(shieldrepeat7b);
				}
				//���p�t
				else if (job == MAGIC) {
					if (insteadflag == false) {
						hpcut = (valkyrie.atk - magic.def);
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						magic.hp -= hpcut;
						PLmagic->setColor(ccc3(colormax, colordown, colordown));
						magichpal->setString(std::to_string(magic.hp));
						magicdmf->setString(std::to_string(hpcut));		//�_���[�W��ω�������
						this->addChild(magicdmf, onece);				//�_���[�W�������o��
						magicdmf->runAction(magicfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
						magicdmf->runAction(magicfdoutmov);				//�_���[�W��������ɓ�����
						PLmagic->runAction(magicrepeat1b);
						magicHP->runAction(magicrepeat2b);
						magicMN->runAction(magicrepeat3b);
						magichpal->runAction(magicrepeat4b);
						magichpmaxal->runAction(magicrepeat5b);
						magicmnal->runAction(magicrepeat6b);
						magicmnmaxal->runAction(magicrepeat7b);
					}
				}
				//���E��
				else if (job == HEALER) {
					if (insteadflag == false) {
						hpcut = (valkyrie.atk - healer.def);
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						healer.hp -= hpcut;
						PLhealer->setColor(ccc3(colormax, colordown, colordown));
						healerhpal->setString(std::to_string(healer.hp));
						healerdmf->setString(std::to_string(hpcut));	//�_���[�W��ω�������
						this->addChild(healerdmf, onece);				//�_���[�W�������o��
						healerdmf->runAction(healerfadeout);			//�_���[�W�������t�F�[�h�A�E�g������
						healerdmf->runAction(healerfdoutmov);			//�_���[�W��������ɓ�����
						PLhealer->runAction(healerrepeat1b);
						healerHP->runAction(healerrepeat2b);
						healerMN->runAction(healerrepeat3b);
						healerhpal->runAction(healerrepeat4b);
						healerhpmaxal->runAction(healerrepeat5b);
						healermnal->runAction(healerrepeat6b);
						healermnmaxal->runAction(healerrepeat7b);
					}
				}
			}

			//�R�m�̒P�̐g����X�L�����������Ă���Ƃ�
			if (insteadflag == true) {
				//���m��I�񂾏ꍇ
				if (sskillchoice == ATTACKER) {
					//���m
					if (job == ATTACKER) {
						hpcut = (valkyrie.atk * skillupmedium) - shield.def;//���炷�_���[�W���v�Z
																			//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;									//HP�����炷
						shielddmf->setString(std::to_string(hpcut));		//�_���[�W��ω�������
						this->addChild(shielddmf, onece);					//�_���[�W�������o��
						shielddmf->runAction(shieldfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
						shielddmf->runAction(shieldfdoutmov);				//�_���[�W��������ɓ�����
						shieldhpal->setString(std::to_string(shield.hp));
						PLshield->runAction(shieldrepeat1a);
						shieldHP->runAction(shieldrepeat2a);
						shieldMN->runAction(shieldrepeat3a);
						shieldhpal->runAction(shieldrepeat4a);
						shieldhpmaxal->runAction(shieldrepeat5a);
						shieldmnal->runAction(shieldrepeat6a);
						shieldmnmaxal->runAction(shieldrepeat7a);
					}
					//�R�m
					if (job == SHIELD) {
						hpcut = (valkyrie.atk - shield.def);
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;
						PLshield->setColor(ccc3(colormax, colordown, colordown));
						shielddmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
						this->addChild(shielddmf, onece);							//�_���[�W�������o��
						shielddmf->runAction(shieldfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
						shielddmf->runAction(shieldfdoutmov);						//�_���[�W��������ɓ�����
						shieldhpal->setString(std::to_string(shield.hp));
						PLshield->runAction(shieldrepeat1a);
						shieldHP->runAction(shieldrepeat2a);
						shieldMN->runAction(shieldrepeat3a);
						shieldhpal->runAction(shieldrepeat4a);
						shieldhpmaxal->runAction(shieldrepeat5a);
						shieldmnal->runAction(shieldrepeat6a);
						shieldmnmaxal->runAction(shieldrepeat7a);
					}
					//���p�t
					if (job == MAGIC) {
						hpcut = (valkyrie.atk - magic.def);
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						magic.hp -= hpcut;
						PLmagic->setColor(ccc3(colormax, colordown, colordown));
						magicdmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
						this->addChild(magicdmf, onece);							//�_���[�W�������o��
						magicdmf->runAction(magicfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
						magicdmf->runAction(magicfdoutmov);						//�_���[�W��������ɓ�����
						magichpal->setString(std::to_string(magic.hp));
						PLmagic->runAction(magicrepeat1a);
						magicHP->runAction(magicrepeat2a);
						magicMN->runAction(magicrepeat3a);
						magichpal->runAction(magicrepeat4a);
						magichpmaxal->runAction(magicrepeat5a);
						magicmnal->runAction(magicrepeat6a);
						magicmnmaxal->runAction(magicrepeat7a);
					}
					//���E��
					if (job == HEALER) {
						hpcut = (valkyrie.atk - healer.def);
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						healer.hp -= hpcut;
						PLhealer->setColor(ccc3(colormax, colordown, colordown));
						healerdmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
						this->addChild(healerdmf, onece);							//�_���[�W�������o��
						healerdmf->runAction(healerfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
						healerdmf->runAction(healerfdoutmov);						//�_���[�W��������ɓ�����
						healerhpal->setString(std::to_string(healer.hp));
						PLhealer->runAction(healerrepeat1a);
						healerHP->runAction(healerrepeat2a);
						healerMN->runAction(healerrepeat3a);
						healerhpal->runAction(healerrepeat4a);
						healerhpmaxal->runAction(healerrepeat5a);
						healermnal->runAction(healerrepeat6a);
						healermnmaxal->runAction(healerrepeat7a);
					}
				}
				//���p�t��I�񂾏ꍇ
				if (sskillchoice == MAGIC) {
					//���m
					if (job == ATTACKER) {
						hpcut = (valkyrie.atk * skillupmedium) - attacker.def;	//���炷�_���[�W���v�Z
																				//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						attacker.hp -= hpcut;									//HP�����炷
						attackerdmf->setString(std::to_string(hpcut));			//�_���[�W��ω�������
						this->addChild(attackerdmf, onece);						//�_���[�W�������o��
						attackerdmf->runAction(attackerfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
						attackerdmf->runAction(attackerfdoutmov);				//�_���[�W��������ɓ�����
						attackerhpal->setString(std::to_string(attacker.hp));
						PLattacker->runAction(attacker_repeat_smallquake[0]);
						attackerHP->runAction(attacker_repeat_smallquake[1]);
						attackerMN->runAction(attacker_repeat_smallquake[2]);
						attackerhpal->runAction(attacker_repeat_smallquake[3]);
						attackerhpmaxal->runAction(attacker_repeat_smallquake[4]);
						attackermnal->runAction(attacker_repeat_smallquake[5]);
						attackermnmaxal->runAction(attacker_repeat_smallquake[6]);
					}
					//�R�m
					if (job == SHIELD) {
						hpcut = (valkyrie.atk - shield.def);
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;
						PLshield->setColor(ccc3(colormax, colordown, colordown));
						shielddmf->setString(std::to_string(hpcut));			//�_���[�W��ω�������
						this->addChild(shielddmf, onece);						//�_���[�W�������o��
						shielddmf->runAction(shieldfadeout);					//�_���[�W�������t�F�[�h�A�E�g������
						shielddmf->runAction(shieldfdoutmov);					//�_���[�W��������ɓ�����
						shieldhpal->setString(std::to_string(shield.hp));
						PLshield->runAction(shieldrepeat1a);
						shieldHP->runAction(shieldrepeat2a);
						shieldMN->runAction(shieldrepeat3a);
						shieldhpal->runAction(shieldrepeat4a);
						shieldhpmaxal->runAction(shieldrepeat5a);
						shieldmnal->runAction(shieldrepeat6a);
						shieldmnmaxal->runAction(shieldrepeat7a);
					}
					//���p�t
					if (job == MAGIC) {
						//���p�t�̑���ɋR�m���_���[�W�����炤
						hpcut = (valkyrie.atk * skillupmedium) - shield.def;//���炷�_���[�W���v�Z
																			//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;									//HP�����炷
						shielddmf->setString(std::to_string(hpcut));		//�_���[�W��ω�������
						this->addChild(shielddmf, onece);					//�_���[�W�������o��
						shielddmf->runAction(shieldfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
						shielddmf->runAction(shieldfdoutmov);				//�_���[�W��������ɓ�����
						magichpal->setString(std::to_string(magic.hp));
						PLshield->runAction(shieldrepeat1a);
						shieldHP->runAction(shieldrepeat2a);
						shieldMN->runAction(shieldrepeat3a);
						shieldhpal->runAction(shieldrepeat4a);
						shieldhpmaxal->runAction(shieldrepeat5a);
						shieldmnal->runAction(shieldrepeat6a);
						shieldmnmaxal->runAction(shieldrepeat7a);

					}
					//���E��
					if (job == HEALER) {
						hpcut = (valkyrie.atk - healer.def);
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						healer.hp -= hpcut;
						PLhealer->setColor(ccc3(colormax, colordown, colordown));
						healerdmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
						this->addChild(healerdmf, onece);							//�_���[�W�������o��
						healerdmf->runAction(healerfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
						healerdmf->runAction(healerfdoutmov);						//�_���[�W��������ɓ�����
						healerhpal->setString(std::to_string(healer.hp));
						PLhealer->runAction(healerrepeat1a);
						healerHP->runAction(healerrepeat2a);
						healerMN->runAction(healerrepeat3a);
						healerhpal->runAction(healerrepeat4a);
						healerhpmaxal->runAction(healerrepeat5a);
						healermnal->runAction(healerrepeat6a);
						healermnmaxal->runAction(healerrepeat7a);
					}
				}
				//���E�҂�I�񂾏ꍇ
				if (sskillchoice == HEALER) {
					//���m
					if (job == ATTACKER) {
						hpcut = (valkyrie.atk * skillupmedium) - attacker.def;//���炷�_���[�W���v�Z
																			  //�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						attacker.hp -= hpcut;									//HP�����炷
						attackerdmf->setString(std::to_string(hpcut));			//�_���[�W��ω�������
						this->addChild(attackerdmf, onece);						//�_���[�W�������o��
						attackerdmf->runAction(attackerfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
						attackerdmf->runAction(attackerfdoutmov);				//�_���[�W��������ɓ�����
						attackerhpal->setString(std::to_string(attacker.hp));
						PLattacker->runAction(attacker_repeat_smallquake[0]);
						attackerHP->runAction(attacker_repeat_smallquake[1]);
						attackerMN->runAction(attacker_repeat_smallquake[2]);
						attackerhpal->runAction(attacker_repeat_smallquake[3]);
						attackerhpmaxal->runAction(attacker_repeat_smallquake[4]);
						attackermnal->runAction(attacker_repeat_smallquake[5]);
						attackermnmaxal->runAction(attacker_repeat_smallquake[6]);
					}
					//�R�m
					if (job == SHIELD) {
						hpcut = (valkyrie.atk - shield.def);
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;
						PLshield->setColor(ccc3(colormax, colordown, colordown));
						shielddmf->setString(std::to_string(hpcut));			//�_���[�W��ω�������
						this->addChild(shielddmf, onece);						//�_���[�W�������o��
						shielddmf->runAction(shieldfadeout);					//�_���[�W�������t�F�[�h�A�E�g������
						shielddmf->runAction(shieldfdoutmov);					//�_���[�W��������ɓ�����
						shieldhpal->setString(std::to_string(shield.hp));
						PLshield->runAction(shieldrepeat1a);
						shieldHP->runAction(shieldrepeat2a);
						shieldMN->runAction(shieldrepeat3a);
						shieldhpal->runAction(shieldrepeat4a);
						shieldhpmaxal->runAction(shieldrepeat5a);
						shieldmnal->runAction(shieldrepeat6a);
						shieldmnmaxal->runAction(shieldrepeat7a);
					}
					//���p�t
					if (job == MAGIC) {
						hpcut = (valkyrie.atk - magic.def);
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						magic.hp -= hpcut;
						PLmagic->setColor(ccc3(colormax, colordown, colordown));
						magicdmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
						this->addChild(magicdmf, onece);						//�_���[�W�������o��
						magicdmf->runAction(magicfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
						magicdmf->runAction(magicfdoutmov);						//�_���[�W��������ɓ�����
						magichpal->setString(std::to_string(magic.hp));
						PLmagic->runAction(magicrepeat1a);
						magicHP->runAction(magicrepeat2a);
						magicMN->runAction(magicrepeat3a);
						magichpal->runAction(magicrepeat4a);
						magichpmaxal->runAction(magicrepeat5a);
						magicmnal->runAction(magicrepeat6a);
						magicmnmaxal->runAction(magicrepeat7a);
					}
					//���E��
					if (job == HEALER) {
						//���E�҂̑���ɋR�m���_���[�W�����炤
						hpcut = (valkyrie.atk * skillupmedium) - shield.def;//���炷�_���[�W���v�Z
																			//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;									//HP�����炷
						shielddmf->setString(std::to_string(hpcut));		//�_���[�W��ω�������
						this->addChild(shielddmf, onece);					//�_���[�W�������o��
						shielddmf->runAction(shieldfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
						shielddmf->runAction(shieldfdoutmov);				//�_���[�W��������ɓ�����
						shieldhpal->setString(std::to_string(shield.hp));
						PLshield->runAction(shieldrepeat1a);
						shieldHP->runAction(shieldrepeat2a);
						shieldMN->runAction(shieldrepeat3a);
						shieldhpal->runAction(shieldrepeat4a);
						shieldhpmaxal->runAction(shieldrepeat5a);
						shieldmnal->runAction(shieldrepeat6a);
						shieldmnmaxal->runAction(shieldrepeat7a);
					}
				}
			}

		}
		//�L�����摜�̐F��߂�
		if (gameflame == flame100) {
			PLattacker->setColor(ccc3(colormax, colormax, colormax));
			PLshield->setColor(ccc3(colormax, colormax, colormax));
			PLhealer->setColor(ccc3(colormax, colormax, colormax));
			PLmagic->setColor(ccc3(colormax, colormax, colormax));
		}

		//���ʏ���
		//�t���[����230(��)�ɂȂ�ƌ��ʂ�\�L
		if (gameflame == flame230) {
			if (job == ATTACKER) {
				//�_���[�W�\�L
				String *attackerbsatk = String::createWithFormat("���m��%i�_���[�W�^����", hpcut);
				string _attackerbsatk = attackerbsatk->getCString();
				auto attackerbsalabel = Label::createWithSystemFont(_attackerbsatk, "HGRSGU.TTC", fontsizeL);
				attackerbsalabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerbsalabel, backdepth, damageS);
			}
			else if (job == SHIELD) {
				//�_���[�W�\�L
				String *shieldbsatk = String::createWithFormat("�R�m��%i�_���[�W�^����", hpcut);
				string _shieldbsatk = shieldbsatk->getCString();
				auto shieldalabel = Label::createWithSystemFont(_shieldbsatk, "HGRSGU.TTC", fontsizeL);
				shieldalabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(shieldalabel, backdepth, damageS);
			}
			else if (job == MAGIC) {
				//�_���[�W�\�L
				String *magicbsatk = String::createWithFormat("���p�t��%i�_���[�W�^����", hpcut);
				string _magicbsatk = magicbsatk->getCString();
				auto magicalabel = Label::createWithSystemFont(_magicbsatk, "HGRSGU.TTC", fontsizeL);
				magicalabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(magicalabel, backdepth, damageS);
			}
			else if (job == HEALER) {
				//�_���[�W�\�L
				String *healerbsatk = String::createWithFormat("���E�҂�%i�_���[�W�^����", hpcut);
				string _healerbsatk = healerbsatk->getCString();
				auto healeralabel = Label::createWithSystemFont(_healerbsatk, "HGRSGU.TTC", fontsizeL);
				healeralabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(healeralabel, backdepth, damageS);
			}
		}
	}
	//���@���L���[�X�L��
	if (bsact == BOSSSKILL) {
		//��̑���
		if (bskill == BSKILL1) {
			//�t���[����80(��)�ɂȂ�ƃX�L���̖��O�\��
			if (gameflame == flame80) {
				auto Gskill1 = CCLabelTTF::create("�u���炦�c�I�v", "JiyunoTsubasa.ttf", fontsizeL);
				Gskill1->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill1, backdepth, bossskill1S);
			}
			//�h�炷����
			if (gameflame == flame210) {
				auto move = CCSequence::create(
					CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f + 30)),
					CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f)),
					NULL
				);
				//�h�炷
				auto repeat = Repeat::create(move, 1);
				Boss->runAction(repeat);

				// ��ʃT�C�Y�擾
				Size winSize = Director::getInstance()->getVisibleSize();

				//�w�i��h�炷
				auto backmove = CCSequence::create(
					CCMoveTo::create(movecnt, ccp(winSize.width / 2, winSize.height / 1.5f + 30)),
					CCMoveTo::create(movecnt, ccp(winSize.width / 2, winSize.height / 1.5f)),
					NULL
				);
				//����h�炷��
				auto backrepeat = Repeat::create(backmove, continuity2);
				//�h�炷
				back->runAction(backrepeat);

				//�h��鏈��
				Damage();	//�h�炷�������ȉ�����

				//�R�m���݂����g���Ă��Ȃ��Ȃ�
				if (insteadflag == false && allinsteadflag == false) {
					//���m�_���[�W���󂯂����ɗh��鏈��
					if (pl1frame.choicejob == ATTACKER || pl2frame.choicejob == ATTACKER
						|| pl3frame.choicejob == ATTACKER) {
						PLattacker->runAction(attacker_repeat_bigquake[0]);
						attackerHP->runAction(attacker_repeat_bigquake[1]);
						attackerMN->runAction(attacker_repeat_bigquake[2]);
						attackerhpal->runAction(attacker_repeat_bigquake[3]);
						attackerhpmaxal->runAction(attacker_repeat_bigquake[4]);
						attackermnal->runAction(attacker_repeat_bigquake[5]);
						attackermnmaxal->runAction(attacker_repeat_bigquake[6]);
					}
					//�R�m�_���[�W���󂯂����ɗh��鏈��
					if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD
						|| pl3frame.choicejob == SHIELD) {
						PLshield->runAction(shieldrepeat1a);
						shieldHP->runAction(shieldrepeat2a);
						shieldMN->runAction(shieldrepeat3a);
						shieldhpal->runAction(shieldrepeat4a);
						shieldhpmaxal->runAction(shieldrepeat5a);
						shieldmnal->runAction(shieldrepeat6a);
						shieldmnmaxal->runAction(shieldrepeat7a);
					}
					//���p�t�_���[�W���󂯂����ɗh��鏈��
					if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC
						|| pl3frame.choicejob == MAGIC) {
						PLmagic->runAction(magicrepeat1a);
						magicHP->runAction(magicrepeat2a);
						magicMN->runAction(magicrepeat3a);
						magichpal->runAction(magicrepeat4a);
						magichpmaxal->runAction(magicrepeat5a);
						magicmnal->runAction(magicrepeat6a);
						magicmnmaxal->runAction(magicrepeat7a);
					}
					//���E�҃_���[�W���󂯂����ɗh��鏈��
					if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER
						|| pl3frame.choicejob == HEALER) {
						PLhealer->runAction(healerrepeat1a);
						healerHP->runAction(healerrepeat2a);
						healerMN->runAction(healerrepeat3a);
						healerhpal->runAction(healerrepeat4a);
						healerhpmaxal->runAction(healerrepeat5a);
						healermnal->runAction(healerrepeat6a);
						healermnmaxal->runAction(healerrepeat7a);
					}
					//�v���C���[�S����HP�����炷
					//�󂯂��_���[�W���Q�[�W��ɕ\��
					//���m
					if (pl1frame.choicejob == ATTACKER || pl2frame.choicejob == ATTACKER
						|| pl3frame.choicejob == ATTACKER) {
						hpcut = (valkyrie.atk * skillupmedium) - attacker.def;	//���炷�_���[�W���v�Z
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						attacker.hp -= hpcut;							//HP�����炷
						attackerdmf->setString(std::to_string(hpcut));	//�_���[�W��ω�������
						this->addChild(attackerdmf, onece);				//�_���[�W�������o��
						attackerdmf->runAction(attackerfadeout);		//�t�F�[�h�A�E�g����
						attackerdmf->runAction(attackerfdoutmov);		//��ɏオ���Ă�������
					}
					//�R�m
					if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD
						|| pl3frame.choicejob == SHIELD) {
						hpcut = (valkyrie.atk * skillupmedium) - shield.def;//���炷�_���[�W���v�Z
																		//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;								//HP�����炷
						shielddmf->setString(std::to_string(hpcut));	//�_���[�W��ω�������
						this->addChild(shielddmf, onece);				//�_���[�W�������o��
						shielddmf->runAction(shieldfadeout);			//�_���[�W�������t�F�[�h�A�E�g������
						shielddmf->runAction(shieldfdoutmov);			//�_���[�W��������ɓ�����
					}
					//���p�t
					if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC
						|| pl3frame.choicejob == MAGIC) {
						hpcut = (valkyrie.atk * skillupmedium) - magic.def;	//���炷�_���[�W���v�Z
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						magic.hp -= hpcut;								//HP�����炷
						magicdmf->setString(std::to_string(hpcut));		//�_���[�W��ω�������
						this->addChild(magicdmf, onece);				//�_���[�W�������o��
						magicdmf->runAction(magicfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
						magicdmf->runAction(magicfdoutmov);				//�_���[�W��������ɓ�����
					}
					//���E��
					if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER
						|| pl3frame.choicejob == HEALER) {
						hpcut = (valkyrie.atk * skillupmedium) - healer.def;//���炷�_���[�W���v�Z
																			//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						healer.hp -= hpcut;									//HP�����炷
						healerdmf->setString(std::to_string(hpcut));		//�_���[�W��ω�������
						this->addChild(healerdmf, onece);					//�_���[�W�������o��
						healerdmf->runAction(healerfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
						healerdmf->runAction(healerfdoutmov);				//�_���[�W��������ɓ�����
					}
				}

				//�R�m���P�݂̔����g���Ă���Ƃ�
				if (insteadflag == true) {
					//���m��I�񂾏ꍇ
					if (sskillchoice == ATTACKER) {
						//���m�̑���ɋR�m���_���[�W�����炤
						if (pl1frame.choicejob == ATTACKER || pl2frame.choicejob == ATTACKER
							|| pl3frame.choicejob == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - shield.def;//���炷�_���[�W���v�Z
							hpcut = max(1, hpcut);							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							shield.hp -= hpcut;								//HP�����炷
							shielddmf->setString(std::to_string(hpcut));	//�_���[�W��ω�������
							this->addChild(shielddmf, onece);				//�_���[�W�������o��
							shielddmf->runAction(shieldfadeout);			//�_���[�W�������t�F�[�h�A�E�g������
							shielddmf->runAction(shieldfdoutmov);			//�_���[�W��������ɓ�����
							PLshield->runAction(shieldrepeat1a);			//�摜�h�炷�������ȉ�����
							shieldHP->runAction(shieldrepeat2a);
							shieldMN->runAction(shieldrepeat3a);
							shieldhpal->runAction(shieldrepeat4a);
							shieldhpmaxal->runAction(shieldrepeat5a);
							shieldmnal->runAction(shieldrepeat6a);
							shieldmnmaxal->runAction(shieldrepeat7a);
						}
						//���p�t
						if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC
							|| pl3frame.choicejob == MAGIC) {
							hpcut = (valkyrie.atk * skillupmedium) - magic.def;	//���炷�_���[�W���v�Z
							hpcut = max(1, hpcut);							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							magic.hp -= hpcut;								//HP�����炷
							magicdmf->setString(std::to_string(hpcut));		//�_���[�W��ω�������

							//�_���[�W�����A�N�V����
							this->addChild(magicdmf, onece);				//�_���[�W�������o��
							magicdmf->runAction(magicfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
							magicdmf->runAction(magicfdoutmov);				//�_���[�W��������ɓ�����
							PLmagic->runAction(magicrepeat1a);
							magicHP->runAction(magicrepeat2a);
							magicMN->runAction(magicrepeat3a);
							magichpal->runAction(magicrepeat4a);
							magichpmaxal->runAction(magicrepeat5a);
							magicmnal->runAction(magicrepeat6a);
							magicmnmaxal->runAction(magicrepeat7a);
						}
						//���E��
						if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER
							|| pl3frame.choicejob == HEALER) {
							hpcut = (valkyrie.atk * skillupmedium) - healer.def;//���炷�_���[�W���v�Z
							hpcut = max(1, hpcut);							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							healer.hp -= hpcut;								//HP�����炷
							healerdmf->setString(std::to_string(hpcut));	//�_���[�W��ω�������
							this->addChild(healerdmf, onece);				//�_���[�W�������o��
							healerdmf->runAction(healerfadeout);			//�_���[�W�������t�F�[�h�A�E�g������
							healerdmf->runAction(healerfdoutmov);			//�_���[�W��������ɓ�����
							PLhealer->runAction(healerrepeat1a);
							healerHP->runAction(healerrepeat2a);
							healerMN->runAction(healerrepeat3a);
							healerhpal->runAction(healerrepeat4a);
							healerhpmaxal->runAction(healerrepeat5a);
							healermnal->runAction(healerrepeat6a);
							healermnmaxal->runAction(healerrepeat7a);
						}
					}
					//���p�t��I�񂾏ꍇ
					if (sskillchoice == MAGIC) {
						//���m
						if (pl1frame.choicejob == ATTACKER || pl2frame.choicejob == ATTACKER
							|| pl3frame.choicejob == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - attacker.def;//���炷�_���[�W���v�Z
							hpcut = max(1, hpcut);							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							attacker.hp -= hpcut;							//HP�����炷
							attackerdmf->setString(std::to_string(hpcut));	//�_���[�W��ω�������
							this->addChild(attackerdmf, onece);				//�_���[�W�������o��
							attackerdmf->runAction(attackerfadeout);		//�_���[�W�������t�F�[�h�A�E�g������
							attackerdmf->runAction(attackerfdoutmov);		//�_���[�W��������ɓ�����
							PLattacker->runAction(attacker_repeat_bigquake[0]);		//�摜�h�炷�������ȉ�����
							attackerHP->runAction(attacker_repeat_bigquake[1]);
							attackerMN->runAction(attacker_repeat_bigquake[2]);
							attackerhpal->runAction(attacker_repeat_bigquake[3]);
							attackerhpmaxal->runAction(attacker_repeat_bigquake[4]);
							attackermnal->runAction(attacker_repeat_bigquake[5]);
							attackermnmaxal->runAction(attacker_repeat_bigquake[6]);
						}
						//���p�t�̑���ɋR�m���_���[�W�����炤
						if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC
							|| pl3frame.choicejob == MAGIC) {
							hpcut = (valkyrie.atk * skillupmedium) - shield.def;	//���炷�_���[�W���v�Z
							hpcut = max(1, hpcut);							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							shield.hp -= hpcut;								//HP�����炷
							shielddmf->setString(std::to_string(hpcut));	//�_���[�W��ω�������
							this->addChild(shielddmf, onece);				//�_���[�W�������o��
							shielddmf->runAction(shieldfadeout);			//�_���[�W�������t�F�[�h�A�E�g������
							shielddmf->runAction(shieldfdoutmov);			//�_���[�W��������ɓ�����
							PLshield->runAction(shieldrepeat1a);
							shieldHP->runAction(shieldrepeat2a);
							shieldMN->runAction(shieldrepeat3a);
							shieldhpal->runAction(shieldrepeat4a);
							shieldhpmaxal->runAction(shieldrepeat5a);
							shieldmnal->runAction(shieldrepeat6a);
							shieldmnmaxal->runAction(shieldrepeat7a);
						}
						//���E��
						if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER
							|| pl3frame.choicejob == HEALER) {
							hpcut = (valkyrie.atk * skillupmedium) - healer.def;//���炷�_���[�W���v�Z
							hpcut = max(1, hpcut);							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							healer.hp -= hpcut;								//HP�����炷
							healerdmf->setString(std::to_string(hpcut));	//�_���[�W��ω�������
							this->addChild(healerdmf, onece);				//�_���[�W�������o��
							healerdmf->runAction(healerfadeout);			//�_���[�W�������t�F�[�h�A�E�g������
							healerdmf->runAction(healerfdoutmov);			//�_���[�W��������ɓ�����
							PLhealer->runAction(healerrepeat1a);
							healerHP->runAction(healerrepeat2a);
							healerMN->runAction(healerrepeat3a);
							healerhpal->runAction(healerrepeat4a);
							healerhpmaxal->runAction(healerrepeat5a);
							healermnal->runAction(healerrepeat6a);
							healermnmaxal->runAction(healerrepeat7a);
						}
					}
					//���E�҂�I�񂾏ꍇ
					if (sskillchoice == HEALER) {
						//���m
						if (pl1frame.choicejob == ATTACKER || pl2frame.choicejob == ATTACKER
							|| pl3frame.choicejob == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - attacker.def;//���炷�_���[�W���v�Z
							hpcut = max(1, hpcut);							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							attacker.hp -= hpcut;							//HP�����炷
							attackerdmf->setString(std::to_string(hpcut));	//�_���[�W��ω�������
							this->addChild(attackerdmf, onece);				//�_���[�W�������o��
							attackerdmf->runAction(attackerfadeout);		//�_���[�W�������t�F�[�h�A�E�g������
							attackerdmf->runAction(attackerfdoutmov);		//�_���[�W��������ɓ�����
							PLattacker->runAction(attacker_repeat_bigquake[0]);		//�摜�h�炷�������ȉ�����
							attackerHP->runAction(attacker_repeat_bigquake[1]);
							attackerMN->runAction(attacker_repeat_bigquake[2]);
							attackerhpal->runAction(attacker_repeat_bigquake[3]);
							attackerhpmaxal->runAction(attacker_repeat_bigquake[4]);
							attackermnal->runAction(attacker_repeat_bigquake[5]);
							attackermnmaxal->runAction(attacker_repeat_bigquake[6]);
						}
						//���p�t
						if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC
							|| pl3frame.choicejob == MAGIC) {
							hpcut = (valkyrie.atk * skillupmedium) - magic.def;	//���炷�_���[�W���v�Z
							hpcut = max(1, hpcut);							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							magic.hp -= hpcut;								//HP�����炷
							magicdmf->setString(std::to_string(hpcut));		//�_���[�W��ω�������
							this->addChild(magicdmf, onece);				//�_���[�W�������o��
							magicdmf->runAction(magicfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
							magicdmf->runAction(magicfdoutmov);				//�_���[�W��������ɓ�����
							PLmagic->runAction(magicrepeat1a);
							magicHP->runAction(magicrepeat2a);
							magicMN->runAction(magicrepeat3a);
							magichpal->runAction(magicrepeat4a);
							magichpmaxal->runAction(magicrepeat5a);
							magicmnal->runAction(magicrepeat6a);
							magicmnmaxal->runAction(magicrepeat7a);
						}
						//���E�҂̑���ɋR�m���_���[�W�����炤
						if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER
							|| pl3frame.choicejob == HEALER) {
							hpcut = (valkyrie.atk * skillupmedium) - shield.def;//���炷�_���[�W���v�Z
							hpcut = max(1, hpcut);							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							shield.hp -= hpcut;								//HP�����炷
							shielddmf->setString(std::to_string(hpcut));	//�_���[�W��ω�������
							this->addChild(shielddmf, onece);				//�_���[�W�������o��
							shielddmf->runAction(shieldfadeout);			//�_���[�W�������t�F�[�h�A�E�g������
							shielddmf->runAction(shieldfdoutmov);			//�_���[�W��������ɓ�����
							PLshield->runAction(shieldrepeat1a);
							shieldHP->runAction(shieldrepeat2a);
							shieldMN->runAction(shieldrepeat3a);
							shieldhpal->runAction(shieldrepeat4a);
							shieldhpmaxal->runAction(shieldrepeat5a);
							shieldmnal->runAction(shieldrepeat6a);
							shieldmnmaxal->runAction(shieldrepeat7a);
						}
					}
					if (job == SHIELD) {
						//���m�_���[�W���󂯂����ɗh��鏈��
						if (pl1frame.choicejob == ATTACKER || pl2frame.choicejob == ATTACKER
							|| pl3frame.choicejob == ATTACKER) {
							PLattacker->runAction(attacker_repeat_bigquake[0]);
							attackerHP->runAction(attacker_repeat_bigquake[1]);
							attackerMN->runAction(attacker_repeat_bigquake[2]);
							attackerhpal->runAction(attacker_repeat_bigquake[3]);
							attackerhpmaxal->runAction(attacker_repeat_bigquake[4]);
							attackermnal->runAction(attacker_repeat_bigquake[5]);
							attackermnmaxal->runAction(attacker_repeat_bigquake[6]);
						}
						//�R�m�_���[�W���󂯂����ɗh��鏈��
						if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD
							|| pl3frame.choicejob == SHIELD) {
							PLshield->runAction(shieldrepeat1a);
							shieldHP->runAction(shieldrepeat2a);
							shieldMN->runAction(shieldrepeat3a);
							shieldhpal->runAction(shieldrepeat4a);
							shieldhpmaxal->runAction(shieldrepeat5a);
							shieldmnal->runAction(shieldrepeat6a);
							shieldmnmaxal->runAction(shieldrepeat7a);
						}
						//���p�t�_���[�W���󂯂����ɗh��鏈��
						if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC
							|| pl3frame.choicejob == MAGIC) {
							PLmagic->runAction(magicrepeat1a);
							magicHP->runAction(magicrepeat2a);
							magicMN->runAction(magicrepeat3a);
							magichpal->runAction(magicrepeat4a);
							magichpmaxal->runAction(magicrepeat5a);
							magicmnal->runAction(magicrepeat6a);
							magicmnmaxal->runAction(magicrepeat7a);
						}
						//���E�҃_���[�W���󂯂����ɗh��鏈��
						if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER
							|| pl3frame.choicejob == HEALER) {
							PLhealer->runAction(healerrepeat1a);
							healerHP->runAction(healerrepeat2a);
							healerMN->runAction(healerrepeat3a);
							healerhpal->runAction(healerrepeat4a);
							healerhpmaxal->runAction(healerrepeat5a);
							healermnal->runAction(healerrepeat6a);
							healermnmaxal->runAction(healerrepeat7a);
						}
						//�v���C���[�S����HP�����炷
						//�󂯂��_���[�W���Q�[�W��ɕ\��
						//���m
						if (pl1frame.choicejob == ATTACKER || pl2frame.choicejob == ATTACKER
							|| pl3frame.choicejob == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - attacker.def;	//���炷�_���[�W���v�Z
																					//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							attacker.hp -= hpcut;							//HP�����炷
							attackerdmf->setString(std::to_string(hpcut));	//�_���[�W��ω�������
							this->addChild(attackerdmf, onece);				//�_���[�W�������o��
							attackerdmf->runAction(attackerfadeout);		//�t�F�[�h�A�E�g����
							attackerdmf->runAction(attackerfdoutmov);		//��ɏオ���Ă�������
						}
						//�R�m
						if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD
							|| pl3frame.choicejob == SHIELD) {
							hpcut = (valkyrie.atk * skillupmedium) - shield.def;//���炷�_���[�W���v�Z
																				//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;								//HP�����炷
							shielddmf->setString(std::to_string(hpcut));	//�_���[�W��ω�������
							this->addChild(shielddmf, onece);				//�_���[�W�������o��
							shielddmf->runAction(shieldfadeout);			//�_���[�W�������t�F�[�h�A�E�g������
							shielddmf->runAction(shieldfdoutmov);			//�_���[�W��������ɓ�����
						}
						//���p�t
						if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC
							|| pl3frame.choicejob == MAGIC) {
							hpcut = (valkyrie.atk * skillupmedium) - magic.def;	//���炷�_���[�W���v�Z
																				//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							magic.hp -= hpcut;								//HP�����炷
							magicdmf->setString(std::to_string(hpcut));		//�_���[�W��ω�������
							this->addChild(magicdmf, onece);				//�_���[�W�������o��
							magicdmf->runAction(magicfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
							magicdmf->runAction(magicfdoutmov);				//�_���[�W��������ɓ�����
						}
						//���E��
						if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER
							|| pl3frame.choicejob == HEALER) {
							hpcut = (valkyrie.atk * skillupmedium) - healer.def;//���炷�_���[�W���v�Z
																				//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							healer.hp -= hpcut;									//HP�����炷
							healerdmf->setString(std::to_string(hpcut));		//�_���[�W��ω�������
							this->addChild(healerdmf, onece);					//�_���[�W�������o��
							healerdmf->runAction(healerfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
							healerdmf->runAction(healerfdoutmov);				//�_���[�W��������ɓ�����

						}
					}
				}

				//�R�m���S�݂̔����g���Ă��鎞
				if (allinsteadflag == true) {
					hpcut = (valkyrie.atk * skillupmedium) - healer.def;//���炷�_���[�W���v�Z
																		//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
					if (hpcut <= 1) {
						hpcut = 1;
					}
					if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD
						|| pl3frame.choicejob == SHIELD) {
						shield.hp -= hpcut;								//HP�����炷
						shielddmf->setString(std::to_string(hpcut));	//�_���[�W��ω�������
						this->addChild(shielddmf, onece);				//�_���[�W�������o��
						shielddmf->runAction(shieldfadeout);			//�_���[�W�������t�F�[�h�A�E�g������
						shielddmf->runAction(shieldfdoutmov);			//�_���[�W��������ɓ�����
						PLshield->runAction(shieldrepeat1a);			//�摜�h�炷�������ȉ�����
						shieldHP->runAction(shieldrepeat2a);
						shieldMN->runAction(shieldrepeat3a);
						shieldhpal->runAction(shieldrepeat4a);
						shieldhpmaxal->runAction(shieldrepeat5a);
						shieldmnal->runAction(shieldrepeat6a);
						shieldmnmaxal->runAction(shieldrepeat7a);
					}
				}

				//�g�ɐ��߂Ă��̃L������
				PLattacker->setColor(ccc3(colormax, colordown, colordown));
				PLshield->setColor(ccc3(colormax, colordown, colordown));
				PLhealer->setColor(ccc3(colormax, colordown, colordown));
				PLmagic->setColor(ccc3(colormax, colordown, colordown));

				//HP�̐��l��ς���
				attackerhpal->setString(std::to_string(attacker.hp));
				shieldhpal->setString(std::to_string(shield.hp));
				healerhpal->setString(std::to_string(healer.hp));
				magichpal->setString(std::to_string(magic.hp));
			}
			//�R�m�̑S�݂̔����g�������Ɏg������
			if (gameflame == flame220) {
				if (allinsteadflag == true) {
					hpcut = (valkyrie.atk * skillupmedium) - healer.def;//���炷�_���[�W���v�Z
																		//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
					if (hpcut <= 1) {
						hpcut = 1;
					}
					if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD
						|| pl3frame.choicejob == SHIELD) {
						shield.hp -= hpcut;								//HP�����炷
						shielddmf->setString(std::to_string(hpcut));	//�_���[�W��ω�������
						this->addChild(shielddmf, onece);				//�_���[�W�������o��
						shielddmf->runAction(shieldfadeout);			//�_���[�W�������t�F�[�h�A�E�g������
						shielddmf->runAction(shieldfdoutmov);			//�_���[�W��������ɓ�����
					}
				}

				//HP�̐��l��ς���
				attackerhpal->setString(std::to_string(attacker.hp));
				shieldhpal->setString(std::to_string(shield.hp));
				healerhpal->setString(std::to_string(healer.hp));
				magichpal->setString(std::to_string(magic.hp));
			}
			//�R�m�̒P�݂̔��ƑS�݂̔����g�������Ɏg������
			if (gameflame == flame230) {
				if (insteadflag == true || allinsteadflag == true) {
					hpcut = (valkyrie.atk * skillupmedium) - healer.def;//���炷�_���[�W���v�Z
					//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
					if (hpcut <= 1) {
						hpcut = 1;
					}
					if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD
						|| pl3frame.choicejob == SHIELD) {
						shield.hp -= hpcut;								//HP�����炷
						shielddmf->setString(std::to_string(hpcut));	//�_���[�W��ω�������
						this->addChild(shielddmf, onece);				//�_���[�W�������o��
						shielddmf->runAction(shieldfadeout);			//�_���[�W�������t�F�[�h�A�E�g������
						shielddmf->runAction(shieldfdoutmov);			//�_���[�W��������ɓ�����
					}
				}

				//HP�̐��l��ς���
				attackerhpal->setString(std::to_string(attacker.hp));
				shieldhpal->setString(std::to_string(shield.hp));
				healerhpal->setString(std::to_string(healer.hp));
				magichpal->setString(std::to_string(magic.hp));
			}
			//�_���[�W����
			//�t���[����250(��)�ɂȂ�ƃ_���[�W�\�L
			if (gameflame == flame250) {
				auto Gskill1dec = CCLabelTTF::create("�S���Ƀ_���[�W��^����", "HGRSGU.TTC", fontsizeL);
				Gskill1dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill1dec, backdepth, bossskill1damageS);

				//�L�����̐F��߂�
				PLattacker->setColor(ccc3(colormax, colormax, colormax));
				PLshield->setColor(ccc3(colormax, colormax, colormax));
				PLhealer->setColor(ccc3(colormax, colormax, colormax));
				PLmagic->setColor(ccc3(colormax, colormax, colormax));
			}

		}
		//��̑���
		if (bskill == BSKILL2) {
			//�t���[����80(��)�ɂȂ�ƃX�L���̖��O�\��
			if (gameflame == flame80) {

				auto Gskill2 = CCLabelTTF::create("�u�₠�����I�v", "HGRSGU.TTC", fontsizeL);
				Gskill2->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill2, backdepth, bossskill2S);

				//�R�m�̐g����X�L�����������Ă��Ȃ��Ƃ�
				if (insteadflag == false) {
					//���m
					if (job == ATTACKER) {
						hpcut = (valkyrie.atk - attacker.def);						//�_���[�W���v�Z
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						attacker.hp -= hpcut;									//HP���ւ炷
						PLattacker->setColor(ccc3(colormax, colordown, colordown));	//�󂯂���Ԃ�����
						attackerdmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
						this->addChild(attackerdmf, onece);							//�_���[�W�������o��
						attackerdmf->runAction(attackerfadeout);					//�_���[�W�������t�F�[�h�A�E�g������
						attackerdmf->runAction(attackerfdoutmov);					//�_���[�W��������ɓ�����
						attackerhpal->setString(std::to_string(attacker.hp));		//���l��ς��遫�ȉ�����
					}
					//�R�m
					else if (job == SHIELD) {
						hpcut = (valkyrie.atk - shield.def);
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;
						PLshield->setColor(ccc3(colormax, colordown, colordown));
						shielddmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
						this->addChild(shielddmf, onece);							//�_���[�W�������o��
						shielddmf->runAction(shieldfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
						shielddmf->runAction(shieldfdoutmov);						//�_���[�W��������ɓ�����
						shieldhpal->setString(std::to_string(shield.hp));
					}
					//���p�t
					else if (job == MAGIC) {
						hpcut = (valkyrie.atk - magic.def);
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						magic.hp -= hpcut;
						PLmagic->setColor(ccc3(colormax, colordown, colordown));
						magicdmf->setString(std::to_string(hpcut));					//�_���[�W��ω�������
						this->addChild(magicdmf, onece);							//�_���[�W�������o��
						magicdmf->runAction(magicfadeout);							//�_���[�W�������t�F�[�h�A�E�g������
						magicdmf->runAction(magicfdoutmov);							//�_���[�W��������ɓ�����
						magichpal->setString(std::to_string(magic.hp));
					}
					//���E��
					else if (job == HEALER) {
						hpcut = (valkyrie.atk - healer.def);
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						healer.hp -= hpcut;
						PLhealer->setColor(ccc3(colormax, colordown, colordown));
						healerdmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
						this->addChild(healerdmf, onece);							//�_���[�W�������o��
						healerdmf->runAction(healerfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
						healerdmf->runAction(healerfdoutmov);						//�_���[�W��������ɓ�����
						healerhpal->setString(std::to_string(healer.hp));
					}
				}

				//�R�m�̒P�̐g����t���O���������Ă���Ƃ�
				if (insteadflag == true) {
					//���m��I�񂾏ꍇ
					if (sskillchoice == ATTACKER) {
						//���m
						if (job == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - shield.def;//���炷�_���[�W���v�Z
							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;									//HP�����炷
							shielddmf->setString(std::to_string(hpcut));		//�_���[�W��ω�������
							this->addChild(shielddmf, onece);					//�_���[�W�������o��
							shielddmf->runAction(shieldfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
							shielddmf->runAction(shieldfdoutmov);				//�_���[�W��������ɓ�����
						}
						//�R�m
						if (job == SHIELD) {
							hpcut = (valkyrie.atk - shield.def);
							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;
							PLshield->setColor(ccc3(colormax, colordown, colordown));
							shielddmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
							this->addChild(shielddmf, onece);							//�_���[�W�������o��
							shielddmf->runAction(shieldfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
							shielddmf->runAction(shieldfdoutmov);						//�_���[�W��������ɓ�����
							shieldhpal->setString(std::to_string(shield.hp));
						}
						//���p�t
						if (job == MAGIC) {
							hpcut = (valkyrie.atk - magic.def);
							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							magic.hp -= hpcut;
							PLmagic->setColor(ccc3(colormax, colordown, colordown));
							magicdmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
							this->addChild(magicdmf, onece);							//�_���[�W�������o��
							magicdmf->runAction(magicfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
							magicdmf->runAction(magicfdoutmov);						//�_���[�W��������ɓ�����
							magichpal->setString(std::to_string(magic.hp));
						}
						//���E��
						if (job == HEALER) {
							hpcut = (valkyrie.atk - healer.def);
							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							healer.hp -= hpcut;
							PLhealer->setColor(ccc3(colormax, colordown, colordown));
							healerdmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
							this->addChild(healerdmf, onece);							//�_���[�W�������o��
							healerdmf->runAction(healerfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
							healerdmf->runAction(healerfdoutmov);						//�_���[�W��������ɓ�����
							healerhpal->setString(std::to_string(healer.hp));
						}
					}
					//���p�t��I�񂾏ꍇ
					if (sskillchoice == MAGIC) {
						if (job == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - attacker.def;	//���炷�_���[�W���v�Z
							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							attacker.hp -= hpcut;									//HP�����炷
							attackerdmf->setString(std::to_string(hpcut));			//�_���[�W��ω�������
							this->addChild(attackerdmf, onece);						//�_���[�W�������o��
							attackerdmf->runAction(attackerfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
							attackerdmf->runAction(attackerfdoutmov);				//�_���[�W��������ɓ�����
						}
						//�R�m
						if (job == SHIELD) {
							hpcut = (valkyrie.atk - shield.def);
							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;
							PLshield->setColor(ccc3(colormax, colordown, colordown));
							shielddmf->setString(std::to_string(hpcut));			//�_���[�W��ω�������
							this->addChild(shielddmf, onece);						//�_���[�W�������o��
							shielddmf->runAction(shieldfadeout);					//�_���[�W�������t�F�[�h�A�E�g������
							shielddmf->runAction(shieldfdoutmov);					//�_���[�W��������ɓ�����
							shieldhpal->setString(std::to_string(shield.hp));
						}
						//���p�t
						if (job == MAGIC) {
							//���p�t�̑���ɋR�m���_���[�W�����炤
							if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC
								|| pl3frame.choicejob == MAGIC) {
								hpcut = (valkyrie.atk * skillupmedium) - shield.def;//���炷�_���[�W���v�Z
																					//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
								if (hpcut <= 1) {
									hpcut = 1;
								}
								shield.hp -= hpcut;									//HP�����炷
								shielddmf->setString(std::to_string(hpcut));		//�_���[�W��ω�������
								this->addChild(shielddmf, onece);					//�_���[�W�������o��
								shielddmf->runAction(shieldfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
								shielddmf->runAction(shieldfdoutmov);				//�_���[�W��������ɓ�����
							}
						}
						//���E��
						if (job == HEALER) {
							hpcut = (valkyrie.atk - healer.def);
							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							healer.hp -= hpcut;
							PLhealer->setColor(ccc3(colormax, colordown, colordown));
							healerdmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
							this->addChild(healerdmf, onece);							//�_���[�W�������o��
							healerdmf->runAction(healerfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
							healerdmf->runAction(healerfdoutmov);						//�_���[�W��������ɓ�����
							healerhpal->setString(std::to_string(healer.hp));
						}
					}
					//���E�҂�I�񂾏ꍇ
					if (sskillchoice == HEALER) {
						//���m
						if (job == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - attacker.def;//���炷�_���[�W���v�Z
																				//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							attacker.hp -= hpcut;									//HP�����炷
							attackerdmf->setString(std::to_string(hpcut));		//�_���[�W��ω�������
							this->addChild(attackerdmf, onece);					//�_���[�W�������o��
							attackerdmf->runAction(attackerfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
							attackerdmf->runAction(attackerfdoutmov);				//�_���[�W��������ɓ�����
						}
						//�R�m
						if (job == SHIELD) {
							hpcut = (valkyrie.atk - shield.def);
							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;
							PLshield->setColor(ccc3(colormax, colordown, colordown));
							shielddmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
							this->addChild(shielddmf, onece);							//�_���[�W�������o��
							shielddmf->runAction(shieldfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
							shielddmf->runAction(shieldfdoutmov);						//�_���[�W��������ɓ�����
							shieldhpal->setString(std::to_string(shield.hp));
						}
						//���p�t
						if (job == MAGIC) {
							hpcut = (valkyrie.atk - magic.def);
							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							magic.hp -= hpcut;
							PLmagic->setColor(ccc3(colormax, colordown, colordown));
							magicdmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
							this->addChild(magicdmf, onece);							//�_���[�W�������o��
							magicdmf->runAction(magicfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
							magicdmf->runAction(magicfdoutmov);						//�_���[�W��������ɓ�����
							magichpal->setString(std::to_string(magic.hp));
						}
						//���E��
						if (job == HEALER) {
							//���E�҂̑���ɋR�m���_���[�W�����炤
							if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER
								|| pl3frame.choicejob == HEALER) {
								hpcut = (valkyrie.atk * skillupmedium) - shield.def;//���炷�_���[�W���v�Z
																					//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
								if (hpcut <= 1) {
									hpcut = 1;
								}
								shield.hp -= hpcut;									//HP�����炷
								shielddmf->setString(std::to_string(hpcut));		//�_���[�W��ω�������
								this->addChild(shielddmf, onece);					//�_���[�W�������o��
								shielddmf->runAction(shieldfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
								shielddmf->runAction(shieldfdoutmov);				//�_���[�W��������ɓ�����
							}
						}
					}
				}

				//�G�t�F�N�g
				//�G�t�F�N�g�̕\��
				CCSize s = CCDirector::sharedDirector()->getWinSize();
				//�G�t�F�N�g�̗�����w��
				CCParticleSystemQuad* particle = CCParticleSystemQuad::create("Effect/bosseffect.plist");
				particle->setAutoRemoveOnFinish(true);

				particle->resetSystem();									//�G�t�F�N�g�J�n
				particle->setPosition(ccp(rightSize.width / 2,
					rightSize.height / 3));			//�G�t�F�N�g��\������ꏊ�̐ݒ�
				this->addChild(particle, backdepth, bossskill1E);			//�G�t�F�N�g��z�u
			}
			//���ڂ̍U��
			if (gameflame == flame150) {
				//���ڂ�HP�����炷

				//�_���[�W���󂯂����h�炷����
				Damage();

				//�R�m�̒P�̐g����X�L�����������Ă��Ȃ��Ƃ�
				if (insteadflag == false) {
					//���m
					if (job == ATTACKER) {
						hpcut = (valkyrie.atk - attacker.def);					//�_���[�W�v�Z
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						attacker.hp -= hpcut;									//HP�����炷
						PLattacker->setColor(ccc3(colormax, colordown, colordown));	//�_���[�W���������(�v���C���[�̉摜��Ԃ�����)
						attackerdmf->setString(std::to_string(hpcut));			//�_���[�W��ω�������
						this->addChild(attackerdmf, onece);						//�_���[�W�������o��
						attackerdmf->runAction(attackerfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
						attackerdmf->runAction(attackerfdoutmov);				//�_���[�W��������ɓ�����
						attackerhpal->setString(std::to_string(attacker.hp));	//HP���l�����炷
						PLattacker->runAction(attacker_repeat_bigquake[0]);
						attackerHP->runAction(attacker_repeat_bigquake[1]);
						attackerMN->runAction(attacker_repeat_bigquake[2]);
						attackerhpal->runAction(attacker_repeat_bigquake[3]);
						attackerhpmaxal->runAction(attacker_repeat_bigquake[4]);
						attackermnal->runAction(attacker_repeat_bigquake[5]);
						attackermnmaxal->runAction(attacker_repeat_bigquake[6]);
					}
					//�R�m
					else if (job == SHIELD) {
						hpcut = (valkyrie.atk - shield.def);
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;
						PLshield->setColor(ccc3(colormax, colordown, colordown));
						shieldhpal->setString(std::to_string(shield.hp));
						shielddmf->setString(std::to_string(hpcut));			//�_���[�W��ω�������
						this->addChild(shielddmf, onece);						//�_���[�W�������o��
						shielddmf->runAction(shieldfadeout);					//�_���[�W�������t�F�[�h�A�E�g������
						shielddmf->runAction(shieldfdoutmov);					//�_���[�W��������ɓ�����
						PLshield->runAction(shieldrepeat1a);
						shieldHP->runAction(shieldrepeat2a);
						shieldMN->runAction(shieldrepeat3a);
						shieldhpal->runAction(shieldrepeat4a);
						shieldhpmaxal->runAction(shieldrepeat5a);
						shieldmnal->runAction(shieldrepeat6a);
						shieldmnmaxal->runAction(shieldrepeat7a);
					}
					//���p�t
					else if (job == MAGIC) {
						hpcut = (valkyrie.atk - magic.def);
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						magic.hp -= hpcut;
						PLmagic->setColor(ccc3(colormax, colordown, colordown));
						magichpal->setString(std::to_string(magic.hp));
						magicdmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
						this->addChild(magicdmf, onece);						//�_���[�W�������o��
						magicdmf->runAction(magicfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
						magicdmf->runAction(magicfdoutmov);						//�_���[�W��������ɓ�����
						PLmagic->runAction(magicrepeat1a);
						magicHP->runAction(magicrepeat2a);
						magicMN->runAction(magicrepeat3a);
						magichpal->runAction(magicrepeat4a);
						magichpmaxal->runAction(magicrepeat5a);
						magicmnal->runAction(magicrepeat6a);
						magicmnmaxal->runAction(magicrepeat7a);
					}
					//���E��
					else if (job == HEALER) {
						hpcut = (valkyrie.atk - healer.def);
						//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
						if (hpcut <= 1) {
							hpcut = 1;
						}
						healer.hp -= hpcut;
						PLhealer->setColor(ccc3(colormax, colordown, colordown));
						healerhpal->setString(std::to_string(healer.hp));
						healerdmf->setString(std::to_string(hpcut));			//�_���[�W��ω�������
						this->addChild(healerdmf, onece);						//�_���[�W�������o��
						healerdmf->runAction(healerfadeout);					//�_���[�W�������t�F�[�h�A�E�g������
						healerdmf->runAction(healerfdoutmov);					//�_���[�W��������ɓ�����
						PLhealer->runAction(healerrepeat1a);
						healerHP->runAction(healerrepeat2a);
						healerMN->runAction(healerrepeat3a);
						healerhpal->runAction(healerrepeat4a);
						healerhpmaxal->runAction(healerrepeat5a);
						healermnal->runAction(healerrepeat6a);
						healermnmaxal->runAction(healerrepeat7a);
					}
				}

				//�R�m�̒P�̐g����t���O���������Ă���Ƃ�
				if (insteadflag == true) {
					//���m��I�񂾏ꍇ
					if (sskillchoice == ATTACKER) {
						//���m
						if (job == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - shield.def;//���炷�_���[�W���v�Z
																				//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;									//HP�����炷
							shielddmf->setString(std::to_string(hpcut));		//�_���[�W��ω�������
							this->addChild(shielddmf, onece);					//�_���[�W�������o��
							shielddmf->runAction(shieldfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
							shielddmf->runAction(shieldfdoutmov);				//�_���[�W��������ɓ�����
							shieldhpal->setString(std::to_string(shield.hp));
							PLshield->runAction(shieldrepeat1a);
							shieldHP->runAction(shieldrepeat2a);
							shieldMN->runAction(shieldrepeat3a);
							shieldhpal->runAction(shieldrepeat4a);
							shieldhpmaxal->runAction(shieldrepeat5a);
							shieldmnal->runAction(shieldrepeat6a);
							shieldmnmaxal->runAction(shieldrepeat7a);
						}
						//�R�m
						if (job == SHIELD) {
							hpcut = (valkyrie.atk - shield.def);
							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;
							PLshield->setColor(ccc3(colormax, colordown, colordown));
							shielddmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
							this->addChild(shielddmf, onece);							//�_���[�W�������o��
							shielddmf->runAction(shieldfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
							shielddmf->runAction(shieldfdoutmov);						//�_���[�W��������ɓ�����
							shieldhpal->setString(std::to_string(shield.hp));
							PLshield->runAction(shieldrepeat1a);
							shieldHP->runAction(shieldrepeat2a);
							shieldMN->runAction(shieldrepeat3a);
							shieldhpal->runAction(shieldrepeat4a);
							shieldhpmaxal->runAction(shieldrepeat5a);
							shieldmnal->runAction(shieldrepeat6a);
							shieldmnmaxal->runAction(shieldrepeat7a);
						}
						//���p�t
						if (job == MAGIC) {
							hpcut = (valkyrie.atk - magic.def);
							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							magic.hp -= hpcut;
							PLmagic->setColor(ccc3(colormax, colordown, colordown));
							magicdmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
							this->addChild(magicdmf, onece);							//�_���[�W�������o��
							magicdmf->runAction(magicfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
							magicdmf->runAction(magicfdoutmov);						//�_���[�W��������ɓ�����
							magichpal->setString(std::to_string(magic.hp));
							PLmagic->runAction(magicrepeat1a);
							magicHP->runAction(magicrepeat2a);
							magicMN->runAction(magicrepeat3a);
							magichpal->runAction(magicrepeat4a);
							magichpmaxal->runAction(magicrepeat5a);
							magicmnal->runAction(magicrepeat6a);
							magicmnmaxal->runAction(magicrepeat7a);
						}
						//���E��
						if (job == HEALER) {
							hpcut = (valkyrie.atk - healer.def);
							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							healer.hp -= hpcut;
							PLhealer->setColor(ccc3(colormax, colordown, colordown));
							healerdmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
							this->addChild(healerdmf, onece);							//�_���[�W�������o��
							healerdmf->runAction(healerfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
							healerdmf->runAction(healerfdoutmov);						//�_���[�W��������ɓ�����
							healerhpal->setString(std::to_string(healer.hp));
							PLhealer->runAction(healerrepeat1a);
							healerHP->runAction(healerrepeat2a);
							healerMN->runAction(healerrepeat3a);
							healerhpal->runAction(healerrepeat4a);
							healerhpmaxal->runAction(healerrepeat5a);
							healermnal->runAction(healerrepeat6a);
							healermnmaxal->runAction(healerrepeat7a);
						}
					}
					//���p�t��I�񂾏ꍇ
					if (sskillchoice == MAGIC) {
						//���m
						if (job == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - attacker.def;	//���炷�_���[�W���v�Z
																					//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							attacker.hp -= hpcut;									//HP�����炷
							attackerdmf->setString(std::to_string(hpcut));			//�_���[�W��ω�������
							this->addChild(attackerdmf, onece);						//�_���[�W�������o��
							attackerdmf->runAction(attackerfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
							attackerdmf->runAction(attackerfdoutmov);				//�_���[�W��������ɓ�����
							attackerhpal->setString(std::to_string(attacker.hp));
							PLattacker->runAction(attacker_repeat_bigquake[0]);
							attackerHP->runAction(attacker_repeat_bigquake[1]);
							attackerMN->runAction(attacker_repeat_bigquake[2]);
							attackerhpal->runAction(attacker_repeat_bigquake[3]);
							attackerhpmaxal->runAction(attacker_repeat_bigquake[4]);
							attackermnal->runAction(attacker_repeat_bigquake[5]);
							attackermnmaxal->runAction(attacker_repeat_bigquake[6]);
						}
						//�R�m
						if (job == SHIELD) {
							hpcut = (valkyrie.atk - shield.def);
							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;
							PLshield->setColor(ccc3(colormax, colordown, colordown));
							shielddmf->setString(std::to_string(hpcut));			//�_���[�W��ω�������
							this->addChild(shielddmf, onece);						//�_���[�W�������o��
							shielddmf->runAction(shieldfadeout);					//�_���[�W�������t�F�[�h�A�E�g������
							shielddmf->runAction(shieldfdoutmov);					//�_���[�W��������ɓ�����
							shieldhpal->setString(std::to_string(shield.hp));
							PLshield->runAction(shieldrepeat1a);
							shieldHP->runAction(shieldrepeat2a);
							shieldMN->runAction(shieldrepeat3a);
							shieldhpal->runAction(shieldrepeat4a);
							shieldhpmaxal->runAction(shieldrepeat5a);
							shieldmnal->runAction(shieldrepeat6a);
							shieldmnmaxal->runAction(shieldrepeat7a);
						}
						//���p�t
						if (job == MAGIC) {
							//���p�t�̑���ɋR�m���_���[�W�����炤
							hpcut = (valkyrie.atk * skillupmedium) - shield.def;//���炷�_���[�W���v�Z
																				//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;									//HP�����炷
							shielddmf->setString(std::to_string(hpcut));		//�_���[�W��ω�������
							this->addChild(shielddmf, onece);					//�_���[�W�������o��
							shielddmf->runAction(shieldfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
							shielddmf->runAction(shieldfdoutmov);				//�_���[�W��������ɓ�����
							magichpal->setString(std::to_string(magic.hp));
							PLshield->runAction(shieldrepeat1a);
							shieldHP->runAction(shieldrepeat2a);
							shieldMN->runAction(shieldrepeat3a);
							shieldhpal->runAction(shieldrepeat4a);
							shieldhpmaxal->runAction(shieldrepeat5a);
							shieldmnal->runAction(shieldrepeat6a);
							shieldmnmaxal->runAction(shieldrepeat7a);

						}
						//���E��
						if (job == HEALER) {
							hpcut = (valkyrie.atk - healer.def);
							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							healer.hp -= hpcut;
							PLhealer->setColor(ccc3(colormax, colordown, colordown));
							healerdmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
							this->addChild(healerdmf, onece);							//�_���[�W�������o��
							healerdmf->runAction(healerfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
							healerdmf->runAction(healerfdoutmov);						//�_���[�W��������ɓ�����
							healerhpal->setString(std::to_string(healer.hp));
							PLhealer->runAction(healerrepeat1a);
							healerHP->runAction(healerrepeat2a);
							healerMN->runAction(healerrepeat3a);
							healerhpal->runAction(healerrepeat4a);
							healerhpmaxal->runAction(healerrepeat5a);
							healermnal->runAction(healerrepeat6a);
							healermnmaxal->runAction(healerrepeat7a);
						}
					}
					//���E�҂�I�񂾏ꍇ
					if (sskillchoice == HEALER) {
						//���m
						if (job == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - attacker.def;//���炷�_���[�W���v�Z
																				  //�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							attacker.hp -= hpcut;									//HP�����炷
							attackerdmf->setString(std::to_string(hpcut));			//�_���[�W��ω�������
							this->addChild(attackerdmf, onece);						//�_���[�W�������o��
							attackerdmf->runAction(attackerfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
							attackerdmf->runAction(attackerfdoutmov);				//�_���[�W��������ɓ�����
							attackerhpal->setString(std::to_string(attacker.hp));
							PLattacker->runAction(attacker_repeat_bigquake[0]);
							attackerHP->runAction(attacker_repeat_bigquake[1]);
							attackerMN->runAction(attacker_repeat_bigquake[2]);
							attackerhpal->runAction(attacker_repeat_bigquake[3]);
							attackerhpmaxal->runAction(attacker_repeat_bigquake[4]);
							attackermnal->runAction(attacker_repeat_bigquake[5]);
							attackermnmaxal->runAction(attacker_repeat_bigquake[6]);
						}
						//�R�m
						if (job == SHIELD) {
							hpcut = (valkyrie.atk - shield.def);
							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;
							PLshield->setColor(ccc3(colormax, colordown, colordown));
							shielddmf->setString(std::to_string(hpcut));			//�_���[�W��ω�������
							this->addChild(shielddmf, onece);						//�_���[�W�������o��
							shielddmf->runAction(shieldfadeout);					//�_���[�W�������t�F�[�h�A�E�g������
							shielddmf->runAction(shieldfdoutmov);					//�_���[�W��������ɓ�����
							shieldhpal->setString(std::to_string(shield.hp));
							PLshield->runAction(shieldrepeat1a);
							shieldHP->runAction(shieldrepeat2a);
							shieldMN->runAction(shieldrepeat3a);
							shieldhpal->runAction(shieldrepeat4a);
							shieldhpmaxal->runAction(shieldrepeat5a);
							shieldmnal->runAction(shieldrepeat6a);
							shieldmnmaxal->runAction(shieldrepeat7a);
						}
						//���p�t
						if (job == MAGIC) {
							hpcut = (valkyrie.atk - magic.def);
							//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							magic.hp -= hpcut;
							PLmagic->setColor(ccc3(colormax, colordown, colordown));
							magicdmf->setString(std::to_string(hpcut));				//�_���[�W��ω�������
							this->addChild(magicdmf, onece);						//�_���[�W�������o��
							magicdmf->runAction(magicfadeout);						//�_���[�W�������t�F�[�h�A�E�g������
							magicdmf->runAction(magicfdoutmov);						//�_���[�W��������ɓ�����
							magichpal->setString(std::to_string(magic.hp));
							PLmagic->runAction(magicrepeat1a);
							magicHP->runAction(magicrepeat2a);
							magicMN->runAction(magicrepeat3a);
							magichpal->runAction(magicrepeat4a);
							magichpmaxal->runAction(magicrepeat5a);
							magicmnal->runAction(magicrepeat6a);
							magicmnmaxal->runAction(magicrepeat7a);
						}
						//���E��
						if (job == HEALER) {
							//���E�҂̑���ɋR�m���_���[�W�����炤
							hpcut = (valkyrie.atk * skillupmedium) - shield.def;//���炷�_���[�W���v�Z
																				//�������炷HP��1�ȉ��̏ꍇ1�ɂ���
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;									//HP�����炷
							shielddmf->setString(std::to_string(hpcut));		//�_���[�W��ω�������
							this->addChild(shielddmf, onece);					//�_���[�W�������o��
							shielddmf->runAction(shieldfadeout);				//�_���[�W�������t�F�[�h�A�E�g������
							shielddmf->runAction(shieldfdoutmov);				//�_���[�W��������ɓ�����
							shieldhpal->setString(std::to_string(shield.hp));
							PLshield->runAction(shieldrepeat1a);
							shieldHP->runAction(shieldrepeat2a);
							shieldMN->runAction(shieldrepeat3a);
							shieldhpal->runAction(shieldrepeat4a);
							shieldhpmaxal->runAction(shieldrepeat5a);
							shieldmnal->runAction(shieldrepeat6a);
							shieldmnmaxal->runAction(shieldrepeat7a);
						}
					}
				}

				//�L�����̉摜�̐F��߂�
				PLattacker->setColor(ccc3(colormax, colormax, colormax));
				PLshield->setColor(ccc3(colormax, colormax, colormax));
				PLhealer->setColor(ccc3(colormax, colormax, colormax));
				PLmagic->setColor(ccc3(colormax, colormax, colormax));
			}
			//���ʏ���
			//�t���[����230(��)�ɂȂ�ƌ��ʂ�\�L
			if (gameflame == flame230) {
				auto Gskill2dec = CCLabelTTF::create("�_���[�W���󂯂�", "HGRSGU.TTC", fontsizeL);
				Gskill2dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill2dec, backdepth, bossskill2damageS);
			}
		}
		//�Z��̐w
		if (bskill == BSKILL3) {
			if (gameflame == flame80) {
				auto Gskill3 = CCLabelTTF::create("�u����ł����@���L���[�Ȃ̂Łv", "HGRSGU.TTC", fontsizeL);
				Gskill3->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill3, backdepth, bossskill3S);

				//���@���L���[�̖h��͂𑝂₷
				buffup = valkyrie.defmax;//�グ��h��͂��v�Z(���@���L�����|�̖h��́~0.5)
				valkyrie.def += buffup;				//���@���L���[�̖h��͂ɉ�����				

				//�X�L�����ʃ^�[���ɂ�鏈��
				if (bvskill3.buffturn1 == 0) {
					bvskill3.buffturn1 = 2;
					bvskill3.buffupefect1 = buffup;
				}
				else if (bvskill3.buffturn2 == 0) {
					bvskill3.buffturn2 = 2;
					bvskill3.buffupefect2 = buffup;
				}
			}
			//���ʏ���
			//�t���[����230(��)�ɂȂ�ƌ��ʂ�\�L
			if (gameflame == flame230) {
				auto Gskill3dec = CCLabelTTF::create("���@���L���[�̖h��͂��啝�ɏオ����", "HGRSGU.TTC", fontsizeM);
				Gskill3dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill3dec, backdepth, bossskill3damageS);
			}
		}
		//�G�X�e
		if (bskill == BSKILL4) {
			if (gameflame == flame80) {
				auto Gskill4 = CCLabelTTF::create("�u�G�X�e�c����c�v", "HGRSGU.TTC", fontsizeL);
				Gskill4->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill4, backdepth, bossskill4S);

				//���@���L���[��HP�𑝂₷
				bsskillrecovery = valkyrie.hp / tenpercent;
				valkyrie.hp += bsskillrecovery;
			}
			//���ʏ���
			//�t���[����230(��)�ɂȂ�ƌ��ʂ�\�L
			if (gameflame == flame230) {
				//�񕜕\�L
				String *Gskill4dec = String::createWithFormat("���@���L���[��%i�AHP���񕜂���", bsskillrecovery);
				string _Gskill4dec = Gskill4dec->getCString();
				auto bss4alabel = Label::createWithSystemFont(_Gskill4dec, "HGRSGU.TTC", fontsizeL);
				bss4alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(bss4alabel, backdepth, bossskill4damageS);
			}
		}
	}
}

//�摜��h�炷���߂̏���
void BossScene::Damage()
{
//���m
	//attackerframe.choisjob�����m�̏ꍇ
	if (pl1frame.choicejob == ATTACKER) {
	//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������m,1a
		auto attackermove1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		attacker_repeat_bigquake[0] = Repeat::create(attackermove1a, continuity1);
		//�h�炷�������m,2a
		auto attackermove2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		attacker_repeat_bigquake[1]= Repeat::create(attackermove2a, continuity1);
		//�h�炷�������m,3a
		auto attackermove3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		attacker_repeat_bigquake[2] = Repeat::create(attackermove3a, continuity1);
		//�h�炷�������m,4a
		auto attackermove4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_bigquake[3] = Repeat::create(attackermove4a, continuity1);
		//�h�炷�������m,5a
		auto attackermove5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_bigquake[4] = Repeat::create(attackermove5a, continuity1);
		//�h�炷�������m,6a
		auto attackermove6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_bigquake[5] = Repeat::create(attackermove6a, continuity1);
		//�h�炷�������m,7a
		auto attackermove7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_bigquake[6] = Repeat::create(attackermove7a, continuity1);
	//�h�ꕝ�����������
		//�h�炷�������m,1b
		auto attackermove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		attacker_repeat_smallquake[0] = Repeat::create(attackermove1b, continuity1);
		//�h�炷�������m,2b
		auto attackermove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		attacker_repeat_smallquake[1] = Repeat::create(attackermove2b, continuity1);
		//�h�炷�������m,3b
		auto attackermove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		attacker_repeat_smallquake[2] = Repeat::create(attackermove3b, continuity1);
		//�h�炷�������m,4b
		auto attackermove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_smallquake[3] = Repeat::create(attackermove4b, continuity1);
		//�h�炷�������m,5b
		auto attackermove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_smallquake[4] = Repeat::create(attackermove5b, continuity1);
		//�h�炷�������m,6b
		auto attackermove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_smallquake[5] = Repeat::create(attackermove6b, continuity1);
		//�h�炷�������m,7b
		auto attackermove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_smallquake[6] = Repeat::create(attackermove7b, continuity1);
	}
	//pl2frame.choisjob�����m�̏ꍇ
	if (pl2frame.choicejob == ATTACKER) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������m,1a
		auto attackermove1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		attacker_repeat_bigquake[0] = Repeat::create(attackermove1a, continuity1);
		//�h�炷�������m,2a
		auto attackermove2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		attacker_repeat_bigquake[1] = Repeat::create(attackermove2a, continuity1);
		//�h�炷�������m,3a
		auto attackermove3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		attacker_repeat_bigquake[2] = Repeat::create(attackermove3a, continuity1);
		//�h�炷�������m,4a
		auto attackermove4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_bigquake[3] = Repeat::create(attackermove4a, continuity1);
		//�h�炷�������m,5a
		auto attackermove5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_bigquake[4] = Repeat::create(attackermove5a, continuity1);
		//�h�炷�������m,6a
		auto attackermove6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_bigquake[5] = Repeat::create(attackermove6a, continuity1);
		//�h�炷�������m,7a
		auto attackermove7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_bigquake[6] = Repeat::create(attackermove7a, continuity1);
		//�h�ꕝ�����������
		//�h�炷�������m,1b
		auto attackermove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		attacker_repeat_smallquake[0] = Repeat::create(attackermove1b, continuity1);
		//�h�炷�������m,2b
		auto attackermove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		attacker_repeat_smallquake[1] = Repeat::create(attackermove2b, continuity1);
		//�h�炷�������m,3b
		auto attackermove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		attacker_repeat_smallquake[2] = Repeat::create(attackermove3b, continuity1);
		//�h�炷�������m,4b
		auto attackermove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_smallquake[3] = Repeat::create(attackermove4b, continuity1);
		//�h�炷�������m,5b
		auto attackermove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_smallquake[4] = Repeat::create(attackermove5b, continuity1);
		//�h�炷�������m,6b
		auto attackermove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_smallquake[5] = Repeat::create(attackermove6b, continuity1);
		//�h�炷�������m,7b
		auto attackermove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_smallquake[6] = Repeat::create(attackermove7b, continuity1);
	}
	//pl3frame.choisjob�����m�̏ꍇ
	if (pl3frame.choicejob == ATTACKER) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������m,1a
		auto attackermove1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		attacker_repeat_bigquake[0] = Repeat::create(attackermove1a, continuity1);
		//�h�炷�������m,2a
		auto attackermove2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		attacker_repeat_bigquake[1] = Repeat::create(attackermove2a, continuity1);
		//�h�炷�������m,3a
		auto attackermove3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		attacker_repeat_bigquake[2] = Repeat::create(attackermove3a, continuity1);
		//�h�炷�������m,4a
		auto attackermove4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_bigquake[3] = Repeat::create(attackermove4a, continuity1);
		//�h�炷�������m,5a
		auto attackermove5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_bigquake[4] = Repeat::create(attackermove5a, continuity1);
		//�h�炷�������m,6a
		auto attackermove6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_bigquake[5] = Repeat::create(attackermove6a, continuity1);
		//�h�炷�������m,7a
		auto attackermove7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_bigquake[6] = Repeat::create(attackermove7a, continuity1);
		//�h�ꂪ���������
		//�h�炷�������m,1b
		auto attackermove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		attacker_repeat_smallquake[0] = Repeat::create(attackermove1b, continuity1);
		//�h�炷�������m,2b
		auto attackermove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		attacker_repeat_smallquake[1] = Repeat::create(attackermove2b, continuity1);
		//�h�炷�������m,3b
		auto attackermove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		attacker_repeat_smallquake[2] = Repeat::create(attackermove3b, continuity1);
		//�h�炷�������m,4b
		auto attackermove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_smallquake[3] = Repeat::create(attackermove4b, continuity1);
		//�h�炷�������m,5b
		auto attackermove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_smallquake[4] = Repeat::create(attackermove5b, continuity1);
		//�h�炷�������m,6b
		auto attackermove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_smallquake[5] = Repeat::create(attackermove6b, continuity1);
		//�h�炷�������m,7b
		auto attackermove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_smallquake[6] = Repeat::create(attackermove7b, continuity1);
	}
//�R�m
	//shieldframe.choisjob���R�m�̏ꍇ
	if (pl1frame.choicejob == SHIELD) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�����R�m,1a
		auto shieldmove1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		shield_repeat_smallquake[0] = Repeat::create(shieldmove1a, continuity1);
		//�h�炷�����R�m,2a
		auto shieldmove2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		shield_repeat_smallquake[1] = Repeat::create(shieldmove2a, continuity1);
		//�h�炷�����R�m,3a
		auto shieldmove3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		shield_repeat_smallquake[2] = Repeat::create(shieldmove3a, continuity1);
		//�h�炷�����R�m,4a
		auto shieldmove4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		shield_repeat_smallquake[3] = Repeat::create(shieldmove4a, continuity1);
		//�h�炷�����R�m,5a
		auto shieldmove5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		shield_repeat_smallquake[4] = Repeat::create(shieldmove5a, continuity1);
		//�h�炷�����R�m,6a
		auto shieldmove6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		shield_repeat_smallquake[5] = Repeat::create(shieldmove6a, continuity1);
		//�h�炷�����R�m,7a
		auto shieldmove7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		shield_repeat_smallquake[6] = Repeat::create(shieldmove7a, continuity1);
		//�h�ꕝ�����������
		//�h�炷�����R�m,1b
		auto shieldmove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		shieldrepeat1b = Repeat::create(shieldmove1b, continuity1);
		//�h�炷�����R�m,2b
		auto shieldmove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		shieldrepeat2b = Repeat::create(shieldmove2b, continuity1);
		//�h�炷�����R�m,3b
		auto shieldmove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		shieldrepeat3b = Repeat::create(shieldmove3b, continuity1);
		//�h�炷�����R�m,4b
		auto shieldmove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		shieldrepeat4b = Repeat::create(shieldmove4b, continuity1);
		//�h�炷�����R�m,5b
		auto shieldmove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		shieldrepeat5b = Repeat::create(shieldmove5b, continuity1);
		//�h�炷�����R�m,6b
		auto shieldmove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		shieldrepeat6b = Repeat::create(shieldmove6b, continuity1);
		//�h�炷�����R�m,7b
		auto shieldmove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		shieldrepeat7b = Repeat::create(shieldmove7b, continuity1);
	}
	//pl2frame.choisjob���R�m�̏ꍇ
	if (pl2frame.choicejob == SHIELD) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�����R�m,1a
		auto shieldmove1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		shield_repeat_smallquake[0] = Repeat::create(shieldmove1a, continuity1);
		//�h�炷�����R�m,2a
		auto shieldmove2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		shield_repeat_smallquake[1] = Repeat::create(shieldmove2a, continuity1);
		//�h�炷�����R�m,3a
		auto shieldmove3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		shield_repeat_smallquake[2] = Repeat::create(shieldmove3a, continuity1);
		//�h�炷�����R�m,4a
		auto shieldmove4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		shield_repeat_smallquake[3] = Repeat::create(shieldmove4a, continuity1);
		//�h�炷�����R�m,5a
		auto shieldmove5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		shield_repeat_smallquake[4] = Repeat::create(shieldmove5a, continuity1);
		//�h�炷�����R�m,6a
		auto shieldmove6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		shield_repeat_smallquake[5] = Repeat::create(shieldmove6a, continuity1);
		//�h�炷�����R�m,7a
		auto shieldmove7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		shield_repeat_smallquake[6] = Repeat::create(shieldmove7a, continuity1);
		//�h�ꕝ�����������
		//�h�炷�����R�m,1b
		auto shieldmove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		shieldrepeat1b = Repeat::create(shieldmove1b, continuity1);
		//�h�炷�����R�m,2b
		auto shieldmove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		shieldrepeat2b = Repeat::create(shieldmove2b, continuity1);
		//�h�炷�����R�m,3b
		auto shieldmove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		shieldrepeat3b = Repeat::create(shieldmove3b, continuity1);
		//�h�炷�����R�m,4b
		auto shieldmove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		shieldrepeat4b = Repeat::create(shieldmove4b, continuity1);
		//�h�炷�����R�m,5b
		auto shieldmove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		shieldrepeat5b = Repeat::create(shieldmove5b, continuity1);
		//�h�炷�����R�m,6b
		auto shieldmove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		shieldrepeat6b = Repeat::create(shieldmove6b, continuity1);
		//�h�炷�����R�m,7b
		auto shieldmove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		shieldrepeat7b = Repeat::create(shieldmove7b, continuity1);
	}
	//pl3frame.choisjob���R�m�̏ꍇ
	if (pl3frame.choicejob == SHIELD) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�����R�m,1a
		auto shieldmove1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		shield_repeat_smallquake[0] = Repeat::create(shieldmove1a, continuity1);
		//�h�炷�����R�m,2a
		auto shieldmove2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		shield_repeat_smallquake[1] = Repeat::create(shieldmove2a, continuity1);
		//�h�炷�����R�m,3a
		auto shieldmove3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		shield_repeat_smallquake[2] = Repeat::create(shieldmove3a, continuity1);
		//�h�炷�����R�m,4a
		auto shieldmove4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		shield_repeat_smallquake[3] = Repeat::create(shieldmove4a, continuity1);
		//�h�炷�����R�m,5a
		auto shieldmove5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		shield_repeat_smallquake[4] = Repeat::create(shieldmove5a, continuity1);
		//�h�炷�����R�m,6a
		auto shieldmove6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		shield_repeat_smallquake[5] = Repeat::create(shieldmove6a, continuity1);
		//�h�炷�����R�m,7a
		auto shieldmove7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		shield_repeat_smallquake[6] = Repeat::create(shieldmove7a, continuity1);
		//�h�ꂪ���������
		//�h�炷�����R�m,1b
		auto shieldmove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		shieldrepeat1b = Repeat::create(shieldmove1b, continuity1);
		//�h�炷�����R�m,2b
		auto shieldmove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		shieldrepeat2b = Repeat::create(shieldmove2b, continuity1);
		//�h�炷�����R�m,3b
		auto shieldmove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		shieldrepeat3b = Repeat::create(shieldmove3b, continuity1);
		//�h�炷�����R�m,4b
		auto shieldmove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		shieldrepeat4b = Repeat::create(shieldmove4b, continuity1);
		//�h�炷�����R�m,5b
		auto shieldmove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		shieldrepeat5b = Repeat::create(shieldmove5b, continuity1);
		//�h�炷�����R�m,6b
		auto shieldmove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		shieldrepeat6b = Repeat::create(shieldmove6b, continuity1);
		//�h�炷�����R�m,7b
		auto shieldmove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		shieldrepeat7b = Repeat::create(shieldmove7b, continuity1);
	}
//���p�t
	//pl1frame.choisjob�����p�t�̏ꍇ
	if (pl1frame.choicejob == MAGIC) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������p�t,1a
		auto magicmove1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		magicrepeat1a = Repeat::create(magicmove1a, continuity1);
		//�h�炷�������p�t,2a
		auto magicmove2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		magicrepeat2a = Repeat::create(magicmove2a, continuity1);
		//�h�炷�������p�t,3a
		auto magicmove3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		magicrepeat3a = Repeat::create(magicmove3a, continuity1);
		//�h�炷�������p�t,4a
		auto magicmove4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat4a = Repeat::create(magicmove4a, continuity1);
		//�h�炷�������p�t,5a
		auto magicmove5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat5a = Repeat::create(magicmove5a, continuity1);
		//�h�炷�������p�t,6a
		auto magicmove6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat6a = Repeat::create(magicmove6a, continuity1);
		//�h�炷�������p�t,7a
		auto magicmove7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat7a = Repeat::create(magicmove7a, continuity1);
		//�h�ꕝ�����������
		//�h�炷�������p�t,1b
		auto magicmove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		magicrepeat1b = Repeat::create(magicmove1b, continuity1);
		//�h�炷�������p�t,2b
		auto magicmove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		magicrepeat2b = Repeat::create(magicmove2b, continuity1);
		//�h�炷�������p�t,3b
		auto magicmove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		magicrepeat3b = Repeat::create(magicmove3b, continuity1);
		//�h�炷�������p�t,4b
		auto magicmove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat4b = Repeat::create(magicmove4b, continuity1);
		//�h�炷�������p�t,5b
		auto magicmove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat5b = Repeat::create(magicmove5b, continuity1);
		//�h�炷�������p�t,6b
		auto magicmove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat6b = Repeat::create(magicmove6b, continuity1);
		//�h�炷�������p�t,7b
		auto magicmove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat7b = Repeat::create(magicmove7b, continuity1);
	}
	//pl2frame.choisjob�����p�t�̏ꍇ
	if (pl2frame.choicejob == MAGIC) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������p�t,1a
		auto magicmove1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		magicrepeat1a = Repeat::create(magicmove1a, continuity1);
		//�h�炷�������p�t,2a
		auto magicmove2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		magicrepeat2a = Repeat::create(magicmove2a, continuity1);
		//�h�炷�������p�t,3a
		auto magicmove3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		magicrepeat3a = Repeat::create(magicmove3a, continuity1);
		//�h�炷�������p�t,4a
		auto magicmove4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat4a = Repeat::create(magicmove4a, continuity1);
		//�h�炷�������p�t,5a
		auto magicmove5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat5a = Repeat::create(magicmove5a, continuity1);
		//�h�炷�������p�t,6a
		auto magicmove6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat6a = Repeat::create(magicmove6a, continuity1);
		//�h�炷�������p�t,7a
		auto magicmove7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat7a = Repeat::create(magicmove7a, continuity1);
		//�h�ꕝ�����������
		//�h�炷�������p�t,1b
		auto magicmove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		magicrepeat1b = Repeat::create(magicmove1b, continuity1);
		//�h�炷�������p�t,2b
		auto magicmove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		magicrepeat2b = Repeat::create(magicmove2b, continuity1);
		//�h�炷�������p�t,3b
		auto magicmove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		magicrepeat3b = Repeat::create(magicmove3b, continuity1);
		//�h�炷�������p�t,4b
		auto magicmove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat4b = Repeat::create(magicmove4b, continuity1);
		//�h�炷�������p�t,5b
		auto magicmove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat5b = Repeat::create(magicmove5b, continuity1);
		//�h�炷�������p�t,6b
		auto magicmove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat6b = Repeat::create(magicmove6b, continuity1);
		//�h�炷�������p�t,7b
		auto magicmove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat7b = Repeat::create(magicmove7b, continuity1);
	}
	//magicframe.choisjob�����p�t�̏ꍇ
	if (pl3frame.choicejob == MAGIC) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������p�t,1a
		auto magicmove1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		magicrepeat1a = Repeat::create(magicmove1a, continuity1);
		//�h�炷�������p�t,2a
		auto magicmove2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		magicrepeat2a = Repeat::create(magicmove2a, continuity1);
		//�h�炷�������p�t,3a
		auto magicmove3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		magicrepeat3a = Repeat::create(magicmove3a, continuity1);
		//�h�炷�������p�t,4a
		auto magicmove4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat4a = Repeat::create(magicmove4a, continuity1);
		//�h�炷�������p�t,5a
		auto magicmove5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat5a = Repeat::create(magicmove5a, continuity1);
		//�h�炷�������p�t,6a
		auto magicmove6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat6a = Repeat::create(magicmove6a, continuity1);
		//�h�炷�������p�t,7a
		auto magicmove7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat7a = Repeat::create(magicmove7a, continuity1);
		//�h�ꂪ���������
		//�h�炷�������p�t,1b
		auto magicmove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		magicrepeat1b = Repeat::create(magicmove1b, continuity1);
		//�h�炷�������p�t,2b
		auto magicmove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		magicrepeat2b = Repeat::create(magicmove2b, continuity1);
		//�h�炷�������p�t,3b
		auto magicmove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		magicrepeat3b = Repeat::create(magicmove3b, continuity1);
		//�h�炷�������p�t,4b
		auto magicmove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat4b = Repeat::create(magicmove4b, continuity1);
		//�h�炷�������p�t,5b
		auto magicmove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat5b = Repeat::create(magicmove5b, continuity1);
		//�h�炷�������p�t,6b
		auto magicmove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat6b = Repeat::create(magicmove6b, continuity1);
		//�h�炷�������p�t,7b
		auto magicmove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat7b = Repeat::create(magicmove7b, continuity1);
	}
//���E��
	//healerframe.choisjob�����E�҂̏ꍇ
	if (pl1frame.choicejob == HEALER) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������E��,1a
		auto healermove1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		healerrepeat1a = Repeat::create(healermove1a, continuity1);
		//�h�炷�������E��,2a
		auto healermove2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		healerrepeat2a = Repeat::create(healermove2a, continuity1);
		//�h�炷�������E��,3a
		auto healermove3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		healerrepeat3a = Repeat::create(healermove3a, continuity1);
		//�h�炷�������E��,4a
		auto healermove4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat4a = Repeat::create(healermove4a, continuity1);
		//�h�炷�������E��,5a
		auto healermove5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat5a = Repeat::create(healermove5a, continuity1);
		//�h�炷�������E��,6a
		auto healermove6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat6a = Repeat::create(healermove6a, continuity1);
		//�h�炷�������E��,7a
		auto healermove7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat7a = Repeat::create(healermove7a, continuity1);
		//�h�ꕝ�����������
		//�h�炷�������E��,1b
		auto healermove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		healerrepeat1b = Repeat::create(healermove1b, continuity1);
		//�h�炷�������E��,2b
		auto healermove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		healerrepeat2b = Repeat::create(healermove2b, continuity1);
		//�h�炷�������E��,3b
		auto healermove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		healerrepeat3b = Repeat::create(healermove3b, continuity1);
		//�h�炷�������E��,4b
		auto healermove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat4b = Repeat::create(healermove4b, continuity1);
		//�h�炷�������E��,5b
		auto healermove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat5b = Repeat::create(healermove5b, continuity1);
		//�h�炷�������E��,6b
		auto healermove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat6b = Repeat::create(healermove6b, continuity1);
		//�h�炷�������E��,7b
		auto healermove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat7b = Repeat::create(healermove7b, continuity1);
	}
	//healerframe.choisjob�����E�҂̏ꍇ
	if (pl2frame.choicejob == HEALER) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������E��,1a
		auto healermove1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		healerrepeat1a = Repeat::create(healermove1a, continuity1);
		//�h�炷�������E��,2a
		auto healermove2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		healerrepeat2a = Repeat::create(healermove2a, continuity1);
		//�h�炷�������E��,3a
		auto healermove3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		healerrepeat3a = Repeat::create(healermove3a, continuity1);
		//�h�炷�������E��,4a
		auto healermove4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat4a = Repeat::create(healermove4a, continuity1);
		//�h�炷�������E��,5a
		auto healermove5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat5a = Repeat::create(healermove5a, continuity1);
		//�h�炷�������E��,6a
		auto healermove6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat6a = Repeat::create(healermove6a, continuity1);
		//�h�炷�������E��,7a
		auto healermove7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat7a = Repeat::create(healermove7a, continuity1);
		//�h�ꕝ�����������
		//�h�炷�������E��,1b
		auto healermove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		healerrepeat1b = Repeat::create(healermove1b, continuity1);
		//�h�炷�������E��,2b
		auto healermove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		healerrepeat2b = Repeat::create(healermove2b, continuity1);
		//�h�炷�������E��,3b
		auto healermove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		healerrepeat3b = Repeat::create(healermove3b, continuity1);
		//�h�炷�������E��,4b
		auto healermove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat4b = Repeat::create(healermove4b, continuity1);
		//�h�炷�������E��,5b
		auto healermove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat5b = Repeat::create(healermove5b, continuity1);
		//�h�炷�������E��,6b
		auto healermove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat6b = Repeat::create(healermove6b, continuity1);
		//�h�炷�������E��,7b
		auto healermove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat7b = Repeat::create(healermove7b, continuity1);
	}
	//pl3frame.choisjob�����E�҂̏ꍇ
	if (pl3frame.choicejob == HEALER) {
		//�h�ꕝ����r�I�ɑ傫�����
		//�h�炷�������E��,1a
		auto healermove1a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		healerrepeat1a = Repeat::create(healermove1a, continuity1);
		//�h�炷�������E��,2a
		auto healermove2a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		healerrepeat2a = Repeat::create(healermove2a, continuity1);
		//�h�炷�������E��,3a
		auto healermove3a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		healerrepeat3a = Repeat::create(healermove3a, continuity1);
		//�h�炷�������E��,4a
		auto healermove4a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat4a = Repeat::create(healermove4a, continuity1);
		//�h�炷�������E��,5a
		auto healermove5a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat5a = Repeat::create(healermove5a, continuity1);
		//�h�炷�������E��,6a
		auto healermove6a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat6a = Repeat::create(healermove6a, continuity1);
		//�h�炷�������E��,7a
		auto healermove7a = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 10)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 15)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f - 20)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + moverange)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat7a = Repeat::create(healermove7a, continuity1);
		//�h�ꂪ���������
		//�h�炷�������E��,1b
		auto healermove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		healerrepeat1b = Repeat::create(healermove1b, continuity1);
		//�h�炷�������E��,2b
		auto healermove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		healerrepeat2b = Repeat::create(healermove2b, continuity1);
		//�h�炷�������E��,3b
		auto healermove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		healerrepeat3b = Repeat::create(healermove3b, continuity1);
		//�h�炷�������E��,4b
		auto healermove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat4b = Repeat::create(healermove4b, continuity1);
		//�h�炷�������E��,5b
		auto healermove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat5b = Repeat::create(healermove5b, continuity1);
		//�h�炷�������E��,6b
		auto healermove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat6b = Repeat::create(healermove6b, continuity1);
		//�h�炷�������E��,7b
		auto healermove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat7b = Repeat::create(healermove7b, continuity1);
	}
//�{�X
	auto bossmove = CCSequence::create(
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2 + 2, rightSize.height / 1.7f)),
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2 - 2, rightSize.height / 1.7f)),
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2 + 2, rightSize.height / 1.7f)),
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2 - 2, rightSize.height / 1.7f)),
		CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f)),
		NULL
	);
	bossrepeat = Repeat::create(bossmove, continuity1);
}

//�X�L���^�[������
void BossScene::Skillturn()
{
	switch (bufft)
	{
//���m�@askill2(���@���L�����|�̖h���������)
	case BossScene::ASKILL2T: {
		//1�^�[���ڂ͉������Ȃ�
		if (battleturn == 1) {
			allworkendflag = true;
		}

		//�d�ˊ|���̏ꍇ�����邩�瑝�₵�Ă���
		//���m�@askill2�̌��ʃ^�[������1
		if (askill2.buffendflag1 == false) {
			if (askill2.buffturn1 > 1) {
				askill2.buffturn1 -= 1;
				askill2.buffendflag1 = true;	//�X�L���^�[��������Ȃ�^�[����1�����ďI��
			}
			else if (askill2.buffturn1 == 0) {
				askill2.buffendflag1 = true;	//�X�L���^�[�����Ȃ��Ȃ炻�̂܂܏I��
			}
		}
		//���m�@askill2�̌��ʃ^�[������2
		if (askill2.buffendflag2 == false) {
			if (askill2.buffturn2 > 1) {
				askill2.buffturn2 -= 1;
				askill2.buffendflag2 = true;
			}
			else if (askill2.buffturn2 == 0) {
				askill2.buffendflag2 = true;
			}
		}
		//���ʃ^�[����0�ɂȂ�����X�e�[�^�X��߂�
		//����1
		if (askill2.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.def += askill2.buffdownefect1;		//����������������
				askill2.buffdownefect1 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����2
		if (askill2.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.def += askill2.buffdownefect2;		//����������������
				askill2.buffdownefect2 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}

		//������
		auto askill2buffend = CCLabelTTF::create("���@���L�����[�̖h��͂��߂���", "HGRSGU.TTC", fontsizeL);
		askill2buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//�\�L���ďI��
		if (battleturn > 1) {
			if (askill2.buffendflag1 == false) {
				if (askill2.buffturn1 == 1) {
					if (gameflame == flame80) {
						this->addChild(askill2buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						askill2.buffturn1 = 0;				//����������
						askill2.buffendflag1 = true;		//�I�����
					}
				}
			}
			if (askill2.buffturn2 == 1) {
				if (askill2.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(askill2buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						askill2.buffturn2 = 0;				//����������
						askill2.buffendflag2 = true;		//�I�����
					}
				}
			}
		}
		//���m�̃X�L��2�̏������S���I��������I���
		if (askill2.buffendflag1 == true && askill2.buffendflag2 == true) {
			bufft = ASKILL4T;
			this->removeChildByTag(buffendS);			//�\�L������
			askill2allworkendflag = true;				//�X�L���V�̏����͑S���I�����
			askill2.buffendflag1 = false;				//������
			askill2.buffendflag2 = false;				//������
			gameflame = 0;								//���Ԃ�0��
		}
		break;
	}
//���m�@askill4(���@���L�����|�̍U����������)
	case BossScene::ASKILL4T: {
		//�d�ˊ|���̏ꍇ�����邩�瑝�₵�Ă���
		//���m�@askill4�̌��ʃ^�[������1
		if (askill4.buffendflag1 == false) {
			if (askill4.buffturn1 > 1) {
				askill4.buffturn1 -= 1;
				askill4.buffendflag1 = true;	//�X�L���^�[��������Ȃ�^�[����1�����ďI��
			}
			else if (askill4.buffturn1 == 0) {
				askill4.buffendflag1 = true;	//�X�L���^�[�����Ȃ��Ȃ炻�̂܂܏I��
			}
		}
		//���m�@askill4�̌��ʃ^�[������2
		if (askill4.buffendflag2 == false) {
			if (askill4.buffturn2 > 1) {
				askill4.buffturn2 -= 1;
				askill4.buffendflag2 = true;
			}
			else if (askill4.buffturn2 == 0) {
				askill4.buffendflag2 = true;
			}
		}
		//���ʃ^�[����0�ɂȂ�����X�e�[�^�X��߂�
		//����1
		if (askill4.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.atk += askill4.buffdownefect1;		//����������������
				askill4.buffdownefect1 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����2
		if (askill4.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.atk += askill4.buffdownefect2;		//����������������
				askill4.buffdownefect2 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}

		//������
		auto askill4buffend = CCLabelTTF::create("���@���L�����[�̍U���͂��߂���", "HGRSGU.TTC", fontsizeL);
		askill4buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//�\�L���ďI��
		if (battleturn > 1) {
			if (askill4.buffturn1 == 1) {
				if (askill4.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(askill4buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						askill4.buffturn1 = 0;				//����������
						askill4.buffendflag1 = true;		//�I�����
					}
				}
			}
			if (askill4.buffturn2 == 1) {
				if (askill4.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(askill4buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						askill4.buffturn2 = 0;				//����������
						askill4.buffendflag2 = true;		//�I�����
					}
				}
			}
		}
		//���m�̃X�L��2�̏������S���I��������I���
		if (askill4.buffendflag1 == true && askill4.buffendflag2 == true) {
			bufft = ASKILL7T;
			this->removeChildByTag(buffendS);			//�\�L������
			askill4allworkendflag = true;				//�X�L���V�̏����͑S���I�����
			askill4.buffendflag1 = false;				//������
			askill4.buffendflag2 = false;				//������
			gameflame = 0;								//���Ԃ�0��
		}
		break;
	}
//���m�@ASKILL7(���m�̍U���͏��A�b�v)
	case BossScene::ASKILL7T: {
		//�d�ˊ|���̏ꍇ�����邩�瑝�₵�Ă���
		//���m�@ASKILL7�̌��ʃ^�[������1
		if (askill7.buffendflag1 == false) {
			if (askill7.buffturn1 > 1) {
				askill7.buffturn1 -= 1;
				askill7.buffendflag1 = true;	//�X�L���^�[��������Ȃ�^�[����1�����ďI��
			}
			else if (askill7.buffturn1 == 0) {
				askill7.buffendflag1 = true;	//�X�L���^�[�����Ȃ��Ȃ炻�̂܂܏I��
			}
		}
		//���m�@ASKILL7�̌��ʃ^�[������2
		if (askill7.buffendflag2 == false) {
			if (askill7.buffturn2 > 1) {
				askill7.buffturn2 -= 1;
				askill7.buffendflag2 = true;
			}
			else if (askill7.buffturn2 == 0) {
				askill7.buffendflag2 = true;
			}
		}
		//���m�@ASKILL7�̌��ʃ^�[������3
		if (askill7.buffendflag3 == false) {
			if (askill7.buffturn3 > 1) {
				askill7.buffturn3 -= 1;
				askill7.buffendflag3 = true;
			}
			else if (askill7.buffturn3 == 0) {
				askill7.buffendflag3 = true;
			}
		}
		//���m�@ASKILL7�̌��ʃ^�[������4
		if (askill7.buffendflag4 == false) {
			if (askill7.buffturn4 > 1) {
				askill7.buffturn4 -= 1;
				askill7.buffendflag4 = true;
			}
			else if (askill7.buffturn4 == 0) {
				askill7.buffendflag4 = true;
			}
		}
		//���ʃ^�[����0�ɂȂ�����X�e�[�^�X��߂�
		//����1
		if (askill7.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= askill7.buffupefect1;		//�グ������������
				askill7.buffupefect1 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����2
		if (askill7.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= askill7.buffupefect2;		//�グ������������
				askill7.buffupefect2 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����3
		if (askill7.buffturn3 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= askill7.buffupefect3;		//�グ������������
				askill7.buffupefect3 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����4
		if (askill7.buffturn4 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= askill7.buffupefect4;		//�グ������������
				askill7.buffupefect4 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}

		//������
		auto askill7buffend = CCLabelTTF::create("���m�̍U���͂��߂���", "HGRSGU.TTC", fontsizeL);
		askill7buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//�\�L���ďI��
		if (battleturn > 1) {
			if (askill7.buffturn1 == 1) {
				if (askill7.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(askill7buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						askill7.buffturn1 = 0;				//����������
						askill7.buffendflag1 = true;		//�I�����
					}
				}
			}
			if (askill7.buffturn2 == 1) {
				if (askill7.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(askill7buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						askill7.buffturn2 = 0;				//����������
						askill7.buffendflag2 = true;		//�I�����
					}
				}
			}
			if (askill7.buffturn3 == 1) {
				if (askill7.buffendflag3 == false) {
					if (gameflame == flame80) {
						this->addChild(askill7buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						askill7.buffturn3 = 0;				//����������
						askill7.buffendflag3 = true;		//�I�����
					}
				}
			}
			if (askill7.buffturn4 == 1) {
				if (askill7.buffendflag4 == false) {
					if (gameflame == flame80) {
						this->addChild(askill7buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						askill7.buffturn4 = 0;				//����������
						askill7.buffendflag4 = true;		//�I�����
					}
				}
			}
		}
		//���m�̃X�L��7�̏������S���I��������I���
		if (askill7.buffendflag1 == true && askill7.buffendflag2 == true
			&& askill7.buffendflag3 == true && askill7.buffendflag4 == true) {
			bufft = ASKILL8T;
			this->removeChildByTag(buffendS);			//�\�L������
			askill7allworkendflag = true;				//�X�L���V�̏����͑S���I�����
			askill7.buffendflag1 = false;				//������
			askill7.buffendflag2 = false;				//������
			askill7.buffendflag3 = false;				//������
			askill7.buffendflag4 = false;				//������
			gameflame = 0;								//���Ԃ�0��
		}
		break;
	}
//���m�@askill8(���m�̍U���̓_�C�A�b�v,�h��͏��_�E��)
	case BossScene::ASKILL8T: {
		//�d�ˊ|���̏ꍇ�����邩�瑝�₵�Ă���
		//���m�@askill8�̌��ʃ^�[������1
		if (askill8.buffendflag1 == false) {
			if (askill8.buffturn1 > 1) {
				askill8.buffturn1 -= 1;
				askill8.buffendflag1 = true;	//�X�L���^�[��������Ȃ�^�[����1�����ďI��
			}
			else if (askill8.buffturn1 == 0) {
				askill8.buffendflag1 = true;	//�X�L���^�[�����Ȃ��Ȃ炻�̂܂܏I��
			}
		}
		//���m�@askill8�̌��ʃ^�[������2
		if (askill8.buffendflag2 == false) {
			if (askill8.buffturn2 > 1) {
				askill8.buffturn2 -= 1;
				askill8.buffendflag2 = true;
			}
			else if (askill8.buffturn2 == 0) {
				askill8.buffendflag2 = true;
			}
		}
		//���m�@askill8�̌��ʃ^�[������3
		if (askill8.buffendflag3 == false) {
			if (askill8.buffturn3 > 1) {
				askill8.buffturn3 -= 1;
				askill8.buffendflag3 = true;
			}
			else if (askill8.buffturn3 == 0) {
				askill8.buffendflag3 = true;
			}
		}
		//���m�@askill8�̌��ʃ^�[������4
		if (askill8.buffendflag4 == false) {
			if (askill8.buffturn4 > 1) {
				askill8.buffturn4 -= 1;
				askill8.buffendflag4 = true;
			}
			else if (askill8.buffturn4 == 0) {
				askill8.buffendflag4 = true;
			}
		}
		//���ʃ^�[����0�ɂȂ�����X�e�[�^�X��߂�
		//����1
		if (askill8.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= askill8.buffupefect1;		//�グ������������
				attacker.def += askill8.buffdownefect1;		//����������������
				askill8.buffupefect1 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
				askill8.buffdownefect1 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����2
		if (askill8.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= askill8.buffupefect2;		//�グ������������
				attacker.def += askill8.buffdownefect2;		//����������������
				askill8.buffupefect2 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
				askill8.buffdownefect2 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����3
		if (askill8.buffturn3 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= askill8.buffupefect3;		//�グ������������
				attacker.def += askill8.buffdownefect3;		//����������������
				askill8.buffupefect3 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
				askill8.buffdownefect3 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����4
		if (askill8.buffturn4 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= askill8.buffupefect4;		//�グ������������
				attacker.def += askill8.buffdownefect4;		//����������������
				askill8.buffupefect4 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
				askill8.buffdownefect4 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}

		//������
		auto askill8buffend = CCLabelTTF::create("���m�̍U���͂��߂���", "HGRSGU.TTC", fontsizeL);
		askill8buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		auto askill8buffend2 = CCLabelTTF::create("���m�̖h��͂��߂���", "HGRSGU.TTC", fontsizeL);
		askill8buffend2->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//�\�L���ďI��
		if (battleturn > 1) {
			if (askill8.buffturn1 == 1) {
				if (askill8.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(askill8buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//�\�L������
						this->addChild(askill8buffend2, backdepth, buffend2S);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame220) {
						askill8.buffturn1 = 0;				//����������
						askill8.buffendflag1 = true;		//�I�����
					}
				}
			}
			if (askill8.buffturn2 == 1) {
				if (askill8.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(askill8buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//�\�L������
						this->addChild(askill8buffend2, backdepth, buffend2S);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame220) {
						askill8.buffturn2 = 0;				//����������
						askill8.buffendflag2 = true;		//�I�����
					}
				}
			}
			if (askill8.buffturn3 == 1) {
				if (askill8.buffendflag3 == false) {
					if (gameflame == flame80) {
						this->addChild(askill8buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//�\�L������
						this->addChild(askill8buffend2, backdepth, buffend2S);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame220) {
						askill8.buffturn3 = 0;				//����������
						askill8.buffendflag3 = true;		//�I�����
					}
				}
			}
			if (askill8.buffturn4 == 1) {
				if (askill8.buffendflag4 == false) {
					if (gameflame == flame80) {
						this->addChild(askill8buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//�\�L������
						this->addChild(askill8buffend2, backdepth, buffend2S);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame220) {
						askill8.buffturn4 = 0;				//����������
						askill8.buffendflag4 = true;		//�I�����
					}
				}
			}
		}
		//���m�̃X�L��8�̏������S���I��������I���
		if (askill8.buffendflag1 == true && askill8.buffendflag2 == true
			&& askill8.buffendflag3 == true && askill8.buffendflag4 == true) {
			bufft = SSKILL2T;
			this->removeChildByTag(buffend2S);			//�\�L������
			askill8allworkendflag = true;				//�X�L���V�̏����͑S���I�����
			askill8.buffendflag1 = false;				//������
			askill8.buffendflag2 = false;				//������
			askill8.buffendflag3 = false;				//������
			askill8.buffendflag4 = false;				//������
			gameflame = 0;								//���Ԃ�0��
		}
		break;
	}
//�R�m�@sskill5(�S���̑���Ƀ_���[�W���󂯂�)
	case BossScene::SSKILL2T: {
		bufft = SSKILL3T;
		break;
	}
//�R�m�@sskill3(�R�m�Ƀ^�Q�W��)
	case BossScene::SSKILL3T: {
		//�d�ˊ|���̏ꍇ�����邩�瑝�₵�Ă���
		//�R�m�@sskill3�̌��ʃ^�[������1
		if (sskill3.buffendflag1 == false) {
			if (sskill3.buffturn1 > 1) {
				sskill3.buffturn1 -= 1;
				sskill3.buffendflag1 = true;	//�X�L���^�[��������Ȃ�^�[����1�����ďI��
			}
			else if (sskill3.buffturn1 == 0) {
				sskill3.buffendflag1 = true;	//�X�L���^�[�����Ȃ��Ȃ炻�̂܂܏I��
			}
		}
		//�R�m�@sskill3�̌��ʃ^�[������2
		if (sskill3.buffendflag2 == false) {
			if (sskill3.buffturn2 > 1) {
				sskill3.buffturn2 -= 1;
				sskill3.buffendflag2 = true;
			}
			else if (sskill3.buffturn2 == 0) {
				sskill3.buffendflag2 = true;
			}
		}
		
		//���ʃ^�[����0�ɂȂ�����X�e�[�^�X��߂�
		//����1
		if (sskill3.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				coverflag1 = false;		//�^�Q�W��1����
			}
		}
		//����2
		if (sskill3.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				coverflag2 = false;		//�^�Q�W��2����
			}
		}

		//������
		auto sskill3buffend = CCLabelTTF::create("�R�m�̃^�Q�W�������߂���", "HGRSGU.TTC", fontsizeL);
		sskill3buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//�\�L���ďI��
		if (battleturn > 1) {
			if (sskill3.buffturn1 == 1) {
				if (sskill3.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill3buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						sskill3.buffturn1 = 0;				//����������
						sskill3.buffendflag1 = true;		//�I�����
					}
				}
			}
			if (sskill3.buffturn2 == 1) {
				if (sskill3.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill3buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						sskill3.buffturn2 = 0;				//����������
						sskill3.buffendflag2 = true;		//�I�����
					}
				}
			}
		}
		//�R�m�̃X�L��3�̏������S���I��������I���
		if (sskill3.buffendflag1 == true && sskill3.buffendflag2 == true) {
			bufft = SSKILL4T;
			this->removeChildByTag(buffendS);			//�\�L������
			sskill3allworkendflag = true;				//�X�L���V�̏����͑S���I�����
			sskill3.buffendflag1 = false;				//������
			sskill3.buffendflag2 = false;				//������
			gameflame = 0;								//���Ԃ�0��
		}
		break;
	}
//�R�m�@sskill4(�I�񂾂�̑���Ƀ_���[�W���󂯂�)
	case BossScene::SSKILL4T: {
		//�d�ˊ|���̏ꍇ�����邩�瑝�₵�Ă���
		//�R�m�@sskill4�̌��ʃ^�[������1
		if (sskill4.buffendflag1 == false) {
			if (sskill4.buffturn1 > 1) {
				sskill4.buffturn1 -= 1;
				sskill4.buffendflag1 = true;	//�X�L���^�[��������Ȃ�^�[����1�����ďI��
			}
			else if (sskill4.buffturn1 == 0) {
				sskill4.buffendflag1 = true;	//�X�L���^�[�����Ȃ��Ȃ炻�̂܂܏I��
			}
		}

		//���ʃ^�[����0�ɂȂ�����X�e�[�^�X��߂�
		//����1
		if (sskill4.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				insteadflag = false;		//�^�Q�W��1����
			}
		}
		
		//������
		auto sskill4buffend = CCLabelTTF::create("�R�m�̒P�݂̔���Ԃ��߂���", "HGRSGU.TTC", fontsizeL);
		sskill4buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//�\�L���ďI��
		if (battleturn > 1) {
			if (sskill4.buffturn1 == 1) {
				if (sskill4.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill4buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						sskill4.buffturn1 = 0;				//����������
						sskill4.buffendflag1 = true;		//�I�����
					}
				}
			}
		}
		//�R�m�̃X�L��3�̏������S���I��������I���
		if (sskill4.buffendflag1 == true) {
			bufft = SSKILL5T;
			this->removeChildByTag(buffendS);			//�\�L������
			sskill4allworkendflag = true;				//�X�L���V�̏����͑S���I�����
			sskill4.buffendflag1 = false;				//������
			sskill4.buffendflag2 = false;				//������
			gameflame = 0;								//���Ԃ�0��
		}
		break;
	}
//�R�m�@sskill5(�S���̑���Ƀ_���[�W���󂯂�)
	case BossScene::SSKILL5T: {
		//�d�ˊ|���̏ꍇ�����邩�瑝�₵�Ă���
		//�R�m�@sskill5�̌��ʃ^�[������1
		if (sskill5.buffendflag1 == false) {
			if (sskill5.buffturn1 > 1) {
				sskill5.buffturn1 -= 1;
				sskill5.buffendflag1 = true;	//�X�L���^�[��������Ȃ�^�[����1�����ďI��
			}
			else if (sskill5.buffturn1 == 0) {
				sskill5.buffendflag1 = true;	//�X�L���^�[�����Ȃ��Ȃ炻�̂܂܏I��
			}
		}

		//���ʃ^�[����0�ɂȂ�����X�e�[�^�X��߂�
		//����1
		if (sskill5.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				allinsteadflag = false;		//�^�Q�W��1����
			}
		}

		//������
		auto sskill5buffend = CCLabelTTF::create("�R�m�̑S�݂̔���Ԃ��߂���", "HGRSGU.TTC", fontsizeL);
		sskill5buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//�\�L���ďI��
		if (battleturn > 1) {
			if (sskill5.buffturn1 == 1) {
				if (sskill5.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill5buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						sskill5.buffturn1 = 0;				//����������
						sskill5.buffendflag1 = true;		//�I�����
					}
				}
			}
		}
		//�R�m�̃X�L��3�̏������S���I��������I���
		if (sskill5.buffendflag1 == true) {
			bufft = SSKILL6T;
			this->removeChildByTag(buffendS);			//�\�L������
			sskill5allworkendflag = true;				//�X�L���V�̏����͑S���I�����
			sskill5.buffendflag1 = false;				//������
			sskill5.buffendflag2 = false;				//������
			gameflame = 0;								//���Ԃ�0��
		}
		break;
	}
//�R�m�@sskill6(��x���񂾂畜��)
	case BossScene::SSKILL6T: {
		bufft = SSKILL7T;
		break;
	}
//�R�m�@sskill7(�R�m�̖h��͏��A�b�v)
	case BossScene::SSKILL7T: {
		//�d�ˊ|���̏ꍇ�����邩�瑝�₵�Ă���
		//�R�m�@sskill7�̌��ʃ^�[������1
		if (sskill7.buffendflag1 == false) {
			if (sskill7.buffturn1 > 1) {
				sskill7.buffturn1 -= 1;
				sskill7.buffendflag1 = true;	//�X�L���^�[��������Ȃ�^�[����1�����ďI��
			}
			else if (sskill7.buffturn1 == 0) {
				sskill7.buffendflag1 = true;	//�X�L���^�[�����Ȃ��Ȃ炻�̂܂܏I��
			}
		}
		//�R�m�@sskill7�̌��ʃ^�[������2
		if (sskill7.buffendflag2 == false) {
			if (sskill7.buffturn2 > 1) {
				sskill7.buffturn2 -= 1;
				sskill7.buffendflag2 = true;
			}
			else if (sskill7.buffturn2 == 0) {
				sskill7.buffendflag2 = true;
			}
		}
		//�R�m�@sskill7�̌��ʃ^�[������3
		if (sskill7.buffendflag3 == false) {
			if (sskill7.buffturn3 > 1) {
				sskill7.buffturn3 -= 1;
				sskill7.buffendflag3 = true;
			}
			else if (sskill7.buffturn3 == 0) {
				sskill7.buffendflag3 = true;
			}
		}
		//�R�m�@sskill7�̌��ʃ^�[������4
		if (sskill7.buffendflag4 == false) {
			if (sskill7.buffturn4 > 1) {
				sskill7.buffturn4 -= 1;
				sskill7.buffendflag4 = true;
			}
			else if (sskill7.buffturn4 == 0) {
				sskill7.buffendflag4 = true;
			}
		}
		//�R�m�@sskill7�̌��ʃ^�[������5
		if (sskill7.buffendflag5 == false) {
			if (sskill7.buffturn5 > 1) {
				sskill7.buffturn5 -= 1;
				sskill7.buffendflag5 = true;
			}
			else if (sskill7.buffturn5 == 0) {
				sskill7.buffendflag5 = true;
			}
		}
		//���ʃ^�[����0�ɂȂ�����X�e�[�^�X��߂�
		//����1
		if (sskill7.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.def -= sskill7.buffupefect1;		//�グ������������
				sskill7.buffupefect1 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����2
		if (sskill7.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.def -= sskill7.buffupefect2;		//�グ������������
				sskill7.buffupefect2 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����3
		if (sskill7.buffturn3 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.def -= sskill7.buffupefect3;		//�グ������������
				sskill7.buffupefect3 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����4
		if (sskill7.buffturn4 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.def -= sskill7.buffupefect4;		//�グ������������
				sskill7.buffupefect4 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����5
		if (sskill7.buffturn5 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.def -= sskill7.buffupefect5;		//�グ������������
				sskill7.buffupefect5 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}

		//������
		auto sskill7buffend = CCLabelTTF::create("�R�m�̖h��͂��߂���", "HGRSGU.TTC", fontsizeL);
		sskill7buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//�\�L���ďI��
		if (battleturn > 1) {
			if (sskill7.buffturn1 == 1) {
				if (sskill7.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill7buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						sskill7.buffturn1 = 0;				//����������
						sskill7.buffendflag1 = true;		//�I�����
					}
				}
			}
			if (sskill7.buffturn2 == 1) {
				if (sskill7.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill7buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						sskill7.buffturn2 = 0;				//����������
						sskill7.buffendflag2 = true;		//�I�����
					}
				}
			}
			if (sskill7.buffturn3 == 1) {
				if (sskill7.buffendflag3 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill7buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						sskill7.buffturn3 = 0;				//����������
						sskill7.buffendflag3 = true;		//�I�����
					}
				}
			}
			if (sskill7.buffturn4 == 1) {
				if (sskill7.buffendflag4 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill7buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						sskill7.buffturn4 = 0;				//����������
						sskill7.buffendflag4 = true;		//�I�����
					}
				}
			}
			if (sskill7.buffturn5 == 1) {
				if (sskill7.buffendflag5 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill7buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						sskill7.buffturn5 = 0;				//����������
						sskill7.buffendflag5 = true;		//�I�����
					}
				}
			}
		}
		//�R�m�̃X�L��7�̏������S���I��������I���
		if (sskill7.buffendflag1 == true && sskill7.buffendflag2 == true
			&& sskill7.buffendflag3 == true && sskill7.buffendflag4 == true
			&& sskill7.buffendflag5 == true) {
			bufft = SSKILL8T;
			this->removeChildByTag(buffendS);			//�\�L������
			sskill7allworkendflag = true;				//�X�L���V�̏����͑S���I�����
			sskill7.buffendflag1 = false;				//������
			sskill7.buffendflag2 = false;				//������
			sskill7.buffendflag3 = false;				//������
			sskill7.buffendflag4 = false;				//������
			sskill7.buffendflag5 = false;				//������
			gameflame = 0;								//���Ԃ�0��
		}
		break;
	}
//�R�m�@sskill8(�R�m�̖h��̓_�C�A�b�v,�U���͏��_�E��)
	case BossScene::SSKILL8T: {
		//�d�ˊ|���̏ꍇ�����邩�瑝�₵�Ă���
		//�R�m�@sskill8�̌��ʃ^�[������1
		if (sskill8.buffendflag1 == false) {
			if (sskill8.buffturn1 > 1) {
				sskill8.buffturn1 -= 1;
				sskill8.buffendflag1 = true;	//�X�L���^�[��������Ȃ�^�[����1�����ďI��
			}
			else if (sskill8.buffturn1 == 0) {
				sskill8.buffendflag1 = true;	//�X�L���^�[�����Ȃ��Ȃ炻�̂܂܏I��
			}
		}
		//�R�m�@sskill8�̌��ʃ^�[������2
		if (sskill8.buffendflag2 == false) {
			if (sskill8.buffturn2 > 1) {
				sskill8.buffturn2 -= 1;
				sskill8.buffendflag2 = true;
			}
			else if (sskill8.buffturn2 == 0) {
				sskill8.buffendflag2 = true;
			}
		}
		//�R�m�@sskill8�̌��ʃ^�[������3
		if (sskill8.buffendflag3 == false) {
			if (sskill8.buffturn3 > 1) {
				sskill8.buffturn3 -= 1;
				sskill8.buffendflag3 = true;
			}
			else if (sskill8.buffturn3 == 0) {
				sskill8.buffendflag3 = true;
			}
		}
		//�R�m�@sskill8�̌��ʃ^�[������4
		if (sskill8.buffendflag4 == false) {
			if (sskill8.buffturn4 > 1) {
				sskill8.buffturn4 -= 1;
				sskill8.buffendflag4 = true;
			}
			else if (sskill8.buffturn4 == 0) {
				sskill8.buffendflag4 = true;
			}
		}
		//���ʃ^�[����0�ɂȂ�����X�e�[�^�X��߂�
		//����1
		if (sskill8.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				shield.def -= sskill8.buffupefect1;	//�グ������������
				shield.atk += sskill8.buffdownefect1;	//����������������
				sskill8.buffupefect1 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				sskill8.buffdownefect1 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����2
		if (sskill8.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				shield.def -= sskill8.buffupefect2;		//�グ������������
				shield.atk += sskill8.buffdownefect2;	//����������������
				sskill8.buffupefect2 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				sskill8.buffdownefect2 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����3
		if (sskill8.buffturn3 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				shield.def -= sskill8.buffupefect3;		//�グ������������
				shield.atk += sskill8.buffdownefect3;	//����������������
				sskill8.buffupefect3 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				sskill8.buffdownefect3 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����4
		if (sskill8.buffturn4 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				shield.def -= sskill8.buffupefect4;		//�グ������������
				shield.atk += sskill8.buffdownefect4;	//����������������
				sskill8.buffupefect4 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				sskill8.buffdownefect4 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
			}
		}

		//������
		auto sskill8buffend = CCLabelTTF::create("�R�m�̖h��͂��߂���", "HGRSGU.TTC", fontsizeL);
		sskill8buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		auto sskill8buffend2 = CCLabelTTF::create("�R�m�̍U���͂��߂���", "HGRSGU.TTC", fontsizeL);
		sskill8buffend2->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//�\�L���ďI��
		if (battleturn > 1) {
			if (sskill8.buffturn1 == 1) {
				if (sskill8.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill8buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//�\�L������
						this->addChild(sskill8buffend2, backdepth, buffend2S);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame220) {
						sskill8.buffturn1 = 0;				//����������
						sskill8.buffendflag1 = true;		//�I�����
					}
				}
			}
			if (sskill8.buffturn2 == 1) {
				if (sskill8.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill8buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//�\�L������
						this->addChild(sskill8buffend2, backdepth, buffend2S);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame220) {
						sskill8.buffturn2 = 0;				//����������
						sskill8.buffendflag2 = true;		//�I�����
					}
				}
			}
			if (sskill8.buffturn3 == 1) {
				if (sskill8.buffendflag3 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill8buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//�\�L������
						this->addChild(sskill8buffend2, backdepth, buffend2S);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame220) {
						sskill8.buffturn3 = 0;				//����������
						sskill8.buffendflag3 = true;		//�I�����
					}
				}
			}
			if (sskill8.buffturn4 == 1) {
				if (sskill8.buffendflag4 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill8buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//�\�L������
						this->addChild(sskill8buffend2, backdepth, buffend2S);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame220) {
						sskill8.buffturn4 = 0;				//����������
						sskill8.buffendflag4 = true;		//�I�����
					}
				}
			}
		}
		//�R�m�̃X�L��8�̏������S���I��������I���
		if (sskill8.buffendflag1 == true && sskill8.buffendflag2 == true
			&& sskill8.buffendflag3 == true && sskill8.buffendflag4 == true) {
			bufft = MSKILL2T;
			this->removeChildByTag(buffend2S);			//�\�L������
			sskill8allworkendflag = true;				//�X�L��8�̏����͑S���I�����
			sskill8.buffendflag1 = false;				//������
			sskill8.buffendflag2 = false;				//������
			sskill8.buffendflag3 = false;				//������
			sskill8.buffendflag4 = false;				//������
			gameflame = 0;								//���Ԃ�0��
		}
		break;
	}
//���p�t mskill2(���p�t�̖h��͏��A�b�v)
	case BossScene::MSKILL2T: {
		if (mskill2.buffendflag1 == false) {
			//�d�ˊ|���̏ꍇ�����邩�瑝�₵�Ă���
			//���p�t�@mskill2�̌��ʃ^�[������1
			if (mskill2.buffturn1 > 1) {
				mskill2.buffturn1 -= 1;
				mskill2.buffendflag1 = true;	//�X�L���^�[��������Ȃ�^�[����1�����ďI��
			}
			else if (mskill2.buffturn1 == 0) {
				mskill2.buffendflag1 = true;	//�X�L���^�[�����Ȃ��Ȃ炻�̂܂܏I��
			}
		}
		//���p�t�@mskill2�̌��ʃ^�[������2
		if (mskill2.buffendflag2 == false) {
			if (mskill2.buffturn2 > 1) {
				mskill2.buffturn2 -= 1;
				mskill2.buffendflag2 = true;
			}
			else if (mskill2.buffturn2 == 0) {
				mskill2.buffendflag2 = true;
			}
		}
		//���ʃ^�[����0�ɂȂ�����X�e�[�^�X��߂�
		//����1
		if (mskill2.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				magic.def -= mskill2.buffupefect1;		//�グ������������
				mskill2.buffupefect1 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����2
		if (mskill2.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				magic.def -= mskill2.buffupefect2;		//�グ������������
				mskill2.buffupefect2 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
			}
		}

		//������
		auto mskill2buffend = CCLabelTTF::create("���p�t�̖h��͂��߂���", "HGRSGU.TTC", fontsizeL);
		mskill2buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//�\�L���ďI��
		if (battleturn > 1) {
			if (mskill2.buffturn1 == 1) {
				if (mskill2.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill2buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						mskill2.buffturn1 = 0;				//����������
						mskill2.buffendflag1 = true;		//�I�����
					}
				}
			}
			if (mskill2.buffturn2 == 1) {
				if (mskill2.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill2buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						mskill2.buffturn2 = 0;				//����������
						mskill2.buffendflag2 = true;		//�I�����
					}
				}
			}
		}
		//���p�t�̃X�L��2�̏������S���I��������I���
		if (mskill2.buffendflag1 == true && mskill2.buffendflag2 == true) {
			bufft = MSKILL3T;
			this->removeChildByTag(buffendS);			//�\�L������
			mskill2allworkendflag = true;				//�X�L���V�̏����͑S���I�����
			mskill2.buffendflag1 = false;				//������
			mskill2.buffendflag2 = false;				//������
			gameflame = 0;								//���Ԃ�0��
		}
		break;
	}
//���p�t mskill3(�G�̍U���͂����_�E��)
	case BossScene::MSKILL3T: {
		if (mskill3.buffendflag1 == false) {
			//�d�ˊ|���̏ꍇ�����邩�瑝�₵�Ă���
			//���p�t�@mskill3�̌��ʃ^�[������1
			if (mskill3.buffturn1 > 1) {
				mskill3.buffturn1 -= 1;
				mskill3.buffendflag1 = true;	//�X�L���^�[��������Ȃ�^�[����1�����ďI��
			}
			else if (mskill3.buffturn1 == 0) {
				mskill3.buffendflag1 = true;	//�X�L���^�[�����Ȃ��Ȃ炻�̂܂܏I��
			}
		}
		//���p�t�@mskill3�̌��ʃ^�[������2
		if (mskill3.buffendflag2 == false) {
			if (mskill3.buffturn2 > 1) {
				mskill3.buffturn2 -= 1;
				mskill3.buffendflag2 = true;
			}
			else if (mskill3.buffturn2 == 0) {
				mskill3.buffendflag2 = true;
			}
		}
		//���ʃ^�[����0�ɂȂ�����X�e�[�^�X��߂�
		//����1
		if (mskill3.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.atk += mskill3.buffdownefect1;		//����������������
				mskill3.buffdownefect1 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����2
		if (mskill3.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.atk += mskill3.buffdownefect2;		//����������������
				mskill3.buffdownefect2 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}

		//������
		auto mskill3buffend = CCLabelTTF::create("���@���L�����[�̍U���͂��߂���", "HGRSGU.TTC", fontsizeL);
		mskill3buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//�\�L���ďI��
		if (battleturn > 1) {
			if (mskill3.buffturn1 == 1) {
				if (mskill3.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill3buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						mskill3.buffturn1 = 0;				//����������
						mskill3.buffendflag1 = true;		//�I�����
					}
				}
			}
			if (mskill3.buffturn2 == 1) {
				if (mskill3.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill3buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						mskill3.buffturn2 = 0;				//����������
						mskill3.buffendflag2 = true;		//�I�����
					}
				}
			}
		}
		//���p�t�̃X�L��2�̏������S���I��������I���
		if (mskill3.buffendflag1 == true && mskill3.buffendflag2 == true) {
			bufft = MSKILL5T;
			this->removeChildByTag(buffendS);			//�\�L������
			mskill3allworkendflag = true;				//�X�L���V�̏����͑S���I�����
			mskill3.buffendflag1 = false;				//������
			mskill3.buffendflag2 = false;				//������
			gameflame = 0;								//���Ԃ�0��
		}
		break;
	}
//���p�t mskill5(�����̍U���͂�h��͂����A�b�v)
	case BossScene::MSKILL5T: {
		//�d�ˊ|���̏ꍇ�����邩�瑝�₵�Ă���
		//���p�t�@mskill5�̌��ʃ^�[������1
		if (mskill5.buffendflag1 == false) {
			if (mskill5.buffturn1 > 1) {
				mskill5.buffturn1 -= 1;
				mskill5.buffendflag1 = true;	//�X�L���^�[��������Ȃ�^�[����1�����ďI��
			}
			else if (mskill5.buffturn1 == 0) {
				mskill5.buffendflag1 = true;	//�X�L���^�[�����Ȃ��Ȃ炻�̂܂܏I��
			}
		}
		//���p�t�@mskill5�̌��ʃ^�[������2
		if (mskill5.buffendflag2 == false) {
			if (mskill5.buffturn2 > 1) {
				mskill5.buffturn2 -= 1;
				mskill5.buffendflag2 = true;
			}
			else if (mskill5.buffturn2 == 0) {
				mskill5.buffendflag2 = true;
			}
		}
		//���p�t�@mskill5�̌��ʃ^�[������3
		if (mskill5.buffendflag3 == false) {
			if (mskill5.buffturn3 > 1) {
				mskill5.buffturn3 -= 1;
				mskill5.buffendflag3 = true;
			}
			else if (mskill5.buffturn3 == 0) {
				mskill5.buffendflag3 = true;
			}
		}
		//���p�t�@mskill5�̌��ʃ^�[������4
		if (mskill5.buffendflag4 == false) {
			if (mskill5.buffturn4 > 1) {
				mskill5.buffturn4 -= 1;
				mskill5.buffendflag4 = true;
			}
			else if (mskill5.buffturn4 == 0) {
				mskill5.buffendflag4 = true;
			}
		}

		//���ʃ^�[����0�ɂȂ�����X�e�[�^�X��߂�
		//����1
		if (mskill5.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= mskill5.attackeratkbuff1;	//�グ������������
				attacker.def -= mskill5.attackerdefbuff1;	//�グ������������
				shield.atk -= mskill5.shieldatkbuff1;		//�グ������������
				shield.def -= mskill5.shielddefbuff1;		//�グ������������
				magic.atk -= mskill5.magicatkbuff1;			//�グ������������
				magic.def -= mskill5.magicdefbuff1;			//�グ������������
				healer.atk -= mskill5.healeratkbuff1;		//�グ������������
				healer.def -= mskill5.healerdefbuff1;		//�グ������������
				mskill5.attackeratkbuff1 = 0;			//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.attackerdefbuff1 = 0;			//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.shieldatkbuff1 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.shielddefbuff1 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.magicatkbuff1 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.magicdefbuff1 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.healeratkbuff1 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.healerdefbuff1 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����2
		if (mskill5.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= mskill5.attackeratkbuff2;	//�グ������������
				attacker.def -= mskill5.attackerdefbuff2;	//�グ������������
				shield.atk -= mskill5.shieldatkbuff2;		//�グ������������
				shield.def -= mskill5.shielddefbuff2;		//�グ������������
				magic.atk -= mskill5.magicatkbuff2;			//�グ������������
				magic.def -= mskill5.magicdefbuff2;			//�グ������������
				healer.atk -= mskill5.healeratkbuff2;		//�グ������������
				healer.def -= mskill5.healerdefbuff2;		//�グ������������
				mskill5.attackeratkbuff2 = 0;			//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.attackerdefbuff2 = 0;			//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.shieldatkbuff2 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.shielddefbuff2 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.magicatkbuff2 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.magicdefbuff2 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.healeratkbuff2 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.healerdefbuff2 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����3
		if (mskill5.buffturn3 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= mskill5.attackeratkbuff3;	//�グ������������
				attacker.def -= mskill5.attackerdefbuff3;	//�グ������������
				shield.atk -= mskill5.shieldatkbuff3;		//�グ������������
				shield.def -= mskill5.shielddefbuff3;		//�グ������������
				magic.atk -= mskill5.magicatkbuff3;			//�グ������������
				magic.def -= mskill5.magicdefbuff3;			//�グ������������
				healer.atk -= mskill5.healeratkbuff3;		//�グ������������
				healer.def -= mskill5.healerdefbuff3;		//�グ������������
				mskill5.attackeratkbuff3 = 0;			//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.attackerdefbuff3 = 0;			//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.shieldatkbuff3 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.shielddefbuff3 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.magicatkbuff3 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.magicdefbuff3 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.healeratkbuff3 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.healerdefbuff3 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����4
		if (mskill5.buffturn4 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= mskill5.attackeratkbuff4;	//�グ������������
				attacker.def -= mskill5.attackerdefbuff4;	//�グ������������
				shield.atk -= mskill5.shieldatkbuff4;		//�グ������������
				shield.def -= mskill5.shielddefbuff4;		//�グ������������
				magic.atk -= mskill5.magicatkbuff4;			//�グ������������
				magic.def -= mskill5.magicdefbuff4;			//�グ������������
				healer.atk -= mskill5.healeratkbuff4;		//�グ������������
				healer.def -= mskill5.healerdefbuff4;		//�グ������������
				mskill5.attackeratkbuff4 = 0;			//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.attackerdefbuff4 = 0;			//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.shieldatkbuff4 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.shielddefbuff4 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.magicatkbuff4 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.magicdefbuff4 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.healeratkbuff4 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill5.healerdefbuff4 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
			}
		}

		//������
		auto mskill5buffend = CCLabelTTF::create("�S���̍U���͂��߂���", "HGRSGU.TTC", fontsizeL);
		mskill5buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		auto mskill5buffend2 = CCLabelTTF::create("�S���̖h��͂��߂���", "HGRSGU.TTC", fontsizeL);
		mskill5buffend2->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//�\�L���ďI��
		if (battleturn > 1) {
			if (mskill5.buffturn1 == 1) {
				if (mskill5.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill5buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//�\�L������
						this->addChild(mskill5buffend2, backdepth, buffend2S);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame220) {
						mskill5.buffturn1 = 0;				//����������
						mskill5.buffendflag1 = true;		//�I�����
					}
				}
			}
			if (mskill5.buffturn2 == 1) {
				if (mskill5.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill5buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//�\�L������
						this->addChild(mskill5buffend2, backdepth, buffend2S);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame220) {
						mskill5.buffturn2 = 0;				//����������
						mskill5.buffendflag2 = true;		//�I�����
					}
				}
			}
			if (mskill5.buffturn3 == 1) {
				if (mskill5.buffendflag3 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill5buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//�\�L������
						this->addChild(mskill5buffend2, backdepth, buffend2S);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame220) {
						mskill5.buffturn3 = 0;				//����������
						mskill5.buffendflag3 = true;		//�I�����
					}
				}
			}
			if (mskill5.buffturn4 == 1) {
				if (mskill5.buffendflag4 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill5buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//�\�L������
						this->addChild(mskill5buffend2, backdepth, buffend2S);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame220) {
						mskill5.buffturn4 = 0;				//����������
						mskill5.buffendflag4 = true;		//�I�����
					}
				}
			}
		}
		//���p�t�̃X�L��8�̏������S���I��������I���
		if (mskill5.buffendflag1 == true && mskill5.buffendflag2 == true
			&& mskill5.buffendflag3 == true && mskill5.buffendflag4 == true) {
			bufft = MSKILL6T;
			this->removeChildByTag(buffend2S);			//�\�L������
			mskill5allworkendflag = true;				//�X�L���V�̏����͑S���I�����
			mskill5.buffendflag1 = false;				//������
			mskill5.buffendflag2 = false;				//������
			mskill5.buffendflag3 = false;				//������
			mskill5.buffendflag4 = false;				//������
			gameflame = 0;								//���Ԃ�0��
		}
		break;
	}
//���p�t mskill6(�����̍U���͂�h��͂��A�b�v)
	case BossScene::MSKILL6T: {
		//�d�ˊ|���̏ꍇ�����邩�瑝�₵�Ă���
		//���p�t�@mskill6�̌��ʃ^�[������1
		if (mskill6.buffendflag1 == false) {
			if (mskill6.buffturn1 > 1) {
				mskill6.buffturn1 -= 1;
				mskill6.buffendflag1 = true;	//�X�L���^�[��������Ȃ�^�[����1�����ďI��
			}
			else if (mskill6.buffturn1 == 0) {
				mskill6.buffendflag1 = true;	//�X�L���^�[�����Ȃ��Ȃ炻�̂܂܏I��
			}
		}
		//���p�t�@mskill6�̌��ʃ^�[������2
		if (mskill6.buffendflag2 == false) {
			if (mskill6.buffturn2 > 1) {
				mskill6.buffturn2 -= 1;
				mskill6.buffendflag2 = true;
			}
			else if (mskill6.buffturn2 == 0) {
				mskill6.buffendflag2 = true;
			}
		}
		//���p�t�@mskill6�̌��ʃ^�[������3
		if (mskill6.buffendflag3 == false) {
			if (mskill6.buffturn3 > 1) {
				mskill6.buffturn3 -= 1;
				mskill6.buffendflag3 = true;
			}
			else if (mskill6.buffturn3 == 0) {
				mskill6.buffendflag3 = true;
			}
		}
		//���p�t�@mskill6�̌��ʃ^�[������4
		if (mskill6.buffendflag4 == false) {
			if (mskill6.buffturn4 > 1) {
				mskill6.buffturn4 -= 1;
				mskill6.buffendflag4 = true;
			}
			else if (mskill6.buffturn4 == 0) {
				mskill6.buffendflag4 = true;
			}
		}
		//���ʃ^�[����0�ɂȂ�����X�e�[�^�X��߂�
		//����1
		if (mskill6.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= mskill6.attackeratkbuff1;//�グ������������
				attacker.def -= mskill6.attackerdefbuff1;//�グ������������
				shield.atk -= mskill6.shieldatkbuff1;	//�グ������������
				shield.def -= mskill6.shielddefbuff1;	//�グ������������
				magic.atk -= mskill6.magicatkbuff1;		//�グ������������
				magic.def -= mskill6.magicdefbuff1;		//�グ������������
				healer.atk -= mskill6.healeratkbuff1;	//�グ������������
				healer.def -= mskill6.healerdefbuff1;	//�グ������������
				mskill6.attackeratkbuff1 = 0;			//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.attackerdefbuff1 = 0;			//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.shieldatkbuff1 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.shielddefbuff1 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.magicatkbuff1 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.magicdefbuff1 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.healeratkbuff1 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.healerdefbuff1 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����2
		if (mskill6.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= mskill6.attackeratkbuff2;//�グ������������
				attacker.def -= mskill6.attackerdefbuff2;//�グ������������
				shield.atk -= mskill6.shieldatkbuff2;	//�グ������������
				shield.def -= mskill6.shielddefbuff2;	//�グ������������
				magic.atk -= mskill6.magicatkbuff2;		//�グ������������
				magic.def -= mskill6.magicdefbuff2;		//�グ������������
				healer.atk -= mskill6.healeratkbuff2;	//�グ������������
				healer.def -= mskill6.healerdefbuff2;	//�グ������������
				mskill6.attackeratkbuff2 = 0;			//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.attackerdefbuff2 = 0;			//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.shieldatkbuff2 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.shielddefbuff2 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.magicatkbuff2 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.magicdefbuff2 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.healeratkbuff2 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.healerdefbuff2 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����3
		if (mskill6.buffturn3 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= mskill6.attackeratkbuff3;//�グ������������
				attacker.def -= mskill6.attackerdefbuff3;//�グ������������
				shield.atk -= mskill6.shieldatkbuff3;	//�グ������������
				shield.def -= mskill6.shielddefbuff3;	//�グ������������
				magic.atk -= mskill6.magicatkbuff3;		//�グ������������
				magic.def -= mskill6.magicdefbuff3;		//�グ������������
				healer.atk -= mskill6.healeratkbuff3;	//�グ������������
				healer.def -= mskill6.healerdefbuff3;	//�グ������������
				mskill6.attackeratkbuff3 = 0;			//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.attackerdefbuff3 = 0;			//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.shieldatkbuff3 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.shielddefbuff3 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.magicatkbuff3 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.magicdefbuff3 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.healeratkbuff3 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.healerdefbuff3 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����4
		if (mskill6.buffturn4 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= mskill6.attackeratkbuff4;//�グ������������
				attacker.def -= mskill6.attackerdefbuff4;//�グ������������
				shield.atk -= mskill6.shieldatkbuff4;	//�グ������������
				shield.def -= mskill6.shielddefbuff4;	//�グ������������
				magic.atk -= mskill6.magicatkbuff4;		//�グ������������
				magic.def -= mskill6.magicdefbuff4;		//�グ������������
				healer.atk -= mskill6.healeratkbuff4;	//�グ������������
				healer.def -= mskill6.healerdefbuff4;	//�グ������������
				mskill6.attackeratkbuff4 = 0;			//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.attackerdefbuff4 = 0;			//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.shieldatkbuff4 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.shielddefbuff4 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.magicatkbuff4 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.magicdefbuff4 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.healeratkbuff4 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
				mskill6.healerdefbuff4 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
			}
		}

		//������
		auto mskill6buffend = CCLabelTTF::create("�S���̍U���͂��߂���", "HGRSGU.TTC", fontsizeL);
		mskill6buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		auto mskill6buffend2 = CCLabelTTF::create("�S���̖h��͂��߂���", "HGRSGU.TTC", fontsizeL);
		mskill6buffend2->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//�\�L���ďI��
		if (battleturn > 1) {
			if (mskill6.buffturn1 == 1) {
				if (mskill6.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill6buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//�\�L������
						this->addChild(mskill6buffend2, backdepth, buffend2S);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame220) {
						this->removeChildByTag(buffend2S);	//�\�L������
						gameflame = 0;						//����������
						mskill6.buffturn1 = 0;				//����������
						mskill6.buffendflag1 = true;		//�I�����
					}
				}
			}
			if (mskill6.buffturn2 == 1) {
				if (mskill6.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill6buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//�\�L������
						this->addChild(mskill6buffend2, backdepth, buffend2S);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame220) {
						this->removeChildByTag(buffend2S);	//�\�L������
						gameflame = 0;						//����������
						mskill6.buffturn2 = 0;				//����������
						mskill6.buffendflag2 = true;		//�I�����
					}
				}
			}
			if (mskill6.buffturn3 == 1) {
				if (mskill6.buffendflag3 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill6buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//�\�L������
						this->addChild(mskill6buffend2, backdepth, buffend2S);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame220) {
						this->removeChildByTag(buffend2S);	//�\�L������
						gameflame = 0;						//����������
						mskill6.buffturn3 = 0;				//����������
						mskill6.buffendflag3 = true;		//�I�����
					}
				}
			}
			if (mskill6.buffturn4 == 1) {
				if (mskill6.buffendflag4 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill6buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//�\�L������
						this->addChild(mskill6buffend2, backdepth, buffend2S);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame220) {
						this->removeChildByTag(buffend2S);	//�\�L������
						mskill6.buffturn4 = 0;				//����������
						mskill6.buffendflag4 = true;		//�I�����
					}
				}
			}
		}
		//���p�t�̃X�L��6�̏������S���I��������I���
		if (mskill6.buffendflag1 == true && mskill6.buffendflag2 == true
			&& mskill6.buffendflag3 == true&& mskill6.buffendflag4 == true) {
			bufft = HSKILL2T;
			mskill6allworkendflag = true;				//�X�L���V�̏����͑S���I�����
			mskill6.buffendflag1 = false;				//������
			mskill6.buffendflag2 = false;				//������
			mskill6.buffendflag3 = false;				//������
			mskill6.buffendflag4 = false;				//������
			gameflame = 0;								//���Ԃ�0��
		}
		break;
	}
//���E�� hskill2(�G�̍U���͂𒆃_�E��)
	case BossScene::HSKILL2T: {
		//�d�ˊ|���̏ꍇ�����邩�瑝�₵�Ă���
		//���E�ҁ@HSKILL2�̌��ʃ^�[������1
		if (hskill2.buffendflag1 == false) {
			if (hskill2.buffturn1 > 1) {
				hskill2.buffturn1 -= 1;
				hskill2.buffendflag1 = true;	//�X�L���^�[��������Ȃ�^�[����1�����ďI��
			}
			else if (hskill2.buffturn1 == 0) {
				hskill2.buffendflag1 = true;	//�X�L���^�[�����Ȃ��Ȃ炻�̂܂܏I��
			}
		}
		//���E�ҁ@hskill2�̌��ʃ^�[������2
		if (hskill2.buffendflag2 == false) {
			if (hskill2.buffturn2 > 1) {
				hskill2.buffturn2 -= 1;
				hskill2.buffendflag2 = true;
			}
			else if (hskill2.buffturn2 == 0) {
				hskill2.buffendflag2 = true;
			}
		}
		//���E�ҁ@hskill2�̌��ʃ^�[������3
		if (hskill2.buffendflag3 == false) {
			if (hskill2.buffturn3 > 1) {
				hskill2.buffturn3 -= 1;
				hskill2.buffendflag3 = true;
			}
			else if (hskill2.buffturn3 == 0) {
				hskill2.buffendflag3 = true;
			}
		}
		//���E�ҁ@hskill2�̌��ʃ^�[������4
		if (hskill2.buffendflag4 == false) {
			if (hskill2.buffturn4 > 1) {
				hskill2.buffturn4 -= 1;
				hskill2.buffendflag4 = true;
			}
			else if (hskill2.buffturn4 == 0) {
				hskill2.buffendflag4 = true;
			}
		}
		//���ʃ^�[����0�ɂȂ�����X�e�[�^�X��߂�
		//����1
		if (hskill2.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.atk -= hskill2.buffupefect1;		//����������������
				hskill2.buffupefect1 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����2
		if (hskill2.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.atk -= hskill2.buffupefect2;		//����������������
				hskill2.buffupefect2 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����3
		if (hskill2.buffturn3 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.atk -= hskill2.buffupefect3;		//����������������
				hskill2.buffupefect3 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����4
		if (hskill2.buffturn4 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.atk -= hskill2.buffupefect4;		//����������������
				hskill2.buffupefect4 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}

		//������
		auto hskill2buffend = CCLabelTTF::create("���@���L�����[�̍U���͂��߂���", "HGRSGU.TTC", fontsizeL);
		hskill2buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//�\�L���ďI��
		if (battleturn > 1) {
			if (hskill2.buffturn1 == 1) {
				if (hskill2.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(hskill2buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						hskill2.buffturn1 = 0;				//����������
						hskill2.buffendflag1 = true;		//�I�����
					}
				}
			}
			if (hskill2.buffturn2 == 1) {
				if (hskill2.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(hskill2buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						hskill2.buffturn2 = 0;				//����������
						hskill2.buffendflag2 = true;		//�I�����
					}
				}
			}
			if (hskill2.buffturn3 == 1) {
				if (hskill2.buffendflag3 == false) {
					if (gameflame == flame80) {
						this->addChild(hskill2buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						hskill2.buffturn3 = 0;				//����������
						hskill2.buffendflag3 = true;		//�I�����
					}
				}
			}
			if (hskill2.buffturn4 == 1) {
				if (hskill2.buffendflag4 == false) {
					if (gameflame == flame80) {
						this->addChild(hskill2buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						hskill2.buffturn4 = 0;				//����������
						hskill2.buffendflag4 = true;		//�I�����
					}
				}
			}
		}

		//���E�҂̃X�L��2�̏������S���I��������I���
		if (hskill2.buffendflag1 == true && hskill2.buffendflag2 == true
			&& hskill2.buffendflag3 == true && hskill2.buffendflag4 == true) {
			bufft = HSKILL3T;
			this->removeChildByTag(buffendS);			//�\�L������
			hskill2allworkendflag = true;				//�X�L���V�̏����͑S���I�����
			hskill2.buffendflag1 = false;				//������
			hskill2.buffendflag2 = false;				//������
			hskill2.buffendflag3 = false;				//������
			hskill2.buffendflag4 = false;				//������
			gameflame = 0;								//���Ԃ�0��
		}
		break;
	}
//���E�� hskill3(�G�̖h��͂𒆃_�E��)
	case BossScene::HSKILL3T: {
		//�d�ˊ|���̏ꍇ�����邩�瑝�₵�Ă���
		//���E�ҁ@hskill3�̌��ʃ^�[������1
		if (hskill3.buffendflag1 == false) {
			if (hskill3.buffturn1 > 1) {
				hskill3.buffturn1 -= 1;
				hskill3.buffendflag1 = true;	//�X�L���^�[��������Ȃ�^�[����1�����ďI��
			}
			else if (hskill3.buffturn1 == 0) {
				hskill3.buffendflag1 = true;	//�X�L���^�[�����Ȃ��Ȃ炻�̂܂܏I��
			}
		}
		//���E�ҁ@hskill3�̌��ʃ^�[������2
		if (hskill3.buffendflag2 == false) {
			if (hskill3.buffturn2 > 1) {
				hskill3.buffturn2 -= 1;
				hskill3.buffendflag2 = true;
			}
			else if (hskill3.buffturn2 == 0) {
				hskill3.buffendflag2 = true;
			}
		}
		//���E�ҁ@hskill3�̌��ʃ^�[������3
		if (hskill3.buffendflag3 == false) {
			if (hskill3.buffturn3 > 1) {
				hskill3.buffturn3 -= 1;
				hskill3.buffendflag3 = true;
			}
			else if (hskill3.buffturn3 == 0) {
				hskill3.buffendflag3 = true;
			}

		}
		//���E�ҁ@hskill3�̌��ʃ^�[������4
		if (hskill3.buffendflag4 == false) {
			if (hskill3.buffturn4 > 1) {
				hskill3.buffturn4 -= 1;
				hskill3.buffendflag4 = true;
			}
			else if (hskill3.buffturn4 == 0) {
				hskill3.buffendflag4 = true;
			}
		}

		//���ʃ^�[����0�ɂȂ�����X�e�[�^�X��߂�
		//����1
		if (hskill3.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.def -= hskill3.buffupefect1;		//����������������
				hskill3.buffupefect1 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����2
		if (hskill3.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.def -= hskill3.buffupefect2;		//����������������
				hskill3.buffupefect2 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����3
		if (hskill3.buffturn3 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.def -= hskill3.buffupefect3;		//����������������
				hskill3.buffupefect3 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����4
		if (hskill3.buffturn4 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.def -= hskill3.buffupefect4;		//����������������
				hskill3.buffupefect4 = 0;					//�o�t�̌��ʂ������l�ɖ߂�
			}
		}

		//������
		auto hskill3buffend = CCLabelTTF::create("���@���L�����[�̖h��͂��߂���", "HGRSGU.TTC", fontsizeL);
		hskill3buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//�\�L���ďI��
		if (battleturn > 1) {
			if (hskill3.buffturn1 == 1) {
				if (hskill3.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(hskill3buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						hskill3.buffturn1 = 0;				//����������
						hskill3.buffendflag1 = true;		//�I�����
					}
				}
			}
			if (hskill3.buffturn2 == 1) {
				if (hskill3.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(hskill3buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						hskill3.buffturn2 = 0;				//����������
						hskill3.buffendflag2 = true;		//�I�����
					}
				}
			}
			if (hskill3.buffturn3 == 1) {
				if (hskill3.buffendflag3 == false) {
					if (gameflame == flame80) {
						this->addChild(hskill3buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						hskill3.buffturn3 = 0;				//����������
						hskill3.buffendflag3 = true;		//�I�����
					}
				}
			}
			if (hskill3.buffturn4 == 1) {
				if (hskill3.buffendflag4 == false) {
					if (gameflame == flame80) {
						this->addChild(hskill3buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						hskill3.buffturn4 = 0;				//����������
						hskill3.buffendflag4 = true;		//�I�����
					}
				}
			}
		}

		//���E�҂̃X�L��2�̏������S���I��������I���
		if (hskill3.buffendflag1 == true && hskill3.buffendflag2 == true
			&& hskill3.buffendflag3 == true && hskill3.buffendflag4 == true) {
			bufft = BVSKILL3T;
			this->removeChildByTag(buffendS);			//�\�L������
			hskill3allworkendflag = true;				//�X�L���V�̏����͑S���I�����
			hskill3.buffendflag1 = false;				//������
			hskill3.buffendflag2 = false;				//������
			hskill3.buffendflag3 = false;				//������
			hskill3.buffendflag4 = false;				//������
			gameflame = 0;								//���Ԃ�0��
		}
		break;
	}
//���@���L�����| bvskill3(���g�̖h��͂��A�b�v)
	case BossScene::BVSKILL3T: {
		//�d�ˊ|���̏ꍇ�����邩�瑝�₵�Ă���
		//���@���L�����|�@bvskill3�̌��ʃ^�[������1
		if (bvskill3.buffendflag1 == false) {
			if (bvskill3.buffturn1 > 1) {
				bvskill3.buffturn1 -= 1;
				bvskill3.buffendflag1 = true;	//�X�L���^�[��������Ȃ�^�[����1�����ďI��
			}
			else if (bvskill3.buffturn1 == 0) {
				bvskill3.buffendflag1 = true;	//�X�L���^�[�����Ȃ��Ȃ炻�̂܂܏I��
			}
		}
		//���@���L�����|�@bvskill3�̌��ʃ^�[������2
		if (bvskill3.buffendflag2 == false) {
			if (bvskill3.buffturn2 > 1) {
				bvskill3.buffturn2 -= 1;
				bvskill3.buffendflag2 = true;
			}
			else if (bvskill3.buffturn2 == 0) {
				bvskill3.buffendflag2 = true;
			}
		}
		//���ʃ^�[����0�ɂȂ�����X�e�[�^�X��߂�
		//����1
		if (bvskill3.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				magic.def -= bvskill3.buffupefect1;		//�グ������������
				bvskill3.buffupefect1 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
			}
		}
		//����2
		if (bvskill3.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				magic.def -= bvskill3.buffupefect2;		//�グ������������
				bvskill3.buffupefect2 = 0;				//�o�t�̌��ʂ������l�ɖ߂�
			}
		}

		//������
		auto bvskill3buffend = CCLabelTTF::create("���@���L�����|�̖h��͂��߂���", "HGRSGU.TTC", fontsizeL);
		bvskill3buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//�\�L���ďI��
		if (battleturn > 1) {
			if (bvskill3.buffturn1 == 1) {
				if (bvskill3.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(bvskill3buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						bvskill3.buffturn1 = 0;				//����������
						bvskill3.buffendflag1 = true;		//�I�����
					}
				}
			}
			if (bvskill3.buffturn2 == 1) {
				if (bvskill3.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(bvskill3buffend, backdepth, buffendS);	//�o�t�̌��ʂ��؂ꂽ���Ƃ�\�L����
					}
					if (gameflame == flame150) {
						bvskill3.buffturn2 = 0;				//����������
						bvskill3.buffendflag2 = true;		//�I�����
					}
				}
			}
		}
		//���@���L�����|�̃X�L��2�̏������S���I��������I���
		if (bvskill3.buffendflag1 == true && bvskill3.buffendflag2 == true) {
			this->removeChildByTag(buffendS);			//�\�L������
			bvskill3allworkendflag = true;				//�X�L���V�̏����͑S���I�����
			bvskill3.buffendflag1 = false;				//������
			bvskill3.buffendflag2 = false;				//������
			gameflame = 0;								//���Ԃ�0��
		}
		//�S���I�������R�}���h�I����
		if (bvskill3allworkendflag == true) {
			allworkendflag = true;
			askill2allworkendflag = false;				//������
			askill4allworkendflag = false;				//������
			askill7allworkendflag = false;				//������
			askill8allworkendflag = false;				//������
			mskill2allworkendflag = false;				//������
			mskill3allworkendflag = false;				//������
			hskill2allworkendflag = false;				//������
			hskill3allworkendflag = false;				//������
			bvskill3allworkendflag = false;				//������
		}
		break;
	}
	default: {
		break;
	}
	}
}

// �ŏ��ɏo�Ă���摜
void BossScene::BossBackGroudn()
{
	// ��ʃT�C�Y�擾
	Size winSize = Director::getInstance()->getWinSize();
	//rightSize = Director::getInstance()->getVisibleSize();
	rightSize = CCDirector::sharedDirector()->getWinSize();
	//�摜�̃|�C���g���Đݒ�
	CCPoint ancharpoint = ccp(0.0f, 0.0f);		//����
	CCPoint anancharpoint = ccp(1.0f, 0.0f);	//�E��
//�w�i
	back = CCSprite::create("BackImage/ST_Boss.png");							//�w�i�̉摜�w��
	back->setPosition(ccp(rightSize.width / 2, rightSize.height / 2));			// �\�����W�w��
	this->addChild(back, backdepth);											//�ǉ�
//�e���b�v
	auto Telop = CCSprite::create("UI/UI_Terop.png");
	Telop->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
	Telop->setScaleX(1.5f);
	this->addChild(Telop, backdepth);
//�{�X
	// �{�X�̕\��
	Boss = CCSprite::create("enemy/EM_Valkyrie.png");							// �摜�w��
	Boss->setPosition(ccp(rightSize.width / 2, rightSize.height / 1.7f));		// �\�����W�w��
	this->addChild(Boss, backdepth);											// �ǉ�
	//BOSSHP�o�[
	HPboss = CCSprite::create("UI/Status/UI_Status_EMLife.png");
	HPboss->setPosition(ccp(rightSize.width / 2 - HPboss->getContentSize().width / 2,
		rightSize.height / 1.4f + HPboss->getContentSize().height / 2));
	HPboss->setAnchorPoint(ancharpoint);
	HPbar = HPboss->getTextureRect().origin;
	bosshpgaugewidth = HPboss->getContentSize().width;
	this->addChild(HPboss, middledepth);
	//������̍����o�[
	auto HPLboss = CCSprite::create("UI/Status/UI_Status_EMLost.png");
	HPLboss->setPosition(ccp(rightSize.width / 2 - HPboss->getContentSize().width / 2,
		rightSize.height / 1.4f + HPboss->getContentSize().height / 2));
	HPLboss->setAnchorPoint(ancharpoint);
	bosshpgaugewidth = HPLboss->getContentSize().width;
	this->addChild(HPLboss, backdepth);
//���m�̃X�e�[�^�X�o�[
	//�X�e�[�^�X�̃v���[�g(��Ԍ��̂��)
	PLattacker= CCSprite::create("UI/Status/UI_Status_Attacker.png");
	if (pl1frame.choicejob == ATTACKER) {
		PLattacker->setPosition(rightSize.width / 4.1f, rightSize.height / 5);
	}
	if (pl2frame.choicejob == ATTACKER) {
		PLattacker->setPosition(rightSize.width / 2, rightSize.height / 5);
	}
	if (pl3frame.choicejob == ATTACKER) {
		PLattacker->setPosition(rightSize.width / 1.32f, rightSize.height / 5);
	}
	PLattacker->setScaleX(0.6f);
	PLattacker->setScaleY(0.8f);
	this->addChild(PLattacker, backdepth);
	//HP�o�[
	attackerHP = CCSprite::create("UI/Status/UI_Status_Life.png");
	if (pl1frame.choicejob == ATTACKER) {
		attackerHP->setPosition(ccp(rightSize.width / 6.325f, rightSize.height / 5.735f));
	}
	if (pl2frame.choicejob == ATTACKER) {
		attackerHP->setPosition(ccp(rightSize.width / 2.42f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == ATTACKER) {
		attackerHP->setPosition(ccp(rightSize.width / 1.489f, rightSize.height / 5.73f));
	}
	attackerHP->setAnchorPoint(ancharpoint);
	attackerHP->setScaleX(0.6f);
	attackerHP->setScaleY(0.8f);
	HPbar = attackerHP->getTextureRect().origin;
	attackerhpgaugewidth = attackerHP->getContentSize().width;
	this->addChild(attackerHP, prevdepth);
	//MANA�o�[
	attackerMN = CCSprite::create("UI/Status/UI_Status_Mana.png");
	if (pl1frame.choicejob == ATTACKER) {
		attackerMN->setPosition(ccp(rightSize.width / 3.6f, rightSize.height / 5.73f));
	}
	if (pl2frame.choicejob == ATTACKER) {
		attackerMN->setPosition(ccp(rightSize.width / 1.87f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == ATTACKER) {
		attackerMN->setPosition(ccp(rightSize.width / 1.265f, rightSize.height / 5.73f));
	}
	attackerMN->setAnchorPoint(ancharpoint);
	attackerMN->setScaleX(0.6f);
	attackerMN->setScaleY(0.8f);
	MNbar = attackerMN->getTextureRect().origin;
	attackermngaugewidth = attackerMN->getContentSize().width;
	this->addChild(attackerMN, prevdepth);
	//���mHP�\�L
	//���l���ς�镔��
	attackerhpal = LabelTTF::create(std::to_string(attacker.hp), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == ATTACKER) {
		attackerhpal->setPosition(rightSize.width / 5.0f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == ATTACKER) {
		attackerhpal->setPosition(rightSize.width / 2.18f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == ATTACKER) {
		attackerhpal->setPosition(rightSize.width / 1.39f, rightSize.height / 6.7f);
	}
	attackerhpal->setColor(ccc3(150,255,255));			//���F
	attackerhpal->setAnchorPoint(anancharpoint);
	this->addChild(attackerhpal, prevdepth);
	//HP�̍ő�l
	attackerhpmaxal = LabelTTF::create("/" + std::to_string(attacker.hpmax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == ATTACKER) {
		attackerhpmaxal->setPosition(rightSize.width / 4.5f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == ATTACKER) {
		attackerhpmaxal->setPosition(rightSize.width / 2.08f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == ATTACKER) {
		attackerhpmaxal->setPosition(rightSize.width / 1.35f, rightSize.height / 6.3f);
	}
	this->addChild(attackerhpmaxal, prevdepth);
	//���mMANA�\�L
	//���l���ς�镔��
	attackermnal = LabelTTF::create(std::to_string(attacker.mana), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == ATTACKER) {
		attackermnal->setPosition(rightSize.width / 3.22f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == ATTACKER) {
		attackermnal->setPosition(rightSize.width / 1.77f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == ATTACKER) {
		attackermnal->setPosition(rightSize.width / 1.21f, rightSize.height / 6.7f);
	}
	attackermnal->setColor(ccc3(192, 136, 255));			//��
	attackermnal->setAnchorPoint(anancharpoint);
	this->addChild(attackermnal, prevdepth);
	//MP�̍ő�l
	attackermnmaxal = LabelTTF::create("/" + std::to_string(attacker.manamax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == ATTACKER) {
		attackermnmaxal->setPosition(rightSize.width / 3.0f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == ATTACKER) {
		attackermnmaxal->setPosition(rightSize.width / 1.7f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == ATTACKER) {
		attackermnmaxal->setPosition(rightSize.width / 1.18f, rightSize.height / 6.3f);
	}
	this->addChild(attackermnmaxal, prevdepth);
//�R�m�̃X�e�[�^�X�o�[
	//�X�e�[�^�X�̃v���[�g(��Ԍ��̂��)
	PLshield = CCSprite::create("UI/Status/UI_Status_Shield.png");
	if (pl1frame.choicejob == SHIELD) {
		PLshield->setPosition(rightSize.width / 4.1f, rightSize.height / 5);
	}
	if (pl2frame.choicejob == SHIELD) {
		PLshield->setPosition(rightSize.width / 2, rightSize.height / 5);
	}
	if (pl3frame.choicejob == SHIELD) {
		PLshield->setPosition(rightSize.width / 1.32f, rightSize.height / 5);
	}
	PLshield->setScaleX(0.6f);
	PLshield->setScaleY(0.8f);
	this->addChild(PLshield, backdepth);
	//HP�o�[
	shieldHP = CCSprite::create("UI/Status/UI_Status_Life.png");
	if (pl1frame.choicejob == SHIELD) {
		shieldHP->setPosition(ccp(rightSize.width / 6.325f, rightSize.height / 5.735f));
	}
	if (pl2frame.choicejob == SHIELD) {
		shieldHP->setPosition(ccp(rightSize.width / 2.42f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == SHIELD) {
		shieldHP->setPosition(ccp(rightSize.width / 1.489f, rightSize.height / 5.73f));
	}
	shieldHP->setAnchorPoint(ancharpoint);
	shieldHP->setScaleX(0.6f);
	shieldHP->setScaleY(0.8f);
	HPbar = shieldHP->getTextureRect().origin;
	shieldhpgaugewidth = shieldHP->getContentSize().width;
	this->addChild(shieldHP, prevdepth);
	//MANA�o�[
	shieldMN = CCSprite::create("UI/Status/UI_Status_Mana.png");
	if (pl1frame.choicejob == SHIELD) {
		shieldMN->setPosition(ccp(rightSize.width / 3.6f, rightSize.height / 5.73f));
	}
	if (pl2frame.choicejob == SHIELD) {
		shieldMN->setPosition(ccp(rightSize.width / 1.87f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == SHIELD) {
		shieldMN->setPosition(ccp(rightSize.width / 1.265f, rightSize.height / 5.73f));
	}
	shieldMN->setAnchorPoint(ancharpoint);
	shieldMN->setScaleX(0.6f);
	shieldMN->setScaleY(0.8f);
	MNbar = shieldMN->getTextureRect().origin;
	shieldmngaugewidth = shieldMN->getContentSize().width;
	this->addChild(shieldMN, prevdepth);
	//�R�mHP�\�L
	//���l���ς�镔��
	shieldhpal = LabelTTF::create(std::to_string(shield.hp), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == SHIELD) {
		shieldhpal->setPosition(rightSize.width / 5.0f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == SHIELD) {
		shieldhpal->setPosition(rightSize.width / 2.18f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == SHIELD) {
		shieldhpal->setPosition(rightSize.width / 1.39f, rightSize.height / 6.7f);
	}
	shieldhpal->setColor(ccc3(150, 255, 255));			//���F
	shieldhpal->setAnchorPoint(anancharpoint);
	this->addChild(shieldhpal, prevdepth);
	//HP�̍ő�l
	shieldhpmaxal = LabelTTF::create("/" + std::to_string(shield.hpmax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == SHIELD) {
		shieldhpmaxal->setPosition(rightSize.width / 4.5f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == SHIELD) {
		shieldhpmaxal->setPosition(rightSize.width / 2.08f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == SHIELD) {
		shieldhpmaxal->setPosition(rightSize.width / 1.35f, rightSize.height / 6.3f);
	}
	this->addChild(shieldhpmaxal, prevdepth);
	//�R�mMANA�\�L
	//���l���ς�镔��
	shieldmnal = LabelTTF::create(std::to_string(shield.mana), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == SHIELD) {
		shieldmnal->setPosition(rightSize.width / 3.22f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == SHIELD) {
		shieldmnal->setPosition(rightSize.width / 1.77f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == SHIELD) {
		shieldmnal->setPosition(rightSize.width / 1.21f, rightSize.height / 6.7f);
	}
	shieldmnal->setColor(ccc3(192, 136, 255));			//��
	shieldmnal->setAnchorPoint(anancharpoint);
	this->addChild(shieldmnal, prevdepth);
	//MP�̍ő�l
	shieldmnmaxal = LabelTTF::create("/" + std::to_string(shield.manamax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == SHIELD) {
		shieldmnmaxal->setPosition(rightSize.width / 3.0f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == SHIELD) {
		shieldmnmaxal->setPosition(rightSize.width / 1.7f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == SHIELD) {
		shieldmnmaxal->setPosition(rightSize.width / 1.18f, rightSize.height / 6.3f);
	}
	this->addChild(shieldmnmaxal, prevdepth);
//���p�t�̃X�e�[�^�X�o�[
	//�X�e�[�^�X�v���[�g(��Ԍ��̂��)
	PLmagic = CCSprite::create("UI/Status/UI_Status_Magic.png");					//�摜�w��
	if (pl1frame.choicejob == MAGIC) {
		PLmagic->setPosition(rightSize.width / 4.1f, rightSize.height / 5);
	}
	if (pl2frame.choicejob == MAGIC) {
		PLmagic->setPosition(rightSize.width / 2, rightSize.height / 5);
	}
	if (pl3frame.choicejob == MAGIC) {
		PLmagic->setPosition(rightSize.width / 1.32f, rightSize.height / 5);
	}
	PLmagic->setScaleX(0.6f);														//�傫���ύX
	PLmagic->setScaleY(0.8f);
	this->addChild(PLmagic, backdepth);											//�ǉ�
	//HP�o�[																	//HP�o�[
	magicHP = CCSprite::create("UI/Status/UI_Status_Life.png");
	if (pl1frame.choicejob == MAGIC) {
		magicHP->setPosition(ccp(rightSize.width / 6.325f, rightSize.height / 5.735f));
	}
	if (pl2frame.choicejob == MAGIC) {
		magicHP->setPosition(ccp(rightSize.width / 2.42f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == MAGIC) {
		magicHP->setPosition(ccp(rightSize.width / 1.489f, rightSize.height / 5.73f));
	}
	magicHP->setAnchorPoint(ancharpoint);
	magicHP->setScaleX(0.6f);
	magicHP->setScaleY(0.8f);
	HPbar = magicHP->getTextureRect().origin;
	healerhpgaugewidth = magicHP->getContentSize().width;
	this->addChild(magicHP, prevdepth);
	//MANA�o�[
	magicMN = CCSprite::create("UI/Status/UI_Status_Mana.png");
	if (pl1frame.choicejob == MAGIC) {
		magicMN->setPosition(ccp(rightSize.width / 3.6f, rightSize.height / 5.73f));
	}
	if (pl2frame.choicejob == MAGIC) {
		magicMN->setPosition(ccp(rightSize.width / 1.87f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == MAGIC) {
		magicMN->setPosition(ccp(rightSize.width / 1.265f, rightSize.height / 5.73f));
	}
	magicMN->setAnchorPoint(ancharpoint);
	magicMN->setScaleX(0.6f);
	magicMN->setScaleY(0.8f);
	MNbar = magicMN->getTextureRect().origin;
	healermngaugewidth = magicMN->getContentSize().width;
	this->addChild(magicMN, prevdepth);
	//���p�tHP�\�L
	//���l���ς�镔��
	magichpal = LabelTTF::create(std::to_string(magic.hp), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == MAGIC) {
		magichpal->setPosition(rightSize.width / 5.0f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == MAGIC) {
		magichpal->setPosition(rightSize.width / 2.18f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == MAGIC) {
		magichpal->setPosition(rightSize.width / 1.39f, rightSize.height / 6.7f);
	}
	magichpal->setColor(ccc3(150, 255, 255));
	magichpal->setAnchorPoint(anancharpoint);
	this->addChild(magichpal, prevdepth);
	//HP�̍ő�l
	magichpmaxal = LabelTTF::create("/" + std::to_string(magic.hpmax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == MAGIC) {
		magichpmaxal->setPosition(rightSize.width / 4.5f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == MAGIC) {
		magichpmaxal->setPosition(rightSize.width / 2.08f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == MAGIC) {
		magichpmaxal->setPosition(rightSize.width / 1.35f, rightSize.height / 6.3f);
	}
	this->addChild(magichpmaxal, prevdepth);
	//���p�tMANA�\�L
	//���l���ς�镔��
	magicmnal = LabelTTF::create(std::to_string(magic.mana), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == MAGIC) {
		magicmnal->setPosition(rightSize.width / 3.22f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == MAGIC) {
		magicmnal->setPosition(rightSize.width / 1.77f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == MAGIC) {
		magicmnal->setPosition(rightSize.width / 1.21f, rightSize.height / 6.7f);
	}
	magicmnal->setColor(ccc3(192, 136, 255));
	magicmnal->setAnchorPoint(anancharpoint);
	this->addChild(magicmnal, prevdepth);
	//MP�̍ő�l
	magicmnmaxal = LabelTTF::create("/" + std::to_string(magic.manamax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == MAGIC) {
		magicmnmaxal->setPosition(rightSize.width / 3.0f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == MAGIC) {
		magicmnmaxal->setPosition(rightSize.width / 1.7f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == MAGIC) {
		magicmnmaxal->setPosition(rightSize.width / 1.18f, rightSize.height / 6.3f);
	}
	this->addChild(magicmnmaxal, prevdepth);
//���E�҂̃X�e�[�^�X�o�[
	////�X�e�[�^�X�̃v���[�g(��Ԍ��̂��)
	PLhealer = CCSprite::create("UI/Status/UI_Status_Healer.png");					//�摜�w��
	if (pl1frame.choicejob == HEALER) {
		PLhealer->setPosition(rightSize.width / 4.1f, rightSize.height / 5);
	}
	if (pl2frame.choicejob == HEALER) {
		PLhealer->setPosition(rightSize.width / 2, rightSize.height / 5);
	}
	if (pl3frame.choicejob == HEALER) {
		PLhealer->setPosition(rightSize.width / 1.32f, rightSize.height / 5);
	}
	PLhealer->setScaleX(0.6f);														//�傫���ύX
	PLhealer->setScaleY(0.8f);
	this->addChild(PLhealer, backdepth);											//�ǉ�
																					//HP�o�[
	healerHP = CCSprite::create("UI/Status/UI_Status_Life.png");
	if (pl1frame.choicejob == HEALER) {
		healerHP->setPosition(ccp(rightSize.width / 6.325f, rightSize.height / 5.735f));
	}
	if (pl2frame.choicejob == HEALER) {
		healerHP->setPosition(ccp(rightSize.width / 2.42f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == HEALER) {
		healerHP->setPosition(ccp(rightSize.width / 1.489f, rightSize.height / 5.73f));
	}
	healerHP->setAnchorPoint(ancharpoint);
	healerHP->setScaleX(0.6f);
	healerHP->setScaleY(0.8f);
	HPbar = healerHP->getTextureRect().origin;
	healerhpgaugewidth = healerHP->getContentSize().width;
	this->addChild(healerHP, prevdepth);
	//MANA�o�[
	healerMN = CCSprite::create("UI/Status/UI_Status_Mana.png");
	if (pl1frame.choicejob == HEALER) {
		healerMN->setPosition(ccp(rightSize.width / 3.6f, rightSize.height / 5.73f));
	}
	if (pl2frame.choicejob == HEALER) {
		healerMN->setPosition(ccp(rightSize.width / 1.87f, rightSize.height / 5.735f));
	}
	if (pl3frame.choicejob == HEALER) {
		healerMN->setPosition(ccp(rightSize.width / 1.265f, rightSize.height / 5.73f));
	}
	healerMN->setAnchorPoint(ancharpoint);
	healerMN->setScaleX(0.6f);
	healerMN->setScaleY(0.8f);
	MNbar = healerMN->getTextureRect().origin;
	healermngaugewidth = healerMN->getContentSize().width;
	this->addChild(healerMN, prevdepth);
	//���E��HP�\�L
	//���l���ς�镔��
	healerhpal = LabelTTF::create(std::to_string(healer.hp), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == HEALER) {
		healerhpal->setPosition(rightSize.width / 5.0f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == HEALER) {
		healerhpal->setPosition(rightSize.width / 2.18f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == HEALER) {
		healerhpal->setPosition(rightSize.width / 1.39f, rightSize.height / 6.7f);
	}
	healerhpal->setColor(ccc3(150, 255, 255));
	healerhpal->setAnchorPoint(anancharpoint);
	this->addChild(healerhpal, prevdepth);
	//HP�̍ő�l
	healerhpmaxal = LabelTTF::create("/" + std::to_string(healer.hpmax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == HEALER) {
		healerhpmaxal->setPosition(rightSize.width / 4.5f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == HEALER) {
		healerhpmaxal->setPosition(rightSize.width / 2.08f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == HEALER) {
		healerhpmaxal->setPosition(rightSize.width / 1.35f, rightSize.height / 6.3f);
	}
	this->addChild(healerhpmaxal, prevdepth);
	//���E��MANA�\�L
	//���l���ς�镔��
	healermnal = LabelTTF::create(std::to_string(healer.mana), "HGRSGU.TTC", fontsizeM);
	if (pl1frame.choicejob == HEALER) {
		healermnal->setPosition(rightSize.width / 3.22f, rightSize.height / 6.7f);
	}
	if (pl2frame.choicejob == HEALER) {
		healermnal->setPosition(rightSize.width / 1.77f, rightSize.height / 6.7f);
	}
	if (pl3frame.choicejob == HEALER) {
		healermnal->setPosition(rightSize.width / 1.21f, rightSize.height / 6.7f);
	}
	healermnal->setColor(ccc3(192, 136, 255));
	healermnal->setAnchorPoint(anancharpoint);
	this->addChild(healermnal, prevdepth);
	//MP�̍ő�l
	healermnmaxal = LabelTTF::create("/" + std::to_string(healer.manamax), "HGRSGU.TTC", fontsizeS);
	if (pl1frame.choicejob == HEALER) {
		healermnmaxal->setPosition(rightSize.width / 3.0f, rightSize.height / 6.3f);
	}
	if (pl2frame.choicejob == HEALER) {
		healermnmaxal->setPosition(rightSize.width / 1.7f, rightSize.height / 6.3f);
	}
	if (pl3frame.choicejob == HEALER) {
		healermnmaxal->setPosition(rightSize.width / 1.18f, rightSize.height / 6.3f);
	}
	this->addChild(healermnmaxal, prevdepth);
}

// ��ʑJ��
void BossScene::pushStart(Ref * pSender)
{
	CCLOG("Push�{�^��");

	// �J�ڍ�̉�ʂ�ݽ�ݽ
	Scene *pScene = GameClear::createScene();							
	// 0.6�b�����Ď���ʂɑJ��(����,�J�ڐ�,�F(�I�v�V����))
	TransitionFade *transition = TransitionFade::create(0.6f, pScene);
	// �J�ڎ��s �A�j���[�V����
	Director::getInstance()->replaceScene(transition);
}

//�{�^�����������Ƃ�
bool BossScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {
	return true;
}

//�{�^���������ė������Ƃ�
void BossScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
	if (battle == CHOICE) {
		//���@
		AttackButton1->setVisible(true);
		SkillButton1->setVisible(true);
	}
}

void BossScene::onTouchMove(cocos2d::Touch* touch, cocos2d::Event* event) {

}

void BossScene::onTouchCansell(cocos2d::Touch* touch, cocos2d::Event* event) {
	onTouchEnded(touch, event);
}