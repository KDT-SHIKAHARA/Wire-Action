#include "Camera.h"
#include "SystemConfig.h"

Camera::Camera(){
	//	�������W�̐ݒ�
	position_ = { (float)WINDOW_W / 2 , (float)WINDOW_H / 2 };
	//	�\���͈͂̐ݒ�
	area_size_ = { (float)WINDOW_W ,(float)WINDOW_H};
}
