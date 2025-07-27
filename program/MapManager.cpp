#include"MapManager.h"
#include"Rect.h"
#include"GameObject.h"
#include"ColliderComp.h"
#include"RigidbodyComp.h"
#include<cmath>
/// <summary>
/// �}�b�v�Ƃ̓����蔻����s���B
/// ���\�b�h�̌Ăяo���O�ɓ����蔻����s����I�u�W�F�N�g�����肵�Ă���Ăяo��
/// </summary>
/// <param name="gameObj"></param>
void MapManager::CheckCollision( GameObject& gameObj){

	//	�Q�[���I�u�W�F�N�g�̍��W
	const auto& obj_position = gameObj.transform.WorldPosition();

	//	�Q�[���I�u�W�F�N�g�̃T�C�Y
	const auto& gameobj_size = gameObj.GetComponent<ColliderComp>()->size();

	//	���̃Q�[���I�u�W�F�N�g�̒��O�̈ړ��x�N�g��
	const auto& gameobj_velo = gameObj.GetComponent<RigidbodyComp>()->velocity();

	//	�}�b�v�^�C���̃T�C�Y
	const auto& tile_size = mapData_.GetTileSize();

	//	�v���C���[�Ɠ������Ă���}�b�v�͈̔�

	//	�����蔻��ɕK�v�ȏ��
	Rect objRect{
		obj_position.x,
		obj_position.y,
		gameobj_size.x,
		gameobj_size.y,
	};

	//	�}�b�v�O�Ȃ�}�b�v�̐����ɂ���B
	const int left = objRect.x / tile_size;
	const int right = (objRect.x + objRect.w) / tile_size;
	const int top = objRect.y / tile_size;
	const int bottom = (objRect.y + objRect.h) / tile_size;

	//	�}�b�v�O�ɏo���瓖���蔻����I������
	auto rigit_ptr = gameObj.GetComponent<RigidbodyComp>();



	//	�}�b�v���̐����œ����蔻��
	for (int y = top; y <= bottom; y++) {
		for (int x = left; x <= right; x++) {
			if (!mapData_.IsInMap(x, y))continue;

			const auto& tile = mapData_.GetTile(x, y);
			if (!tile.isCollision) continue;

			//	�}�b�v�^�C���̋�`
			Rect tileRect{
				(float)x * tile_size,
				(float)y * tile_size,
				(float)tile_size,
				(float)tile_size,
			};

			//	�߂荞��ł��邩����
			if (objRect.IsCollision(tileRect)) {
				//	false: ���ɐi��ł��� true: �E�ɐi��ł���
				float overlap_x = (gameobj_velo.x > 0) ?
					(objRect.x + objRect.w) - tileRect.x
					: (tileRect.x + tileRect.w) - tileRect.x;

				//	false: ��ɐi��ł��� true: ���ɐi��ł���
				float overlap_y = (gameobj_velo.y > 0) ?
					(objRect.y + objRect.h) - tileRect.y
					: (tileRect.y + tileRect.h) - tileRect.y;


				//	�������ق��ɉ����߂�
				if (std::abs(overlap_x) < std::abs(overlap_y)) {
					auto tmp_vec = (gameobj_velo.x > 0) ? -overlap_x : overlap_x;

					gameObj.transform.Translate(Vector2D<float>{tmp_vec, 0});
				}

				else {
					auto tmp_vec = (gameobj_velo.y > 0) ? -overlap_y : overlap_y;
					gameObj.transform.Translate(Vector2D<float>{0, tmp_vec});

					//	�������Ȃ�
					//  �ڒn�t���O�𗧂Ă�B
					//	�d�̓t���O��܂�
					if (gameobj_velo.y > 0)
					{
						rigit_ptr->SetVelocity({ rigit_ptr->velocity().x,0 });
						rigit_ptr->isGravity_.Set(false);
						rigit_ptr->isGrounded_.Set(true);
					}

				
					//	�ړ��ʂ��Ȃ���
					

				}

				objRect.x = obj_position.x;
				objRect.y = obj_position.y;

			}
		}
	}

}

/// <summary>
/// �t�@�C������t�@�C���p�X��ǂݍ����
/// �t�@�C������摜��ǂݍ���
/// </summary>
void MapManager::Load() {
	//	�t�@�C���p�X��ǂݍ���
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
/// �`��
/// </summary>
/// <param name="camera"> �J�����N���X�̍��W���擾 </param>
void MapManager::Render(const Camera& camera) {
	try
	{
		//	�`��
		render_.Render(mapData_, camera);

	}
	catch (const std::exception&)
	{
		
	}
}