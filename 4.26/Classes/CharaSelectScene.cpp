#include "CharaSelectScene.h"
#include "FightScene.h"
#include "GameOver.h"
#include "Imput.h"
#include <algorithm>
#include "cocos2d.h"

#pragma execution_character_set("utf-8")

const int PL_TAG		  = 101;				// タグ用
const int TEXT_OFFSET	  = 480;				// text表示のオフセット値
const int DIV_NUM		  = 4;
const int DIV_ANGLE		  = 360 / DIV_NUM;
const int DIV_ANGLE_HALF  = DIV_ANGLE / 2;
const int BUTTON_POS_X	  = 50;					// ボタンの配置座標X
const int BUTTON_POS_Y	  = 1200;				// ボタンの配置座標Y
const int FONT_SIZE		  = 45;					// プレイヤー説明文用の文字ｻｲｽﾞ
const int PL_TEXT_RECT_X  = 250;				// プレイヤー用の板の配置位置X
const int PL_TEXT_RECT_Y  = 750;				// プレイヤー用の板の配置位置Y
// 角度関係で使うよ
const int RADIUS		  = 200;
const float PI			  = 3.14159265359f;
const float FLATTEN_RATE  = 0.4f;
const unsigned int PL_POS_OFFSET_X = 420;		// プレイヤー表示のオフセット
const unsigned int PL_POS_OFFSET_Y = 820;		// プレイヤー表示のオフセット
// 拡縮用
const float LIMIT_TIME	  = 0.9f;				// 秒指定[戻る際]
const float DOUBLE_SCALE  = 0.5f;				// 何倍か[拡大率指定]
const float WAIT_TIME	  = 0.6f;

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
	// ボタン配置 (通常時,押した時,押した時のｱｸｼｮﾝ)
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(CharaSelectScene::pushStart, this));

	// ボタンの配置
	startButton->setPosition(BUTTON_POS_X, BUTTON_POS_Y);
	// メニュー作成(自動obj)
	auto menu = Menu::create(startButton, NULL);
	// 座標配置
	menu->setPosition(Point::ZERO);
	// 追加
	this->addChild(menu, 8);
	
	charaDraw();			// キャラ表示
	swipeRotation();		// スワイプに合わせて回転
	fontsDraw();			// 文字描画
	objHit();
	this->scheduleUpdate();	// 更新	

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

// 更新
void CharaSelectScene::update(float delta)
{
}

// クリック判定
void CharaSelectScene::clickCheck()
{
	// クリックしたとき
	_listener->onTouchBegan = [&](Touch *touch, Event *event)
	{
		return true;
	};
	// 移動
	_listener->onTouchMoved = [&](Touch *touch, Event *event)
	{
	};
	// 離した
	_listener->onTouchEnded = [&](Touch *touch, Event *event)
	{
	};
	//this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_listener, this);
}

