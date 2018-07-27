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

// 初期化
bool BossScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	//キャラ枠１（アタッカーの場合）
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
	pl1frame.choicejob = HEALER;		//剣士
	//キャラ枠2（ヒーラーな場合）
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
	pl2frame.choicejob = SHIELD;		//聖職者
	//キャラ枠3（マジックの場合）
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
	pl3frame.choicejob = ATTACKER;		//魔術師

	//剣士
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
	//騎士
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
	//魔術師
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
	//聖職者
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
	//ヴァルキリー
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

	//初期設定
	turn = PLAYER;			//誰のターン？
	battle = START;			//バトル
	choices = CHAR1;		//コマンドを選ぶ最初のキャラ
	bsact = PICK;			//ボスの動き
	job = NON;				//キャラ選択
	bufft = ASKILL2T;		//バフ・デバフのターン処理の最初
	
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();

	// ボタン配置
	// 通常時,押した時
	// 押した時のｱｸｼｮﾝ
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(BossScene::pushStart, this));

	// ボタンの配置
	startButton->setPosition(Point(winSize.width / 16, winSize.height / 2));
	// メニュー作成(自動obj)
	auto menu = Menu::create(startButton, NULL);
	menu->setPosition(Point::ZERO);
	// 追加
	this->addChild(menu, backdepth);

	//タッチモード設定
	this->setTouchMode(kCCTouchesOneByOne);
	this->setTouchEnabled(true);

	// バックグランド
	BossBackGroudn();

	//アップデート更新
	this->scheduleUpdate();

	return true;
}

//ボス戦の流れの処理
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
		//ステータスアップやダウンなどを管理するところ
		case BossScene::WAIT: {
			gameflame++;					//ゲームフレームを進める			
			Skillturn();					//スキルの効果が切れたかどうかを判断するための処理

			//死亡設定
			//剣士のキャラのHPが0になったら
			if (pl1frame.choicejob == ATTACKER || pl2frame.choicejob == ATTACKER || pl3frame.choicejob == ATTACKER) {
				if (attacker.hp == 0) {
					attacker.deathflag = true;
				}
			}
			//騎士のキャラのHPが0になったら
			if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD || pl3frame.choicejob == SHIELD) {
				if (shield.hp == 0) {
					shield.deathflag = true;
				}
			}
			//魔術師のキャラのHPが0になったら
			if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC || pl3frame.choicejob == MAGIC) {
				if (magic.hp == 0) {
					magic.deathflag = true;
				}
			}
			//聖職者のキャラのHPが0になったら
			if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER || pl3frame.choicejob == HEALER) {
				if (healer.hp == 0) {
					healer.deathflag = true;
				}
			}
				
			//前準備
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
			
			//HPがゼロになったら画面遷移
			//剣士がいないとき
			if (shield.deathflag == true && magic.deathflag == true && healer.deathflag == true) {
				Scene *pScene = GameClear::createScene();							// 遷移策の画面をｲﾝｽﾀﾝｽ
				TransitionFade *transition = TransitionFade::create(1.0, pScene);	// 0.6秒かけて次画面に遷移(時間,遷移先,色(オプション))
				Director::getInstance()->replaceScene(transition);					// 遷移実行 アニメーション
			}
			//騎士がいないとき
			else if (attacker.deathflag == true && magic.deathflag == true && healer.deathflag == true) {
				Scene *pScene = GameClear::createScene();							// 遷移策の画面をｲﾝｽﾀﾝｽ
				TransitionFade *transition = TransitionFade::create(1.0, pScene);	// 0.6秒かけて次画面に遷移(時間,遷移先,色(オプション))
				Director::getInstance()->replaceScene(transition);					// 遷移実行 アニメーション
			}
			//魔術師がいないとき
			else if (attacker.deathflag == true && shield.deathflag == true && healer.deathflag == true) {
				Scene *pScene = GameClear::createScene();							// 遷移策の画面をｲﾝｽﾀﾝｽ
				TransitionFade *transition = TransitionFade::create(1.0, pScene);	// 0.6秒かけて次画面に遷移(時間,遷移先,色(オプション))
				Director::getInstance()->replaceScene(transition);					// 遷移実行 アニメーション
			}
			//聖職者がいないとき
			else if (attacker.deathflag == true && shield.deathflag == true && magic.deathflag == true) {
				Scene *pScene = GameClear::createScene();							// 遷移策の画面をｲﾝｽﾀﾝｽ
				TransitionFade *transition = TransitionFade::create(1.0, pScene);	// 0.6秒かけて次画面に遷移(時間,遷移先,色(オプション))
				Director::getInstance()->replaceScene(transition);					// 遷移実行 アニメーション
			}

			if (allworkendflag == true) {
				battle = CHOICE;			//選択に行く
				choices = CHAR1;			//選択を最初からに戻す
				bufft = ASKILL2T;			//最初に戻す
				gameflame = 0;				//時間を初期値に戻す
				skillflame = 0;				//スキルの時間を初期値に
				allworkendflag = false;		//元に戻しておく


				//攻撃コマンドボタン
				AttackButton1 = CCSprite::create("UI/Command/UI_Button_Attack01.png");	 //画像指定
				AttackButton1->setPosition(rightSize.width / 3, rightSize.height / 2.1f);//配置場所
				this->addChild(AttackButton1, middledepth, attackbuttonaI);				//追加		

				//攻撃コマンドボタン(押されているとき)
				AttackButton2 = CCSprite::create("UI/Command/UI_Button_Attack02.png");	 //画像指定
				AttackButton2->setPosition(rightSize.width / 3, rightSize.height / 2.1f);//配置場所
				this->addChild(AttackButton2, backdepth, attackbuttonbI);				//追加

				//スキルコマンドボタン
				SkillButton1 = CCSprite::create("UI/Command/UI_Button_Skill01.png");	//画像指定
				SkillButton1->setPosition(rightSize.width / 3, rightSize.height / 2.7f);//配置場所
				this->addChild(SkillButton1, middledepth, skillbuttonaI);				//追加

				//スキルコマンドボタン(押されているとき)
				SkillButton2 = CCSprite::create("UI/Command/UI_Button_Skill02.png");	//画像指定
				SkillButton2->setPosition(rightSize.width / 3, rightSize.height / 2.7f);//配置場所
				this->addChild(SkillButton2, backdepth, skillbuttonbI);						//追加

				//PLTURN(右上)															
				plturn = CCSprite::create("Description/PL.png");						//配置文字
				plturn->setPosition(rightSize.width / 1.1f, rightSize.height / 1.25f);	//場所配置
				this->addChild(plturn, backdepth, playertrunI);							//追加
			}
			break;
		}
		//プレイヤーが何のコマンドを選択するかを決める
		case BossScene::CHOICE: {
			// 画面サイズ取得。
			Size visibleSize = Director::getInstance()->getVisibleSize();
			//タッチイベント取得
			auto Atouchget = EventListenerTouchOneByOne::create();	//アタックボタン
			auto S1touchget = EventListenerTouchOneByOne::create();	//スキルボタン

			choicetime++;			//ボタンが連続で押されないようにするための処理
			//タッチ処理
			auto Abutton = AttackButton1;
			auto Sbutton = SkillButton1;

			//アタックボタン
			Atouchget->onTouchBegan = [this, visibleSize, Abutton](Touch* touch, Event* event) {
				Vec2 point1 = touch->getLocation();					//タッチしたポイント。
				Rect rectButton1 = Abutton->getBoundingBox();		//ボタン画像の範囲。
				switch (choices) {
				//キャラ1
				case BossScene::CHAR1: {
					if (!(pl1 == PL1DEATH)) {
						if (choicetime > flame15) {
							//ボタン画像の範囲内をタッチした場合。
							if (rectButton1.containsPoint(point1)) {
								AttackButton1->setVisible(false);		//上のボタンを消す
								pl1 = PL1ATTACK;						//アタックにする
								this->removeChildByTag(choiceS);
								choicetime = 0;
								choices = CHAR2;						//次のキャラへ
								return true;
							}
							else {
								CCLOG("NO TOUCH");
								return false;
							}
						}
					}
					//死亡状態なら次のキャラへ
					if (pl1 == PL1DEATH) {
						this->removeChildByTag(choiceS);
						choicetime = 0;
						choices = CHAR2;						//次のキャラへ
					}
					break;
				}
				//キャラ2
				case BossScene::CHAR2: {
					if (!(pl2 == PL2DEATH)) {
						if (choicetime > flame15) {
							//ボタン画像の範囲内をタッチした場合。
							if (rectButton1.containsPoint(point1)) {
								this->removeChildByTag(choiceS);
								AttackButton1->setVisible(false);	//上のボタンを消す
								pl2 = PL2ATTACK;					//アタックにする
								choicetime = 0;
								choices = CHAR3;					//次のキャラへ
								return true;
							}
							else {
								CCLOG("NO TOUCH");
								return false;
							}
						}
					}
					//死亡状態ならそのまま次のキャラへ
					if (pl2 == PL2DEATH) {
						this->removeChildByTag(choiceS);
						choicetime = 0;
						choices = CHAR3;							//次のキャラへ
					}
					break;
				}
				 //キャラ3
				case BossScene::CHAR3: {
					if (!(pl3 == PL3DEATH)) {
						if (choicetime > flame15) {
							//ボタン画像の範囲内をタッチした場合
							if (rectButton1.containsPoint(point1)) {
								pick_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(プレイヤーのキャラを選択)
								act_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(ボスの動く回数)
								decide_rnd = random(rndmin, rndmax);	//指定した範囲内の乱数を取得(ボスの動き)
								skill_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(スキル)
								state = true;							//動ける状態にする
								Abutton->removeFromParentAndCleanup(true);//コマンドボタン(attack)を消す
								this->removeChildByTag(attackbuttonbI);
								this->removeChildByTag(skillbuttonaI);
								this->removeChildByTag(skillbuttonbI);
								this->removeChildByTag(choiceS);
								pl3 = PL3ATTACK;						//アタックにする
								choicetime = 0;
								battle = ACTION;						//エフェクトなど
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
						pick_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(プレイヤーのキャラを選択)
						act_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(ボスの動く回数)
						decide_rnd = random(rndmin, rndmax);	//指定した範囲内の乱数を取得(ボスの動き)
						skill_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(スキル)
						state = true;							//動ける状態にする
						Abutton->removeFromParentAndCleanup(true);//コマンドボタン(attack)を消す
						this->removeChildByTag(attackbuttonbI);
						this->removeChildByTag(skillbuttonaI);
						this->removeChildByTag(skillbuttonbI);
						this->removeChildByTag(choiceS);
						choicetime = 0;
						battle = ACTION;						//エフェクトなど
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
			//スキルボタン
			S1touchget->onTouchBegan = [this, visibleSize, Sbutton](Touch* touch, Event* event) {
				Vec2 point2 = touch->getLocation();								//タッチしたポイント。
				Rect rectButton1 = Sbutton->getBoundingBox();					//ボタン画像の範囲。
				switch (choices) {
					//キャラ1
				case BossScene::CHAR1: {
					if (!(pl1 == PL1DEATH)) {
						if (choicetime > flame15) {
							//ボタン画像の範囲内をタッチした場合。
							if (rectButton1.containsPoint(point2)) {
								SkillButton1->setVisible(false);					//上のボタンを消す
								pl1 = PL1SKILL;										//スキルを使う
								//PL1の職業にあったスキルを使う
								if (pl1frame.choicejob == ATTACKER)askill = ASKILL5;	//剣士のスキル
								if (pl1frame.choicejob == SHIELD)sskill = SSKILL1;	//騎士のスキル
								if (pl1frame.choicejob == MAGIC)mskill = MSKILL1;	//魔術師のスキル
								if (pl1frame.choicejob == HEALER)hskill = HSKILL4;	//聖職者のスキル
								this->removeChildByTag(choiceS);

								//騎士の選択系スキルだった場合
								if (pl1frame.choicejob == SHIELD) {
									if (sskill == SSKILL4) {
										choices = CHOICETIME;
										choicetime = 0;
										this->removeChildByTag(choiceS);
									}
								}
								//魔術師の選択系スキルの場合
								//聖職者の単体スキル系統だった場合など
								if (pl1frame.choicejob == HEALER) {
									//聖職者の回復系スキルの回復量を決める
									if (hskill == HSKILL4) {
										recovery_rnd = random(recoverylittlemin, recoverylittlemax);
									}
									else if (hskill == HSKILL5) {
										recovery_rnd = random(recoverylargemin, recoverylargemax);
									}
									else if (hskill == HSKILL6) {
										recovery_rnd = random(recoverymediummin, recoverymediummax);
									}
									//聖職者の単体選択系スキルだった場合、回復する相手を選ぶ
									if (hskill == HSKILL1 || hskill == HSKILL4
										|| hskill == HSKILL5 || hskill == HSKILL8) {
										choices = CHOICETIME;
										choicetime = 0;
										this->removeChildByTag(choiceS);
									}
								}
								//単体選択系のスキルじゃない場合
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
									   //キャラ2
				case BossScene::CHAR2: {
					if (!(pl2 == PL2DEATH)) {
						if (choicetime > flame15) {
							//ボタン画像の範囲内をタッチした場合。
							if (rectButton1.containsPoint(point2)) {
								SkillButton1->setVisible(false);					//上のボタンを消す
								pl2 = PL2SKILL;										//スキル使う
								//PL2の職業にあったスキルを使う
								if (pl2frame.choicejob == ATTACKER)askill = ASKILL2;//剣士のスキル
								if (pl2frame.choicejob == SHIELD)sskill = SSKILL4;	//騎士のスキル
								if (pl2frame.choicejob == MAGIC)mskill = MSKILL3;	//魔術師のスキル
								if (pl2frame.choicejob == HEALER)hskill = HSKILL4;	//聖職者のスキル

								//騎士の選択系スキルだった場合
								if (pl2frame.choicejob == SHIELD) {
									if (sskill == SSKILL4) {
										choices = CHOICETIME;
										choicetime = 0;
										this->removeChildByTag(choiceS);
									}
								}
								//聖職者の単体スキル系統だった場合など
								if (pl2frame.choicejob == HEALER) {
									//聖職者の回復系スキルの回復量を決める
									if (hskill == HSKILL4) {
										recovery_rnd = random(recoverylittlemin, recoverylittlemax);
									}
									else if (hskill == HSKILL5) {
										recovery_rnd = random(recoverylargemin, recoverylargemax);
									}
									else if (hskill == HSKILL6) {
										recovery_rnd = random(recoverymediummin, recoverymediummax);
									}
									//聖職者の単体選択系スキルだった場合、回復する相手を選ぶ
									if (hskill == HSKILL1 || hskill == HSKILL4
										|| hskill == HSKILL5 || hskill == HSKILL8) {
										choices = CHOICETIME;
										choicetime = 0;
										this->removeChildByTag(choiceS);
									}
								}
								//単体選択系のスキルじゃない場合
								if (!(pl2frame.choicejob == HEALER && hskill == HSKILL1 || hskill == HSKILL4 || hskill == HSKILL5 || hskill == HSKILL8)) {
									if (!(pl2frame.choicejob == SHIELD && sskill == SSKILL4)) {
										if (!(pl2frame.choicejob == MAGIC && mskill == MSKILL7)) {
											choices = CHAR3;			//次のキャラへ
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
						choices = CHAR3;			//次のキャラへ
						choicetime = 0;
						choiceendflag = false;
						this->removeChildByTag(choiceS);
					}
					break;
				}
									   //キャラ3
				case BossScene::CHAR3: {
					if (!(pl3 == PL3DEATH)) {
						if (choicetime > flame15) {
							//ボタン画像の範囲内をタッチした場合。
							if (rectButton1.containsPoint(point2)) {
								pick_rnd = random(rndmin, rndmax);			//指定した範囲内の乱数を取得(プレイヤーのキャラを選択)
								act_rnd = random(rndmin, rndmax);			//指定した範囲内の乱数を取得(ボスの動く回数)
								decide_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(ボスの動き)
								skill_rnd = random(rndmin, rndmax);			//指定した範囲内の乱数を取得(スキル)
								state = true;								//動ける状態にする
								Sbutton->removeFromParentAndCleanup(true);	//コマンドボタン(attack)を消す
								this->removeChildByTag(attackbuttonaI);
								this->removeChildByTag(attackbuttonbI);
								this->removeChildByTag(skillbuttonbI);
								pl3 = PL3SKILL;										//スキルにする
								//PL3の職業にあったスキルを使う
								if (pl3frame.choicejob == ATTACKER)askill = ASKILL1;//剣士のスキル
								if (pl3frame.choicejob == SHIELD)sskill = SSKILL3;	//騎士のスキル
								if (pl3frame.choicejob == MAGIC)mskill = MSKILL1;	//魔術師のスキル
								if (pl3frame.choicejob == HEALER)hskill = HSKILL1;	//聖職者のスキル

								//騎士の選択系スキルだった場合
								if (pl3frame.choicejob == SHIELD && sskill == SSKILL4) {
									choices = CHOICETIME;
									choicetime = 0;
									this->removeChildByTag(choiceS);
								}
								//聖職者の単体スキル系統だった場合など
								if (pl3frame.choicejob == HEALER) {
									//聖職者の回復系スキルの回復量を決める
									if (hskill == HSKILL4) {
										recovery_rnd = random(recoverylittlemin, recoverylittlemax);
									}
									else if (hskill == HSKILL5) {
										recovery_rnd = random(recoverylargemin, recoverylargemax);
									}
									else if (hskill == HSKILL6) {
										recovery_rnd = random(recoverymediummin, recoverymediummax);
									}
									//聖職者の単体選択系スキルだった場合、回復する相手を選ぶ
									if (hskill == HSKILL1 || hskill == HSKILL4
										|| hskill == HSKILL5 || hskill == HSKILL8) {
										choices = CHOICETIME;
										choicetime = 0;
										this->removeChildByTag(choiceS);
									}
								}
								//単体選択系のスキルじゃない場合
								if (!(pl3frame.choicejob == HEALER && hskill == HSKILL1 || hskill == HSKILL4 || hskill == HSKILL5 || hskill == HSKILL8)) {
									if (!(pl3frame.choicejob == SHIELD && sskill == SSKILL4)) {
										if (!(pl3frame.choicejob == MAGIC && mskill == MSKILL7)) {
											choicetime = 0;										//タイムを0
											battle = ACTION;									//エフェクトなどを担当
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
						choicetime = 0;										//タイムを0
						battle = ACTION;									//エフェクトなどを担当
						choices = CHAR1;
						choiceendflag = false;
						this->removeChildByTag(choiceS);
					}
					break;
				}
									   //スキルなどでキャラを選択する所
				case BossScene::CHOICETIME: {
					//騎士の場合
					if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD || pl3frame.choicejob == SHIELD) {
						if (sskill == SSKILL4) {
							//タッチイベント取得
							auto attackerframetouch = EventListenerTouchOneByOne::create();	//剣士タッチ
							auto magicframetouch = EventListenerTouchOneByOne::create();	//魔術師タッチ
							auto healerframetouch = EventListenerTouchOneByOne::create();	//聖職者タッチ

							//タッチ処理
							auto attackerbutton = PLattacker;	//剣士
							auto magicbutton = PLmagic;			//魔術師
							auto healerbutton = PLhealer;		//聖職者

							//剣士をタッチした場合
							attackerframetouch->onTouchBegan = [this, visibleSize, attackerbutton](Touch* touch, Event* event) {
								Vec2 attackerpoint = touch->getLocation();					//タッチしたポイント。
								Rect attackerrectButton = attackerbutton->getBoundingBox();	//ボタン画像の範囲。
								if (attackerrectButton.containsPoint(attackerpoint)) {
									//PL1が騎士の場合
									if (pl1frame.choicejob == SHIELD) {
										sskillchoice = ATTACKER;
										choices = CHAR2;
										choicetime = 0;
										this->removeChildByTag(choiceplS);
									}
									//PL2が騎士の場合
									else if (pl2frame.choicejob == SHIELD) {
										sskillchoice = ATTACKER;
										choices = CHAR3;
										choicetime = 0;
										this->removeChildByTag(choiceplS);
									}
									//PL3が騎士の場合
									else if (pl3frame.choicejob == SHIELD) {
										sskillchoice = ATTACKER;
										battle = ACTION;			//エフェクトなどを担当
										choicetime = 0;				//タイムを0
										choices = CHAR1;
										choiceendflag = false;
										this->removeChildByTag(choiceplS);
									}
								}
								return true;
							};
							//魔術師をタッチした場合
							magicframetouch->onTouchBegan = [this, visibleSize, magicbutton](Touch* touch, Event* event) {
								Vec2 magicpoint = touch->getLocation();					//タッチしたポイント。
								Rect magicrectButton = magicbutton->getBoundingBox();	//ボタン画像の範囲。
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
										battle = ACTION;			//エフェクトなどを担当
										choicetime = 0;				//タイムを0
										choices = CHAR1;
										choiceendflag = false;
										this->removeChildByTag(choiceplS);
									}
								}
								return true;
							};
							//聖職者をタッチした場合
							healerframetouch->onTouchBegan = [this, visibleSize, healerbutton](Touch* touch, Event* event) {
								Vec2 healerpoint = touch->getLocation();					//タッチしたポイント。
								Rect healerrectButton = healerbutton->getBoundingBox();	//ボタン画像の範囲。
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
										battle = ACTION;			//エフェクトなどを担当
										choicetime = 0;				//タイムを0
										choices = CHAR1;
										choiceendflag = false;
										this->removeChildByTag(choiceplS);
									}
								}
								return true;
							};
							//剣士 touchget, buttonをイベント登録する。
							auto attackerdirector = Director::getInstance();
							attackerdirector->getEventDispatcher()->addEventListenerWithSceneGraphPriority(attackerframetouch, attackerbutton);
							//魔術師 touchget, buttonをイベント登録する。
							auto magicdirector = Director::getInstance();
							magicdirector->getEventDispatcher()->addEventListenerWithSceneGraphPriority(magicframetouch, magicbutton);
							//聖職者 touchget, buttonをイベント登録する。
							auto healerdirector = Director::getInstance();
							healerdirector->getEventDispatcher()->addEventListenerWithSceneGraphPriority(healerframetouch, healerbutton);
						}
					}

					//聖職者の場合
					if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER || pl3frame.choicejob == HEALER) {
						if (hskill == HSKILL1 || hskill == HSKILL4 || hskill == HSKILL5 || hskill == HSKILL8) {
							//タッチイベント取得
							auto attackerframetouch = EventListenerTouchOneByOne::create();	//剣士タッチ
							auto shieldframetouch = EventListenerTouchOneByOne::create();	//騎士タッチ
							auto magicframetouch = EventListenerTouchOneByOne::create();	//魔術師タッチ
							auto healerframetouch = EventListenerTouchOneByOne::create();	//聖職者タッチ

							//タッチ処理
							auto attackerbutton = PLattacker;	//剣士
							auto shieldbutton = PLshield;		//騎士
							auto magicbutton = PLmagic;			//魔術師
							auto healerbutton = PLhealer;		//聖職者

							//剣士をタッチした場合
							if (attacker.deathflag == false) {
								attackerframetouch->onTouchBegan = [this, visibleSize, attackerbutton](Touch* touch, Event* event) {
									Vec2 attackerpoint = touch->getLocation();					//タッチしたポイント。
									Rect attackerrectButton = attackerbutton->getBoundingBox();	//ボタン画像の範囲。
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
											battle = ACTION;			//エフェクトなどを担当
											choices = CHAR1;
											choiceendflag = false;
										}
									}
									return true;
								};
							}
							//騎士をタッチした場合
							if (shield.deathflag == false) {
								shieldframetouch->onTouchBegan = [this, visibleSize, shieldbutton](Touch* touch, Event* event) {
									Vec2 shieldpoint = touch->getLocation();				//タッチしたポイント。
									Rect shieldrectButton = shieldbutton->getBoundingBox();	//ボタン画像の範囲。
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
											battle = ACTION;			//エフェクトなどを担当
											choices = CHAR1;
											choiceendflag = false;
										}
									}
									return true;
								};
							}
							//魔術師をタッチした場合
							magicframetouch->onTouchBegan = [this, visibleSize, magicbutton](Touch* touch, Event* event) {
								Vec2 magicpoint = touch->getLocation();					//タッチしたポイント。
								Rect magicrectButton = magicbutton->getBoundingBox();	//ボタン画像の範囲。
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
										battle = ACTION;			//エフェクトなどを担当
										choices = CHAR1;
										choiceendflag = false;
									}
								}
								return true;
							};
							//聖職者をタッチした場合
							healerframetouch->onTouchBegan = [this, visibleSize, healerbutton](Touch* touch, Event* event) {
								Vec2 healerpoint = touch->getLocation();					//タッチしたポイント。
								Rect healerrectButton = healerbutton->getBoundingBox();	//ボタン画像の範囲。
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
										battle = ACTION;			//エフェクトなどを担当
										choices = CHAR1;
										choiceendflag = false;
									}
								}
								return true;
							};
							//剣士 touchget, buttonをイベント登録する。
							auto attackerdirector = Director::getInstance();
							attackerdirector->getEventDispatcher()->addEventListenerWithSceneGraphPriority(attackerframetouch, attackerbutton);
							//騎士 touchget, buttonをイベント登録する。
							auto shielddirector = Director::getInstance();
							shielddirector->getEventDispatcher()->addEventListenerWithSceneGraphPriority(shieldframetouch, shieldbutton);
							//魔術師 touchget, buttonをイベント登録する。
							auto magicdirector = Director::getInstance();
							magicdirector->getEventDispatcher()->addEventListenerWithSceneGraphPriority(magicframetouch, magicbutton);
							//聖職者 touchget, buttonをイベント登録する。
							auto healerdirector = Director::getInstance();
							healerdirector->getEventDispatcher()->addEventListenerWithSceneGraphPriority(healerframetouch, healerbutton);
						}
					}

					//選択中は色をもどす
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
			//選択するときに出る文字
			if (choicetime == flame15) {
				//初期化
				//剣士
				auto lo = CCLabelTTF::create("剣士はどうする", "HGRSGU.TTC", fontsizeL);
				lo->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				//騎士
				auto ls = CCLabelTTF::create("騎士はどうする", "HGRSGU.TTC", fontsizeL);
				ls->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				//魔術師
				auto lw = CCLabelTTF::create("魔術師はどうする", "HGRSGU.TTC", fontsizeL);
				lw->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				//聖職者
				auto ll = CCLabelTTF::create("聖職者はどうする", "HGRSGU.TTC", fontsizeL);
				ll->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

				//それぞれのPLの選択されているキャラを選ぶ
				if (choices == CHAR1) {
					if (pl1frame.choicejob == ATTACKER) {
						this->addChild(lo, backdepth, choiceS);	//剣士
					}
					else if (pl1frame.choicejob == SHIELD) {
						this->addChild(ll, backdepth, choiceS);	//騎士
					}
					else if (pl1frame.choicejob == MAGIC) {
						this->addChild(lw, backdepth, choiceS);	//魔術師
					}
					else if (pl1frame.choicejob == HEALER) {
						this->addChild(ll, backdepth, choiceS); //聖職者
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
					cho = CCLabelTTF::create("どのキャラを選択しますか", "HGRSGU.TTC", fontsizeL);
					cho->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
					this->addChild(cho, backdepth, choiceplS);
				}
			}
			//選択キャラを明確にする(選択されてないキャラは少し暗くする)
			if (choices == CHAR1) {
				//pl1frameの時
				//剣士
				if (pl1frame.choicejob == ATTACKER) {
					PLattacker->setColor(ccc3(colormax, colormax, colormax));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//騎士
				else if (pl1frame.choicejob == SHIELD) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colormax, colormax, colormax));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//魔術師
				else if (pl1frame.choicejob == MAGIC) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colormax, colormax, colormax));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//聖職者
				else if (pl1frame.choicejob == HEALER) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colormax, colormax, colormax));
				}
			}
			if (choices == CHAR2) {
				//pl2frameの時
				if (pl2frame.choicejob == ATTACKER) {
					PLattacker->setColor(ccc3(colormax, colormax, colormax));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//騎士
				else if (pl2frame.choicejob == SHIELD) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colormax, colormax, colormax));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//魔術師
				else if (pl2frame.choicejob == MAGIC) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colormax, colormax, colormax));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//聖職者
				else if (pl2frame.choicejob == HEALER) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colormax, colormax, colormax));
				}
			}
			if (choices == CHAR3) {
				//pl3frameの時
				if (pl3frame.choicejob == ATTACKER) {
					PLattacker->setColor(ccc3(colormax, colormax, colormax));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//騎士
				else if (pl3frame.choicejob == SHIELD) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colormax, colormax, colormax));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//魔術師
				else if (pl3frame.choicejob == MAGIC) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colormax, colormax, colormax));
					PLhealer->setColor(ccc3(colordown, colordown, colordown));
				}
				//聖職者
				else if (pl3frame.choicejob == HEALER) {
					PLattacker->setColor(ccc3(colordown, colordown, colordown));
					PLshield->setColor(ccc3(colordown, colordown, colordown));
					PLmagic->setColor(ccc3(colordown, colordown, colordown));
					PLhealer->setColor(ccc3(colormax, colormax, colormax));
				}
			}
			

			// touchget, buttonをイベント登録する。
			auto director = Director::getInstance();
			director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(Atouchget, Abutton);
			auto director2 = Director::getInstance();
			director2->getEventDispatcher()->addEventListenerWithSceneGraphPriority(S1touchget, Sbutton);
			break;
		}
		//プレイヤーのアクション(エフェクトなど)
		case BossScene::ACTION: {
			//プレイヤーたちの画像の色を戻す
			PLattacker->setColor(ccc3(colormax, colormax, colormax));
			PLshield->setColor(ccc3(colormax, colormax, colormax));
			PLhealer->setColor(ccc3(colormax, colormax, colormax));
			PLmagic->setColor(ccc3(colormax, colormax, colormax));

			if (state == true) {
				gameflame++;							//カウント開始
				skillflame++;							//スキルカウント開始
				PLturn();								//主な処理
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
		//初期化//

		//剣士のダメージ表示処理の初期化
		if(pl1frame.choicejob == ATTACKER){
			//剣士ダメージ表示
			attackerdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			attackerdmf->setPosition(rightSize.width / 4, rightSize.height / 5.3f);
			attackerdmf->setColor(ccc3(colormax, colormin, colormin));
			//剣士ダメージ表示のフェードアウト処理
			attackerfadeout = CCFadeOut::create(2.0f);											//何秒で消える？
			attackerfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 4, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}
		else if (pl2frame.choicejob == ATTACKER) {
			//剣士ダメージ表示
			attackerdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			attackerdmf->setPosition(rightSize.width / 2, rightSize.height / 5.3f);
			attackerdmf->setColor(ccc3(colormax, colormin, colormin));
			//剣士ダメージ表示のフェードアウト処理
			attackerfadeout = CCFadeOut::create(2.0f);											//何秒で消える？
			attackerfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 2, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}
		else if (pl3frame.choicejob == ATTACKER) {
			//剣士ダメージ表示
			attackerdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			attackerdmf->setPosition(rightSize.width / 1.3f, rightSize.height / 5.3f);
			attackerdmf->setColor(ccc3(colormax, colormin, colormin));
			//剣士ダメージ表示のフェードアウト処理
			attackerfadeout = CCFadeOut::create(2.0f);												//何秒で消える？
			attackerfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 1.3f, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}

		//騎士のダメージ表示処理の初期化
		if (pl1frame.choicejob == SHIELD) {
			//騎士ダメージ表示
			shielddmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			shielddmf->setPosition(rightSize.width / 4, rightSize.height / 5.3f);
			shielddmf->setColor(ccc3(colormax, colormin, colormin));
			//騎士ダメージ表示のフェードアウト処理
			shieldfadeout = CCFadeOut::create(2.0f);									//何秒で消える？
			shieldfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 4, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}
		else if (pl2frame.choicejob == SHIELD) {
			//騎士ダメージ表示
			shielddmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			shielddmf->setPosition(rightSize.width / 2, rightSize.height / 5.3f);
			shielddmf->setColor(ccc3(colormax, colormin, colormin));
			//騎士ダメージ表示のフェードアウト処理
			shieldfadeout = CCFadeOut::create(2.0f);									//何秒で消える？
			shieldfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 2, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}
		else if (pl3frame.choicejob == SHIELD) {
			//騎士ダメージ表示
			shielddmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			shielddmf->setPosition(rightSize.width / 1.3f, rightSize.height / 5.3f);
			shielddmf->setColor(ccc3(colormax, colormin, colormin));
			//騎士ダメージ表示のフェードアウト処理
			shieldfadeout = CCFadeOut::create(2.0f);									//何秒で消える？
			shieldfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 1.3f, rightSize.height / 5.3f + moverange)), NULL);//ダメージ表示を移動させる
		}

		//魔術師のダメージ表示処理の初期化
		if (pl1frame.choicejob == MAGIC) {
			//魔術師ダメージ表示
			magicdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			magicdmf->setPosition(rightSize.width / 4, rightSize.height / 5.3f);
			magicdmf->setColor(ccc3(colormax, colormin, colormin));
			//魔術師ダメージ表示のフェードアウト処理
			magicfadeout = CCFadeOut::create(2.0f);											//何秒で消える？
			magicfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 4, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}
		else if (pl2frame.choicejob == MAGIC) {
			//魔術師ダメージ表示
			magicdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			magicdmf->setPosition(rightSize.width / 2, rightSize.height / 5.3f);
			magicdmf->setColor(ccc3(colormax, colormin, colormin));
			//魔術師ダメージ表示のフェードアウト処理
			magicfadeout = CCFadeOut::create(2.0f);											//何秒で消える？
			magicfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 2, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}
		else if (pl3frame.choicejob == MAGIC) {
			//魔術師ダメージ表示
			magicdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			magicdmf->setPosition(rightSize.width / 1.3f, rightSize.height / 5.3f);
			magicdmf->setColor(ccc3(colormax, colormin, colormin));
			//魔術師ダメージ表示のフェードアウト処理
			magicfadeout = CCFadeOut::create(2.0f);											//何秒で消える？
			magicfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 1.3f, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}

		//聖職者のダメージ表示処理の初期化
		if (pl1frame.choicejob == HEALER) {
			//聖職者ダメージ表示
			healerdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			healerdmf->setPosition(rightSize.width / 4, rightSize.height / 5.3f);
			healerdmf->setColor(ccc3(colormax, colormin, colormin));
			//聖職者ダメージ表示のフェードアウト処理
			healerfadeout = CCFadeOut::create(2.0f);											//何秒で消える？
			healerfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 4, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}
		else if (pl2frame.choicejob == HEALER) {
			//聖職者ダメージ表示
			healerdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			healerdmf->setPosition(rightSize.width / 2, rightSize.height / 5.3f);
			healerdmf->setColor(ccc3(colormax, colormin, colormin));
			//聖職者ダメージ表示のフェードアウト処理
			healerfadeout = CCFadeOut::create(2.0f);											//何秒で消える？
			healerfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 2, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}
		else if (pl3frame.choicejob == HEALER) {
			//聖職者ダメージ表示
			healerdmf = LabelTTF::create(std::to_string(hpcut), "HGRSGU.TTC", fontsizeL);
			healerdmf->setPosition(rightSize.width / 1.3f, rightSize.height / 5.3f);
			healerdmf->setColor(ccc3(colormax, colormin, colormin));
			//聖職者ダメージ表示のフェードアウト処理
			healerfadeout = CCFadeOut::create(2.0f);											//何秒で消える？
			healerfdoutmov = CCSequence::create(CCMoveTo::create(1.0f,
				ccp(rightSize.width / 1.3f, rightSize.height / 5.3f + moverange)), NULL);	//ダメージ表示を移動させる
		}

		flag = false;									//フラグをfalseに
		gameflame++;									//カウント開始
		BSturn();										//主な処理
		
		if (gameflame == flame170) {
			//文字を消す
			this->removeChildByTag(normalattackS);		//通常攻撃
			this->removeChildByTag(bossskill1S);		//スキル1			
			this->removeChildByTag(bossskill2S);		//スキル2
			this->removeChildByTag(bossskill3S);		//スキル3
			this->removeChildByTag(bossskill4S);		//スキル4
		}
		if (gameflame > flamemax) {
			if (act_rnd < tenpercent) {
				//文字を消す
				this->removeChildByTag(bossturnI);				//BSTURN
				this->removeChildByTag(damageS);				//効果表記(通常攻撃)
				this->removeChildByTag(bossskill1E);			//パーティクル
				this->removeChildByTag(bossskill1damageS);		//効果表記(スキル1)
				this->removeChildByTag(bossskill2damageS);		//効果表記(スキル2)
				this->removeChildByTag(bossskill3damageS);		//効果表記(スキル3)
				this->removeChildByTag(bossskill4damageS);		//効果表記(スキル4)

				gameflame = 0;									//時間を0へ
				actcnt = 0;										//カウントを0へ
				fntflag = false;								//ダメージ表示フラグをfalseに
				job = NON;										//選んだキャラを初期の状態に戻す
				battle = START;									//バトルを初期の状態に戻す
				choices = CHAR1;								//選択キャラを最初に
				turn = PLAYER;									//プレイヤーのターンへ
			}
			if (act_rnd >= tenpercent && act_rnd <= rndmax) {
				if (actcnt < 1) {
					//文字を消す
					this->removeChildByTag(damageS);			//効果表記(通常攻撃)
					this->removeChildByTag(bossskill1E);		//パーティクル
					this->removeChildByTag(bossskill1damageS);	//効果表記(スキル1)
					this->removeChildByTag(bossskill2damageS);	//効果表記(スキル2)
					this->removeChildByTag(bossskill3damageS);	//効果表記(スキル3)
					this->removeChildByTag(bossskill4damageS);	//効果表記(スキル4)

					pick_rnd = random(rndmin, rndmax);			//指定した範囲内の乱数を取得(プレイヤーのキャラを選択)
					act_rnd = random(rndmin, rndmax);			//指定した範囲内の乱数を取得(ボスの動く回数)
					decide_rnd = random(rndmin, rndmax);		//指定した範囲内の乱数を取得(ボスの動き)
					skill_rnd = random(rndmin, rndmax);			//指定した範囲内の乱数を取得(スキル)

					actcnt += 1;								//攻撃カウントを増やして2回以上攻撃しないようにする
					gameflame = 0;								//時間を0へ
					fntflag = false;							//ダメージ表示フラグをfalseに
					bsact = PICK;								//ボスの動きを初期に戻す
					turn = BOSS;								//もう一回ボスの行動へ
				}
				else {
					//文字を消す
					this->removeChildByTag(bossturnI);			//BSTURN
					this->removeChildByTag(damageS);			//効果表記(通常攻撃)
					this->removeChildByTag(bossskill1E);		//パーティクル
					this->removeChildByTag(bossskill1damageS);	//効果表記(スキル1)
					this->removeChildByTag(bossskill2damageS);	//効果表記(スキル2)
					this->removeChildByTag(bossskill3damageS);	//効果表記(スキル3)
					this->removeChildByTag(bossskill4damageS);	//効果表記(スキル4)

					gameflame = 0;								//時間を0へ
					actcnt = 0;									//カウントを0へ
					fntflag = false;							//ダメージ表示フラグをfalseに
					job = NON;									//選んだキャラを初期の状態に戻す
					battle = START;								//バトルを初期の状態に戻す
					choices = CHAR1;							//選択キャラを最初に
					turn = PLAYER;								//プレイヤーのターンへ
				}
			}
		}
	}

	//剣士のHPゲージを減らす
	attackerHP->setTextureRect(Rect(HPbar.x, HPbar.y,
		attackerhpgaugewidth * attacker.hp / attacker.hpmax,
		attackerHP->getContentSize().height));
	//剣士のMANAゲージに変化をつける
	attackerMN->setTextureRect(Rect(MNbar.x, MNbar.y,
		attackermngaugewidth * attacker.mana / attacker.manamax,
		attackerMN->getContentSize().height));
	//騎士のHPゲージを減らす
	shieldHP->setTextureRect(Rect(HPbar.x, HPbar.y,
		shieldhpgaugewidth * shield.hp / shield.hpmax,
		shieldHP->getContentSize().height));
	//騎士のMANAゲージに変化をつける
	shieldMN->setTextureRect(Rect(MNbar.x, MNbar.y,
		shieldmngaugewidth * shield.mana / shield.manamax,
		shieldMN->getContentSize().height));
	//魔術師のHPゲージを減らす
	magicHP->setTextureRect(Rect(HPbar.x, HPbar.y,
		healerhpgaugewidth * magic.hp / magic.hpmax,
		magicHP->getContentSize().height));
	//魔術師のMANAゲージに変化をつける
	magicMN->setTextureRect(Rect(MNbar.x, MNbar.y,
		healermngaugewidth * magic.mana / magic.manamax,
		magicMN->getContentSize().height));
	//聖職者のHPゲージを減らす
	healerHP->setTextureRect(Rect(HPbar.x, HPbar.y,
		healerhpgaugewidth * healer.hp / healer.hpmax,
		healerHP->getContentSize().height));
	//聖職者のMANAゲージに変化をつける
	healerMN->setTextureRect(Rect(MNbar.x, MNbar.y,
		healermngaugewidth * healer.mana / healer.manamax,
		healerMN->getContentSize().height));
	//ボスのHPゲージに変化をつける
	HPboss->setTextureRect(Rect(HPbar.x, HPbar.y,
		bosshpgaugewidth * valkyrie.hp / valkyrie.hpmax,
		HPboss->getContentSize().height));

	//それぞれのキャラのHP、MANAがMAX以上の時MAXにする
	//剣士
	if (attacker.hp >= attacker.hpmax) {
		attackerhpal->setString(std::to_string(attacker.hpmax));
		attacker.hp = attacker.hpmax;
	}
	if (attacker.mana >= attacker.manamax) {
		attackermnal->setString(std::to_string(attacker.manamax));
		attacker.mana = attacker.manamax;
	}
	//騎士
	if (shield.hp >= shield.hpmax) {
		shieldhpal->setString(std::to_string(shield.hpmax));
		shield.hp = shield.hpmax;
	}
	if (shield.mana >= shield.manamax) {
		shieldmnal->setString(std::to_string(shield.manamax));
		shield.mana = shield.manamax;
	}
	//魔術師
	if (magic.hp >= magic.hpmax) {
		magichpal->setString(std::to_string(magic.hpmax));
		magic.hp = magic.hpmax;
	}
	if (magic.mana >= magic.manamax) {
		magicmnal->setString(std::to_string(magic.manamax));
		magic.mana = magic.manamax;
	}
	//聖職者
	if (healer.hp >= healer.hpmax) {
		healerhpal->setString(std::to_string(healer.hpmax));
		healer.hp = healer.hpmax;
	}
	if (healer.mana >= healer.manamax) {
		healermnal->setString(std::to_string(healer.manamax));
		healer.mana = healer.manamax;
	}
	//ヴァルキュリー
	if (valkyrie.hp >= valkyrie.hpmax) {
		valkyrie.hp = valkyrie.hpmax;
	}
	if (valkyrie.mana >= valkyrie.manamax) {
		valkyrie.mana = valkyrie.manamax;
	}
	//それぞれのプレイヤーのHP、MANAが0以下の時0にする
	//剣士
	if (attacker.hp <= hpmin) {
		attackerhpal->setString(std::to_string(hpmin));
		attacker.hp = hpmin;
	}
	if (attacker.mana <= hpmin) {
		attackermnal->setString(std::to_string(hpmin));
		attacker.mana = hpmin;
	}
	//騎士
	if (shield.hp <= hpmin) {
		shieldhpal->setString(std::to_string(hpmin));
		shield.hp = hpmin;
	}
	if (shield.mana <= hpmin) {
		shieldmnal->setString(std::to_string(hpmin));
		shield.mana = hpmin;
	}
	//魔術師
	if (magic.hp <= hpmin) {
		magichpal->setString(std::to_string(hpmin));
		magic.hp = hpmin;
	}
	if (magic.mana <= hpmin) {
		magicmnal->setString(std::to_string(hpmin));
		magic.mana = hpmin;
	}
	//聖職者
	if (healer.hp <= hpmin) {
		healerhpal->setString(std::to_string(hpmin));
		healer.hp = hpmin;
	}
	if (healer.mana <= hpmin) {
		healermnal->setString(std::to_string(hpmin));
		healer.mana = hpmin;
	}
	//死亡したとき
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
		//プレイヤー1の行動

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
		//通常攻撃関連
		if (pl1 == PL1ATTACK) {
			Plattacks();
		}
		//プレイヤースキル関連
		if (pl1 == PL1SKILL) {
			Plskills();
		}
		//攻撃・スキルが終わったら
		if (!(pl1 == PL1DEATH)) {
			if (attackendflag == true || skillendflag == true) {
				choices = CHAR2;								//次のキャラへ
				pl1 = PL1NON;									//pl1は何もしないようにする
				gameflame = 0;									//時間を初期値に戻す
				skillflame = 0;									//スキルの時間を初期値に
				skillendflag = false;							//フラグ初期値に戻す
				attackendflag = false;							//フラグを戻す
			}
		}
		if (pl1 == PL1DEATH) {
			choices = CHAR2;								//次のキャラへ
			gameflame = 0;									//時間を初期値に戻す
			skillflame = 0;									//スキルの時間を初期値に
			skillendflag = false;							//フラグ初期値に戻す
			attackendflag = false;							//フラグを戻す
		}
		break;
	}
	case BossScene::CHAR2: {
		//プレイヤー2の行動
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
		//通常攻撃関連
		if (pl2 == PL2ATTACK) {
			Plattacks();
		}
		//プレイヤースキル関連
		if (pl2 == PL2SKILL) {
			Plskills();
		}
		if (!(pl2 == PL2DEATH)) {
			if (attackendflag == true || skillendflag == true) {
				choices = CHAR3;
				pl2 = PL2NON;
				gameflame = 0;									//時間を初期値に戻す
				skillflame = 0;									//スキルの時間を初期値に
				skillendflag = false;							//フラグ初期値に戻す
				attackendflag = false;							//フラグを戻す
			}
		}
		if (pl2 == PL2DEATH) {
			choices = CHAR3;
			gameflame = 0;									//時間を初期値に戻す
			skillflame = 0;									//スキルの時間を初期値に
			skillendflag = false;							//フラグ初期値に戻す
			attackendflag = false;
		}
		break;
	}
	case BossScene::CHAR3: {
		//プレイヤー3の行動
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
		//通常攻撃関連
		if (pl3 == PL3ATTACK) {
			Plattacks();
		}
		//プレイヤースキル関連
		if (pl3 == PL3SKILL) {
			Plskills();
		}
		if (!(pl3 == PL3DEATH)) {
			if (attackendflag == true || skillendflag == true) {
				turn = BOSS;								//ボスのターンにする
				bsact = PICK;								//ボスの動きを初期化
				choices = CHAR1;							//選択を最初からに戻す
				pl3 == PL3NON;
				this->removeChildByTag(playertrunI);		//PLTURNを消す1
				gameflame = 0;								//時間を初期値に戻す
				skillflame = 0;								//スキルの時間を初期値に
				skillendflag = false;						//フラグ初期値に戻す
				attackendflag = false;						//フラグを戻す

				//BSTURN文字表示
				emturn = CCSprite::create("Description/BS.png");							// 配置文字
				emturn->setPosition(rightSize.width / 1.13, rightSize.height / 1.25f);		// 配置場所
				this->addChild(emturn, backdepth, bossturnI);								// 追加
			}
		}
		if (pl3 == PL3DEATH) {
			turn = BOSS;								//ボスのターンにする
			bsact = PICK;								//ボスの動きを初期化
			choices = CHAR1;							//選択を最初からに戻す
			this->removeChildByTag(playertrunI);		//PLTURNを消す
			gameflame = 0;								//時間を初期値に戻す
			skillflame = 0;								//スキルの時間を初期値に
			skillendflag = false;						//フラグ初期値に戻す
			attackendflag = false;						//フラグを戻す
		}
		break;
	}
	default: {
		break;
	}
	}
	//HPが0になったら
	if (valkyrie.hp <= 0) {
		// 遷移策の画面をｲﾝｽﾀﾝｽ
		Scene *pScene = GameClear::createScene();
		// 0.6秒かけて次画面に遷移(時間,遷移先,色(オプション))
		TransitionFade *transition = TransitionFade::create(1.0, pScene);
		// 遷移実行 アニメーション
		Director::getInstance()->replaceScene(transition);
	}
}

