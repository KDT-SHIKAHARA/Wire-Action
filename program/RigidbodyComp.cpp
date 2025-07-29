#include "RigidbodyComp.h"
#include "GameObject.h"
#include"Time.h"
#include<cmath>
#include<algorithm>

RigidbodyComp::RigidbodyComp(float arg_mass , Flag arg_isGravity, Flag arg_isStatic)
	:mass_(arg_mass), velocity_(0,0), acceleration_(0,0), gravity_(0,0), totalForce_(0,0), damping_(0.5), isGravity_(arg_isGravity), isGrounded_(false),isStatic_(arg_isStatic)
{}

/// <summary>
/// 外力の追加
/// </summary>
/// <param name="arg_force"> 外力の追加 </param>
void RigidbodyComp::AddForce(const Vector2D<float>& arg_force){
	totalForce_ += arg_force;
}

void RigidbodyComp::AddVelocity(const Vector2D<float>& arg_velocity)
{
	velocity_ += arg_velocity;
}

/// <summary>
/// 移動ベクトルの設定
/// </summary>
/// <param name="arg_velocity"> 移動ベクトルの設定 </param>
void RigidbodyComp::SetVelocity(const Vector2D<float>& arg_velocity){
	velocity_ = arg_velocity;

}

/// <summary>
/// 物理挙動の計算と移動量の加算
/// </summary>
void RigidbodyComp::Update(){

	////	減衰量の範囲制限
	damping_ = std::clamp(damping_, 0.0f, 1.0f);

	//	親のweak_ptrをlockして取得
	auto GameObj = GetGameObj();
	if (!GameObj) return;

	//	デルタ時間取得
	const auto& deltaTime = Time::deltaTime();

	//	物理挙動実行判定
	if (!isStatic_) {

		//	重力実行判定
		if (isGravity_) {

			//	合計値 *= 重力定数 * 重さ 
			totalForce_ += Vector2D<float>(0, kGravity * mass_);
		}

		//	加速度 = 外力 / 質量
		acceleration_ = totalForce_ / mass_;
		velocity_ += acceleration_ ;



		//	外力のリセット
		totalForce_.Clear();

	}
	

	//	減衰量 (等倍 - 減衰量)
	velocity_.x *= (1.0f - damping_);

	//	移動処理は、別の場所で行って移動量だけ保存するクラスにする。

	////	移動処理は常に行う
	//GameObj->transform.AddPosition(velocity_ * deltaTime);


} 
