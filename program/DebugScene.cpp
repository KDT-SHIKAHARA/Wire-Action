#include "DebugScene.h"
#include "debugDef.h"
#include "DebugLog.h"





SceneDebug::SceneDebug(){
	auto player = std::make_shared<TestPlayer>();
	player->SetComponents();
	testPlayer = player;
	map.Load();
}

void SceneDebug::Update(){
	testPlayer->Update();
	map.CheckCollision(*testPlayer);
}

void SceneDebug::Render()
{
	DEBUG_LOG("debug scene");
	map.Render(camera);
	testPlayer->Render();
}
