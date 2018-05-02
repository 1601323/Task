//#ifndef __Lib__ScrollBarView__
//#define __Lib__ScrollBarView__
//
//#include "cocos2d.h"
//#include "cocos-ext.h"
//
//
//
//class ScrollBarView :public cocos2d::LayerColor
//{
//public:
//
//	// バータイプ
//	enum class BarType
//	{
//		VERTICAL_IN = 1,
//		VERTICAL_OUT,
//		HORIZONTAL_IN,
//		HORIZONTAL_OUT,
//	};
//	// ｺﾝｽﾄﾗｸﾀ
//	ScrollBarView(cocos2d::extension::ScrollView *view, BarType type);
//	// ﾃﾞｽﾄﾗｸﾀ
//	~ScrollBarView();
//	// 生成
//	static ScrollBarView* create(cocos2d::extension::ScrollView *view, BarType type);
//	// バーの位置
//	void refresh();
//
//	/**
//	* Setter methodsセッターメソッド
//	*/
//	void setBarFade(bool barFade);
//	void setBarSize(float barSize);
//	void setBarFadeDelayTime(float fadeDelayTime);
//
//private:
//	/**
//	* Scrolling type enum
//	19/5000
//	スクロールタイプの列挙型
//	*/
//	BarType positionType;
//
//	/**
//	* Delay times untill fade-out bar　フェードアウトバーまでの遅延時間
//	*/
//	float fadeDelayTime;
//
//	/**
//	* Enable to fade-out flagフェードアウトフラグを有効にする
//	*/
//	bool barFade;
//
//	/**
//	* Stacked bar sizeスタックバーのサイズ
//	*/
//	float barSize;
//
//	/**
//	* Stacked scroll-view size ( width or height )
//	44/5000
//	もしかして: Stacked scrollview size ( width or height )
//	スタックされたスクロールビューのサイズ（幅または高さ）
//	*/
//	float viewFixSize;
//
//	/**
//	* Stacked current content size ( width or height )*スタックされた現在のコンテンツサイズ（幅または高さ）
//	*/
//	float currentContentSize;
//
//	/**
//	* Stacked before content size ( width or height )  *コンテンツサイズ（幅または高さ）より前にスタック
//	*/
//	float beforeContentSize;
//
//	/**
//	* cocos2d view/sprite properties cocos2dビュー/スプライトのプロパティ
//	*/
//	cocos2d::extension::ScrollView *view;
//	cocos2d::extension::Scale9Sprite *bar;
//
//
//	/**
//	* Fade in/out methodフェードイン/アウト方式
//	*/
//	void fadeOut(float delta);
//	void fadeIn();
//
//	/**
//	* Initialize scrollbarスクロールバーを初期化する
//	*/
//	bool init();
//
//	/**
//	* Initialize for vertical scroll垂直スクロールの場合は初期化
//	*/
//	void initVertical();
//
//	/**
//	* Initialize for horizontal scroll水平スクロール用に初期化する
//	*/
//	void initHorizontal();
//
//	/**
//	* Recalculate scrollbar positionスクロールバーの位置を再計算する
//	*/
//	void setBarPosition(float offset);
//
//	/**
//	* Recalculate scrollbar scaleスクロールバーのスケールを再計算する
//	*/
//	void setBarScale();
//};
//
//
//#endif // !__Lib__ScrollView__

//#ifndef __ScrollView01__TopScroll__
//#define __ScrollView01__TopScroll__
//
//#include "cocos2d.h"
//#include "extensions/cocos-ext.h"
//
//USING_NS_CC;
//USING_NS_CC_EXT;
//
//class TopScroll :public Layer,public ScrollViewDelegate // デリゲート
//{
//protected:
//	// コンストラクタ
//	TopScroll();
//	// デストラクタ
//	virtual ~TopScroll();
//	// メソッド CREATE_FUNCとの連携
//	bool init() override;
//
//public:
//	static cocos2d::Scene* createScene();
//	CREATE_FUNC(TopScroll);
//	void scrollViewDidScroll(ScrollView *view);
//	void scrollViewDidZoom(ScrollView *view);
//};
//
//
//#endif /* defined(__ScrollView01__TopScroll__) */

//#include "cocos2d.h"
//
//class TopScroll : public cocos2d::Node,public cocos2d::Layer
//{
//private:
//	cocos2d::Vector<cocos2d::Node *> players;
//	float angle;
//
//	bool init();
//
//	void arrange();
//
//public:
//	static TopScroll* create();
//};