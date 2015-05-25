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