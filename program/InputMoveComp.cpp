#include "InputMoveComp.h"
#include"GameObject.h"
#include"input.h"
#include"RigidbodyComp.h"

/// <summary>
/// 入力状態を参照して、入力移動量を設定する。
/// </summary>
void InputMove::Update(){
	//	入力を行うかどうかの判定
	if (!isInput) return;
	//	入力に応じた移動量を設定する
	auto rigit_ptr = GetGameObj()->GetComponent<RigidbodyComp>();

	//	左
	if (Input::IsKeyPressed(KEY_INPUT_A)) {
		rigit_ptr->AddVelocity({ -move_speed_ ,0 });
	}

	//	右
	if (Input::IsKeyPressed(KEY_INPUT_D)) {
		rigit_ptr->AddVelocity({ move_speed_ ,0 });
	}
}