// プレイヤー説明文
void CharaSelectScene::charaText()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();
	// フォント指定
	TTFConfig ttfConfig("fonts/HGRSGU.TTC", FONT_SIZE);
	// 色指定
	auto textColor = Color3B(0,0,50);
	// テキスト
	auto label1 = Label::createWithTTF(ttfConfig,
		"剣一本で多彩な攻撃\n防御を捨ててでも火力をとる\n諸刃の剣士");
	auto label2 = Label::createWithTTF(ttfConfig,
		"魔法で生成した盾で見方を守る\n自らもダメージを受けるが\n仲間を守る唯一無二の盾");
	auto label3 = Label::createWithTTF(ttfConfig,
		"魔法攻撃で敵を攻撃するもよし\n見方を強化してサポートしてもよし\n二つの顔を持つマジシャン");
	auto label4 = Label::createWithTTF(ttfConfig,
		"回復のスペシャリストと思いきや\n敵の弱体化もお任せ\nデバフ系ヒーラー");
	
	// アタッカー
	if (Top == PL_Attacker)
	{
		this->removeChildByTag(PL_TAG);
		// タグ設定
		label1->setTag(PL_TAG);
		label1->setColor(textColor);
		// 座標設定
		label1->setPosition(winSize.width / 2, winSize.height / 2 + TEXT_OFFSET);
		// タグチェック
		if (int tag = label1->getTag() != 1)
		{
			this->addChild(label1, 6);
		}
	}
	// シールド
	else if (Top == PL_Shield)
	{
		this->removeChildByTag(PL_TAG);
		// タグ設定
		label2->setTag(PL_TAG);
		// 色設定
		label2->setColor(textColor);
		// 座標設定
		label2->setPosition(winSize.width / 2, winSize.height / 2 + TEXT_OFFSET);
		// タグチェック
		if (int tag = label2->getTag() != 1)
		{
			this->addChild(label2, 6);
		}
	}
	// 魔法
	else if (Top == PL_Magic)
	{
		this->removeChildByTag(PL_TAG);
		// タグ設定
		label3->setTag(PL_TAG);
		// 色設定
		label3->setColor(textColor);
		// 座標設定
		label3->setPosition(winSize.width / 2, winSize.height / 2 + TEXT_OFFSET);
		// タグチェック
		if (int tag = label3->getTag() != 1)
		{
			this->addChild(label3, 6);
		}

	}
	// 回復
	else if (Top == PL_Healer)
	{
		this->removeChildByTag(PL_TAG);
		// タグ設定
		label4->setTag(PL_TAG);
		// 色設定
		label4->setColor(textColor);
		// 座標設定
		label4->setPosition(winSize.width / 2, winSize.height / 2 + TEXT_OFFSET);
		// タグチェック
		if (int tag = label4->getTag() != 1)
		{
			this->addChild(label4, 6);
		}

	}
	else
	{
		log("ｴﾗｰ起きてますよ");
	}
}

// 文字描画
void CharaSelectScene::fontsDraw()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	// スワイプの動いているとこ
	// 配置文字
	auto swipeLabel = Label::createWithSystemFont("スワイプで動くよ", "fonts/HGRSGU.TTC", 30);
	// 配置場所
	swipeLabel->setPosition(100, 300);
	swipeLabel->setColor(Color3B(200, 150, 0));

	// Select追加
	this->addChild(swipeLabel, 1);
	auto act1 = ScaleTo::create(LIMIT_TIME, DOUBLE_SCALE);   // 0.9秒で0.5倍に拡大
	auto act2 = ScaleTo::create(LIMIT_TIME, 1.0f);			 // 0.9秒で元のサイズに戻す
	swipeLabel->runAction(RepeatForever::create(Sequence::create(act1, act2, NULL)));  //  延々繰り返し

	// 説明文表示
	_listener->onTouchBegan = [&](Touch * touch, Event *event)
	{
		touchPos = touch->getLocation();
		//指定Rect内をクリックしたら説明文表示
		if (pl_rect.containsPoint(touchPos))
		{
			charaText();
			log("説明文たぜ大将！！");
		}
		else if (box_rect.containsPoint(touchPos))
		{
			// チーム編成キャンセルするとき用
			log("チームメンバーが編成されたぜ大将!!");
		}
		else {}
		return true;
	};
	// 移動
	_listener->onTouchMoved = [&](Touch *touch, Event *event)
	{
		this->removeChildByTag(PL_TAG);
	};
	// 離した
	_listener->onTouchEnded = [&](Touch *touch, Event *event)
	{
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_listener, this);
}

// キャラ表示
void CharaSelectScene::charaDraw()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	PL_Attacker = Sprite::create("Player/PL_Attacker.png");
	PL_Shield   = Sprite::create("Player/PL_Shield.png");
	PL_Magic    = Sprite::create("Player/PL_Magic.png");
	PL_Healer   = Sprite::create("Player/PL_Healer.png");

	this->items.clear();
	this->items.push_back(PL_Attacker);
	this->items.push_back(PL_Shield);
	this->items.push_back(PL_Magic);
	this->items.push_back(PL_Healer);
	//this->items.clear();
	//this->items.push_back(Sprite::create("PL_Attacker.png"));
	//this->items.push_back(Sprite::create("PL_Shield.png"));
	//this->items.push_back(Sprite::create("PL_Magic.png"));
	//this->items.push_back(Sprite::create("PL_Healer.png"));

	// 選択されてないもの半透明に
	if (!Top)
	{
		////黒い四角形スプライト
		Sprite* shadowSprite = Sprite::create();
		shadowSprite->setTextureRect(Rect(0.0f, 0.0f, winSize.width, winSize.height));
		shadowSprite->setColor(Color3B::BLACK);
		shadowSprite->setOpacity(200);
		shadowSprite->setPosition(Point(winSize.width / 2, winSize.height / 2));
	}

	// 円状に等間隔で配置
	for (auto& item : items)
	{
		this->addChild(item, 0);
	}
	this->angle = 0.0f;
	this->arrange();

	Box = CCSprite::create("PL_CharFlame01.png");
	Box->setScale(1.5f);
	Box->setPosition(165, 140);
	addChild(Box, 2);
	CCSprite *Box1 = CCSprite::create("PL_CharFlame01.png");
	Box1->setScale(1.5f);
	Box1->setPosition(390, 140);
	addChild(Box1, 2);
	CCSprite *Box2 = CCSprite::create("PL_CharFlame01.png");
	Box2->setScale(1.5f);
	Box2->setPosition(615, 140);
	addChild(Box2, 2);

}

