#pragma once
#include"MapData.h"
#include"Camera.h"
#include"TextureResource.h"
#include<unordered_map>
#include<memory>

class MapRender {
	//	タイル画像のコレクション型
	using TexturePtr_map = std::unordered_map<int, std::shared_ptr<TextureResource>>;
public:
	//	タイル画像を読み込む
	void LoadTexture(const std::unordered_map<int, std::string>& tiles_file_path);


	void Render(const MapData& mapData, const Camera& camera);
private:
	TexturePtr_map tile_textures_;	//	タイル画像のコレクション
};