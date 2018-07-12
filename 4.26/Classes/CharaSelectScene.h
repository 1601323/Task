#ifndef __Screen__CharaSelectScene__
#define __Screen__CharaSelectScene__
#include "cocos2d.h"
#include <Vector>
#include "Global.h"

USING_NS_CC;

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
	void backStart(Ref *pSender);
	// 選択されたキャラ情報格納
	static const std::vector<CharaName>& GetCharaData();


private:
	Node* Top;
	// キャラ情報
	Sprite *_PL_Attacker;			// ｱﾀｯｶｰ(小男)
	Sprite *_PL_Shield;				// 守備(大男)
	Sprite *_PL_Magic;				// 魔法使い(ツイン)
	Sprite *_PL_Healer;				// 回復(ｹﾓﾐﾐ)
	// 当たり判定用
	Vec2 _touchPos;					// 現在の座標
	Rect _pl_rect;					// プレイヤーのRect
	Rect _box_rect;					// チーム編成用
	Rect _ok_rect;					// 
	Sprite *_pl_square;				// プレイヤーのスプライト
	Sprite *_teamBox;				// チーム編成用
	Sprite *_okButton;

	void Update(float delta);		// アップデート
	void CharaDraw();				// キャラ表示
	void CharaText();				// きゃら説明文
	void TeamBoxDraw();				// 表示	
	void CharaSelectBackGroudn();	// 背景
	void ObjHit();					// 当たり判定用
	void Arrange();					// アレンジ	
	void SwipeRotation();			// スワイプに合わせて回転
					
	// touchイベント
	bool TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);	// 押した瞬間
	void TouchMove(cocos2d::Touch* touch, cocos2d::Event* event);	// スワイプ中
	void TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);	// 離した瞬間

	//// 保存する用のデータ
	static std::vector<CharaName> CharaData;
	// click判定
	EventListenerTouchOneByOne *_listener = EventListenerTouchOneByOne::create();

	// きれいに並べなおしておいてね
	CCSprite *_Box;
	unsigned int _clickCnt = 0;	// クリック回数を保存

	Sprite *_Pl_BOX;
	SpriteBatchNode *_batchNode;

	void CharaSeveData();
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

/*
	// 生成個数
	const unsigned int minCnt = 8;		// 最小生成量
	const unsigned int maxCnt = 20;		// 最大生成量
										// 実行時間	
	float minTime = 0.2f;
	float maxTime = 0.35;
	// 飛び跳ねる高さ
	float minHeight = 12.0f;
	float maxHeight = 22.0f;
	// 広がる幅
	float minX = -18.0f;
	float maxX = 18.0;
	// 広がる高さ
	float minY = -14.0f;
	float maxY = 0;
	//Sprite *effect;

// 指定した速度で開始
	void runEffect(Sprite *effect);
	// アニメーション実行
	void setStart(const float min,const float max);
	// 飛び跳ねる高さ
	void setJumpHeight(const float min,const float max);
	// 広がる範囲X
	void setWidth(const float min,const float max);
	// 広がる範囲Y
	void setHeight(const float min,const float max);
	// 最後に自分削除
	void updateSelf();

void CharaSelectScene::runEffect(Sprite *effect)
{
int max = random(this->minTime,this->maxTime);
for (int i = 0; i < maxTime; i++)
{
effect = Sprite::create("effect_cure01_0000.png"); //"effect_cure01_0000.png"
float baseTime = random(minTime, maxTime);
float baseHeight = random(minHeight, maxHeight);
float baseVecX = random(minX, maxX);
float baseVecY = random(minY, maxY);

// だんだんバウンド小さく
// 時間、幅(X,Y)、高さ、要素数
auto jump1 = JumpBy::create(baseTime,Vec2(baseVecX, baseVecY), baseHeight,1);
auto jump2 = JumpBy::create(baseTime*0.8, Vec2(baseVecX/2, baseVecY/2), baseHeight/2, 1);
auto jump3 = JumpBy::create(baseTime*0.6, Vec2(baseVecX/4, baseVecY/4), baseHeight/4, 1);

auto dele = DelayTime::create(1.0f);
auto lastFunc = CallFuncN::create([this](Node* node)
{
node->removeFromParentAndCleanup(true);
this->updateSelf();
});

effect->runAction(Sequence::create(jump1, jump2, jump3, dele,nullptr));

this->updateSelf();
}
}
//
void CharaSelectScene::updateSelf()
{
this->removeFromParentAndCleanup(true);
}
// アニメーション実行
void CharaSelectScene::setStart(float min, const float max)
{
this->minTime = min;
this->maxTime = max;
}
// 飛び跳ねる高さ
void CharaSelectScene::setJumpHeight(float min, const float max)
{
this->minHeight = min;
this->maxHeight = max;
}
// 広がり方X
void CharaSelectScene::setWidth(float min, const float max)
{
this->minX = min;
this->maxX = max;
}
// 広がり方Y
void CharaSelectScene::setHeight(float min, const float max)
{
this->minY = min;
this->maxY = max;
}
*/