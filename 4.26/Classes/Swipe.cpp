#include "Swipe.h"
#include "CharaSelectScene.h"
#include <algorithm>
#include "cocos2d.h"

#pragma execution_character_set("utf-8")

const int DIV_NUM = 4;
const int DIV_CIRCLE = 360;
const int DIV_ANGLE = DIV_CIRCLE / DIV_NUM;
const int DIV_ANGLE_HALF = DIV_ANGLE / 2;

// 角度調整
const unsigned int RADIUS = 150;				// 円の広がり
const float PI = 3.14159265359f;
const float FLATTEN_RATE = 0.1f;				// 奥行
const unsigned int PL_POS_OFFSET_Y = 400;		// プレイヤー表示のオフセット
const unsigned int PL_POS_OFFSET_X = 600;		// プレイヤー表示のオフセット
// 拡大幅
const float LIMIT_TIME = 0.9f;				// 秒指定[戻る際]
const float DOUBLE_SCALE = 0.5f;				// 何倍か[拡大率指定]
const float WAIT_TIME = 0.6f;				// 待機時間
const float BOX_SCALE = 0.9;				// チーム編成用のBOXの拡大率

const unsigned int BUTTON_POS_X = 50;				// ボタンの配置座標X
const unsigned int BUTTON_POS_Y = 1200;				// ボタンの配置座標Y

													// タッチ語のイベント用
const float DELETE = 1.5f;
const unsigned int TOUCH_RADIUS = 25;

// アレンジ用
const int SCALE = 5;					// 引数(座標)用のスケール
const int UPSIDECNT = 3;					// 上に表示する個数
const int DRAWCNT = 6;					// 表示する個数(総数)
const float DEFAULT_SCALE = 1.f;					// 通常拡大率
const float DIFF_SCALE = 0.15;					// 拡大率0.15
const float ROLE_Y_DIST = 0.05f;				// 回転する際の移動量(数字を大きくすると余計に動く)
const GLubyte DEFAULT_OPACITY = 255;					// 通常不透明度			
const GLubyte DIFF_OPACITY = 0;					// 不透明度
const Vec2 POS = Vec2(600, 650);		// 配置座標410、650
const Vec2 OFFSET = Vec2(0, -100);		// オフセット(横へのひろがりかえれるよ)

										// 中心
const Vec2 POS2 = Vec2(410, 650);		// 配置座標410、650
const Vec2 POS3 = Vec2(5, 650);		// click後初めの方_配置座標410、650　
const Vec2 POS4 = Vec2(40, 650);		// 変更後の座標
const Vec2 POSKILL = Vec2(490, 550);		// 配置座標410、650		スキル用のやつ


											// 実態生成
std::vector<SelectName> Swipe::SelectData;

Scene *Swipe::createScene()
{
	auto scene = Scene::create();
	auto layer = Swipe::create();
	scene->addChild(layer);
	return scene;
}

// 初期化
bool Swipe::init()
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
	auto startButton = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(Swipe::pushStart, this));

	// ボタンの配置
	startButton->setPosition(BUTTON_POS_X, BUTTON_POS_Y);
	// メニュー作成(自動obj)
	auto menu = Menu::create(startButton, NULL);
	menu->setPosition(Point::ZERO);
	// 追加
	this->addChild(menu, 1);

	flag = false;

	TestPLDraw();			// 仮ボス表示(後で消しておいてよ)
	ActSelectDraw();		// キャラ表示
	SwipeRotation();		// スワイプに合わせて回転
	ObjHit();				// 当たり判定用
	Arrange(POS2);

	// touchイベント
	auto touchEventGet = EventListenerTouchOneByOne::create();
	touchEventGet->onTouchBegan = CC_CALLBACK_2(Swipe::TouchBegan, this);
	touchEventGet->onTouchMoved = CC_CALLBACK_2(Swipe::TouchMove, this);
	touchEventGet->onTouchEnded = CC_CALLBACK_2(Swipe::TouchEnd, this);

	// 登録
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchEventGet, this);



	return true;
}

// 仮ボス表示
void Swipe::TestPLDraw()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();

	Sprite *Boss = Sprite::create("Enemy/EM_Valkyrie.png");
	Boss->setPosition(winSize.width / 2, winSize.height / 2 + 100
	);
	addChild(Boss, 2);
}

