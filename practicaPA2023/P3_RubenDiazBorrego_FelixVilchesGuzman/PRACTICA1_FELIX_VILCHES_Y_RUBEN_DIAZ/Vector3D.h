#pragma once
#include <GL/glut.h>

class Vector3D
{
private:
	float X;
	float Y;
	float Z;

	float rotX;
	float rotY;
	float rotZ;

	float oriX;
	float oriY;
	float oriZ;

public:



	Vector3D(float x = 0.0, float y = 0.0, float z = 0.0, float rX = 0.0, float rY = 0.0, float rZ = 0.0, float orX = 0.0, float orY = 0.0, float orZ = 0.0)
		: X(x), Y(y), Z(z), rotX(rX), rotY(rY), rotZ(rZ), oriX(orX), oriY(orY), oriZ (orZ){};



	inline float GetX() const { return this->X; }
	inline float GetY() const { return this->Y; }
	inline float GetZ() const { return this->Z; }
	
	inline float GetRotX() const { return this->rotX; }
	inline float GetRotY() const { return this->rotY; }
	inline float GetRotZ() const { return this->rotZ; }

	inline float GetOriX() const { return this->oriX; }
	inline float GetOriY() const { return this->oriY; }
	inline float GetOriZ() const { return this->oriZ; }

	inline void SetX(const float& XToSet) { this->X = XToSet; }
	inline void SetY(const float& YToSet) { this->Y = YToSet; }
	inline void SetZ(const float& ZToSet) { this->Z = ZToSet; }

	inline void SetRotX(const float& rotXToSet) { this->rotX = rotXToSet; }
	inline void SetRotY(const float& rotYToSet) { this->rotY = rotYToSet; }
	inline void SetRotZ(const float& rotZToSet) { this->rotZ = rotZToSet; }
	
	inline void SetOriX(const float& OriXToSet) { this->oriX = OriXToSet; }
	inline void SetOriY(const float& OriYToSet) { this->oriY = OriYToSet; }
	inline void SetOriZ(const float& OriZToSet) { this->oriZ = OriZToSet; }
	

	Vector3D Add(const Vector3D& b);
	Vector3D Substract(const Vector3D& b);
	Vector3D Product(const float& b);
	Vector3D Division(const float& b);
	float DotProduct(const Vector3D& v);

	Vector3D operator+(const Vector3D& b);
	Vector3D operator-(const Vector3D& b);
	Vector3D operator*(const float& b);
	Vector3D operator*(const float& b) const;
	Vector3D operator/(const float& b);
	float operator*(const Vector3D& v);

};

