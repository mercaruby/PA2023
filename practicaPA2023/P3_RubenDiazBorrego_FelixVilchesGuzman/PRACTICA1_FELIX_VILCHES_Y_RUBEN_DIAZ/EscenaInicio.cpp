#include "EscenaInicio.h"
void EscenaInicio::ProcessKeyPressed(unsigned char key, int px, int py)
{


	switch (key) {
	case 'm':
	case 'M':
		this->finEscena = true;
		//this->activeScene->ClearScene();	//Reiniciar Nivel
		break;


	}



}

void EscenaInicio::Render()
{
	// Asegúrate de llamar a la función Render de la cámara compartida  

	this->camara.Render();


	// Renderiza los objetos en la escena  
	Scene::Render();
}