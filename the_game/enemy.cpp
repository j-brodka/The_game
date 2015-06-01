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

vector<Coords>enemy;

GLuint _textureId;
Image * image;

void NPC::DrawNPC(double _x, double _y)
{
	glTranslated(_x, _y, 0);
	glBindTexture(GL_TEXTURE_2D, _textureId); //Mówimy OpenGl jaka tekstura
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1f, 0.1f, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1f, 0.1f, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0);

	glEnd();
}

void inicjujEnemy()
{
	NPC black_knight, cerber, dwarf, giant_spider, grimlud, grund, hydra, mad_axeman, minotaur, priestess, priest, ranger, rehgar, thraal, uruk1, uruk2, uruk3, varus;
	
	image = loadBMP("textures/icons/black_knight.bmp");
	glPushMatrix();
	black_knight.DrawNPC(5.8162, -4.474);
	glPopMatrix();
	black_knight.setX(5.8162);
	black_knight.setY(-4.474);
	enemy.push_back(black_knight.getPozycja());

	image = loadBMP("textures/icons/cerber.bmp");
	glPushMatrix();
	cerber.DrawNPC(-6.0399, -1.3422);
	glPopMatrix();
	cerber.setX(-6.0399);
	cerber.setX(-1.3422);
	enemy.push_back(cerber.getPozycja());

	image = loadBMP("textures/icons/dwarf.bmp");
	glPushMatrix();
	dwarf.DrawNPC(-1.1185, -2.0133);
	glPopMatrix();
	dwarf.setX(-1.1185);
	dwarf.setY(-2.0133);
	enemy.push_back(dwarf.getPozycja());

	image = loadBMP("textures/icons/giant_spider.bmp");
	glPushMatrix();
	giant_spider.DrawNPC(2.237, -4.0266);
	glPopMatrix();
	giant_spider.setX(2.237);
	giant_spider.setX(-4.0266);
	enemy.push_back(giant_spider.getPozycja());

	image = loadBMP("textures/icons/grimlud.bmp");
	glPushMatrix();
	grimlud.DrawNPC(3.3555, -3.8029);
	glPopMatrix();
	grimlud.setX(3.3555);
	grimlud.setX(-3.8029);
	enemy.push_back(grimlud.getPozycja());

	image = loadBMP("textures/icons/grund.bmp");
	glPushMatrix();
	grund.DrawNPC(4.0266, -5.3688);
	glPopMatrix();
	grund.setX(4.0266);
	grund.setX(-5.3688);
	enemy.push_back(grund.getPozycja());

	image = loadBMP("textures/icons/hydra.bmp");
	glPushMatrix();
	hydra.DrawNPC(-3.3555, -5.8162);
	glPopMatrix();
	hydra.setX(-3.3555);
	hydra.setX(-5.8162);
	enemy.push_back(hydra.getPozycja());

	image = loadBMP("textures/icons/mad_axeman.bmp");
	glPushMatrix();
	mad_axeman.DrawNPC(-4.0266, -3.8029);
	glPopMatrix();
	mad_axeman.setX(-4.0266);
	mad_axeman.setX(-3.8029);
	enemy.push_back(mad_axeman.getPozycja());

	image = loadBMP("textures/icons/minotaur.bmp");
	glPushMatrix();
	minotaur.DrawNPC(0.4474, -5.5925);
	glPopMatrix();
	minotaur.setX(0.4474);
	minotaur.setX(-5.5925);
	enemy.push_back(minotaur.getPozycja());

	image = loadBMP("textures/icons/priestess.bmp");
	glPushMatrix();
	priestess.DrawNPC(3.5792, 0.6711);
	glPopMatrix();
	priestess.setX(3.5792);
	priestess.setX(0.6711);
	enemy.push_back(priestess.getPozycja());

	image = loadBMP("textures/icons/priest.bmp");
	glPushMatrix();
	priest.DrawNPC(4.474, 0.6711);
	glPopMatrix();
	priest.setX(4.474);
	priest.setX(0.6711);
	enemy.push_back(priest.getPozycja());

	image = loadBMP("textures/icons/ranger.bmp");
	glPushMatrix();
	ranger.DrawNPC(-4.9214, -1.7896);
	glPopMatrix();
	ranger.setX(-4.9214);
	ranger.setX(-1.7896);
	enemy.push_back(ranger.getPozycja());

	image = loadBMP("textures/icons/rehgar.bmp");
	glPushMatrix();
	rehgar.DrawNPC(-4.474, 2.4607);
	glPopMatrix();
	rehgar.setX(-4.474);
	rehgar.setX(2.4607);
	enemy.push_back(rehgar.getPozycja());

	image = loadBMP("textures/icons/thraal.bmp");
	glPushMatrix();
	thraal.DrawNPC(-2.0133, -6.0399);
	glPopMatrix();
	thraal.setX(-2.0133);
	thraal.setY(-6.0399);
	enemy.push_back(thraal.getPozycja());

	image = loadBMP("textures/icons/uruk_1.bmp");
	glPushMatrix();
	uruk1.DrawNPC(4.474, -3.1318);
	glPopMatrix();
	uruk1.setX(4.474);
	uruk1.setY(-3.1318);
	enemy.push_back(uruk1.getPozycja());

	image = loadBMP("textures/icons/uruk_2.bmp");
	glPushMatrix();
	uruk2.DrawNPC(2.237, -2.237);
	glPopMatrix();
	uruk2.setX(2.237);
	uruk2.setY(-2.237);
	enemy.push_back(uruk2.getPozycja());

	image = loadBMP("textures/icons/uruk_3.bmp");
	glPushMatrix();
	uruk3.DrawNPC(-2.6844, -2.4607);
	glPopMatrix();
	uruk3.setX(-2.6844);
	uruk3.setY(-2.4607);
	enemy.push_back(uruk3.getPozycja());

	image = loadBMP("textures/icons/varus.bmp");
	glPushMatrix();
	varus.DrawNPC(-4.474, 0.6711);
	glPopMatrix();
	varus.setX(-4.474);
	varus.setY(0.6711);
	enemy.push_back(varus.getPozycja());
}

void kolizjaEnemy()
{
	for (int i = 0; i < enemy.size(); i++)
	{
		if (player.getPozycja() == enemy[i])
		{
			ifKolizja = false;
			i = enemy.size();
		}
		else
			ifKolizja = true;
	}
}
