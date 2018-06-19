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

	// スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
	void pushStart(Ref *pSender);
	// 選択されたキャラ情報格納
	static const std::vector<CharaName>& GetCharaData();


private:
	Node* Top;
	// キャラ情報
	Sprite* PL_Attacker;			// ｱﾀｯｶｰ(小男)
	Sprite *PL_Shield;				// 守備(大男)
	Sprite *PL_Magic;				// 魔法使い(ツイン)
	Sprite *PL_Healer;				// 回復(ｹﾓﾐﾐ)
	// 当たり判定用
	Vec2 touchPos;					// 現在の座標
	Rect pl_rect;					// プレイヤーのRect
	Rect box_rect;					// チーム編成用
	Sprite *pl_square;				// プレイヤーのスプライト
	Sprite *teamBox;				// チーム編成用

	void update(float delta);		// アップデート
	void charaDraw();				// キャラ表示
	void fontsDraw();				// 文字描画
	void charaText();				// きゃら説明文
	void Draw();					// 表示	
	void CharaSelectBackGroudn();	// 背景
	void testChara();
	void objHit();					// 当たり判定用
	void arrange();					// アレンジ	
	void swipeRotation();			// スワイプに合わせて回転
					
	// touchイベント
	bool TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);	// 押した瞬間
	void TouchMove(cocos2d::Touch* touch, cocos2d::Event* event);	// スワイプ中
	void TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);	// 離した瞬間

	// 保存する用のデータ
	static std::vector<CharaName> CharaData;
	// click判定
	EventListenerTouchOneByOne *_listener = EventListenerTouchOneByOne::create();
	CCSprite *Box;
	CCSprite *Box1;
	unsigned int clickCnt = 0;	// クリック回数を保存

	Sprite *Pl_BOX;

};

#endif // Title

/*
_listener->onTouchBegan = [&](Touch * touch, Event *event)
{
}
listener->onTouchMoved = [&](Touch *touch, Event *event)
{
	this->removeChildByTag(PL_TAG);
};
// 離した
_listener->onTouchEnded = [&](Touch *touch, Event *event)
{
};
this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_listener, this);

*/