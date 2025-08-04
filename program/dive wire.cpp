#include "dive wire.h"
#include "MapManager.h"
#include "input.h"
#include "GameObject.h"
#include "PlayerStateController.h"
#include "Time.h"


DiveWire::DiveWire(const Vector2D<float>& gameObjPos):basePos_(gameObjPos)
{
}

void DiveWire::Update()
{
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
		anchorPos_ += (velocity_ * (anchorSpeed_ * Time::deltaTime()));

		//	長さの取得
		length_ = Get2Distance<float>(anchorPos_, basePos_);

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
}

/// <summary>
/// 移動ベクトルの計算
/// </summary>
void DiveWire::Start() {
	anchorPos_ = basePos_;
	velocity_ = Vector2D<float>{ Input::MouseX(),Input::MouseY() } - basePos_;
	velocity_.Normalize();
}


bool DiveWire::IsFinished() const
{
	return false;
}
