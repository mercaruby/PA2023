#include "Scene.h"
#include <math.h>
#include <iostream>


using namespace std;
void Scene::AddGameObject(Solid* object) 
{
	this->gameObjects.push_back(object);

}
void Scene::Render()
{
	for (int i = 0; i < this->gameObjects.size(); i++)
	{
		this->gameObjects[i]->Render();
	}

	cout << "Esta llamando al render de Scene, no al de EscenaInicio" << endl;
}
void Scene::Update(const double &dt)
{
	for (int i = 0; i < this->gameObjects.size(); i++)
	{
		this->gameObjects[i]->Update(dt, gravity);
		this->checkBoundary();
		
	}


	
}

 void Scene::checkBoundary() {

	 
	 for (Solid* ps : gameObjects) 
	 {
		 if (ps-> getPosX() > this->boundary.GetX() || ps->getPosX() < 0)
		 { 
			 ps -> setVel(Vector3D(-1 * ps -> getVel().GetX(), ps -> getVel().GetY(), ps -> getVel().GetZ()));
		 }

		 if (ps->getPosY() > this->boundary.GetY() || ps->getPosY() < 0)
		 {
			 ps->setVel(Vector3D(ps->getVel().GetX(), -1 * ps->getVel().GetY(), ps->getVel().GetZ()));
		 }

		 if (ps->getPosZ() > this->boundary.GetZ() || ps->getPosZ() < 0)
		 {
			 ps->setVel(Vector3D(ps->getVel().GetX(), ps->getVel().GetY(), -1 * ps->getVel().GetZ()));
		 }
		 
	 }

}