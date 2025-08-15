#include "PlayerRender.h"
#include "GameObject.h"
#include "ColliderComp.h"

PlayerAnim::PlayerAnim()
{
	const std::string& Idle_str = "res/player/texture/idle/Unitychan_Idle_";
	//	アニメーションクラスのインスタンスも同時に作ってね
	animations_[AnimType::Idle].LoadFrames(Idle_str, 3,0.2f);
}

void PlayerAnim::Update()
{
	if (!state_) return;

	//	ここスイッチ文ね state_->GetStateを見てね
	//	stateコンポーネントのenum classを見て
	//	animtypeの数値を設定する


	//	animtypeをインデックスに持つ更新メソッドを呼び出す。
	animations_[now_type_].Update();

}

void PlayerAnim::Render()
{
	//	ここ2行で書いてるけどプレイヤーは左上基準なのでこのままだと
	//	ずれます。サイズの半分の数値を足さないといけない
	const auto& transform = GetGameObj()->transform.WorldPosition();
	const auto& size = GetGameObj()->GetComponent<ColliderComp>()->size();
	animations_[now_type_].Render(transform.x + size.x / 2,transform.y + size.y / 2);
}
