#include "CamaraFija.h"
void CamaraFija::Render() {
	glRotatef(getOri().GetX(), 1.0, 0.0, 0.0);
	glRotatef(getOri().GetY(), 0.0, 1.0, 0.0);
	glRotatef(getOri().GetZ(), 0.0, 0.0, 1.0);
	glTranslatef(-1 * this->getPos().GetX(), -1 * this->getPos().GetY(), -1 * this->getPos().GetZ());
}

void CamaraFija::ProcessKeyPressed(unsigned char key, int px, int py)
{
	switch (key) {
	case 'f':
	case 'F':
		this->setP(Vector3D(5.0f, 7.0f, 18.0f)); //camara frontal
		this->setOri(Vector3D(20.0f, 0.0f, 0.0f));

		break;

	case 'l':
	case 'L':
		this->setP(Vector3D(5.0f, 30.0f, -6.0f)); //camara Lateral
		this->setOri(Vector3D(90.0f, -90.0f, 0.0f));

		break;

	case 'c':
	case 'C':
		this->setP(Vector3D(5.0f, 25.0f, -3.0f)); //camara Aerea
		this->setOri(Vector3D(90.0f, 0.0f, 0.0f));
		break;


	}

}