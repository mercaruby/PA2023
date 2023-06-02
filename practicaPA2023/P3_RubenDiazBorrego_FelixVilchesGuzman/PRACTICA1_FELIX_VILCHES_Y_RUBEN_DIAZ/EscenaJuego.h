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
#include "Jugador.h"
#include "Vector3D.h"
#include "Camera.h"
#include "PowerUp.h"
#include "Ranking.h"
#include "CamaraFija.h"
#include "Jugador.h"
#include "Scene.h"
#include "ObstaculoMeteorito.h"
#include "Cuboid.h"
#include "ObstaculoBasuraEspacial.h"

using namespace std;

class EscenaJuego: public Scene
{

private:
	CamaraFija camara;
	vector <Solid*> gameObjects;
	vector <Solid*> obstaculos;
	Jugador jugador;

	PowerUP* powerUp;
	Ranking ranking;


	int numeroObst;
	float puntos = 0;
	bool derrota = false;
	bool colisionPowerUp = false;
	bool spawnedPowerUp = false;


public:

	EscenaJuego(int numObs, Vector3D posCamara = Vector3D(5.0f, 5.0f, 20.0f),
		Vector3D rotCamara = Vector3D(20.0f, 0.0f, 0.0f)) :
		Scene(), camara(CamaraFija(posCamara, rotCamara)) {
		numeroObst = numObs;
		crearEscenario();
		crearObstaculos();
		crearJugador();
		crearPowerUps();
	}



	inline int getPuntos() { return this->puntos; }
	inline void setPuntos(int puntos) { this->puntos = puntos; }

	inline CamaraFija getCamara() const { return this->camara; }
	inline void setCamara(CamaraFija camaraToSet) { this->camara = camaraToSet; }

	PowerUP* getPowerUP() { return this->powerUp; }
	void setPowerUP(PowerUP* powerToSet) { this->powerUp = powerToSet; }

	Jugador getJugador() { return this->jugador; }
	void setJugador(const Jugador& jugadorToSet) { this->jugador = jugadorToSet; }

	void addGameObject(Solid* object);
	void addObstaculos(Solid* object);
	void ClearScene();
	void Render();



	//elementos de la escena
	void crearEscenario();
	void crearObstaculos();
	void crearJugador();
	void crearPowerUps();

	
	//progreso del juego

	void Update(const float& time);
	void limitesObstaculos(const float& time);

	void comprobarColisionObstaculos();
	void comprobarColisionPowerUp();
	void spawnearPowerUP();

	void ProcessKeyPressed(unsigned char key, int px, int py);

};


