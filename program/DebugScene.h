#pragma once
#include"sceneBase.h"
#include"TestPlayer.h"
#include"MapManager.h"
#include"Camera.h"

/// <summary>
/// デバック用スクリーン
/// </summary>
class SceneDebug :public Scene{
	std::shared_ptr<GameObject> player_;


public:
	SceneDebug();
	void Update()override;
	void Render()override;
};