#include "Camera.h"
void Camera::Render() {
	glTranslated(-1 * this->getPosX(), -1 * this->getPosY(), -1 * this->getPosZ());

	glRotatef(getRX(), 1.0, 0.0, 0.0);
	glRotatef(getRY(), 0.0, 1.0, 0.0);
	glRotatef(getRZ(), 0.0, 0.0, 1.0);
}

void Camera::Update(const float& time, const Vector3D& gravity){}
