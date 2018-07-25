#include "CharaSelectScene.h"
#include "FightScene.h"
#include "GameOver.h"
#include "TitleScene.h"
#include "Global.h"
#include "Imput.h"
#include <algorithm>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

#pragma execution_character_set("utf-8")

const int DIV_NUM		  = 4;
const int DIV_ANGLE		  = 360 / DIV_NUM;
const int DIV_ANGLE_HALF  = DIV_ANGLE / 2;

const unsigned int PL_TAG				= 101;		// プレイヤー切り替え用タグ
const unsigned int TEXT_OFFSET			= 510;		// text表示のオフセット値
const unsigned int FAST_CLICK			= 1;		// 初めのclick
const unsigned int SECOND_CLICK			= 2;		// 2回目click
const unsigned int TEAM_MEMBER			= 3;		// チームの人数

const unsigned int NEXT_BUTTON_X		= 660;		// 次の画面遷移へのボタンの配置座標X
const unsigned int NEXT_BUTTON_Y		= 65;		// 次の画面遷移へのボタンの配置座標Y

const unsigned int FONT_SIZE			= 38;		// プレイヤー説明文用の文字ｻｲｽﾞ
const unsigned int PL_TEXT_RECT_X		= 250;		// プレイヤー用の板の配置位置X
const unsigned int PL_TEXT_RECT_Y		= 750;		// プレイヤー用の板の配置位置Y
const unsigned int TEAM_BOX_X			= 165;		// チーム編成用のboxの配置位開X
const unsigned int TEAM_BOX_Y			= 180;		// チーム編成用のboxの配置位置Y
const unsigned int TEAM_BOX_OFFSET_X	= 225;		// チーム編成用のboxのオフセット
const unsigned int PLAYER_NAME_WIDTH	= 210;

// 角度関係で使うよ
const int RADIUS						= 200;
const float PI							= 3.14159265359f;
const float FLATTEN_RATE				= 0.4f;
const unsigned int PL_POS_OFFSET_X		= 420;				// プレイヤー表示のオフセット
const unsigned int PL_POS_OFFSET_Y		= 820;				// プレイヤー表示のオフセット
// 拡縮用
const float LIMIT_TIME					= 0.9f;				// 秒指定[戻る際]
const float DOUBLE_SCALE				= 0.5f;				// 何倍か[拡大率指定]
const float WAIT_TIME					= 0.6f;				// 待機時間
const float BOX_SCALE					= 1.2;				// チーム編成用のBOXの拡大率

const float SOUND_VOLUME				= 0.5f;				// BGM音量調整

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
	auto _buttunNext = MenuItemImage::create("UI/Command/UI_Button_Next.png", "UI/Command/UI_Button_Next.png", CC_CALLBACK_1(CharaSelectScene::pushStart, this));
	_buttunNext->setPosition(NEXT_BUTTON_X+30, NEXT_BUTTON_Y);		// 座標指定
	_buttunNext->setScale(0.5);										// 大きさ調整

	auto menu1 = Menu::create(_buttunNext, NULL);					// メニュー作成(自動obj)
	menu1->setPosition(Point::ZERO);								// 座標配置
	this->addChild(menu1, 8);										// 追加

	auto _buttunBack = MenuItemImage::create("UI/Command/UI_Button_Back.png", "UI/Command/UI_Button_Back.png", CC_CALLBACK_1(CharaSelectScene::backStart, this));
	_buttunBack->setPosition(NEXT_BUTTON_X - 550, NEXT_BUTTON_Y);	// 座標指定
	_buttunBack->setScale(0.5);										// 大きさ調整	

	auto menu2 = Menu::create(_buttunBack, NULL);					// メニュー作成(自動obj)
	menu2->setPosition(Point::ZERO);								// 座標配置
	this->addChild(menu2, 8);										// 追加

	// touchイベント
	auto touchEventGet = EventListenerTouchOneByOne::create();
	touchEventGet->onTouchBegan = CC_CALLBACK_2(CharaSelectScene::TouchBegan, this);
	touchEventGet->onTouchMoved = CC_CALLBACK_2(CharaSelectScene::TouchMove, this);
	touchEventGet->onTouchEnded = CC_CALLBACK_2(CharaSelectScene::TouchEnd, this);
	// 登録
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchEventGet, this);
	
	//Sound();
	TeamBoxDraw();			// 表示(キャラ以外)
	CharaDraw();			// キャラ表示
	SwipeRotation();		// スワイプに合わせて回転
	ObjHit();				// 当たり判定
	this->scheduleUpdate();	// 更新	

	CharaData.reserve(TEAM_MEMBER);	// 事前に領域確保[チームの人数分]
	return true;
}

