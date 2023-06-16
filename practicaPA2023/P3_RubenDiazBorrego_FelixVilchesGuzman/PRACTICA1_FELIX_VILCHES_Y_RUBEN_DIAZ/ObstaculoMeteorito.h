#pragma once
#include "Sphere.h"
#include "Enemigos.h"

using namespace std;
class ObstaculoMeteorito: public Enemigos {

public:
    ObstaculoMeteorito() {}
    ObstaculoMeteorito(Vector3D pos, Color col, Vector3D vel, Vector3D rot)
        : Enemigos("..\\3dModels\\nave1.obj", pos, col = Color(0, 90, 0) , vel) {}
    //void CambiarColorConTiempo();
    void Update(const float& time, const Vector3D& gravity) override;

};

