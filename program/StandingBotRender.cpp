#include "StandingBotRender.h"
#include "TextureResourceMng.h"
#include "Camera.h"
#include"GameObject.h"
#include "ColliderComp.h"

StandBotRender::StandBotRender(){
	res_texture_ = TextureResourceMgr::Instance().GetTexture(res_tex_filePath_);
	
}

void StandBotRender::Render()
{
	//	取得
	auto camera_pos = Camera::Instance().position();
	auto camera_size = Camera::Instance().area_size();
	//	座標
	const auto& trans = GetGameObj()->transform.WorldPosition();
	//	サイズ
	const auto& size = GetGameObj()->GetComponent<ColliderComp>()->size();

}
