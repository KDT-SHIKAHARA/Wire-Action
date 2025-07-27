#pragma once
#include"MapRender.h"
#include"MapData.h"
#include"MapResHandle.h"

class GameObject;
class MapManager {
	//	�`��
	MapRender render_;

	//	�f�[�^
	MapData mapData_;

	//	�n���h��
	TileTextureRegistry registry_;

	//	�n���h�����i�[���Ă�t�@�C���̃p�X
	std::string handle_path_ = "res/map/handle/data.xml";
	std::string map_data_path_ = "res/map/data/map_data.txt";

public:
	void CheckCollision( GameObject& gameObj);

	//	�}�b�v�f�[�^�̓Ǎ�
	void Load();

	//	�`��
	void Render(const Camera& camera);
};