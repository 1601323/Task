#include "GameOver.h"
#include "TitleScene.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "shader/Shaders.hpp"
#include "shader/shaderaction/ChangeColorBy.hpp"

// ローディング画面
/*　https://www.indetail.co.jp/blog/cocos2d-x3/ 　*/

USING_NS_CC;

typedef void (GameOver::*SEL_SCHEDULE)(float);

Scene *GameOver::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOver::create();
	scene->addChild(layer);
	return scene;
}

// 初期化
bool GameOver::init()
{
	if (!Layer::init())
	{
		return false;
	}

	// バックグランド
	ClearBackGroudn();

	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	// ボタン配置
	// 通常時,押した時
	// 押した時のｱｸｼｮﾝ
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(GameOver::pushStart, this));

	// ボタンの配置
	startButton->setPosition(50, 1200);
	// メニュー作成(自動obj)
	auto menu = Menu::create(startButton, NULL);
	menu->setPosition(Point::ZERO);
	// 追加
	this->addChild(menu, 1);


	//keyData();
	// 毎フレーム呼び出し　/*　https://qiita.com/s0hno/items/739b8da8d0ee1375c2cd　*/
	this->scheduleUpdate();
	//scaling();
	MagicEffect();			// 魔法陣のやつ
	//SwordEffect();			// touchしたところに追従するよ
	//Ripple();				// 波紋
	//Shadow();				// 影
	//test();				// アルファ
	//particle();			// パーティクル表現
	//sampleSprite();		// スプライト赤になってるよ
	//changeGradation();	// Gradation
	//glowSprite();			// スプライトを光らせる
	//auraEffect();			// オーラ ×
	//blur();
	//objExtinctionEffect	// エフェクト消えた表現
	return true;
}

// 更新
void GameOver::update(float delta)
{
	keyData();
//	test1();
	
}


//
void GameOver::scaling()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

}

// テスト
void GameOver::test1()
{
	/* http://pierre-net.com/post-717/ */
	// 画面サイズ取得
	Size visibleSize = Director::getInstance()->getVisibleSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	// Rect画像切り取る関数(切り取り座標X,Y,幅、高さ)
	// 切れてるとき
	if (keydown_flg == 0)
	{
		Sprite *enemyUp = Sprite::create("Enemy/EM_Zombi.png", Rect(0, 0, 335, 200));
		enemyUp->setColor(Color3B(255,0,0));
		enemyUp->setPosition(visibleSize.width / 2, visibleSize.height / 2 +100);
		this->addChild(enemyUp);
	}
	// 通常時
	else
	{
		Sprite *enemy = Sprite::create("Enemy/EM_Zombi.png");
		enemy->setPosition(visibleSize.width/2 , visibleSize.height/2 );
		this->addChild(enemy);
		
	}
}

void GameOver::keyData()
{
	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* keyEvent) {
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_SPACE)
		{
			keydown_flg = 1;
			cocos2d::log("1");
		}
		else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_0)
		{
			keydown_flg = 0;
			cocos2d::log("0");
		}
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

// オーラ
void GameOver::auraEffect()
{
	//画像サイズ取得
	Size visibleSize = Director::getInstance()->getWinSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	// 画像登録
	auto sprite = Sprite::create("HelloWorld.png");
	// 配置(中心位置)
	sprite->setPosition(visibleSize.width/2 ,visibleSize.height/2);
	
	Vec4 color(0.5f,0.5f,0.5f,1.0f);

	GLfloat ctime  = 1.0f;
	GLfloat gtime  = 1.0f;
	GLfloat radius = 5.0f;

	auto fileUtiles = FileUtils::getInstance();
	auto fragmentFullPath = fileUtiles->fullPathForFilename("shaders/glow.fsh");
	auto fragSource = fileUtiles->getStringFromFile(fragmentFullPath);

	auto glprogram = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, fragSource.c_str());
	auto glProgramState = GLProgramState::getOrCreateWithGLProgram(glprogram);

	glProgramState->setUniformVec4("u_outlineColor", color);
	glProgramState->setUniformFloat("u_ctime", ctime);
	glProgramState->setUniformFloat("u_threshold", gtime);
	glProgramState->setUniformFloat("u_radius", radius);

	sprite->setGLProgramState(glProgramState);

	glProgramState->setUniformCallback("u_outlineColor", CC_CALLBACK_2(GameOver::callbackColor, this));

	addChild(sprite,1);
}

