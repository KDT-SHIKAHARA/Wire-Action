#pragma once
#include"GameObjectMgr.h"
#include"MapManager.h"
#include"moveSystem.h"
#include"Camera.h"

class Scene {
	Camera camera;
public:
	Scene() = default;
	virtual ~Scene() = default;
	virtual void Update() {
		GameObjMgr::Instance().Update();
		MapManager::Instance().CheckCollision(GameObjMgr::Instance().GetGameObjList());
		MoveSystem::Instance().Update(GameObjMgr::Instance().GetGameObjList());
	}
	virtual void Render() {
		MapManager::Instance().Render(camera);
		GameObjMgr::Instance().Render();
	};
};