void BossScene::Plattacks()
{
	//剣士
	if (job == ATTACKER) {
		if (gameflame == flame50) {
			//通常攻撃
			//ボスのHPを減らす
			Damage();
			Boss->runAction(bossrepeat);
			hpcut = (attacker.atk - valkyrie.def);
			//もし減らすHPが1以下の場合減らすHPを1にする
			if (hpcut <= 1) {
				hpcut = 1;
			}
			valkyrie.hp -= hpcut;
			//ダメージ表記
			String *attackeratk = String::createWithFormat("剣士は%iダメージ与えた", hpcut);
			string _attackeratk = attackeratk->getCString();
			auto attackeralabel = Label::createWithSystemFont(_attackeratk, "HGRSGU.TTC", fontsizeL);
			attackeralabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(attackeralabel, backdepth, attackerdamageS);
		}
		//攻撃終わり
		if (gameflame == flame80) {
			this->removeChildByTag(attackerdamageS);
			attackendflag = true;
		}
	}
	//騎士
	if (job == SHIELD) {
		if (gameflame == flame50) {
			//通常攻撃
			//ボスのHPを減らす
			hpcut = (shield.atk - valkyrie.def);
			//もし減らすHPが1以下の場合減らすHPを1にする
			if (hpcut <= 1) {
				hpcut = 1;
			}
			valkyrie.hp -= hpcut;
			//ダメージ表記
			String *shieldatk = String::createWithFormat("騎士は%iダメージ与えた", hpcut);
			string _shieldatk = shieldatk->getCString();
			auto shieldalabel = Label::createWithSystemFont(_shieldatk, "HGRSGU.TTC", fontsizeL);
			shieldalabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(shieldalabel, backdepth, shielddamageS);
		}
		//攻撃終わり
		if (gameflame == flame80) {
			this->removeChildByTag(shielddamageS);
			attackendflag = true;
		}
	}
	//魔術師
	if (job == MAGIC) {
		if (gameflame == flame50) {
			//通常攻撃
			//ボスのHPを減らす
			hpcut = (magic.atk - valkyrie.def);
			//もし減らすHPが1以下の場合減らすHPを1にする
			if (hpcut <= 1) {
				hpcut = 1;
			}
			valkyrie.hp -= hpcut;
			//ダメージ表記
			String *magicatk = String::createWithFormat("魔術師は%iダメージ与えた", hpcut);
			string _magicatk = magicatk->getCString();
			auto magicalabel = Label::createWithSystemFont(_magicatk, "HGRSGU.TTC", fontsizeL);
			magicalabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(magicalabel, backdepth, magicdamageS);

		}
		//攻撃終わり
		if (gameflame == flame80) {
			this->removeChildByTag(magicdamageS);
			attackendflag = true;
		}
	}
	//聖職者
	if (job == HEALER) {
		if (gameflame == flame50) {
			//通常攻撃
			//ボスのHPを減らす
			hpcut = (healer.atk - valkyrie.def);
			//もし減らすHPが1以下の場合減らすHPを1にする
			if (hpcut <= 1) {
				hpcut = 1;
			}
			valkyrie.hp -= hpcut;
			//ダメージ表記
			String *healeratk = String::createWithFormat("聖職者は%iダメージ与えた", hpcut);
			string _healeratk = healeratk->getCString();
			auto healeralabel = Label::createWithSystemFont(_healeratk, "HGRSGU.TTC", fontsizeL);
			healeralabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(healeralabel, backdepth, healerdamageS);
		}
		//攻撃終わり
		if (gameflame == flame80) {
			this->removeChildByTag(healerdamageS);
			attackendflag = true;
		}
	}
}

