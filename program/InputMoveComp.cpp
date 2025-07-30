#include "InputMoveComp.h"
#include"GameObject.h"
#include"input.h"
#include"RigidbodyComp.h"
#include"PlayerStateController.h"

/// <summary>
/// ���͏�Ԃ��Q�Ƃ��āA���͈ړ��ʂ�ݒ肷��B
/// </summary>
void InputMove::Update(){
	//	���͂��s�����ǂ����̔���
	if (!isInput) return;

	//	���s�\���
	auto state = GetGameObj()->GetComponent<StateController>();

	//	���͂ɉ������ړ��ʂ�ݒ肷��
	auto rigit_ptr = GetGameObj()->GetComponent<RigidbodyComp>();

	//	�K�v�ȃR���|�[�l���g�����Ă��邩�m�F
	if (!rigit_ptr || !state) return;

	//	���s�s�Ȃ珈�����I��
	if (!state->CanMove()) return;


	//	��
	if (Input::IsKeyPressed(KEY_INPUT_A)) {
		rigit_ptr->AddVelocity({ -move_speed_ ,0 });
		state->RequestMove();
	}

	//	�E
	if (Input::IsKeyPressed(KEY_INPUT_D)) {
		rigit_ptr->AddVelocity({ move_speed_ ,0 });
		state->RequestMove();
	}
}
