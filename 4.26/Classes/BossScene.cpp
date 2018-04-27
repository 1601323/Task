#include "BossScene.h"
#include "GameClear.h"

Scene *BossScene::createScene()
{
	auto scene = Scene::create();
	auto layer = BossScene::create();
	scene->addChild(layer);
	return scene;
}

// 初期化
bool BossScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	// バックグランド
	BossBackGroudn();

	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();

	// ボタン配置
	// 通常時,押した時
	// 押した時のｱｸｼｮﾝ
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(BossScene::pushStart, this));

	// ボタンの配置
	startButton->setPosition(Point(winSize.width / 2, winSize.height / 2));
	// メニュー作成(自動obj)
	auto menu = Menu::create(startButton, NULL);
	menu->setPosition(Point::ZERO);
	// 追加
	this->addChild(menu, 1);

	return true;
}

// 背景
void BossScene::BossBackGroudn()
{
	// 画面サイズ取得
	Size winSize = Director::getInstance()->getVisibleSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	// バックカラー
	auto groundCollar = LayerColor::create(Color4B::RED, winSize.width, winSize.height);

	// バックグランドCollar第2:表示順
	this->addChild(groundCollar, 0);

	// タイトル配置
	// 配置文字
	auto lbl_Select = Label::createWithSystemFont("Boss", "HiraKakuProN-W6", 100);
	// 配置場所
	lbl_Select->setPosition(Point(origin.x + winSize.width / 2,
		origin.y + winSize.height - lbl_Select->getContentSize().height));

	// Select追加
	this->addChild(lbl_Select, 1);
}

// 画面遷移
void BossScene::pushStart(Ref * pSender)
{
	CCLOG("Pushボタン");

	// 遷移策の画面をｲﾝｽﾀﾝｽ
	Scene *pScene = GameClear::createScene();

	// 0.6秒かけて次画面に遷移
	// (時間,遷移先,色(オプション))
	TransitionFade *transition = TransitionFade::create(0.6, pScene);

	// 遷移実行 アニメーション
	Director::getInstance()->replaceScene(transition);
}