void BossScene::Plskills()
{
//剣士
	if (job == ATTACKER) {
		//ツインフルーレ
		if (askill == ASKILL1) {
			if (gameflame == flame50) {
				//敵単体に小ダメージ2回攻撃
				//プレイヤー１の減らすMANA
				attacker.mana -= 3;
				//MANAの数値を変える
				attackermnal->setString(std::to_string(attacker.mana));
				//ボスのHPを減らす
				hpcut = attacker.atk * skilluplittle - valkyrie.def;
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//効果処理
				valkyrie.hp -= hpcut;
				//ダメージ表記
				String *attackerskl = String::createWithFormat("剣士は%iダメージ与えた", hpcut);
				string _attackerskl = attackerskl->getCString();
				auto p1slabel = Label::createWithSystemFont(_attackerskl, "HGRSGU.TTC", fontsizeL);
				p1slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p1slabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame80) {
				this->removeChildByTag(attackerdamageS);		//ダメージ表記を消す
			}
			//2回目のダメージを与える
			if (skillflame == flame150) {
				//効果処理
				valkyrie.hp -= hpcut;
				//ダメージ表記
				String *attackerskl = String::createWithFormat("剣士は%iダメージ与えた", hpcut);
				string _attackerskl = attackerskl->getCString();
				auto attackerslabel = Label::createWithSystemFont(_attackerskl, "HGRSGU.TTC", fontsizeL);
				attackerslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerslabel, backdepth, attackerdamageS);
			}
			//スキル終わり
			if (skillflame == flame200) {
				this->removeChildByTag(askill1E);				//エフェクトを消す
				this->removeChildByTag(attackerdamageS);		//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//アーマーブレイク
		if (askill == ASKILL2) {
			if (skillflame == flame50) {
				//敵単体に小ダメージ+防御力ダウン
				//プレイヤー１の減らすMANA
				attacker.mana -= 2;

				//MANAの数値を変える
				attackermnal->setString(std::to_string(attacker.mana));
				//ボスのHPを減らす
				hpcut = (attacker.atk - valkyrie.def);
				//敵のステータス(防御力)を下げる値を決める
				//今の防御力の2割減らす
				buffdown = valkyrie.def * buffdownlittle;
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//効果処理
				valkyrie.hp -= hpcut;
				valkyrie.def -= buffdown;
				//スキル効果ターンによる処理
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
				//ダメージ表記
				String *attackerskl = String::createWithFormat("剣士は%iダメージ与えた", hpcut);
				string _attackerskl = attackerskl->getCString();
				auto attackerslabel = Label::createWithSystemFont(_attackerskl, "HGRSGU.TTC", fontsizeL);
				attackerslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerslabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame100) {
				this->removeChildByTag(askill1E);				//エフェクトを消す
				this->removeChildByTag(attackerdamageS);		//ダメージ表記を消す
				auto pl1buffdown = CCLabelTTF::create("ヴァルキュリーの防御力が少し下がった", "HGRSGU.TTC", fontsizeM);
				pl1buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl1buffdown, backdepth, buffdownS);
			}
			if (skillflame == flame150) {
				this->removeChildByTag(askill1E);				//エフェクトを消す
				this->removeChildByTag(buffdownS);				//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//ライフソード
		if (askill == ASKILL3) {
			if (skillflame == flame50) {
				//敵単体に小ダメージ＋自身のHPを小回復
				//プレイヤー１の減らすMANA
				attacker.mana -= 2;

				//MANAの数値を変える
				attackermnal->setString(std::to_string(attacker.mana));
				//ボスのHPを減らす
				hpcut = (attacker.atk - valkyrie.def);
				//回復する値を決める
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//今のHPの2割回復
				recovery = hpcut * buffdownlittle;
				//効果処理
				valkyrie.hp -= hpcut;
				attacker.hp += recovery;
				attackerhpal->setString(std::to_string(attacker.hp));
				//ダメージ表記
				String *attackerskl = String::createWithFormat("剣士は%iダメージ与えた", hpcut);
				string _attackerskl = attackerskl->getCString();
				auto attackerslabel = Label::createWithSystemFont(_attackerskl, "HGRSGU.TTC", fontsizeL);
				attackerslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerslabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//エフェクトを消す
				this->removeChildByTag(attackerdamageS);				//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//インパクトスラッシュ
		if (askill == ASKILL4) {
			if (skillflame == flame50) {
				//敵単体に小ダメージ+攻撃力ダウン
				//プレイヤー１の減らすMANA
				attacker.mana -= 2;

				//MANAの数値を変える
				attackermnal->setString(std::to_string(attacker.mana));
				//ボスのHPを減らす
				hpcut = (attacker.atk - valkyrie.def);
				//敵のステータス(攻撃力)を下げる値を決める
				//今の攻撃力の2割減らす
				buffdown = valkyrie.atk * buffdownlittle;
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//効果処理
				valkyrie.hp -= hpcut;
				valkyrie.atk -= buffdown;
				//スキル効果ターンによる処理
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
				//ダメージ表記
				String *attackerskl = String::createWithFormat("剣士は%iダメージ与えた", hpcut);
				string _attackerskl = attackerskl->getCString();
				auto attackerslabel = Label::createWithSystemFont(_attackerskl, "HGRSGU.TTC", fontsizeL);
				attackerslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerslabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame100) {
				this->removeChildByTag(attackerdamageS);	//ダメージ表記を消す
				auto pl1buffdown = CCLabelTTF::create("ヴァルキュリーの攻撃力が少し下がった", "HGRSGU.TTC", fontsizeM);
				pl1buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl1buffdown, backdepth, buffdownS);
				
			}
			if (skillflame == flame150) {
				this->removeChildByTag(askill1E);			//エフェクトを消す
				this->removeChildByTag(buffdownS);			//ダメージ表記を消す
				skillendflag = true;
			
			}
		}
		//ソードスルー
		if (askill == ASKILL5) {
			if (skillflame == flame50) {
				//敵単体に防御力無視の中ダメージ
				//エフェクトの表示
				//エフェクトの流れを指定
				CCParticleSystemQuad* plparticle = CCParticleSystemQuad::create("Effect/plskill2.plist");
				plparticle->setAutoRemoveOnFinish(true);
				//エフェクト処理
				plparticle->resetSystem();								//パーティクル開始
				plparticle->setPosition(ccp(rightSize.width / 2,
					rightSize.height / 1.7f));							//パーティクルを表示する場所の設定
				this->addChild(plparticle, backdepth, askill1E);		//パーティクルを配置
				//プレイヤー１の減らすMANA
				attacker.mana -= 4;

				//MANAの数値を変える
				attackermnal->setString(std::to_string(attacker.mana));
				//ボスのHPを減らす
				//防御無視なので敵の防御力を引かない
				hpcut = attacker.atkmax * skillupmedium;
				//効果処理
				valkyrie.hp -= hpcut;
				//ダメージ表記
				String *attackerskl = String::createWithFormat("剣士は%iダメージ与えた", hpcut);
				string _attackerskl = attackerskl->getCString();
				auto attackerslabel = Label::createWithSystemFont(_attackerskl, "HGRSGU.TTC", fontsizeL);
				attackerslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerslabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//エフェクトを消す
				this->removeChildByTag(attackerdamageS);		//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//紅蓮剣
		if (askill == ASKILL6) {
			if (skillflame == flame50) {
				//敵単体に大ダメージ
				//プレイヤー１の減らすMANA
				attacker.mana -= 5;

				//MANAの数値を変える
				attackermnal->setString(std::to_string(attacker.mana));
				//ボスのHPを減らす
				//今の攻撃力の倍のダメージを与える
				hpcut = (attacker.atk * skilluplarge) - valkyrie.def;
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//効果処理
				valkyrie.hp -= hpcut;
				//ダメージ表記
				String *attackerskl = String::createWithFormat("剣士は%iダメージ与えた", hpcut);
				string _attackerskl = attackerskl->getCString();
				auto attackerslabel = Label::createWithSystemFont(_attackerskl, "HGRSGU.TTC", fontsizeL);
				attackerslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerslabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//エフェクトを消す
				this->removeChildByTag(attackerdamageS);				//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//コンディクション
		if (askill == ASKILL7) {
			if (skillflame == flame50) {
				//3ターンの間、自身の攻撃力が小アップ
				//プレイヤー１の減らすMANA
				attacker.mana -= 3;

				//MANAの数値を変える
				attackermnal->setString(std::to_string(attacker.mana));
				//アタッカーの元の攻撃力の2割ほど攻撃力を上げる
				buffup = attacker.atkmax * buffdownlittle;
				//効果処理
				attacker.atk += buffup;
				//スキル効果ターンによる処理
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
				//ダメージ表記
				String *attackerbuff = String::createWithFormat("剣士は%i攻撃力が少しアップした", buffup);
				string _attackerbuff = attackerbuff->getCString();
				auto attackerslabel = Label::createWithSystemFont(_attackerbuff, "HGRSGU.TTC", fontsizeL);
				attackerslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerslabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);				//エフェクトを消す
				this->removeChildByTag(attackerdamageS);		//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//ウォリアーウォークライ
		if (askill == ASKILL8) {
			if (skillflame == flame50) {
				//3ターンの間、自身の攻撃力を大アップ・防御力小ダウン
				//プレイヤー１の減らすMANA
				attacker.mana -= 7;
				//MANAの数値を変える
				attackermnal->setString(std::to_string(attacker.mana));
				//アタッカーの攻撃力を上げる
				//アタッカーの元の攻撃力ぶん攻撃力を上げる
				buffup = attacker.atkmax;
				//アタッカーの防御力を下げる
				buffdown = attacker.def * buffdownlarge;
				//効果処理
				attacker.atk += buffup;
				attacker.def -= buffdown;
				//スキル効果ターンによる処理
				if (askill8.buffturn1 == 0) {
					askill8.buffturn1 = 5;				//持続するターン
					askill8.buffupefect1 = buffup;		//上がった分のステータスを記憶
					askill8.buffdownefect1 = buffdown;	//下がった分のステータスを記憶
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

				//ダメージ表記
				String *attackerbuf = String::createWithFormat("剣士は攻撃力が大幅にアップした", buffup);
				string _attackerbuf = attackerbuf->getCString();
				auto attackerslabel = Label::createWithSystemFont(_attackerbuf, "HGRSGU.TTC", fontsizeL);
				attackerslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerslabel, backdepth, attackerdamageS);
			}
			//ステータス変化表記
			if (skillflame == flame100) {
				this->removeChildByTag(attackerdamageS);
				auto pl1buffdown = CCLabelTTF::create("剣士の防御力が少し下がった", "HGRSGU.TTC", fontsizeL);
				pl1buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl1buffdown, backdepth, buffdownS);
			}
			if (skillflame == flame150) {
				this->removeChildByTag(askill1E);				//エフェクトを消す
				this->removeChildByTag(buffdownS);				//ステータス変化表記を消す
				skillendflag = true;
			}
		}
	}
//騎士
	if (job == SHIELD) {
		//アインスゾイレ
		if (sskill == SSKILL1) {
			//敵単体に小ダメージの２回攻撃
			if (gameflame == flame50) {
				//敵単体に小ダメージ2回攻撃
				//プレイヤー１の減らすMANA
				shield.mana -= 3;
				//MANAの数値を変える
				attackermnal->setString(std::to_string(attacker.mana));
				//ボスのHPを減らす
				hpcut = attacker.atk * skilluplittle - valkyrie.def;
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				//効果処理
				valkyrie.hp -= hpcut;
				//ダメージ表記
				String *shieldskl = String::createWithFormat("騎士は%iダメージ与えた", hpcut);
				string _shieldskl = shieldskl->getCString();
				auto shieldslabel = Label::createWithSystemFont(_shieldskl, "HGRSGU.TTC", fontsizeL);
				shieldslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(shieldslabel, backdepth, attackerdamageS);
			}
			if (skillflame == flame80) {
				this->removeChildByTag(attackerdamageS);		//ダメージ表記を消す
			}
			//2回目のダメージを与える
			if (skillflame == flame150) {
				//効果処理
				valkyrie.hp -= hpcut;
				//ダメージ表記
				String *shieldskl = String::createWithFormat("騎士は%iダメージ与えた", hpcut);
				string _shieldskl = shieldskl->getCString();
				auto shieldslabel = Label::createWithSystemFont(_shieldskl, "HGRSGU.TTC", fontsizeL);
				shieldslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(shieldslabel, backdepth, attackerdamageS);
			}
			//スキル終わり
			if (skillflame == flame200) {
				this->removeChildByTag(askill1E);				//エフェクトを消す
				this->removeChildByTag(attackerdamageS);		//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//カウンター
		if (sskill == SSKILL2) {
			//攻撃を受けたとき、敵を攻撃する
		}
		//最前線
		if (sskill == SSKILL3) {
			//敵の攻撃を自身に集中させる
			if (gameflame == flame50) {
				//騎士の消費するマナを決める
				shield.mana -= 2;
				//MANAの数値を変える
				shieldmnal->setString(std::to_string(shield.mana));

				// スキル効果ターンによる処理
					if (sskill3.buffturn1 == 0) {
						sskill3.buffturn1 = 2;	//スキルの効果が発揮するターンを決める
						coverflag1 = true;		//タゲ集中フラグをオンにする
					}
					else if (sskill3.buffturn3 == 0) {
						sskill3.buffturn2= 2;	//スキルの効果が発揮するターンを決める
						coverflag2= true;		//タゲ集中フラグをオンにする
					}

				//効果表記
				auto shieldcover = CCLabelTTF::create("騎士に攻撃が集中する", "HGRSGU.TTC", fontsizeL);
				shieldcover->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(shieldcover, backdepth, coverS);
			}
			if (gameflame == flame100) {
				this->removeChildByTag(coverS);	//ステータス変化表記を消す
				skillendflag = true;			//スキル終わり
			}

		}
		//身代わりの氷像
		if (sskill == SSKILL4) {
			//味方単体へのダメージを代わりに受ける
			if (gameflame == flame50) {
				//騎士の消費するマナを決める
				shield.mana -= 2;
				//MANAの数値を変える
				shieldmnal->setString(std::to_string(shield.mana));

				// スキル効果ターンによる処理
				if (sskill4.buffturn1 == 0) {
					sskill4.buffturn1 = 1;	//スキルの効果が発揮するターンを決める
					insteadflag = true;		//身代わりフラグをオンにする
				}

				//剣士を選んだ場合
				if (sskillchoice == ATTACKER) {
					//効果表記
					auto shieldinstead = CCLabelTTF::create("剣士の代わりに攻撃を受ける", "HGRSGU.TTC", fontsizeL);
					shieldinstead->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
					this->addChild(shieldinstead, backdepth, insteadS);
				}
				//魔術師を選んだ場合
				else if (sskillchoice == MAGIC) {
					auto shieldinstead = CCLabelTTF::create("魔術師の代わりに攻撃を受ける", "HGRSGU.TTC", fontsizeL);
					shieldinstead->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
					this->addChild(shieldinstead, backdepth, insteadS);
				}
				//聖職者を選んだ場合
				else if (sskillchoice == HEALER) {
					auto shieldinstead = CCLabelTTF::create("聖職者の代わりに攻撃を受ける", "HGRSGU.TTC", fontsizeL);
					shieldinstead->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
					this->addChild(shieldinstead, backdepth, insteadS);
				}


			}
			if (gameflame == flame100) {
				this->removeChildByTag(insteadS);	//ステータス変化表記を消す
				skillendflag = true;				//スキル終わり
			}
		}
		//群れる氷像
		if (sskill == SSKILL5) {
			//味方全員へのダメージを代わりに受ける
			if (gameflame == flame50) {
				//騎士の消費するマナを決める
				shield.mana -= 3;
				//MANAの数値を変える
				shieldmnal->setString(std::to_string(shield.mana));

				// スキル効果ターンによる処理
				if (sskill5.buffturn1 == 0) {
					sskill5.buffturn1 = 1;	//スキルの効果が発揮するターンを決める
					allinsteadflag = true;		//身代わりフラグをオンにする
				}

				//効果表記
				auto shieldinstead = CCLabelTTF::create("全員の代わりに攻撃を受ける", "HGRSGU.TTC", fontsizeL);
				shieldinstead->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(shieldinstead, backdepth, insteadS);
			}
			if (gameflame == flame100) {
				this->removeChildByTag(insteadS);	//ステータス変化表記を消す
				skillendflag = true;			//スキル終わり
			}
		}
		//鼓舞する雄叫び
		if (sskill == SSKILL6) {
			//戦闘不能時１度だけ自身のHP１で復活する
		}
		//氷の御衣
		if (sskill == SSKILL7) {
			if (skillflame == flame50) {
				//5ターンの間、自身の防御力を小アップ
				//プレイヤー１の減らすMANA
				shield.mana -= 2;

				//MANAの数値を変える
				shieldmnal->setString(std::to_string(shield.mana));
				//アタッカーの元の攻撃力の2割ほど攻撃力を上げる
				buffup = shield.defmax * buffdownlittle;
				//効果処理
				shield.atk += buffup;
				//スキル効果ターンによる処理
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
				//ダメージ表記
				String *shieldbuff = String::createWithFormat("騎士は%i防御力が少しアップした", buffup);
				string _shieldbuff = shieldbuff->getCString();
				auto shieldslabel = Label::createWithSystemFont(_shieldbuff, "HGRSGU.TTC", fontsizeL);
				shieldslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(shieldslabel, backdepth, shielddamageS);
			}
			if (skillflame == flame110) {
				this->removeChildByTag(askill1E);			//エフェクトを消す
				this->removeChildByTag(shielddamageS);		//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//騎士の矜持
		if (sskill == SSKILL8) {
			if (skillflame == flame50) {
				//4ターンの間、自身の防御力を大アップ・攻撃力小ダウン
				//プレイヤー１の減らすMANA
				shield.mana -= 6;

				//MANAの数値を変える
				shieldmnal->setString(std::to_string(shield.mana));
				//騎士の元の防御力の2割ほど攻撃力を上げる
				buffup = shield.defmax;
				buffdown = shield.atk * buffdownlarge;
				//効果処理
				shield.def += buffup;
				shield.atk -= buffdown;
				//スキル効果ターンによる処理
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
				//ステータス変化表記
				String *shieldbuff = String::createWithFormat("騎士は防御力が大幅にアップした", buffup);
				string _shieldbuff = shieldbuff->getCString();
				auto shieldslabel = Label::createWithSystemFont(_shieldbuff, "HGRSGU.TTC", fontsizeL);
				shieldslabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(shieldslabel, backdepth, shielddamageS);
			}
			//ステータス変化表記
			if (skillflame == flame100) {
				this->removeChildByTag(shielddamageS);		//ダメージ表記を消す
				auto shieldbuffdown = CCLabelTTF::create("騎士の攻撃力が少し下がった", "HGRSGU.TTC", fontsizeL);
				shieldbuffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(shieldbuffdown, backdepth, buffdownS);
			}
			if (skillflame == flame150) {
				this->removeChildByTag(buffdownS);				//ステータス変化表記を消す
				skillendflag = true;
			}
		}
	}
//魔術師
	if (job == MAGIC) {
		//マジックミサイル
		if (mskill == MSKILL1) {
			if (gameflame == flame50) {
				//敵単体に小ダメージ
				//エフェクトの表示
				//エフェクトの流れを指定
				CCParticleSystemQuad* plparticle3 = CCParticleSystemQuad::create("Effect/plskill3.plist");
				plparticle3->setAutoRemoveOnFinish(true);

				//エフェクト処理
				plparticle3->resetSystem();								//パーティクル開始
				plparticle3->setPosition(ccp(rightSize.width / 2,
					rightSize.height / 1.7f));							//パーティクルを表示する場所の設定
				this->addChild(plparticle3, backdepth, mskill1E);		//パーティクルを配置

				//プレイヤー3のMANAを減らす
				magic.mana -= 5;
				//MANAの数値を変える
				magicmnal->setString(std::to_string(magic.mana));
				//ボスのHPを減らす
				hpcut = (magic.matk - valkyrie.mdef);
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				//ダメージ表記
				String *p3skl = String::createWithFormat("魔術師は%iダメージ与えた", hpcut);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			//スキル終わり
			if (skillflame == flame250) {
				this->removeChildByTag(mskill1E);			//ぐるぐるしてるやつ
				this->removeChildByTag(magicdamageS);			//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//アーマーショット
		if(mskill == MSKILL2) {
			if (gameflame == flame50) {
				//敵単体に小ダメージ+自身の防御小アップ
				//プレイヤー3のMANAを減らす
				magic.mana -= 3;
				//MANAの数値を変える
				magicmnal->setString(std::to_string(magic.mana));
				//ボスのHPを減らす
				hpcut = (magic.matk - valkyrie.mdef);
				buffup = magic.def / skilluplarge;
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				magic.def += buffup;
				//スキル効果ターンによる処理
				if (mskill2.buffturn1 == 0) {
					mskill2.buffturn1 = 1;
					mskill2.buffupefect1 = buffup;
				}
				else if (mskill2.buffturn2 == 0) {
					mskill2.buffturn2 = 1;
					mskill2.buffupefect2 = buffup;
				}
				

				//ダメージ表記
				String *p3skl = String::createWithFormat("魔術師は%iダメージ与えた", hpcut);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			if (skillflame == flame100) {
				this->removeChildByTag(magicdamageS);
				auto pl3buffdown = CCLabelTTF::create("魔術師の防御力が少し上がった", "HGRSGU.TTC", fontsizeL);
				pl3buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl3buffdown, backdepth, buffdownS);
			}
			if (skillflame == flame150) {
				this->removeChildByTag(mskill1E);			//ぐるぐるしてるやつ
				this->removeChildByTag(magicdamageS);			//ダメージ表記を消す
				this->removeChildByTag(buffdownS);
				skillendflag = true;
			}
		}
		//マジックバースト
		if (mskill == MSKILL3) {
			if (gameflame == flame50) {
				//敵単体に中ダメージ + 敵の攻撃ダウン
				//プレイヤー3のMANAを減らす
				magic.mana -= 3;
				//MANAの数値を変える
				magicmnal->setString(std::to_string(magic.mana));
				//ボスのHPを減らす
				hpcut = (magic.matk * skillupmedium) - valkyrie.mdef;
				//魔術師の今の攻撃力の５割の攻撃力を下げる
				buffdown = valkyrie.atk * buffdownlittle;
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				valkyrie.atk -= buffdown;
				//スキル効果ターンによる処理
				if (mskill3.buffturn1 == 0) {
					mskill3.buffturn1 = 1;
					mskill3.buffdownefect1 = buffdown;
				}
				else if (mskill3.buffturn2 == 0) {
					mskill3.buffturn2 = 1;
					mskill3.buffdownefect2 = buffdown;
				}

				//ダメージ表記
				String *p3skl = String::createWithFormat("魔術師は%iダメージ与えた", buffdown);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			if (skillflame == flame100) {
				this->removeChildByTag(magicdamageS);
				auto pl3buffdown = CCLabelTTF::create("敵の攻撃力が下がった", "HGRSGU.TTC", fontsizeL);
				pl3buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl3buffdown, backdepth, buffdownS);
			}
			if (skillflame == flame150) {
				this->removeChildByTag(mskill1E);			//ぐるぐるしてるやつ
				this->removeChildByTag(magicdamageS);			//ダメージ表記を消す
				this->removeChildByTag(buffdownS);
				skillendflag = true;
			}
		}
		//VFD
		if (mskill == MSKILL4) {
			if (gameflame == flame50) {
				//敵単体に特大ダメージ
				//プレイヤー3のMANAを減らす
				magic.mana -= 7;
				//MANAの数値を変える
				magicmnal->setString(std::to_string(magic.mana));
				//ボスのHPを減らす
				hpcut = (magic.matk * skilluplarge) - valkyrie.mdef;
				//もし減らすHPが1以下の場合減らすHPを1にする
				if (hpcut <= 1) {
					hpcut = 1;
				}
				valkyrie.hp -= hpcut;
				//ダメージ表記
				String *p3skl = String::createWithFormat("魔術師は%iダメージ与えた", hpcut);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			//スキル終わり
			if (skillflame == flame250) {
				this->removeChildByTag(mskill1E);			//ぐるぐるしてるやつ
				this->removeChildByTag(magicdamageS);			//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//グランツ
		if (mskill == MSKILL5) {
			if (gameflame == flame50) {
				//3ターンの間、味方全体の攻撃力と防御力小アップ
				//プレイヤー3のMANAを減らす
				magic.mana -= 3;
				//MANAの数値を変える
				magicmnal->setString(std::to_string(magic.mana));
				//味方全員のステータスを上げる
				//剣士の攻撃と防御を上げる
				attackeratkbuffup = attacker.atk * buffuplittle;
				attackerdefbuffup = attacker.def * buffuplittle;
				attacker.atk += attackeratkbuffup;
				attacker.def += attackerdefbuffup;
				//騎士のry
				shieldatkbuffup = shield.atk * buffuplittle;
				shielddefbuffup = shield.def * buffuplittle;
				shield.atk += shieldatkbuffup;
				shield.def += shielddefbuffup;
				//魔術師のry
				magicatkbuffup = magic.atk * buffuplittle;
				magicdefbuffup = magic.def * buffuplittle;
				magic.atk += magicatkbuffup;
				magic.def += magicdefbuffup;
				//聖職者のry
				healeratkbuffup = healer.atk * buffuplittle;
				healerdefbuffup = healer.def * buffuplittle;
				healer.atk += healeratkbuffup;
				healer.def += healerdefbuffup;

				//スキル効果ターンによる処理
				if (mskill5.buffturn1 == 0) {
					mskill5.buffturn1 = 4;							//持続するターン
					mskill5.attackeratkbuff1 = attackeratkbuffup;	//上がった分のステータスを記憶(剣士)
					mskill5.attackerdefbuff1 = attackerdefbuffup;	//上がった分のステータスを記憶(剣士)
					mskill5.shieldatkbuff1 = shieldatkbuffup;		//上がった分のステータスを記憶(騎士)
					mskill5.shielddefbuff1 = shielddefbuffup;		//上がった分のステータスを記憶(騎士)
					mskill5.magicatkbuff1 = magicatkbuffup;			//上がった分のステータスを記憶(魔術師)
					mskill5.magicdefbuff1 = magicdefbuffup;			//上がった分のステータスを記憶(魔術師)
					mskill5.healeratkbuff1 = healeratkbuffup;		//上がった分のステータスを記憶(聖職者)
					mskill5.healerdefbuff1 = healerdefbuffup;		//上がった分のステータスを記憶(聖職者)
				}
				else if (mskill5.buffturn2 == 0) {
					mskill5.buffturn2 = 4;
					mskill5.attackeratkbuff2 = attackeratkbuffup;	//上がった分のステータスを記憶(剣士)
					mskill5.attackerdefbuff2 = attackerdefbuffup;	//上がった分のステータスを記憶(剣士)
					mskill5.shieldatkbuff2 = shieldatkbuffup;		//上がった分のステータスを記憶(騎士)
					mskill5.shielddefbuff2 = shielddefbuffup;		//上がった分のステータスを記憶(騎士)
					mskill5.magicatkbuff2 = magicatkbuffup;			//上がった分のステータスを記憶(魔術師)
					mskill5.magicdefbuff2 = magicdefbuffup;			//上がった分のステータスを記憶(魔術師)
					mskill5.healeratkbuff2 = healeratkbuffup;		//上がった分のステータスを記憶(聖職者)
					mskill5.healerdefbuff2 = healerdefbuffup;		//上がった分のステータスを記憶(聖職者)
				}
				else if (mskill5.buffturn3 == 0) {
					mskill5.buffturn3 = 4;
					mskill5.attackeratkbuff3 = attackeratkbuffup;	//上がった分のステータスを記憶(剣士)
					mskill5.attackerdefbuff3 = attackerdefbuffup;	//上がった分のステータスを記憶(剣士)
					mskill5.shieldatkbuff3 = shieldatkbuffup;		//上がった分のステータスを記憶(騎士)
					mskill5.shielddefbuff3 = shielddefbuffup;		//上がった分のステータスを記憶(騎士)
					mskill5.magicatkbuff3 = magicatkbuffup;			//上がった分のステータスを記憶(魔術師)
					mskill5.magicdefbuff3 = magicdefbuffup;			//上がった分のステータスを記憶(魔術師)
					mskill5.healeratkbuff3 = healeratkbuffup;		//上がった分のステータスを記憶(聖職者)
					mskill5.healerdefbuff3 = healerdefbuffup;		//上がった分のステータスを記憶(聖職者)
				}
				else if (mskill5.buffturn4 == 0) {
					mskill5.buffturn4 = 4;
					mskill5.attackeratkbuff4 = attackeratkbuffup;	//上がった分のステータスを記憶(剣士)
					mskill5.attackerdefbuff4 = attackerdefbuffup;	//上がった分のステータスを記憶(剣士)
					mskill5.shieldatkbuff4 = shieldatkbuffup;		//上がった分のステータスを記憶(騎士)
					mskill5.shielddefbuff4 = shielddefbuffup;		//上がった分のステータスを記憶(騎士)
					mskill5.magicatkbuff4 = magicatkbuffup;			//上がった分のステータスを記憶(魔術師)
					mskill5.magicdefbuff4 = magicdefbuffup;			//上がった分のステータスを記憶(魔術師)
					mskill5.healeratkbuff4 = healeratkbuffup;		//上がった分のステータスを記憶(聖職者)
					mskill5.healerdefbuff4 = healerdefbuffup;		//上がった分のステータスを記憶(聖職者)
				}
				
				//ステータスアップ表記
				auto pl3buffup = CCLabelTTF::create("味方の攻撃力と防御力が少し上がった", "HGRSGU.TTC", fontsizeM);
				pl3buffup->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl3buffup, backdepth, buffupS);
			}
			//スキル終わり
			if (skillflame == flame150) {
				this->removeChildByTag(mskill1E);			//ぐるぐるしてるやつ
				this->removeChildByTag(magicdamageS);		//ダメージ表記を消す
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//神の御剣
		if (mskill == MSKILL6) {
			if (gameflame == flame50) {
				//2ターンの間、味方全体の攻撃力と防御力大アップ
				//プレイヤー3のMANAを減らす
				magic.mana -= 5;
				//MANAの数値を変える
				magicmnal->setString(std::to_string(magic.mana));
				//味方全員のステータスを上げる
				//剣士の攻撃と防御を上げる
				attackeratkbuffup = attacker.atkmax;
				attackerdefbuffup = attacker.defmax;
				attacker.atk += attackeratkbuffup;
				attacker.def += attackerdefbuffup;
				//騎士のry
				shieldatkbuffup = shield.atkmax;
				shielddefbuffup = shield.defmax;
				shield.atk += shieldatkbuffup;
				shield.def += shielddefbuffup;
				//魔術師のry
				magicatkbuffup = magic.atkmax;
				magicdefbuffup = magic.defmax;
				magic.atk += magicatkbuffup;
				magic.def += magicdefbuffup;
				//聖職者のry
				healeratkbuffup = healer.atkmax;
				healerdefbuffup = healer.defmax;
				healer.atk += healeratkbuffup;
				healer.def += healerdefbuffup;

				//スキル効果ターンによる処理
				if (mskill6.buffturn1 == 0) {
					mskill6.buffturn1 = 3;							//持続するターン
					mskill6.attackeratkbuff1 = attackeratkbuffup;	//上がった分のステータスを記憶(剣士)
					mskill6.attackerdefbuff1 = attackerdefbuffup;	//上がった分のステータスを記憶(剣士)
					mskill6.shieldatkbuff1 = shieldatkbuffup;		//上がった分のステータスを記憶(騎士)
					mskill6.shielddefbuff1 = shielddefbuffup;		//上がった分のステータスを記憶(騎士)
					mskill6.magicatkbuff1 = magicatkbuffup;			//上がった分のステータスを記憶(魔術師)
					mskill6.magicdefbuff1 = magicdefbuffup;			//上がった分のステータスを記憶(魔術師)
					mskill6.healeratkbuff1 = healeratkbuffup;		//上がった分のステータスを記憶(聖職者)
					mskill6.healerdefbuff1 = healerdefbuffup;		//上がった分のステータスを記憶(聖職者)
				}
				else if (mskill6.buffturn2 == 0) {
					mskill6.buffturn2 = 3;
					mskill6.attackeratkbuff2 = attackeratkbuffup;	//上がった分のステータスを記憶(剣士)
					mskill6.attackerdefbuff2 = attackerdefbuffup;	//上がった分のステータスを記憶(剣士)
					mskill6.shieldatkbuff2 = shieldatkbuffup;		//上がった分のステータスを記憶(騎士)
					mskill6.shielddefbuff2 = shielddefbuffup;		//上がった分のステータスを記憶(騎士)
					mskill6.magicatkbuff2 = magicatkbuffup;			//上がった分のステータスを記憶(魔術師)
					mskill6.magicdefbuff2 = magicdefbuffup;			//上がった分のステータスを記憶(魔術師)
					mskill6.healeratkbuff2 = healeratkbuffup;		//上がった分のステータスを記憶(聖職者)
					mskill6.healerdefbuff2 = healerdefbuffup;		//上がった分のステータスを記憶(聖職者)
				}
				else if (mskill6.buffturn3 == 0) {
					mskill6.buffturn3 = 3;
					mskill6.attackeratkbuff3 = attackeratkbuffup;	//上がった分のステータスを記憶(剣士)
					mskill6.attackerdefbuff3 = attackerdefbuffup;	//上がった分のステータスを記憶(剣士)
					mskill6.shieldatkbuff3 = shieldatkbuffup;		//上がった分のステータスを記憶(騎士)
					mskill6.shielddefbuff3 = shielddefbuffup;		//上がった分のステータスを記憶(騎士)
					mskill6.magicatkbuff3 = magicatkbuffup;			//上がった分のステータスを記憶(魔術師)
					mskill6.magicdefbuff3 = magicdefbuffup;			//上がった分のステータスを記憶(魔術師)
					mskill6.healeratkbuff3 = healeratkbuffup;		//上がった分のステータスを記憶(聖職者)
					mskill6.healerdefbuff3 = healerdefbuffup;		//上がった分のステータスを記憶(聖職者)
				}
				else if (mskill6.buffturn4 == 0) {
					mskill6.buffturn4 = 3;
					mskill6.attackeratkbuff4 = attackeratkbuffup;	//上がった分のステータスを記憶(剣士)
					mskill6.attackerdefbuff4 = attackerdefbuffup;	//上がった分のステータスを記憶(剣士)
					mskill6.shieldatkbuff4 = shieldatkbuffup;		//上がった分のステータスを記憶(騎士)
					mskill6.shielddefbuff4 = shielddefbuffup;		//上がった分のステータスを記憶(騎士)
					mskill6.magicatkbuff4 = magicatkbuffup;			//上がった分のステータスを記憶(魔術師)
					mskill6.magicdefbuff4 = magicdefbuffup;			//上がった分のステータスを記憶(魔術師)
					mskill6.healeratkbuff4 = healeratkbuffup;		//上がった分のステータスを記憶(聖職者)
					mskill6.healerdefbuff4 = healerdefbuffup;		//上がった分のステータスを記憶(聖職者)
				}

				//ステータスアップ表記
				auto pl3buffup = CCLabelTTF::create("味方の攻撃力と防御力が大幅に上がった", "HGRSGU.TTC", fontsizeL);
				pl3buffup->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl3buffup, backdepth, buffupS);
			}
			//スキル終わり
			if (skillflame == flame150) {
				this->removeChildByTag(mskill1E);			//ぐるぐるしてるやつ
				this->removeChildByTag(magicdamageS);			//ダメージ表記を消す
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//魔力吸収
		if (mskill == MSKILL7) {
			//味方単体のMPを10%吸収し自身のMPを回復する
		}
		//心呼吸
		if (mskill == MSKILL8) {
			if (gameflame == flame50) {
				//3ターンの間、自身のMPを小回復
				//プレイヤー3のMANAを減らす
				magic.mana -= 4;
				//MANAの数値を変える
				magicmnal->setString(std::to_string(magic.mana));
				//魔術師のmanaを回復させる
				recovery = magic.manamax / skilluplittle;
		
				//ダメージ表記
				String *p3skl = String::createWithFormat("魔術師は%iダメージ与えた", recovery);
				string _p3skl = p3skl->getCString();
				auto p3slabel = Label::createWithSystemFont(_p3skl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, magicdamageS);
			}
			//スキル終わり
			if (skillflame == flame250) {
				this->removeChildByTag(mskill1E);			//ぐるぐるしてるやつ
				this->removeChildByTag(magicdamageS);			//ダメージ表記を消す
				skillendflag = true;
			}
		}
	}
//聖職者
	if (job == HEALER) {
		//魔力供給
		if (hskill == HSKILL1) {
			if (gameflame == flame50) {
				//味方単体に自身のMPを小与える
				//聖職者のMANAを減らす
				recovery = manarecovery;
				healer.mana -= recovery;
				//MANAの数値を変える
				healermnal->setString(std::to_string(healer.mana));
				//選んだキャラを回復させる
				if (hskillchoice == ATTACKER) {
					attacker.mana += recovery;								//マナ回復
					attackermnal->setString(std::to_string(attacker.mana));	//マナの数字を変える
				}
				else if (hskillchoice == HEALER) {
					healer.mana += recovery;
					healermnal->setString(std::to_string(healer.mana));
				}
				else if (hskillchoice == MAGIC) {
					magic.mana += recovery;
					magicmnal->setString(std::to_string(magic.mana));
				}
				//ダメージ表記
				String *healerskl = String::createWithFormat("聖職者は%i回復させた", recovery);
				string _healerskl = healerskl->getCString();
				auto p3slabel = Label::createWithSystemFont(_healerskl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, healerdamageS);
			}
			//スキル終わり
			if (skillflame == flame80) {
				this->removeChildByTag(hskill1E);				//エフェクトを消す
				this->removeChildByTag(healerdamageS);				//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//死者の経典
		if (hskill == HSKILL2) {
			if (gameflame == flame50) {
				//敵単体の攻撃力中ダウン
				//プレイヤー１のMANAを減らす
				healer.mana -= 5;
				//MANAの数値を変える
				healermnal->setString(std::to_string(healer.mana));
				//ボスの攻撃力を中ダウン
				buffdown = valkyrie.atk * buffdownlarge;
				valkyrie.atk = buffdown;

				//スキル効果ターンによる処理
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

				//ステータスアップ表記
				auto pl2buffdown = CCLabelTTF::create("敵の攻撃力を下げた", "HGRSGU.TTC", fontsizeL);
				pl2buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl2buffdown, backdepth, buffupS);
				
			}
			//スキル終わり
			if (skillflame == flame80) {
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//聖者の経典
		if (hskill == HSKILL3) {
			if (gameflame == flame50) {
				//敵単体の防御力中ダウン
				//プレイヤー１のMANAを減らす
				healer.mana -= 5;
				//MANAの数値を変える
				healermnal->setString(std::to_string(healer.mana));
				//ボスの攻撃力を中ダウン
				buffdown = valkyrie.def * buffdownlarge;
				valkyrie.def = buffdown;

				//スキル効果ターンによる処理
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

				//ステータスアップ表記
				auto pl2buffdown = CCLabelTTF::create("敵の防御力を下げた", "HGRSGU.TTC", fontsizeL);
				pl2buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl2buffdown, backdepth, buffupS);

			}
			//スキル終わり
			if (skillflame == flame80) {
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//セイントローグ
		if (hskill == HSKILL4) {
			if (gameflame == flame50) {
				//味方単体のHPを小回復
				//エフェクトの表示
				//エフェクトの流れを指定
				CCParticleSystemQuad* plparticle2 = CCParticleSystemQuad::create("Effect/plskill1.plist");

				plparticle2->setAutoRemoveOnFinish(true);

				//エフェクト処理
				//パーティクル開始
				plparticle2->resetSystem();								

				//剣士を選ぶ場合
				if (hskillchoice == ATTACKER) {
					if (pl1frame.choicejob == ATTACKER) {
						plparticle2->setPosition(ccp(rightSize.width / 4.1f,
							rightSize.height / 5));							//パーティクルを表示する場所の設定
					}
					else if (pl2frame.choicejob == ATTACKER) {
						plparticle2->setPosition(ccp(rightSize.width / 2,
							rightSize.height / 5));							//パーティクルを表示する場所の設定
					}
					else if (pl3frame.choicejob == ATTACKER) {
						plparticle2->setPosition(ccp(rightSize.width / 1.32f,
							rightSize.height / 5));							//パーティクルを表示する場所の設定
					}
				}
				//騎士を選ぶ場合
				if (hskillchoice == SHIELD) {
					if (pl1frame.choicejob == SHIELD) {
						plparticle2->setPosition(ccp(rightSize.width / 4.1f,
							rightSize.height / 5));							//パーティクルを表示する場所の設定
					}
					else if (pl2frame.choicejob == SHIELD) {
						plparticle2->setPosition(ccp(rightSize.width / 2,
							rightSize.height / 5));							//パーティクルを表示する場所の設定
					}
					else if (pl3frame.choicejob == SHIELD) {
						plparticle2->setPosition(ccp(rightSize.width / 1.32f,
							rightSize.height / 5));							//パーティクルを表示する場所の設定
					}
				}
				//魔術師を選ぶ場合
				if (hskillchoice == MAGIC) {
					if (pl1frame.choicejob == MAGIC) {
						plparticle2->setPosition(ccp(rightSize.width / 4.1f,
							rightSize.height / 5));							//パーティクルを表示する場所の設定
					}
					else if (pl2frame.choicejob == MAGIC) {
						plparticle2->setPosition(ccp(rightSize.width / 2,
							rightSize.height / 5));							//パーティクルを表示する場所の設定
					}
					else if (pl3frame.choicejob == MAGIC) {
						plparticle2->setPosition(ccp(rightSize.width / 1.32f,
							rightSize.height / 5));							//パーティクルを表示する場所の設定
					}
				}
				//聖職者
				if (hskillchoice == HEALER) {
					if (pl1frame.choicejob == HEALER) {
						plparticle2->setPosition(ccp(rightSize.width / 4.1f,
							rightSize.height / 5));							//パーティクルを表示する場所の設定
					}
					else if (pl2frame.choicejob == HEALER) {
						plparticle2->setPosition(ccp(rightSize.width / 2,
							rightSize.height / 5));							//パーティクルを表示する場所の設定
					}
					else if (pl3frame.choicejob == HEALER) {
						plparticle2->setPosition(ccp(rightSize.width / 1.32f,
							rightSize.height / 5));							//パーティクルを表示する場所の設定
					}
				}
				//パーティクルを配置
				this->addChild(plparticle2, backdepth, hskill1E);		


				//聖職者のMANAを減らす
				healer.mana -= 2;
				//MANAの数値を変える
				healermnal->setString(std::to_string(healer.mana));
				//選んだキャラを回復させる
				//剣士
				if (hskillchoice == ATTACKER) {
					attacker.hp += recovery_rnd;						//回復
					attackerhpal->setString(std::to_string(attacker.hp));		//HPの数字を変える
				}
				//騎士
				else if (hskillchoice == SHIELD) {
					shield.hp += recovery_rnd;
					shieldhpal->setString(std::to_string(shield.hp));
				}
				//魔術師
				else if (hskillchoice == MAGIC) {
					magic.hp += recovery_rnd;
					magichpal->setString(std::to_string(magic.hp));
				}
				//聖職者
				else if (hskillchoice == HEALER) {
					healer.hp += recovery_rnd;
					healerhpal->setString(std::to_string(healer.hp));
				}
				//ダメージ表記
				String *healerskl = String::createWithFormat("聖職者は%i回復させた", recovery_rnd);
				string _healerskl = healerskl->getCString();
				auto p3slabel = Label::createWithSystemFont(_healerskl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, healerdamageS);
			}
			//スキル終わり
			if (skillflame == flame100) {
				this->removeChildByTag(hskill1E);				//エフェクトを消す
				this->removeChildByTag(healerdamageS);			//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//聖闘士ぺーパー
		if (hskill == HSKILL5) {
			if (gameflame == flame50) {
				//味方単体のHPを中回復
				//聖職者のMANAを減らす
				healer.mana -= 3;
				//MANAの数値を変える
				healermnal->setString(std::to_string(healer.mana));
				//選んだキャラを回復させる
				//剣士
				if (hskillchoice == ATTACKER) {
					attacker.hp += recovery_rnd;							//回復
					attackerhpal->setString(std::to_string(attacker.hp));	//HPの数字を変える
				}
				//騎士
				else if (hskillchoice == SHIELD) {
					shield.hp += recovery_rnd;
					shieldhpal->setString(std::to_string(shield.hp));
				}
				//聖職者
				else if (hskillchoice == HEALER) {
					healer.hp += recovery_rnd;
					healerhpal->setString(std::to_string(healer.hp));
				}
				//魔術師
				else if (hskillchoice == MAGIC) {
					magic.hp += recovery_rnd;
					magichpal->setString(std::to_string(magic.hp));
				}
				//ダメージ表記
				String *healerskl = String::createWithFormat("聖職者は%i回復させた", recovery_rnd);
				string _healerskl = healerskl->getCString();
				auto p3slabel = Label::createWithSystemFont(_healerskl, "HGRSGU.TTC", fontsizeL);
				p3slabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(p3slabel, backdepth, healerdamageS);
			}
			//スキル終わり
			if (skillflame == flame80) {
				this->removeChildByTag(hskill1E);				//エフェクトを消す
				this->removeChildByTag(healerdamageS);			//ダメージ表記を消す
				skillendflag = true;
			}
		}
		//聖者の祈り
		if (hskill == HSKILL6) {
			if (gameflame == flame50) {
				//味方全体のHPを小回復
				//プレイヤー１のMANAを減らす
				healer.mana -= 4;
				//MANAの数値を変える
				healermnal->setString(std::to_string(healer.mana));
				//プレイヤー全員のHPを小回復
				attacker.hp += recovery_rnd;
				healer.hp += recovery_rnd;
				magic.hp += recovery_rnd;
				//プレイヤーのHPの数値を変える
				attackerhpal->setString(std::to_string(attacker.hp));
				healerhpal->setString(std::to_string(healer.hp));
				magichpal->setString(std::to_string(magic.hp));

				//ステータスアップ表記
				auto pl2buffdown = CCLabelTTF::create("味方のHPが少し回復した", "HGRSGU.TTC", fontsizeL);
				pl2buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl2buffdown, backdepth, buffupS);

			}
			//スキル終わり
			if (skillflame == flame80) {
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//セイントオーダー
		if (hskill == HSKILL7) {
			if (gameflame == flame50) {
				//味方全体のHPを大回復
				//プレイヤー１のMANAを減らす
				healer.mana -= 7;
				//MANAの数値を変える
				healermnal->setString(std::to_string(healer.mana));
				//プレイヤー全員のHPを大回復
				attacker.hp += recoveryall;
				shield.hp += recoveryall;
				healer.hp += recoveryall;
				magic.hp += recoveryall;
				//プレイヤーのHPの数値を変える
				attackerhpal->setString(std::to_string(attacker.hp));
				shieldhpal->setString(std::to_string(shield.hp));
				healerhpal->setString(std::to_string(healer.hp));
				magichpal->setString(std::to_string(magic.hp));

				//ステータスアップ表記
				auto pl2buffdown = CCLabelTTF::create("味方のHPが少し回復した", "HGRSGU.TTC", fontsizeL);
				pl2buffdown->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(pl2buffdown, backdepth, buffupS);

			}
			//スキル終わり
			if (skillflame == flame80) {
				this->removeChildByTag(buffupS);
				skillendflag = true;
			}
		}
		//神の啓示
		if (hskill == HSKILL8) {
			if (gameflame == flame50) {
				//味方単体を戦闘不能状態から復活させる

				//聖職者のMANAを減らす
				healer.mana -= 7;
				//MANAの数値を変える
				healermnal->setString(std::to_string(healer.mana));
				//選んだキャラを復活させる
				//剣士
				if (hskillchoice == ATTACKER) {
					attacker.hp += attacker.hpmax;							//回復
					attackerhpal->setString(std::to_string(attacker.hp));	//HPの数字を変える
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
				//騎士
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
				//聖職者
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
				//魔術師
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
				//剣士を選んだ場合
				if (sskillchoice == ATTACKER) {
					//効果表記
					auto revival = CCLabelTTF::create("剣士の代わりに攻撃を受ける", "HGRSGU.TTC", fontsizeL);
					revival->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
					this->addChild(revival, backdepth, insteadS);
				}
				//騎士を選んだ場合
				else if (sskillchoice == SHIELD) {
					auto revival = CCLabelTTF::create("騎士の代わりに攻撃を受ける", "HGRSGU.TTC", fontsizeL);
					revival->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
					this->addChild(revival, backdepth, insteadS);
				}
				//魔術師を選んだ場合
				else if (sskillchoice == MAGIC) {
					auto revival = CCLabelTTF::create("魔術師の代わりに攻撃を受ける", "HGRSGU.TTC", fontsizeL);
					revival->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
					this->addChild(revival, backdepth, insteadS);
				}
			}
			//スキル終わり
			if (skillflame == flame80) {
				this->removeChildByTag(hskill1E);			//エフェクトを消す
				this->removeChildByTag(insteadS);			//ダメージ表記を消す
				skillendflag = true;
			}
		}
	}
}

void BossScene::BSturn()
{
	//狙うプレイヤーを決める
	if (bsact == PICK) {
		//聖職者がいないとき
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
					//タゲ集中が働いているのなら
					else if (coverflag1 == true || coverflag2 == true || allinsteadflag == true) {
						job = SHIELD;
					}
				}
			}
		}
		//剣士がいないとき
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
					//タゲ集中が働いているのなら
					else if (coverflag1 == true || coverflag2 == true || allinsteadflag == true) {
						job = SHIELD;
					}
				}
			}
		}
		//騎士がいないとき
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
					//タゲ集中が働いているのなら
					else if (coverflag1 == true || coverflag2 == true || allinsteadflag == true) {
						job = SHIELD;
					}
				}
			}
		}
		//魔術師がいないとき
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
					//タゲ集中が働いているのなら
					else if (coverflag1 == true || coverflag2 == true || allinsteadflag == true) {
						job = SHIELD;
					}
				}
			}
		}
		bsact = DECIDE;
	}

	//通常攻撃かスキルかを決める
	if (bsact == DECIDE) {
		if (decide_rnd < sixtypercent) {
			bsact = BOSSATTACK;
		}
		if (decide_rnd >= sixtypercent && decide_rnd <= rndmax) {
			bsact = BOSSSKILL;
		}
	}

	//どのスキルで攻撃するかを決める
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

	//選んだキャラを出力に表示
	log("job %i", job);
	//カウントを出力に表示
	log("skill_rnd %i", skill_rnd);
	//プレイヤー1のHPを表示
	CCString *hpstr1 = CCString::createWithFormat("現在PL1HPは%dです", attacker.hp);
	log("%s", hpstr1->getCString());
	//プレイヤー2のHPを表示
	CCString *hpstr2 = CCString::createWithFormat("現在PL2HPは%dです", healer.hp);
	log("%s", hpstr2->getCString());
	//プレイヤー3のHPを表示
	CCString *hpstr3 = CCString::createWithFormat("現在PL3HPは%dです", magic.hp);
	log("%s", hpstr3->getCString());
	//ボスのHPを表示
	CCString *hpstrBS = CCString::createWithFormat("現在ヴァルキリーHPは%dです", valkyrie.hp);
	log("%s", hpstrBS->getCString());

	//攻撃モードの時
	if (bsact == BOSSATTACK) {
		if (gameflame == flame80) {
			//フレームが80(仮)になったら文字を表示する
			auto atk = CCLabelTTF::create("「やあっ！(通常攻撃)」", "HGRSGU.TTC", fontsizeL);
			atk->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
			this->addChild(atk, backdepth, normalattackS);
			//ボスの画像を揺らす処理
			auto move = CCSequence::create(
				CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f + moverange)),
				CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f)),
				NULL
			);
			//揺らす
			auto repeat = Repeat::create(move, 1);
			Boss->runAction(repeat);

			//ダメージを受けた時に揺らす処理
			Damage();				

			//騎士の単体身代わりスキルが発動していないとき
			if (insteadflag == false) {
				//剣士
				if (job == ATTACKER) {
					hpcut = (valkyrie.atk - attacker.def);					//減らすHPを計算
					//もし減らすHPが1以下の場合1にする
					if (hpcut <= 1) {
						hpcut = 1;
					}
					attacker.hp -= hpcut;										//HPを減らす
					PLattacker->setColor(ccc3(colormax, colordown, colordown));	//ダメージを受けるプレイヤーは赤くする
					attackerhpal->setString(std::to_string(attacker.hp));		//ダメージを受けるプレイヤーのHPを減らす
					attackerdmf->setString(std::to_string(hpcut));	//ダメージを変化させる
					this->addChild(attackerdmf, onece);				//ダメージ文字を出す
					attackerdmf->runAction(attackerfadeout);		//ダメージ文字をフェードアウトさせる
					attackerdmf->runAction(attackerfdoutmov);		//ダメージ文字を上に動かす
					PLattacker->runAction(attacker_repeat_smallquake[0]);
					attackerHP->runAction(attacker_repeat_smallquake[1]);
					attackerMN->runAction(attacker_repeat_smallquake[2]);
					attackerhpal->runAction(attacker_repeat_smallquake[3]);
					attackerhpmaxal->runAction(attacker_repeat_smallquake[4]);
					attackermnal->runAction(attacker_repeat_smallquake[5]);
					attackermnmaxal->runAction(attacker_repeat_smallquake[6]);
				}
				//騎士
				else if (job == SHIELD) {
					hpcut = (valkyrie.atk - shield.def);
					//もし減らすHPが1以下の場合1にする
					if (hpcut <= 1) {
						hpcut = 1;
					}
					shield.hp -= hpcut;
					PLshield->setColor(ccc3(colormax, colordown, colordown));
					shieldhpal->setString(std::to_string(shield.hp));
					shielddmf->setString(std::to_string(hpcut));	//ダメージを変化させる
					this->addChild(shielddmf, onece);				//ダメージ文字を出す
					shielddmf->runAction(shieldfadeout);			//ダメージ文字をフェードアウトさせる
					shielddmf->runAction(shieldfdoutmov);			//ダメージ文字を上に動かす
					PLshield->runAction(shieldrepeat1b);
					shieldHP->runAction(shieldrepeat2b);
					shieldMN->runAction(shieldrepeat3b);
					shieldhpal->runAction(shieldrepeat4b);
					shieldhpmaxal->runAction(shieldrepeat5b);
					shieldmnal->runAction(shieldrepeat6b);
					shieldmnmaxal->runAction(shieldrepeat7b);
				}
				//魔術師
				else if (job == MAGIC) {
					if (insteadflag == false) {
						hpcut = (valkyrie.atk - magic.def);
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						magic.hp -= hpcut;
						PLmagic->setColor(ccc3(colormax, colordown, colordown));
						magichpal->setString(std::to_string(magic.hp));
						magicdmf->setString(std::to_string(hpcut));		//ダメージを変化させる
						this->addChild(magicdmf, onece);				//ダメージ文字を出す
						magicdmf->runAction(magicfadeout);				//ダメージ文字をフェードアウトさせる
						magicdmf->runAction(magicfdoutmov);				//ダメージ文字を上に動かす
						PLmagic->runAction(magicrepeat1b);
						magicHP->runAction(magicrepeat2b);
						magicMN->runAction(magicrepeat3b);
						magichpal->runAction(magicrepeat4b);
						magichpmaxal->runAction(magicrepeat5b);
						magicmnal->runAction(magicrepeat6b);
						magicmnmaxal->runAction(magicrepeat7b);
					}
				}
				//聖職者
				else if (job == HEALER) {
					if (insteadflag == false) {
						hpcut = (valkyrie.atk - healer.def);
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						healer.hp -= hpcut;
						PLhealer->setColor(ccc3(colormax, colordown, colordown));
						healerhpal->setString(std::to_string(healer.hp));
						healerdmf->setString(std::to_string(hpcut));	//ダメージを変化させる
						this->addChild(healerdmf, onece);				//ダメージ文字を出す
						healerdmf->runAction(healerfadeout);			//ダメージ文字をフェードアウトさせる
						healerdmf->runAction(healerfdoutmov);			//ダメージ文字を上に動かす
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

			//騎士の単体身代わりスキルが発動しているとき
			if (insteadflag == true) {
				//剣士を選んだ場合
				if (sskillchoice == ATTACKER) {
					//剣士
					if (job == ATTACKER) {
						hpcut = (valkyrie.atk * skillupmedium) - shield.def;//減らすダメージを計算
																			//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;									//HPを減らす
						shielddmf->setString(std::to_string(hpcut));		//ダメージを変化させる
						this->addChild(shielddmf, onece);					//ダメージ文字を出す
						shielddmf->runAction(shieldfadeout);				//ダメージ文字をフェードアウトさせる
						shielddmf->runAction(shieldfdoutmov);				//ダメージ文字を上に動かす
						shieldhpal->setString(std::to_string(shield.hp));
						PLshield->runAction(shieldrepeat1a);
						shieldHP->runAction(shieldrepeat2a);
						shieldMN->runAction(shieldrepeat3a);
						shieldhpal->runAction(shieldrepeat4a);
						shieldhpmaxal->runAction(shieldrepeat5a);
						shieldmnal->runAction(shieldrepeat6a);
						shieldmnmaxal->runAction(shieldrepeat7a);
					}
					//騎士
					if (job == SHIELD) {
						hpcut = (valkyrie.atk - shield.def);
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;
						PLshield->setColor(ccc3(colormax, colordown, colordown));
						shielddmf->setString(std::to_string(hpcut));				//ダメージを変化させる
						this->addChild(shielddmf, onece);							//ダメージ文字を出す
						shielddmf->runAction(shieldfadeout);						//ダメージ文字をフェードアウトさせる
						shielddmf->runAction(shieldfdoutmov);						//ダメージ文字を上に動かす
						shieldhpal->setString(std::to_string(shield.hp));
						PLshield->runAction(shieldrepeat1a);
						shieldHP->runAction(shieldrepeat2a);
						shieldMN->runAction(shieldrepeat3a);
						shieldhpal->runAction(shieldrepeat4a);
						shieldhpmaxal->runAction(shieldrepeat5a);
						shieldmnal->runAction(shieldrepeat6a);
						shieldmnmaxal->runAction(shieldrepeat7a);
					}
					//魔術師
					if (job == MAGIC) {
						hpcut = (valkyrie.atk - magic.def);
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						magic.hp -= hpcut;
						PLmagic->setColor(ccc3(colormax, colordown, colordown));
						magicdmf->setString(std::to_string(hpcut));				//ダメージを変化させる
						this->addChild(magicdmf, onece);							//ダメージ文字を出す
						magicdmf->runAction(magicfadeout);						//ダメージ文字をフェードアウトさせる
						magicdmf->runAction(magicfdoutmov);						//ダメージ文字を上に動かす
						magichpal->setString(std::to_string(magic.hp));
						PLmagic->runAction(magicrepeat1a);
						magicHP->runAction(magicrepeat2a);
						magicMN->runAction(magicrepeat3a);
						magichpal->runAction(magicrepeat4a);
						magichpmaxal->runAction(magicrepeat5a);
						magicmnal->runAction(magicrepeat6a);
						magicmnmaxal->runAction(magicrepeat7a);
					}
					//聖職者
					if (job == HEALER) {
						hpcut = (valkyrie.atk - healer.def);
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						healer.hp -= hpcut;
						PLhealer->setColor(ccc3(colormax, colordown, colordown));
						healerdmf->setString(std::to_string(hpcut));				//ダメージを変化させる
						this->addChild(healerdmf, onece);							//ダメージ文字を出す
						healerdmf->runAction(healerfadeout);						//ダメージ文字をフェードアウトさせる
						healerdmf->runAction(healerfdoutmov);						//ダメージ文字を上に動かす
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
				//魔術師を選んだ場合
				if (sskillchoice == MAGIC) {
					//剣士
					if (job == ATTACKER) {
						hpcut = (valkyrie.atk * skillupmedium) - attacker.def;	//減らすダメージを計算
																				//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						attacker.hp -= hpcut;									//HPを減らす
						attackerdmf->setString(std::to_string(hpcut));			//ダメージを変化させる
						this->addChild(attackerdmf, onece);						//ダメージ文字を出す
						attackerdmf->runAction(attackerfadeout);				//ダメージ文字をフェードアウトさせる
						attackerdmf->runAction(attackerfdoutmov);				//ダメージ文字を上に動かす
						attackerhpal->setString(std::to_string(attacker.hp));
						PLattacker->runAction(attacker_repeat_smallquake[0]);
						attackerHP->runAction(attacker_repeat_smallquake[1]);
						attackerMN->runAction(attacker_repeat_smallquake[2]);
						attackerhpal->runAction(attacker_repeat_smallquake[3]);
						attackerhpmaxal->runAction(attacker_repeat_smallquake[4]);
						attackermnal->runAction(attacker_repeat_smallquake[5]);
						attackermnmaxal->runAction(attacker_repeat_smallquake[6]);
					}
					//騎士
					if (job == SHIELD) {
						hpcut = (valkyrie.atk - shield.def);
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;
						PLshield->setColor(ccc3(colormax, colordown, colordown));
						shielddmf->setString(std::to_string(hpcut));			//ダメージを変化させる
						this->addChild(shielddmf, onece);						//ダメージ文字を出す
						shielddmf->runAction(shieldfadeout);					//ダメージ文字をフェードアウトさせる
						shielddmf->runAction(shieldfdoutmov);					//ダメージ文字を上に動かす
						shieldhpal->setString(std::to_string(shield.hp));
						PLshield->runAction(shieldrepeat1a);
						shieldHP->runAction(shieldrepeat2a);
						shieldMN->runAction(shieldrepeat3a);
						shieldhpal->runAction(shieldrepeat4a);
						shieldhpmaxal->runAction(shieldrepeat5a);
						shieldmnal->runAction(shieldrepeat6a);
						shieldmnmaxal->runAction(shieldrepeat7a);
					}
					//魔術師
					if (job == MAGIC) {
						//魔術師の代わりに騎士がダメージをくらう
						hpcut = (valkyrie.atk * skillupmedium) - shield.def;//減らすダメージを計算
																			//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;									//HPを減らす
						shielddmf->setString(std::to_string(hpcut));		//ダメージを変化させる
						this->addChild(shielddmf, onece);					//ダメージ文字を出す
						shielddmf->runAction(shieldfadeout);				//ダメージ文字をフェードアウトさせる
						shielddmf->runAction(shieldfdoutmov);				//ダメージ文字を上に動かす
						magichpal->setString(std::to_string(magic.hp));
						PLshield->runAction(shieldrepeat1a);
						shieldHP->runAction(shieldrepeat2a);
						shieldMN->runAction(shieldrepeat3a);
						shieldhpal->runAction(shieldrepeat4a);
						shieldhpmaxal->runAction(shieldrepeat5a);
						shieldmnal->runAction(shieldrepeat6a);
						shieldmnmaxal->runAction(shieldrepeat7a);

					}
					//聖職者
					if (job == HEALER) {
						hpcut = (valkyrie.atk - healer.def);
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						healer.hp -= hpcut;
						PLhealer->setColor(ccc3(colormax, colordown, colordown));
						healerdmf->setString(std::to_string(hpcut));				//ダメージを変化させる
						this->addChild(healerdmf, onece);							//ダメージ文字を出す
						healerdmf->runAction(healerfadeout);						//ダメージ文字をフェードアウトさせる
						healerdmf->runAction(healerfdoutmov);						//ダメージ文字を上に動かす
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
				//聖職者を選んだ場合
				if (sskillchoice == HEALER) {
					//剣士
					if (job == ATTACKER) {
						hpcut = (valkyrie.atk * skillupmedium) - attacker.def;//減らすダメージを計算
																			  //もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						attacker.hp -= hpcut;									//HPを減らす
						attackerdmf->setString(std::to_string(hpcut));			//ダメージを変化させる
						this->addChild(attackerdmf, onece);						//ダメージ文字を出す
						attackerdmf->runAction(attackerfadeout);				//ダメージ文字をフェードアウトさせる
						attackerdmf->runAction(attackerfdoutmov);				//ダメージ文字を上に動かす
						attackerhpal->setString(std::to_string(attacker.hp));
						PLattacker->runAction(attacker_repeat_smallquake[0]);
						attackerHP->runAction(attacker_repeat_smallquake[1]);
						attackerMN->runAction(attacker_repeat_smallquake[2]);
						attackerhpal->runAction(attacker_repeat_smallquake[3]);
						attackerhpmaxal->runAction(attacker_repeat_smallquake[4]);
						attackermnal->runAction(attacker_repeat_smallquake[5]);
						attackermnmaxal->runAction(attacker_repeat_smallquake[6]);
					}
					//騎士
					if (job == SHIELD) {
						hpcut = (valkyrie.atk - shield.def);
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;
						PLshield->setColor(ccc3(colormax, colordown, colordown));
						shielddmf->setString(std::to_string(hpcut));			//ダメージを変化させる
						this->addChild(shielddmf, onece);						//ダメージ文字を出す
						shielddmf->runAction(shieldfadeout);					//ダメージ文字をフェードアウトさせる
						shielddmf->runAction(shieldfdoutmov);					//ダメージ文字を上に動かす
						shieldhpal->setString(std::to_string(shield.hp));
						PLshield->runAction(shieldrepeat1a);
						shieldHP->runAction(shieldrepeat2a);
						shieldMN->runAction(shieldrepeat3a);
						shieldhpal->runAction(shieldrepeat4a);
						shieldhpmaxal->runAction(shieldrepeat5a);
						shieldmnal->runAction(shieldrepeat6a);
						shieldmnmaxal->runAction(shieldrepeat7a);
					}
					//魔術師
					if (job == MAGIC) {
						hpcut = (valkyrie.atk - magic.def);
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						magic.hp -= hpcut;
						PLmagic->setColor(ccc3(colormax, colordown, colordown));
						magicdmf->setString(std::to_string(hpcut));				//ダメージを変化させる
						this->addChild(magicdmf, onece);						//ダメージ文字を出す
						magicdmf->runAction(magicfadeout);						//ダメージ文字をフェードアウトさせる
						magicdmf->runAction(magicfdoutmov);						//ダメージ文字を上に動かす
						magichpal->setString(std::to_string(magic.hp));
						PLmagic->runAction(magicrepeat1a);
						magicHP->runAction(magicrepeat2a);
						magicMN->runAction(magicrepeat3a);
						magichpal->runAction(magicrepeat4a);
						magichpmaxal->runAction(magicrepeat5a);
						magicmnal->runAction(magicrepeat6a);
						magicmnmaxal->runAction(magicrepeat7a);
					}
					//聖職者
					if (job == HEALER) {
						//聖職者の代わりに騎士がダメージをくらう
						hpcut = (valkyrie.atk * skillupmedium) - shield.def;//減らすダメージを計算
																			//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;									//HPを減らす
						shielddmf->setString(std::to_string(hpcut));		//ダメージを変化させる
						this->addChild(shielddmf, onece);					//ダメージ文字を出す
						shielddmf->runAction(shieldfadeout);				//ダメージ文字をフェードアウトさせる
						shielddmf->runAction(shieldfdoutmov);				//ダメージ文字を上に動かす
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
		//キャラ画像の色を戻す
		if (gameflame == flame100) {
			PLattacker->setColor(ccc3(colormax, colormax, colormax));
			PLshield->setColor(ccc3(colormax, colormax, colormax));
			PLhealer->setColor(ccc3(colormax, colormax, colormax));
			PLmagic->setColor(ccc3(colormax, colormax, colormax));
		}

		//効果処理
		//フレームが230(仮)になると効果を表記
		if (gameflame == flame230) {
			if (job == ATTACKER) {
				//ダメージ表記
				String *attackerbsatk = String::createWithFormat("剣士に%iダメージ与えた", hpcut);
				string _attackerbsatk = attackerbsatk->getCString();
				auto attackerbsalabel = Label::createWithSystemFont(_attackerbsatk, "HGRSGU.TTC", fontsizeL);
				attackerbsalabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(attackerbsalabel, backdepth, damageS);
			}
			else if (job == SHIELD) {
				//ダメージ表記
				String *shieldbsatk = String::createWithFormat("騎士に%iダメージ与えた", hpcut);
				string _shieldbsatk = shieldbsatk->getCString();
				auto shieldalabel = Label::createWithSystemFont(_shieldbsatk, "HGRSGU.TTC", fontsizeL);
				shieldalabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(shieldalabel, backdepth, damageS);
			}
			else if (job == MAGIC) {
				//ダメージ表記
				String *magicbsatk = String::createWithFormat("魔術師に%iダメージ与えた", hpcut);
				string _magicbsatk = magicbsatk->getCString();
				auto magicalabel = Label::createWithSystemFont(_magicbsatk, "HGRSGU.TTC", fontsizeL);
				magicalabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(magicalabel, backdepth, damageS);
			}
			else if (job == HEALER) {
				//ダメージ表記
				String *healerbsatk = String::createWithFormat("聖職者に%iダメージ与えた", hpcut);
				string _healerbsatk = healerbsatk->getCString();
				auto healeralabel = Label::createWithSystemFont(_healerbsatk, "HGRSGU.TTC", fontsizeL);
				healeralabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(healeralabel, backdepth, damageS);
			}
		}
	}
	//ヴァルキリースキル
	if (bsact == BOSSSKILL) {
		//一の太刀
		if (bskill == BSKILL1) {
			//フレームが80(仮)になるとスキルの名前表示
			if (gameflame == flame80) {
				auto Gskill1 = CCLabelTTF::create("「くらえ…！」", "JiyunoTsubasa.ttf", fontsizeL);
				Gskill1->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill1, backdepth, bossskill1S);
			}
			//揺らす処理
			if (gameflame == flame210) {
				auto move = CCSequence::create(
					CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f + 30)),
					CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 1.7f)),
					NULL
				);
				//揺らす
				auto repeat = Repeat::create(move, 1);
				Boss->runAction(repeat);

				// 画面サイズ取得
				Size winSize = Director::getInstance()->getVisibleSize();

				//背景を揺らす
				auto backmove = CCSequence::create(
					CCMoveTo::create(movecnt, ccp(winSize.width / 2, winSize.height / 1.5f + 30)),
					CCMoveTo::create(movecnt, ccp(winSize.width / 2, winSize.height / 1.5f)),
					NULL
				);
				//何回揺らすか
				auto backrepeat = Repeat::create(backmove, continuity2);
				//揺らす
				back->runAction(backrepeat);

				//揺れる処理
				Damage();	//揺らす処理↓以下同文

				//騎士が庇うを使っていないなら
				if (insteadflag == false && allinsteadflag == false) {
					//剣士ダメージを受けた時に揺れる処理
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
					//騎士ダメージを受けた時に揺れる処理
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
					//魔術師ダメージを受けた時に揺れる処理
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
					//聖職者ダメージを受けた時に揺れる処理
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
					//プレイヤー全員のHPを減らす
					//受けたダメージをゲージ上に表示
					//剣士
					if (pl1frame.choicejob == ATTACKER || pl2frame.choicejob == ATTACKER
						|| pl3frame.choicejob == ATTACKER) {
						hpcut = (valkyrie.atk * skillupmedium) - attacker.def;	//減らすダメージを計算
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						attacker.hp -= hpcut;							//HPを減らす
						attackerdmf->setString(std::to_string(hpcut));	//ダメージを変化させる
						this->addChild(attackerdmf, onece);				//ダメージ文字を出す
						attackerdmf->runAction(attackerfadeout);		//フェードアウト処理
						attackerdmf->runAction(attackerfdoutmov);		//上に上がっていく処理
					}
					//騎士
					if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD
						|| pl3frame.choicejob == SHIELD) {
						hpcut = (valkyrie.atk * skillupmedium) - shield.def;//減らすダメージを計算
																		//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;								//HPを減らす
						shielddmf->setString(std::to_string(hpcut));	//ダメージを変化させる
						this->addChild(shielddmf, onece);				//ダメージ文字を出す
						shielddmf->runAction(shieldfadeout);			//ダメージ文字をフェードアウトさせる
						shielddmf->runAction(shieldfdoutmov);			//ダメージ文字を上に動かす
					}
					//魔術師
					if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC
						|| pl3frame.choicejob == MAGIC) {
						hpcut = (valkyrie.atk * skillupmedium) - magic.def;	//減らすダメージを計算
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						magic.hp -= hpcut;								//HPを減らす
						magicdmf->setString(std::to_string(hpcut));		//ダメージを変化させる
						this->addChild(magicdmf, onece);				//ダメージ文字を出す
						magicdmf->runAction(magicfadeout);				//ダメージ文字をフェードアウトさせる
						magicdmf->runAction(magicfdoutmov);				//ダメージ文字を上に動かす
					}
					//聖職者
					if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER
						|| pl3frame.choicejob == HEALER) {
						hpcut = (valkyrie.atk * skillupmedium) - healer.def;//減らすダメージを計算
																			//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						healer.hp -= hpcut;									//HPを減らす
						healerdmf->setString(std::to_string(hpcut));		//ダメージを変化させる
						this->addChild(healerdmf, onece);					//ダメージ文字を出す
						healerdmf->runAction(healerfadeout);				//ダメージ文字をフェードアウトさせる
						healerdmf->runAction(healerfdoutmov);				//ダメージ文字を上に動かす
					}
				}

				//騎士が単体庇うを使っているとき
				if (insteadflag == true) {
					//剣士を選んだ場合
					if (sskillchoice == ATTACKER) {
						//剣士の代わりに騎士がダメージをくらう
						if (pl1frame.choicejob == ATTACKER || pl2frame.choicejob == ATTACKER
							|| pl3frame.choicejob == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - shield.def;//減らすダメージを計算
							hpcut = max(1, hpcut);							//もし減らすHPが1以下の場合1にする
							shield.hp -= hpcut;								//HPを減らす
							shielddmf->setString(std::to_string(hpcut));	//ダメージを変化させる
							this->addChild(shielddmf, onece);				//ダメージ文字を出す
							shielddmf->runAction(shieldfadeout);			//ダメージ文字をフェードアウトさせる
							shielddmf->runAction(shieldfdoutmov);			//ダメージ文字を上に動かす
							PLshield->runAction(shieldrepeat1a);			//画像揺らす処理↓以下同文
							shieldHP->runAction(shieldrepeat2a);
							shieldMN->runAction(shieldrepeat3a);
							shieldhpal->runAction(shieldrepeat4a);
							shieldhpmaxal->runAction(shieldrepeat5a);
							shieldmnal->runAction(shieldrepeat6a);
							shieldmnmaxal->runAction(shieldrepeat7a);
						}
						//魔術師
						if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC
							|| pl3frame.choicejob == MAGIC) {
							hpcut = (valkyrie.atk * skillupmedium) - magic.def;	//減らすダメージを計算
							hpcut = max(1, hpcut);							//もし減らすHPが1以下の場合1にする
							magic.hp -= hpcut;								//HPを減らす
							magicdmf->setString(std::to_string(hpcut));		//ダメージを変化させる

							//ダメージ文字アクション
							this->addChild(magicdmf, onece);				//ダメージ文字を出す
							magicdmf->runAction(magicfadeout);				//ダメージ文字をフェードアウトさせる
							magicdmf->runAction(magicfdoutmov);				//ダメージ文字を上に動かす
							PLmagic->runAction(magicrepeat1a);
							magicHP->runAction(magicrepeat2a);
							magicMN->runAction(magicrepeat3a);
							magichpal->runAction(magicrepeat4a);
							magichpmaxal->runAction(magicrepeat5a);
							magicmnal->runAction(magicrepeat6a);
							magicmnmaxal->runAction(magicrepeat7a);
						}
						//聖職者
						if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER
							|| pl3frame.choicejob == HEALER) {
							hpcut = (valkyrie.atk * skillupmedium) - healer.def;//減らすダメージを計算
							hpcut = max(1, hpcut);							//もし減らすHPが1以下の場合1にする
							healer.hp -= hpcut;								//HPを減らす
							healerdmf->setString(std::to_string(hpcut));	//ダメージを変化させる
							this->addChild(healerdmf, onece);				//ダメージ文字を出す
							healerdmf->runAction(healerfadeout);			//ダメージ文字をフェードアウトさせる
							healerdmf->runAction(healerfdoutmov);			//ダメージ文字を上に動かす
							PLhealer->runAction(healerrepeat1a);
							healerHP->runAction(healerrepeat2a);
							healerMN->runAction(healerrepeat3a);
							healerhpal->runAction(healerrepeat4a);
							healerhpmaxal->runAction(healerrepeat5a);
							healermnal->runAction(healerrepeat6a);
							healermnmaxal->runAction(healerrepeat7a);
						}
					}
					//魔術師を選んだ場合
					if (sskillchoice == MAGIC) {
						//剣士
						if (pl1frame.choicejob == ATTACKER || pl2frame.choicejob == ATTACKER
							|| pl3frame.choicejob == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - attacker.def;//減らすダメージを計算
							hpcut = max(1, hpcut);							//もし減らすHPが1以下の場合1にする
							attacker.hp -= hpcut;							//HPを減らす
							attackerdmf->setString(std::to_string(hpcut));	//ダメージを変化させる
							this->addChild(attackerdmf, onece);				//ダメージ文字を出す
							attackerdmf->runAction(attackerfadeout);		//ダメージ文字をフェードアウトさせる
							attackerdmf->runAction(attackerfdoutmov);		//ダメージ文字を上に動かす
							PLattacker->runAction(attacker_repeat_bigquake[0]);		//画像揺らす処理↓以下同文
							attackerHP->runAction(attacker_repeat_bigquake[1]);
							attackerMN->runAction(attacker_repeat_bigquake[2]);
							attackerhpal->runAction(attacker_repeat_bigquake[3]);
							attackerhpmaxal->runAction(attacker_repeat_bigquake[4]);
							attackermnal->runAction(attacker_repeat_bigquake[5]);
							attackermnmaxal->runAction(attacker_repeat_bigquake[6]);
						}
						//魔術師の代わりに騎士がダメージをくらう
						if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC
							|| pl3frame.choicejob == MAGIC) {
							hpcut = (valkyrie.atk * skillupmedium) - shield.def;	//減らすダメージを計算
							hpcut = max(1, hpcut);							//もし減らすHPが1以下の場合1にする
							shield.hp -= hpcut;								//HPを減らす
							shielddmf->setString(std::to_string(hpcut));	//ダメージを変化させる
							this->addChild(shielddmf, onece);				//ダメージ文字を出す
							shielddmf->runAction(shieldfadeout);			//ダメージ文字をフェードアウトさせる
							shielddmf->runAction(shieldfdoutmov);			//ダメージ文字を上に動かす
							PLshield->runAction(shieldrepeat1a);
							shieldHP->runAction(shieldrepeat2a);
							shieldMN->runAction(shieldrepeat3a);
							shieldhpal->runAction(shieldrepeat4a);
							shieldhpmaxal->runAction(shieldrepeat5a);
							shieldmnal->runAction(shieldrepeat6a);
							shieldmnmaxal->runAction(shieldrepeat7a);
						}
						//聖職者
						if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER
							|| pl3frame.choicejob == HEALER) {
							hpcut = (valkyrie.atk * skillupmedium) - healer.def;//減らすダメージを計算
							hpcut = max(1, hpcut);							//もし減らすHPが1以下の場合1にする
							healer.hp -= hpcut;								//HPを減らす
							healerdmf->setString(std::to_string(hpcut));	//ダメージを変化させる
							this->addChild(healerdmf, onece);				//ダメージ文字を出す
							healerdmf->runAction(healerfadeout);			//ダメージ文字をフェードアウトさせる
							healerdmf->runAction(healerfdoutmov);			//ダメージ文字を上に動かす
							PLhealer->runAction(healerrepeat1a);
							healerHP->runAction(healerrepeat2a);
							healerMN->runAction(healerrepeat3a);
							healerhpal->runAction(healerrepeat4a);
							healerhpmaxal->runAction(healerrepeat5a);
							healermnal->runAction(healerrepeat6a);
							healermnmaxal->runAction(healerrepeat7a);
						}
					}
					//聖職者を選んだ場合
					if (sskillchoice == HEALER) {
						//剣士
						if (pl1frame.choicejob == ATTACKER || pl2frame.choicejob == ATTACKER
							|| pl3frame.choicejob == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - attacker.def;//減らすダメージを計算
							hpcut = max(1, hpcut);							//もし減らすHPが1以下の場合1にする
							attacker.hp -= hpcut;							//HPを減らす
							attackerdmf->setString(std::to_string(hpcut));	//ダメージを変化させる
							this->addChild(attackerdmf, onece);				//ダメージ文字を出す
							attackerdmf->runAction(attackerfadeout);		//ダメージ文字をフェードアウトさせる
							attackerdmf->runAction(attackerfdoutmov);		//ダメージ文字を上に動かす
							PLattacker->runAction(attacker_repeat_bigquake[0]);		//画像揺らす処理↓以下同文
							attackerHP->runAction(attacker_repeat_bigquake[1]);
							attackerMN->runAction(attacker_repeat_bigquake[2]);
							attackerhpal->runAction(attacker_repeat_bigquake[3]);
							attackerhpmaxal->runAction(attacker_repeat_bigquake[4]);
							attackermnal->runAction(attacker_repeat_bigquake[5]);
							attackermnmaxal->runAction(attacker_repeat_bigquake[6]);
						}
						//魔術師
						if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC
							|| pl3frame.choicejob == MAGIC) {
							hpcut = (valkyrie.atk * skillupmedium) - magic.def;	//減らすダメージを計算
							hpcut = max(1, hpcut);							//もし減らすHPが1以下の場合1にする
							magic.hp -= hpcut;								//HPを減らす
							magicdmf->setString(std::to_string(hpcut));		//ダメージを変化させる
							this->addChild(magicdmf, onece);				//ダメージ文字を出す
							magicdmf->runAction(magicfadeout);				//ダメージ文字をフェードアウトさせる
							magicdmf->runAction(magicfdoutmov);				//ダメージ文字を上に動かす
							PLmagic->runAction(magicrepeat1a);
							magicHP->runAction(magicrepeat2a);
							magicMN->runAction(magicrepeat3a);
							magichpal->runAction(magicrepeat4a);
							magichpmaxal->runAction(magicrepeat5a);
							magicmnal->runAction(magicrepeat6a);
							magicmnmaxal->runAction(magicrepeat7a);
						}
						//聖職者の代わりに騎士がダメージをくらう
						if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER
							|| pl3frame.choicejob == HEALER) {
							hpcut = (valkyrie.atk * skillupmedium) - shield.def;//減らすダメージを計算
							hpcut = max(1, hpcut);							//もし減らすHPが1以下の場合1にする
							shield.hp -= hpcut;								//HPを減らす
							shielddmf->setString(std::to_string(hpcut));	//ダメージを変化させる
							this->addChild(shielddmf, onece);				//ダメージ文字を出す
							shielddmf->runAction(shieldfadeout);			//ダメージ文字をフェードアウトさせる
							shielddmf->runAction(shieldfdoutmov);			//ダメージ文字を上に動かす
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
						//剣士ダメージを受けた時に揺れる処理
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
						//騎士ダメージを受けた時に揺れる処理
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
						//魔術師ダメージを受けた時に揺れる処理
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
						//聖職者ダメージを受けた時に揺れる処理
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
						//プレイヤー全員のHPを減らす
						//受けたダメージをゲージ上に表示
						//剣士
						if (pl1frame.choicejob == ATTACKER || pl2frame.choicejob == ATTACKER
							|| pl3frame.choicejob == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - attacker.def;	//減らすダメージを計算
																					//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							attacker.hp -= hpcut;							//HPを減らす
							attackerdmf->setString(std::to_string(hpcut));	//ダメージを変化させる
							this->addChild(attackerdmf, onece);				//ダメージ文字を出す
							attackerdmf->runAction(attackerfadeout);		//フェードアウト処理
							attackerdmf->runAction(attackerfdoutmov);		//上に上がっていく処理
						}
						//騎士
						if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD
							|| pl3frame.choicejob == SHIELD) {
							hpcut = (valkyrie.atk * skillupmedium) - shield.def;//減らすダメージを計算
																				//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;								//HPを減らす
							shielddmf->setString(std::to_string(hpcut));	//ダメージを変化させる
							this->addChild(shielddmf, onece);				//ダメージ文字を出す
							shielddmf->runAction(shieldfadeout);			//ダメージ文字をフェードアウトさせる
							shielddmf->runAction(shieldfdoutmov);			//ダメージ文字を上に動かす
						}
						//魔術師
						if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC
							|| pl3frame.choicejob == MAGIC) {
							hpcut = (valkyrie.atk * skillupmedium) - magic.def;	//減らすダメージを計算
																				//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							magic.hp -= hpcut;								//HPを減らす
							magicdmf->setString(std::to_string(hpcut));		//ダメージを変化させる
							this->addChild(magicdmf, onece);				//ダメージ文字を出す
							magicdmf->runAction(magicfadeout);				//ダメージ文字をフェードアウトさせる
							magicdmf->runAction(magicfdoutmov);				//ダメージ文字を上に動かす
						}
						//聖職者
						if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER
							|| pl3frame.choicejob == HEALER) {
							hpcut = (valkyrie.atk * skillupmedium) - healer.def;//減らすダメージを計算
																				//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							healer.hp -= hpcut;									//HPを減らす
							healerdmf->setString(std::to_string(hpcut));		//ダメージを変化させる
							this->addChild(healerdmf, onece);					//ダメージ文字を出す
							healerdmf->runAction(healerfadeout);				//ダメージ文字をフェードアウトさせる
							healerdmf->runAction(healerfdoutmov);				//ダメージ文字を上に動かす

						}
					}
				}

				//騎士が全体庇うを使っている時
				if (allinsteadflag == true) {
					hpcut = (valkyrie.atk * skillupmedium) - healer.def;//減らすダメージを計算
																		//もし減らすHPが1以下の場合1にする
					if (hpcut <= 1) {
						hpcut = 1;
					}
					if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD
						|| pl3frame.choicejob == SHIELD) {
						shield.hp -= hpcut;								//HPを減らす
						shielddmf->setString(std::to_string(hpcut));	//ダメージを変化させる
						this->addChild(shielddmf, onece);				//ダメージ文字を出す
						shielddmf->runAction(shieldfadeout);			//ダメージ文字をフェードアウトさせる
						shielddmf->runAction(shieldfdoutmov);			//ダメージ文字を上に動かす
						PLshield->runAction(shieldrepeat1a);			//画像揺らす処理↓以下同文
						shieldHP->runAction(shieldrepeat2a);
						shieldMN->runAction(shieldrepeat3a);
						shieldhpal->runAction(shieldrepeat4a);
						shieldhpmaxal->runAction(shieldrepeat5a);
						shieldmnal->runAction(shieldrepeat6a);
						shieldmnmaxal->runAction(shieldrepeat7a);
					}
				}

				//紅に染めてこのキャラを
				PLattacker->setColor(ccc3(colormax, colordown, colordown));
				PLshield->setColor(ccc3(colormax, colordown, colordown));
				PLhealer->setColor(ccc3(colormax, colordown, colordown));
				PLmagic->setColor(ccc3(colormax, colordown, colordown));

				//HPの数値を変える
				attackerhpal->setString(std::to_string(attacker.hp));
				shieldhpal->setString(std::to_string(shield.hp));
				healerhpal->setString(std::to_string(healer.hp));
				magichpal->setString(std::to_string(magic.hp));
			}
			//騎士の全体庇うを使った時に使う処理
			if (gameflame == flame220) {
				if (allinsteadflag == true) {
					hpcut = (valkyrie.atk * skillupmedium) - healer.def;//減らすダメージを計算
																		//もし減らすHPが1以下の場合1にする
					if (hpcut <= 1) {
						hpcut = 1;
					}
					if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD
						|| pl3frame.choicejob == SHIELD) {
						shield.hp -= hpcut;								//HPを減らす
						shielddmf->setString(std::to_string(hpcut));	//ダメージを変化させる
						this->addChild(shielddmf, onece);				//ダメージ文字を出す
						shielddmf->runAction(shieldfadeout);			//ダメージ文字をフェードアウトさせる
						shielddmf->runAction(shieldfdoutmov);			//ダメージ文字を上に動かす
					}
				}

				//HPの数値を変える
				attackerhpal->setString(std::to_string(attacker.hp));
				shieldhpal->setString(std::to_string(shield.hp));
				healerhpal->setString(std::to_string(healer.hp));
				magichpal->setString(std::to_string(magic.hp));
			}
			//騎士の単体庇うと全体庇うを使った時に使う処理
			if (gameflame == flame230) {
				if (insteadflag == true || allinsteadflag == true) {
					hpcut = (valkyrie.atk * skillupmedium) - healer.def;//減らすダメージを計算
					//もし減らすHPが1以下の場合1にする
					if (hpcut <= 1) {
						hpcut = 1;
					}
					if (pl1frame.choicejob == SHIELD || pl2frame.choicejob == SHIELD
						|| pl3frame.choicejob == SHIELD) {
						shield.hp -= hpcut;								//HPを減らす
						shielddmf->setString(std::to_string(hpcut));	//ダメージを変化させる
						this->addChild(shielddmf, onece);				//ダメージ文字を出す
						shielddmf->runAction(shieldfadeout);			//ダメージ文字をフェードアウトさせる
						shielddmf->runAction(shieldfdoutmov);			//ダメージ文字を上に動かす
					}
				}

				//HPの数値を変える
				attackerhpal->setString(std::to_string(attacker.hp));
				shieldhpal->setString(std::to_string(shield.hp));
				healerhpal->setString(std::to_string(healer.hp));
				magichpal->setString(std::to_string(magic.hp));
			}
			//ダメージ処理
			//フレームが250(仮)になるとダメージ表記
			if (gameflame == flame250) {
				auto Gskill1dec = CCLabelTTF::create("全員にダメージを与える", "HGRSGU.TTC", fontsizeL);
				Gskill1dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill1dec, backdepth, bossskill1damageS);

				//キャラの色を戻す
				PLattacker->setColor(ccc3(colormax, colormax, colormax));
				PLshield->setColor(ccc3(colormax, colormax, colormax));
				PLhealer->setColor(ccc3(colormax, colormax, colormax));
				PLmagic->setColor(ccc3(colormax, colormax, colormax));
			}

		}
		//二の太刀
		if (bskill == BSKILL2) {
			//フレームが80(仮)になるとスキルの名前表示
			if (gameflame == flame80) {

				auto Gskill2 = CCLabelTTF::create("「やあああ！」", "HGRSGU.TTC", fontsizeL);
				Gskill2->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill2, backdepth, bossskill2S);

				//騎士の身代わりスキルが発動していないとき
				if (insteadflag == false) {
					//剣士
					if (job == ATTACKER) {
						hpcut = (valkyrie.atk - attacker.def);						//ダメージを計算
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						attacker.hp -= hpcut;									//HPをへらす
						PLattacker->setColor(ccc3(colormax, colordown, colordown));	//受けるやつを赤くする
						attackerdmf->setString(std::to_string(hpcut));				//ダメージを変化させる
						this->addChild(attackerdmf, onece);							//ダメージ文字を出す
						attackerdmf->runAction(attackerfadeout);					//ダメージ文字をフェードアウトさせる
						attackerdmf->runAction(attackerfdoutmov);					//ダメージ文字を上に動かす
						attackerhpal->setString(std::to_string(attacker.hp));		//数値を変える↓以下同文
					}
					//騎士
					else if (job == SHIELD) {
						hpcut = (valkyrie.atk - shield.def);
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;
						PLshield->setColor(ccc3(colormax, colordown, colordown));
						shielddmf->setString(std::to_string(hpcut));				//ダメージを変化させる
						this->addChild(shielddmf, onece);							//ダメージ文字を出す
						shielddmf->runAction(shieldfadeout);						//ダメージ文字をフェードアウトさせる
						shielddmf->runAction(shieldfdoutmov);						//ダメージ文字を上に動かす
						shieldhpal->setString(std::to_string(shield.hp));
					}
					//魔術師
					else if (job == MAGIC) {
						hpcut = (valkyrie.atk - magic.def);
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						magic.hp -= hpcut;
						PLmagic->setColor(ccc3(colormax, colordown, colordown));
						magicdmf->setString(std::to_string(hpcut));					//ダメージを変化させる
						this->addChild(magicdmf, onece);							//ダメージ文字を出す
						magicdmf->runAction(magicfadeout);							//ダメージ文字をフェードアウトさせる
						magicdmf->runAction(magicfdoutmov);							//ダメージ文字を上に動かす
						magichpal->setString(std::to_string(magic.hp));
					}
					//聖職者
					else if (job == HEALER) {
						hpcut = (valkyrie.atk - healer.def);
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						healer.hp -= hpcut;
						PLhealer->setColor(ccc3(colormax, colordown, colordown));
						healerdmf->setString(std::to_string(hpcut));				//ダメージを変化させる
						this->addChild(healerdmf, onece);							//ダメージ文字を出す
						healerdmf->runAction(healerfadeout);						//ダメージ文字をフェードアウトさせる
						healerdmf->runAction(healerfdoutmov);						//ダメージ文字を上に動かす
						healerhpal->setString(std::to_string(healer.hp));
					}
				}

				//騎士の単体身代わりフラグが発動しているとき
				if (insteadflag == true) {
					//剣士を選んだ場合
					if (sskillchoice == ATTACKER) {
						//剣士
						if (job == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - shield.def;//減らすダメージを計算
							//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;									//HPを減らす
							shielddmf->setString(std::to_string(hpcut));		//ダメージを変化させる
							this->addChild(shielddmf, onece);					//ダメージ文字を出す
							shielddmf->runAction(shieldfadeout);				//ダメージ文字をフェードアウトさせる
							shielddmf->runAction(shieldfdoutmov);				//ダメージ文字を上に動かす
						}
						//騎士
						if (job == SHIELD) {
							hpcut = (valkyrie.atk - shield.def);
							//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;
							PLshield->setColor(ccc3(colormax, colordown, colordown));
							shielddmf->setString(std::to_string(hpcut));				//ダメージを変化させる
							this->addChild(shielddmf, onece);							//ダメージ文字を出す
							shielddmf->runAction(shieldfadeout);						//ダメージ文字をフェードアウトさせる
							shielddmf->runAction(shieldfdoutmov);						//ダメージ文字を上に動かす
							shieldhpal->setString(std::to_string(shield.hp));
						}
						//魔術師
						if (job == MAGIC) {
							hpcut = (valkyrie.atk - magic.def);
							//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							magic.hp -= hpcut;
							PLmagic->setColor(ccc3(colormax, colordown, colordown));
							magicdmf->setString(std::to_string(hpcut));				//ダメージを変化させる
							this->addChild(magicdmf, onece);							//ダメージ文字を出す
							magicdmf->runAction(magicfadeout);						//ダメージ文字をフェードアウトさせる
							magicdmf->runAction(magicfdoutmov);						//ダメージ文字を上に動かす
							magichpal->setString(std::to_string(magic.hp));
						}
						//聖職者
						if (job == HEALER) {
							hpcut = (valkyrie.atk - healer.def);
							//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							healer.hp -= hpcut;
							PLhealer->setColor(ccc3(colormax, colordown, colordown));
							healerdmf->setString(std::to_string(hpcut));				//ダメージを変化させる
							this->addChild(healerdmf, onece);							//ダメージ文字を出す
							healerdmf->runAction(healerfadeout);						//ダメージ文字をフェードアウトさせる
							healerdmf->runAction(healerfdoutmov);						//ダメージ文字を上に動かす
							healerhpal->setString(std::to_string(healer.hp));
						}
					}
					//魔術師を選んだ場合
					if (sskillchoice == MAGIC) {
						if (job == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - attacker.def;	//減らすダメージを計算
							//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							attacker.hp -= hpcut;									//HPを減らす
							attackerdmf->setString(std::to_string(hpcut));			//ダメージを変化させる
							this->addChild(attackerdmf, onece);						//ダメージ文字を出す
							attackerdmf->runAction(attackerfadeout);				//ダメージ文字をフェードアウトさせる
							attackerdmf->runAction(attackerfdoutmov);				//ダメージ文字を上に動かす
						}
						//騎士
						if (job == SHIELD) {
							hpcut = (valkyrie.atk - shield.def);
							//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;
							PLshield->setColor(ccc3(colormax, colordown, colordown));
							shielddmf->setString(std::to_string(hpcut));			//ダメージを変化させる
							this->addChild(shielddmf, onece);						//ダメージ文字を出す
							shielddmf->runAction(shieldfadeout);					//ダメージ文字をフェードアウトさせる
							shielddmf->runAction(shieldfdoutmov);					//ダメージ文字を上に動かす
							shieldhpal->setString(std::to_string(shield.hp));
						}
						//魔術師
						if (job == MAGIC) {
							//魔術師の代わりに騎士がダメージをくらう
							if (pl1frame.choicejob == MAGIC || pl2frame.choicejob == MAGIC
								|| pl3frame.choicejob == MAGIC) {
								hpcut = (valkyrie.atk * skillupmedium) - shield.def;//減らすダメージを計算
																					//もし減らすHPが1以下の場合1にする
								if (hpcut <= 1) {
									hpcut = 1;
								}
								shield.hp -= hpcut;									//HPを減らす
								shielddmf->setString(std::to_string(hpcut));		//ダメージを変化させる
								this->addChild(shielddmf, onece);					//ダメージ文字を出す
								shielddmf->runAction(shieldfadeout);				//ダメージ文字をフェードアウトさせる
								shielddmf->runAction(shieldfdoutmov);				//ダメージ文字を上に動かす
							}
						}
						//聖職者
						if (job == HEALER) {
							hpcut = (valkyrie.atk - healer.def);
							//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							healer.hp -= hpcut;
							PLhealer->setColor(ccc3(colormax, colordown, colordown));
							healerdmf->setString(std::to_string(hpcut));				//ダメージを変化させる
							this->addChild(healerdmf, onece);							//ダメージ文字を出す
							healerdmf->runAction(healerfadeout);						//ダメージ文字をフェードアウトさせる
							healerdmf->runAction(healerfdoutmov);						//ダメージ文字を上に動かす
							healerhpal->setString(std::to_string(healer.hp));
						}
					}
					//聖職者を選んだ場合
					if (sskillchoice == HEALER) {
						//剣士
						if (job == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - attacker.def;//減らすダメージを計算
																				//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							attacker.hp -= hpcut;									//HPを減らす
							attackerdmf->setString(std::to_string(hpcut));		//ダメージを変化させる
							this->addChild(attackerdmf, onece);					//ダメージ文字を出す
							attackerdmf->runAction(attackerfadeout);				//ダメージ文字をフェードアウトさせる
							attackerdmf->runAction(attackerfdoutmov);				//ダメージ文字を上に動かす
						}
						//騎士
						if (job == SHIELD) {
							hpcut = (valkyrie.atk - shield.def);
							//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;
							PLshield->setColor(ccc3(colormax, colordown, colordown));
							shielddmf->setString(std::to_string(hpcut));				//ダメージを変化させる
							this->addChild(shielddmf, onece);							//ダメージ文字を出す
							shielddmf->runAction(shieldfadeout);						//ダメージ文字をフェードアウトさせる
							shielddmf->runAction(shieldfdoutmov);						//ダメージ文字を上に動かす
							shieldhpal->setString(std::to_string(shield.hp));
						}
						//魔術師
						if (job == MAGIC) {
							hpcut = (valkyrie.atk - magic.def);
							//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							magic.hp -= hpcut;
							PLmagic->setColor(ccc3(colormax, colordown, colordown));
							magicdmf->setString(std::to_string(hpcut));				//ダメージを変化させる
							this->addChild(magicdmf, onece);							//ダメージ文字を出す
							magicdmf->runAction(magicfadeout);						//ダメージ文字をフェードアウトさせる
							magicdmf->runAction(magicfdoutmov);						//ダメージ文字を上に動かす
							magichpal->setString(std::to_string(magic.hp));
						}
						//聖職者
						if (job == HEALER) {
							//聖職者の代わりに騎士がダメージをくらう
							if (pl1frame.choicejob == HEALER || pl2frame.choicejob == HEALER
								|| pl3frame.choicejob == HEALER) {
								hpcut = (valkyrie.atk * skillupmedium) - shield.def;//減らすダメージを計算
																					//もし減らすHPが1以下の場合1にする
								if (hpcut <= 1) {
									hpcut = 1;
								}
								shield.hp -= hpcut;									//HPを減らす
								shielddmf->setString(std::to_string(hpcut));		//ダメージを変化させる
								this->addChild(shielddmf, onece);					//ダメージ文字を出す
								shielddmf->runAction(shieldfadeout);				//ダメージ文字をフェードアウトさせる
								shielddmf->runAction(shieldfdoutmov);				//ダメージ文字を上に動かす
							}
						}
					}
				}

				//エフェクト
				//エフェクトの表示
				CCSize s = CCDirector::sharedDirector()->getWinSize();
				//エフェクトの流れを指定
				CCParticleSystemQuad* particle = CCParticleSystemQuad::create("Effect/bosseffect.plist");
				particle->setAutoRemoveOnFinish(true);

				particle->resetSystem();									//エフェクト開始
				particle->setPosition(ccp(rightSize.width / 2,
					rightSize.height / 3));			//エフェクトを表示する場所の設定
				this->addChild(particle, backdepth, bossskill1E);			//エフェクトを配置
			}
			//二回目の攻撃
			if (gameflame == flame150) {
				//二回目のHPを減らす

				//ダメージを受けた時揺らす処理
				Damage();

				//騎士の単体身代わりスキルが発動していないとき
				if (insteadflag == false) {
					//剣士
					if (job == ATTACKER) {
						hpcut = (valkyrie.atk - attacker.def);					//ダメージ計算
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						attacker.hp -= hpcut;									//HPを減らす
						PLattacker->setColor(ccc3(colormax, colordown, colordown));	//ダメージをくらった(プレイヤーの画像を赤くする)
						attackerdmf->setString(std::to_string(hpcut));			//ダメージを変化させる
						this->addChild(attackerdmf, onece);						//ダメージ文字を出す
						attackerdmf->runAction(attackerfadeout);				//ダメージ文字をフェードアウトさせる
						attackerdmf->runAction(attackerfdoutmov);				//ダメージ文字を上に動かす
						attackerhpal->setString(std::to_string(attacker.hp));	//HP数値を減らす
						PLattacker->runAction(attacker_repeat_bigquake[0]);
						attackerHP->runAction(attacker_repeat_bigquake[1]);
						attackerMN->runAction(attacker_repeat_bigquake[2]);
						attackerhpal->runAction(attacker_repeat_bigquake[3]);
						attackerhpmaxal->runAction(attacker_repeat_bigquake[4]);
						attackermnal->runAction(attacker_repeat_bigquake[5]);
						attackermnmaxal->runAction(attacker_repeat_bigquake[6]);
					}
					//騎士
					else if (job == SHIELD) {
						hpcut = (valkyrie.atk - shield.def);
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						shield.hp -= hpcut;
						PLshield->setColor(ccc3(colormax, colordown, colordown));
						shieldhpal->setString(std::to_string(shield.hp));
						shielddmf->setString(std::to_string(hpcut));			//ダメージを変化させる
						this->addChild(shielddmf, onece);						//ダメージ文字を出す
						shielddmf->runAction(shieldfadeout);					//ダメージ文字をフェードアウトさせる
						shielddmf->runAction(shieldfdoutmov);					//ダメージ文字を上に動かす
						PLshield->runAction(shieldrepeat1a);
						shieldHP->runAction(shieldrepeat2a);
						shieldMN->runAction(shieldrepeat3a);
						shieldhpal->runAction(shieldrepeat4a);
						shieldhpmaxal->runAction(shieldrepeat5a);
						shieldmnal->runAction(shieldrepeat6a);
						shieldmnmaxal->runAction(shieldrepeat7a);
					}
					//魔術師
					else if (job == MAGIC) {
						hpcut = (valkyrie.atk - magic.def);
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						magic.hp -= hpcut;
						PLmagic->setColor(ccc3(colormax, colordown, colordown));
						magichpal->setString(std::to_string(magic.hp));
						magicdmf->setString(std::to_string(hpcut));				//ダメージを変化させる
						this->addChild(magicdmf, onece);						//ダメージ文字を出す
						magicdmf->runAction(magicfadeout);						//ダメージ文字をフェードアウトさせる
						magicdmf->runAction(magicfdoutmov);						//ダメージ文字を上に動かす
						PLmagic->runAction(magicrepeat1a);
						magicHP->runAction(magicrepeat2a);
						magicMN->runAction(magicrepeat3a);
						magichpal->runAction(magicrepeat4a);
						magichpmaxal->runAction(magicrepeat5a);
						magicmnal->runAction(magicrepeat6a);
						magicmnmaxal->runAction(magicrepeat7a);
					}
					//聖職者
					else if (job == HEALER) {
						hpcut = (valkyrie.atk - healer.def);
						//もし減らすHPが1以下の場合1にする
						if (hpcut <= 1) {
							hpcut = 1;
						}
						healer.hp -= hpcut;
						PLhealer->setColor(ccc3(colormax, colordown, colordown));
						healerhpal->setString(std::to_string(healer.hp));
						healerdmf->setString(std::to_string(hpcut));			//ダメージを変化させる
						this->addChild(healerdmf, onece);						//ダメージ文字を出す
						healerdmf->runAction(healerfadeout);					//ダメージ文字をフェードアウトさせる
						healerdmf->runAction(healerfdoutmov);					//ダメージ文字を上に動かす
						PLhealer->runAction(healerrepeat1a);
						healerHP->runAction(healerrepeat2a);
						healerMN->runAction(healerrepeat3a);
						healerhpal->runAction(healerrepeat4a);
						healerhpmaxal->runAction(healerrepeat5a);
						healermnal->runAction(healerrepeat6a);
						healermnmaxal->runAction(healerrepeat7a);
					}
				}

				//騎士の単体身代わりフラグが発動しているとき
				if (insteadflag == true) {
					//剣士を選んだ場合
					if (sskillchoice == ATTACKER) {
						//剣士
						if (job == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - shield.def;//減らすダメージを計算
																				//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;									//HPを減らす
							shielddmf->setString(std::to_string(hpcut));		//ダメージを変化させる
							this->addChild(shielddmf, onece);					//ダメージ文字を出す
							shielddmf->runAction(shieldfadeout);				//ダメージ文字をフェードアウトさせる
							shielddmf->runAction(shieldfdoutmov);				//ダメージ文字を上に動かす
							shieldhpal->setString(std::to_string(shield.hp));
							PLshield->runAction(shieldrepeat1a);
							shieldHP->runAction(shieldrepeat2a);
							shieldMN->runAction(shieldrepeat3a);
							shieldhpal->runAction(shieldrepeat4a);
							shieldhpmaxal->runAction(shieldrepeat5a);
							shieldmnal->runAction(shieldrepeat6a);
							shieldmnmaxal->runAction(shieldrepeat7a);
						}
						//騎士
						if (job == SHIELD) {
							hpcut = (valkyrie.atk - shield.def);
							//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;
							PLshield->setColor(ccc3(colormax, colordown, colordown));
							shielddmf->setString(std::to_string(hpcut));				//ダメージを変化させる
							this->addChild(shielddmf, onece);							//ダメージ文字を出す
							shielddmf->runAction(shieldfadeout);						//ダメージ文字をフェードアウトさせる
							shielddmf->runAction(shieldfdoutmov);						//ダメージ文字を上に動かす
							shieldhpal->setString(std::to_string(shield.hp));
							PLshield->runAction(shieldrepeat1a);
							shieldHP->runAction(shieldrepeat2a);
							shieldMN->runAction(shieldrepeat3a);
							shieldhpal->runAction(shieldrepeat4a);
							shieldhpmaxal->runAction(shieldrepeat5a);
							shieldmnal->runAction(shieldrepeat6a);
							shieldmnmaxal->runAction(shieldrepeat7a);
						}
						//魔術師
						if (job == MAGIC) {
							hpcut = (valkyrie.atk - magic.def);
							//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							magic.hp -= hpcut;
							PLmagic->setColor(ccc3(colormax, colordown, colordown));
							magicdmf->setString(std::to_string(hpcut));				//ダメージを変化させる
							this->addChild(magicdmf, onece);							//ダメージ文字を出す
							magicdmf->runAction(magicfadeout);						//ダメージ文字をフェードアウトさせる
							magicdmf->runAction(magicfdoutmov);						//ダメージ文字を上に動かす
							magichpal->setString(std::to_string(magic.hp));
							PLmagic->runAction(magicrepeat1a);
							magicHP->runAction(magicrepeat2a);
							magicMN->runAction(magicrepeat3a);
							magichpal->runAction(magicrepeat4a);
							magichpmaxal->runAction(magicrepeat5a);
							magicmnal->runAction(magicrepeat6a);
							magicmnmaxal->runAction(magicrepeat7a);
						}
						//聖職者
						if (job == HEALER) {
							hpcut = (valkyrie.atk - healer.def);
							//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							healer.hp -= hpcut;
							PLhealer->setColor(ccc3(colormax, colordown, colordown));
							healerdmf->setString(std::to_string(hpcut));				//ダメージを変化させる
							this->addChild(healerdmf, onece);							//ダメージ文字を出す
							healerdmf->runAction(healerfadeout);						//ダメージ文字をフェードアウトさせる
							healerdmf->runAction(healerfdoutmov);						//ダメージ文字を上に動かす
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
					//魔術師を選んだ場合
					if (sskillchoice == MAGIC) {
						//剣士
						if (job == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - attacker.def;	//減らすダメージを計算
																					//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							attacker.hp -= hpcut;									//HPを減らす
							attackerdmf->setString(std::to_string(hpcut));			//ダメージを変化させる
							this->addChild(attackerdmf, onece);						//ダメージ文字を出す
							attackerdmf->runAction(attackerfadeout);				//ダメージ文字をフェードアウトさせる
							attackerdmf->runAction(attackerfdoutmov);				//ダメージ文字を上に動かす
							attackerhpal->setString(std::to_string(attacker.hp));
							PLattacker->runAction(attacker_repeat_bigquake[0]);
							attackerHP->runAction(attacker_repeat_bigquake[1]);
							attackerMN->runAction(attacker_repeat_bigquake[2]);
							attackerhpal->runAction(attacker_repeat_bigquake[3]);
							attackerhpmaxal->runAction(attacker_repeat_bigquake[4]);
							attackermnal->runAction(attacker_repeat_bigquake[5]);
							attackermnmaxal->runAction(attacker_repeat_bigquake[6]);
						}
						//騎士
						if (job == SHIELD) {
							hpcut = (valkyrie.atk - shield.def);
							//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;
							PLshield->setColor(ccc3(colormax, colordown, colordown));
							shielddmf->setString(std::to_string(hpcut));			//ダメージを変化させる
							this->addChild(shielddmf, onece);						//ダメージ文字を出す
							shielddmf->runAction(shieldfadeout);					//ダメージ文字をフェードアウトさせる
							shielddmf->runAction(shieldfdoutmov);					//ダメージ文字を上に動かす
							shieldhpal->setString(std::to_string(shield.hp));
							PLshield->runAction(shieldrepeat1a);
							shieldHP->runAction(shieldrepeat2a);
							shieldMN->runAction(shieldrepeat3a);
							shieldhpal->runAction(shieldrepeat4a);
							shieldhpmaxal->runAction(shieldrepeat5a);
							shieldmnal->runAction(shieldrepeat6a);
							shieldmnmaxal->runAction(shieldrepeat7a);
						}
						//魔術師
						if (job == MAGIC) {
							//魔術師の代わりに騎士がダメージをくらう
							hpcut = (valkyrie.atk * skillupmedium) - shield.def;//減らすダメージを計算
																				//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;									//HPを減らす
							shielddmf->setString(std::to_string(hpcut));		//ダメージを変化させる
							this->addChild(shielddmf, onece);					//ダメージ文字を出す
							shielddmf->runAction(shieldfadeout);				//ダメージ文字をフェードアウトさせる
							shielddmf->runAction(shieldfdoutmov);				//ダメージ文字を上に動かす
							magichpal->setString(std::to_string(magic.hp));
							PLshield->runAction(shieldrepeat1a);
							shieldHP->runAction(shieldrepeat2a);
							shieldMN->runAction(shieldrepeat3a);
							shieldhpal->runAction(shieldrepeat4a);
							shieldhpmaxal->runAction(shieldrepeat5a);
							shieldmnal->runAction(shieldrepeat6a);
							shieldmnmaxal->runAction(shieldrepeat7a);

						}
						//聖職者
						if (job == HEALER) {
							hpcut = (valkyrie.atk - healer.def);
							//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							healer.hp -= hpcut;
							PLhealer->setColor(ccc3(colormax, colordown, colordown));
							healerdmf->setString(std::to_string(hpcut));				//ダメージを変化させる
							this->addChild(healerdmf, onece);							//ダメージ文字を出す
							healerdmf->runAction(healerfadeout);						//ダメージ文字をフェードアウトさせる
							healerdmf->runAction(healerfdoutmov);						//ダメージ文字を上に動かす
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
					//聖職者を選んだ場合
					if (sskillchoice == HEALER) {
						//剣士
						if (job == ATTACKER) {
							hpcut = (valkyrie.atk * skillupmedium) - attacker.def;//減らすダメージを計算
																				  //もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							attacker.hp -= hpcut;									//HPを減らす
							attackerdmf->setString(std::to_string(hpcut));			//ダメージを変化させる
							this->addChild(attackerdmf, onece);						//ダメージ文字を出す
							attackerdmf->runAction(attackerfadeout);				//ダメージ文字をフェードアウトさせる
							attackerdmf->runAction(attackerfdoutmov);				//ダメージ文字を上に動かす
							attackerhpal->setString(std::to_string(attacker.hp));
							PLattacker->runAction(attacker_repeat_bigquake[0]);
							attackerHP->runAction(attacker_repeat_bigquake[1]);
							attackerMN->runAction(attacker_repeat_bigquake[2]);
							attackerhpal->runAction(attacker_repeat_bigquake[3]);
							attackerhpmaxal->runAction(attacker_repeat_bigquake[4]);
							attackermnal->runAction(attacker_repeat_bigquake[5]);
							attackermnmaxal->runAction(attacker_repeat_bigquake[6]);
						}
						//騎士
						if (job == SHIELD) {
							hpcut = (valkyrie.atk - shield.def);
							//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;
							PLshield->setColor(ccc3(colormax, colordown, colordown));
							shielddmf->setString(std::to_string(hpcut));			//ダメージを変化させる
							this->addChild(shielddmf, onece);						//ダメージ文字を出す
							shielddmf->runAction(shieldfadeout);					//ダメージ文字をフェードアウトさせる
							shielddmf->runAction(shieldfdoutmov);					//ダメージ文字を上に動かす
							shieldhpal->setString(std::to_string(shield.hp));
							PLshield->runAction(shieldrepeat1a);
							shieldHP->runAction(shieldrepeat2a);
							shieldMN->runAction(shieldrepeat3a);
							shieldhpal->runAction(shieldrepeat4a);
							shieldhpmaxal->runAction(shieldrepeat5a);
							shieldmnal->runAction(shieldrepeat6a);
							shieldmnmaxal->runAction(shieldrepeat7a);
						}
						//魔術師
						if (job == MAGIC) {
							hpcut = (valkyrie.atk - magic.def);
							//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							magic.hp -= hpcut;
							PLmagic->setColor(ccc3(colormax, colordown, colordown));
							magicdmf->setString(std::to_string(hpcut));				//ダメージを変化させる
							this->addChild(magicdmf, onece);						//ダメージ文字を出す
							magicdmf->runAction(magicfadeout);						//ダメージ文字をフェードアウトさせる
							magicdmf->runAction(magicfdoutmov);						//ダメージ文字を上に動かす
							magichpal->setString(std::to_string(magic.hp));
							PLmagic->runAction(magicrepeat1a);
							magicHP->runAction(magicrepeat2a);
							magicMN->runAction(magicrepeat3a);
							magichpal->runAction(magicrepeat4a);
							magichpmaxal->runAction(magicrepeat5a);
							magicmnal->runAction(magicrepeat6a);
							magicmnmaxal->runAction(magicrepeat7a);
						}
						//聖職者
						if (job == HEALER) {
							//聖職者の代わりに騎士がダメージをくらう
							hpcut = (valkyrie.atk * skillupmedium) - shield.def;//減らすダメージを計算
																				//もし減らすHPが1以下の場合1にする
							if (hpcut <= 1) {
								hpcut = 1;
							}
							shield.hp -= hpcut;									//HPを減らす
							shielddmf->setString(std::to_string(hpcut));		//ダメージを変化させる
							this->addChild(shielddmf, onece);					//ダメージ文字を出す
							shielddmf->runAction(shieldfadeout);				//ダメージ文字をフェードアウトさせる
							shielddmf->runAction(shieldfdoutmov);				//ダメージ文字を上に動かす
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

				//キャラの画像の色を戻す
				PLattacker->setColor(ccc3(colormax, colormax, colormax));
				PLshield->setColor(ccc3(colormax, colormax, colormax));
				PLhealer->setColor(ccc3(colormax, colormax, colormax));
				PLmagic->setColor(ccc3(colormax, colormax, colormax));
			}
			//効果処理
			//フレームが230(仮)になると効果を表記
			if (gameflame == flame230) {
				auto Gskill2dec = CCLabelTTF::create("ダメージを受けた", "HGRSGU.TTC", fontsizeL);
				Gskill2dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill2dec, backdepth, bossskill2damageS);
			}
		}
		//六帝の陣
		if (bskill == BSKILL3) {
			if (gameflame == flame80) {
				auto Gskill3 = CCLabelTTF::create("「これでもヴァルキリーなので」", "HGRSGU.TTC", fontsizeL);
				Gskill3->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill3, backdepth, bossskill3S);

				//ヴァルキリーの防御力を増やす
				buffup = valkyrie.defmax;//上げる防御力を計算(ヴァルキュリ－の防御力×0.5)
				valkyrie.def += buffup;				//ヴァルキリーの防御力に加える				

				//スキル効果ターンによる処理
				if (bvskill3.buffturn1 == 0) {
					bvskill3.buffturn1 = 2;
					bvskill3.buffupefect1 = buffup;
				}
				else if (bvskill3.buffturn2 == 0) {
					bvskill3.buffturn2 = 2;
					bvskill3.buffupefect2 = buffup;
				}
			}
			//効果処理
			//フレームが230(仮)になると効果を表記
			if (gameflame == flame230) {
				auto Gskill3dec = CCLabelTTF::create("ヴァルキリーの防御力が大幅に上がった", "HGRSGU.TTC", fontsizeM);
				Gskill3dec->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill3dec, backdepth, bossskill3damageS);
			}
		}
		//エステ
		if (bskill == BSKILL4) {
			if (gameflame == flame80) {
				auto Gskill4 = CCLabelTTF::create("「エステ…ｽｷｨ…」", "HGRSGU.TTC", fontsizeL);
				Gskill4->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(Gskill4, backdepth, bossskill4S);

				//ヴァルキリーのHPを増やす
				bsskillrecovery = valkyrie.hp / tenpercent;
				valkyrie.hp += bsskillrecovery;
			}
			//効果処理
			//フレームが230(仮)になると効果を表記
			if (gameflame == flame230) {
				//回復表記
				String *Gskill4dec = String::createWithFormat("ヴァルキリーは%i、HPが回復した", bsskillrecovery);
				string _Gskill4dec = Gskill4dec->getCString();
				auto bss4alabel = Label::createWithSystemFont(_Gskill4dec, "HGRSGU.TTC", fontsizeL);
				bss4alabel->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
				this->addChild(bss4alabel, backdepth, bossskill4damageS);
			}
		}
	}
}

//画像を揺らすための処理
void BossScene::Damage()
{
//剣士
	//attackerframe.choisjobが剣士の場合
	if (pl1frame.choicejob == ATTACKER) {
	//揺れ幅が比較的に大きいやつ
		//揺らす処理剣士,1a
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
		//揺らす処理剣士,2a
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
		//揺らす処理剣士,3a
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
		//揺らす処理剣士,4a
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
		//揺らす処理剣士,5a
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
		//揺らす処理剣士,6a
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
		//揺らす処理剣士,7a
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
	//揺れ幅が小さいやつ
		//揺らす処理剣士,1b
		auto attackermove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		attacker_repeat_smallquake[0] = Repeat::create(attackermove1b, continuity1);
		//揺らす処理剣士,2b
		auto attackermove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		attacker_repeat_smallquake[1] = Repeat::create(attackermove2b, continuity1);
		//揺らす処理剣士,3b
		auto attackermove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		attacker_repeat_smallquake[2] = Repeat::create(attackermove3b, continuity1);
		//揺らす処理剣士,4b
		auto attackermove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_smallquake[3] = Repeat::create(attackermove4b, continuity1);
		//揺らす処理剣士,5b
		auto attackermove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_smallquake[4] = Repeat::create(attackermove5b, continuity1);
		//揺らす処理剣士,6b
		auto attackermove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_smallquake[5] = Repeat::create(attackermove6b, continuity1);
		//揺らす処理剣士,7b
		auto attackermove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_smallquake[6] = Repeat::create(attackermove7b, continuity1);
	}
	//pl2frame.choisjobが剣士の場合
	if (pl2frame.choicejob == ATTACKER) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理剣士,1a
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
		//揺らす処理剣士,2a
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
		//揺らす処理剣士,3a
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
		//揺らす処理剣士,4a
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
		//揺らす処理剣士,5a
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
		//揺らす処理剣士,6a
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
		//揺らす処理剣士,7a
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
		//揺れ幅が小さいやつ
		//揺らす処理剣士,1b
		auto attackermove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		attacker_repeat_smallquake[0] = Repeat::create(attackermove1b, continuity1);
		//揺らす処理剣士,2b
		auto attackermove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		attacker_repeat_smallquake[1] = Repeat::create(attackermove2b, continuity1);
		//揺らす処理剣士,3b
		auto attackermove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		attacker_repeat_smallquake[2] = Repeat::create(attackermove3b, continuity1);
		//揺らす処理剣士,4b
		auto attackermove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_smallquake[3] = Repeat::create(attackermove4b, continuity1);
		//揺らす処理剣士,5b
		auto attackermove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_smallquake[4] = Repeat::create(attackermove5b, continuity1);
		//揺らす処理剣士,6b
		auto attackermove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_smallquake[5] = Repeat::create(attackermove6b, continuity1);
		//揺らす処理剣士,7b
		auto attackermove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_smallquake[6] = Repeat::create(attackermove7b, continuity1);
	}
	//pl3frame.choisjobが剣士の場合
	if (pl3frame.choicejob == ATTACKER) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理剣士,1a
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
		//揺らす処理剣士,2a
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
		//揺らす処理剣士,3a
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
		//揺らす処理剣士,4a
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
		//揺らす処理剣士,5a
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
		//揺らす処理剣士,6a
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
		//揺らす処理剣士,7a
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
		//揺れが小さいやつ
		//揺らす処理剣士,1b
		auto attackermove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		attacker_repeat_smallquake[0] = Repeat::create(attackermove1b, continuity1);
		//揺らす処理剣士,2b
		auto attackermove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		attacker_repeat_smallquake[1] = Repeat::create(attackermove2b, continuity1);
		//揺らす処理剣士,3b
		auto attackermove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		attacker_repeat_smallquake[2] = Repeat::create(attackermove3b, continuity1);
		//揺らす処理剣士,4b
		auto attackermove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_smallquake[3] = Repeat::create(attackermove4b, continuity1);
		//揺らす処理剣士,5b
		auto attackermove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_smallquake[4] = Repeat::create(attackermove5b, continuity1);
		//揺らす処理剣士,6b
		auto attackermove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		attacker_repeat_smallquake[5] = Repeat::create(attackermove6b, continuity1);
		//揺らす処理剣士,7b
		auto attackermove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		attacker_repeat_smallquake[6] = Repeat::create(attackermove7b, continuity1);
	}
//騎士
	//shieldframe.choisjobが騎士の場合
	if (pl1frame.choicejob == SHIELD) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理騎士,1a
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
		//揺らす処理騎士,2a
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
		//揺らす処理騎士,3a
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
		//揺らす処理騎士,4a
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
		//揺らす処理騎士,5a
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
		//揺らす処理騎士,6a
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
		//揺らす処理騎士,7a
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
		//揺れ幅が小さいやつ
		//揺らす処理騎士,1b
		auto shieldmove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		shieldrepeat1b = Repeat::create(shieldmove1b, continuity1);
		//揺らす処理騎士,2b
		auto shieldmove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		shieldrepeat2b = Repeat::create(shieldmove2b, continuity1);
		//揺らす処理騎士,3b
		auto shieldmove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		shieldrepeat3b = Repeat::create(shieldmove3b, continuity1);
		//揺らす処理騎士,4b
		auto shieldmove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		shieldrepeat4b = Repeat::create(shieldmove4b, continuity1);
		//揺らす処理騎士,5b
		auto shieldmove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		shieldrepeat5b = Repeat::create(shieldmove5b, continuity1);
		//揺らす処理騎士,6b
		auto shieldmove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		shieldrepeat6b = Repeat::create(shieldmove6b, continuity1);
		//揺らす処理騎士,7b
		auto shieldmove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		shieldrepeat7b = Repeat::create(shieldmove7b, continuity1);
	}
	//pl2frame.choisjobが騎士の場合
	if (pl2frame.choicejob == SHIELD) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理騎士,1a
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
		//揺らす処理騎士,2a
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
		//揺らす処理騎士,3a
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
		//揺らす処理騎士,4a
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
		//揺らす処理騎士,5a
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
		//揺らす処理騎士,6a
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
		//揺らす処理騎士,7a
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
		//揺れ幅が小さいやつ
		//揺らす処理騎士,1b
		auto shieldmove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		shieldrepeat1b = Repeat::create(shieldmove1b, continuity1);
		//揺らす処理騎士,2b
		auto shieldmove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		shieldrepeat2b = Repeat::create(shieldmove2b, continuity1);
		//揺らす処理騎士,3b
		auto shieldmove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		shieldrepeat3b = Repeat::create(shieldmove3b, continuity1);
		//揺らす処理騎士,4b
		auto shieldmove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		shieldrepeat4b = Repeat::create(shieldmove4b, continuity1);
		//揺らす処理騎士,5b
		auto shieldmove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		shieldrepeat5b = Repeat::create(shieldmove5b, continuity1);
		//揺らす処理騎士,6b
		auto shieldmove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		shieldrepeat6b = Repeat::create(shieldmove6b, continuity1);
		//揺らす処理騎士,7b
		auto shieldmove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		shieldrepeat7b = Repeat::create(shieldmove7b, continuity1);
	}
	//pl3frame.choisjobが騎士の場合
	if (pl3frame.choicejob == SHIELD) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理騎士,1a
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
		//揺らす処理騎士,2a
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
		//揺らす処理騎士,3a
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
		//揺らす処理騎士,4a
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
		//揺らす処理騎士,5a
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
		//揺らす処理騎士,6a
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
		//揺らす処理騎士,7a
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
		//揺れが小さいやつ
		//揺らす処理騎士,1b
		auto shieldmove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		shieldrepeat1b = Repeat::create(shieldmove1b, continuity1);
		//揺らす処理騎士,2b
		auto shieldmove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		shieldrepeat2b = Repeat::create(shieldmove2b, continuity1);
		//揺らす処理騎士,3b
		auto shieldmove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		shieldrepeat3b = Repeat::create(shieldmove3b, continuity1);
		//揺らす処理騎士,4b
		auto shieldmove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		shieldrepeat4b = Repeat::create(shieldmove4b, continuity1);
		//揺らす処理騎士,5b
		auto shieldmove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		shieldrepeat5b = Repeat::create(shieldmove5b, continuity1);
		//揺らす処理騎士,6b
		auto shieldmove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		shieldrepeat6b = Repeat::create(shieldmove6b, continuity1);
		//揺らす処理騎士,7b
		auto shieldmove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		shieldrepeat7b = Repeat::create(shieldmove7b, continuity1);
	}
//魔術師
	//pl1frame.choisjobが魔術師の場合
	if (pl1frame.choicejob == MAGIC) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理魔術師,1a
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
		//揺らす処理魔術師,2a
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
		//揺らす処理魔術師,3a
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
		//揺らす処理魔術師,4a
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
		//揺らす処理魔術師,5a
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
		//揺らす処理魔術師,6a
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
		//揺らす処理魔術師,7a
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
		//揺れ幅が小さいやつ
		//揺らす処理魔術師,1b
		auto magicmove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		magicrepeat1b = Repeat::create(magicmove1b, continuity1);
		//揺らす処理魔術師,2b
		auto magicmove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		magicrepeat2b = Repeat::create(magicmove2b, continuity1);
		//揺らす処理魔術師,3b
		auto magicmove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		magicrepeat3b = Repeat::create(magicmove3b, continuity1);
		//揺らす処理魔術師,4b
		auto magicmove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat4b = Repeat::create(magicmove4b, continuity1);
		//揺らす処理魔術師,5b
		auto magicmove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat5b = Repeat::create(magicmove5b, continuity1);
		//揺らす処理魔術師,6b
		auto magicmove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat6b = Repeat::create(magicmove6b, continuity1);
		//揺らす処理魔術師,7b
		auto magicmove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat7b = Repeat::create(magicmove7b, continuity1);
	}
	//pl2frame.choisjobが魔術師の場合
	if (pl2frame.choicejob == MAGIC) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理魔術師,1a
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
		//揺らす処理魔術師,2a
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
		//揺らす処理魔術師,3a
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
		//揺らす処理魔術師,4a
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
		//揺らす処理魔術師,5a
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
		//揺らす処理魔術師,6a
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
		//揺らす処理魔術師,7a
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
		//揺れ幅が小さいやつ
		//揺らす処理魔術師,1b
		auto magicmove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		magicrepeat1b = Repeat::create(magicmove1b, continuity1);
		//揺らす処理魔術師,2b
		auto magicmove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		magicrepeat2b = Repeat::create(magicmove2b, continuity1);
		//揺らす処理魔術師,3b
		auto magicmove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		magicrepeat3b = Repeat::create(magicmove3b, continuity1);
		//揺らす処理魔術師,4b
		auto magicmove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat4b = Repeat::create(magicmove4b, continuity1);
		//揺らす処理魔術師,5b
		auto magicmove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat5b = Repeat::create(magicmove5b, continuity1);
		//揺らす処理魔術師,6b
		auto magicmove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat6b = Repeat::create(magicmove6b, continuity1);
		//揺らす処理魔術師,7b
		auto magicmove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat7b = Repeat::create(magicmove7b, continuity1);
	}
	//magicframe.choisjobが魔術師の場合
	if (pl3frame.choicejob == MAGIC) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理魔術師,1a
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
		//揺らす処理魔術師,2a
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
		//揺らす処理魔術師,3a
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
		//揺らす処理魔術師,4a
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
		//揺らす処理魔術師,5a
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
		//揺らす処理魔術師,6a
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
		//揺らす処理魔術師,7a
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
		//揺れが小さいやつ
		//揺らす処理魔術師,1b
		auto magicmove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		magicrepeat1b = Repeat::create(magicmove1b, continuity1);
		//揺らす処理魔術師,2b
		auto magicmove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		magicrepeat2b = Repeat::create(magicmove2b, continuity1);
		//揺らす処理魔術師,3b
		auto magicmove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		magicrepeat3b = Repeat::create(magicmove3b, continuity1);
		//揺らす処理魔術師,4b
		auto magicmove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat4b = Repeat::create(magicmove4b, continuity1);
		//揺らす処理魔術師,5b
		auto magicmove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat5b = Repeat::create(magicmove5b, continuity1);
		//揺らす処理魔術師,6b
		auto magicmove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		magicrepeat6b = Repeat::create(magicmove6b, continuity1);
		//揺らす処理魔術師,7b
		auto magicmove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		magicrepeat7b = Repeat::create(magicmove7b, continuity1);
	}
