#include "Cylinder.h"
void Cylinder::Render() {
	GLUquadricObj* quadricTemp = gluNewQuadric();
	glPushMatrix();

	glTranslatef(getPosX(), getPosY(), getPosZ());
	glColor3f(getColR(), getColG(), getColB());

	glRotatef(getRX(), 1.0, 0.0, 0.0);
	glRotatef(getRY(), 0.0, 1.0, 0.0);
	glRotatef(getRZ(), 0.0, 0.0, 1.0);


	gluCylinder(quadricTemp, this->GetRadB(), this->GetRadPS(), this->GetAltura(), this->GetSlices(), this->GetSlacks());

	glPopMatrix();
	gluDeleteQuadric(quadricTemp);

}