// エフェクト消えた時のやつ
void GameOver::objExtinctionEffect()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	CCParticleExplosion* p = CCParticleExplosion::create(); // 爆発的なエフェクトの初期化
	p->setDuration(0.05);									// エフェクトが停止するまでの時間 
	p->setScale(0.2f);										// エフェクト大きさ
	p->setSpeed(800);										// エフェクトの動く速さ
	p->setPosition(winSize.width / 2, winSize.height / 2);  // エフェクトの発生地点
	// エフェクトの表示
	this->addChild(p, 8); // addChild するとすぐ表示
}

// スプライトを光らせる
/* http://brbranch.jp/blog/201607/cocos2d-x/shader/ */
void GameOver::glowSprite()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	// シェーダいじっくったマンーーー

	// 画像の追加(変化なし)
	auto sprite = Sprite::create("HelloWorld.png");
	// 座標指定
	sprite->setPosition(Vec2(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y - 200));
	// 画像の追加(変化あり)
	auto spr2 = Sprite::create("HelloWorld.png");
	// 座標指定
	spr2->setPosition(Vec2(winSize.width / 2, winSize.height / 2 + origin.y + 200));


	auto change = ChangeColorBy::create(ChangeColorType::HSV, Vec3(1.0, -1.0, 1.0), false, 1.0);
	sprite->runAction(Sequence::create(DelayTime::create(5.0), change, FadeOut::create(0.5), NULL));
	{
		// shaderの作成
		// 呼び出し(shaderファイルの読み込み)
		auto readShader = GLProgram::createWithByteArrays(cocos2d::LightHsvShaderVert, cocos2d::LightHsvShaderFrag);
		auto state = GLProgramState::getOrCreateWithGLProgram(readShader);
		// ｽﾌﾟﾗｲﾄに設定
		spr2->setGLProgramState(state);
		// 変数の設定(u_color内に設定されるよ)
		state->setUniformVec3("u_color", Vec3(0.0, 0.0, 0.0));
	}

	// 追加
	this->addChild(sprite, 0);
	this->addChild(spr2, 1);
}

// 背景
void GameOver::ClearBackGroudn()
{
	// 画面サイズ取得
	Size winSize = Director::getInstance()->getVisibleSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	// タイトル配置
	// 配置文字
	auto lbl_Select = Label::createWithSystemFont("Nemui!!!!!!!!!!!!!!!!!!", "HiraKakuProN-W6", 100);
	// 配置場所
	lbl_Select->setPosition(Point(origin.x + winSize.width / 2,origin.y + winSize.height - lbl_Select->getContentSize().height));

	// Select追加
	this->addChild(lbl_Select, 1);

	//// player表示
	//Sprite *plyaer = Sprite::create("EM_Zombi.png");
	//plyaer->setPosition(winSize.width/2,winSize.height/2-100);
	//addChild(plyaer,1);
}

// 画面遷移
void GameOver::pushStart(Ref * pSender)
{
	CCLOG("Pushボタン");

	// 遷移策の画面をｲﾝｽﾀﾝｽ
	Scene *pScene = TitleScene::createScene();

	// 0.6秒かけて次画面に遷移
	// (時間,遷移先,色(オプション))
	TransitionFade *transition = TransitionFade::create(0.6, pScene);

	// 遷移実行 アニメーション
	Director::getInstance()->replaceScene(transition);
}

