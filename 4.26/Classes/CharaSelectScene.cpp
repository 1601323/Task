#include "CharaSelectScene.h"
#include "FightScene.h"
#include "Imput.h"
#include <algorithm>
#include "cocos2d.h"
#include "DmEffect.h"

#define PI 3.14159265359f  
#define RADIUS 100  
#define FLATTEN_RATE 0.4f  

USING_NS_CC;

// 実態作るよ
std::vector<CharaName> CharaSelectScene::CharaData;

Scene *CharaSelectScene::createScene()
{
	auto scene = Scene::create();
	auto layer = CharaSelectScene::create();
	scene->addChild(layer);
	return scene;
}

// 初期化
bool CharaSelectScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	// バックグランド
	CharaSelectBackGroudn();

	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();

	// ボタン配置
	// 通常時,押した時
	// 押した時のｱｸｼｮﾝ
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(CharaSelectScene::pushStart, this));

	// ボタンの配置
	startButton->setPosition(50,1200);
	// メニュー作成(自動obj)
	auto menu = Menu::create(startButton, NULL);
	menu->setPosition(Point::ZERO);
	// 追加
	this->addChild(menu, 3);

	PL_Attacker = Sprite::create("PL_Attacker.png");

 	this->items.clear();
	this->items.push_back(PL_Attacker);
	this->items.push_back(CCSprite::create("PL_Shield.png"));
	this->items.push_back(CCSprite::create("PL_Magic.png"));
	this->items.push_back(CCSprite::create("PL_Healer.png"));

	// 円状に等間隔で配置
	for (auto item : items)
		this->addChild(item);

	this->angle = 0.0f;
	this->arrange();
	// スワイプに合わせて回転

	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [ ](Touch *touch, Event *event) { return true; };
	listener->onTouchMoved = [&](Touch *touch, Event *event) 
	{
		float delta  = touch->getLocation().x - touch->getPreviousLocation().x;
		this->angle += delta;
		this->arrange();
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// ダメージ表示のやつ
	/*srand((unsigned int)time(nullptr));

	auto listner = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [this](Touch* touch, Event* event)
	{
		DmEffect* effect = DmEffect::create();
		effect->setPosition(Vec2(touch->getLocation().x + 30 ,touch->getLocation().y));
		effect->showEffect(rand() % 9999);
		this->addChild(effect);

		return true;
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listner, this);*/

	return true;
}

// アレンジ　回転とか
void CharaSelectScene::arrange()
{
	// 円状に等間隔で配置
	float theta = 360.0f / items.size()+(items.size()/2);
	float baseAngle = this->angle + 270.0f;							// 加算すると円の奥行増えるよ
	for (int i = 0; i < items.size(); i++)
	{
		// 270 度の位置が正面にくるように  
		float angle		= theta   * i + baseAngle;
		float radians	= angle   * PI / 180.0f;
		float x		    = RADIUS  * cos(radians);
		float y	        = RADIUS  * sin(radians) * FLATTEN_RATE;	// 円の角度斜めにするよ
		float radiusY   = RADIUS  * FLATTEN_RATE;
		float diameterY = radiusY * 2;
		float scale		= (diameterY - y) / diameterY;				// y座標に応じて変化するよ
		GLubyte opacity = 255 - (y + radiusY);

		this->items.at(i)->setPosition(Vec2(x+420, y+450));
		this->items.at(i)->setScale(scale);
		this->items.at(i)->setOpacity(opacity);
		this->items.at(i)->setZOrder(diameterY - y);
	}
	//そーとするよ(´・ω・`)
	auto tmpVector = items;
	std::sort(tmpVector.begin(), tmpVector.end(), [](const Node* a, const Node* b)
	{return a->getScale() < b->getScale(); });
	Top = tmpVector.front();

}

// 背景
void CharaSelectScene::CharaSelectBackGroudn()
{
	// 画面サイズ取得
	Size winSize = Director::getInstance()->getVisibleSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	// タイトル配置
	// 配置文字
	auto lbl_Select = Label::createWithSystemFont("CharaSelect", "HiraKakuProN-W6", 100);
	// 配置場所
	lbl_Select->setPosition(Point(origin.x + winSize.width / 2,
		origin.y + winSize.height - lbl_Select->getContentSize().height));

	// Select追加
	this->addChild(lbl_Select, 1);
}

