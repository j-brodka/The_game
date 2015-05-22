#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#define PI 3.14159265
#include "func.h"
#include "NPC.h"
#include "imageloader.h"
#include "przeszkoda.h"
#include <GL/freeglut.h>
#include <vector>
using namespace std;

Image * imageMAP = loadBMP("textures/mapa.bmp");

double moveX, moveY;
int strona=0;

GLuint _textureIdMAP;

bool Coords::operator==(const Coords &a)
{
	if ((this->X == a.X) && (this->Y == a.Y))
		return true;
	else
		return false;
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
	
	kolizja();
	cofka();

	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
	player.DrawNPC();
	glPopMatrix();


	glTranslated(moveX, moveY, 0);

	glBindTexture(GL_TEXTURE_2D, _textureIdMAP);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageMAP->width, imageMAP->height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageMAP->pixels);
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

