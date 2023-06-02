#include "Torus.h"

void Torus::Render() {
	glPushMatrix();

	glTranslatef(getPosX(), getPosY(), getPosZ());
	glColor3f(getColR(), getColG(), getColB());

	glRotatef(getRX(), 1.0, 0.0, 0.0);
	glRotatef(getRY(), 0.0, 1.0, 0.0);
	glRotatef(getRZ(), 0.0, 0.0, 1.0);

	
	glutSolidTorus(this->GetRadI(), this->GetRadE(), this->GetFaces(), this->GetRings());

	glPopMatrix();

}