// 魔法陣表示
void GameOver::MagicEffect()
{
	// 画面サイズ取得
	Size winSize = Director::getInstance()->getVisibleSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	// 魔法陣のやつやりまっせ！！
	// つぶして奥行表現
	Node *fram = Node::create();
	fram->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	fram->setPosition(winSize.width / 2-200, winSize.height / 2 -450);
	fram->setScaleY(0.5);
	this->addChild(fram);
	// 魔法陣
	Sprite *magic = Sprite::create("sample1.png");						// 画像読み込み
	magic->setAnchorPoint(Vec2::ANCHOR_MIDDLE);							// オブジェクトの基準点を中心に
	magic->setPosition(winSize.width/2-200, winSize.height/2 -450);		// 座標セット
	magic->setScale(0.0f);												// 大きさセット

	// スプライトを光らせる
	auto change = ChangeColorBy::create(ChangeColorType::HSV, Vec3(1.0, -1.0, 1.0), false, 1.0);
	magic->runAction(Sequence::create(DelayTime::create(1.0), change, FadeOut::create(0.5), NULL));
	{
		// shaderの作成
		// 呼び出し(shaderファイルの読み込み)
		auto readShader = GLProgram::createWithByteArrays(cocos2d::LightHsvShaderVert, cocos2d::LightHsvShaderFrag);
		auto state = GLProgramState::getOrCreateWithGLProgram(readShader);
		// ｽﾌﾟﾗｲﾄに設定
		magic->setGLProgramState(state);
		// 変数の設定(u_color内に設定されるよ)
		state->setUniformVec3("u_color", Vec3(0.0, 0.0, 0.0));
	}

	fram->addChild(magic,0);

	// アニメーション
	FiniteTimeAction *action1 = Spawn::create(RotateBy::create(0.2f, 90.0f),	/*ｽﾞｽﾞｽﾞっと大きく*/
		ScaleTo::create(0.2f, 1.7f), NULL);										/*だんだん大きく*/
	FiniteTimeAction *action2 = RotateBy::create(1.5f, 300.0f);					/*回転*/
	FiniteTimeAction *action3 = Spawn::create(RotateBy::create(0.2f, 90.0f),	/*ｽﾞｽﾞｽﾞっと大きく*/
		ScaleTo::create(0.2f, 3.0f),											/*だんだん大きく*/
		FadeOut::create(0.2f), NULL);											/*ﾌｪｲﾄｱｳﾄ*/
																				// 繰り返し呼ぶ
	
	CallFunc *reset = CallFunc::create([magic]() {
		// リピートの為にリセット
		magic->setScale(0.0f);
		magic->setOpacity(255);
	});

	// 複数のアニメーションを連続で行う
	magic->runAction(RepeatForever::create(Sequence::create(action1,
		action2,
		action3,
		reset,

		
		DelayTime::create(1.0f), NULL)));		// 一定時間後に生成
	magic->setColor(Color3B(0, 255, 90));

}
// 回復表示
void GameOver::RecoveryEffect()
{
	// 画面サイズ取得
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 orizin		 = Director::getInstance()->getVisibleOrigin();

	// スプライトしーとの準備a
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites.plest");
	
	// 画像の表示
	Sprite* sprite = Sprite::createWithSpriteFrameName("effect_cure01_0000.png");
}
// touchしたところに追従するよ
//　　https://qiita.com/edo_m18/items/c2db0bc42dcc59975889
void GameOver::SwordEffect()
{
	static int streak_tag   = 1000;		// 指定ﾀｸﾞ用
	static int streak_layer = 10000;	// 光線ﾚｲﾔｰ

	// 生成
	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	// touch処理
	listener->onTouchBegan = [this](Touch *touch, Event *event) -> bool {
		this->removeChildByTag(streak_tag);		// removeChildByTag:オブジェクトの削除用
		// 使用する画像の登録
		// MotionStreakクラス軌跡表示用(使用すると剣の軌跡エフェクト表現可)
		// フェード時間、表示が始まるための移動速度、画像サイズ、色、ファイル
		auto streak = MotionStreak::create(fadeSpeed, startSpeed, imageSize, Color3B(200, 200, 250), "sample.png");
		// 加算のブレンド設定 ADDITIVE{G_SRC_ALPHA,GL_ONE}
		streak->setBlendFunc(BlendFunc::ADDITIVE);
		// 座標セット
		streak->setPosition(800, 1200);
		// 追加
		this->addChild(streak, streak_layer, streak_tag);
		return true;
	};
	listener->onTouchMoved = [=](Touch *touch, Event *event) {
		auto streak = (MotionStreak*)this->getChildByTag(streak_tag);
		streak->setPosition(touch->getLocation());
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}
// 波紋のやーつ
void GameOver::Ripple()
{
	//	色の加算合成 後からつうじゅうするやつ

	// 波紋のスピード
	unsigned int rippleSpeed  = 7;
	// 中心の波紋のスピード
	unsigned int rippleCenter = 500;

	Ripple3D* action;
	// スプライトを作成
	Sprite *fish = Sprite::create("sample.png");
	fish->setPosition(Vec2(320, 568));

	// 波紋を広げるアニメーション作成()　
	//CCRipple3D::create ((float)時間,(CCSize)グリッドサイズ,(CCPoint)波紋の中心位置,(float)半径,(int)波の数,(float)振幅 );
	
	action = Ripple3D::create(10, cocos2d::Size(150, 150), Vec2(640 / 2, 1136 / 2), rippleCenter, rippleSpeed, 100);
	// NodeGrid作成
	NodeGrid *nodeGrid = NodeGrid::create();
	nodeGrid->addChild(fish);
	nodeGrid->runAction(action);

	this->addChild(nodeGrid);
}
// 丸い影
void GameOver::Shadow()
{
	//// 画面サイズ取得
	//Size VisibleSize = Director::getInstance()->getVisibleSize();
	//// 塗りつぶした円（＝大きな点）
	//DrawNode *dot = DrawNode::create();
	//dot->drawDot(Vec2::ZERO, 50, Color4F::YELLOW);
	//dot->setPosition(VisibleSize.width/2,VisibleSize.height/2 + 200);
	//this->addChild(dot,2);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	Size winSize = Director::getInstance()->getWinSize();

	//cocos2dxの画像
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	sprite->setScale(1.5f, 3.0f);
	this->addChild(sprite, 0);

	////黒い四角形スプライト
	Sprite* shadowSprite = Sprite::create();
	shadowSprite->setTextureRect(Rect(0.0f, 0.0f, winSize.width, winSize.height));
	shadowSprite->setColor(Color3B::BLACK);
	shadowSprite->setOpacity(200);
	shadowSprite->setPosition(Point(winSize.width / 2, winSize.height / 2));
	//this->addChild(shadowSprite, 1);

	//切り抜く円を描画
	DrawNode *light = DrawNode::create();
	light->drawDot(Point(winSize.width / 2, winSize.height / 2), 100, Color4F::WHITE);

	//クリッピング作成
	ClippingNode* clipping = ClippingNode::create();
	clipping->setStencil(light);						//切り抜き範囲を設定
	clipping->addChild(shadowSprite);					//クリッピングの上に切り抜くSpriteを配置
	clipping->setInverted(true);						//切り抜いた部分以外を表示するか(true)切り抜いた部分を表示するか(false)
	clipping->setAlphaThreshold(0.1f);					//アルファのしきい値を設定
	this->addChild(clipping, 1);
}

// grow表現
/* https://qiita.com/isaoeka/items/dee8159e2a0c2a37a662　*/
bool GameOver::glow()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(winSize.width / 2, winSize.height / 2);

	Vec4 color(0.5f, 0.5f, 0.5f, 1.0f);

	m_ctime = 0.01f;  // メンバ変数
	GLfloat gtime = 1.0f;
	GLfloat radius = 5.0f;

	auto fileUtiles = FileUtils::getInstance();

	auto fragmentFullPath = fileUtiles->fullPathForFilename("shader/shaders/glow.fsh");
	auto fragSource = fileUtiles->getStringFromFile(fragmentFullPath);

	auto glprogram = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, fragSource.c_str());
	auto glProgramState = GLProgramState::getOrCreateWithGLProgram(glprogram);

	glProgramState->setUniformVec4("u_outlineColor", color);
	glProgramState->setUniformFloat("u_ctime", m_ctime);
	glProgramState->setUniformFloat("u_threshold", gtime);
	glProgramState->setUniformFloat("u_radius", radius);

	sprite->setGLProgramState(glProgramState);

	glProgramState->setUniformCallback("u_ctime", CC_CALLBACK_2(GameOver::callbackColor, this));

	this->addChild(sprite, 3);

	return false;
}
void GameOver::callBackTime(GLProgram * glProgram, Uniform * uniform)
{
	m_ctime += 0.05;
	glProgram->setUniformLocationWith1f(uniform->location,(sin(m_ctime) + 1 ) / 2);
}
void GameOver::callbackColor(GLProgram* glProgram, Uniform* uniform)
{
	float r = CCRANDOM_0_1();
	float g = CCRANDOM_0_1();
	float b = CCRANDOM_0_1();
	float a = 1.0f;

	glProgram->setUniformLocationWith4f(uniform->location, r, g, b, a);
}

