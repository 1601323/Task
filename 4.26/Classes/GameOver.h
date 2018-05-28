#ifndef __Screen__GameOver__
#define __Screen__GameOver__

#include "cocos2d.h"

USING_NS_CC;

class GameOver :public cocos2d::Layer
{
public:
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(GameOver);

	void ClearBackGroudn();

	// スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
	void pushStart(Ref *pSender);
private:
	int m_iCount  = 0;
	float m_ctime = 0;
	// 魔法陣表示
	void MagicEffect();
	// 回復
	void RecoveryEffect();
	// 剣
	void SwordEffect();
	float fadeSpeed		    = 0.8f;	// フェード時間
	unsigned int startSpeed = 1;	// 表示開始までの移動速度
	unsigned int imageSize	= 20;	// 画像サイズ
	// 色
	// 破門
	void Ripple();
	// test
	void Shadow();
	// grow表現
	bool glow();
	void callBackTime(GLProgram* glProgram,Uniform* uniform);
	void callbackColor(GLProgram* glProgram, Uniform* uniform);
	//アルファ
	void test();
	// パーティクル表現
	void particle();
	// スプライト赤
	void sampleSprite();
	// グラデーション
	void changeGradation();
	// shaderスプライトを光らせる
	void glowSprite();
	// ｵﾌﾞｼﾞｪｸﾄ消えた時の
	// オーラ出させる
	void auraEffect();
	void objExtinctionEffect();
	//
	void test1();
	int keydown_flg = 1;
	void keyData();
	// アップデート
	void update(float delta);

	void scaling();
};

#endif //Select