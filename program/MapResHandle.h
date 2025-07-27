#pragma once
#include<string>
#include<unordered_map>

/// <summary>
/// �t�@�C���p�X�̊Ǘ�
/// </summary>
class TileTextureRegistry {
public:
	//	xml�t�@�C������p�X��ǂݍ���
	//	true: �Ǎ����� false: �Ǎ����s
	void LoadFilesPath(const std::string& xml_path);
	 
	//	�^�C��ID�ɑΉ�����t�@�C���p�X��Ԃ�
	//	������Ȃ�������󕶎���Ԃ��B
	//	�f�t�H���g�t�@�C���p�X��ݒ肵�Ă�����
	std::string GetPath(int tile_id)const;

	std::unordered_map<int, std::string> tiles_file_path() { return tiles_file_path_; }

private:
	std::unordered_map<int, std::string> tiles_file_path_;
	std::string tiles_base_path_;
};