void GameOver::test()
{
	//CCSize size = CCDirector::sharedDirector()->getWinSize();

	//CCLayerColor* background = CCLayerColor::create(ccc4(0, 255, 0, 255), size.width, size.height);
	//this->addChild(background, 10);

	//CCLayerColor* foreground = CCLayerColor::create(ccc4(0, 0, 255, 127), size.width, size.height);
	//this->addChild(foreground, 20);

	//ccBlendFunc blend;
	//blend.src = GL_SRC_ALPHA;
	//blend.dst = GL_ONE_MINUS_SRC_ALPHA;

	//foreground->setBlendFunc(blend);



	/*Size size = Director::getInstance()->getVisibleSize();
	Vec2 orizin = Director::getInstance()->getVisibleOrigin();
	CCLayerColor* mask = CCLayerColor::create(ccc4(0, 0, 0, 128), size.width, size.height);
	this->addChild(mask, 30);

	srand((unsigned int)time(NULL));

	CCDrawNode* dot = CCDrawNode::create();
	dot->drawDot(ccp(rand() % (int)size.width, rand() % (int)size.height), rand() % 100, ccc4f(1, 1, 1, 1));
	dot->drawDot(ccp(rand() % (int)size.width, rand() % (int)size.height), rand() % 100, ccc4f(1, 1, 1, 1));
	dot->drawDot(ccp(rand() % (int)size.width, rand() % (int)size.height), rand() % 100, ccc4f(1, 1, 1, 1));
	dot->drawDot(ccp(rand() % (int)size.width, rand() % (int)size.height), rand() % 100, ccc4f(1, 1, 1, 1));
	dot->drawDot(ccp(rand() % (int)size.width, rand() % (int)size.height), rand() % 100, ccc4f(1, 1, 1, 1));
	dot->drawDot(ccp(rand() % (int)size.width, rand() % (int)size.height), rand() % 100, ccc4f(1, 1, 1, 1));
	dot->drawDot(ccp(rand() % (int)size.width, rand() % (int)size.height), rand() % 100, ccc4f(1, 1, 1, 1));
	dot->drawDot(ccp(rand() % (int)size.width, rand() % (int)size.height), rand() % 100, ccc4f(1, 1, 1, 1));
	this->addChild(dot, 40);

	ccBlendFunc blend;
	blend.src = GL_DST_COLOR;
	blend.dst = GL_ONE;

	dot->setBlendFunc(blend);*/


}

