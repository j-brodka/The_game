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

GLuint _textureId;
Image * image;

NPC black_knight, cerber, dwarf, giant_spider, grimlud, grund, hydra, mad_axeman, minotaur, priestess, priest, ranger, rehgar, thraal, uruk1, uruk2, uruk3, varus;

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

void rysujEnemy()
{
	image = loadBMP("textures/icons/black_knight.bmp");
	glPushMatrix();
	black_knight.DrawNPC(5.8162, -4.474);
	glPopMatrix();

	image = loadBMP("textures/icons/cerber.bmp");
	glPushMatrix();
	cerber.DrawNPC(-6.0399, -1.3422);
	glPopMatrix();

	image = loadBMP("textures/icons/dwarf.bmp");
	glPushMatrix();
	dwarf.DrawNPC(-1.1185, -2.0133);
	glPopMatrix();

	image = loadBMP("textures/icons/giant_spider.bmp");
	glPushMatrix();
	giant_spider.DrawNPC(2.237, -4.0266);
	glPopMatrix();

	image = loadBMP("textures/icons/grimlud.bmp");
	glPushMatrix();
	grimlud.DrawNPC(3.3555, -3.8029);
	glPopMatrix();

	image = loadBMP("textures/icons/grund.bmp");
	glPushMatrix();
	grund.DrawNPC(4.0266, -5.3688);
	glPopMatrix();

	image = loadBMP("textures/icons/hydra.bmp");
	glPushMatrix();
	hydra.DrawNPC(-3.3555, -5.8162);
	glPopMatrix();

	image = loadBMP("textures/icons/mad_axeman.bmp");
	glPushMatrix();
	mad_axeman.DrawNPC(-4.0266, -3.8029);
	glPopMatrix();

	image = loadBMP("textures/icons/minotaur.bmp");
	glPushMatrix();
	minotaur.DrawNPC(0.4474, -5.5925);
	glPopMatrix();

	image = loadBMP("textures/icons/priestess.bmp");
	glPushMatrix();
	priestess.DrawNPC(3.5792, 0.6711);
	glPopMatrix();

	image = loadBMP("textures/icons/priest.bmp");
	glPushMatrix();
	priest.DrawNPC(4.474, 0.6711);
	glPopMatrix();

	image = loadBMP("textures/icons/ranger.bmp");
	glPushMatrix();
	ranger.DrawNPC(-4.9214, -1.7896);
	glPopMatrix();

	image = loadBMP("textures/icons/rehgar.bmp");
	glPushMatrix();
	rehgar.DrawNPC(-4.474, 2.4607);
	glPopMatrix();

	image = loadBMP("textures/icons/thraal.bmp");
	glPushMatrix();
	thraal.DrawNPC(-2.0133, -6.0399);
	glPopMatrix();

	image = loadBMP("textures/icons/uruk_1.bmp");
	glPushMatrix();
	uruk1.DrawNPC(4.474, -3.1318);
	glPopMatrix();

	image = loadBMP("textures/icons/uruk_2.bmp");
	glPushMatrix();
	uruk2.DrawNPC(2.237, -2.237);
	glPopMatrix();

	image = loadBMP("textures/icons/uruk_3.bmp");
	glPushMatrix();
	uruk3.DrawNPC(-2.6844, -2.4607);
	glPopMatrix();

	image = loadBMP("textures/icons/varus.bmp");
	glPushMatrix();
	varus.DrawNPC(-4.474, 0.6711);
	glPopMatrix();
}

