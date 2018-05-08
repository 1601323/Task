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
	void arrange();	// アレンジ
	// 背景
	void CharaSelectBackGroudn();
	// スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
	void pushStart(Ref *pSender);
	// 選択されたキャラ情報格納
	static const std::vector<CharaName>& GetCharaData();

private:
	Node* Top;
	Sprite* PL_Attacker;
	Sprite *PL_Shield;
	Sprite *PL_Magic;
	Sprite *PL_Healer;
	void CharaClick();
	// 保存する用のデータ
	static std::vector<CharaName> CharaData;
	//bool onTouchBegan(Touch *touch, Event *unused_event);
};

#endif // Title