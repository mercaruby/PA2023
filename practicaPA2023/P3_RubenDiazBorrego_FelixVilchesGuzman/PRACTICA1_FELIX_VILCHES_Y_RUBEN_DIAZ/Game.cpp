#include "Game.h"
#include <iostream>

using namespace std;

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{

	//de momento no hacemos nada...
	/*cout << "Tecla pulsada: " << key << endl;*/

	this->activeScene->ProcessKeyPressed(key, px, py);




	//switch (key) {
	//case 'm':
	//case 'M':
	//	//this->activeScene->ClearScene();	//Reiniciar Nivel
	//	this->Init();
	//	break;
	

}




void Game::ProcessMouseMovement(int x, int y)
{
	//de momento no hacemos nada...
	/*cout << "Movimiento del raton: " << x << "," << y << endl;*/

}

void Game::ProcessMouseClick(int button, int state, int x, int y)
{
	//de momento no hacemos nada...
	/*cout << "Click: " << button << endl;*/

}


void Game::Init()
{

int obstaculos = 3; 

EscenaInicio* inicioScene = new EscenaInicio();
EscenaJuego* mainScene = new (nothrow) EscenaJuego(obstaculos);
EscenaFin* finScene = new EscenaFin();


//this->scenes.push_back(mainScene);
//this-> activeScene =  mainScene;

 // Añadir las instancias al vector 'scenes'  
this->scenes.push_back(inicioScene);
this->scenes.push_back(mainScene);
this->scenes.push_back(finScene);
//scenes.push_back(finalScene);

// Establecer activeScene como inicioScene para comenzar con la escena de inicio  
this->activeScene = inicioScene;

cout << activeScene << endl;
cout << "LO DE ENCIMA ES ACTIVE SCENE" << endl;
}


void Game::Render()
{
	this->activeScene->Render();
}

void Game::Update()
{
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD)
	{
		this->activeScene->Update(TIME_INCREMENT);
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}

	if (this->activeScene->GetFinEscena()) {

		this->activeScene->SetFinEscena(false);

		// Buscar la posición actual de la escena activa en el vector 'scenes'  
		auto it = find(scenes.begin(), scenes.end(), activeScene);

		// Avanzar al siguiente elemento en el vector 'scenes', si es posible  
		if (it != scenes.end()) {
			// Si está en la última posición del vector, volver a la posición 0  
			if (it + 1 == scenes.end()) {
				activeScene = static_cast<EscenaJuego*>(*scenes.begin());
				//this->activeScene->ClearScene();
			}
			else {
				activeScene = static_cast<EscenaJuego*>(*(it + 1));
			}
		}
	}
	
}
