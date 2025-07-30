#include "InputMoveComp.h"
#include"GameObject.h"
#include"input.h"
#include"RigidbodyComp.h"
#include"PlayerStateController.h"

/// <summary>
/// 入力状態を参照して、入力移動量を設定する。
/// </summary>
void InputMove::Update(){
	//	入力を行うかどうかの判定
	if (!isInput) return;

	//	実行可能状態
	auto state = GetGameObj()->GetComponent<StateController>();

	//	入力に応じた移動量を設定する
	auto rigit_ptr = GetGameObj()->GetComponent<RigidbodyComp>();

	//	必要なコンポーネントがついているか確認
	if (!rigit_ptr || !state) return;

	//	実行不可なら処理を終了
	if (!state->CanMove()) return;


	//	左
	if (Input::IsKeyPressed(KEY_INPUT_A)) {
		rigit_ptr->AddVelocity({ -move_speed_ ,0 });
		state->RequestMove();
	}

	//	右
	if (Input::IsKeyPressed(KEY_INPUT_D)) {
		rigit_ptr->AddVelocity({ move_speed_ ,0 });
		state->RequestMove();
	}
}
