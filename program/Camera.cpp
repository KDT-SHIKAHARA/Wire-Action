#include "Camera.h"
#include "SystemConfig.h"

Camera::Camera(){
	//	‰ŠúÀ•W‚Ìİ’è
	position_ = { (float)WINDOW_W / 2 , (float)WINDOW_H / 2 };
	//	•\¦”ÍˆÍ‚Ìİ’è
	area_size_ = { (float)WINDOW_W ,(float)WINDOW_H};
}
