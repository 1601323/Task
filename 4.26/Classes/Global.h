#ifndef __Screen__Global__
#define __Screen__Global__

#include "cocos2d.h"
#include <Vector>

enum class CharaName
{
	CHARA_ATTACKER,		// ���j
	CHARA_SHIELD,		// ��j
	CHARA_MAGIC,		// �c�C��
	CHARA_GEALER,		// �P���~�~
};

class Global :public cocos2d::Layer
{
public:
	virtual bool init();
	// �L�������i�[[�ǂݎ��p]
//	const std::vector<CharaName>& GetCharaData();
private:
	// �ۑ�����p�̃f�[�^
//	static std::vector<CharaName>& CharaData;
};

#endif 