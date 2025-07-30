#include "PlayerStateController.h"
#include"GameObject.h"
#include"RigidbodyComp.h"
#include"InputMoveComp.h"

/// <summary>
/// stateコンポーネントの取得
/// </summary>
void StateController::Start()
{
	state_ = GetGameObj()->GetComponent<PlayerStateComp>();
}


/// <summary>
/// 各コンポーネントの終了状態を終了判定メソッドを見て状態の終了を管理する
/// </summary>
void StateController::Update(){	
	if (!state_)return;
	auto state = state_->GetState();
	//	状態の終了判定
	//	終了したら待機状態に戻す
	switch (state) {
	case _P_STATE::Idle:
		break;

	case _P_STATE::Move: {
		const auto& vector = GetGameObj()->GetComponent<RigidbodyComp>()->velocity();

		//	移動量がなかったら待機状態にする
		if (vector.x == 0.0f) {
			state = _P_STATE::Idle;
		}
		break;
	}

	case _P_STATE::Jump: {
		auto& isGround = GetGameObj()->GetComponent<RigidbodyComp>()->isGrounded_;

		//	着地していたら待機状態にする
		if (isGround) {
			state = _P_STATE::Idle;
		}
		break;

	}

	}

}
