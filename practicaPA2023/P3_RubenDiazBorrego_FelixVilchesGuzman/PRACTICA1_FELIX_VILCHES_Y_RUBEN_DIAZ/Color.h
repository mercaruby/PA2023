#pragma once
#include <GL/glut.h>

class Color
{

private:
	float R;
	float G;
	float B;
	float limit(int x);

public:

	Color(float R=0.0, float G=0.0, float B=0.0) : R(R), G(G), B(B) {}

	inline float GetR() const { return this->R; }
	inline float GetG() const { return this->G; }
	inline float GetB() const { return this->B; }

	
	inline void SetR(const float& RToSet) { this->R =  limit(RToSet); }
	inline void SetG(const float& GToSet) { this->G =  limit(GToSet); }
	inline void SetB(const float& BToSet) { this->B =  limit(BToSet); }
	

};

