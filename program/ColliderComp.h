#pragma once
#include"Component.h"
#include"vector2d.h"


/// <summary>
/// “–‚½‚è”»’è‚É•K—v‚Èî•ñ‚ğæ“¾‚·‚é
/// </summary>
class ColliderComp : public Component{
	Vector2D<float> size_;
public:
	ColliderComp(Vector2D<float> arg_size = { 0,0 })
		:size_(arg_size){ }

	Vector2D<float> size() const { return size_; }
	void Update()override{}

};
