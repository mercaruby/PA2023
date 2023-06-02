#pragma once
#include <vector>
#include "Solid.h"


using namespace std;
class Scene
{

private:

	
	Vector3D boundary;
	Vector3D size;
	Vector3D gravity;



protected:

	bool finEscena = false;
	vector <Solid*> gameObjects;
public:
	//Scene(Vector3D bound = Vector3D(14, 10, 20)): boundary(bound) {};

	Scene(Vector3D sizeToSet = Vector3D(10.0f, 10.0f, 10.0f), Vector3D gravity = Vector3D(0.0f, -0.01f, 0.0f)) :
		size(sizeToSet), gravity(gravity) {}

	inline Vector3D GetSize() const { return this->size; }
	
	inline bool GetFinEscena() const { return this->finEscena; }

	inline Vector3D GetGravity() const { return this->gravity; }

	inline void SetGravity(const Vector3D& gravity) { this->gravity = gravity; }

	inline void SetSize(const Vector3D& sizeToSet) { this->size = sizeToSet; }

	inline void SetFinEscena(const bool& finEscenaToSet) {this->finEscena = finEscenaToSet; }

	virtual void ClearScene() = 0;
	//virtual void Render();
	//virtual void Update(const float& time);

	
	void AddGameObject(Solid* object);
	void Render();
	void Update(const double &dt);
	void checkBoundary();

	virtual void ProcessKeyPressed(unsigned char key, int px, int py) = 0;
};

