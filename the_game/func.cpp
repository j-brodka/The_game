#include <iostream>
#define PI 3.14159265
#include "func.h"
#include "NPC.h"
#include "imageloader.h"
#include "przeszkoda.h"
#include <GL/freeglut.h>
#include <vector>
using namespace std;


double moveX, moveY;
int strona=0;
GLuint texture[3];

GLuint _textureId, _textureId2, _textureId3;

bool Coords::operator==(const Coords &a)
{
	if ((this->X == a.X) && (this->Y == a.Y))
		return true;
	else
		return false;
}

GLuint loadTexture(Image * image)
{
	GLuint textureId;
	glGenTextures(1, &textureId); //Tworzymy miejsce dla tekstury
	glBindTexture(GL_TEXTURE_2D, textureId); //Mówimy OpenGl jaka tekstura
	glTexImage2D(GL_TEXTURE_2D, //zawsze GL_TEXTURE_2D
		0, //0 teraz
		GL_RGB, //Format OpenGL u¿yty dla obrazu
		image->width, image->height, //Szerokoœæ i wysokoœæ
		0, //Ramka obrazu
		GL_RGB, //GL_RGB, pixele s¹ w tym formacie
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, pixele s¹ takimi zmiennymi
		image->pixels); //uaktualnienie pixeli
	return textureId; //zwraca identyfikator tekstury;
}

void zaladujObrazy()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	Image * image = loadBMP("textures/mapa.bmp");
	_textureId = loadTexture(image);
	delete image;
}

void idle(void)
{
	glutPostRedisplay();
}
void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void processNormalKeys(unsigned char key, int xx, int yy) 
{
	
}
void SpecialKeysFunc(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
	{
						if (ifKolizja == false)
						{
							moveY -= 0.2237;
							player.setY(0.2237);
							cout << "x " << player.getX() << " y " << player.getY() << endl;
						}
						strona = 8;
						break;
	}

	case GLUT_KEY_DOWN:
	{
						  if (ifKolizja == false)
						  {
							  moveY += 0.2237;
							  player.setY(-0.2237);
							  cout << "x " << player.getX() << " y " << player.getY() << endl;
						  }
						  strona = 2;
						  break;
	}

	case GLUT_KEY_RIGHT:
	{
						   if (ifKolizja == false)
						   {
							   moveX -= 0.2237;
							   player.setX(0.2237);
							   cout << "x " << player.getX() << " y " << player.getY() << endl;
						   }
						   strona = 6;
						   break;
	}

	case GLUT_KEY_LEFT:
	{
						  if (ifKolizja == false)
						  {
							  moveX += 0.2237;
							  player.setX(-0.2237);
							  cout << "x " << player.getX() << " y " << player.getY() << endl;
						  }
						  strona = 4;
						  break;
	}
	case 27:
	{
			   
			   exit(0);
	}
	}

}

void cofka()
{
	if (ifKolizja == true)
	{
		if (strona == 8)
		{
			moveY += 0.2237;
			player.setY(-0.2237);
		}
		else if (strona == 2)
		{
			moveY -= 0.2237;
			player.setY(0.2237);
		}
		else if (strona == 6)
		{
			moveX += 0.2237;
			player.setX(-0.2237);
		}
		else if (strona == 4)
		{
			moveX -= 0.2237;
			player.setX(0.2237);
		}
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//kolizja();
	//cofka();

	glPushMatrix();
	player.DrawNPC();
	glPopMatrix();



	glTranslated(moveX, moveY, 0);

	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-10.5, -9, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-10.5, 9, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(10.5, 9, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(10.5, -9, 0);

	glEnd();

	glDisable(GL_TEXTURE_2D);


	
	glutSwapBuffers();
}

