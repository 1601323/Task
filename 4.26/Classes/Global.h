#ifndef __Screen__Global__
#define __Screen__Global__

#include "cocos2d.h"
#include <Vector>

enum class CharaName
{
	CHARA_ATTACKER,		
	CHARA_SHIELD,		
	CHARA_MAGIC,		
	CHARA_HEALER,		
};

class Global :public cocos2d::Layer
{
public:
	virtual bool init();

private:

};

#endif 