//聖職者
	//healerframe.choisjobが聖職者の場合
	if (pl1frame.choicejob == HEALER) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理聖職者,1a
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
		//揺らす処理聖職者,2a
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
		//揺らす処理聖職者,3a
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
		//揺らす処理聖職者,4a
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
		//揺らす処理聖職者,5a
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
		//揺らす処理聖職者,6a
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
		//揺らす処理聖職者,7a
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
		//揺れ幅が小さいやつ
		//揺らす処理聖職者,1b
		auto healermove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.1f, rightSize.height / 5)),
			NULL
		);
		healerrepeat1b = Repeat::create(healermove1b, continuity1);
		//揺らす処理聖職者,2b
		auto healermove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 6.32f, rightSize.height / 5.73f)),
			NULL
		);
		healerrepeat2b = Repeat::create(healermove2b, continuity1);
		//揺らす処理聖職者,3b
		auto healermove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.6f, rightSize.height / 5.73f)),
			NULL
		);
		healerrepeat3b = Repeat::create(healermove3b, continuity1);
		//揺らす処理聖職者,4b
		auto healermove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 5.0f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat4b = Repeat::create(healermove4b, continuity1);
		//揺らす処理聖職者,5b
		auto healermove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 4.5f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat5b = Repeat::create(healermove5b, continuity1);
		//揺らす処理聖職者,6b
		auto healermove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.22f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat6b = Repeat::create(healermove6b, continuity1);
		//揺らす処理聖職者,7b
		auto healermove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 3.0f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat7b = Repeat::create(healermove7b, continuity1);
	}
	//healerframe.choisjobが聖職者の場合
	if (pl2frame.choicejob == HEALER) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理聖職者,1a
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
		//揺らす処理聖職者,2a
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
		//揺らす処理聖職者,3a
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
		//揺らす処理聖職者,4a
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
		//揺らす処理聖職者,5a
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
		//揺らす処理聖職者,6a
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
		//揺らす処理聖職者,7a
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
		//揺れ幅が小さいやつ
		//揺らす処理聖職者,1b
		auto healermove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2, rightSize.height / 5)),
			NULL
		);
		healerrepeat1b = Repeat::create(healermove1b, continuity1);
		//揺らす処理聖職者,2b
		auto healermove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.42f, rightSize.height / 5.735f)),
			NULL
		);
		healerrepeat2b = Repeat::create(healermove2b, continuity1);
		//揺らす処理聖職者,3b
		auto healermove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.87f, rightSize.height / 5.735f)),
			NULL
		);
		healerrepeat3b = Repeat::create(healermove3b, continuity1);
		//揺らす処理聖職者,4b
		auto healermove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.18f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat4b = Repeat::create(healermove4b, continuity1);
		//揺らす処理聖職者,5b
		auto healermove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 2.08f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat5b = Repeat::create(healermove5b, continuity1);
		//揺らす処理聖職者,6b
		auto healermove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.77f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat6b = Repeat::create(healermove6b, continuity1);
		//揺らす処理聖職者,7b
		auto healermove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.7f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat7b = Repeat::create(healermove7b, continuity1);
	}
	//pl3frame.choisjobが聖職者の場合
	if (pl3frame.choicejob == HEALER) {
		//揺れ幅が比較的に大きいやつ
		//揺らす処理聖職者,1a
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
		//揺らす処理聖職者,2a
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
		//揺らす処理聖職者,3a
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
		//揺らす処理聖職者,4a
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
		//揺らす処理聖職者,5a
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
		//揺らす処理聖職者,6a
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
		//揺らす処理聖職者,7a
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
		//揺れが小さいやつ
		//揺らす処理聖職者,1b
		auto healermove1b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5 + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.32f, rightSize.height / 5)),
			NULL
		);
		healerrepeat1b = Repeat::create(healermove1b, continuity1);
		//揺らす処理聖職者,2b
		auto healermove2b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.489f, rightSize.height / 5.73f)),
			NULL
		);
		healerrepeat2b = Repeat::create(healermove2b, continuity1);
		//揺らす処理聖職者,3b
		auto healermove3b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.265f, rightSize.height / 5.73f)),
			NULL
		);
		healerrepeat3b = Repeat::create(healermove3b, continuity1);
		//揺らす処理聖職者,4b
		auto healermove4b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.39f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat4b = Repeat::create(healermove4b, continuity1);
		//揺らす処理聖職者,5b
		auto healermove5b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.35f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat5b = Repeat::create(healermove5b, continuity1);
		//揺らす処理聖職者,6b
		auto healermove6b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.21f, rightSize.height / 6.7f)),
			NULL
		);
		healerrepeat6b = Repeat::create(healermove6b, continuity1);
		//揺らす処理聖職者,7b
		auto healermove7b = CCSequence::create(
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f + 5)),
			CCMoveTo::create(movecnt, ccp(rightSize.width / 1.18f, rightSize.height / 6.3f)),
			NULL
		);
		healerrepeat7b = Repeat::create(healermove7b, continuity1);
	}
