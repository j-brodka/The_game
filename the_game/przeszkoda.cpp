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
		first.Y = 2.0133;
		for (int i = 0; i < 5; i++)
		{
			first.Y += 0.2237;
			koord.push_back(first);
		}
	}
}

void kolLas1()
{
	Coords first, second, third, fourth, fifth, sixth, seventh, eight;
	first.X = -4.0266;
	first.Y = -2.9081;
	second.X = -0.2237;
	second.Y = -4.2503;
	third.X = -3.8029;
	third.Y = -4.474;
	fourth.X = -4.744;
	fourth.Y = -3.1318;
	fifth.X = -0.8948;
	fifth.Y = -2.9081;
	sixth.X = -0.8948;
	sixth.Y = -2.6844;
	seventh.X = -1.1185;
	seventh.Y = -2.6844;
	eight.X = -0.2237;
	eight.Y = -0.6711;
	koord.push_back(third);
	for (int i = 0; i < 21; i++)
	{
		first.X += 0.2237;
		first.Y = -2.9081;
		for (int i = 0; i < 5; i++)
		{
			first.Y -= 0.2237;
			koord.push_back(first);
		}
	}
	for (int i = 0; i < 18; i++)
	{
		second.X -= 0.2237;
		koord.push_back(second);
	}
	for (int i = 0; i < 4; i++)
	{
		third.X += 0.2237;
		third.Y = -4.2503;
		for (int i = 0; i < 2; i++)
		{
			third.Y -= 0.2237;
			koord.push_back(third);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		fourth.X += 0.2237;
		fourth.Y = -3.1318;
		for (int i = 0; i < 5; i++)
		{
			fourth.Y -= 0.2237;
			koord.push_back(fourth);
		}
	}
	for (int i = 0; i < 7; i++)
	{
		fifth.X += 0.2237;
		koord.push_back(fifth);
	}
	for (int i = 0; i < 9; i++)
	{
		sixth.X += 0.2237;
		koord.push_back(sixth);
	}
	for (int i = 0; i < 6; i++)
	{
		seventh.X += 0.2237;
		seventh.Y = -2.6844;
		for (int i = 0; i < 10; i++)
		{
			seventh.Y += 0.2237;
			koord.push_back(seventh);
		}
	}
	for (int i = 0; i < 6; i++)
	{
		eight.X += 0.2237;
		eight.Y = -0.6711;
		for (int i = 0; i < 2; i++)
		{
			eight.Y -= 0.2237;
			koord.push_back(eight);
		}
	}

}

/*void kolLas2()
{

}*/


void stworzKolizja()
{
	kolSpawn();
	kolLawa();
	kolLas1();
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