#ifndef NPC_H
#define NPC_H

class NPC
{
private:
	Coords pozycja;
public:
	void DrawHERO(void);
	void setX(double x);
	void setY(double y);
	double getX();
	double getY();
	Coords getPozycja();
};

extern NPC player;
extern bool ifKolizja;

#endif