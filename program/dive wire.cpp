#include "dive wire.h"
#include "MapManager.h"
#include "input.h"
#include "GameObject.h"
#include "PlayerStateController.h"
#include "Time.h"
#include "dxlib.h"
#include "GetColor.h"
#include "ColliderComp.h"

DiveWire::DiveWire(const Vector2D<float>& gameObjPos):basePos_(gameObjPos)
{
}

void DiveWire::Update()
{
	//	停止して、移動などもできない状態で設置判定まで行うので
	// 座標の更新は一旦なくす

	
	////	座標の取得
	//gameObjPos_ = GetGameObj()->transform.WorldPosition();

	//	今の状態を見る
	auto state = GetGameObj()->GetComponent<PlayerStateComp>();
	if (!state)return;
	if (state->GetState() != _P_STATE::dive) return;

	//	アンカー発射までの待ち時間
	if (chargeFrame < kChargeFrameMax) {
		chargeFrame += Time::deltaTime();
		return;
	}


	//	アンカーが設置されていなかったら移動処理をする
	if (!isAnchored) {
		//	正規化した移動ベクトル * 移動速度(1秒間の移動速度 * 1Fの時間)
		anchorPos_ += (velocity_ * anchorSpeed_) * Time::deltaTime();
		

		//	長さの取得
		length_ = Get2Distance<float>(anchorPos_, gameObjPos_);

		//	設置判定をする
		if (MapManager::Instance().CheckPointHit(anchorPos_)) {
			isAnchored = true;
		}
		//	設置されていなくて、長さが最大を越していたら処理を終了する
		else if (length_ >= kWireLength) {
			isFinished_ = true;
		}
	}
	//	アンカーが設置されていたら
	else {
		//	GameObjectを移動させる



	}
}

void DiveWire::Render()
{

	auto state = GetGameObj()->GetComponent<PlayerStateComp>();
	if (!state)return;
	if (state->GetState() != _P_STATE::dive) return;

	DrawLineAA(gameObjPos_.x, gameObjPos_.y, anchorPos_.x, anchorPos_.y,
		SKYBLUE);
}

/// <summary>
/// 移動ベクトルの計算
/// </summary>
void DiveWire::Start() {
	auto size = GetGameObj()->GetComponent<ColliderComp>()->size();
	anchorPos_ = gameObjPos_ = (GetGameObj()->transform.WorldPosition() + (size / 2));
	velocity_ = Vector2D<float>{ (float)Input::MouseX(),(float)Input::MouseY() } - gameObjPos_;
	velocity_.Normalize();
}


bool DiveWire::IsFinished() const
{
	return isFinished_;
}
