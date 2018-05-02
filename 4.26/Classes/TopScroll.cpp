//#include "ScrollBarView.h"
//
//USING_NS_CC;
//USING_NS_CC_EXT;
//
//// Default size macros
//#define BAR_FIX_SIZE 10.0f
//#define BAR_MIN_SIZE 20.0f
//
//ScrollBarView::ScrollBarView(ScrollView *view, BarType type)
//	:view(view),
//	positionType(type),
//	barFade(true),
//	fadeDelayTime(0.5f),
//	barSize(0.0f)
//{}
//
//ScrollBarView::~ScrollBarView()
//{
//	// Remove and clean scroll bar sprite
//	removeChild(bar);
//	CC_SAFE_DELETE(bar);
//}
//
//
//ScrollBarView* ScrollBarView::create(ScrollView *view, BarType type)
//{
//	ScrollBarView *sc = new ScrollBarView(view, type);
//	if (!sc->init())
//	{
//		CC_SAFE_DELETE(sc);
//		return nullptr;
//	}
//
//	sc->autorelease();
//	return sc;
//}
//
//void ScrollBarView::setBarFade(bool barFade)
//{
//	barFade = barFade;
//}
//
//void ScrollBarView::setBarFadeDelayTime(float fadeDelayTime)
//{
//	fadeDelayTime = fadeDelayTime;
//}
//
//bool ScrollBarView::init()
//{
//	this->setAnchorPoint(Vec2::ZERO);
//	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0)))
//	{
//		return false;
//	}
//
//	float offset;
//	switch (positionType)
//	{
//	case BarType::VERTICAL_IN:
//	case BarType::VERTICAL_OUT:
//		this->initVertical();
//		offset = view->getContentOffset().y;
//		break;
//
//	case BarType::HORIZONTAL_IN:
//	case BarType::HORIZONTAL_OUT:
//		this->initHorizontal();
//		offset = view->getContentOffset().x;
//	}
//
//	bool isVisible = (currentContentSize <= viewFixSize) ? false : true;
//	this->setVisible(isVisible);
//
//	this->addChild(bar);
//
//	setBarScale();
//	setBarPosition(offset);
//
//	// Get scrollview parent node and attach this
//	Node *parent = view->getParent();
//	parent->addChild(this, 1000, 1000); // enough z-order?
//										// Set fade-out queue only once
//	this->scheduleOnce(schedule_selector(ScrollBarView::fadeOut), fadeDelayTime);
//
//	return true;
//}
//
//void ScrollBarView::initVertical()
//{
//	Point position = view->getPosition();
//	// Create 9-patch sprite
//	Rect imageSize = Rect(0, 0, BAR_FIX_SIZE, BAR_MIN_SIZE);
//	Rect insets = Rect(1, 4, 8, 12);
//	bar = Scale9Sprite::create("scrollbar_horizontal.png", imageSize, insets);
//
//	bar->setAnchorPoint(Vec2(0.5f, 0));
//	bar->setPosition(Vec2(bar->getContentSize().width / 2, 0));
//
//	Size size = view->cocos2d::Node::getContentSize();
//	viewFixSize = size.height;
//	currentContentSize = beforeContentSize = view->getContentSize().height;
//
//	// Inner
//	if (positionType == BarType::VERTICAL_IN)
//	{
//		this->setPosition(position.x + size.width - BAR_FIX_SIZE, position.y);
//	}
//	// Outer
//	else
//	{
//		this->setPosition(position.x + size.width, position.y);
//	}
//}
//
//void ScrollBarView::initHorizontal()
//{
//	Point position = view->getPosition();
//	// Create 9-patch sprite
//	Rect imageSize = Rect(0, 0, BAR_FIX_SIZE, BAR_MIN_SIZE);
//	Rect insets = Rect(4, 1, 12, 8);
//	bar = Scale9Sprite::create("scrollbar_vertical", imageSize, insets);
//
//	bar->setAnchorPoint(Vec2(0, 0.5f));
//
//	Size size = view->cocos2d::Node::getContentSize();
//	viewFixSize = size.width;
//	currentContentSize = beforeContentSize = view->getContentSize().width;
//
//	// Inner
//	if (positionType == BarType::HORIZONTAL_IN)
//	{
//		this->setPosition(position.x, position.y + (bar->getContentSize().height / 2 + 1));
//	}
//	// Outer
//	else
//	{
//		this->setPosition(position.x, position.y - (bar->getContentSize().height / 2 + 1));
//	}
//
//}
//
//void ScrollBarView::fadeOut(float delta)
//{
//	if (!barFade)
//	{
//		return;
//	}
//
//	float x, y;
//	switch (positionType)
//	{
//	case BarType::VERTICAL_IN:
//	case BarType::VERTICAL_OUT:
//		x = 0.0f;
//		y = 1.0f;
//		break;
//	case BarType::HORIZONTAL_IN:
//	case BarType::HORIZONTAL_OUT:
//		x = 1.0f;
//		y = 0.0f;
//		break;
//	}
//
//	ScaleTo *action = ScaleTo::create(0.1f, x, y);
//	bar->runAction(action);
//}
//
//void ScrollBarView::fadeIn()
//{
//	if (!barFade)
//	{
//		return;
//	}
//
//	ScaleTo *action = ScaleTo::create(0.05f, 1.0f, 1.0f);
//	bar->runAction(action);
//}
//
//void ScrollBarView::setBarPosition(float offset)
//{
//	offset *= -1;
//
//	// Calculate bar position
//	float pos = (((offset - viewFixSize) / currentContentSize) * viewFixSize) + barSize;
//	switch (positionType)
//	{
//	case BarType::VERTICAL_IN:
//	case BarType::VERTICAL_OUT:
//		// Does position be overflow min-y or max-y on scrollview container?
//		if (pos < 0 || pos >(viewFixSize - barSize + 1))
//		{
//			return;
//		}
//		bar->setPosition(Vec2(bar->getPosition().x, pos));
//		break;
//	case BarType::HORIZONTAL_IN:
//	case BarType::HORIZONTAL_OUT:
//		// Does position be overflow min-x or max-x on scrollview container?
//		if (pos <= 0 || pos > (viewFixSize - barSize + 1))
//		{
//			return;
//		}
//		bar->setPosition(Vec2(pos, bar->getPosition().y));
//		break;
//	}
//}
//
//void ScrollBarView::setBarScale()
//{
//	beforeContentSize = currentContentSize;
//
//	// Calculate bar scale ( float unit )
//	float scale = (viewFixSize / currentContentSize) * viewFixSize;
//	barSize = scale;
//
//	if (scale < BAR_MIN_SIZE || scale >= viewFixSize)
//	{
//		return;
//	}
//
//	switch (positionType)
//	{
//	case BarType::VERTICAL_IN:
//	case BarType::VERTICAL_OUT:
//		bar->setContentSize(Size(BAR_FIX_SIZE, scale));
//		break;
//	case BarType::HORIZONTAL_IN:
//	case BarType::HORIZONTAL_OUT:
//		bar->setContentSize(Size(scale, BAR_FIX_SIZE));
//		break;
//	}
//}
//
//void ScrollBarView::refresh()
//{
//	if (bar->getScaleX() == 0.0f || bar->getScaleY() == 0.0f)
//	{
//		fadeIn();
//	}
//
//	// Stop all scheduled queues ( e.g. fadeout )
//	this->unscheduleAllSelectors();
//	// And re-attach fade out schedule queue
//	this->scheduleOnce(schedule_selector(ScrollBarView::fadeOut), fadeDelayTime);
//
//	float offset;
//	switch (positionType)
//	{
//	case BarType::VERTICAL_IN:
//	case BarType::VERTICAL_OUT:
//		offset = view->getContentOffset().y;
//		currentContentSize = view->getContentSize().height;
//		break;
//	case BarType::HORIZONTAL_IN:
//	case BarType::HORIZONTAL_OUT:
//		offset = view->getContentOffset().x;
//		currentContentSize = view->getContentSize().width;
//		break;
//	}
//
//	// Can be visible?
//	bool isVisible = (currentContentSize <= viewFixSize) ? false : true;
//	this->setVisible(isVisible);
//
//	// If size is not equal, calculate size and update
//	if (beforeContentSize != currentContentSize)
//	{
//		setBarScale();
//	}
//
//	// Set position
//	setBarPosition(offset);
//}