// 押した瞬間
bool Swipe::TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	_touchPos = touch->getLocation();
	TouchArrange(touch);

	_pushCnt++;

	//if (_clickButtunRect.containsPoint(_touchPos))
	{
		// ボタンをクリックされたら選択肢によって変わる
		if (_pushCnt>1)
		{
			int i = 0;
			for (i = 0; i<selects.size(); i++)
			{
				if (selects[i] != Top)
				{
					break;
				}
				// 追加
				SelectData.push_back(static_cast<SelectName> (i));
			}
			_pushCnt = 0;
		}
	}
	return true;
}

// スワイプ中
void Swipe::TouchMove(cocos2d::Touch* touch, cocos2d::Event* event)
{
}

// 離した瞬間
void Swipe::TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event)
{
	_touchPos = touch->getLocation();

	_clickCnt++;

	if (_clickCnt>2)
	{
		if (_r_clickButtunRect.containsPoint(_touchPos))
		{
			SelectMove();		// 何選択したか

								// Arrange1の座標をPOS3の座標に変更
								// Arrange2の表示
								// Arrange1のスワイプを切る
		}
		_clickCnt = 0;
	}
}

// 行動選択表示
void Swipe::ActSelectDraw()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	_s_Attack = Sprite::create("UI/Command/UI_Button_Attack01.png");
	_s_Defence = Sprite::create("UI/Command/UI_Button_Defence01.png");
	_s_Item = Sprite::create("UI/Command/UI_Button_Item01.png");
	_s_Skill = Sprite::create("UI/Command/UI_Button_Skill01.png");

	this->items.clear();
	this->items.push_back(_s_Attack);
	this->items.push_back(_s_Defence);
	this->items.push_back(_s_Item);
	this->items.push_back(_s_Skill);

	// 配置
	for (auto& item : items)
	{
		this->addChild(item, 0);
	}
	this->angle = 0.0f;
}

// スキル表示
void Swipe::SkillDraw()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	// マルチれぞーしょん対応か
	Point origin = Director::getInstance()->getVisibleOrigin();

	_s_Top = Sprite::create("UI/Status/UI_Button_Choice01.png");
	_s_Belpw = Sprite::create("UI/Status/UI_Button_Wait01.png");
	_s_Belpw1 = Sprite::create("UI/Status/UI_Button_Wait01.png");
	_s_Belpw2 = Sprite::create("UI/Status/UI_Button_Wait01.png");

	this->selects.clear();
	this->selects.push_back(_s_Top);
	this->selects.push_back(_s_Belpw);
	this->selects.push_back(_s_Belpw1);
	this->selects.push_back(_s_Belpw2);

	// 配置
	for (auto& item : selects)
	{
		this->addChild(item, 0);
	}
	this->angle = 0.0f;
}

// 選択画面
void Swipe::SelectMove()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();

	// 攻撃
	if (Top == _s_Attack)
	{
		log("攻撃");
		flag = false;
	}
	// 防御
	else if (Top == _s_Defence)
	{
		log("防御");
		flag = false;
	}
	// アイテム
	else if (Top == _s_Item)
	{
		log("アイテム");
		flag = false;
	}
	// 
	else if (Top == _s_Skill)
	{
		flag = true;
		SkillDraw();		// スキル一覧表示
		SwipeRotation(ROLE_Y_DIST);
		Arrange(POSKILL, selects, UPSIDECNT, DRAWCNT, DEFAULT_SCALE, DIFF_SCALE, DEFAULT_OPACITY, DIFF_SCALE, OFFSET);
		log("スキル一覧表示します");
	}
	// 何もなし
	else
	{
		log("ｴﾗｰ起きていますよ");
	}
}

