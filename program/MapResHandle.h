#pragma once
#include<string>
#include<unordered_map>

/// <summary>
/// ファイルパスの管理
/// </summary>
class TileTextureRegistry {
public:
	//	xmlファイルからパスを読み込む
	//	true: 読込成功 false: 読込失敗
	void LoadFilesPath(const std::string& xml_path);
	 
	//	タイルIDに対応するファイルパスを返す
	//	見つからなかったら空文字を返す。
	//	デフォルトファイルパスを設定してもいい
	std::string GetPath(int tile_id)const;

	std::unordered_map<int, std::string> tiles_file_path() { return tiles_file_path_; }

private:
	std::unordered_map<int, std::string> tiles_file_path_;
	std::string tiles_base_path_;
};