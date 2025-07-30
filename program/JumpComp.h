#pragma once
#include"Component.h"


/// <summary>
/// ジャンプ処理を追加するコンポーネント
/// </summary>
class JumpComp : public Component {
public:
	/// <summary>
	/// キー状態の参照と移動量の設定
	/// </summary>
	void Update()override;

};