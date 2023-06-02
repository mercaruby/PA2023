#pragma once
#include "Enemigos.h"
class ObstaculoBasuraEspacial: public Enemigos
{

	public:
		ObstaculoBasuraEspacial() {}
		ObstaculoBasuraEspacial(Vector3D pos, Color col, Vector3D vel, Vector3D rot)
			: Enemigos("..\\3dModels\\nave2.obj", pos, col, vel) {}

	//public:
	//	ObstaculoBasuraEspacial() {}
	//	ObstaculoBasuraEspacial(Vector3D pos, Color col, Vector3D vel, Vector3D rot) :
	//		Sphere(pos, col, vel, rot) {}

	//	void CambiarColorConTiempo();

	};


