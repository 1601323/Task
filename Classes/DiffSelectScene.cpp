#include "DiffSelectScene.h"
#include "CharaSelectScene.h"

Scene *DiffSelectScene::createScene()
{
	auto scene = Scene::create();
	auto layer = DiffSelectScene::create();
	scene->addChild(layer);
	return scene;
}

// 初期化
bool DiffSelectScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	// バックグランド
	SelectBackGroudn();

	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();

	// ボタン配置 (通常時,押した時)
	// 押した時のｱｸｼｮﾝ
	auto diffButton = MenuItemImage::create("01.png", "02.png", CC_CALLBACK_1(DiffSelectScene::pushStart, this));
	auto EasyButton = MenuItemImage::create("03.png", "04.png", CC_CALLBACK_1(DiffSelectScene::pushStart, this));

	// ボタンの配置
	diffButton->setPosition(Point(winSize.width / 2 + 80, winSize.height / 2));
	EasyButton->setPosition(Point(winSize.width / 2 - 80, winSize.height / 2));

	// メニュー作成(自動obj)
	auto menu1 = Menu::create(diffButton, NULL);
	auto menu2 = Menu::create(EasyButton, NULL);
	menu1->setPosition(Point::ZERO);
	menu2->setPosition(Point::ZERO);

	// 追加
	this->addChild(menu1, 1);
	this->addChild(menu2, 2);

	return true;
}

// 

// 背景
void DiffSelectScene::SelectBackGroudn()
{
	// 背景
	// サイズ取得
	CCSize rightSize = CCDirector::sharedDirector()->getWinSize();
	// 画像指定
	CCSprite* pSprite = CCSprite::create("haikei.png");
	// 表示座標指定
	pSprite->setPosition(ccp(rightSize.width / 2, rightSize.height / 2));
	// 追加
	this->addChild(pSprite, 0);

	// 回る背景のやつ
	//CCSize rightSize = CCDirector::sharedDirector()->getWinSize();
	//CCSprite* pSprite = CCSprite::create("miku.png");
	//pSprite->setPosition(ccp(rightSize.width/2,rightSize.height/2));
	//pSprite->setOpacity(85);
	//this->addChild(pSprite,1);
	// ﾏﾜﾚﾏﾜﾚﾏﾜｰﾚ
	//CCActionInterval* actionRate = CCRotateBy::create(4.0f,360);
	//CCRepeatForever*  actionRepeatForver = CCRepeatForever::create(actionRate);
	//pSprite->runAction(actionRepeatForver);

	// 画面サイズ取得
	Size winSize = Director::getInstance()->getVisibleSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	// タイトル配置
	// 配置文字
	auto lbl_Select = Label::createWithSystemFont("Select", "HiraKakuProN-W6", 100);
	// 配置場所
	lbl_Select->setPosition(Point(origin.x + winSize.width / 2,
								  origin.y + winSize.height - lbl_Select->getContentSize().height));

	// Select追加
	this->addChild(lbl_Select, 2);

	// キャラ表示
	// 画像指定
	CCSprite* pPlayer = CCSprite::create("Player.png");
	// 表示座標指定
	pPlayer->setPosition(ccp(rightSize.width / 2, rightSize.height / 2));
	// 追加
	this->addChild(pPlayer, 1);

}

// 画面遷移
void DiffSelectScene::pushStart(Ref * pSender)
{
	CCLOG("Pushボタン");

	// 遷移策の画面をｲﾝｽﾀﾝｽ
	Scene *pScene = CharaSelectScene::createScene();

	// 0.6秒かけて次画面に遷移
	// (時間,遷移先,色(オプション))
	TransitionFade *transition = TransitionFade::create(0.6, pScene);

	// 遷移実行 アニメーション
	Director::getInstance()->replaceScene(transition);
}