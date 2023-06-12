#include "EscenaJuego.h"
#include <math.h>
#include <iostream>
#include <string>
using namespace std;
void EscenaJuego::ClearScene() 
{
	this->gameObjects.clear();
	this->obstaculos.clear();

}

void EscenaJuego::addGameObject(Solid* object)
{
	this->gameObjects.push_back(object);
}
void EscenaJuego::addObstaculos(Solid* object)
{

	this->obstaculos.push_back(object);
}

void EscenaJuego::crearEscenario()
{
	/*Text* info = new Text();
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
	this->addGameObject(infoCam);*/

	Cuboid* parteIzq = new Cuboid();
	parteIzq->setP(Vector3D(-3.0f, -1.0f, 5.0f));
	parteIzq->setC(Color(1.0f, 1.0f, 120.0f));
	parteIzq->setH(0.5f);
	parteIzq->setL(0.5f);
	parteIzq->setW(1000.0f);
	parteIzq->SetIsAffectedByGravity(false);
	this->addGameObject(parteIzq);

	Cuboid* parteDer = new Cuboid();
	parteDer->setP(Vector3D(13.0f, -1.0f, 5.0f));
	parteDer->setC(Color(1.0f, 1.0f, 120.0f));
	parteDer->setH(0.5f);
	parteDer->setL(0.5f);
	parteDer->setW(1000.0f);
	parteDer->SetIsAffectedByGravity(false);
	this->addGameObject(parteDer);

}

void EscenaJuego::crearObstaculos()
{
	ObstaculoBasuraEspacial* basura = new(nothrow) ObstaculoBasuraEspacial[numeroObst];
	if (basura != nullptr) {
		for (int index = 1; index < numeroObst; index++) {
			basura[index] = ObstaculoBasuraEspacial(
				Vector3D((rand() % 13), (0.5), -25),  
				Color(120.0f, 1.0f, 1.0f),
				Vector3D((0.07 + index * 0.001), (0), (0.6 * index)),  
				0.1 + 2 * 0.1 
			);
			basura[index].SetIsAffectedByGravity(false);
			this->addObstaculos(basura + index);
		}
	}

	ObstaculoMeteorito* meteoritos = new(nothrow) ObstaculoMeteorito[numeroObst];
	if (meteoritos != nullptr) {
		for (int index = 1; index < numeroObst; index++) {
			meteoritos[index] = ObstaculoMeteorito(
				Vector3D((rand() % 13), (0.8), -25),  
				Color((120), (0), (120)),
				Vector3D((0.07 + index * 0.001), (0), (0.75 * index)), 
				0.1 + 2 * 0.1 
			);
			meteoritos[index].SetIsAffectedByGravity(false);
			this->addObstaculos(meteoritos + index);
		}
	}
}


void EscenaJuego::crearPowerUps() {

	PowerUP* item = new PowerUP();
	item->setP(Vector3D(120.0f, -4.2f, -25.0f)); 
	item->setOriX(0.0f);    
	item->setOriY(20.0f);    
	item->setOriZ(0.0f);    
	this->setPowerUP(item);
}

void EscenaJuego::crearJugador() {

	Jugador* jugador = new Jugador();
	jugador->setP(Vector3D(5.0f, 0.0f, 10.0f));
	jugador->setVel(Vector3D(0.45f, 0, 0));
	this->setJugador(*jugador);
}


void EscenaJuego::Render()
{
	this->camara.Render();
	this->jugador.Render();
	if (!colisionPowerUp) {
		this->powerUp->Render();
	}
	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Render();
	}
	for (int idx = 0; idx < this->obstaculos.size(); idx++)
	{
		this->obstaculos[idx]->Render();
	}
}

void EscenaJuego::Update(const double& time)
{
	if (!derrota) {
		this->puntos += time;

		//Text* pts = new Text();
		//pts->setP(Vector3D(5, 18, -4));
		//pts->setC(Color(1, 120, 120));
		//pts->setText(to_string(puntos));
		//this->addGameObject(pts);
		
		//LO DE ARRIBA ERA PARA HACER UN CONTADOR EN PANTALLA DE PUNTOS PERO NO FUI CAPAZ DE QUE NO SE SOBRESCRIBIESEN UNOS ENCIMA DE OTROS
		
		cout << puntos << endl;

		//Crear el power up si no se ha creado todavia
		if (!spawnedPowerUp) {
			spawnearPowerUP();
		}

		comprobarColisionObstaculos();
		comprobarColisionPowerUp();

		//Asegurarse de que los obstaculos no se salgan de la carretera
		//Cuando llegan los obstaculos al final, vuelven a la posicion de inicio
		limitesObstaculos(time);

		//Mientras que no haya colisionado el PowerUP, seguimos actualizandolo
		if (!colisionPowerUp) {
			this->powerUp->Update(time, this->GetGravity());
		}

		for (int idx = 0; idx < this->obstaculos.size(); idx++)
		{
			this->obstaculos[idx]->Update(time, this->GetGravity());

		}

		


		//Si perdemos, mostrar ranking y reiniciar
		if (derrota) {
			this->ClearScene();
			this->finEscena = true;
			cout << "HAS PERDIDO!" << endl;
			ranking.crearRanking(puntos);
			cout << "PULSA M PARA VOLVER A INTENTARLO" << endl;
			
		}

	}
}

