#pragma once
#include "Solid.h"
#include "Model.h"
#include <iostream>
#include "ModelLoader.h"
#include "Cylinder.h"

class Jugador: public Model
{
private:
	float colisionIzq = 0.7;
	float colisionDer = 0.7;

	float velocidad = 0.45f;


public: 
	Jugador() {

		ModelLoader* loader = new ModelLoader();
		loader->LoadModel("..\\3dModels\\nave1.obj");
		this->triangles = loader->getModelo().triangles;
		this->setC(Color(0, 120, 0));
		this->SetIsAffectedByGravity(false);
		this->setVel(Vector3D(velocidad, 0, 0));
	}


	void cambiarVel(float v);
	inline float getColisionIzq() { return colisionIzq; }
	inline float getColisionDer() { return colisionDer; }
	void ProcessKeyPressed(unsigned char key, int px, int py);

};

