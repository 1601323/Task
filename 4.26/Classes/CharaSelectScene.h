#ifndef __Screen__CharaSelectScene__
#define __Screen__CharaSelectScene__
#include "cocos2d.h"
#include <Vector>

USING_NS_CC;

enum class CharaName
{
	CHARA_ATTACKER,		// 小男
	CHARA_SHIELD,		// 大男
	CHARA_MAGIC,		// ツイン
	CHARA_GEALER,		// ケモミミ
};

class CharaSelectScene :public cocos2d::Layer
{
public:
	float angle;
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(CharaSelectScene);
	std::vector<cocos2d::Node *> items;

	// 背景
	void CharaSelectBackGroudn();
	// スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
	void pushStart(Ref *pSender);
	// 選択されたキャラ情報格納
	static const std::vector<CharaName>& GetCharaData();


private:
	Node* Top;
	// キャラ情報
	Sprite* PL_Attacker;	 // ｱﾀｯｶｰ(小男)
	Sprite *PL_Shield;		 // 守備(大男)
	Sprite *PL_Magic;		 // 魔法使い(ツイン)
	Sprite *PL_Healer;		 // 回復(ｹﾓﾐﾐ)
	void update(float delta);// アップデート
	void charaDraw();		 // キャラ表示
	void swipeRotation();	 // スワイプに合わせて回転
	void drawBox();			 // □表示
	void fontsDraw();		 // 文字描画
	void arrange();			 // アレンジ						
	void charaText();		 // きゃら説明文
	void clickCheck();			 // clickされたら呼ばれる
	// 保存する用のデータ
	static std::vector<CharaName> CharaData;
	// click判定
	EventListenerTouchOneByOne *_listener = EventListenerTouchOneByOne::create();
};

#endif // Title