#include "DiveWireController.h"
#include "GameObject.h"
#include "PlayerStateController.h"
#include "input.h"
#include "dive wire.h"

/// <summary>
/// 発射可能状態の判定と入力の判定、DiveWireの有効化
/// </summary>
void DiveWireController::Update() {
	auto state = GetGameObj()->GetComponent<StateController>();
	if (!state)return;
	if (!state->CanDiveWire()) return;

	//	入力判定
	if (Input::IsMouseOn(MOUSE_INPUT_RIGHT)) {
		auto diveWire = GetGameObj()->GetComponent<DiveWire>();
		if (!diveWire)return;
		state->RequestDiveWire();	//	変更リクエスト
		diveWire->Start();			//	移動ベクトルセット

		//	ゲームオブジェクトの重力系を停止する
	}	
}