#pragma once
#include "Solid.h"
#include <GL/glut.h>


class Cuboid: public Solid
{
private:

	
	float lon, height, weight;

public:

	Cuboid(Vector3D p = Vector3D(0, 0, -2), Color c = Color(1, 0, 0), Vector3D r = Vector3D(0, 0, 0),  float l = 0.5, float h = 1.5, float w = 0.5) : Solid(p, c, r), lon(l), height(h), weight(w) {}

	inline float GetL() const { return this->lon; }
	inline float GetH() const { return this->height; }
	inline float GetW() const { return this->weight; }

	inline void setL(const float& lo) { this->lon = lo; }
	inline void setH(const float& he) { this->height = he; }
	inline void setW(const float& we) { this->weight = we; }

	//àra cambiarlos todos a la vez
	inline void setParameters(float lo, float he, float we) { lon = lo, height = he, weight = we; }


	void Render();

};


