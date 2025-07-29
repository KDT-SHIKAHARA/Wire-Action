#pragma once
#include<vector>
#include<memory>
#include"MapRender.h"
#include"MapData.h"
#include"MapResHandle.h"
#include"singleton.h"

class GameObject;
class MapManager:public Singleton<MapManager>{
	friend class Singleton<MapManager>;

	MapManager() = default;
	virtual ~MapManager() = default;


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
	//	�����蔻��
	void CheckCollision(const std::vector<std::shared_ptr<GameObject>>& gameObjs);

	//	�}�b�v�f�[�^�̓Ǎ�
	void Load();

	//	�`��
	void Render(const Camera& camera);
};