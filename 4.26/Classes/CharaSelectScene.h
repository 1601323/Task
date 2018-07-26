#ifndef __Screen__CharaSelectScene__
#define __Screen__CharaSelectScene__
#include "cocos2d.h"
#include <Vector>
#include <map>
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
	unsigned int _clickCnt = 0;		// クリック回数を保存
	bool _changeFlag;				// キャラクター切り替え用Flag
	Node* Top;
	Sprite *_s_fontBoard;			// 説明文の背景板
	SpriteBatchNode *_batchNode;
	// キャラ情報
	Sprite *_s_Attacker;			// ｱﾀｯｶｰ(小男)
	Sprite *_s_Shield;				// 守備(大男)
	Sprite *_s_Magic;				// 魔法使い(ツイン)
	Sprite *_s_Healer;				// 回復(ｹﾓﾐﾐ)

	Sprite *_s_teamAttacker;
	Sprite *_s_teamShied ;
	Sprite *_s_teamMagic ;
	Sprite *_s_teamHealer ;

	// 当たり判定用
	Vec2 _touchPos;					// 現在の座標
	Rect _r_pl_rect;				// プレイヤーのRect
	Rect _r_box_rect;				// チーム編成用
	Rect _r_ok_rect;				// 
	Sprite *_s_pl_square;			// プレイヤーのスプライト
	Sprite *_s_teamBox;				// チーム編成用
	Sprite *_s_okButton;
	CCSprite *_ccp_Box;				// チーム用のSprite

	void Update(float delta);		// アップデート
	void CharaDraw();				// キャラ表示
	void CharaText();				// キャラ説明文
	void TeamBoxDraw();				// 表示	
	void CharaSelectBackGroudn();	// 背景
	void ObjHit();					// 当たり判定用
	void Arrange();					// アレンジ	
	void SwipeRotation();			// スワイプに合わせて回転
	void AddTeam();					// チーム編成用
	void CharaSeveData();
	void Sound();					// 音楽用
	void TeamDraw();				// チームメンバー表示
					
	// touchイベント
	bool TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);	// 押した瞬間
	void TouchMove(cocos2d::Touch* touch, cocos2d::Event* event);	// スワイプ中
	void TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);	// 離した瞬間

	//// 保存する用のデータ
	static std::vector<CharaName> CharaData;
	static std::map<CharaName,Sprite *> teamData;
	// click判定
	EventListenerTouchOneByOne *_listener = EventListenerTouchOneByOne::create();

	// きれいに並べなおしておいてね
	// テスト用
	void Test();
	Sprite *_test;
};

#endif // Title