#pragma once
#include "Model.h"
#include <string>
#include "ModelLoader.h"

using namespace std;

class Enemigos: public Model
{

public:
	Enemigos() : Model() {}
	Enemigos(const string& modelPath, const Vector3D& positionToSet, const Color& colorToSet, const Vector3D& speedToSet = Vector3D()) : Model(positionToSet, colorToSet, speedToSet) 
	{
		ModelLoader loader;
		loader.LoadModel(modelPath);
		triangles = loader.getModelo().triangles;
	}

};

