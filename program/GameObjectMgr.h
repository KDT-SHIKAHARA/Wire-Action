#pragma once
#include<vector>
#include<memory>
#include"singleton.h"
#include"GameObject.h"



/// <summary>
/// �Q�[���I�u�W�F�N�g�̃C���X�^���X�̊Ǘ�
/// ���ʃ��\�b�h�̌Ăяo��
/// </summary>
class GameObjMgr :public Singleton<GameObjMgr>{
	friend class Singleton<GameObjMgr>;

	GameObjMgr() = default;
	virtual ~GameObjMgr() =default;
	using GameObjList= std::vector<std::shared_ptr<GameObject>>;

public:
	//	�Q�[���I�u�W�F�N�g�̒ǉ�
	void AddGameObject(std::shared_ptr<GameObject> gameObj) {
		gameObjs_.push_back(gameObj);
	};

	//	�X�V
	void Update() {
		for (auto& gameObj : gameObjs_) {
			gameObj->Update();
		}
	}

	//	�`��
	void Render() {
		for (auto& gameObj : gameObjs_) {
			gameObj->Render();
		}
	}

	const GameObjList& GetGameObjList()const { return gameObjs_; }
private:
	GameObjList gameObjs_;
};

