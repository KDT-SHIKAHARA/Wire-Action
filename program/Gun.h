#pragma once
#include"Component.h"
#include"DrawableComp.h"
#include"vector2d.h"



struct Bullet {
	Bullet(const Vector2Df& a_position, const Vector2Df& a_velocity,float a_radius, float a_attack);
	void Update();
	void Render();

	Vector2Df m_position;	 //	座標
	Vector2Df m_velocity;	 //	秒間の移動量
	bool m_enable = true;	 //	有効判定
private:
	float m_radius = 10;			//	半径のサイズ
	float m_attack = 1;	//	攻撃力
};

class Gun : public Component, public DrawableComp {
	void shoot();	//	発射メソッド

public:

private:
	float m_fireRate;	//	発射間隔
	float m_fireCooldown;	//	発射までのクールタイム
};
