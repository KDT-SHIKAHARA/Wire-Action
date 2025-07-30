#include "Player.h"
#include "RigidbodyComp.h"
#include "ColliderComp.h"
#include "InputMoveComp.h"
#include "GetColor.h"
#include "PlayerState.h"
#include "PlayerStateController.h"


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
	auto rigid = AddComponent<RigidbodyComp>();	//	����
	AddComponent<ColliderComp>(Vector2D<float>{ 50, 70 });
	AddComponent<InputMove>();		//	���͈ړ�
	AddComponent<PlayerStateComp>(5);
	auto stateCo = AddComponent<StateController>();
	stateCo->Start();

}

/// <summary>
/// �e�R���|�[�l���g�̍X�V����
/// </summary>
void Player::Update()
{
	GameObject::Update();
}

void Player::Render()
{
	const auto& trans = transform.WorldPosition();
	const auto& size = GetComponent<ColliderComp>()->size();
	DrawBoxAA(trans.x, trans.y, trans.x + size.x, trans.y + size.y,
		RED, TRUE);
}
