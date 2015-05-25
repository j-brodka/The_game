#include <iostream>
#define PI 3.14159265
#include "func.h"
#include "NPC.h"
#include "imageloader.h"
#include "przeszkoda.h"
#include "scena.h"
#include "enemy.h"
#include <GL/freeglut.h>
#include <vector>
using namespace std;

double moveX, moveY;
int strona=0;


void SpawnHero()
{
	player.lvlRaise(1);
	player.setDamage(3, 10);
	scena = 0;
}

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
	switch (key)
	{
	case 27:
	{

			   exit(0);
	}
	case 32:
	{
			   if (scena == 0)
				   scena = 1;
			   else
				   scena = 2;
	}
	}
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
	glPushMatrix();
	
	if (scena==0)
		drawMenu();
	else if (scena==1)
		drawIntro();
	else if (scena==2)
		drawMap(moveX, moveY);

	glPopMatrix();
	glutSwapBuffers();
}

