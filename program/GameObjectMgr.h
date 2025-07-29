#pragma once
#include<vector>
#include<memory>
#include"singleton.h"


class GameObject;
/// <summary>
/// ゲームオブジェクトのインスタンスの管理
/// 共通メソッドの呼び出し
/// </summary>
class GameObjMgr :public Singleton<GameObjMgr>{
	GameObjMgr() = default;
	virtual ~GameObjMgr() = default;
	using GameObjList= std::vector<std::shared_ptr<GameObject>>;

public:
	void Update();
	void Render();
private:
	GameObjList gameObjs;
};