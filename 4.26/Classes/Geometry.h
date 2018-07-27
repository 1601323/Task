#include "cocos2d.h"


//エトセトラ-----------------------------------------------------------------------------------------------------
const unsigned int INIT_GIVE_DAMAGE = 50;			//敵へ与えるダメージの初期値
const unsigned int DAMAGE_DISPLAY_DURATION = 100;	//与えたダメージの数値の表示時間
const unsigned int EXP = 10;						//獲得経験値
const unsigned int NEXT_BATTLE_TIMER = 180;			//すべての雑魚敵が死んで次のバトルが始まるまでのタイマー
const unsigned int BATTLE_MAX = 6;					//最大バトル数
const unsigned int GIVE_ENEMY_DAMAGE_FONT_SIZE = 40;//敵へのダメージ表記用ラベルのフォントサイズ
const unsigned int EXP_LABEL_FONT_SIZE = 70;		//EXPラベルのフォントサイズ
const float CHANGE_FIGHT_SCENE_TO_BOSS_SCENE_DURATION = 0.6f;	//何秒かけてFightSceneからBossSceneへ遷移するか

const float TOUCH_SPRITE_HITBOX_OFFSET = 50.f;

//敵-------------------------------------------------------------------------------------------------------------
const unsigned int ENEMY_HP_MAX = 300;				//敵のHPの上限値
const float ENEMY_DISPLAY_UNTIL_TIME = 1.5f;		//次のバトルに遷移して敵が出現するまでの時間
const float ENEMY_FADEIN_DURATION = 0.5f;			//敵が何秒かけてフェードインして現れるか

//敵のHpゲージ---------------------------------------------------------------------------------------------------
const float BACK_GAGE_DISPLAY_INTERVAL_TIME = ENEMY_DISPLAY_UNTIL_TIME + 0.2f;	//バックゲージが表示されるまでの待機時間
const float BLUE_GAGE_DISPLAY_INTERVAL_TIME = ENEMY_DISPLAY_UNTIL_TIME;	//青ゲージが表示されるまでの待機時間

const float BACK_GAGE_FADE_IN_DURATION = 0.3f;		//何秒かけてバックゲージのフェードインを行うか
const float BACK_GAGE_FADE_OUT_DURATION = 0.3f;		//何秒かけてバックゲージのフェードアウトを行うか

const float BLUE_GAGE__FADE_IN_DURATION = 0.5f;		//何秒かけてHpゲージのフェードインを行うか
const float BULE_GAGE_FADE_OUT_DURATION = 0.3f;		//何秒かけてHpゲージのフェードアウトを行うか
/* ※赤ゲージと同じ時間に設定してしまうと、フェードイン中のゲージの色合いが変な感じになるので、
     青ゲージの方が表示されるまでの待機時間が短く設定している*/

//HP関係---------------------------------------------------------------------------------------------------------
const unsigned int HP_GAGE_SIZE_WIDTH = 300;		//HPゲージの横サイズ
const unsigned int HP_GAGE_SIZE_HEIGHT = 10;		//HPゲージの縦サイズ

//バトルラベル(BL)関係-------------------------------------------------------------------------------------------
const unsigned int BATTLE_LABEL_FONT_SIZE = 60;		//フォントサイズ
const float BL_FADE_IN_DURATION = 0.3f;				//何秒かけてバトルラベルのフェードインを行うか
const float BL_FADE_OUT_DURATION = 0.3f;			//何秒かけてバトルラベルのフェードアウトを行うか
///const Vec2 OTHER_BL_POS(400.f, 820.f);　←下の奴をVec2でまとめたかったけど、眠すぎて頭が回らず結局XYそれぞれに分けた。後でやるかも	
const float OTHER_BL_POS_X = 400.f;					//バトル１～５のラベルの位置
const float OTHER_BL_POS_Y = 820.f;
///const Vec2 FINAL_BL_POS(290.f, 820.f);			
const float FINAL_BL_POS_X = 290.f;					//最終バトルラベルの位置
const float FINAL_BL_POS_Y = 820.f;

//バトルナンバーラベル(BNL)関係--------------------------------------------------------------------------------
const unsigned int BNL_FONT_SIZE = 80;				//フォントサイズ
const float BNL_FADE_IN_DURATION = 0.3f;			//何秒かけてラベルのフェードインを行うか
const float BNL_FADE_OUT_DURATION = 0.3f;			//何秒かけてラベルのフェードインを行うか
///const Vec2 OTHER_BNL_POS(570.f, 780.f);	
const float OTHER_BNL_POS_X = 570.f;				//バトル１～５のラベルの位置
const float OTHER_BNL_POS_Y = 780.f;
///const Vec2 FINAL_BNL_POS(510.f, 780.f);			
const float FINAL_BNL_POS_X = 510.f;				//最終バトルのラベルの位置
const float FINAL_BNL_POS_Y = 780.f;

