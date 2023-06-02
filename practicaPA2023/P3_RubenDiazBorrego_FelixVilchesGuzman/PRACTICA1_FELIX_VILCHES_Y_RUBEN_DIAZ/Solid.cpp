#include "Solid.h"
#include <iostream>

using namespace std;

 void Solid::Update(const float& time, const Vector3D& gravity) {

	this->setRX(getRX() + getOriX() * time);
	this->setRY(getRY() + getOriY() * time);
	this->setRZ(getRZ() + getOriZ() * time);


	this->setP(Vector3D(this->getPos() + this->getVel() * time));

	this->setOri(
		Vector3D(
			this->getOri().GetX() + time * this->getOri().GetX(),
			this->getOri().GetY() + time * this->getOri().GetY(),
			this->getOri().GetZ() + time * this->getOri().GetZ()
		));

	if (this->GetIsAffectedByGravity())
	{
		this->setVel(Vector3D(this->getVel() + gravity * time));
	}
}