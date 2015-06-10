#include <iostream>
#include <stdio.h>
#define PI 3.14159265
#include "func.h"
#include "NPC.h"
#include "imageloader.h"
#include "przeszkoda.h"
#include "scena.h"
#include "enemy.h"
#include <GL/freeglut.h>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

double moveX, moveY;
int strona=0;
int scena=0;
int nrEnemy = 0;
bool trybWalka = false;
vector<NPC>enemy2;
string level, damage, hp;

void SpawnHero()
{
	player.setLVL(1);
	player.setDamage(3, 10);
	player.setAlive(true);
	player.setHP(30);
	player.setNR(0);
	scena = 0;
	level = "Level: ";
	damage = "Damage: min    max";
	hp = "HP: ";
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

void inicjujEnemy2()
{
	enemy2.push_back(black_knight);
	enemy2.push_back(cerber);
	enemy2.push_back(dwarf);
	enemy2.push_back(giant_spider);
	enemy2.push_back(hydra);
	enemy2.push_back(grimlud);
	enemy2.push_back(grund);
	enemy2.push_back(mad_axeman);
	enemy2.push_back(minotaur);
	enemy2.push_back(priestess);
	enemy2.push_back(priest);
	enemy2.push_back(ranger);
	enemy2.push_back(rehgar);
	enemy2.push_back(thraal);
	enemy2.push_back(uruk1);
	enemy2.push_back(uruk2);
	enemy2.push_back(uruk3);
	enemy2.push_back(varus);
}

void sprawdzWalka()
{
	for (int i = 0; i < enemy2.size(); i++)
	{
		if ((player.getPozycja()).X == (enemy2[i].getX() + 0.2237) || (player.getPozycja()).X == (enemy2[i].getX()) || (player.getPozycja()).X == (enemy2[i].getX() - 0.2237))
		{
			if ((player.getPozycja()).Y == (enemy2[i].getY() + 0.2237) || (player.getPozycja()).Y == (enemy2[i].getY()) || (player.getPozycja()).Y == (enemy2[i].getY() - 0.2237))
			{
				if (player.returnLVL() == enemy2[i].returnLVL())
				nrEnemy = enemy2[i].returnNR();
				scena = 3;
			}
		}
	}
}

void Napisz(float x, float y, string str)
{
	int len, i;
	glRasterPos2f(x, y);
	char * cstr = new char[str.length() + 1];
	strcpy_s(cstr, 20, str.c_str());
	len = (int)strlen(cstr);
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, cstr[i]);
	}
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
	case 102:
	{
				sprawdzWalka();
	}
	}
}
void SpecialKeysFunc(int key, int x, int y)
{
	if (scena == 2)
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
string convert(int i)
{
	stringstream ss;
	string str;
	ss << i;
	ss >> str;
	return str;
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
	else if (scena == 2)
	{
		int i = player.returnLVL();
		Napisz(-1.95, -1.19, level);
		Napisz(-1.40, -1.19, convert(i));
		int j = player.returnHP();
		Napisz(-1.95, -1.32, hp);
		Napisz(-1.40, -1.32, convert(j));
		int k = player.returnDamageMin();
		Napisz(-1.95, -1.45, damage);
		Napisz(-1.40, -1.45, convert(k));
		int l = player.returnDamageMax();
		Napisz(-1.14, -1.45, convert(l));
		drawMap(moveX, moveY);
		
	}
	else if (scena == 3)
		drawBattle(nrEnemy);

	glPopMatrix();
	glutSwapBuffers();
}

