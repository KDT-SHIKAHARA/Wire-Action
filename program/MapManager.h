#pragma once
#include"MapRender.h"
#include"MapData.h"
#include"MapResHandle.h"

class GameObject;
class MapManager {
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
	void CheckCollision( GameObject& gameObj);

	//	マップデータの読込
	void Load();

	//	描画
	void Render(const Camera& camera);
};