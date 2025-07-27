#include "RigidbodyComp.h"
#include "GameObject.h"
#include"Time.h"


RigidbodyComp::RigidbodyComp(float arg_mass , Flag arg_isGravity, Flag arg_isStatic)
	:mass_(arg_mass), velocity_(0,0), acceleration_(0,0), gravity_(0,0), totalForce_(0,0), damping_(0.0), isGravity_(arg_isGravity), isGrounded_(false),isStatic_(arg_isStatic)
{}

/// <summary>
/// �O�͂̒ǉ�
/// </summary>
/// <param name="arg_force"> �O�͂̒ǉ� </param>
void RigidbodyComp::AddForce(const Vector2D<float>& arg_force){
	totalForce_ += arg_force;
}

/// <summary>
/// �ړ��x�N�g���̐ݒ�
/// </summary>
/// <param name="arg_velocity"> �ړ��x�N�g���̐ݒ� </param>
void RigidbodyComp::SetVelocity(const Vector2D<float>& arg_velocity){
	velocity_ = arg_velocity;

}

/// <summary>
/// ���������̌v�Z�ƈړ��ʂ̉��Z
/// </summary>
void RigidbodyComp::Update(){
	//	�e��weak_ptr��lock���Ď擾
	auto GameObj = GetGameObj();
	if (!GameObj) return;

	//	�f���^���Ԏ擾
	const auto& deltaTime = Time::deltaTime();

	//	�����������s����
	if (isStatic_) {

		//	�d�͎��s����
		if (isGravity_) {

			//	���v�l *= �d�͒萔 * �d�� 
			totalForce_ += Vector2D<float>(0, kGravity * mass_);
		}

		//	�����x = �O�� / ����
		acceleration_ = totalForce_ / mass_;
		velocity_ += acceleration_;

		//	������ (���{ - ������)
		velocity_ *= (1.0f - damping_);

		//	�O�͂̃��Z�b�g
		totalForce_.Clear();

	}
	

	//	�ړ������͏�ɍs��
	GameObj->transform.AddPosition(velocity_ * deltaTime);
} 