// クリック開始時に呼ばれる
//bool CharaSelectScene::onTouchBegan(Touch *touch, Event *unused_event)
//{
//	cocos2d::CCSprite* m_pSprite;
//
//	// touch座標取得
//	Vec2 touch_pos = touch->getLocation();
//	// スプライトのAABBを取得
//	Rect rect_spr = m_pSprite->getBoundingBox();
//
//	// スプライトにTouch座標が含まれているかどうか
//	bool hit = rect_spr.containsPoint(touch_pos);
//
//	if (hit)
//	{
//		log("touch sprite!!!");
//	}
//	return true;
//}


// Clickしたらデータ入れるよ
void CharaSelectScene::CharaClick()
{
	// どれが一番前にいるのかを分かるように調べよう→暗くする処理楽だよ
	// 0123にそろえましょうか　//static_cast<CharaData>(1234のやつ-1);

	//if()
	{
	// ここら辺の範囲2かいタップしたら
		int i = 0;
		for (i = 0; i < items.size(); i++)
		{
			// 
			if (items[i] == Top)
			{
				break;
			}
			// 追加
			CharaData.push_back(static_cast<CharaName> (i));
		}
			// 選択外の者は暗くする
			//	if ()
			//	{

			//		/*タップした奴　拡大率で今前のやつを判断

			//		その番号をpushback*/
			//		//push_back
			//		CharaData.push_back;
			//	}
	};
}

// キャラ情報取得
const std::vector<CharaName>& CharaSelectScene::GetCharaData()
{
	return CharaData;
}


// 画面遷移
void CharaSelectScene::pushStart(Ref * pSender)
{
	CCLOG("Pushボタン");

	// 遷移策の画面をｲﾝｽﾀﾝｽ
	Scene *pScene = FightScene::createScene();

	// 0.6秒かけて次画面に遷移
	// (時間,遷移先,色(オプション))
	TransitionFade *transition = TransitionFade::create(0.6, pScene);

	// 遷移実行 アニメーション
	Director::getInstance()->replaceScene(transition);
}



/*
http://takachan.hatenablog.com/entry/2017/08/08/002844
https://iscene.jimdo.com/2015/02/04/cocos2d-x-ver-3-x-c-iphone-android-%E3%81%AE%E9%96%8B%E7%99%BA%E5%9F%BA%E7%A4%8E%E8%AC%9B%E5%BA%A7-%E7%9B%AE-%E6%AC%A1/
http://hayateasdf.hatenablog.com/entry/2017/12/21/190434#10-%E6%95%B5%E3%81%AE%E4%BD%9C%E6%88%90
https://qiita.com/isaoeka/items/dee8159e2a0c2a37a662
http://brbranch.jp/blog/201607/cocos2d-x/shader/
http://buildman.xyz/blog/cocos2dx-beginner-10/
https://teratail.com/questions/72658
http://www.fujimi-labo.com/2016/11/29/cocos2d-x8_1/
http://rinov.jp/cocos-doujo-dx/index.html
https://qiita.com/HamachiTaro/items/f7df7fc101e7e1222afc
http://brbranch.jp/blog/201312/cocos2d-x/convert_to_node_space/

// 文字表示
//http://developer.wonderpla.net/entry/blog/engineer/Cocos2dx_Carousel
//http://hayateasdf.hatenablog.com/entry/2017/12/21/190434#10-%E6%95%B5%E3%81%AE%E4%BD%9C%E6%88%90
//https://iscene.jimdo.com/2015/02/23/cocos2d-x-ver-3-x-top%E3%83%9A%E3%83%BC%E3%82%B8-tableview-%E7%94%BB%E5%83%8F%E8%A1%A8%E7%A4%BA%E7%B7%A8/
// cocos いろんなのが載ってるサイト
// https://iscene.jimdo.com/2015/02/04/cocos2d-x-ver-3-x-c-iphone-android-%E3%81%AE%E9%96%8B%E7%99%BA%E5%9F%BA%E7%A4%8E%E8%AC%9B%E5%BA%A7-%E7%9B%AE-%E6%AC%A1/
*/