#include "TitleScene.h"
//音をならすためにinclude
#include "SimpleAudioEngine.h"
#include "CharaSelectScene.h"

Scene *TitleScene::createScene()
{
	auto scene = Scene::create();
	auto layer = TitleScene::create();
	scene->addChild(layer);
	return scene;
}

// 初期化
bool TitleScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	// バックグランド
	TitleBackGroudn();

	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();

	// ボタン配置
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(TitleScene::pushStart, this));

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
void TitleScene::TitleBackGroudn()
{
	// 画面サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	// マルチレゾリューション対応がどうとか
	Point origin = Director::getInstance()->getVisibleOrigin();

	// 背景画像追加
	Sprite* bgsprite = Sprite::create("BackImage/Title.png");
	// 表示座標指定
	bgsprite->setPosition(winSize.width/2,winSize.height/2);
	this->addChild(bgsprite, 0);
}

// 画面遷移
void TitleScene::pushStart(Ref *pSender)
{
	// log表示
	CCLOG("Pushボタン");

	// 遷移策の画面をｲﾝｽﾀﾝｽ
	Scene *pScene = CharaSelectScene::createScene();

	// 模様左からだんだん...
	Director::getInstance()->replaceScene(TransitionFadeTR::create(0.7f, CharaSelectScene::createScene()));
	CCDirector::sharedDirector()->replaceScene(CCTransitionFadeTR::create(2.0f, CharaSelectScene::createScene()));
}