//ボス
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

//スキルターン処理
void BossScene::Skillturn()
{
	switch (bufft)
	{
//剣士　askill2(ヴァルキュリ－の防御を下げる)
	case BossScene::ASKILL2T: {
		//1ターン目は何もしない
		if (battleturn == 1) {
			allworkendflag = true;
		}

		//重ね掛けの場合があるから増やしておく
		//剣士　askill2の効果ターン処理1
		if (askill2.buffendflag1 == false) {
			if (askill2.buffturn1 > 1) {
				askill2.buffturn1 -= 1;
				askill2.buffendflag1 = true;	//スキルターンがあるならターンを1引いて終了
			}
			else if (askill2.buffturn1 == 0) {
				askill2.buffendflag1 = true;	//スキルターンがないならそのまま終了
			}
		}
		//剣士　askill2の効果ターン処理2
		if (askill2.buffendflag2 == false) {
			if (askill2.buffturn2 > 1) {
				askill2.buffturn2 -= 1;
				askill2.buffendflag2 = true;
			}
			else if (askill2.buffturn2 == 0) {
				askill2.buffendflag2 = true;
			}
		}
		//効果ターンが0になったらステータスを戻す
		//処理1
		if (askill2.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.def += askill2.buffdownefect1;		//下げた分だけ足す
				askill2.buffdownefect1 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理2
		if (askill2.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.def += askill2.buffdownefect2;		//下げた分だけ足す
				askill2.buffdownefect2 = 0;					//バフの効果を初期値に戻す
			}
		}

		//初期化
		auto askill2buffend = CCLabelTTF::create("ヴァルキュリーの防御力が戻った", "HGRSGU.TTC", fontsizeL);
		askill2buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//表記して終了
		if (battleturn > 1) {
			if (askill2.buffendflag1 == false) {
				if (askill2.buffturn1 == 1) {
					if (gameflame == flame80) {
						this->addChild(askill2buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						askill2.buffturn1 = 0;				//初期化する
						askill2.buffendflag1 = true;		//終わった
					}
				}
			}
			if (askill2.buffturn2 == 1) {
				if (askill2.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(askill2buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						askill2.buffturn2 = 0;				//初期化する
						askill2.buffendflag2 = true;		//終わった
					}
				}
			}
		}
		//剣士のスキル2の処理が全部終了したら終わり
		if (askill2.buffendflag1 == true && askill2.buffendflag2 == true) {
			bufft = ASKILL4T;
			this->removeChildByTag(buffendS);			//表記を消す
			askill2allworkendflag = true;				//スキル７の処理は全部終わった
			askill2.buffendflag1 = false;				//初期化
			askill2.buffendflag2 = false;				//初期化
			gameflame = 0;								//時間を0に
		}
		break;
	}
//剣士　askill4(ヴァルキュリ－の攻撃を下げる)
	case BossScene::ASKILL4T: {
		//重ね掛けの場合があるから増やしておく
		//剣士　askill4の効果ターン処理1
		if (askill4.buffendflag1 == false) {
			if (askill4.buffturn1 > 1) {
				askill4.buffturn1 -= 1;
				askill4.buffendflag1 = true;	//スキルターンがあるならターンを1引いて終了
			}
			else if (askill4.buffturn1 == 0) {
				askill4.buffendflag1 = true;	//スキルターンがないならそのまま終了
			}
		}
		//剣士　askill4の効果ターン処理2
		if (askill4.buffendflag2 == false) {
			if (askill4.buffturn2 > 1) {
				askill4.buffturn2 -= 1;
				askill4.buffendflag2 = true;
			}
			else if (askill4.buffturn2 == 0) {
				askill4.buffendflag2 = true;
			}
		}
		//効果ターンが0になったらステータスを戻す
		//処理1
		if (askill4.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.atk += askill4.buffdownefect1;		//下げた分だけ足す
				askill4.buffdownefect1 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理2
		if (askill4.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.atk += askill4.buffdownefect2;		//下げた分だけ足す
				askill4.buffdownefect2 = 0;					//バフの効果を初期値に戻す
			}
		}

		//初期化
		auto askill4buffend = CCLabelTTF::create("ヴァルキュリーの攻撃力が戻った", "HGRSGU.TTC", fontsizeL);
		askill4buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//表記して終了
		if (battleturn > 1) {
			if (askill4.buffturn1 == 1) {
				if (askill4.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(askill4buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						askill4.buffturn1 = 0;				//初期化する
						askill4.buffendflag1 = true;		//終わった
					}
				}
			}
			if (askill4.buffturn2 == 1) {
				if (askill4.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(askill4buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						askill4.buffturn2 = 0;				//初期化する
						askill4.buffendflag2 = true;		//終わった
					}
				}
			}
		}
		//剣士のスキル2の処理が全部終了したら終わり
		if (askill4.buffendflag1 == true && askill4.buffendflag2 == true) {
			bufft = ASKILL7T;
			this->removeChildByTag(buffendS);			//表記を消す
			askill4allworkendflag = true;				//スキル７の処理は全部終わった
			askill4.buffendflag1 = false;				//初期化
			askill4.buffendflag2 = false;				//初期化
			gameflame = 0;								//時間を0に
		}
		break;
	}
//剣士　ASKILL7(剣士の攻撃力小アップ)
	case BossScene::ASKILL7T: {
		//重ね掛けの場合があるから増やしておく
		//剣士　ASKILL7の効果ターン処理1
		if (askill7.buffendflag1 == false) {
			if (askill7.buffturn1 > 1) {
				askill7.buffturn1 -= 1;
				askill7.buffendflag1 = true;	//スキルターンがあるならターンを1引いて終了
			}
			else if (askill7.buffturn1 == 0) {
				askill7.buffendflag1 = true;	//スキルターンがないならそのまま終了
			}
		}
		//剣士　ASKILL7の効果ターン処理2
		if (askill7.buffendflag2 == false) {
			if (askill7.buffturn2 > 1) {
				askill7.buffturn2 -= 1;
				askill7.buffendflag2 = true;
			}
			else if (askill7.buffturn2 == 0) {
				askill7.buffendflag2 = true;
			}
		}
		//剣士　ASKILL7の効果ターン処理3
		if (askill7.buffendflag3 == false) {
			if (askill7.buffturn3 > 1) {
				askill7.buffturn3 -= 1;
				askill7.buffendflag3 = true;
			}
			else if (askill7.buffturn3 == 0) {
				askill7.buffendflag3 = true;
			}
		}
		//剣士　ASKILL7の効果ターン処理4
		if (askill7.buffendflag4 == false) {
			if (askill7.buffturn4 > 1) {
				askill7.buffturn4 -= 1;
				askill7.buffendflag4 = true;
			}
			else if (askill7.buffturn4 == 0) {
				askill7.buffendflag4 = true;
			}
		}
		//効果ターンが0になったらステータスを戻す
		//処理1
		if (askill7.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= askill7.buffupefect1;		//上げた分だけ引く
				askill7.buffupefect1 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理2
		if (askill7.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= askill7.buffupefect2;		//上げた分だけ引く
				askill7.buffupefect2 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理3
		if (askill7.buffturn3 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= askill7.buffupefect3;		//上げた分だけ引く
				askill7.buffupefect3 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理4
		if (askill7.buffturn4 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= askill7.buffupefect4;		//上げた分だけ引く
				askill7.buffupefect4 = 0;					//バフの効果を初期値に戻す
			}
		}

		//初期化
		auto askill7buffend = CCLabelTTF::create("剣士の攻撃力が戻った", "HGRSGU.TTC", fontsizeL);
		askill7buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//表記して終了
		if (battleturn > 1) {
			if (askill7.buffturn1 == 1) {
				if (askill7.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(askill7buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						askill7.buffturn1 = 0;				//初期化する
						askill7.buffendflag1 = true;		//終わった
					}
				}
			}
			if (askill7.buffturn2 == 1) {
				if (askill7.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(askill7buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						askill7.buffturn2 = 0;				//初期化する
						askill7.buffendflag2 = true;		//終わった
					}
				}
			}
			if (askill7.buffturn3 == 1) {
				if (askill7.buffendflag3 == false) {
					if (gameflame == flame80) {
						this->addChild(askill7buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						askill7.buffturn3 = 0;				//初期化する
						askill7.buffendflag3 = true;		//終わった
					}
				}
			}
			if (askill7.buffturn4 == 1) {
				if (askill7.buffendflag4 == false) {
					if (gameflame == flame80) {
						this->addChild(askill7buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						askill7.buffturn4 = 0;				//初期化する
						askill7.buffendflag4 = true;		//終わった
					}
				}
			}
		}
		//剣士のスキル7の処理が全部終了したら終わり
		if (askill7.buffendflag1 == true && askill7.buffendflag2 == true
			&& askill7.buffendflag3 == true && askill7.buffendflag4 == true) {
			bufft = ASKILL8T;
			this->removeChildByTag(buffendS);			//表記を消す
			askill7allworkendflag = true;				//スキル７の処理は全部終わった
			askill7.buffendflag1 = false;				//初期化
			askill7.buffendflag2 = false;				//初期化
			askill7.buffendflag3 = false;				//初期化
			askill7.buffendflag4 = false;				//初期化
			gameflame = 0;								//時間を0に
		}
		break;
	}
//剣士　askill8(剣士の攻撃力ダイアップ,防御力小ダウン)
	case BossScene::ASKILL8T: {
		//重ね掛けの場合があるから増やしておく
		//剣士　askill8の効果ターン処理1
		if (askill8.buffendflag1 == false) {
			if (askill8.buffturn1 > 1) {
				askill8.buffturn1 -= 1;
				askill8.buffendflag1 = true;	//スキルターンがあるならターンを1引いて終了
			}
			else if (askill8.buffturn1 == 0) {
				askill8.buffendflag1 = true;	//スキルターンがないならそのまま終了
			}
		}
		//剣士　askill8の効果ターン処理2
		if (askill8.buffendflag2 == false) {
			if (askill8.buffturn2 > 1) {
				askill8.buffturn2 -= 1;
				askill8.buffendflag2 = true;
			}
			else if (askill8.buffturn2 == 0) {
				askill8.buffendflag2 = true;
			}
		}
		//剣士　askill8の効果ターン処理3
		if (askill8.buffendflag3 == false) {
			if (askill8.buffturn3 > 1) {
				askill8.buffturn3 -= 1;
				askill8.buffendflag3 = true;
			}
			else if (askill8.buffturn3 == 0) {
				askill8.buffendflag3 = true;
			}
		}
		//剣士　askill8の効果ターン処理4
		if (askill8.buffendflag4 == false) {
			if (askill8.buffturn4 > 1) {
				askill8.buffturn4 -= 1;
				askill8.buffendflag4 = true;
			}
			else if (askill8.buffturn4 == 0) {
				askill8.buffendflag4 = true;
			}
		}
		//効果ターンが0になったらステータスを戻す
		//処理1
		if (askill8.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= askill8.buffupefect1;		//上げた分だけ引く
				attacker.def += askill8.buffdownefect1;		//下げた分だけ足す
				askill8.buffupefect1 = 0;					//バフの効果を初期値に戻す
				askill8.buffdownefect1 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理2
		if (askill8.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= askill8.buffupefect2;		//上げた分だけ引く
				attacker.def += askill8.buffdownefect2;		//下げた分だけ足す
				askill8.buffupefect2 = 0;					//バフの効果を初期値に戻す
				askill8.buffdownefect2 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理3
		if (askill8.buffturn3 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= askill8.buffupefect3;		//上げた分だけ引く
				attacker.def += askill8.buffdownefect3;		//下げた分だけ足す
				askill8.buffupefect3 = 0;					//バフの効果を初期値に戻す
				askill8.buffdownefect3 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理4
		if (askill8.buffturn4 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= askill8.buffupefect4;		//上げた分だけ引く
				attacker.def += askill8.buffdownefect4;		//下げた分だけ足す
				askill8.buffupefect4 = 0;					//バフの効果を初期値に戻す
				askill8.buffdownefect4 = 0;					//バフの効果を初期値に戻す
			}
		}

		//初期化
		auto askill8buffend = CCLabelTTF::create("剣士の攻撃力が戻った", "HGRSGU.TTC", fontsizeL);
		askill8buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		auto askill8buffend2 = CCLabelTTF::create("剣士の防御力が戻った", "HGRSGU.TTC", fontsizeL);
		askill8buffend2->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//表記して終了
		if (battleturn > 1) {
			if (askill8.buffturn1 == 1) {
				if (askill8.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(askill8buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//表記を消す
						this->addChild(askill8buffend2, backdepth, buffend2S);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame220) {
						askill8.buffturn1 = 0;				//初期化する
						askill8.buffendflag1 = true;		//終わった
					}
				}
			}
			if (askill8.buffturn2 == 1) {
				if (askill8.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(askill8buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//表記を消す
						this->addChild(askill8buffend2, backdepth, buffend2S);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame220) {
						askill8.buffturn2 = 0;				//初期化する
						askill8.buffendflag2 = true;		//終わった
					}
				}
			}
			if (askill8.buffturn3 == 1) {
				if (askill8.buffendflag3 == false) {
					if (gameflame == flame80) {
						this->addChild(askill8buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//表記を消す
						this->addChild(askill8buffend2, backdepth, buffend2S);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame220) {
						askill8.buffturn3 = 0;				//初期化する
						askill8.buffendflag3 = true;		//終わった
					}
				}
			}
			if (askill8.buffturn4 == 1) {
				if (askill8.buffendflag4 == false) {
					if (gameflame == flame80) {
						this->addChild(askill8buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//表記を消す
						this->addChild(askill8buffend2, backdepth, buffend2S);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame220) {
						askill8.buffturn4 = 0;				//初期化する
						askill8.buffendflag4 = true;		//終わった
					}
				}
			}
		}
		//剣士のスキル8の処理が全部終了したら終わり
		if (askill8.buffendflag1 == true && askill8.buffendflag2 == true
			&& askill8.buffendflag3 == true && askill8.buffendflag4 == true) {
			bufft = SSKILL2T;
			this->removeChildByTag(buffend2S);			//表記を消す
			askill8allworkendflag = true;				//スキル７の処理は全部終わった
			askill8.buffendflag1 = false;				//初期化
			askill8.buffendflag2 = false;				//初期化
			askill8.buffendflag3 = false;				//初期化
			askill8.buffendflag4 = false;				//初期化
			gameflame = 0;								//時間を0に
		}
		break;
	}
//騎士　sskill5(全員の代わりにダメージを受ける)
	case BossScene::SSKILL2T: {
		bufft = SSKILL3T;
		break;
	}
//騎士　sskill3(騎士にタゲ集中)
	case BossScene::SSKILL3T: {
		//重ね掛けの場合があるから増やしておく
		//騎士　sskill3の効果ターン処理1
		if (sskill3.buffendflag1 == false) {
			if (sskill3.buffturn1 > 1) {
				sskill3.buffturn1 -= 1;
				sskill3.buffendflag1 = true;	//スキルターンがあるならターンを1引いて終了
			}
			else if (sskill3.buffturn1 == 0) {
				sskill3.buffendflag1 = true;	//スキルターンがないならそのまま終了
			}
		}
		//騎士　sskill3の効果ターン処理2
		if (sskill3.buffendflag2 == false) {
			if (sskill3.buffturn2 > 1) {
				sskill3.buffturn2 -= 1;
				sskill3.buffendflag2 = true;
			}
			else if (sskill3.buffturn2 == 0) {
				sskill3.buffendflag2 = true;
			}
		}
		
		//効果ターンが0になったらステータスを戻す
		//処理1
		if (sskill3.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				coverflag1 = false;		//タゲ集中1解除
			}
		}
		//処理2
		if (sskill3.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				coverflag2 = false;		//タゲ集中2解除
			}
		}

		//初期化
		auto sskill3buffend = CCLabelTTF::create("騎士のタゲ集中率が戻った", "HGRSGU.TTC", fontsizeL);
		sskill3buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//表記して終了
		if (battleturn > 1) {
			if (sskill3.buffturn1 == 1) {
				if (sskill3.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill3buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						sskill3.buffturn1 = 0;				//初期化する
						sskill3.buffendflag1 = true;		//終わった
					}
				}
			}
			if (sskill3.buffturn2 == 1) {
				if (sskill3.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill3buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						sskill3.buffturn2 = 0;				//初期化する
						sskill3.buffendflag2 = true;		//終わった
					}
				}
			}
		}
		//騎士のスキル3の処理が全部終了したら終わり
		if (sskill3.buffendflag1 == true && sskill3.buffendflag2 == true) {
			bufft = SSKILL4T;
			this->removeChildByTag(buffendS);			//表記を消す
			sskill3allworkendflag = true;				//スキル７の処理は全部終わった
			sskill3.buffendflag1 = false;				//初期化
			sskill3.buffendflag2 = false;				//初期化
			gameflame = 0;								//時間を0に
		}
		break;
	}
//騎士　sskill4(選んだやつの代わりにダメージを受ける)
	case BossScene::SSKILL4T: {
		//重ね掛けの場合があるから増やしておく
		//騎士　sskill4の効果ターン処理1
		if (sskill4.buffendflag1 == false) {
			if (sskill4.buffturn1 > 1) {
				sskill4.buffturn1 -= 1;
				sskill4.buffendflag1 = true;	//スキルターンがあるならターンを1引いて終了
			}
			else if (sskill4.buffturn1 == 0) {
				sskill4.buffendflag1 = true;	//スキルターンがないならそのまま終了
			}
		}

		//効果ターンが0になったらステータスを戻す
		//処理1
		if (sskill4.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				insteadflag = false;		//タゲ集中1解除
			}
		}
		
		//初期化
		auto sskill4buffend = CCLabelTTF::create("騎士の単体庇う状態が戻った", "HGRSGU.TTC", fontsizeL);
		sskill4buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//表記して終了
		if (battleturn > 1) {
			if (sskill4.buffturn1 == 1) {
				if (sskill4.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill4buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						sskill4.buffturn1 = 0;				//初期化する
						sskill4.buffendflag1 = true;		//終わった
					}
				}
			}
		}
		//騎士のスキル3の処理が全部終了したら終わり
		if (sskill4.buffendflag1 == true) {
			bufft = SSKILL5T;
			this->removeChildByTag(buffendS);			//表記を消す
			sskill4allworkendflag = true;				//スキル７の処理は全部終わった
			sskill4.buffendflag1 = false;				//初期化
			sskill4.buffendflag2 = false;				//初期化
			gameflame = 0;								//時間を0に
		}
		break;
	}
//騎士　sskill5(全員の代わりにダメージを受ける)
	case BossScene::SSKILL5T: {
		//重ね掛けの場合があるから増やしておく
		//騎士　sskill5の効果ターン処理1
		if (sskill5.buffendflag1 == false) {
			if (sskill5.buffturn1 > 1) {
				sskill5.buffturn1 -= 1;
				sskill5.buffendflag1 = true;	//スキルターンがあるならターンを1引いて終了
			}
			else if (sskill5.buffturn1 == 0) {
				sskill5.buffendflag1 = true;	//スキルターンがないならそのまま終了
			}
		}

		//効果ターンが0になったらステータスを戻す
		//処理1
		if (sskill5.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				allinsteadflag = false;		//タゲ集中1解除
			}
		}

		//初期化
		auto sskill5buffend = CCLabelTTF::create("騎士の全体庇う状態が戻った", "HGRSGU.TTC", fontsizeL);
		sskill5buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//表記して終了
		if (battleturn > 1) {
			if (sskill5.buffturn1 == 1) {
				if (sskill5.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill5buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						sskill5.buffturn1 = 0;				//初期化する
						sskill5.buffendflag1 = true;		//終わった
					}
				}
			}
		}
		//騎士のスキル3の処理が全部終了したら終わり
		if (sskill5.buffendflag1 == true) {
			bufft = SSKILL6T;
			this->removeChildByTag(buffendS);			//表記を消す
			sskill5allworkendflag = true;				//スキル７の処理は全部終わった
			sskill5.buffendflag1 = false;				//初期化
			sskill5.buffendflag2 = false;				//初期化
			gameflame = 0;								//時間を0に
		}
		break;
	}
//騎士　sskill6(一度死んだら復活)
	case BossScene::SSKILL6T: {
		bufft = SSKILL7T;
		break;
	}
//騎士　sskill7(騎士の防御力小アップ)
	case BossScene::SSKILL7T: {
		//重ね掛けの場合があるから増やしておく
		//騎士　sskill7の効果ターン処理1
		if (sskill7.buffendflag1 == false) {
			if (sskill7.buffturn1 > 1) {
				sskill7.buffturn1 -= 1;
				sskill7.buffendflag1 = true;	//スキルターンがあるならターンを1引いて終了
			}
			else if (sskill7.buffturn1 == 0) {
				sskill7.buffendflag1 = true;	//スキルターンがないならそのまま終了
			}
		}
		//騎士　sskill7の効果ターン処理2
		if (sskill7.buffendflag2 == false) {
			if (sskill7.buffturn2 > 1) {
				sskill7.buffturn2 -= 1;
				sskill7.buffendflag2 = true;
			}
			else if (sskill7.buffturn2 == 0) {
				sskill7.buffendflag2 = true;
			}
		}
		//騎士　sskill7の効果ターン処理3
		if (sskill7.buffendflag3 == false) {
			if (sskill7.buffturn3 > 1) {
				sskill7.buffturn3 -= 1;
				sskill7.buffendflag3 = true;
			}
			else if (sskill7.buffturn3 == 0) {
				sskill7.buffendflag3 = true;
			}
		}
		//騎士　sskill7の効果ターン処理4
		if (sskill7.buffendflag4 == false) {
			if (sskill7.buffturn4 > 1) {
				sskill7.buffturn4 -= 1;
				sskill7.buffendflag4 = true;
			}
			else if (sskill7.buffturn4 == 0) {
				sskill7.buffendflag4 = true;
			}
		}
		//騎士　sskill7の効果ターン処理5
		if (sskill7.buffendflag5 == false) {
			if (sskill7.buffturn5 > 1) {
				sskill7.buffturn5 -= 1;
				sskill7.buffendflag5 = true;
			}
			else if (sskill7.buffturn5 == 0) {
				sskill7.buffendflag5 = true;
			}
		}
		//効果ターンが0になったらステータスを戻す
		//処理1
		if (sskill7.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.def -= sskill7.buffupefect1;		//上げた分だけ引く
				sskill7.buffupefect1 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理2
		if (sskill7.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.def -= sskill7.buffupefect2;		//上げた分だけ引く
				sskill7.buffupefect2 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理3
		if (sskill7.buffturn3 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.def -= sskill7.buffupefect3;		//上げた分だけ引く
				sskill7.buffupefect3 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理4
		if (sskill7.buffturn4 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.def -= sskill7.buffupefect4;		//上げた分だけ引く
				sskill7.buffupefect4 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理5
		if (sskill7.buffturn5 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.def -= sskill7.buffupefect5;		//上げた分だけ引く
				sskill7.buffupefect5 = 0;					//バフの効果を初期値に戻す
			}
		}

		//初期化
		auto sskill7buffend = CCLabelTTF::create("騎士の防御力が戻った", "HGRSGU.TTC", fontsizeL);
		sskill7buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//表記して終了
		if (battleturn > 1) {
			if (sskill7.buffturn1 == 1) {
				if (sskill7.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill7buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						sskill7.buffturn1 = 0;				//初期化する
						sskill7.buffendflag1 = true;		//終わった
					}
				}
			}
			if (sskill7.buffturn2 == 1) {
				if (sskill7.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill7buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						sskill7.buffturn2 = 0;				//初期化する
						sskill7.buffendflag2 = true;		//終わった
					}
				}
			}
			if (sskill7.buffturn3 == 1) {
				if (sskill7.buffendflag3 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill7buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						sskill7.buffturn3 = 0;				//初期化する
						sskill7.buffendflag3 = true;		//終わった
					}
				}
			}
			if (sskill7.buffturn4 == 1) {
				if (sskill7.buffendflag4 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill7buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						sskill7.buffturn4 = 0;				//初期化する
						sskill7.buffendflag4 = true;		//終わった
					}
				}
			}
			if (sskill7.buffturn5 == 1) {
				if (sskill7.buffendflag5 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill7buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						sskill7.buffturn5 = 0;				//初期化する
						sskill7.buffendflag5 = true;		//終わった
					}
				}
			}
		}
		//騎士のスキル7の処理が全部終了したら終わり
		if (sskill7.buffendflag1 == true && sskill7.buffendflag2 == true
			&& sskill7.buffendflag3 == true && sskill7.buffendflag4 == true
			&& sskill7.buffendflag5 == true) {
			bufft = SSKILL8T;
			this->removeChildByTag(buffendS);			//表記を消す
			sskill7allworkendflag = true;				//スキル７の処理は全部終わった
			sskill7.buffendflag1 = false;				//初期化
			sskill7.buffendflag2 = false;				//初期化
			sskill7.buffendflag3 = false;				//初期化
			sskill7.buffendflag4 = false;				//初期化
			sskill7.buffendflag5 = false;				//初期化
			gameflame = 0;								//時間を0に
		}
		break;
	}
//騎士　sskill8(騎士の防御力ダイアップ,攻撃力小ダウン)
	case BossScene::SSKILL8T: {
		//重ね掛けの場合があるから増やしておく
		//騎士　sskill8の効果ターン処理1
		if (sskill8.buffendflag1 == false) {
			if (sskill8.buffturn1 > 1) {
				sskill8.buffturn1 -= 1;
				sskill8.buffendflag1 = true;	//スキルターンがあるならターンを1引いて終了
			}
			else if (sskill8.buffturn1 == 0) {
				sskill8.buffendflag1 = true;	//スキルターンがないならそのまま終了
			}
		}
		//騎士　sskill8の効果ターン処理2
		if (sskill8.buffendflag2 == false) {
			if (sskill8.buffturn2 > 1) {
				sskill8.buffturn2 -= 1;
				sskill8.buffendflag2 = true;
			}
			else if (sskill8.buffturn2 == 0) {
				sskill8.buffendflag2 = true;
			}
		}
		//騎士　sskill8の効果ターン処理3
		if (sskill8.buffendflag3 == false) {
			if (sskill8.buffturn3 > 1) {
				sskill8.buffturn3 -= 1;
				sskill8.buffendflag3 = true;
			}
			else if (sskill8.buffturn3 == 0) {
				sskill8.buffendflag3 = true;
			}
		}
		//騎士　sskill8の効果ターン処理4
		if (sskill8.buffendflag4 == false) {
			if (sskill8.buffturn4 > 1) {
				sskill8.buffturn4 -= 1;
				sskill8.buffendflag4 = true;
			}
			else if (sskill8.buffturn4 == 0) {
				sskill8.buffendflag4 = true;
			}
		}
		//効果ターンが0になったらステータスを戻す
		//処理1
		if (sskill8.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				shield.def -= sskill8.buffupefect1;	//上げた分だけ引く
				shield.atk += sskill8.buffdownefect1;	//下げた分だけ足す
				sskill8.buffupefect1 = 0;				//バフの効果を初期値に戻す
				sskill8.buffdownefect1 = 0;				//バフの効果を初期値に戻す
			}
		}
		//処理2
		if (sskill8.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				shield.def -= sskill8.buffupefect2;		//上げた分だけ引く
				shield.atk += sskill8.buffdownefect2;	//下げた分だけ足す
				sskill8.buffupefect2 = 0;				//バフの効果を初期値に戻す
				sskill8.buffdownefect2 = 0;				//バフの効果を初期値に戻す
			}
		}
		//処理3
		if (sskill8.buffturn3 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				shield.def -= sskill8.buffupefect3;		//上げた分だけ引く
				shield.atk += sskill8.buffdownefect3;	//下げた分だけ足す
				sskill8.buffupefect3 = 0;				//バフの効果を初期値に戻す
				sskill8.buffdownefect3 = 0;				//バフの効果を初期値に戻す
			}
		}
		//処理4
		if (sskill8.buffturn4 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				shield.def -= sskill8.buffupefect4;		//上げた分だけ引く
				shield.atk += sskill8.buffdownefect4;	//下げた分だけ足す
				sskill8.buffupefect4 = 0;				//バフの効果を初期値に戻す
				sskill8.buffdownefect4 = 0;				//バフの効果を初期値に戻す
			}
		}

		//初期化
		auto sskill8buffend = CCLabelTTF::create("騎士の防御力が戻った", "HGRSGU.TTC", fontsizeL);
		sskill8buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		auto sskill8buffend2 = CCLabelTTF::create("騎士の攻撃力が戻った", "HGRSGU.TTC", fontsizeL);
		sskill8buffend2->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//表記して終了
		if (battleturn > 1) {
			if (sskill8.buffturn1 == 1) {
				if (sskill8.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill8buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//表記を消す
						this->addChild(sskill8buffend2, backdepth, buffend2S);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame220) {
						sskill8.buffturn1 = 0;				//初期化する
						sskill8.buffendflag1 = true;		//終わった
					}
				}
			}
			if (sskill8.buffturn2 == 1) {
				if (sskill8.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill8buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//表記を消す
						this->addChild(sskill8buffend2, backdepth, buffend2S);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame220) {
						sskill8.buffturn2 = 0;				//初期化する
						sskill8.buffendflag2 = true;		//終わった
					}
				}
			}
			if (sskill8.buffturn3 == 1) {
				if (sskill8.buffendflag3 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill8buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//表記を消す
						this->addChild(sskill8buffend2, backdepth, buffend2S);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame220) {
						sskill8.buffturn3 = 0;				//初期化する
						sskill8.buffendflag3 = true;		//終わった
					}
				}
			}
			if (sskill8.buffturn4 == 1) {
				if (sskill8.buffendflag4 == false) {
					if (gameflame == flame80) {
						this->addChild(sskill8buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//表記を消す
						this->addChild(sskill8buffend2, backdepth, buffend2S);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame220) {
						sskill8.buffturn4 = 0;				//初期化する
						sskill8.buffendflag4 = true;		//終わった
					}
				}
			}
		}
		//騎士のスキル8の処理が全部終了したら終わり
		if (sskill8.buffendflag1 == true && sskill8.buffendflag2 == true
			&& sskill8.buffendflag3 == true && sskill8.buffendflag4 == true) {
			bufft = MSKILL2T;
			this->removeChildByTag(buffend2S);			//表記を消す
			sskill8allworkendflag = true;				//スキル8の処理は全部終わった
			sskill8.buffendflag1 = false;				//初期化
			sskill8.buffendflag2 = false;				//初期化
			sskill8.buffendflag3 = false;				//初期化
			sskill8.buffendflag4 = false;				//初期化
			gameflame = 0;								//時間を0に
		}
		break;
	}
