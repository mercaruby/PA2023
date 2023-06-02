#pragma once
#include <GL/glut.h>
#include <string>
#include "Solid.h"
#include "Vector3D.h"

using namespace std;
class Text:public Solid
{
	string text;
	float size;

public:
	Text(string t = "Default text") : Solid(), text(t) {}

	inline string getText() { return text; }
	inline void setText(string t) { text = t; }

	void Render();
};