// 当たり判定用
void CharaSelectScene::objHit()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();

	// プレイヤー用のクリック判定用板
	pl_rect   = Rect(0, 0, PL_TEXT_RECT_X, PL_TEXT_RECT_Y);		// 範囲
	pl_square = Sprite::create();								// 生成
	pl_square->setTextureRect(pl_rect);							// テクスチャ指定
	pl_square->setPosition(430, winSize.height / 2);			// 座標配置
	//this->addChild(pl_square);									// 追加

	// プレイヤーのRect取得
	pl_rect = Rect(pl_square->getPosition().x - pl_square->getContentSize().width / 2,
				   pl_square->getPosition().y - pl_square->getContentSize().height / 2,
				   pl_square->getContentSize().width,
				   pl_square->getContentSize().height);

	// チーム編成用枠判定
	box_rect = Rect(Box->getPosition().x - Box->getContentSize().width,
					Box->getPosition().y - Box->getContentSize().height,
					Box->getContentSize().width,
					Box->getContentSize().height);


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

		this->items.at(i)->setPosition(Vec2(x+ PL_POS_OFFSET_X, y+ PL_POS_OFFSET_Y));
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

// スワイプに合わせて回転
void CharaSelectScene::swipeRotation()
{
	// スワイプに合わせて回転
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	// クリックしたとき
	listener->onTouchBegan = [](Touch *touch, Event *event) { return true; };
	// 移動量[スワイプ]
	listener->onTouchMoved = [&](Touch *touch, Event *event)
	{
		float delta = touch->getLocation().x - touch->getPreviousLocation().x;
		this->angle += delta;
		this->arrange();
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
		this->arrange();
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

// 背景
void CharaSelectScene::CharaSelectBackGroudn()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	// 背景画像追加
	Sprite* backImage = Sprite::create("BackImage/ST_CharSerect2.png");
	// 配置座標
	backImage->setPosition(winSize.width / 2, winSize.height / 2);
	// 追加
	this->addChild(backImage);
}

// Clickしたらデータ入れるよ
//void CharaSelectScene::CharaClick()
//{
//	// どれが一番前にいるのかを分かるように調べよう→暗くする処理楽だよ
//	// 0123にそろえましょうか　//static_cast<CharaData>(1234のやつ-1);
//
//	if(Top)
//	{
//	// ここら辺の範囲2かいタップしたら
//		int i = 0;
//		for (i = 0; i < items.size(); i++)
//		{
//			// 
//			if (items[i] == Top)
//			{
//				break;
//			}
//			// 追加
//			CharaData.push_back(static_cast<CharaName> (i));
//		}
//			// 選択外の者は暗くする
//				if (!Top)
//				{
//
//					/*タップした奴　拡大率で今前のやつを判断
//
//					その番号をpushback*/
//					//push_back
//					CharaData.push_back;
//				}
//	};
//}

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
	Scene *pScene = GameOver::createScene();

	// 0.6秒かけて次画面に遷移
	// (時間,遷移先,色(オプション))
	TransitionFade *transition = TransitionFade::create(WAIT_TIME, pScene);

	// 遷移実行 アニメーション
	Director::getInstance()->replaceScene(transition);
}

/*　URL
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


http://vivi.dyndns.org/blog/archives/605
https://freegame-mugen.jp/roleplaying/game_6860.html
https://qiita.com/s0hno/items/739b8da8d0ee1375c2cd


*/
