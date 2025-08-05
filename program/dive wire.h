#pragma once

#include"Component.h"
#include"DrawableComp.h"
#include"flag.h"
#include"vector2d.h"

/// <summary>
/// ダイブワイヤーの管理
/// </summary>
class DiveWire : public Component, public DrawableComp {



public:
	DiveWire(const Vector2D<float>& gameObjPos);
	virtual ~DiveWire() = default;

	void Update()override;
	void Render()override;

	void Start();
	bool IsFinished()const;

	//	リセット
	void ReSet() {
		isAnchored = false;
		isFinished_ = false;
		chargeFrame = 0.0f;
	}

	Vector2D<float> anchorPos()const { return anchorPos_; };

	Flag isAnchored = false;	//	アンカーが固定されているかどうかの判定
private:
	
	const Vector2D<float>& basePos_;
	Vector2D<float> gameObjPos_;
	Vector2D<float> anchorPos_;
	Vector2D<float> velocity_;
	double chargeFrame = 0;
	const double kChargeFrameMax = 0.5;	//	発射するまでのcharge時間
	float length_ = 0;
	const float anchorSpeed_ = 1000.0f;	//	アンカーの移動速度
	const float kWireLength = 400.0f;	//	ワイヤーの最大の長さ
	Flag isFinished_ = false;
};


