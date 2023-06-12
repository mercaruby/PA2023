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

//void Text::Render() {
//    glPushMatrix();
//
//    glTranslatef(getPosX(), getPosY(), getPosZ());
//
//    // Configura el color utilizando glColorMaterial  
//    glEnable(GL_COLOR_MATERIAL);
//    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//    glColor3f(getColR(), getColG(), getColB());
//
//    glRasterPos3d(0, 0, 0);
//
//    for (char c : text) {
//        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
//    }
//
//    // Deshabilita GL_COLOR_MATERIAL  
//    glDisable(GL_COLOR_MATERIAL);
//
//    glPopMatrix();
//}
