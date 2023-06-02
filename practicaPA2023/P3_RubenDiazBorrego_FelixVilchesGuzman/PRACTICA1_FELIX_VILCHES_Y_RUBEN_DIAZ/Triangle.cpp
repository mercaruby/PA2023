#include "Triangle.h"
void Triangle::Render() {
	glBegin(GL_TRIANGLES);

	glColor3f(c0.GetR(), c0.GetG(), c0.GetB());
	glNormal3f(n0.GetX(), n0.GetY(), n0.GetZ());
	glVertex3f(p0.GetX(), p0.GetY(), p0.GetZ());

	glColor3f(c1.GetR(), c1.GetG(), c1.GetB());
	glNormal3f(n1.GetX(), n1.GetY(), n1.GetZ());
	glVertex3f(p1.GetX(), p1.GetY(), p1.GetZ());

	glColor3f(c2.GetR(), c2.GetG(), c2.GetB());
	glNormal3f(n2.GetX(), n2.GetY(), n2.GetZ());
	glVertex3f(p2.GetX(), p2.GetY(), p2.GetZ());

	glEnd();
}
