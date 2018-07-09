#ifndef __Screen__TitleScene__
#define __Screen__TitleScene__

#include "cocos2d.h"

USING_NS_CC;

class TitleScene :public cocos2d::Layer
{
public:
	float angle;
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(TitleScene);
	std::vector<cocos2d::Node *> items;
	void TitleBackGroudn();

	// スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
	void pushStart(Ref *pSender);

private:
	int nowSelect;					// 現在選ばれている番号
	unsigned int _clickCnt = 0;		// クリック回数を保存
	Node* Top;						// 最前にあるものの情報
	// 行動パターン情報
	Sprite *_Attack;				// 攻撃
	Sprite *_Defence;				// 防御
	Sprite *_Item;					// アイテム
	Sprite *_Skill;					// スキル

	// 当たり判定用
	Vec2 _touchPos;					// 現在座標
	Rect _swipeRect;				// スワイプ用の判定範囲
	Rect _clickButtunRect;			// ボタンのクリック判定
	Sprite *_swipe;					// スワイプ用スプライト
	Sprite *_clickButton;			// クリック用スプライト
	Sprite *_ChoiceSkill;			// 選択スキル

	void ActSelectDraw();						// 表示
	void Arrange(const Vec2 _pos);				// 角度調整
	void Arrange(const Vec2 _pos, std::vector<Node*>& _sprite, const int _upSideCnt, const int _drawCnt, const float _defaultScale, const float _diffScale, const GLubyte _defaultOpacity, const GLubyte _diffOpacity, const Vec2 _offset);										// (配置座標,スプライト,上に表示する数,総表示数,通常拡大率,拡大率,通常透過,透過,X軸への広がり)
	void SwipeRotation();						// 回転
	void SwipeRotation(const float roleYDist);	// 回転
	void RectDraw(const unsigned int x, const unsigned int y, const unsigned int _width, const unsigned int _height, const int posX, const int posY);		// 四角描画用(X,Y,幅,高さ,配置座標)
	void ObjHit();								// 当たり判定用
	void TouchArrange(Touch* _touch);			// タッチしたところエフェクト

	// touchイベント
	bool TouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);	// 押した瞬間
	void TouchMove(cocos2d::Touch* touch, cocos2d::Event* event);	// スワイプ中
	void TouchEnd(cocos2d::Touch* touch, cocos2d::Event* event);	// 離した瞬間
	EventListenerTouchOneByOne *_listener = EventListenerTouchOneByOne::create();
};

#endif // Title