//#include "TopScroll.h"
//// ScrollView インクルード
//#include "extensions/cocos-ext.h"
//
//
//USING_NS_CC;     // cocos2d
//USING_NS_CC_EXT; // cocos2d::extension
//
//
//TopScroll::TopScroll()
//
//{
//}
//
//TopScroll::~TopScroll()
//{
//}
//
//
//// createSceneはLayerをSceneに貼り付けて返すクラスメソッドです。
//// 自分自身(TopScroll)を生成し、空のSceneに貼り付けて返す簡単な処理を行っているだけです。
//// これでほかのシーンからの遷移が楽に行えます。
//Scene* TopScroll::createScene()
//
//{
//	auto scene = Scene::create();
//	auto layer = TopScroll::create();
//	scene->addChild(layer);
//	return scene;
//}
//
//
//bool TopScroll::init()
//{
//	if (!Layer::init())
//	{
//		return false;
//	}
//
//
//
//	// 画面サイズ取得
//
//	auto size = Director::getInstance()->getVisibleSize();
//
//	// 画面サイズでスクロールビューを作る
//	auto *pScrollView = ScrollView::create(size);
//
//	// スクロールビュー自体の大きさを変更したい場合
//	// pScrollView->setViewSize(Size(500, 500));
//
//
//	// バウンスを許可するか（以下は非許可）
//	// pScrollView->setBounceable(false);
//
//	// スクロール方向の指定
//
//	 pScrollView->setDirection(ScrollView::Direction::HORIZONTAL);
//
//	/*
//
//	列挙型定数                 説明
//
//	Direction::BOTH          両方向
//
//	Direction::HORIZONTAL    横（水平）方向のみ
//
//	Direction::VERTICAL      縦（垂直）方向のみ
//
//	Direction::NONE          制限をなくす
//
//	*/
//
//
//
//	this->addChild(pScrollView);
//
//	// デリゲートを使うと、スクロールの状態を取得することができます。
//
//	//TopScrollレイヤーをデリゲートに設定
//
//	pScrollView->setDelegate(this);
//
//
//
//	//スクロールビューに入れるスプライトを用意
//
//	auto *pSprite = Sprite::create("PL_Magic.png");
//
//
//
//	pScrollView->setContainer(pSprite);
//
//	pScrollView->setContentSize(pSprite->getContentSize());
//
//
//	return true;
//
//}
//
//
//// スクロール
//
//void TopScroll::scrollViewDidScroll(ScrollView *view)
//{
//	log("スクロール！");
//}
//
//
//// ズーム
//void TopScroll::scrollViewDidZoom(ScrollView *view)
//
//{
//	log("ズーム！");
//}
//
//
//#include "TopScroll.h"
//
//using namespace cocos2d;
//
//#define PI 3.14159265359f  
//#define RADIUS 100  
//#define FLATTEN_RATE 0.4f  
//
//TopScroll* TopScroll::create()
//{
//	TopScroll *instance = new TopScroll();
//	instance->init();
//	instance->autorelease();
//	return instance;
//}
//
//bool TopScroll::init()
//{
//	if (!Node::init())
//		return false;
//
//	this->players.clear();
//	this->players.pushBack(Label::createWithSystemFont("1", "Arial", 72));
//	this->players.pushBack(Label::createWithSystemFont("2", "Arial", 72));
//	this->players.pushBack(Label::createWithSystemFont("3", "Arial", 72));
//	this->players.pushBack(Label::createWithSystemFont("4", "Arial", 72));
//	this->players.pushBack(Label::createWithSystemFont("5", "Arial", 72));
//
//	for (auto item : players)
//		this->addChild(item);
//
//	this->angle = 0.0f;
//	this->arrange();
//
//	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
//	listener->onTouchBegan = [](Touch *touch, Event *event) { return true; };
//	listener->onTouchMoved = [&](Touch *touch, Event *event) {
//		float delta = touch->getLocation().x - touch->getPreviousLocation().x;
//		this->angle += delta;
//		this->arrange();
//	};
//	listener->onTouchEnded = [&](Touch *touch, Event *event) {
//		// Z オーダが一番大きい（= 一番手前の）オブジェクトを探す  
//		int maxZ = 0;
//		ssize_t frontIndex = 0;
//		for (int i = 0; i < this->players.size(); i++)
//		{
//			if (this->players.at(i)->getZOrder() > maxZ)
//			{
//				maxZ = this->players.at(i)->getZOrder();
//				frontIndex = i;
//			}
//		}
//
//		float theta = 360.0f / this->players.size();
//		float angleToMove = 360.0f - theta * frontIndex;
//
//		// 逆回転防止  
//		if (this->angle > 180.0f) this->angle -= 360.0f;
//		if (this->angle < -180.0f) this->angle += 360.0f;
//		if (angleToMove - this->angle > 180.0f) angleToMove -= 360.0f;
//		if (angleToMove - this->angle < -180.0f) angleToMove += 360.0f;
//
//		auto moveToHome = [=](float) {
//			if (fabs(angleToMove - this->angle) <= 0.1f)
//			{
//				this->unschedule("moveToHome");
//				this->angle = angleToMove;
//				this->arrange();
//				return;
//			}
//
//			float delta = (angleToMove - this->angle) * 0.1f;
//			this->angle += delta;
//			this->arrange();
//		};
//		this->schedule(moveToHome, 0.0f, "moveToHome");
//	};
//	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
//
//	return true;
//}
//
//void TopScroll::arrange()
//{
//	float theta = 360.0f / players.size();
//	float baseAngle = this->angle + 270.0f;
//	for (int i = 0; i < players.size(); i++)
//	{
//		// 270 度の位置が正面にくるように  
//		float angle = theta * i + baseAngle;
//		float radians = angle * PI / 180.0f;
//		float x = RADIUS * cos(radians);
//		float y = RADIUS * sin(radians) * FLATTEN_RATE;
//		float radiusY = RADIUS * FLATTEN_RATE;
//		float diameterY = radiusY * 2;
//		float scale = (diameterY - y) / diameterY;
//		GLubyte opacity = 255 - (y + radiusY);
//		this->players.at(i)->setPosition(Vec2(x, y));
//		this->players.at(i)->setScale(scale);
//		this->players.at(i)->setOpacity(opacity);
//		this->players.at(i)->setZOrder(diameterY - y);
//	}
//}