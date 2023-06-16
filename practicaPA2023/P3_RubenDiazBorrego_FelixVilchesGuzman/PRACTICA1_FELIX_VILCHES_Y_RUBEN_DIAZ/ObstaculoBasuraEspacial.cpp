﻿#include "ObstaculoBasuraEspacial.h"
#include "EscenaJuego.h"

void ObstaculoBasuraEspacial::Update(const float& time, const Vector3D& gravity) {
	

	Solid::Update(time, gravity); 

	//cogemos el valor anterior y le sumamos para se cambie
	this->setRZ(getRZ() + 5); //con this->setOriZ(10); machacar�amos lo que hacemos en solid con la orientacion, solo para que rote una cantidad fija

	//cout << getRZ() << endl;

	//asignamos una velocidad solo en un eje para que el obst�culo rebote en el lado derecho
	Vector3D rebote = (getVel() + (0, 0, 0.01));

	this->setVel(rebote);
}
