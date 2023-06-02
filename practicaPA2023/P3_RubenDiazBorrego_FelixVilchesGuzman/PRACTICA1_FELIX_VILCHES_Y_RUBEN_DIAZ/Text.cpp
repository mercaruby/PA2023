#include "Text.h"

void Text::Render() 
	{
	glPushMatrix();

	glTranslatef(getPosX(), getPosY(), getPosZ());
	glColor3f(getColR(), getColG(), getColB());
	glRasterPos3d(0, 0, 0);
	for (char c : text)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
	glPopMatrix();

	}