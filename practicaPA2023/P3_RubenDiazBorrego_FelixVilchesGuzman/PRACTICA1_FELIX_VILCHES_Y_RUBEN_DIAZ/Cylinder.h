#pragma once
#include"Solid.h"

class Cylinder:public Solid

{

private:
	float radB, radPS, altura, slices, slacks;

public:

	Cylinder(Vector3D p = Vector3D(0, 0, -2), Color c = Color(1, 0, 0), Vector3D r = Vector3D(0, 0, 0), float rdB = 0.5, float rdPS = 1.5, float al = 1, float sli = 5, float sla=5) : Solid(p, c, r), radB(rdB), radPS(rdPS), altura(al), slices(sli), slacks(sla) {}

	Cylinder(Vector3D position, Color color, Vector3D speed, Vector3D rotation, float rdB = 0.5, float rdPS = 1.5, float al = 1, float sli = 5, float sla = 5) :
		Solid(position, color, speed, rotation, Vector3D(), true), radB(rdB), radPS(rdPS), altura(al), slices(sli), slacks(sla){}


	inline float GetRadB() const { return this->radB; }
	inline float GetRadPS() const { return this->radPS; }
	inline float GetAltura() const { return this->altura; }
	inline float GetSlices() const { return this->slices; }
	inline float GetSlacks() const { return this->slacks; }
	

	inline void setRadB(const float& rdB) { this->radB = rdB; }
	inline void setRadPS(const float& rdPS) { this->radPS = rdPS; }
	inline void setRadE(const float& al) { this->altura = al; }
	inline void SetSlices(const float& sli) { this->slices = sli; }
	inline void SetSlacks(const float& sla) { this->slacks = sla; }
	//para cambiar todos los parametros en una linea
	inline void setParameters(float rdB, float rdPS, float al, float sli, float sla) { radB = rdB, radPS = rdPS, altura = al, slices = sli, slacks = sla; }

	void Render();
};
