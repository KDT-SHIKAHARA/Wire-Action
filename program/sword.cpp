#include "sword.h"
#include "GameObject.h"
#include "RigidbodyComp.h"

//	開始
void Sword::Start() {
	auto direction = GetGameObj()->transform.GetAngleType();

	switch (direction) {
	case Direction::Right:
		angle_ = 45.f;	//	開始角度
		angleIncrement_ = -90.f;	//	
		break;
	case Direction::Left:
		angle_ = 135.f;
		angleIncrement_ = 90.f;
		break;
	case Direction::Up:
		angle_ = 60.f;
		angleIncrement_ = 70.0f;
		break;
	case Direction::Down:
		angle_ = 270.f;
		angleIncrement_ = -70.0f;
		break;

	}

	//	移動量の最大値を設置
	angleMax_ = angle_ + angleIncrement_;

	attackFrame = 0;

}


void Sword::Update()
{
}

void Sword::Render()
{

}