//魔術師 mskill2(魔術師の防御力小アップ)
	case BossScene::MSKILL2T: {
		if (mskill2.buffendflag1 == false) {
			//重ね掛けの場合があるから増やしておく
			//魔術師　mskill2の効果ターン処理1
			if (mskill2.buffturn1 > 1) {
				mskill2.buffturn1 -= 1;
				mskill2.buffendflag1 = true;	//スキルターンがあるならターンを1引いて終了
			}
			else if (mskill2.buffturn1 == 0) {
				mskill2.buffendflag1 = true;	//スキルターンがないならそのまま終了
			}
		}
		//魔術師　mskill2の効果ターン処理2
		if (mskill2.buffendflag2 == false) {
			if (mskill2.buffturn2 > 1) {
				mskill2.buffturn2 -= 1;
				mskill2.buffendflag2 = true;
			}
			else if (mskill2.buffturn2 == 0) {
				mskill2.buffendflag2 = true;
			}
		}
		//効果ターンが0になったらステータスを戻す
		//処理1
		if (mskill2.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				magic.def -= mskill2.buffupefect1;		//上げた分だけ引く
				mskill2.buffupefect1 = 0;				//バフの効果を初期値に戻す
			}
		}
		//処理2
		if (mskill2.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				magic.def -= mskill2.buffupefect2;		//上げた分だけ引く
				mskill2.buffupefect2 = 0;				//バフの効果を初期値に戻す
			}
		}

		//初期化
		auto mskill2buffend = CCLabelTTF::create("魔術師の防御力が戻った", "HGRSGU.TTC", fontsizeL);
		mskill2buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//表記して終了
		if (battleturn > 1) {
			if (mskill2.buffturn1 == 1) {
				if (mskill2.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill2buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						mskill2.buffturn1 = 0;				//初期化する
						mskill2.buffendflag1 = true;		//終わった
					}
				}
			}
			if (mskill2.buffturn2 == 1) {
				if (mskill2.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill2buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						mskill2.buffturn2 = 0;				//初期化する
						mskill2.buffendflag2 = true;		//終わった
					}
				}
			}
		}
		//魔術師のスキル2の処理が全部終了したら終わり
		if (mskill2.buffendflag1 == true && mskill2.buffendflag2 == true) {
			bufft = MSKILL3T;
			this->removeChildByTag(buffendS);			//表記を消す
			mskill2allworkendflag = true;				//スキル７の処理は全部終わった
			mskill2.buffendflag1 = false;				//初期化
			mskill2.buffendflag2 = false;				//初期化
			gameflame = 0;								//時間を0に
		}
		break;
	}
