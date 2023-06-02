#pragma once
#include "Vector3D.h"
#include "Color.h"
#include <GL/glut.h>
#include "Vector3D.h"

class Solid
{
private:
	Vector3D pos;
	Vector3D rot;
	Vector3D rotVel;
	Vector3D OrientationSpeed;
	Vector3D speed;
	Color col;
	double dt = 1;

	bool isAffectedByGravity;

public:
	/*Solid(): pos(Vector3D()), col(Color()), speed(Vector3D()), rot(Vector3D()), OrientationSpeed(Vector3D()), isAffectedByGravity(true){}*/


	Solid (Vector3D p = Vector3D(0, 0, -2), Color c = Color(1, 0, 0), Vector3D r = Vector3D(0, 0, 0), Vector3D ori = Vector3D (0,0,0), Vector3D vel = Vector3D(0, 0, 0)) :
		pos(p), col(c), rot(Vector3D()), OrientationSpeed(Vector3D()), speed(Vector3D()) {}

	Solid(Vector3D pos, Color col, Vector3D speed, Vector3D orientation, Vector3D orientationSpeed, bool isAffectedByGravity) :
		pos(pos), col(col), speed(speed), rot(rot), OrientationSpeed(orientationSpeed), isAffectedByGravity(isAffectedByGravity) {}


	inline float getPosX() const { return pos.GetX(); }
	inline float getPosY() const { return pos.GetY(); }
	inline float getPosZ() const { return pos.GetZ(); }

	inline float getColR() const { return col.GetR(); }
	inline float getColG() const { return col.GetG(); }
	inline float getColB() const { return col.GetB(); }

	inline float getRX() const { return rot.GetRotX(); }
	inline float getRY() const { return rot.GetRotY(); }
	inline float getRZ() const { return rot.GetRotZ(); }

	inline float getOriX() const { return OrientationSpeed.GetOriX(); }
	inline float getOriY() const { return OrientationSpeed.GetOriY(); }
	inline float getOriZ() const { return OrientationSpeed.GetOriZ(); }

	inline void setPosX(float PX) { pos.SetX(PX); }
	inline void setPosY(float PY) { pos.SetY(PY); }
	inline void setPosZ(float PZ) { pos.SetZ(PZ); }

	inline void setColR(float CR) { col.SetR(CR); }
	inline void setColG(float CG) { col.SetG(CG); }
	inline void setPosB(float CB) { col.SetB(CB); }

	inline void setRX(float RX) { rot.SetRotX(RX); }
	inline void setRY(float RY) { rot.SetRotY(RY); }
	inline void setRZ(float RZ) { rot.SetRotZ(RZ); }

	inline void setOriX(float ori) { OrientationSpeed.SetOriX(ori); }
	inline void setOriY(float ori) { OrientationSpeed.SetOriY(ori); }
	inline void setOriZ(float ori) { OrientationSpeed.SetOriZ(ori); }

	inline Color getCol() { return col; }
	inline Vector3D getPos() { return pos; }
	inline Vector3D getRot() { return rot; }
	inline Vector3D getOri() { return OrientationSpeed; }
	inline Vector3D getVel() { return speed; }

	inline void setP(Vector3D P) { pos = P; }
	inline void setC(Color C) { col = C; }
	inline void setR(Vector3D R) { rot = R; }
	inline void setOri(Vector3D Or) { OrientationSpeed = Or; }
	inline void setVel(Vector3D v) { speed = v; }

	inline bool GetIsAffectedByGravity() const { return this->isAffectedByGravity; }
	inline void SetIsAffectedByGravity(const bool& isAffectedByGravity) { this->isAffectedByGravity = isAffectedByGravity; }


	virtual void Render() = 0;

	virtual void Update(const float& time, const Vector3D& gravity);

};


