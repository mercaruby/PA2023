// PRACTICA3_FELIX_VILCHES_Y_RUBEN_DIAZ.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <GL/glut.h>

#include "Game.h"

using namespace std;

// ||||||||||||||||||||||||		CONSTANTES		|||||||||||||||||||||||||||

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int WINDOW_POSITION_X = 300;
const int WINDOW_POSITION_Y = 400;
const char TITLE[] = "PRACTICA 3 FELIX VILCHES Y RUBEN DIAZ";

const GLclampf RED = 0;
const GLclampf GREEN = 0;
const GLclampf BLUE = 0.4;
const GLclampf ALPHA = 1;

bool fullScreenMode = FALSE;								 //Tenemos que inicializar el booleano fullScreenMode a false porque si no nos dará error luego



// ||||||||||||||||||||||||		USANDO GAME		|||||||||||||||||||||||||||

Game game;


// ||||||||||||||||||||||||		FUNCIONES AUXILIARES		|||||||||||||||||||||||||||

void writeLine(string text)
{
	cout << text << endl;
}


// ||||||||||||||||||||||||		FUNCIONES OPENGL		|||||||||||||||||||||||||||

void initGraphics()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(RED, GREEN, BLUE, ALPHA);

	game.Init();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	game.Render();

	glutSwapBuffers();
}


// ||||||||||||||||||||||||		OTROS EVENTOS		|||||||||||||||||||||||||||

void reshape(GLsizei width, GLsizei height)
{
	if (height == 0) height == 1;
	GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.f, aspectRatio, 1.0f, 200.f);
	glMatrixMode(GL_MODELVIEW);
}

void idle()
{
	game.Update();
	glutPostRedisplay();
}

void keyPressed(unsigned char key, int px, int py)
{
	game.ProcessKeyPressed(key, px, py);
	glutPostRedisplay();
}

void mouseMoved(int x, int y)
{
	game.ProcessMouseMovement(x, y);
	glutPostRedisplay();
}

void mouseClicked(int button, int state, int x, int y)
{
	game.ProcessMouseClick(button,state, x, y);
	glutPostRedisplay();
}



void specialKey(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_F11:
			fullScreenMode = !fullScreenMode;
			if (fullScreenMode)
			{
				glutFullScreen();
			}
			else
			{
				glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
				glutPositionWindow(WINDOW_POSITION_X, WINDOW_POSITION_Y);
			}
			break;
	}
}



// ||||||||||||||||||||||||		***** MAIN *****		|||||||||||||||||||||||||||

int main(int argc, char** argv)
{
	writeLine("Hello world con OpenGL");

	writeLine("Generando ventana...");

	glutInit(&argc, argv);															//Inicializa el GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);							//Doble buffer, modo RGBA, depth buffer
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);									//Tamaño inicial de la ventana
	glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);						//Posicion inicial de la ventana
	glutCreateWindow(TITLE);															//Crea la ventana con el titulo 

	writeLine("Registrando funciones de tratamiento de eventos...");
	glutDisplayFunc(display);														//tratamiento del evento de repintado de la ventana
	glutReshapeFunc(reshape);														//tratamiento del evento de redimensionado de la ventana
	glutKeyboardFunc(keyPressed);													//tratamiento del evento de tecla pulsada
	glutSpecialFunc(specialKey);													//tratamiento del evento de tecla especial pulsada
	glutMotionFunc(mouseMoved);														//tratamiento del evento de	evento del movimiento del raton
	glutMouseFunc(mouseClicked);													//tratamiento del evento del evento del click del raton
	glutIdleFunc(idle);																//para cuando no hay eventos que tratar

	writeLine("Iniciando graficos...");
	initGraphics();																	// INICIAMOS OPENGL

	writeLine("Iniciando bucle infinito...");
	writeLine("Pulse F11 para activar/desactivar el modo de pantalla completa.");
	glutMainLoop();
}
