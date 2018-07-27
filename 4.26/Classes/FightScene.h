#ifndef __Screen__FightScene__
#define __Screen__FightScene__

#include "cocos2d.h"

USING_NS_CC;


class FightScene :public cocos2d::Layer
{
private:

	Sprite* _enemySprite;			//敵の画像
	Vec2 _touchLocation;			//タッチ座標
	Rect _enemySpriteRect;			//敵の画像のRect
	Rect _enemyHpRect;				//敵のHpバーのRect
	Rect _backHpRect;				//敵のHpバーのRect
	Sprite* _backGage;
	Sprite* _blueGage;
	

	bool _enemyDeathFlg;			//敵が死んだかどうか
	int _enemyHpNow;				//敵の残りHp
	int _giveDamage;				//敵に与えるダメージ数
	int _damageDispTime;			//与えたダメージ数値の表示時間
	bool _damageDispFlag;			//与えたダメージ数値が表示するかどうか
	unsigned int _battleCounter;	//今のバトル数数
	bool _moveFlag;					//移動中かどうか
	int _hitCount;
	unsigned int _nextBattleTimer;	//次のバトルが始まるまでのタイマー
	bool _enemyDispFlag;			//敵の表示フラグ
	unsigned int _exp;				//経験値用
	unsigned int _expDispTime;
	bool ExpDispFlag;

	//敵の画像切り替え
	void EnemySelector();

	// タッチされた瞬間に呼び出される
	virtual bool TouchBegan(Touch* touch, Event* event);
	// スワイプ中に呼び出される
	virtual void TouchMove(Touch* touch, Event* event);
	// 画面から指が離された瞬間に呼び出される
	virtual void TouchEnd(Touch* touch, Event* event);

	//毎フレーム呼び出されるアップデート
	void update(float delta);

	//画像のRectを取得
	Rect GetSpriteRect(Sprite* sprite, Rect rect);
	//画像を振動させるんだ！！
	void SpriteTremble(Sprite* sprite);
	//敵のHpゲージ
	void EnemyHpGage();
	//敵のHpゲージのフェードイン処理
	void EnemyHpGageFadeIn();
	//敵のHpゲージのフェードアウト処理
	void EnemyHpGageFadeOut();
	//敵のフェードイン処理
	void EnemyFadeIn();
	//敵のHpゲージ情報を更新
	void ReloadEnemyHp();
	//与えたダメージ数値を表示する
	void GiveDamageDisplay(unsigned int giveDamage);
	//画像がが上下にゆらゆらと揺れる
	void SpriteSwayUpDown(Sprite* sprite);

	//ボス戦へ行くボタンを表示する
	void DisplayBossButton();
	//「はい」と「いいえ」ボタンを表示する
	void DisplayYesNoButton();
	//「はい」と「いいえ」ボタンを非表示にする
	void NonDisplayYesNoButton();
	//ボス戦へ行く関係のボタンのドロー
	void DrawChangeBossSceneMenu();

	//ボス戦へ向かうボタン
	Menu* _bossButton;
	//「はい」ボタン
	Menu* _yesButton;
	//「いいえ」ボタン
	Menu* _noButton;


	float _yesNoButtonUseTimer = 0.5f;		//はいといいえボタンが使えるようになるまでのタイマー	
	bool _yesNoButtonUseFlag = false;		//はいといいえボタンが使えるかどうか
	bool _bossButtonPushFlag = false;		//ボスボタンが押されたかどうか


	Label *damageLabel;

	void BattleAnnounce();		//

	void HitDisplay();				//敵に攻撃した時の「1HIT!!」とか「2HIT!!」とかのアレ
	Label *hitLabel;

	//アナウンス関係
	Sprite* announceBackSprite;
	void ExpGetAnnounce();
	Label *expLabel;
	Label *announceTelop;


	// @param label ラベル
	// @param largeTime 何秒かけて拡大するか
	// @param multiple	何倍に拡大するか
	// @param backTime	何秒かけて縮小するか
	// @param backMultiple	何倍に縮小か
	// @param delay		何秒間表示させるか
	// @param fadeOutTime	フェードアウトは何秒かけて行うか
	void ScalingAndFadeout(Label* label, float largeTime, float multiple, float backTime, float backMultiple, float delay, float fadeOutTime);

	//テキスト表示処理をまとめてやろうと思ったけど、途中めんどくさくなって後回しなう
	void DrawLabel		 (const char *fontFilePath, Vec2 &position, std::string& text, Color3B textCololr, int fontSize);
	void DrawGlowLabel	 (const char *fontFilePath, Vec2 &position, std::string& text, Color3B textCololr, int fontSize, Color4B glowColor);
	void DrawShadowLabel (const char *fontFilePath, Vec2 &position, std::string& text, Color3B textCololr, int fontSize, Color4B shadowColor, Size &offset, int shadowSize);
	void DrawOutlineLabel(const char *fontFilePath, Vec2 &position, std::string& text, Color3B textCololr, int fontSize, Color4B outlineColor, int outlineSize);


	//デバッグ用-------------------
	void Skip();
	Sprite* _skipButtonSprite;
	Rect _skipButtonRect;

public:
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(FightScene);

	void FightBackGroudn();


	FightScene();
	~FightScene();


	// スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
	void ChangeBossScene(Ref *pSender);
	//void ChangeWalkScene(Ref *pSender);

};

enum class BattleNumber : unsigned int {
	Battle1 = 1,
	Battle2,
	Battle3,
	Battle4,
	Battle5,
	Battle6,


};



#endif //Select