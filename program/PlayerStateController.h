#pragma once
#include"PlayerState.h"
#include"Component.h"


/// <summary>
/// �v���C���[�̏�Ԃ𐧌䂷��B
/// �e�R���|�[�l���g�̏I�����\�b�h�����Ԃ̕ύX���s��
/// �����ł͏�Ԃ̕ω��������s���āA��ԕω������ď������s�����ǂ�����
/// �e�R���|�[�l���g�Ŋm�F����
/// </summary>
class StateController : public Component {
public:
	void Start();
	void Update()override;

	// ��ԕύX���N�G�X�g
	//	�W�����v
	void RequestJump() {
		if (!state_) return;
		//	�ҋ@�A�ړ�
		if (CanJump()) {
			state_->SetState(_P_STATE::Jump);
		}
	}

	//	�ړ�
	void RequestMove() {
		if (!state_) return;
		//	�ҋ@�A�ړ��A�W�����v
		if (CanMove()) {
			//	�W�����v��Ԃ���Ȃ����
			if (state_->GetState() != _P_STATE::Jump)
				//	�ړ���Ԃɂ���
				state_->SetState(_P_STATE::Move);
		}

	}

	//	��ԕύX�\����
	//	�W�����v
	bool CanJump()const {
		auto state = state_->GetState();
		return state == _P_STATE::Idle || state == _P_STATE::Move;
	}

	//	�ړ�
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