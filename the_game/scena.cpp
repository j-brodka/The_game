#include <iostream>
#define PI 3.14159265
#include "func.h"
#include "NPC.h"
#include <GL/freeglut.h>
#include "imageloader.h"
#include "przeszkoda.h"
#include "scena.h"
#include "enemy.h"
#include <vector>

Image * imageMAP = loadBMP("textures/mapa.bmp");
GLuint _textureIdMAP;
Image * imageMENU = loadBMP("textures/menu.bmp");
GLuint _textureIdMENU;
Image * imageINTRO = loadBMP("textures/intro.bmp");
GLuint _textureIdINTRO;

int nrEnemy = 0;

void drawMenu()
{
	glEnable(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, _textureIdMENU);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageMENU->width, imageMENU->height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageMENU->pixels);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-2, -2, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-2, 2, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2, 2, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2, -2, 0);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void drawIntro()
{
	glEnable(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, _textureIdINTRO);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageINTRO->width, imageINTRO->height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageINTRO->pixels);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-2, -2, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-2, 2, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2, 2, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2, -2, 0);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void drawMap(double moveX, double moveY)
{
	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
	player.DrawHERO();
	glPopMatrix();


	glTranslated(moveX, moveY, 0);

	glPushMatrix();
	inicjujEnemy();
	glPopMatrix();

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
}

void drawBattle()
{
	GLuint _textureIdBATTLE;
	Image * imageBATTLE;

	if (nrEnemy==1)
		imageBATTLE = loadBMP("textures/battle/black_knight.bmp");
	
	else if (nrEnemy==2)
		imageBATTLE = loadBMP("textures/battle/cerber.bmp");
	
	else if (nrEnemy == 3)
		imageBATTLE = loadBMP("textures/battle/dwarf.bmp");
	
	else if (nrEnemy == 4)
		imageBATTLE = loadBMP("textures/battle/giant_spider.bmp");
	
	else if (nrEnemy == 5)
		imageBATTLE = loadBMP("textures/battle/grimlud.bmp");
	
	else if (nrEnemy == 6)
		imageBATTLE = loadBMP("textures/battle/grund.bmp");
	
	else if (nrEnemy == 7)
		imageBATTLE = loadBMP("textures/battle/hydra.bmp");
	
	else if (nrEnemy == 8)
		imageBATTLE = loadBMP("textures/battle/mad_axeman.bmp");

	else if (nrEnemy == 9)
		imageBATTLE = loadBMP("textures/battle/minotaur.bmp");
	
	else if (nrEnemy == 10)
		imageBATTLE = loadBMP("textures/battle/priestess.bmp");
	
	else if (nrEnemy == 11)
		imageBATTLE = loadBMP("textures/battle/priest.bmp");
	
	else if (nrEnemy == 12)
		imageBATTLE = loadBMP("textures/battle/ranger.bmp");
	
	else if (nrEnemy == 13)
		imageBATTLE = loadBMP("textures/battle/rehgar.bmp");
	
	else if (nrEnemy == 14)
		imageBATTLE = loadBMP("textures/battle/thraal.bmp");
	
	else if (nrEnemy == 15)
		imageBATTLE = loadBMP("textures/battle/uruk_1.bmp");
	
	else if (nrEnemy == 16)
		imageBATTLE = loadBMP("textures/battle/uruk_2.bmp");
	
	else if (nrEnemy == 17)
		imageBATTLE = loadBMP("textures/battle/uruk_3.bmp");
	
	else if (nrEnemy == 18)
		imageBATTLE = loadBMP("textures/battle/varus.bmp");
	
	glEnable(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, _textureIdBATTLE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageBATTLE->width, imageBATTLE->height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageBATTLE->pixels);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-2, -2, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-2, 2, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2, 2, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2, -2, 0);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}