//魔術師 mskill3(敵の攻撃力を小ダウン)
	case BossScene::MSKILL3T: {
		if (mskill3.buffendflag1 == false) {
			//重ね掛けの場合があるから増やしておく
			//魔術師　mskill3の効果ターン処理1
			if (mskill3.buffturn1 > 1) {
				mskill3.buffturn1 -= 1;
				mskill3.buffendflag1 = true;	//スキルターンがあるならターンを1引いて終了
			}
			else if (mskill3.buffturn1 == 0) {
				mskill3.buffendflag1 = true;	//スキルターンがないならそのまま終了
			}
		}
		//魔術師　mskill3の効果ターン処理2
		if (mskill3.buffendflag2 == false) {
			if (mskill3.buffturn2 > 1) {
				mskill3.buffturn2 -= 1;
				mskill3.buffendflag2 = true;
			}
			else if (mskill3.buffturn2 == 0) {
				mskill3.buffendflag2 = true;
			}
		}
		//効果ターンが0になったらステータスを戻す
		//処理1
		if (mskill3.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.atk += mskill3.buffdownefect1;		//下げた分だけ足す
				mskill3.buffdownefect1 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理2
		if (mskill3.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.atk += mskill3.buffdownefect2;		//下げた分だけ足す
				mskill3.buffdownefect2 = 0;					//バフの効果を初期値に戻す
			}
		}

		//初期化
		auto mskill3buffend = CCLabelTTF::create("ヴァルキュリーの攻撃力が戻った", "HGRSGU.TTC", fontsizeL);
		mskill3buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//表記して終了
		if (battleturn > 1) {
			if (mskill3.buffturn1 == 1) {
				if (mskill3.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill3buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						mskill3.buffturn1 = 0;				//初期化する
						mskill3.buffendflag1 = true;		//終わった
					}
				}
			}
			if (mskill3.buffturn2 == 1) {
				if (mskill3.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill3buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						mskill3.buffturn2 = 0;				//初期化する
						mskill3.buffendflag2 = true;		//終わった
					}
				}
			}
		}
		//魔術師のスキル2の処理が全部終了したら終わり
		if (mskill3.buffendflag1 == true && mskill3.buffendflag2 == true) {
			bufft = MSKILL5T;
			this->removeChildByTag(buffendS);			//表記を消す
			mskill3allworkendflag = true;				//スキル７の処理は全部終わった
			mskill3.buffendflag1 = false;				//初期化
			mskill3.buffendflag2 = false;				//初期化
			gameflame = 0;								//時間を0に
		}
		break;
	}
//魔術師 mskill5(味方の攻撃力を防御力を小アップ)
	case BossScene::MSKILL5T: {
		//重ね掛けの場合があるから増やしておく
		//魔術師　mskill5の効果ターン処理1
		if (mskill5.buffendflag1 == false) {
			if (mskill5.buffturn1 > 1) {
				mskill5.buffturn1 -= 1;
				mskill5.buffendflag1 = true;	//スキルターンがあるならターンを1引いて終了
			}
			else if (mskill5.buffturn1 == 0) {
				mskill5.buffendflag1 = true;	//スキルターンがないならそのまま終了
			}
		}
		//魔術師　mskill5の効果ターン処理2
		if (mskill5.buffendflag2 == false) {
			if (mskill5.buffturn2 > 1) {
				mskill5.buffturn2 -= 1;
				mskill5.buffendflag2 = true;
			}
			else if (mskill5.buffturn2 == 0) {
				mskill5.buffendflag2 = true;
			}
		}
		//魔術師　mskill5の効果ターン処理3
		if (mskill5.buffendflag3 == false) {
			if (mskill5.buffturn3 > 1) {
				mskill5.buffturn3 -= 1;
				mskill5.buffendflag3 = true;
			}
			else if (mskill5.buffturn3 == 0) {
				mskill5.buffendflag3 = true;
			}
		}
		//魔術師　mskill5の効果ターン処理4
		if (mskill5.buffendflag4 == false) {
			if (mskill5.buffturn4 > 1) {
				mskill5.buffturn4 -= 1;
				mskill5.buffendflag4 = true;
			}
			else if (mskill5.buffturn4 == 0) {
				mskill5.buffendflag4 = true;
			}
		}

		//効果ターンが0になったらステータスを戻す
		//処理1
		if (mskill5.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= mskill5.attackeratkbuff1;	//上げた分だけ引く
				attacker.def -= mskill5.attackerdefbuff1;	//上げた分だけ引く
				shield.atk -= mskill5.shieldatkbuff1;		//上げた分だけ引く
				shield.def -= mskill5.shielddefbuff1;		//上げた分だけ引く
				magic.atk -= mskill5.magicatkbuff1;			//上げた分だけ引く
				magic.def -= mskill5.magicdefbuff1;			//上げた分だけ引く
				healer.atk -= mskill5.healeratkbuff1;		//上げた分だけ引く
				healer.def -= mskill5.healerdefbuff1;		//上げた分だけ引く
				mskill5.attackeratkbuff1 = 0;			//バフの効果を初期値に戻す
				mskill5.attackerdefbuff1 = 0;			//バフの効果を初期値に戻す
				mskill5.shieldatkbuff1 = 0;				//バフの効果を初期値に戻す
				mskill5.shielddefbuff1 = 0;				//バフの効果を初期値に戻す
				mskill5.magicatkbuff1 = 0;				//バフの効果を初期値に戻す
				mskill5.magicdefbuff1 = 0;				//バフの効果を初期値に戻す
				mskill5.healeratkbuff1 = 0;				//バフの効果を初期値に戻す
				mskill5.healerdefbuff1 = 0;				//バフの効果を初期値に戻す
			}
		}
		//処理2
		if (mskill5.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= mskill5.attackeratkbuff2;	//上げた分だけ引く
				attacker.def -= mskill5.attackerdefbuff2;	//上げた分だけ引く
				shield.atk -= mskill5.shieldatkbuff2;		//上げた分だけ引く
				shield.def -= mskill5.shielddefbuff2;		//上げた分だけ引く
				magic.atk -= mskill5.magicatkbuff2;			//上げた分だけ引く
				magic.def -= mskill5.magicdefbuff2;			//上げた分だけ引く
				healer.atk -= mskill5.healeratkbuff2;		//上げた分だけ引く
				healer.def -= mskill5.healerdefbuff2;		//上げた分だけ引く
				mskill5.attackeratkbuff2 = 0;			//バフの効果を初期値に戻す
				mskill5.attackerdefbuff2 = 0;			//バフの効果を初期値に戻す
				mskill5.shieldatkbuff2 = 0;				//バフの効果を初期値に戻す
				mskill5.shielddefbuff2 = 0;				//バフの効果を初期値に戻す
				mskill5.magicatkbuff2 = 0;				//バフの効果を初期値に戻す
				mskill5.magicdefbuff2 = 0;				//バフの効果を初期値に戻す
				mskill5.healeratkbuff2 = 0;				//バフの効果を初期値に戻す
				mskill5.healerdefbuff2 = 0;				//バフの効果を初期値に戻す
			}
		}
		//処理3
		if (mskill5.buffturn3 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= mskill5.attackeratkbuff3;	//上げた分だけ引く
				attacker.def -= mskill5.attackerdefbuff3;	//上げた分だけ引く
				shield.atk -= mskill5.shieldatkbuff3;		//上げた分だけ引く
				shield.def -= mskill5.shielddefbuff3;		//上げた分だけ引く
				magic.atk -= mskill5.magicatkbuff3;			//上げた分だけ引く
				magic.def -= mskill5.magicdefbuff3;			//上げた分だけ引く
				healer.atk -= mskill5.healeratkbuff3;		//上げた分だけ引く
				healer.def -= mskill5.healerdefbuff3;		//上げた分だけ引く
				mskill5.attackeratkbuff3 = 0;			//バフの効果を初期値に戻す
				mskill5.attackerdefbuff3 = 0;			//バフの効果を初期値に戻す
				mskill5.shieldatkbuff3 = 0;				//バフの効果を初期値に戻す
				mskill5.shielddefbuff3 = 0;				//バフの効果を初期値に戻す
				mskill5.magicatkbuff3 = 0;				//バフの効果を初期値に戻す
				mskill5.magicdefbuff3 = 0;				//バフの効果を初期値に戻す
				mskill5.healeratkbuff3 = 0;				//バフの効果を初期値に戻す
				mskill5.healerdefbuff3 = 0;				//バフの効果を初期値に戻す
			}
		}
		//処理4
		if (mskill5.buffturn4 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= mskill5.attackeratkbuff4;	//上げた分だけ引く
				attacker.def -= mskill5.attackerdefbuff4;	//上げた分だけ引く
				shield.atk -= mskill5.shieldatkbuff4;		//上げた分だけ引く
				shield.def -= mskill5.shielddefbuff4;		//上げた分だけ引く
				magic.atk -= mskill5.magicatkbuff4;			//上げた分だけ引く
				magic.def -= mskill5.magicdefbuff4;			//上げた分だけ引く
				healer.atk -= mskill5.healeratkbuff4;		//上げた分だけ引く
				healer.def -= mskill5.healerdefbuff4;		//上げた分だけ引く
				mskill5.attackeratkbuff4 = 0;			//バフの効果を初期値に戻す
				mskill5.attackerdefbuff4 = 0;			//バフの効果を初期値に戻す
				mskill5.shieldatkbuff4 = 0;				//バフの効果を初期値に戻す
				mskill5.shielddefbuff4 = 0;				//バフの効果を初期値に戻す
				mskill5.magicatkbuff4 = 0;				//バフの効果を初期値に戻す
				mskill5.magicdefbuff4 = 0;				//バフの効果を初期値に戻す
				mskill5.healeratkbuff4 = 0;				//バフの効果を初期値に戻す
				mskill5.healerdefbuff4 = 0;				//バフの効果を初期値に戻す
			}
		}

		//初期化
		auto mskill5buffend = CCLabelTTF::create("全員の攻撃力が戻った", "HGRSGU.TTC", fontsizeL);
		mskill5buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		auto mskill5buffend2 = CCLabelTTF::create("全員の防御力が戻った", "HGRSGU.TTC", fontsizeL);
		mskill5buffend2->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//表記して終了
		if (battleturn > 1) {
			if (mskill5.buffturn1 == 1) {
				if (mskill5.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill5buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//表記を消す
						this->addChild(mskill5buffend2, backdepth, buffend2S);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame220) {
						mskill5.buffturn1 = 0;				//初期化する
						mskill5.buffendflag1 = true;		//終わった
					}
				}
			}
			if (mskill5.buffturn2 == 1) {
				if (mskill5.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill5buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//表記を消す
						this->addChild(mskill5buffend2, backdepth, buffend2S);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame220) {
						mskill5.buffturn2 = 0;				//初期化する
						mskill5.buffendflag2 = true;		//終わった
					}
				}
			}
			if (mskill5.buffturn3 == 1) {
				if (mskill5.buffendflag3 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill5buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//表記を消す
						this->addChild(mskill5buffend2, backdepth, buffend2S);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame220) {
						mskill5.buffturn3 = 0;				//初期化する
						mskill5.buffendflag3 = true;		//終わった
					}
				}
			}
			if (mskill5.buffturn4 == 1) {
				if (mskill5.buffendflag4 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill5buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//表記を消す
						this->addChild(mskill5buffend2, backdepth, buffend2S);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame220) {
						mskill5.buffturn4 = 0;				//初期化する
						mskill5.buffendflag4 = true;		//終わった
					}
				}
			}
		}
		//魔術師のスキル8の処理が全部終了したら終わり
		if (mskill5.buffendflag1 == true && mskill5.buffendflag2 == true
			&& mskill5.buffendflag3 == true && mskill5.buffendflag4 == true) {
			bufft = MSKILL6T;
			this->removeChildByTag(buffend2S);			//表記を消す
			mskill5allworkendflag = true;				//スキル７の処理は全部終わった
			mskill5.buffendflag1 = false;				//初期化
			mskill5.buffendflag2 = false;				//初期化
			mskill5.buffendflag3 = false;				//初期化
			mskill5.buffendflag4 = false;				//初期化
			gameflame = 0;								//時間を0に
		}
		break;
	}
