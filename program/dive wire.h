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
	DiveWire();
	virtual ~DiveWire() = default;

	void Update()override;
	void Render()override;

	bool IsFinished()const;

	Vector2D<float> position()const { return pos_; };

private:
	Vector2D<float> pos_;

	Flag isEnable;	
};


