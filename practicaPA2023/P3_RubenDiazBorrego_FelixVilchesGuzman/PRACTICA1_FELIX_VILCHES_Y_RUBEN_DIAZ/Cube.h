#pragma once
#include "Solid.h"
#include <GL/glut.h>

class Cube: public Solid
{
private:

	float size;

public:

	Cube (Vector3D p = Vector3D(0, 0, -2), Color c = Color(1, 0, 0), Vector3D r = Vector3D(0, 0, 0), float s = 0.4) : Solid(p, c, r), size(s) {}

	Cube(Vector3D position, Color color, Vector3D speed, Vector3D orientation, float rad = 1.0, int slices = 20, int slacks = 20) :
		Solid(position, color, speed, orientation, Vector3D(), true), size(size) {}

	inline float GetSize() const { return this->size; }

	inline void setSize(const float& SZ) { this->size = SZ; }

	void Render();

};