// 押した瞬間
bool CharaSelectScene::TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	_touchPos = touch->getLocation();

	return true;
}
// スワイプ中
void CharaSelectScene::TouchMove(cocos2d::Touch* touch, cocos2d::Event* event)
{
	this->removeChildByTag(PL_TAG);
	_clickCnt = 0;						// 動いているときはカウントしない
	// スワイプ中には板は表示しない
	if (_s_fontBoard->isVisible())
	{
		_s_fontBoard->setVisible(false);
	}	
}
// 離した瞬間
void CharaSelectScene::TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event)
{
	_touchPos = touch->getLocation();
	Top->pause();

	//指定Rect内をクリックしたら説明文表示
	if (_r_pl_rect.containsPoint(_touchPos))
	{
		_clickCnt += 1;
		
		if (_clickCnt > FAST_CLICK)
		{
			_s_fontBoard->setVisible(true);	// 説明文の板表示
			CharaText();					// キャラ説明文
		}
		if (_clickCnt > SECOND_CLICK)
		{
			AddTeam();						// チーム追加用
			_clickCnt = FAST_CLICK;
		}
	}
	else
	{
		_s_fontBoard->setVisible(false);	// 説明文の板非表示
	}
}

// チーム編成表示
void CharaSelectScene::CharaSeveData()
{
	// CahraDataの読み取る
	
}

// 更新
void CharaSelectScene::Update(float delta)
{
}

// キャラ表示
void CharaSelectScene::CharaDraw()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	_s_Attacker = Sprite::create("Player/PL_Attacker.png");
	_s_Shield   = Sprite::create("Player/PL_Shield.png");
	_s_Magic    = Sprite::create("Player/PL_Magic.png");
	_s_Healer   = Sprite::create("Player/PL_Healer.png");

	this->items.clear();
	this->items.push_back(_s_Attacker);
	this->items.push_back(_s_Shield);
	this->items.push_back(_s_Magic);
	this->items.push_back(_s_Healer);
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
	this->Arrange();
}

// プレイヤー説明文
void CharaSelectScene::CharaText()
{
	// 追加でプレイヤーの役割も追加してほしいな
	// Labelは2個で　1つはキャラの説明文,1つはキャラ名表示用

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

	auto plName1 = Label::createWithTTF(ttfConfig, "剣士");
	auto plName2 = Label::createWithTTF(ttfConfig, "騎士");
	auto plName3 = Label::createWithTTF(ttfConfig, "魔術師");
	auto plName4 = Label::createWithTTF(ttfConfig, "聖職者");

	// アタッカー
	if (Top == _s_Attacker)
	{
		this->removeChildByTag(PL_TAG);
		// タグ設定
		label1->setTag(PL_TAG);
		label1->setColor(textColor);
		label1->setPosition(winSize.width / 2, winSize.height / 2 + TEXT_OFFSET);
		// タグ設定
		plName1->setTag(PL_TAG);
		plName1->setColor(textColor);
		plName1->setScale(0.9);
		plName1->setPosition(winSize.width / 2- PLAYER_NAME_WIDTH, winSize.height / 2 + TEXT_OFFSET-100);
		// タグチェック
		if (int tag = label1->getTag() != 1)
		{
			this->addChild(label1 ,6);
			this->addChild(plName1,6);
		}
	}
	// シールド
	else if (Top == _s_Shield)
	{
		this->removeChildByTag(PL_TAG);
		// タグ設定
		label2->setTag(PL_TAG);
		label2->setColor(textColor);
		label2->setPosition(winSize.width / 2, winSize.height / 2 + TEXT_OFFSET);
		// タグ設定
		plName2->setTag(PL_TAG);
		plName2->setColor(textColor);
		plName2->setScale(0.9);
		plName2->setPosition(winSize.width / 2 - PLAYER_NAME_WIDTH, winSize.height / 2 + TEXT_OFFSET - 100);
		if (int tag = label2->getTag() != 1)
		{
			this->addChild(label2 , 6);
			this->addChild(plName2, 6);
		}
	}
	// 魔法
	else if (Top == _s_Magic)
	{
		this->removeChildByTag(PL_TAG);
		// タグ設定
		label3->setTag(PL_TAG);
		label3->setColor(textColor);
		label3->setPosition(winSize.width / 2, winSize.height / 2 + TEXT_OFFSET);
		// タグ設定
		plName3->setTag(PL_TAG);
		plName3->setColor(textColor);
		plName3->setScale(0.9);
		plName3->setPosition(winSize.width / 2 - PLAYER_NAME_WIDTH, winSize.height / 2 + TEXT_OFFSET - 100);
		// タグチェック
		if (int tag = label3->getTag() != 1)
		{
			this->addChild(label3 , 6);
			this->addChild(plName3, 6);
		}

	}
	// 回復
	else if (Top == _s_Healer)
	{
		this->removeChildByTag(PL_TAG);
		// タグ設定
		label4->setTag(PL_TAG);
		label4->setColor(textColor);
		label4->setPosition(winSize.width / 2, winSize.height / 2 + TEXT_OFFSET);
		// タグ設定
		plName4->setTag(PL_TAG);
		plName4->setColor(textColor);
		plName4->setScale(0.9);
		plName4->setPosition(winSize.width / 2 - PLAYER_NAME_WIDTH, winSize.height / 2 + TEXT_OFFSET - 100);
		// タグチェック
		if (int tag = label4->getTag() != 1)
		{
			this->addChild(label4 , 6);
			this->addChild(plName4, 6);
		}
	}
	else
	{
		log("ｴﾗｰ起きてますよ");
	}
}

