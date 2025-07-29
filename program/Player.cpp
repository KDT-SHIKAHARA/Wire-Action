#include "Player.h"
#include "RigidbodyComp.h"
#include "ColliderComp.h"
#include "InputMoveComp.h"
#include "GetColor.h"

/// <summary>
/// ������
/// </summary>
Player::Player():state(PlayerState::idle)
{

}

/// <summary>
/// �R���|�[�l���g�̒ǉ�
/// </summary>
void Player::SetComponent()
{
	transform.SetPosition(Vector2D<float>(500, 100));
	AddComponent<RigidbodyComp>();	//	����
	AddComponent<ColliderComp>(Vector2D<float>{ 50, 70 });
	AddComponent<InputMove>();		//	���͈ړ�
}

/// <summary>
/// �e�R���|�[�l���g�̍X�V����
/// </summary>
void Player::Update()
{
	auto rigid = GetComponent<RigidbodyComp>();	//	����
	switch (state) {
	case PlayerState::idle:
		//	�ҋ@��Ԃňړ��ʂ���������ړ���Ԃɂ���
		if (rigid->velocity().x != 0.0f)
			PlayerState::move;

	case PlayerState::move:
		//	���͔���&�ړ��ʐݒ�
		GetComponent<InputMove>()->Update();

		break;
	}


	//	�ړ�����
	rigid->Update();

}

void Player::Render()
{
	const auto& trans = transform.WorldPosition();
	const auto& size = GetComponent<ColliderComp>()->size();
	DrawBoxAA(trans.x, trans.y, trans.x + size.x, trans.y + size.y,
		RED, TRUE);
}
