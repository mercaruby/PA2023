#pragma once
#define _USE_MATH_DEFINES
#include <math.h> 
#include <GL/glut.h>
#include "Vector3D.h"
#include "solid.h"
class Camera: public Solid
{
private:

public:
	//Camera(Vector3D p = Vector3D(0, 0, 0), Vector3D r = Vector3D(0,0,0)) : Solid() {
	//	setP(p), setR(r);
	//}
	
	Camera(Vector3D positionToSet, Vector3D orientationToSet) : Solid(positionToSet, Color(), Vector3D(), orientationToSet, Vector3D(), true) {}

	Camera(float x, float y, float z) : Solid(Vector3D(x, y, z), Color(), Vector3D(), Vector3D(), Vector3D(), true) {}

	void Render();
	void Update(const float& time, const Vector3D& gravity);
};

