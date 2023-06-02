#pragma once
#include "Model.h"
#include "ModelLoader.h"

class PowerUP:public Model
{


public:
	PowerUP() {

		ModelLoader* loader = new ModelLoader();
		loader->LoadModel("..\\3dModels\\Star.obj");
		this->triangles = loader->getModelo().triangles;
		this->setC(Color(0, 120, 0));
		this->SetIsAffectedByGravity(false);
	}
};

