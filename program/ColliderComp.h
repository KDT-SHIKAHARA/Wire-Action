#pragma once
#include"Component.h"
#include"vector2d.h"

/// <summary>
/// 当たり判定に必要な情報を取得する
/// </summary>
class ColliderComp : public Component{
	Vector2D<float> size_;
public:
	ColliderComp(Vector2D<float> arg_size = { 0,0 })
		:size_(arg_size){ }

	Vector2D<float> size() const { return size_; }
	void Update()override{}

};
