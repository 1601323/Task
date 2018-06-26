#include "TitleScene.h"
#include "DiffSelectScene.h"
#include "CharaSelectScene.h"
#include "GameOver.h"
#include "TopScroll.h"
#include <algorithm>
#include "cocos2d.h"

const int DIV_NUM		 = 4;
const int DIV_CIRCLE	 = 360;		
const int DIV_ANGLE		 = DIV_CIRCLE / DIV_NUM;
const int DIV_ANGLE_HALF = DIV_ANGLE / 2;


// 角度調整
const unsigned int RADIUS		   = 150;		// 円の広がり
const float PI					   = 3.14159265359f;
const float FLATTEN_RATE		   = 0.1f;		// 奥行
const unsigned int PL_POS_OFFSET_Y = 400;		// プレイヤー表示のオフセット
const unsigned int PL_POS_OFFSET_X = 600;		// プレイヤー表示のオフセット

// 拡大幅
const float LIMIT_TIME			   = 0.9f;		// 秒指定[戻る際]
const float DOUBLE_SCALE		   = 0.5f;		// 何倍か[拡大率指定]
const float WAIT_TIME			   = 0.6f;		// 待機時間
const float BOX_SCALE			   = 0.9;		// チーム編成用のBOXの拡大率

const unsigned int BUTTON_POS_X = 50;			// ボタンの配置座標X
const unsigned int BUTTON_POS_Y = 1200;			// ボタンの配置座標Y

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
	// 通常時,押した時
	// 押した時のｱｸｼｮﾝ
	auto startButton = MenuItemImage::create("CloseNormal.png","CloseSelected.png", CC_CALLBACK_1(TitleScene::pushStart,this));

	// ボタンの配置
	startButton->setPosition(BUTTON_POS_X, BUTTON_POS_Y);
	// メニュー作成(自動obj)
	auto menu = Menu::create(startButton,NULL);
	menu->setPosition(Point::ZERO);
	// 追加
	this->addChild(menu,1);
	
	ActSelectDraw();		// キャラ表示
	SwipeRotation();		// スワイプに合わせて回転
	Arrange();

	// touchイベント
	auto touchEventGet = EventListenerTouchOneByOne::create();
	touchEventGet->onTouchBegan = CC_CALLBACK_2(TitleScene::TouchBegan, this);
	touchEventGet->onTouchMoved = CC_CALLBACK_2(TitleScene::TouchMove, this);
	touchEventGet->onTouchEnded = CC_CALLBACK_2(TitleScene::TouchEnd, this);

	// 登録
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchEventGet, this);
	return true;
}

// 押した瞬間
bool TitleScene::TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	return true;
}

// スワイプ中
void TitleScene::TouchMove(cocos2d::Touch* touch, cocos2d::Event* event)
{
}

// 離した瞬間
void TitleScene::TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event)
{
}

// 行動選択表示
void TitleScene::ActSelectDraw()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	_Attack  = Sprite::create("UI/Command/UI_Button_Attack01.png");
	_Defence = Sprite::create("UI/Command/UI_Button_Defence01.png");
	_Item	 = Sprite::create("UI/Command/UI_Button_Item01.png");
	_Skill	 = Sprite::create("UI/Command/UI_Button_Skill01.png");

	this->items.clear();
	this->items.push_back(_Attack);
	this->items.push_back(_Defence);
	this->items.push_back(_Item);
	this->items.push_back(_Skill);

	// 配置
	for (auto& item :items)
	{
		this->addChild(item,0);
	}
	this->angle = 0.0f;
	
}

// アレンジ
void TitleScene::Arrange()
{
	// 縦に回るようなの
	float theta = 360.0f / items.size() + (items.size()/2);
	float baseAngle = this->angle ;							// 加算すると円の奥行増えるよ
	for (int i = 0; i < items.size(); i++)
	{
		// 270 度の位置が正面にくるように  
		float angle		= theta   * i + baseAngle;
		float radians	= angle   * PI / 180.0;
		float x			= RADIUS  * cos(radians);
		float y			= RADIUS  * sin(radians) * FLATTEN_RATE;	// 円の角度斜めにするよ
		float radiusY	= RADIUS  * FLATTEN_RATE;
		float diameterY = radiusY * 2;
		float scale		= (diameterY - y) / diameterY;				// y座標に応じて変化するよ
		GLubyte opacity = 255 - (y + radiusY);

		this->items.at(i)->setPosition(Vec2(y + PL_POS_OFFSET_Y ,x + PL_POS_OFFSET_X));
		this->items.at(i)->setScale(scale);
		this->items.at(i)->setOpacity(opacity);
		this->items.at(i)->setZOrder(diameterY - y);
	}
	//そーとするよ(´・ω・`)
	auto tmpVector = items;
	std::sort(tmpVector.begin(), tmpVector.end(), [](const Node* a, const Node* b)
		// 先に大きいのtrue /　begin > end ←初めに大きいもの来る＝大きい順になる  
	{return a->getScale() > b->getScale(); });
	// TOPに一番多きものが入る
	Top = tmpVector.front();	
}

// スワイプ
void TitleScene::SwipeRotation()
{
	// スワイプに合わせて回転
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	// クリックしたとき
	listener->onTouchBegan = [](Touch *touch, Event *event) { return true; };
	// 移動量[スワイプ]
	listener->onTouchMoved = [&](Touch *touch, Event *event)
	{
		float delta = touch->getLocation().y - touch->getPreviousLocation().y;
		this->angle += delta;
		Arrange();
	};
	// 離した
	listener->onTouchEnded = [&](Touch *touch, Event *event)
	{
		// 補正つけますよ
		// 正の値
		if (angle>0.f)
		{
			this->angle = (((((static_cast<int>(this->angle)) + DIV_ANGLE_HALF) % 360) / DIV_ANGLE) * DIV_ANGLE);
		}
		// 負の値
		else
		{
			this->angle = ((((static_cast<int>(this->angle - 360) % 360 - DIV_ANGLE_HALF) % 360) / DIV_ANGLE) * DIV_ANGLE);
		}
		Arrange();
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

// 背景
void TitleScene::TitleBackGroudn()
{
	// 画面サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	// マルチレゾリューション対応がどうとか
	Point origin = Director::getInstance()->getVisibleOrigin();

	// タイトル配置
	// 配置文字
	auto lbl_Title = Label::createWithSystemFont("Title","HiraKakuProN-W6",100);
	// 配置場所
	lbl_Title->setPosition(Point(origin.x+winSize.width/2,
								 origin.y+winSize.height - lbl_Title->getContentSize().height));
	// Title追加
	this->addChild(lbl_Title,1);

	// 背景画像追加
	Sprite* bgsprite = Sprite::create("BackImage/ST_Boss.png");
	// 表示座標指定
	bgsprite->setPosition(winSize.width/2, winSize.height/2);
	this->addChild(bgsprite,0);
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

// 四角描画
void TitleScene::RectDraw(const unsigned int x, const unsigned int y, const unsigned int _width, const unsigned int _height, const int posX, const int posY)
{
	Rect rect = Rect(x, y, _width, _height);
	Sprite *square = Sprite::create();
	square->setTextureRect(rect);
	square->setPosition(posX, posY);
	this->addChild(square, 5);
}
	