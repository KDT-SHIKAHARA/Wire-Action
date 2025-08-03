#pragma once
#include<vector>
#include<memory>
#include"singleton.h"
#include"GameObject.h"



/// <summary>
/// ゲームオブジェクトのインスタンスの管理
/// 共通メソッドの呼び出し
/// </summary>
class GameObjMgr :public Singleton<GameObjMgr>{
	friend class Singleton<GameObjMgr>;

	GameObjMgr() = default;
	virtual ~GameObjMgr() =default;
	using GameObjList= std::vector<std::shared_ptr<GameObject>>;

	//	削除フラグが立っているゲームオブジェクトの削除
	void DestroyedGameObjects() {
		gameObjs_.erase(
			std::remove_if(
				gameObjs_.begin(),
				gameObjs_.end(),
				[](const std::shared_ptr<GameObject>& obj) { 
					return obj->isDestroyed;
				}), 
			gameObjs_.end());
	}

public:
	//	ゲームオブジェクトの追加
	void AddGameObject(std::shared_ptr<GameObject> gameObj) {
		gameObjs_.push_back(gameObj);
	};

	//	更新
	void Update() {
		for (auto& gameObj : gameObjs_) {
			gameObj->Update();
		}

		//	削除
		DestroyedGameObjects();

	}

	//	描画
	void Render() {
		for (auto& gameObj : gameObjs_) {
			gameObj->Render();
		}
	}

	const GameObjList& GetGameObjList()const { return gameObjs_; }
private:
	GameObjList gameObjs_;
};

