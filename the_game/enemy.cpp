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

vector<NPC>enemy;

Image * image1 = loadBMP("textures/icons/black_knight.bmp");
GLuint _textureId1;
Image * image2 = loadBMP("textures/icons/cerber.bmp");
GLuint _textureId2;
Image * image3 = loadBMP("textures/icons/dwarf.bmp");
GLuint _textureId3;
Image * image4 = loadBMP("textures/icons/giant_spider.bmp");
GLuint _textureId4;
Image * image5 = loadBMP("textures/icons/grimlud.bmp");
GLuint _textureId5;
Image * image6 = loadBMP("textures/icons/grund.bmp");
GLuint _textureId6;
Image * image7 = loadBMP("textures/icons/hydra.bmp");
GLuint _textureId7;
Image * image8 = loadBMP("textures/icons/mad_axeman.bmp");
GLuint _textureId8;
Image * image9 = loadBMP("textures/icons/minotaur.bmp");
GLuint _textureId9;
Image * image10 = loadBMP("textures/icons/priestess.bmp");
GLuint _textureId10;
Image * image11 = loadBMP("textures/icons/priest.bmp");
GLuint _textureId11;
Image * image12 = loadBMP("textures/icons/ranger.bmp");
GLuint _textureId12;
Image * image13 = loadBMP("textures/icons/rehgar.bmp");
GLuint _textureId13;
Image * image14 = loadBMP("textures/icons/thraal.bmp");
GLuint _textureId14;
Image * image15 = loadBMP("textures/icons/uruk1.bmp");
GLuint _textureId15;
Image * image16 = loadBMP("textures/icons/uruk2.bmp");
GLuint _textureId16;
Image * image17 = loadBMP("textures/icons/uruk3.bmp");
GLuint _textureId17;
Image * image18 = loadBMP("textures/icons/varus.bmp");
GLuint _textureId18;

void inicjujEnemy()
{
	NPC black_knight, cerber, dwarf, giant_spider, grimlud, grund, hydra, mad_axeman, minotaur, priestess, priest, ranger, rehgar, thraal, uruk1, uruk2, uruk3, varus;
	black_knight.DrawNPC(_textureId1, image1, 0, 0);
	cerber.DrawNPC(_textureId2, image2, 0, 0);
	dwarf.DrawNPC(_textureId3, image3, 0, 0);
	giant_spider.DrawNPC(_textureId4, image4, 0, 0);
	grimlud.DrawNPC(_textureId5, image5, 0, 0);
	grund.DrawNPC(_textureId6, image6, 0, 0);
	hydra.DrawNPC(_textureId7, image7, 0, 0);
	mad_axeman.DrawNPC(_textureId8, image8, 0, 0);
	minotaur.DrawNPC(_textureId9, image9, 0, 0);
	priestess.DrawNPC(_textureId10, image10, 0, 0);
	priest.DrawNPC(_textureId11, image11, 0, 0);
	ranger.DrawNPC(_textureId12, image12, 0, 0);
	rehgar.DrawNPC(_textureId13, image13, 0, 0);
	thraal.DrawNPC(_textureId14, image14, 0, 0);
	uruk1.DrawNPC(_textureId15, image15, 0, 0);
	uruk2.DrawNPC(_textureId16, image16, 0, 0);
	uruk3.DrawNPC(_textureId17, image17, 0, 0);
	varus.DrawNPC(_textureId18, image18, 0, 0);
}
