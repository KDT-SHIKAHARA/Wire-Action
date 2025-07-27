#include "InputMoveComp.h"
#include"GameObject.h"
#include"input.h"
#include"RigidbodyComp.h"

/// <summary>
/// ���͏�Ԃ��Q�Ƃ��āA���͈ړ��ʂ�ݒ肷��B
/// </summary>
void InputMove::Update(){
	//	���͂��s�����ǂ����̔���
	if (!isInput) return;
	//	���͂ɉ������ړ��ʂ�ݒ肷��
	auto rigit_ptr = GetGameObj()->GetComponent<RigidbodyComp>();

	//	��
	if (Input::IsKeyPressed(KEY_INPUT_A)) {
		rigit_ptr->AddVelocity({ -move_speed_ ,0 });
	}

	//	�E
	if (Input::IsKeyPressed(KEY_INPUT_D)) {
		rigit_ptr->AddVelocity({ move_speed_ ,0 });
	}
}
