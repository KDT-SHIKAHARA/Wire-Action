#include "Player.h"
#include "RigidbodyComp.h"
#include "ColliderComp.h"
#include "InputMoveComp.h"
#include "GetColor.h"
#include "PlayerState.h"
#include "PlayerStateController.h"


/// <summary>
/// 初期化
/// </summary>
Player::Player():state(PlayerState::idle)
{

}

/// <summary>
/// コンポーネントの追加
/// </summary>
void Player::SetComponent()
{
	transform.SetPosition(Vector2D<float>(500, 100));
	auto rigid = AddComponent<RigidbodyComp>();	//	物理
	AddComponent<ColliderComp>(Vector2D<float>{ 50, 70 });
	AddComponent<InputMove>();		//	入力移動
	AddComponent<PlayerStateComp>(5);
	auto stateCo = AddComponent<StateController>();
	stateCo->Start();

}

/// <summary>
/// 各コンポーネントの更新処理
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
