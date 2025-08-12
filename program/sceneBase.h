#pragma once
#include"GameObjectMgr.h"
#include"MapManager.h"
#include"moveSystem.h"
#include"Camera.h"

class Scene {
public:
	Scene() = default;
	virtual ~Scene() = default;
	virtual void Update() {
		GameObjMgr::Instance().Update();
		Camera::Instance().Update();
		MapManager::Instance().CheckCollision(GameObjMgr::Instance().GetGameObjList());
		MoveSystem::Instance().Update(GameObjMgr::Instance().GetGameObjList());
	}
	virtual void Render() {
		MapManager::Instance().Render();
		GameObjMgr::Instance().Render();
	};
};