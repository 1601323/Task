#ifndef __Screen__Global__
#define __Screen__Global__

#include "cocos2d.h"
#include <Vector>

enum class CharaName
{
	CHARA_ATTACKER,		// 小男
	CHARA_SHIELD,		// 大男
	CHARA_MAGIC,		// ツイン
	CHARA_HEALER,		// ケモミミ
};

class Global :public cocos2d::Layer
{
public:
	virtual bool init();
	// キャラセレできるようになったらこっちに書き直そうね
	// キャラ情報格納[読み取り用]
//	const std::vector<CharaName>& GetCharaData();
private:
	// 保存する用のデータ
//	static std::vector<CharaName>& CharaData;
};

#endif 