#ifndef ChangeColorBy_hpp
#define ChangeColorBy_hpp

#include <stdio.h>
#include "cocos2d.h"

// RGBからHSVに変換
enum class ChangeColorType { RGB, HSV };
// ActionInterval :一定時間内に発生するアクションs
class ChangeColorBy : public cocos2d::ActionInterval 
{
public:	
	// ｱｸｼｮﾝクラス
	// ChangeColorBy::create(色タイプ ,色指定 ,元に戻すか否か ,アニメーション時間);
	// 色タイプ：ChangeColorType::RGBまたはChangeColorType::HSVを選択
	// 色指定：Vec3(R,G,B) or Vec3(H,S,V) ※いずれも-1.0〜1.0の範囲で指定
	// 元に戻すか：true:アニメーション終了時に元の色に戻っていく
	// アニメーション時間：秒指定
	static ChangeColorBy *create(const ChangeColorType &type,const cocos2d::Vec3 &color, bool doReverse,float duration);

	// 更新
	void update(float f) override;	
	// ターゲット
	virtual void startWithTarget(cocos2d::Node *target) override;
	// 複製
	virtual ActionInterval *clone() const override;

private:
	// shader
	ChangeColorType m_type;		// 色のタイプ
	cocos2d::Vec3 m_color;		// 色
	bool m_reverse;				// 逆
	// ターゲットの設定(ターゲット、バーテックスシェーダ、フラグメントシェーダー)
	void setShaderWithTarget(cocos2d::Node *target, const GLchar *vert,const GLchar *flag);

   protected:
	// 初期化期間(色タイプ,色,元に戻すか否か,アニメーション時間)
    virtual bool initWithDuration(const ChangeColorType &type, const cocos2d::Vec3 &color, bool doReverse,float duration);

};

#endif /* ChangeColorBy_hpp */
