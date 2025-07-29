#pragma once
#include<vector>
#include<memory>
#include"singleton.h"


class GameObject;
/// <summary>
/// �Q�[���I�u�W�F�N�g�̃C���X�^���X�̊Ǘ�
/// ���ʃ��\�b�h�̌Ăяo��
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