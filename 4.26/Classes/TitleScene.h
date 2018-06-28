#ifndef __Screen__TitleScene__
#define __Screen__TitleScene__

#include "cocos2d.h"

USING_NS_CC;

class TitleScene :public cocos2d::Layer
{
public:
	float angle;
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(TitleScene);
	std::vector<cocos2d::Node *> items;
	void TitleBackGroudn();

	// スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
	void pushStart(Ref *pSender);

private:
	Node* Top;				// 最前にあるものの情報
	// 行動パターン情報
	Sprite *_Attack;		// 攻撃
	Sprite *_Defence;		// 防御
	Sprite *_Item;			// アイテム
	Sprite *_Skill;			// スキル
	// 当たり判定用
	Vec2 _touchPos;			// 現在座標
	Rect _swipeRect;		// スワイプ用の判定範囲
	Sprite *_swipe;
	// スキル選択
	Sprite *_ChoiceSkill;	// 選択スキル
	void ActSelectDraw();	// 表示
	void Arrange();			// 角度調整
	void SwipeRotation();	// 回転
	void ObjHit();			// 当たり判定用
	void RectDraw(const unsigned int x, const unsigned int y, const unsigned int _width, const unsigned int _height, const int posX, const int posY);
	void TouchArrange(Touch* _touch);		// タッチしたところエフェクト

	// touchイベント
	bool TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);	// 押した瞬間
	void TouchMove(cocos2d::Touch* touch, cocos2d::Event* event);	// スワイプ中
	void TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);	// 離した瞬間
	EventListenerTouchOneByOne *_listener = EventListenerTouchOneByOne::create();
};

#endif // Title