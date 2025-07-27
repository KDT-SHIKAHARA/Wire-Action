#include"MapManager.h"
#include"Rect.h"
#include"GameObject.h"
#include"ColliderComp.h"
#include"RigidbodyComp.h"
#include<cmath>
/// <summary>
/// マップとの当たり判定を行う。
/// メソッドの呼び出し前に当たり判定を行えるオブジェクト化判定してから呼び出す
/// </summary>
/// <param name="gameObj"></param>
void MapManager::CheckCollision( GameObject& gameObj){

	//	ゲームオブジェクトの座標
	const auto& obj_position = gameObj.transform.WorldPosition();

	//	ゲームオブジェクトのサイズ
	const auto& gameobj_size = gameObj.GetComponent<ColliderComp>()->size();

	//	そのゲームオブジェクトの直前の移動ベクトル
	const auto& gameobj_velo = gameObj.GetComponent<RigidbodyComp>()->velocity();

	//	マップタイルのサイズ
	const auto& tile_size = mapData_.GetTileSize();

	//	プレイヤーと当たっているマップの範囲

	//	当たり判定に必要な情報
	Rect objRect{
		obj_position.x,
		obj_position.y,
		gameobj_size.x,
		gameobj_size.y,
	};

	//	マップ外ならマップの数字にする。
	const int left = objRect.x / tile_size;
	const int right = (objRect.x + objRect.w) / tile_size;
	const int top = objRect.y / tile_size;
	const int bottom = (objRect.y + objRect.h) / tile_size;

	//	マップ外に出たら当たり判定を終了する
	auto rigit_ptr = gameObj.GetComponent<RigidbodyComp>();



	//	マップ内の数字で当たり判定
	for (int y = top; y <= bottom; y++) {
		for (int x = left; x <= right; x++) {
			if (!mapData_.IsInMap(x, y))continue;

			const auto& tile = mapData_.GetTile(x, y);
			if (!tile.isCollision) continue;

			//	マップタイルの矩形
			Rect tileRect{
				(float)x * tile_size,
				(float)y * tile_size,
				(float)tile_size,
				(float)tile_size,
			};

			//	めり込んでいるか判定
			if (objRect.IsCollision(tileRect)) {
				//	false: 左に進んでいる true: 右に進んでいる
				float overlap_x = (gameobj_velo.x > 0) ?
					(objRect.x + objRect.w) - tileRect.x
					: (tileRect.x + tileRect.w) - tileRect.x;

				//	false: 上に進んでいる true: 下に進んでいる
				float overlap_y = (gameobj_velo.y > 0) ?
					(objRect.y + objRect.h) - tileRect.y
					: (tileRect.y + tileRect.h) - tileRect.y;


				//	小さいほうに押し戻す
				if (std::abs(overlap_x) < std::abs(overlap_y)) {
					auto tmp_vec = (gameobj_velo.x > 0) ? -overlap_x : overlap_x;

					gameObj.transform.Translate(Vector2D<float>{tmp_vec, 0});
				}

				else {
					auto tmp_vec = (gameobj_velo.y > 0) ? -overlap_y : overlap_y;
					gameObj.transform.Translate(Vector2D<float>{0, tmp_vec});

					//	下方向なら
					//  接地フラグを立てる。
					//	重力フラグを折る
					if (gameobj_velo.y > 0)
					{
						rigit_ptr->SetVelocity({ rigit_ptr->velocity().x,0 });
						rigit_ptr->isGravity_.Set(false);
						rigit_ptr->isGrounded_.Set(true);
					}

				
					//	移動量をなくす
					

				}

				objRect.x = obj_position.x;
				objRect.y = obj_position.y;

			}
		}
	}

}

/// <summary>
/// ファイルからファイルパスを読み込んで
/// ファイルから画像を読み込む
/// </summary>
void MapManager::Load() {
	//	ファイルパスを読み込む
	try
	{
		registry_.LoadFilesPath(handle_path_);
		render_.LoadTexture(registry_.tiles_file_path());
		mapData_.LoadMapData(map_data_path_);

	}
	catch (const std::exception&)
	{

	}

}

/// <summary>
/// 描画
/// </summary>
/// <param name="camera"> カメラクラスの座標を取得 </param>
void MapManager::Render(const Camera& camera) {
	try
	{
		//	描画
		render_.Render(mapData_, camera);

	}
	catch (const std::exception&)
	{
		
	}
}