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
	// Aseg�rate de llamar a la funci�n Render de la c�mara compartida  

		this->camara.Render();


	// Renderiza los objetos en la escena  
	Scene::Render();
}