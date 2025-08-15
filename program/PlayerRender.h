#pragma once
#include<unordered_map>
#include<string>
#include<memory>

#include"Anim2D.h"
#include"Component.h"
#include"DrawableComp.h"


class PlayerStateComp;

/// <summary>
/// PlayerStateComp‚Ì“à•””’l‚ğŒ©‚Ä
/// </summary>
class PlayerAnim : public Component, public DrawableComp {

	enum class AnimType {
		Idle,
		Jump,
		Run,
		Wire,
		Attack,
		Extra,
		Damage,
		Dead,
	};

public:
	void Initialize(std::shared_ptr<PlayerStateComp> state) {
		state_ = state;
	}

	PlayerAnim();
	virtual ~PlayerAnim() = default;

	void Update()override;
	void Render()override;

private:
	std::shared_ptr<PlayerStateComp> state_;
	std::unordered_map<AnimType, Anim2D> animations_;
	AnimType now_type_ = AnimType::Idle;
};
