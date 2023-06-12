#include "EscenaFin.h"

void EscenaFin::ProcessKeyPressed(unsigned char key, int px, int py)
{


	switch (key) {
	case 'm':
	case 'M':
		this->finEscena = true;
		//this->activeScene->ClearScene();	//Reiniciar Nivel
		break;

	}

}

void EscenaFin::Render()
{
	// Asegúrate de llamar a la función Render de la cámara compartida  

		this->camara.Render();
		for (int i = 0; i < this->gameObjects.size(); i++)
		{
			this->gameObjects[i]->Render();
		}

	// Renderiza los objetos en la escena  
	//Scene::Render();
}


void EscenaFin::crearEscenaFin()

{

	Text* info2 = new Text();
	info2->setP(Vector3D(2, 5, -4));
	info2->setC(Color(1.0f, 120.0f, 120.0f));
	info2->setText("--- GAME OVER ---");
	this->AddGameObject(info2);

	Text* infoScene2 = new Text();
	infoScene2->setP(Vector3D(-8, 10, -4));
	infoScene2->setC(Color(1.0f, 120.0f, 120.0f));
	infoScene2->setText("Escribe tu nombre en la consola y pulsa M para Volver a Jugar ");
	this->AddGameObject(infoScene2);



}