void EscenaJuego::spawnearPowerUP() 
{
	//A los 100 puntos aparece el anillo PowerUP que nos aumentara la velocidad de movimiento
	if (puntos >= 100) {
		this->powerUp->setP(Vector3D(6.0f, 1.2f, -25.0f));
		this->powerUp->setVel(Vector3D(0.0f, 0.0f, 0.5f));
		spawnedPowerUp = true;
	}
}

void EscenaJuego::comprobarColisionObstaculos() {
	for (int idx = 0; idx < this->obstaculos.size(); idx++)
	{
		if (obstaculos[idx]->getPos().GetZ() < 11.7) { //Para que no haya colision despues de que el obstaculo sobrepase al jugador
			// Colision eje X
			bool collisionX = abs(obstaculos[idx]->getPosX() - this->jugador.getPosX()) < jugador.getColisionIzq(); 		
			// Colision eje Z
			bool collisionZ = abs(obstaculos[idx]->getPosZ() - this->jugador.getPosZ()) < jugador.getColisionDer();

			// Si hay colision en los dos ejes se para el juego y perdemos
			if (collisionX && collisionZ) {

				/*cout << endl;
				cout << jugador.getPosX() << "--";
				cout << jugador.getPosY() << "--";
				cout << jugador.getPosZ() << endl;
				cout << obstaculos[idx]->getPosX() << "--";
				cout << obstaculos[idx]->getPosY() << "--";
				cout << obstaculos[idx]->getPosZ() << "--" << endl;*/

				this->jugador.setVel(Vector3D(0, 0, 0));
				for (int idx = 0; idx < this->obstaculos.size(); idx++)
				{
					this->obstaculos[idx]->setVel(Vector3D(0, 0, 0));
				}
				derrota = true;
			}
		}
	}
}

void EscenaJuego::comprobarColisionPowerUp() {

	//Colision con el PowerUP
	if (powerUp->getPos().GetZ() < 11.7) {

		bool collisionX = abs(powerUp->getPosX() - this->jugador.getPosX()) < jugador.getColisionIzq();
		bool collisionZ = abs(powerUp->getPosZ() - this->jugador.getPosZ()) < jugador.getColisionDer();

		if (collisionX && collisionZ) {
			this->jugador.cambiarVel(this->jugador.getVel().GetX() * 2);
			colisionPowerUp = true;
			delete this->powerUp;
		}
	}
	if (powerUp->getPos().GetZ() > 12) {
		colisionPowerUp = true;
		delete this->powerUp;
	}
}


void EscenaJuego::limitesObstaculos(const float& time) {

	for (int idx = 0; idx < this->obstaculos.size(); idx++)
	{
		//Para que los obstaculos no se salgan del mapa
		this->obstaculos[idx]->Update(time, this->GetGravity());

		if (this->obstaculos[idx]->getPos().GetX() > this->GetSize().GetX()
			|| this->obstaculos[idx]->getPos().GetX() < 0) {

			this->obstaculos[idx]->setVel(Vector3D(this->obstaculos[idx]->getVel().GetX() * -1,
				this->obstaculos[idx]->getVel().GetY(), this->obstaculos[idx]->getVel().GetZ()));
		}
		if (this->obstaculos[idx]->getPos().GetY() > this->GetSize().GetY() ||
			this->obstaculos[idx]->getPos().GetY() < 0) {

			this->obstaculos[idx]->setVel(Vector3D(this->obstaculos[idx]->getVel().GetX(),
				this->obstaculos[idx]->getVel().GetY() * -1, this->obstaculos[idx]->getVel().GetZ()));
		}
		//Si los obstaculos llegan al final, vuelven a spawnear, para que haya obstaculos ilimitados
		if (this->obstaculos[idx]->getPos().GetZ() > 20 ||
			this->obstaculos[idx]->getPos().GetZ() < -30) {

			this->obstaculos[idx]->setP(Vector3D((rand() % 13), (0.5), -25));
		}
	}
}

void EscenaJuego::ProcessKeyPressed(unsigned char key, int px, int py)
{
	this->jugador.ProcessKeyPressed(key, px, py);
	this->camara.ProcessKeyPressed(key, px, py);
}

void EscenaJuego::resetObstacles() {
	// Reinicia el número de obstáculos y otros parámetros relacionados  
	numeroObst = 3; // Por ejemplo, puedes cambiar esto a otro valor si deseas que el juego sea más difícil o más fácil al reiniciar  

	// Limpia los obstáculos actuales  
	for (Solid* obstacle : obstaculos) {
		delete obstacle;
	}
	obstaculos.clear();

	// Recrea los obstáculos  
	crearObstaculos();
}

void EscenaJuego::resetScene() {
	ClearScene(); // Limpia la escena actual  
	crearEscenario(); // Recrea el escenario  
	resetObstacles(); // Reinicia y recrea los obstáculos  
	crearJugador(); // Recrea el jugador  
	crearPowerUps(); // Recrea los power-ups  
	setPuntos(0); // Restablece los puntos a 0  
	derrota = false;

	cout << "se ha reseteado la escena" << endl;
}
