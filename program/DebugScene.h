#pragma once
#include"sceneBase.h"
#include"TestPlayer.h"
#include"MapManager.h"
#include"Camera.h"

/// <summary>
/// �f�o�b�N�p�X�N���[��
/// </summary>
class SceneDebug :public Scene{
	std::shared_ptr<GameObject> testPlayer;
	MapManager map;
	Camera camera;

public:
	SceneDebug();
	void Update()override;
	void Render()override;
};