//魔術師 mskill6(味方の攻撃力を防御力を大アップ)
	case BossScene::MSKILL6T: {
		//重ね掛けの場合があるから増やしておく
		//魔術師　mskill6の効果ターン処理1
		if (mskill6.buffendflag1 == false) {
			if (mskill6.buffturn1 > 1) {
				mskill6.buffturn1 -= 1;
				mskill6.buffendflag1 = true;	//スキルターンがあるならターンを1引いて終了
			}
			else if (mskill6.buffturn1 == 0) {
				mskill6.buffendflag1 = true;	//スキルターンがないならそのまま終了
			}
		}
		//魔術師　mskill6の効果ターン処理2
		if (mskill6.buffendflag2 == false) {
			if (mskill6.buffturn2 > 1) {
				mskill6.buffturn2 -= 1;
				mskill6.buffendflag2 = true;
			}
			else if (mskill6.buffturn2 == 0) {
				mskill6.buffendflag2 = true;
			}
		}
		//魔術師　mskill6の効果ターン処理3
		if (mskill6.buffendflag3 == false) {
			if (mskill6.buffturn3 > 1) {
				mskill6.buffturn3 -= 1;
				mskill6.buffendflag3 = true;
			}
			else if (mskill6.buffturn3 == 0) {
				mskill6.buffendflag3 = true;
			}
		}
		//魔術師　mskill6の効果ターン処理4
		if (mskill6.buffendflag4 == false) {
			if (mskill6.buffturn4 > 1) {
				mskill6.buffturn4 -= 1;
				mskill6.buffendflag4 = true;
			}
			else if (mskill6.buffturn4 == 0) {
				mskill6.buffendflag4 = true;
			}
		}
		//効果ターンが0になったらステータスを戻す
		//処理1
		if (mskill6.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= mskill6.attackeratkbuff1;//上げた分だけ引く
				attacker.def -= mskill6.attackerdefbuff1;//上げた分だけ引く
				shield.atk -= mskill6.shieldatkbuff1;	//上げた分だけ引く
				shield.def -= mskill6.shielddefbuff1;	//上げた分だけ引く
				magic.atk -= mskill6.magicatkbuff1;		//上げた分だけ引く
				magic.def -= mskill6.magicdefbuff1;		//上げた分だけ引く
				healer.atk -= mskill6.healeratkbuff1;	//上げた分だけ引く
				healer.def -= mskill6.healerdefbuff1;	//上げた分だけ引く
				mskill6.attackeratkbuff1 = 0;			//バフの効果を初期値に戻す
				mskill6.attackerdefbuff1 = 0;			//バフの効果を初期値に戻す
				mskill6.shieldatkbuff1 = 0;				//バフの効果を初期値に戻す
				mskill6.shielddefbuff1 = 0;				//バフの効果を初期値に戻す
				mskill6.magicatkbuff1 = 0;				//バフの効果を初期値に戻す
				mskill6.magicdefbuff1 = 0;				//バフの効果を初期値に戻す
				mskill6.healeratkbuff1 = 0;				//バフの効果を初期値に戻す
				mskill6.healerdefbuff1 = 0;				//バフの効果を初期値に戻す
			}
		}
		//処理2
		if (mskill6.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= mskill6.attackeratkbuff2;//上げた分だけ引く
				attacker.def -= mskill6.attackerdefbuff2;//上げた分だけ引く
				shield.atk -= mskill6.shieldatkbuff2;	//上げた分だけ引く
				shield.def -= mskill6.shielddefbuff2;	//上げた分だけ引く
				magic.atk -= mskill6.magicatkbuff2;		//上げた分だけ引く
				magic.def -= mskill6.magicdefbuff2;		//上げた分だけ引く
				healer.atk -= mskill6.healeratkbuff2;	//上げた分だけ引く
				healer.def -= mskill6.healerdefbuff2;	//上げた分だけ引く
				mskill6.attackeratkbuff2 = 0;			//バフの効果を初期値に戻す
				mskill6.attackerdefbuff2 = 0;			//バフの効果を初期値に戻す
				mskill6.shieldatkbuff2 = 0;				//バフの効果を初期値に戻す
				mskill6.shielddefbuff2 = 0;				//バフの効果を初期値に戻す
				mskill6.magicatkbuff2 = 0;				//バフの効果を初期値に戻す
				mskill6.magicdefbuff2 = 0;				//バフの効果を初期値に戻す
				mskill6.healeratkbuff2 = 0;				//バフの効果を初期値に戻す
				mskill6.healerdefbuff2 = 0;				//バフの効果を初期値に戻す
			}
		}
		//処理3
		if (mskill6.buffturn3 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= mskill6.attackeratkbuff3;//上げた分だけ引く
				attacker.def -= mskill6.attackerdefbuff3;//上げた分だけ引く
				shield.atk -= mskill6.shieldatkbuff3;	//上げた分だけ引く
				shield.def -= mskill6.shielddefbuff3;	//上げた分だけ引く
				magic.atk -= mskill6.magicatkbuff3;		//上げた分だけ引く
				magic.def -= mskill6.magicdefbuff3;		//上げた分だけ引く
				healer.atk -= mskill6.healeratkbuff3;	//上げた分だけ引く
				healer.def -= mskill6.healerdefbuff3;	//上げた分だけ引く
				mskill6.attackeratkbuff3 = 0;			//バフの効果を初期値に戻す
				mskill6.attackerdefbuff3 = 0;			//バフの効果を初期値に戻す
				mskill6.shieldatkbuff3 = 0;				//バフの効果を初期値に戻す
				mskill6.shielddefbuff3 = 0;				//バフの効果を初期値に戻す
				mskill6.magicatkbuff3 = 0;				//バフの効果を初期値に戻す
				mskill6.magicdefbuff3 = 0;				//バフの効果を初期値に戻す
				mskill6.healeratkbuff3 = 0;				//バフの効果を初期値に戻す
				mskill6.healerdefbuff3 = 0;				//バフの効果を初期値に戻す
			}
		}
		//処理4
		if (mskill6.buffturn4 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				attacker.atk -= mskill6.attackeratkbuff4;//上げた分だけ引く
				attacker.def -= mskill6.attackerdefbuff4;//上げた分だけ引く
				shield.atk -= mskill6.shieldatkbuff4;	//上げた分だけ引く
				shield.def -= mskill6.shielddefbuff4;	//上げた分だけ引く
				magic.atk -= mskill6.magicatkbuff4;		//上げた分だけ引く
				magic.def -= mskill6.magicdefbuff4;		//上げた分だけ引く
				healer.atk -= mskill6.healeratkbuff4;	//上げた分だけ引く
				healer.def -= mskill6.healerdefbuff4;	//上げた分だけ引く
				mskill6.attackeratkbuff4 = 0;			//バフの効果を初期値に戻す
				mskill6.attackerdefbuff4 = 0;			//バフの効果を初期値に戻す
				mskill6.shieldatkbuff4 = 0;				//バフの効果を初期値に戻す
				mskill6.shielddefbuff4 = 0;				//バフの効果を初期値に戻す
				mskill6.magicatkbuff4 = 0;				//バフの効果を初期値に戻す
				mskill6.magicdefbuff4 = 0;				//バフの効果を初期値に戻す
				mskill6.healeratkbuff4 = 0;				//バフの効果を初期値に戻す
				mskill6.healerdefbuff4 = 0;				//バフの効果を初期値に戻す
			}
		}

		//初期化
		auto mskill6buffend = CCLabelTTF::create("全員の攻撃力が戻った", "HGRSGU.TTC", fontsizeL);
		mskill6buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		auto mskill6buffend2 = CCLabelTTF::create("全員の防御力が戻った", "HGRSGU.TTC", fontsizeL);
		mskill6buffend2->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//表記して終了
		if (battleturn > 1) {
			if (mskill6.buffturn1 == 1) {
				if (mskill6.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill6buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//表記を消す
						this->addChild(mskill6buffend2, backdepth, buffend2S);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame220) {
						this->removeChildByTag(buffend2S);	//表記を消す
						gameflame = 0;						//初期化する
						mskill6.buffturn1 = 0;				//初期化する
						mskill6.buffendflag1 = true;		//終わった
					}
				}
			}
			if (mskill6.buffturn2 == 1) {
				if (mskill6.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill6buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//表記を消す
						this->addChild(mskill6buffend2, backdepth, buffend2S);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame220) {
						this->removeChildByTag(buffend2S);	//表記を消す
						gameflame = 0;						//初期化する
						mskill6.buffturn2 = 0;				//初期化する
						mskill6.buffendflag2 = true;		//終わった
					}
				}
			}
			if (mskill6.buffturn3 == 1) {
				if (mskill6.buffendflag3 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill6buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//表記を消す
						this->addChild(mskill6buffend2, backdepth, buffend2S);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame220) {
						this->removeChildByTag(buffend2S);	//表記を消す
						gameflame = 0;						//初期化する
						mskill6.buffturn3 = 0;				//初期化する
						mskill6.buffendflag3 = true;		//終わった
					}
				}
			}
			if (mskill6.buffturn4 == 1) {
				if (mskill6.buffendflag4 == false) {
					if (gameflame == flame80) {
						this->addChild(mskill6buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						this->removeChildByTag(buffendS);						//表記を消す
						this->addChild(mskill6buffend2, backdepth, buffend2S);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame220) {
						this->removeChildByTag(buffend2S);	//表記を消す
						mskill6.buffturn4 = 0;				//初期化する
						mskill6.buffendflag4 = true;		//終わった
					}
				}
			}
		}
		//魔術師のスキル6の処理が全部終了したら終わり
		if (mskill6.buffendflag1 == true && mskill6.buffendflag2 == true
			&& mskill6.buffendflag3 == true&& mskill6.buffendflag4 == true) {
			bufft = HSKILL2T;
			mskill6allworkendflag = true;				//スキル７の処理は全部終わった
			mskill6.buffendflag1 = false;				//初期化
			mskill6.buffendflag2 = false;				//初期化
			mskill6.buffendflag3 = false;				//初期化
			mskill6.buffendflag4 = false;				//初期化
			gameflame = 0;								//時間を0に
		}
		break;
	}
//聖職者 hskill2(敵の攻撃力を中ダウン)
	case BossScene::HSKILL2T: {
		//重ね掛けの場合があるから増やしておく
		//聖職者　HSKILL2の効果ターン処理1
		if (hskill2.buffendflag1 == false) {
			if (hskill2.buffturn1 > 1) {
				hskill2.buffturn1 -= 1;
				hskill2.buffendflag1 = true;	//スキルターンがあるならターンを1引いて終了
			}
			else if (hskill2.buffturn1 == 0) {
				hskill2.buffendflag1 = true;	//スキルターンがないならそのまま終了
			}
		}
		//聖職者　hskill2の効果ターン処理2
		if (hskill2.buffendflag2 == false) {
			if (hskill2.buffturn2 > 1) {
				hskill2.buffturn2 -= 1;
				hskill2.buffendflag2 = true;
			}
			else if (hskill2.buffturn2 == 0) {
				hskill2.buffendflag2 = true;
			}
		}
		//聖職者　hskill2の効果ターン処理3
		if (hskill2.buffendflag3 == false) {
			if (hskill2.buffturn3 > 1) {
				hskill2.buffturn3 -= 1;
				hskill2.buffendflag3 = true;
			}
			else if (hskill2.buffturn3 == 0) {
				hskill2.buffendflag3 = true;
			}
		}
		//聖職者　hskill2の効果ターン処理4
		if (hskill2.buffendflag4 == false) {
			if (hskill2.buffturn4 > 1) {
				hskill2.buffturn4 -= 1;
				hskill2.buffendflag4 = true;
			}
			else if (hskill2.buffturn4 == 0) {
				hskill2.buffendflag4 = true;
			}
		}
		//効果ターンが0になったらステータスを戻す
		//処理1
		if (hskill2.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.atk -= hskill2.buffupefect1;		//下げた分だけ足す
				hskill2.buffupefect1 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理2
		if (hskill2.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.atk -= hskill2.buffupefect2;		//下げた分だけ足す
				hskill2.buffupefect2 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理3
		if (hskill2.buffturn3 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.atk -= hskill2.buffupefect3;		//下げた分だけ足す
				hskill2.buffupefect3 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理4
		if (hskill2.buffturn4 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.atk -= hskill2.buffupefect4;		//下げた分だけ足す
				hskill2.buffupefect4 = 0;					//バフの効果を初期値に戻す
			}
		}

		//初期化
		auto hskill2buffend = CCLabelTTF::create("ヴァルキュリーの攻撃力が戻った", "HGRSGU.TTC", fontsizeL);
		hskill2buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//表記して終了
		if (battleturn > 1) {
			if (hskill2.buffturn1 == 1) {
				if (hskill2.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(hskill2buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						hskill2.buffturn1 = 0;				//初期化する
						hskill2.buffendflag1 = true;		//終わった
					}
				}
			}
			if (hskill2.buffturn2 == 1) {
				if (hskill2.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(hskill2buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						hskill2.buffturn2 = 0;				//初期化する
						hskill2.buffendflag2 = true;		//終わった
					}
				}
			}
			if (hskill2.buffturn3 == 1) {
				if (hskill2.buffendflag3 == false) {
					if (gameflame == flame80) {
						this->addChild(hskill2buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						hskill2.buffturn3 = 0;				//初期化する
						hskill2.buffendflag3 = true;		//終わった
					}
				}
			}
			if (hskill2.buffturn4 == 1) {
				if (hskill2.buffendflag4 == false) {
					if (gameflame == flame80) {
						this->addChild(hskill2buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						hskill2.buffturn4 = 0;				//初期化する
						hskill2.buffendflag4 = true;		//終わった
					}
				}
			}
		}

		//聖職者のスキル2の処理が全部終了したら終わり
		if (hskill2.buffendflag1 == true && hskill2.buffendflag2 == true
			&& hskill2.buffendflag3 == true && hskill2.buffendflag4 == true) {
			bufft = HSKILL3T;
			this->removeChildByTag(buffendS);			//表記を消す
			hskill2allworkendflag = true;				//スキル７の処理は全部終わった
			hskill2.buffendflag1 = false;				//初期化
			hskill2.buffendflag2 = false;				//初期化
			hskill2.buffendflag3 = false;				//初期化
			hskill2.buffendflag4 = false;				//初期化
			gameflame = 0;								//時間を0に
		}
		break;
	}
//聖職者 hskill3(敵の防御力を中ダウン)
	case BossScene::HSKILL3T: {
		//重ね掛けの場合があるから増やしておく
		//聖職者　hskill3の効果ターン処理1
		if (hskill3.buffendflag1 == false) {
			if (hskill3.buffturn1 > 1) {
				hskill3.buffturn1 -= 1;
				hskill3.buffendflag1 = true;	//スキルターンがあるならターンを1引いて終了
			}
			else if (hskill3.buffturn1 == 0) {
				hskill3.buffendflag1 = true;	//スキルターンがないならそのまま終了
			}
		}
		//聖職者　hskill3の効果ターン処理2
		if (hskill3.buffendflag2 == false) {
			if (hskill3.buffturn2 > 1) {
				hskill3.buffturn2 -= 1;
				hskill3.buffendflag2 = true;
			}
			else if (hskill3.buffturn2 == 0) {
				hskill3.buffendflag2 = true;
			}
		}
		//聖職者　hskill3の効果ターン処理3
		if (hskill3.buffendflag3 == false) {
			if (hskill3.buffturn3 > 1) {
				hskill3.buffturn3 -= 1;
				hskill3.buffendflag3 = true;
			}
			else if (hskill3.buffturn3 == 0) {
				hskill3.buffendflag3 = true;
			}

		}
		//聖職者　hskill3の効果ターン処理4
		if (hskill3.buffendflag4 == false) {
			if (hskill3.buffturn4 > 1) {
				hskill3.buffturn4 -= 1;
				hskill3.buffendflag4 = true;
			}
			else if (hskill3.buffturn4 == 0) {
				hskill3.buffendflag4 = true;
			}
		}

		//効果ターンが0になったらステータスを戻す
		//処理1
		if (hskill3.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.def -= hskill3.buffupefect1;		//下げた分だけ足す
				hskill3.buffupefect1 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理2
		if (hskill3.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.def -= hskill3.buffupefect2;		//下げた分だけ足す
				hskill3.buffupefect2 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理3
		if (hskill3.buffturn3 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.def -= hskill3.buffupefect3;		//下げた分だけ足す
				hskill3.buffupefect3 = 0;					//バフの効果を初期値に戻す
			}
		}
		//処理4
		if (hskill3.buffturn4 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				valkyrie.def -= hskill3.buffupefect4;		//下げた分だけ足す
				hskill3.buffupefect4 = 0;					//バフの効果を初期値に戻す
			}
		}

		//初期化
		auto hskill3buffend = CCLabelTTF::create("ヴァルキュリーの防御力が戻った", "HGRSGU.TTC", fontsizeL);
		hskill3buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//表記して終了
		if (battleturn > 1) {
			if (hskill3.buffturn1 == 1) {
				if (hskill3.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(hskill3buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						hskill3.buffturn1 = 0;				//初期化する
						hskill3.buffendflag1 = true;		//終わった
					}
				}
			}
			if (hskill3.buffturn2 == 1) {
				if (hskill3.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(hskill3buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						hskill3.buffturn2 = 0;				//初期化する
						hskill3.buffendflag2 = true;		//終わった
					}
				}
			}
			if (hskill3.buffturn3 == 1) {
				if (hskill3.buffendflag3 == false) {
					if (gameflame == flame80) {
						this->addChild(hskill3buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						hskill3.buffturn3 = 0;				//初期化する
						hskill3.buffendflag3 = true;		//終わった
					}
				}
			}
			if (hskill3.buffturn4 == 1) {
				if (hskill3.buffendflag4 == false) {
					if (gameflame == flame80) {
						this->addChild(hskill3buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						hskill3.buffturn4 = 0;				//初期化する
						hskill3.buffendflag4 = true;		//終わった
					}
				}
			}
		}

		//聖職者のスキル2の処理が全部終了したら終わり
		if (hskill3.buffendflag1 == true && hskill3.buffendflag2 == true
			&& hskill3.buffendflag3 == true && hskill3.buffendflag4 == true) {
			bufft = BVSKILL3T;
			this->removeChildByTag(buffendS);			//表記を消す
			hskill3allworkendflag = true;				//スキル７の処理は全部終わった
			hskill3.buffendflag1 = false;				//初期化
			hskill3.buffendflag2 = false;				//初期化
			hskill3.buffendflag3 = false;				//初期化
			hskill3.buffendflag4 = false;				//初期化
			gameflame = 0;								//時間を0に
		}
		break;
	}
//ヴァルキュリ－ bvskill3(自身の防御力を大アップ)
	case BossScene::BVSKILL3T: {
		//重ね掛けの場合があるから増やしておく
		//ヴァルキュリ－　bvskill3の効果ターン処理1
		if (bvskill3.buffendflag1 == false) {
			if (bvskill3.buffturn1 > 1) {
				bvskill3.buffturn1 -= 1;
				bvskill3.buffendflag1 = true;	//スキルターンがあるならターンを1引いて終了
			}
			else if (bvskill3.buffturn1 == 0) {
				bvskill3.buffendflag1 = true;	//スキルターンがないならそのまま終了
			}
		}
		//ヴァルキュリ－　bvskill3の効果ターン処理2
		if (bvskill3.buffendflag2 == false) {
			if (bvskill3.buffturn2 > 1) {
				bvskill3.buffturn2 -= 1;
				bvskill3.buffendflag2 = true;
			}
			else if (bvskill3.buffturn2 == 0) {
				bvskill3.buffendflag2 = true;
			}
		}
		//効果ターンが0になったらステータスを戻す
		//処理1
		if (bvskill3.buffturn1 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				magic.def -= bvskill3.buffupefect1;		//上げた分だけ引く
				bvskill3.buffupefect1 = 0;				//バフの効果を初期値に戻す
			}
		}
		//処理2
		if (bvskill3.buffturn2 == 1 && battleturn > 1) {
			if (gameflame == flame15) {
				magic.def -= bvskill3.buffupefect2;		//上げた分だけ引く
				bvskill3.buffupefect2 = 0;				//バフの効果を初期値に戻す
			}
		}

		//初期化
		auto bvskill3buffend = CCLabelTTF::create("ヴァルキュリ－の防御力が戻った", "HGRSGU.TTC", fontsizeL);
		bvskill3buffend->setPosition(rightSize.width / 2, rightSize.height / 1.15f);

		//表記して終了
		if (battleturn > 1) {
			if (bvskill3.buffturn1 == 1) {
				if (bvskill3.buffendflag1 == false) {
					if (gameflame == flame80) {
						this->addChild(bvskill3buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						bvskill3.buffturn1 = 0;				//初期化する
						bvskill3.buffendflag1 = true;		//終わった
					}
				}
			}
			if (bvskill3.buffturn2 == 1) {
				if (bvskill3.buffendflag2 == false) {
					if (gameflame == flame80) {
						this->addChild(bvskill3buffend, backdepth, buffendS);	//バフの効果が切れたことを表記する
					}
					if (gameflame == flame150) {
						bvskill3.buffturn2 = 0;				//初期化する
						bvskill3.buffendflag2 = true;		//終わった
					}
				}
			}
		}
		//ヴァルキュリ－のスキル2の処理が全部終了したら終わり
		if (bvskill3.buffendflag1 == true && bvskill3.buffendflag2 == true) {
			this->removeChildByTag(buffendS);			//表記を消す
			bvskill3allworkendflag = true;				//スキル７の処理は全部終わった
			bvskill3.buffendflag1 = false;				//初期化
			bvskill3.buffendflag2 = false;				//初期化
			gameflame = 0;								//時間を0に
		}
		//全部終わったらコマンド選択へ
		if (bvskill3allworkendflag == true) {
			allworkendflag = true;
			askill2allworkendflag = false;				//初期化
			askill4allworkendflag = false;				//初期化
			askill7allworkendflag = false;				//初期化
			askill8allworkendflag = false;				//初期化
			mskill2allworkendflag = false;				//初期化
			mskill3allworkendflag = false;				//初期化
			hskill2allworkendflag = false;				//初期化
			hskill3allworkendflag = false;				//初期化
			bvskill3allworkendflag = false;				//初期化
		}
		break;
	}
	default: {
		break;
	}
	}
}

// 最初に出ている画像
void BossScene::BossBackGroudn()
{
	// 画面サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	//rightSize = Director::getInstance()->getVisibleSize();
	rightSize = CCDirector::sharedDirector()->getWinSize();
	//画像のポイントを再設定
	CCPoint ancharpoint = ccp(0.0f, 0.0f);		//左寄せ
	CCPoint anancharpoint = ccp(1.0f, 0.0f);	//右寄せ
//背景
	back = CCSprite::create("BackImage/ST_Boss.png");							//背景の画像指定
	back->setPosition(ccp(rightSize.width / 2, rightSize.height / 2));			// 表示座標指定
	this->addChild(back, backdepth);											//追加
//テロップ
	auto Telop = CCSprite::create("UI/UI_Terop.png");
	Telop->setPosition(rightSize.width / 2, rightSize.height / 1.15f);
	Telop->setScaleX(1.5f);
	this->addChild(Telop, backdepth);
//ボス
	// ボスの表示
	Boss = CCSprite::create("enemy/EM_Valkyrie.png");							// 画像指定
	Boss->setPosition(ccp(rightSize.width / 2, rightSize.height / 1.7f));		// 表示座標指定
	this->addChild(Boss, backdepth);											// 追加
	//BOSSHPバー
	HPboss = CCSprite::create("UI/Status/UI_Status_EMLife.png");
	HPboss->setPosition(ccp(rightSize.width / 2 - HPboss->getContentSize().width / 2,
		rightSize.height / 1.4f + HPboss->getContentSize().height / 2));
	HPboss->setAnchorPoint(ancharpoint);
	HPbar = HPboss->getTextureRect().origin;
	bosshpgaugewidth = HPboss->getContentSize().width;
	this->addChild(HPboss, middledepth);
	//うしろの黒いバー
	auto HPLboss = CCSprite::create("UI/Status/UI_Status_EMLost.png");
	HPLboss->setPosition(ccp(rightSize.width / 2 - HPboss->getContentSize().width / 2,
		rightSize.height / 1.4f + HPboss->getContentSize().height / 2));
	HPLboss->setAnchorPoint(ancharpoint);
	bosshpgaugewidth = HPLboss->getContentSize().width;
	this->addChild(HPLboss, backdepth);
//剣士のステータスバー
	//ステータスのプレート(一番後ろのやつ)
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
	//HPバー
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
	//MANAバー
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
	//剣士HP表記
	//数値が変わる部分
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
	attackerhpal->setColor(ccc3(150,255,255));			//水色
	attackerhpal->setAnchorPoint(anancharpoint);
	this->addChild(attackerhpal, prevdepth);
	//HPの最大値
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
	//剣士MANA表記
	//数値が変わる部分
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
	attackermnal->setColor(ccc3(192, 136, 255));			//紫
	attackermnal->setAnchorPoint(anancharpoint);
	this->addChild(attackermnal, prevdepth);
	//MPの最大値
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
//騎士のステータスバー
	//ステータスのプレート(一番後ろのやつ)
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
	//HPバー
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
	//MANAバー
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
	//騎士HP表記
	//数値が変わる部分
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
	shieldhpal->setColor(ccc3(150, 255, 255));			//水色
	shieldhpal->setAnchorPoint(anancharpoint);
	this->addChild(shieldhpal, prevdepth);
	//HPの最大値
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
	//騎士MANA表記
	//数値が変わる部分
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
	shieldmnal->setColor(ccc3(192, 136, 255));			//紫
	shieldmnal->setAnchorPoint(anancharpoint);
	this->addChild(shieldmnal, prevdepth);
	//MPの最大値
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
//魔術師のステータスバー
	//ステータスプレート(一番後ろのやつ)
	PLmagic = CCSprite::create("UI/Status/UI_Status_Magic.png");					//画像指定
	if (pl1frame.choicejob == MAGIC) {
		PLmagic->setPosition(rightSize.width / 4.1f, rightSize.height / 5);
	}
	if (pl2frame.choicejob == MAGIC) {
		PLmagic->setPosition(rightSize.width / 2, rightSize.height / 5);
	}
	if (pl3frame.choicejob == MAGIC) {
		PLmagic->setPosition(rightSize.width / 1.32f, rightSize.height / 5);
	}
	PLmagic->setScaleX(0.6f);														//大きさ変更
	PLmagic->setScaleY(0.8f);
	this->addChild(PLmagic, backdepth);											//追加
	//HPバー																	//HPバー
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
	//MANAバー
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
	//魔術師HP表記
	//数値が変わる部分
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
	//HPの最大値
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
	//魔術師MANA表記
	//数値が変わる部分
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
	//MPの最大値
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
//聖職者のステータスバー
	////ステータスのプレート(一番後ろのやつ)
	PLhealer = CCSprite::create("UI/Status/UI_Status_Healer.png");					//画像指定
	if (pl1frame.choicejob == HEALER) {
		PLhealer->setPosition(rightSize.width / 4.1f, rightSize.height / 5);
	}
	if (pl2frame.choicejob == HEALER) {
		PLhealer->setPosition(rightSize.width / 2, rightSize.height / 5);
	}
	if (pl3frame.choicejob == HEALER) {
		PLhealer->setPosition(rightSize.width / 1.32f, rightSize.height / 5);
	}
	PLhealer->setScaleX(0.6f);														//大きさ変更
	PLhealer->setScaleY(0.8f);
	this->addChild(PLhealer, backdepth);											//追加
																					//HPバー
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
	//MANAバー
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
	//聖職者HP表記
	//数値が変わる部分
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
	//HPの最大値
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
	//聖職者MANA表記
	//数値が変わる部分
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
	//MPの最大値
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

// 画面遷移
void BossScene::pushStart(Ref * pSender)
{
	CCLOG("Pushボタン");

	// 遷移策の画面をｲﾝｽﾀﾝｽ
	Scene *pScene = GameClear::createScene();							
	// 0.6秒かけて次画面に遷移(時間,遷移先,色(オプション))
	TransitionFade *transition = TransitionFade::create(0.6f, pScene);
	// 遷移実行 アニメーション
	Director::getInstance()->replaceScene(transition);
}

//ボタンを押したとき
bool BossScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {
	return true;
}

//ボタンを押して離したとき
void BossScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
	if (battle == CHOICE) {
		//問題①
		AttackButton1->setVisible(true);
		SkillButton1->setVisible(true);
	}
}

void BossScene::onTouchMove(cocos2d::Touch* touch, cocos2d::Event* event) {

}

void BossScene::onTouchCansell(cocos2d::Touch* touch, cocos2d::Event* event) {
	onTouchEnded(touch, event);
}