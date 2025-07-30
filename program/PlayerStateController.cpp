#include "PlayerStateController.h"
#include"GameObject.h"
#include"RigidbodyComp.h"
#include"InputMoveComp.h"

/// <summary>
/// state�R���|�[�l���g�̎擾
/// </summary>
void StateController::Start()
{
	state_ = GetGameObj()->GetComponent<PlayerStateComp>();
}


/// <summary>
/// �e�R���|�[�l���g�̏I����Ԃ��I�����胁�\�b�h�����ď�Ԃ̏I�����Ǘ�����
/// </summary>
void StateController::Update(){	
	if (!state_)return;
	auto state = state_->GetState();
	//	��Ԃ̏I������
	//	�I��������ҋ@��Ԃɖ߂�
	switch (state) {
	case _P_STATE::Idle:
		break;

	case _P_STATE::Move: {
		const auto& vector = GetGameObj()->GetComponent<RigidbodyComp>()->velocity();

		//	�ړ��ʂ��Ȃ�������ҋ@��Ԃɂ���
		if (vector.x == 0.0f) {
			state = _P_STATE::Idle;
		}
		break;
	}

	case _P_STATE::Jump: {
		auto& isGround = GetGameObj()->GetComponent<RigidbodyComp>()->isGrounded_;

		//	���n���Ă�����ҋ@��Ԃɂ���
		if (isGround) {
			state = _P_STATE::Idle;
		}
		break;

	}

	}

}
