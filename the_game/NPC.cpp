#include <iostream>
#define PI 3.14159265
#include "func.h"
#include "NPC.h"
#include <GL/freeglut.h>
#include "imageloader.h"
#include "przeszkoda.h"
#include <vector>

void NPC::DrawNPC(void)
{
	glPushMatrix();

	glColor3d(0, 0, 0);
	glTranslated(0, 0, 0);
	glBegin(GL_POLYGON);
	{
		glVertex3d(-0.1, 0.1, 0);
		glVertex3d(0.1, 0.1, 0);
		glVertex3d(0.1, -0.1, 0);
		glVertex3d(-0.1, -0.1, 0);
	}
	glEnd();

	glPopMatrix();
}

void NPC::setX(double x)
{
	pozycja.X += x;
}
void NPC::setY(double y)
{
	pozycja.Y += y;
}
double NPC::getX()
{
	return pozycja.X;
}
double NPC::getY()
{
	return pozycja.Y;
}
Coords NPC::getPozycja()
{
	return pozycja;
}