void inicjujEnemy()
{
	black_knight.setAlive(true);
	black_knight.setX(5.8162);
	black_knight.setY(-4.474);
	black_knight.setLVL(7);
	black_knight.setHP(100);
	black_knight.setDamage(7, 15);
	black_knight.setNR(1);

	cerber.setAlive(true);
	cerber.setX(-6.0399);
	cerber.setY(-1.3422);
	cerber.setLVL(9);
	cerber.setHP(70);
	cerber.setDamage(12, 20);
	cerber.setNR(2);

	dwarf.setAlive(true);
	dwarf.setX(-1.1185);
	dwarf.setY(-2.0133);
	dwarf.setLVL(1);
	dwarf.setHP(25);
	dwarf.setDamage(2, 5);
	dwarf.setNR(3);

	giant_spider.setAlive(true);
	giant_spider.setX(2.237);
	giant_spider.setY(-4.0266);
	giant_spider.setLVL(12);
	giant_spider.setHP(85);
	giant_spider.setDamage(17, 22);
	giant_spider.setNR(4);

	grimlud.setAlive(true);
	grimlud.setX(3.3555);
	grimlud.setY(-3.8029);
	grimlud.setLVL(4);
	grimlud.setHP(45);
	grimlud.setDamage(8, 14);
	grimlud.setNR(5);

	grund.setAlive(true);
	grund.setX(4.0266);
	grund.setY(-5.3688);
	grund.setLVL(13);
	grund.setHP(90);
	grund.setDamage(19, 24);
	grund.setNR(6);

	hydra.setAlive(true);
	hydra.setX(-3.3555);
	hydra.setY(-5.8162);
	hydra.setLVL(16);
	hydra.setHP(200);
	hydra.setDamage(10, 20);
	hydra.setNR(7);

	mad_axeman.setAlive(true);
	mad_axeman.setX(-4.0266);
	mad_axeman.setY(-3.8029);
	mad_axeman.setLVL(2);
	mad_axeman.setHP(35);
	mad_axeman.setDamage(5, 8);
	mad_axeman.setNR(8);

	minotaur.setAlive(true);
	minotaur.setX(0.4474);
	minotaur.setY(-5.5925);
	minotaur.setLVL(14);
	minotaur.setHP(95);
	minotaur.setDamage(20, 26);
	minotaur.setNR(9);

	priestess.setAlive(true);
	priestess.setX(3.5792);
	priestess.setY(0.6711);
	priestess.setLVL(5);
	priestess.setHP(50);
	priestess.setDamage(9, 14);
	priestess.setNR(10);

	priest.setAlive(true);
	priest.setX(4.474);
	priest.setY(0.6711);
	priest.setLVL(6);
	priest.setHP(55);
	priest.setDamage(10, 15);
	priest.setNR(11);

	ranger.setAlive(true);
	ranger.setX(-4.9214);
	ranger.setY(-1.7896);
	ranger.setLVL(10);
	ranger.setHP(75);
	ranger.setDamage(14, 20);
	ranger.setNR(12);

	rehgar.setAlive(true);
	rehgar.setX(-4.474);
	rehgar.setY(2.4607);
	rehgar.setLVL(18);
	rehgar.setHP(320);
	rehgar.setDamage(5, 19);
	rehgar.setNR(13);

	thraal.setAlive(true);
	thraal.setX(-2.0133);
	thraal.setY(-6.0399);
	thraal.setLVL(15);
	thraal.setHP(100);
	thraal.setDamage(22, 27);
	thraal.setNR(14);

	uruk1.setAlive(true);
	uruk1.setX(4.474);
	uruk1.setY(-3.1318);
	uruk1.setLVL(8);
	uruk1.setHP(65);
	uruk1.setDamage(12, 18);
	uruk1.setNR(15);

	uruk2.setAlive(true);
	uruk2.setX(2.237);
	uruk2.setY(-2.237);
	uruk2.setLVL(3);
	uruk2.setHP(40);
	uruk2.setDamage(8, 11);
	uruk2.setNR(16);

	uruk3.setAlive(true);
	uruk3.setX(-2.6844);
	uruk3.setY(-2.4607);
	uruk3.setLVL(11);
	uruk3.setHP(80);
	uruk3.setDamage(16, 21);
	uruk3.setNR(17);

	varus.setAlive(true);
	varus.setX(-4.474);
	varus.setY(0.6711);
	varus.setLVL(17);
	varus.setHP(255);
	varus.setDamage(12, 22);
	varus.setNR(18);
}


