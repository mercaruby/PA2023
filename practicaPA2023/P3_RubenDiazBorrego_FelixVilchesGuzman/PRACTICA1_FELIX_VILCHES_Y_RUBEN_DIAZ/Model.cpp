#include "Model.h"
 void Model::Render() {
	glPushMatrix();
	glTranslatef(this->getPosX(), this->getPosY(), this->getPosZ());
	glRotatef(this->getRot().GetX(), 1, 0, 0);
	glRotatef(this->getRot().GetY(), 0, 1, 0);
	glRotatef(this->getRot().GetZ(), 0, 0, 1);
	for (Triangle& t : triangles)
		t.Render();
	glPopMatrix();
}

 void Model::Update(const float& dt, const Vector3D& gravity = Vector3D(0.0f, -0.1f, 0.0f)) {
	for (Triangle& t : triangles) {
		t.Update(dt, gravity);
	}
	Solid::Update(dt, gravity);
}

 void Model::Clear() {
	triangles.clear();
}

 void Model::PaintColor(Color color)
{
	for (Triangle& triangle : this->triangles)
	{
		triangle.setC0(color);
		triangle.setC1(color);
		triangle.setC2(color);
	}


}