#include "GameOver.h"
#include "TitleScene.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

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


	

	// 魔法陣のやつ
	MagicEffect();
	// touchしたところに追従するよ
	SwordEffect();
	// 波紋
	//Ripple();
	Test();
	return true;
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
	lbl_Select->setPosition(Point(origin.x + winSize.width / 2,
		origin.y + winSize.height - lbl_Select->getContentSize().height));

	// Select追加
	this->addChild(lbl_Select, 1);

	// player表示
	Sprite *plyaer = Sprite::create("PL_Healer.png");
	plyaer->setPosition(winSize.width/2,winSize.height/2-100);
	addChild(plyaer,1);


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
	Sprite *magic = Sprite::create("sample.png");		// 画像読み込み
	magic->setAnchorPoint(Vec2::ANCHOR_MIDDLE);			// オブジェクトの基準点を中心に
	magic->setPosition(winSize.width/2-200, winSize.height/2 -450);		// 座標セット
	magic->setScale(0.0f);								// 大きさセット
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
void GameOver::SwordEffect()
{
	static int streak_tag = 1000;
	static int streak_layer = 10000;
	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [this](Touch *touch, Event *event) -> bool {
		this->removeChildByTag(streak_tag);

		auto streak = cocos2d::MotionStreak::create(0.8f, 1, 20, Color3B(200, 200, 250), "sample.png");
		streak->setBlendFunc(BlendFunc::ADDITIVE);
		streak->setPosition(800, 1200);
		this->addChild(streak, streak_layer, streak_tag);
		return true;
	};
	listener->onTouchMoved = [=](Touch *touch, Event *event) {
		auto streak = (cocos2d::MotionStreak*)this->getChildByTag(streak_tag);
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

void GameOver::Test()
{
	// 画面サイズ取得
	Size VisibleSize = Director::getInstance()->getVisibleSize();
	// 塗りつぶした円（＝大きな点）
	DrawNode *dot = DrawNode::create();
	dot->drawDot(Vec2::ZERO, 50, Color4F::YELLOW);
	dot->setPosition(VisibleSize.width/2,VisibleSize.height/2 + 200);
	this->addChild(dot,2);
}





