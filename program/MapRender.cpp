#include"MapRender.h"
#include"TextureResourceMng.h"
#include"dxlib.h"
#include"GetColor.h"

/// <summary>
/// ファイルパス管理からファイルパスを取得して、テクスチャを読み込んでいる
/// </summary>
/// <param name="tiles_file_path"></param>
void MapRender::LoadTexture(const std::unordered_map<int, std::string>& tiles_file_path){
	for (auto& [num, filepath] : tiles_file_path) {
		tile_textures_[num] = TextureResourceMgr::Instance().GetTexture(filepath);
	}
}

/// <summary>
///	カメラの座標を使ってディスプレイに映る場所にいるタイルだけ描画する
/// </summary>
/// <param name="mapData"> マップデータのコレクションを格納したクラス </param>
/// <param name="camera">  </param>
void MapRender::Render(const MapData& mapData, const Camera& camera) {
	Vector2D<float> camera_pos = camera.position();
	Vector2D<float> camera_size = camera.area_size();
	int map_size = mapData.GetTileSize();

	//	マップの描画範囲の左上と右下の番号取得
	int left   =	(camera_pos.x - camera_size.x / 2) / map_size;
	int right =		(camera_pos.x + camera_size.x / 2) / map_size;
	int top =		(camera_pos.y - camera_size.y / 2) / map_size;
	int bottom =	(camera_pos.y + camera_size.y / 2) / map_size;

	//	必要箇所のみ描画
	for (int y = top; y <= bottom; y++) {
		for (int x = left; x <= right; x++) {
			//	マップタイルの取得
			const Tile& tile = mapData.GetTile(x, y);

			//	0番なら処理を行わない
			//	今後の0番の実装をできるようにインスタンスは実装しておくけど
			//	実装しないほうがいいかも
			if (tile.id == 0) continue;

			//	描画座標の取得
			int drawX = x * map_size - camera_pos.x + camera_size.x / 2;
			int drawY = y * map_size - camera_pos.y + camera_size.y / 2;

			//	描画
			if (tile.id > 1) {
				int a = 0;
			}


			DrawBox(drawX, drawY, drawX + map_size, drawY + map_size, BLUE, TRUE);
			DrawGraph(drawX, drawY, tile_textures_[tile.id]->GetHandle(), TRUE);
		}
	}



}