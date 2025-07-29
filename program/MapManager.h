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


	//	描画
	MapRender render_;

	//	データ
	MapData mapData_;

	//	ハンドル
	TileTextureRegistry registry_;

	//	ハンドルを格納してるファイルのパス
	std::string handle_path_ = "res/map/handle/data.xml";
	std::string map_data_path_ = "res/map/data/map_data.txt";

public:
	//	当たり判定
	void CheckCollision(const std::vector<std::shared_ptr<GameObject>>& gameObjs);

	//	マップデータの読込
	void Load();

	//	描画
	void Render(const Camera& camera);
};