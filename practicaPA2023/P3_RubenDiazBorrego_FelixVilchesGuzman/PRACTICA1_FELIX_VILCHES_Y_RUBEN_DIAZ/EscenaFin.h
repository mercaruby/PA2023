#pragma once
#include "Scene.h"
#include "Text.h"
#include "CamaraFija.h"

class EscenaFin:public Scene
{

	CamaraFija camara;

public:
	EscenaFin(Vector3D posCamara = Vector3D(5.0f, 5.0f, 20.0f), Vector3D rotCamara = Vector3D(20.0f, 0.0f, 0.0f)) : Scene(), camara(CamaraFija(posCamara, rotCamara)) 
	{

		Text* info = new Text();
		info->setP(Vector3D(-8, 8, -4));
		info->setC(Color(1, 120, 120));
		info->setText("GAME OVER");
		this->AddGameObject(info);

		Text* infoScene = new Text();
		infoScene->setP(Vector3D(-10, 15, -4));
		infoScene->setC(Color(1, 120, 120));
		infoScene->setText("Pulsa M para Jugar ");
		this->AddGameObject(infoScene);
	}

	void ClearScene() {
		gameObjects.clear();
	}

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void Render();
};

