#pragma once
#include "Solid.h"
#include <GL/glut.h>

class Torus: public Solid
{

	private:
		float radI, radE, caras, anillos;

	public:

		Torus(Vector3D p = Vector3D(0, 0, -2), Color c = Color(1, 0, 0), Vector3D r = Vector3D(0, 0, 0), float rdI = 0.5, float rdE = 1.5, float ca = 0.5, float ani = 1.5) : Solid(p, c, r), radI(rdI), radE(rdE), caras(ca), anillos(ani) {}

		inline float GetRadI() const { return this->radI; }
		inline float GetRadE() const { return this->radE; }
		inline float GetFaces() const { return this->caras; }
		inline float GetRings() const { return this->anillos; }

		inline void setRadI(const float& rdI) { this->radI = rdI; }
		inline void setRadE(const float& rdE) { this->radE = rdE; }
		inline void setFaces(const float& ca) { this->caras = ca; }
		inline void setRings(const float& ani) { this->anillos = ani; }

		//para cambiar todos los parametros en una linea
		inline void setParameters(float rdI, float rdE, float ca, float ani) { radI = rdI, radE = rdE, caras = ca, anillos = ani; }

		void Render();
	};





