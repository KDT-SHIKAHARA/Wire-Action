#pragma once


struct Rect {
	float x, y, w, h = 0;

	bool IsCollision(const Rect& other) {
		return !(x + w <= other.x || other.x + other.w <= x ||
			y + h <= other.y || other.y + other.h <= y);
	}
};