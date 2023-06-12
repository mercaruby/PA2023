#pragma once
#include "Scene.h"
#include "Text.h"
#include "CamaraFija.h"
#include <iostream>

using namespace std;
class EscenaInicio : public Scene {

	CamaraFija camara;
	vector <Solid*> gameObjects;

public:
	EscenaInicio(Vector3D posCamara = Vector3D(5.0f, 5.0f, 20.0f),
		Vector3D rotCamara = Vector3D(20.0f, 0.0f, 0.0f)) :
		Scene(), camara(CamaraFija(posCamara, rotCamara)) {
		crearEscenaInicio();
	

		//Text* info = new Text();
		//info->setP(Vector3D(-8, 8, -4));
		//info->setC(Color(1, 120, 120));
		//info->setText("VIDEOJUEGO CREADO POR RUBEN DIAZ BORREGO Y FELIX VILCHES GUZMAN");
		//this->AddGameObject(info);


		//Text* infoCtrl = new Text();
		//infoCtrl->setP(Vector3D(-6, 12, -4));
		//infoCtrl->setC(Color(1, 120, 120));
		//infoCtrl->setText("Mover Izquierda <-| A |     | D |-> Mover Derecha ");
		//this->AddGameObject(infoCtrl);

		//Text* infoCam = new Text();
		//infoCam->setP(Vector3D(-9, 15, -4));
		//infoCam->setC(Color(1, 120, 120));
		//infoCam->setText("| C |-> Vista Aerea  | L |-> Vista Lateral  | F |-> Vista Frontal ");
		//this->AddGameObject(infoCam);

		//Text* infoScene = new Text();
		//infoScene->setP(Vector3D(-10, 15, -4));
		//infoScene->setC(Color(1, 120, 120));
		//infoScene->setText("Pulsa M para Jugar ");
		//this->AddGameObject(infoScene);
    }



	void ProcessKeyPressed(unsigned char key, int px, int py);
	void Render() override;
	void addGameObject(Solid* object);
	void crearEscenaInicio();

	void ClearScene() {
		gameObjects.clear();
	}

	void resetScene(){};
	void Update(const double& dt) {};
};