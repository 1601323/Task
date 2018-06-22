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

	// スキル選択
	Sprite *_ChoiceSkill;	// 選択スキル
	//Sprite *_Skill;			// スキル

	void ActSelectDraw();		// 表示
	void Arrange();			// 角度調整
	void SwipeRotation();	// 回転

	EventListenerTouchOneByOne *_listener = EventListenerTouchOneByOne::create();
};

#endif // Title