#include "Player.h"
#include "RigidbodyComp.h"
#include "ColliderComp.h"
#include "InputMoveComp.h"
#include "GetColor.h"

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
	AddComponent<RigidbodyComp>();	//	物理
	AddComponent<ColliderComp>(Vector2D<float>{ 50, 70 });
	AddComponent<InputMove>();		//	入力移動
}

/// <summary>
/// 各コンポーネントの更新処理
/// </summary>
void Player::Update()
{
	auto rigid = GetComponent<RigidbodyComp>();	//	物理
	switch (state) {
	case PlayerState::idle:
		//	待機状態で移動量があったら移動状態にする
		if (rigid->velocity().x != 0.0f)
			PlayerState::move;

	case PlayerState::move:
		//	入力判定&移動量設定
		GetComponent<InputMove>()->Update();

		break;
	}


	//	移動処理
	rigid->Update();

}

void Player::Render()
{
	const auto& trans = transform.WorldPosition();
	const auto& size = GetComponent<ColliderComp>()->size();
	DrawBoxAA(trans.x, trans.y, trans.x + size.x, trans.y + size.y,
		RED, TRUE);
}
