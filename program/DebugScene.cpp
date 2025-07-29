#include "DebugScene.h"
#include "debugDef.h"
#include "DebugLog.h"
#include "Player.h"




SceneDebug::SceneDebug(){
	auto player = std::make_shared<Player>();
	player->SetComponent();
	player_ = player;
	map.Load();
}

void SceneDebug::Update(){
	player_->Update();
	map.CheckCollision(*player_);
}

void SceneDebug::Render()
{
	DEBUG_LOG("debug scene");
	map.Render(camera);
	player_->Render();
}
