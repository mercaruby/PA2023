#pragma once
#include "Triangle.h"
#include <vector>
#include "Scene.h"

using namespace std;

class Model:public Solid
{
private:
	
public:
	vector <Triangle> triangles;
	Model() : Solid() {};

	Model(Vector3D positionToSet, Color colorToSet, Vector3D speedToSet = Vector3D())
		: Solid(positionToSet, colorToSet, speedToSet, Vector3D(), Vector3D(), false) {}


     void AddTriangles(Triangle t) { triangles.push_back(t); }
	 void Render();
	 void Clear();
	 void PaintColor(Color color);
	 void Update(const float& dt, const Vector3D& gravity) ;
};