// 表示 チーム編成の箱
void CharaSelectScene::TeamBoxDraw()
{
	_batchNode = SpriteBatchNode::create("UI/PL_CharFlame01.png");
	_batchNode->setPosition(TEAM_BOX_OFFSET_X, 0);

	// チーム編成のBox分表示
	for (int n = 0; n<TEAM_MEMBER; n++)
	{
		//batchNodeからテクスチャを取得
		_ccp_Box = Sprite::createWithTexture(_batchNode->getTexture());
		_ccp_Box->setScale(BOX_SCALE);
		
		_ccp_Box->setPosition((TEAM_BOX_X+16)*n, (TEAM_BOX_Y));

		//SpriteBatchNodeに貼り付け
		_batchNode->addChild(_ccp_Box);
	}
	this->addChild(_batchNode);
}

// チームメンバー表示
void CharaSelectScene::TeamDraw()
{
	// CharaDataのデータを参照して画像を表示
	auto data0 = CharaData.at(0);
	auto data1 = CharaData.at(1);
	auto data2 = CharaData.at(2);

	// enumと関連つけたいよね～
	Sprite *_s_teamAttacker = Sprite::create("Player/PL_Attacker_face.png");
	Sprite *_s_teamSHIELD	= Sprite::create("Player/PL_Shield_face.png");
	Sprite *_s_teamMAGIC	= Sprite::create("Player/PL_Magic_face.png");
	Sprite *_s_teamHEALER	= Sprite::create("Player/PL_Healer_face.png");

}

// 背景
void CharaSelectScene::CharaSelectBackGroudn()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	
	// 背景画像追加
	Sprite* _backImage = Sprite::create("BackImage/ST_CharSerect2.png");
	_backImage->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(_backImage,0);

	//説明文の板配置
	_s_fontBoard = Sprite::create("UI/Status/UI_Status_Inters.png");
	_s_fontBoard->setPosition(winSize.width / 2, 1130);
	addChild(_s_fontBoard, 1);
}

