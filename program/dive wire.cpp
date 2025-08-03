#include "dive wire.h"
#include "MapManager.h"
#include "input.h"
#include "GameObject.h"
#include "PlayerStateController.h"

DiveWire::DiveWire()
{

}

void DiveWire::Update()
{
	auto state = GetGameObj()->GetComponent<StateController>();
	if (!state) return;

	//	入力を受け付ける状態か判定
	if (!state->CanDiveWire())return;

	//	入力が行われていない状態
		//	入力が行われているかを判定

	//	入力が行われていたら
		//	移動処理をする
		
		//	設置判定をする
			//	設置されていたらプレイヤーを移動させる
			//	


}

void DiveWire::Render()
{
}

bool DiveWire::IsFinished() const
{
	return false;
}