/*
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

const unsigned int BUTTON_POS_X	   = 50;		// ボタンの配置座標X
const unsigned int BUTTON_POS_Y    = 1200;		// ボタンの配置座標Y

// タッチ語のイベント用
const float DELETE				   = 1.5f;		//
const unsigned int TOUCH_RADIUS    = 25;		//

// アレンジ用
const Vec2 POS = Vec2(410, 650);	// 配置座標
const int UPSIDECNT				= 3;						// 上に表示する個数
const int DRAWCNT				= 6;						// 表示する個数(総数)
const float DEFAULT_SCALE		= 1.f;						// 通常拡大率
const float DIFF_SCALE			= 0.15f;					// 拡大率
const GLubyte DEFAULT_OPACITY	= 255;						// 通常不透明度
const GLubyte DIFF_OPACITY		= 0;						// 不透明度
const Vec2 OFFSET				= Vec2(0, -100);			// オフセット(横へのひろがりかえれるよ)
const float ROLE_Y_DIST			= 80.f;						// 回転する際の移動量(数字を大きくすると余計に動く)



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
	//Arrange(POS, items, UPSIDECNT, DRAWCNT, DEFAULT_SCALE, DIFF_SCALE, DEFAULT_OPACITY, DIFF_SCALE, OFFSET);
	Arrange();
	ObjHit();

	//RectDraw(0, 0, 280, 100, 410, 650);
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
	TouchArrange(touch);
	_touchPos = touch->getLocation();
	if (_swipeRect.containsPoint(_touchPos))
	{
		_clickCnt += 1;
		if (_clickCnt > 1)
		{
			//Arrange(Vec2(800, PL_POS_OFFSET_Y), items, UPSIDECNT, DRAWCNT, DEFAULT_SCALE, DIFF_SCALE, DEFAULT_OPACITY, DIFF_SCALE, Vec2(0, -100));
		}
		//Arrange(Vec2(PL_POS_OFFSET_X, PL_POS_OFFSET_Y), items, UPSIDECNT, DRAWCNT, DEFAULT_SCALE, DIFF_SCALE, DEFAULT_OPACITY, DIFF_SCALE, Vec2(0, -100));
	}
	return true;
}

// スワイプ中
void TitleScene::TouchMove(cocos2d::Touch* touch, cocos2d::Event* event)
{
	//TouchArrange(touch);
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

void TitleScene::Arrange()
{

	// 円状に等間隔で配置
	float theta = 360.0f / items.size() + (items.size() / 2);
	float baseAngle = this->angle + 270.0f;							// 加算すると円の奥行増えるよ
	for (int i = 0; i < items.size(); i++)
	{
		// 270 度の位置が正面にくるように
		float angle = theta   * i + baseAngle;
		float radians = angle   * PI / 180.0f;
		float x = RADIUS  * cos(radians);
		float y = RADIUS  * sin(radians) * FLATTEN_RATE;	// 円の角度斜めにするよ
		float radiusY = RADIUS  * FLATTEN_RATE;
		float diameterY = radiusY * 2;
		float scale = (diameterY - y) / diameterY;				// y座標に応じて変化するよ
		GLubyte opacity = 255 - (y + radiusY);

		this->items.at(i)->setPosition(Vec2(x + PL_POS_OFFSET_X, y + PL_POS_OFFSET_Y + 20));
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
// アレンジ()
void TitleScene::Arrange(const Vec2 _pos, std::vector<Node*>& _sprite, const int _upSideCnt, const int _drawCnt, const float _defaultScale, const float _diffScale, const GLubyte _defaultOpacity, const GLubyte _diffOpacity, const Vec2 _offset)
{
	float tmp, tmp2;
	// 実数値を整数部分と小数部分に分ける
	auto tmpAngle = modf(angle, &tmp);
	tmpAngle = modf(tmpAngle, &tmp2);
	tmpAngle = -tmpAngle;
	// 小数を切り捨て型キャスト
	auto j = static_cast<int>(tmp) % _sprite.size();

	//
	for (int i= -_upSideCnt; i < _drawCnt - _upSideCnt; ++i)
	{
		// 総枚数　% 総枚数= 現在の番号わかる
		auto index = ((i + j) + _sprite.size()) % _sprite.size();
		//
		_sprite[index]->setPosition(POS + Vec2(OFFSET.x * abs(i) , OFFSET.y * (i)));
		//
		//_sprite[index]->setScale(_defaultScale - (abs(i) * _diffScale));
		_sprite[index]->setScale(i == 0 ? _defaultScale : _defaultScale - _diffScale);
		//
		_sprite[index]->setOpacity(_defaultOpacity - (abs(i) * _diffOpacity));
		//
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

// スワイプ(回転速度)
void TitleScene::SwipeRotation()
{
	// スワイプに合わせて回転
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	// クリックしたとき
	listener->onTouchBegan = [](Touch *touch, Event *event) { return true; };
	// 移動量[スワイプ]
	listener->onTouchMoved = [](Touch *touch, Event *event)
	{
		float delta = touch->getLocation().y - touch->getPreviousLocation().y;
		angle += delta;
		//Arrange(POS, items, UPSIDECNT, DRAWCNT, DEFAULT_SCALE, DIFF_SCALE, DEFAULT_OPACITY, DIFF_SCALE, OFFSET);
		Arrange();
	};

	// 離した
	listener->onTouchEnded = [](Touch *touch, Event *event)
	{
		this->angle = roundf(this->angle);
		//Arrange(POS, items, UPSIDECNT, DRAWCNT, DEFAULT_SCALE, DIFF_SCALE, DEFAULT_OPACITY, DIFF_SCALE, OFFSET);
		Arrange();
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

// 当たり判定用範囲
void TitleScene::ObjHit()
{
	//画像サイズ取得
	Size winSize = Director::getInstance()->getWinSize();

	// 選択画面範囲
	_swipeRect = Rect(0, 0, 280, 100);
	_swipe = Sprite::create();
	_swipe->setTextureRect(_swipeRect);
	_swipe->setPosition(410, 650);

	_swipeRect = Rect(_swipe->getPosition().x - _swipe->getContentSize().width / 2,
					  _swipe->getPosition().y - _swipe->getContentSize().height / 2,
					  _swipe->getContentSize().width,
					  _swipe->getContentSize().height);
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

// タッチしたところエフェクト
void TitleScene::TouchArrange(Touch* _touch)
{
	// http://takachan.hatenablog.com/entry/2018/02/27/010443
	_touchPos = _touch->getLocation();
	// 矩形描画
	DrawNode* _circle = DrawNode::create();
	// drawDots(描く個数分の中心座標を含む配列, 半径, 色);
	_circle->drawDot(Vec2::ZERO, TOUCH_RADIUS, Color4F(1.0f, 1.0f, 1.0f, 1.0f));
	// 配置座標
	_circle->setPosition(_touchPos);

	Sprite *_effect = Sprite::create("effect_cure01_0001.png");
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
	// 実行
	_effect->runAction(seq);
	// 追加
	this->addChild(_effect, 10);
}
*/