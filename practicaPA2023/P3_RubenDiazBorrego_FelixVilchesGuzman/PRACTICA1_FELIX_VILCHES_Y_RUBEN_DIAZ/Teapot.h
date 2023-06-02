#pragma once
#include "Solid.h"
#include <GL/glut.h>

class Teapot:public Solid
{
private:

	float size;

public:

	Teapot(Vector3D p = Vector3D(0, 0, -2), Color c = Color(1, 0, 0), Vector3D r = Vector3D(0, 0, 0), float s = 0.4 ) : Solid(p,c,r), size(s) {}

	inline float GetSize() const { return this->size; }

	inline void setSize(const float& SZ) { this-> size = SZ; }

	void Render();

};

