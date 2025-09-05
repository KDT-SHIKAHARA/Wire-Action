#include "Gun.h"
#include "GameObjectMgr.h"
#include "ColliderComp.h"
#include "Hit.h"
#include "health.h"
#include "GetColor.h"
#include "input.h"
#include "PlayerStateController.h"

#include<DxLib.h>

Bullet::Bullet(const Vector2Df& a_position, const Vector2Df& a_velocity, float a_radius, float a_attack)
	:m_position(a_position), m_velocity(a_velocity), m_radius(a_radius), m_attack(a_attack)
{

}

void Bullet::Update() {
	if (!m_enable) return;
	m_position += m_velocity;
	//	当たり判定
	auto enemyList = GameObjMgr::Instance().GetGameObjWithTag(Tag::GetString(TagType::Enemy));
	for (auto enemy : enemyList) {
		//	当たり判定用のコンポーネントの確認
		auto colldier = enemy->GetComponent<ColliderComp>();
		if (!colldier) continue;
		auto size = colldier->size();
		//	円と四角形の当たり判定
		if (Hit::CheckCircleRect(enemy->transform.WorldPosition(), size,
			m_position, m_radius)){
			//	体力コンポーネントを作って、生存の管理コンポーネントを作成。
			auto healsh = enemy->GetComponent<Health>();
			if (!healsh) return;
			healsh->Damage(m_attack);
		}	//	if
	} // for
} // func

void Bullet::Render() {
	DrawCircleAA(m_position.x, m_position.y, m_radius, 50, BLUE, TRUE);
}

void Gun::shoot()
{
	
}
