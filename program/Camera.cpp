#include "Camera.h"
#include "SystemConfig.h"

Camera::Camera(){
	//	初期座標の設定
	position_ = { (float)WINDOW_W / 2 , (float)WINDOW_H / 2 };
	//	表示範囲の設定
	area_size_ = { (float)WINDOW_W ,(float)WINDOW_H};
}
