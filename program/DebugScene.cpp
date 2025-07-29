#include "DebugScene.h"
#include "debugDef.h"
#include "DebugLog.h"
#include "Player.h"
#include "GameObjectMgr.h"


SceneDebug::SceneDebug(){
	auto player = std::make_shared<Player>();
	player->SetComponent();
	GameObjMgr::Instance().AddGameObject(player);
	MapManager::Instance().Load();
}

void SceneDebug::Update(){
	Scene::Update();
}

void SceneDebug::Render()
{
	Scene::Render();
	DEBUG_LOG("debug scene");

}
