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

	void Init();					//Método de inicialización: será invocado desde la función initGraphics
	void Render();					//Método de dibujado: se llamará desde la función display.
	void Update();					//Método de actualización: será invocado desde la función idle.
	void ProcessKeyPressed(unsigned char key, int px, int py);  //Un método para recoger la información de pulsación de teclas : se llamará desde la función keyPressed.
	void ProcessMouseMovement(int x, int y);						//Un método para recoger la información de movimiento del ratón : se llamará desde la función mouseMoved.
	void ProcessMouseClick(int button, int state, int px, int py);  //Un método para recoger la información de pulsación de ratón : se llamará desde la función mousePressed.

	


};

