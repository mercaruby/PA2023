#include "Jugador.h"

void Jugador::cambiarVel(float v) {
	this->velocidad = v;
}

void Jugador::ProcessKeyPressed(unsigned char key, int px, int py) {
	switch (key)
	{
	case 'a':
	case 'A':
		if (this->getPos().GetX() > -1.0f) {   //para no salirse de los bordes
			this->setP(Vector3D(this->getPos().GetX() - velocidad, 0.0f, 10.0f));

		}
		break;
	
	case 'd':
	case 'D':
		if (this->getPos().GetX() < 10.0f) {
			this->setP(Vector3D(this->getPos().GetX() + velocidad, 0.0f, 10.0f));

		}
		break;
	
	default:
		break;
	}

}