// 当たり判定用
void CharaSelectScene::ObjHit()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();

	// プレイヤー用のクリック判定用板
	_r_pl_rect   = Rect(0, 0, PL_TEXT_RECT_X, PL_TEXT_RECT_Y);	// 範囲
	_s_pl_square = Sprite::create();								// 生成
	_s_pl_square->setTextureRect(_r_pl_rect);						// テクスチャ指定
	_s_pl_square->setPosition(430, winSize.height / 2);			// 座標配置
	//this->addChild(pl_square);								// 追加

	// プレイヤークリック判定範囲
	_r_pl_rect = Rect(_s_pl_square->getPosition().x - _s_pl_square->getContentSize().width /  2,
				    _s_pl_square->getPosition().y - _s_pl_square->getContentSize().height / 2,
				    _s_pl_square->getContentSize().width,
				    _s_pl_square->getContentSize().height);

	// No.1当たり判定をきちんとチーム編成の分きちんと対応させる
	// なんかうまくいってないからよろしく丸
	_r_box_rect = Rect(0, 0, _ccp_Box->getContentSize().width * BOX_SCALE, _ccp_Box->getContentSize().height * BOX_SCALE);	// 範囲
	for (int i = 0; i< 3;i++)
	{
		_ccp_Box = Sprite::create();													// 生成
		_ccp_Box->setTextureRect(_r_box_rect);											// テクスチャ指定
		_ccp_Box->setPosition((TEAM_BOX_X + 16)*i + TEAM_BOX_OFFSET_X, (TEAM_BOX_Y));	// 座標配置
		//this->addChild(_Box);
	}
}

// アレンジ　回転とか
void CharaSelectScene::Arrange()
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

		this->items.at(i)->setPosition(Vec2(x+ PL_POS_OFFSET_X, y+ PL_POS_OFFSET_Y + 20));
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
void CharaSelectScene::SwipeRotation()
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
		this->Arrange();
	};
	// 離した
	listener->onTouchEnded = [&](Touch *touch, Event *event)
	{
		// No.2 SwipeRotation内の離した,押した処理を押した,離した特化の関数内に入れるのか

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
		this->Arrange();
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

// キャラ情報取得
const std::vector<CharaName>& CharaSelectScene::GetCharaData()
{
	return CharaData;
}

// チーム追加用
void CharaSelectScene::AddTeam()
{
	int i = 0;
	for (i = 0; i < items.size(); i++)
	{
		if (items[i] != Top)
		{
			continue;
		}
		CharaData.push_back(static_cast<CharaName> (i));
		log("追加されました。%d", i);
		// 例外処理入れてね　おんなじキャラ選べないとか
		if (CharaData.size() == TEAM_MEMBER)
		{
			log("メンバーが揃いました", CharaData);
			TeamDraw();		
			break;
		}
	}
	//// チーム編成の箱をクリックしたとき[第一範囲]
	//if (_box_rect.containsPoint(_touchPos))
	//{
	//	// チーム編成キャンセル
	//	//if (_clickCnt > 2)
	//	{
	//		log("メンバー編成し直したぜ大将!!");
	//		// No.4 clickされたキャラをCharaDataから消す
	//		// 横に(←)詰める
	//	}
	//}
}

// BGM
void CharaSelectScene::Sound()
{
	// あとでSoundManagerやら作ってやり直してね
	// 音楽ファイルの読み込み
	auto _sound = SimpleAudioEngine::getInstance();
	_sound->setBackgroundMusicVolume(SOUND_VOLUME);
	_sound->preloadBackgroundMusic("BGM/BGM_PartyCreate_Main.mp3");

	_sound->playBackgroundMusic("BGM/BGM_PartyCreate_Main.mp3", true);
}

// 次画面遷移
void CharaSelectScene::pushStart(Ref * pSender)
{
	CCLOG("Pushボタン");

	// 遷移策の画面をｲﾝｽﾀﾝｽ
	Scene *pScene = FightScene::createScene();

	// 0.6秒かけて次画面に遷移(時間,遷移先,色(オプション))
	TransitionFade *transition = TransitionFade::create(WAIT_TIME, pScene);

	// 遷移実行 アニメーション
	Director::getInstance()->replaceScene(transition);
}
// 前画面遷移
void CharaSelectScene::backStart(Ref * pSender)
{
	CCLOG("Pushボタン");

	// 遷移策の画面をｲﾝｽﾀﾝｽ
	Scene *pScene = TitleScene::createScene();

	// 0.6秒かけて次画面に遷移 (時間,遷移先,色(オプション))
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

// コインエフェクト表現
http://takachan.hatenablog.com/entry/2017/08/28/213842

// 文字描画
void CharaSelectScene::FontsDraw()
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
}

*/
