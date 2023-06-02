#include "Cuboid.h"


void  Cuboid::Render() {
	glPushMatrix();

	glTranslatef(getPosX(), getPosY(), getPosZ());
	glColor3f(getColR(), getColG(), getColB());

	glRotatef(getRX(), 1.0, 0.0, 0.0);
	glRotatef(getRY(), 0.0, 1.0, 0.0);
	glRotatef(getRZ(), 0.0, 0.0, 1.0);

	glScalef(this->GetL(),this->GetH(),this->GetW());
	glutSolidCube(1);

	glPopMatrix();

}