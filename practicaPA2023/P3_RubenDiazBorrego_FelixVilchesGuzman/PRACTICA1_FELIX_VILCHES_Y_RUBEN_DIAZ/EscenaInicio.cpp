#include "EscenaInicio.h"
void EscenaInicio::ProcessKeyPressed(unsigned char key, int px, int py)
{
	cout << "Has pulsado" << key << endl;

	switch (key) {
	case 'm':
	case 'M':
		this->finEscena = true;
		//this->activeScene->ClearScene();	//Reiniciar Nivel
		break;
		


	}
}

void EscenaInicio::crearEscenaInicio() 
{
	cout << "ESCENA INICIO CREADA" << endl;

		Text* info = new Text();
		info->setP(Vector3D(-8, 8, -4));
		info->setC(Color(1, 120, 120));
		info->setText("VIDEOJUEGO CREADO POR RUBEN DIAZ BORREGO Y FELIX VILCHES GUZMAN");
		this->addGameObject(info);


		Text* infoCtrl = new Text();
		infoCtrl->setP(Vector3D(-6, 12, -4));
		infoCtrl->setC(Color(1, 120, 120));
		infoCtrl->setText("Mover Izquierda <-| A |     | D |-> Mover Derecha ");
		this->addGameObject(infoCtrl);

		Text* infoCam = new Text();
		infoCam->setP(Vector3D(-9, 15, -4));
		infoCam->setC(Color(1, 120, 120));
		infoCam->setText("| C |-> Vista Aerea  | L |-> Vista Lateral  | F |-> Vista Frontal ");
		this->addGameObject(infoCam);

		Text* infoScene = new Text();
		infoScene->setP(Vector3D(-10, 15, -4));
		infoScene->setC(Color(1, 120, 120));
		infoScene->setText("Pulsa M para Jugar ");
		this->addGameObject(infoScene);

}


void EscenaInicio::addGameObject(Solid* object) 
{
	this->gameObjects.push_back(object);
}


void EscenaInicio::Render()
{
	
	cout << "Estoy en la funcion Render de inicio Scene" <<endl;
	this->camara.Render();

}