// パーティクル表現
/*void GameOver::particle()
{
	// 花火
	CCParticleFireworks* pParticle = CCParticleFireworks::createWithTotalParticles(1000);
	// 爆発
	CCParticleExplosion* pParticle = CCParticleExplosion::createWithTotalParticles(1000);
	// 雪
	CCParticleSnow* pParticle	   = CCParticleSnow::createWithTotalParticles(1000);
	// 雨
	CCParticleRain* pParticle	   = CCParticleRain::createWithTotalParticles(1000);
	// 煙
	CCParticleSmoke* pParticle	   = CCParticleSmoke::createWithTotalParticles(1000);
	// 炎
	CCParticleFire* pParticle	   = CCParticleFire::createWithTotalParticles(1000);
	// 花
	CCParticleFlower* pParticle    = CCParticleFlower::createWithTotalParticles(1000);
	// 銀河
	CCParticleGalaxy* pParticle    = CCParticleGalaxy::createWithTotalParticles(1000);
	// 渦巻
	CCParticleSpiral* pParticle    = CCParticleSpiral::createWithTotalParticles(1000);
	// 流星
	CCParticleMeteor* pParticle    = CCParticleMeteor::createWithTotalParticles(1000);
	// 太陽
	CCParticleSun* pParticle	   = CCParticleSun::createWithTotalParticles(1000);

	// 追加
	this->addChild(pParticle,0);
}*/

//CCActionInterval* MyTownTopScene::getAddAction(float base,float scale)
//{
//	CCFadeIn *ac_fadein = CCFadeIn::create(0);
//	CCScaleTo *ac_scale1 = CCScaleTo::create(0.2,scale);
//	CCScaleTo *ac_scale2 = CCScaleTo::create(0.2,base);
//
//	CCFiniteTimeAction *seq = CCSequence::create(ac_fadein, ac_scale1, ac_scale2,NULL);
//	// ｱｸｼｮﾝ
//	CCActionInterval *action = static_cast<CCActionInterval*>(seq);
//}

// スプライト赤になってるよ
//　https://www.drjiro.com/game-engine/cocos2dx/sprite/
void GameOver::sampleSprite()
{
	// 画面サイズ取得
	Size visibleSize = Director::getInstance()->getVisibleSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();
	// スプライトを作成する。
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	sprite->setColor(Color3B(255, 0, 0));

	// スプライトをシーンに追加する。
	this->addChild(sprite, 0);
}

// Gradation
//　http://surfrog.net/2016/04/20/cocos2dgradient/
void GameOver::changeGradation()
{
	// 画面サイズ取得
	Size visibleSize = Director::getInstance()->getVisibleSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	static float thete = 0.0f;	// Gradation変更速度用
	thete += 0.05;				// 追加速度更新
	GLubyte cener = 128, widh = 127;			// 色の基準値と増減地

	GLubyte r = sin(thete)* widh +cener;						// 赤成分
	GLubyte g = sin(thete + 2.0f / 3.0f*M_PI) *widh + cener;	// 緑成分
	GLubyte b = sin(thete + 4.0f / 3.0f*M_PI) *widh + cener;	// 青成分

	//_layer - &gt; setColor(Color3B(r, g, b));	// 色の更新
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	sprite->setColor(Color3B(r,g,b));

	this->addChild(sprite, 0);
}




