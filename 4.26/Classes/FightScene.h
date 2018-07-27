#ifndef __Screen__FightScene__
#define __Screen__FightScene__

#include "cocos2d.h"

USING_NS_CC;


class FightScene :public cocos2d::Layer
{
private:

	Sprite* _enemySprite;			//�G�̉摜
	Vec2 _touchLocation;			//�^�b�`���W
	Rect _enemySpriteRect;			//�G�̉摜��Rect
	Rect _enemyHpRect;				//�G��Hp�o�[��Rect
	Rect _backHpRect;				//�G��Hp�o�[��Rect
	Sprite* _backGage;
	Sprite* _blueGage;
	

	bool _enemyDeathFlg;			//�G�����񂾂��ǂ���
	int _enemyHpNow;				//�G�̎c��Hp
	int _giveDamage;				//�G�ɗ^����_���[�W��
	int _damageDispTime;			//�^�����_���[�W���l�̕\������
	bool _damageDispFlag;			//�^�����_���[�W���l���\�����邩�ǂ���
	unsigned int _battleCounter;	//���̃o�g������
	bool _moveFlag;					//�ړ������ǂ���
	int _hitCount;
	unsigned int _nextBattleTimer;	//���̃o�g�����n�܂�܂ł̃^�C�}�[
	bool _enemyDispFlag;			//�G�̕\���t���O
	unsigned int _exp;				//�o���l�p
	unsigned int _expDispTime;
	bool ExpDispFlag;

	//�G�̉摜�؂�ւ�
	void EnemySelector();

	// �^�b�`���ꂽ�u�ԂɌĂяo�����
	virtual bool TouchBegan(Touch* touch, Event* event);
	// �X���C�v���ɌĂяo�����
	virtual void TouchMove(Touch* touch, Event* event);
	// ��ʂ���w�������ꂽ�u�ԂɌĂяo�����
	virtual void TouchEnd(Touch* touch, Event* event);

	//���t���[���Ăяo�����A�b�v�f�[�g
	void update(float delta);

	//�摜��Rect���擾
	Rect GetSpriteRect(Sprite* sprite, Rect rect);
	//�摜��U��������񂾁I�I
	void SpriteTremble(Sprite* sprite);
	//�G��Hp�Q�[�W
	void EnemyHpGage();
	//�G��Hp�Q�[�W�̃t�F�[�h�C������
	void EnemyHpGageFadeIn();
	//�G��Hp�Q�[�W�̃t�F�[�h�A�E�g����
	void EnemyHpGageFadeOut();
	//�G�̃t�F�[�h�C������
	void EnemyFadeIn();
	//�G��Hp�Q�[�W�����X�V
	void ReloadEnemyHp();
	//�^�����_���[�W���l��\������
	void GiveDamageDisplay(unsigned int giveDamage);
	//�摜�����㉺�ɂ����Ɨh���
	void SpriteSwayUpDown(Sprite* sprite);

	//�{�X��֍s���{�^����\������
	void DisplayBossButton();
	//�u�͂��v�Ɓu�������v�{�^����\������
	void DisplayYesNoButton();
	//�u�͂��v�Ɓu�������v�{�^�����\���ɂ���
	void NonDisplayYesNoButton();
	//�{�X��֍s���֌W�̃{�^���̃h���[
	void DrawChangeBossSceneMenu();

	//�{�X��֌������{�^��
	Menu* _bossButton;
	//�u�͂��v�{�^��
	Menu* _yesButton;
	//�u�������v�{�^��
	Menu* _noButton;


	float _yesNoButtonUseTimer = 0.5f;		//�͂��Ƃ������{�^�����g����悤�ɂȂ�܂ł̃^�C�}�[	
	bool _yesNoButtonUseFlag = false;		//�͂��Ƃ������{�^�����g���邩�ǂ���
	bool _bossButtonPushFlag = false;		//�{�X�{�^���������ꂽ���ǂ���


	Label *damageLabel;

	void BattleAnnounce();		//

	void HitDisplay();				//�G�ɍU���������́u1HIT!!�v�Ƃ��u2HIT!!�v�Ƃ��̃A��
	Label *hitLabel;

	//�A�i�E���X�֌W
	Sprite* announceBackSprite;
	void ExpGetAnnounce();
	Label *expLabel;
	Label *announceTelop;


	// @param label ���x��
	// @param largeTime ���b�����Ċg�傷�邩
	// @param multiple	���{�Ɋg�傷�邩
	// @param backTime	���b�����ďk�����邩
	// @param backMultiple	���{�ɏk����
	// @param delay		���b�ԕ\�������邩
	// @param fadeOutTime	�t�F�[�h�A�E�g�͉��b�����čs����
	void ScalingAndFadeout(Label* label, float largeTime, float multiple, float backTime, float backMultiple, float delay, float fadeOutTime);

	//�e�L�X�g�\���������܂Ƃ߂Ă�낤�Ǝv�������ǁA�r���߂�ǂ������Ȃ��Č�񂵂Ȃ�
	void DrawLabel		 (const char *fontFilePath, Vec2 &position, std::string& text, Color3B textCololr, int fontSize);
	void DrawGlowLabel	 (const char *fontFilePath, Vec2 &position, std::string& text, Color3B textCololr, int fontSize, Color4B glowColor);
	void DrawShadowLabel (const char *fontFilePath, Vec2 &position, std::string& text, Color3B textCololr, int fontSize, Color4B shadowColor, Size &offset, int shadowSize);
	void DrawOutlineLabel(const char *fontFilePath, Vec2 &position, std::string& text, Color3B textCololr, int fontSize, Color4B outlineColor, int outlineSize);


	//�f�o�b�O�p-------------------
	void Skip();
	Sprite* _skipButtonSprite;
	Rect _skipButtonRect;

public:
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(FightScene);

	void FightBackGroudn();


	FightScene();
	~FightScene();


	// �X�^�[�g�{�^���������̏����錾 �߂� Object ���@Ref �ɕύX
	void ChangeBossScene(Ref *pSender);
	//void ChangeWalkScene(Ref *pSender);

};

enum class BattleNumber : unsigned int {
	Battle1 = 1,
	Battle2,
	Battle3,
	Battle4,
	Battle5,
	Battle6,


};



#endif //Select