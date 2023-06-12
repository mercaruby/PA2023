#pragma once
#include <GL/glut.h>
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "Torus.h"
#include "Cylinder.h"
#include "Solid.h"
#include "Scene.h"
#include "Camera.h"
#include "Model.h"
#include "ModelLoader.h"
#include "Triangle.h"
#include "Text.h"
#include <vector>
#include <chrono>
#include "EscenaJuego.h"
#include "EscenaInicio.h"
#include "EscenaFin.h"

using namespace std::chrono;
using namespace std;

class Game
{

private:
	const double TIME_INCREMENT = 0.2; //ms de tiempo en el juego
	const int UPDATE_PERIOD = 10; //ms tiempo en el mundo real

	milliseconds initialMilliseconds;
	long lastUpdatedTime;

	Scene* activeScene;
	//EscenaJuego* texto;


	vector<Scene*> scenes;
	Camera* camara;


public:
	Game(): activeScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0) { };

	void Init();					//M�todo de inicializaci�n: ser� invocado desde la funci�n initGraphics
	void Render();					//M�todo de dibujado: se llamar� desde la funci�n display.
	void Update();					//M�todo de actualizaci�n: ser� invocado desde la funci�n idle.
	void ProcessKeyPressed(unsigned char key, int px, int py);  //Un m�todo para recoger la informaci�n de pulsaci�n de teclas : se llamar� desde la funci�n keyPressed.
	void ProcessMouseMovement(int x, int y);						//Un m�todo para recoger la informaci�n de movimiento del rat�n : se llamar� desde la funci�n mouseMoved.
	void ProcessMouseClick(int button, int state, int px, int py);  //Un m�todo para recoger la informaci�n de pulsaci�n de rat�n : se llamar� desde la funci�n mousePressed.

	


};

