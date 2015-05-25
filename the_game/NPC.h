#ifndef NPC_H
#define NPC_H

class NPC
{
private:
	Coords pozycja;
	int level;
	int minDamage;
	int maxDamage;
public:
	void DrawHERO(void);
	void DrawNPC(GLuint _textureId, Image * image, double _x, double _y);
	void setX(double x);
	void setY(double y);
	double getX();
	double getY();
	Coords getPozycja();
	void lvlRaise(int x);
	void setDamage(int min, int max);
};

extern NPC player;
extern bool ifKolizja;

#endif