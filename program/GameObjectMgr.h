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

