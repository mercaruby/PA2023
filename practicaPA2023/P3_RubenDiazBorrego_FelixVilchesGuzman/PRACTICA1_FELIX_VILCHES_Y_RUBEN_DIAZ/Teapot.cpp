#include "Teapot.h"
#include"Vector3D.h"
#include "Color.h"

void  Teapot::Render() {
	glPushMatrix();
	glTranslatef(getPosX(), getPosY(), getPosZ());
	glColor3f(getColR(), getColG(), getColB());

	glRotatef(getRX(), 1.0, 0.0, 0.0);
	glRotatef(getRY(), 0.0, 1.0, 0.0);
	glRotatef(getRZ(), 0.0, 0.0, 1.0);

	glutSolidTeapot(this->GetSize());

	glPopMatrix();

}