// アレンジ1(配置座標)
void Swipe::Arrange(const Vec2 _pos)
{	// 縦に回るようなの
	float theta = 360.0f / items.size() + (items.size() / 2);
	float baseAngle = this->angle;									// 加算すると円の奥行増えるよ

	for (int i = 0; i < items.size(); i++)
	{
		// 270 度の位置が正面にくるように  
		float angle = theta   * i + baseAngle;
		float radians = angle   * PI / 180.0;
		float x = RADIUS  * cos(radians);
		float y = RADIUS  * sin(radians) * FLATTEN_RATE;	// 円の角度斜めにするよ
		float radiusY = RADIUS  * FLATTEN_RATE;
		float diameterY = radiusY * 2;
		float scale = (diameterY - y - SCALE) / diameterY;		// y座標に応じて変化するよ
		GLubyte opacity = 255 - (y + radiusY);

		this->items.at(i)->setPosition(Vec2(_pos.x, _pos.y + x));	// 配置座標
		this->items.at(i)->setScale(scale);							// 拡大率
		this->items.at(i)->setOpacity(opacity);						// 不透明度
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

// アレンジ2(配置座標,拡大率,回転角度,全体個数,表示個数)
void Swipe::Arrange(const Vec2 _pos, std::vector<Node*>& _sprite, const int _upSideCnt, const int _drawCnt, const float _defaultScale, const float _diffScale, const GLubyte _defaultOpacity, const GLubyte _diffOpacity, const Vec2 _offset)
{
	float tmp, tmp2;
	// 実数値を整数部分と小数部分に分ける
	auto tmpAngle = modf(angle, &tmp);
	tmpAngle = modf(tmpAngle, &tmp2);
	tmpAngle = -tmpAngle;
	// 小数を切り捨て型キャスト
	auto j = static_cast<int>(tmp) % _sprite.size();
	// 
	for (int i = -_upSideCnt; i < _drawCnt - _upSideCnt; ++i)
	{
		// 総枚数　% 総枚数= 現在の番号わかる
		auto index = ((i + j) + _sprite.size()) % _sprite.size();
		// _pos[表示したい位置] + オフセット　*　絶対値(-2~2) ←こうすることで2,1,0,1,2という風に並ぶ,y座標は-2-1,1,2という風になる
		_sprite[index]->setPosition(_pos + Vec2(OFFSET.x * abs(i), OFFSET.y * (i)));
		// 正面に来た場合のみ指定した拡大ｻｲｽﾞになり,その他は小さくなる
		//_sprite[index]->setScale(_defaultScale - (abs(i) * _diffScale));
		_sprite[index]->setScale(i == 0 ? _defaultScale : _defaultScale - _diffScale);
		// 不透明度
		_sprite[index]->setOpacity(_defaultOpacity - (abs(i) * _diffOpacity));
		// 奥行　表示したい個数 - ｒ
		_sprite[index]->setZOrder(_drawCnt - abs(i));
	}
	//そーとするよ(´・ω・`)
	auto tmpVector = _sprite;
	std::sort(tmpVector.begin(), tmpVector.end(), [](const Node* a, const Node* b)
		// 先に大きいのtrue /　begin > end ←初めに大きいもの来る＝大きい順になる  
	{return a->getScale() > b->getScale(); });
	// TOPに一番多きものが入る
	Top = tmpVector.front();

}

// スワイプ
void Swipe::SwipeRotation()
{
	// スワイプに合わせて回転
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	// クリックしたとき
	listener->onTouchBegan = [](Touch *touch, Event *event)
	{	return true; };
	// 移動量[スワイプ]
	listener->onTouchMoved = [&](Touch *touch, Event *event)
	{
		// スキルが選択されていない場合
		if (flag == false)
		{
			if (_r_swipeRect.containsPoint(_touchPos))
			{
				float delta = touch->getLocation().y - touch->getPreviousLocation().y;
				this->angle += delta;
				Arrange(POS2);
			}
		}
		// スキルが選択されている場合
		else
		{
			//Arrange(POS4);
		}

	};
	// 離した
	listener->onTouchEnded = [&](Touch *touch, Event *event)
	{
		// 正の値
		if (angle > 0.f)
		{
			this->angle = (((((static_cast<int>(this->angle)) + DIV_ANGLE_HALF) % 360) / DIV_ANGLE) * DIV_ANGLE);
		}
		// 負の値
		else
		{
			this->angle = ((((static_cast<int>(this->angle - 360) % 360 - DIV_ANGLE_HALF) % 360) / DIV_ANGLE) * DIV_ANGLE);
		}
		if (flag == false)
		{
			Arrange(POS2);
		}
		else
		{
			Arrange(POS4);
		}
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

// スワイプ(回転する際の移動量(数字を大きくすると余計に動く))
void Swipe::SwipeRotation(const float roleYDist)
{
	// スワイプに合わせて回転
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	// クリックしたとき
	listener->onTouchBegan = [](Touch *touch, Event *event) { return true; };
	// 移動量[スワイプ]
	listener->onTouchMoved = [&, roleYDist](Touch *touch, Event *event)
	{
		float delta = touch->getLocation().y - touch->getPreviousLocation().y;
		this->angle += delta / roleYDist;
		if (flag == true)
		{
			Arrange(POS, selects, UPSIDECNT, DRAWCNT, DEFAULT_SCALE, DIFF_SCALE, DEFAULT_OPACITY, DIFF_SCALE, OFFSET);
		}

	};

	// 離した
	listener->onTouchEnded = [&, roleYDist](Touch *touch, Event *event)
	{
		this->angle = roundf(this->angle);
		if (flag == true)
		{
			Arrange(POS, selects, UPSIDECNT, DRAWCNT, DEFAULT_SCALE, DIFF_SCALE, DEFAULT_OPACITY, DIFF_SCALE, OFFSET);
		}
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

// 当たり判定用範囲
void Swipe::ObjHit()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();

	// スワイプの範囲
	_r_swipeRect = Rect(0, 0, 550, 490);
	_s_swipe = Sprite::create();
	_s_swipe->setTextureRect(_r_swipeRect);
	_s_swipe->setPosition(winSize.width / 2 - 10, winSize.height / 2 - 30);

	_r_swipeRect = Rect(_s_swipe->getPosition().x - _s_swipe->getContentSize().width / 2,
		_s_swipe->getPosition().y - _s_swipe->getContentSize().height / 2,
		_s_swipe->getContentSize().width,
		_s_swipe->getContentSize().height);

	// ボタンのclick用
	_r_clickButtunRect = Rect(0, 0, 490, 180);
	_s_clickButton = Sprite::create();
	_s_clickButton->setTextureRect(_r_clickButtunRect);
	_s_clickButton->setPosition(winSize.width / 2 - 10, winSize.height / 2 - 30);

	_r_clickButtunRect = Rect(_s_clickButton->getPosition().x - _s_clickButton->getContentSize().width / 2,
		_s_clickButton->getPosition().y - _s_clickButton->getContentSize().height / 2,
		_s_clickButton->getContentSize().width,
		_s_clickButton->getContentSize().height);

	// スキルのボタン用

}

// 背景
void Swipe::TitleBackGroudn()
{
	// 画面サイズ取得
	Size winSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// タイトル配置
	// 配置文字
	auto lbl_Title = Label::createWithSystemFont("Title", "HiraKakuProN-W6", 100);
	lbl_Title->setPosition(Point(origin.x + winSize.width / 2,
		origin.y + winSize.height - lbl_Title->getContentSize().height));
	// Title追加
	this->addChild(lbl_Title, 1);

	// 背景画像追加
	Sprite* bgsprite = Sprite::create("BackImage/ST_Boss.png");
	bgsprite->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(bgsprite, 0);
}

const std::vector<SelectName>& Swipe::GetSelectData()
{
	return SelectData;
}

// 画面遷移
void Swipe::pushStart(Ref *pSender)
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
void Swipe::RectDraw(const unsigned int x, const unsigned int y, const unsigned int _width, const unsigned int _height, const int posX, const int posY)
{
	Rect rect = Rect(x, y, _width, _height);
	Sprite *square = Sprite::create();
	square->setTextureRect(rect);
	square->setPosition(posX, posY);
	this->addChild(square, 5);
}

// タッチしたところエフェクト
void Swipe::TouchArrange(Touch* _touch)
{
	// http://takachan.hatenablog.com/entry/2018/02/27/010443
	_touchPos = _touch->getLocation();
	// 矩形描画
	DrawNode* _circle = DrawNode::create();
	// drawDots(描く個数分の中心座標を含む配列, 半径, 色);
	_circle->drawDot(Vec2::ZERO, TOUCH_RADIUS, Color4F(1.0f, 1.0f, 1.0f, 1.0f));
	// 配置座標
	_circle->setPosition(_touchPos);

	Sprite *_effect = Sprite::create("Touch/effect_cure01_0001.png");
	_effect->setPosition(_touchPos);

	// アニメーション追加
	// 拡縮
	ActionInterval* _scale = CCScaleTo::create(DELETE, 5.0f);
	// フェイド時間
	ActionInterval* _fadeMove = CCScaleTo::create(DELETE, 0);
	// 複数アニメーション同時再生
	Spawn* _spawn = CCSpawn::create(_scale, _fadeMove, nullptr);
	// 3秒待機
	auto _time = DelayTime::create(3);
	// 終わったら消す処理
	Sequence* seq = Sequence::create(_spawn, _time, nullptr);
	_effect->runAction(seq);
	this->addChild(_effect, 10);
}