//バトルアナウンスラベル全体（BAL）----------------------------------------------------------------------------
const float BAL_SLIDE_UP_DURATION = 0.3f;			//何秒かけてラベルが上へ移動するか
const float BAL_SLIDE_DOWN_DURATION = 0.3f;			//何秒かけてラベルが下へ移動するか
const float BAL_DISPLAY_TIME = 0.7f;				//表示時間（スライドされる時間を除く）
///const Vec2 BAL_SLIDE_UP_VOLUME(0.f, 20.f);			
const float BAL_SLIDE_UP_VOLUME = 20.f;				//ラベルが上へスライド際の移動量
///const Vec2 BAL_SLIDE_DOWN_VOLUME(0.f, -20.f);		
const float BAL_SLIDE_DOWN_VOLUME = -20.f;			//ラベルが下へスライド際の移動量

//画面上部のアナウンステロップ関係-----------------------------------------------------------------------------
const int ANNOUNCE_TELOP_FONT_SIZE = 30;			//フォントサイズ
const int TEXT_BOX_OPACITY = 180;					//背景のテキストボックスの不透明度

//画像振動関係-------------------------------------------------------------------------------------------------
const float SPRITE_TREMBLE_SPEED = 0.05f;			//画像が振動する際の一回当たりの移動時間
const float SPRITE_DEFLECTION_WIDTH = 30;			//振れ幅

//画像がゆらゆら揺れる奴---------------------------------------------------------------------------------------
const float SPRITE_SWAY_SPEED = 3.f;				//揺れるスピード
const float SPRITE_SWAY_DEFLECTION_WIDTH = 20.f;	//振れ幅

//表示テロップの内容--------------------------------------------------------------------------------------------


//リソースパス-------------------------------------------------------------------------------------------------
// タイトル

// キャラセレクト
const std::string UI_BUTTON_NEXT				 = "UI/Command/UI_Button_Next.png";
const std::string UI_BUTTON_NEXT_PUSH			 = "UI/Command/UI_Button_Next02.png";
const std::string UI_BUTTON_BUCK				 = "UI/Command/UI_Button_Back.png";
const std::string UI_BUTTON_BUCK_PUSH			 = "UI/Command/UI_Button_Back.png";
const std::string UI_PL_CHRA_FLAME				 = "UI/PL_CharFlame01.png";
const std::string UI_FONT_BOARD					 = "UI/Status/UI_Status_Inters.png"; 
const std::string BACK_GRAND_SPRITE_CHRASELECT	 = "BackImage/ST_CharSerect2.png";
const std::string FONT_PL_TEXT					 = "fonts/HGRSGU.TTC";

const std::string PL_ATTACKER					 = "Player/PL_Attacker.png";		//キャラ立ち絵
const std::string PL_SHIELD						 = "Player/PL_Shield.png";
const std::string PL_MAGIC						 = "Player/PL_Magic.png";
const std::string PL_HEALER						 = "Player/PL_Healer.png";
const std::string PL_ATTACKER_FACE				 = "Player/PL_Attacker_face01.png";	//チーム編成用
const std::string PL_SHIELD_FACE				 = "Player/PL_Shield_face01.png";
const std::string PL_MAGIC_FACE					 = "Player/PL_Magic_face01.png";
const std::string PL_HEALER_FACE				 = "Player/PL_Healer_face01.png";
// ファイト
const std::string BACK_GRAND_SPRITE_PATH		 = "BackImage/ST_Colosseum.png";	//道中背景
const std::string DAMAGE_LABEL_FONT_PATH		 = "fonts/SHOWG.TTF";				//ダメージラベルフォント
const std::string HIT_LABEL_FONT_PATH			 = "fonts/SHOWG.TTF";				//ヒットラベルフォント
const std::string BAL_FONT_PATH					 = "fonts/COPRGTB.TTF";				//バトルアナウンスラベルフォント
const std::string EXP_LABEL_FONT_PATH			 = "fonts/SHOWG.TTF";				//EXPラベルフォント
const std::string ANNOUNCE_TELOP_LABEL_FONT_PATH = "fonts/HGRSGU.TTC";

const std::string FIELD_ENEMY_FOLDER_PATH		 = "Enemy/FieldEnemy/"; 

const std::string BOSS_BUTTON_PATH				 = "UI/Fight/boss.png";
const std::string PUSH_BOSS_BUTTON_PATH			 = "UI/Fight/boss_push.png";
const std::string YES_BUTTON_PATH				 = "UI/Fight/yes.png";
const std::string PUSH_YES_BUTTON_PATH			 = "UI/Fight/yes_push.png";
const std::string NO_BUTTON_PATH				 = "UI/Fight/no.png";
const std::string PUSH_NO_BUTTON_PATH			 = "UI/Fight/no_push.png";
// ボス

// BGM
const std::string BGM_BOSS_ODEN					 = "BGM/BGM_Oden_Main.mp3";			//オーディンの戦闘で使用するBGM
const std::string BGM_BOSS_SLEIPNIR				 = "BGM/BGM_Sleipnir_Main.mp3";		//スレイプニルの戦闘で使用するBGM
const std::string BGM_BOSS_TORS					 = "BGM/BGM_Tors_Main.mp3";			//Thorの戦闘で使用するBGM
const std::string BGM_BOSS_VALKYRIE				 = "BGM/BGM_Valkyrie_Main.mp3";		//ヴァルキリーの戦闘で使用するBGM
const std::string BGM_CHRASELECT				 = "BGM/BGM_PartyCreate_Main";		//パーティ編成の時に使うBGM
// SE
