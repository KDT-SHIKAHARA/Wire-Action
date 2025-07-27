#pragma once
#include"vector2d.h"

class Camera {
	Vector2D<float> position_;
	Vector2D<float> area_size_;
public:
	Camera();
	virtual ~Camera() = default;
	Vector2D<float> position()const { return position_; }
	Vector2D<float> area_size()const { return area_size_; }

};