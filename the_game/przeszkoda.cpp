#include <iostream>
#define PI 3.14159265
#include "func.h"
#include "NPC.h"
#include <GL/freeglut.h>
#include "imageloader.h"
#include <vector>
#include "przeszkoda.h"
using namespace std;

bool ifKolizja=false;
NPC player;
vector<Coords>koord;

void kolSpawn()
{
	Coords srodek;
	srodek.X = 0;
	srodek.Y = 0;
	koord.push_back(srodek);
	for (int i = 0; i < 3; i++)
	{
		srodek.Y -= 0.2237;
		koord.push_back(srodek);
	}
}

void kolLawa()
{
	Coords first;
	first.X = -5.3688;
	first.Y = 2.0133;
	for (int i = 0; i < 8; i++)
	{
		first.X += 0.2237;
		for (int i = 0; i < 5; i++)
		{
			first.Y += 0.2237;
			koord.push_back(first);
		}
	}
}

void stworzKolizja()
{
	kolSpawn();
	kolLawa();
}

void kolizja()
{
	

	for (int i = 0; i < koord.size(); i++)
	{
		if (player.getPozycja() == koord[i])
		{
			ifKolizja = false;
			i = koord.size();
		}
		else
			ifKolizja = true;
	}
}