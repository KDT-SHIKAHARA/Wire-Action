#pragma once
#include"PlayerState.h"
#include"Component.h"


/// <summary>
/// プレイヤーの状態を制御する。
/// 各コンポーネントの終了メソッドから状態の変更を行う
/// ここでは状態の変化だけを行って、状態変化を見て処理を行うかどうかは
/// 各コンポーネントで確認する
/// </summary>
class StateController : public Component {
public:
	void Start();
	void Update()override;

	// 状態変更リクエスト
	//	ジャンプ
	void RequestJump() {
		if (!state_) return;
		//	待機、移動
		if (CanJump()) {
			state_->SetState(_P_STATE::Jump);
		}
	}

	//	移動
	void RequestMove() {
		if (!state_) return;
		//	待機、移動、ジャンプ
		if (CanMove()) {
			//	ジャンプ状態じゃなければ
			if (state_->GetState() != _P_STATE::Jump)
				//	移動状態にする
				state_->SetState(_P_STATE::Move);
		}

	}

	//	状態変更可能判定
	//	ジャンプ
	bool CanJump()const {
		auto state = state_->GetState();
		return state == _P_STATE::Idle || state == _P_STATE::Move;
	}

	//	移動
	bool CanMove()const {
		auto state = state_->GetState();
		return	
			state == _P_STATE::Idle ||
			state == _P_STATE::Move ||
			state == _P_STATE::Jump;
	}



private:
	std::shared_ptr<PlayerStateComp> state_;

};