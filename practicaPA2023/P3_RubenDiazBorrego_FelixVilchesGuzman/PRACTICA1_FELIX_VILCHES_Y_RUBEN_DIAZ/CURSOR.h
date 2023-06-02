#pragma once
#include "Model.h"
class CURSOR:public Vector3D
{

public:
	CURSOR() {}

	void situarCursor(int x, int y);
	void ocultarCursor();


};

