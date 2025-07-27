#pragma once
#include"Component.h"
#include"flag.h"

class InputMove :public Component {
public:
	virtual ~InputMove() = default;
	void Update()override;

	//	true: “ü—Í‰Â”\ false: “ü—Í•s‰Â
	Flag isInput = true;	
private:
	//	1•bŠÔ‚ÌˆÚ“®‘¬“x
	static constexpr float move_speed_ = 50.0f;
};