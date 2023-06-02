#pragma once
#include "Solid.h"
#include <GL/glut.h>

class  Sphere:public Solid
{
private:
	

	float radio;
	float slices;
	float slacks;

public:

	Sphere(Vector3D p = Vector3D(0, 0, -2), Color c = Color(1, 0, 0), Vector3D r = Vector3D(0, 0, 0), float rad = 0.25, float sli = 20, float sla= 20) : Solid(p, c, r), radio(rad), slices(sli), slacks(sla) {}
	Sphere(Vector3D position, Color color, Vector3D speed, Vector3D orientation, float rad = 1.0, int slices = 20, int slacks = 20) :
		Solid(position, color, speed, orientation, Vector3D(), true), radio(rad), slices(slices), slacks(slacks) {}

	inline float GetRadius() const { return this->radio; }
	inline void SetRadius(const float& RD) { this->radio = RD; }
	
	inline float GetSlices() const { return this->slices; }
	inline void SetSlices(const float& SLI) { this->slices = SLI; }
	
	inline float GetSlacks() const { return this->slacks; }
	inline void SetSlacks(const float& SLC) { this->slacks = SLC; }

	inline void setParameters(float RD, float SLI, float SLC) { radio=RD, slices=SLI, slacks= SLC; }
	void Render();

};


