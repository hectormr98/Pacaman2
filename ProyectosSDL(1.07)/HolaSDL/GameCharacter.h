#pragma once
#include"GameObject.h"

using namespace std;

class GameCharacter : public GameObject
{
public:
	GameCharacter(int x, int y);
	~GameCharacter();
protected:
	
	int IniX, IniY;

	int PosX,
		PosY;

	int dir = 0;
	Texture* text = nullptr;

	bool loadFromFile(string filename);
	void render();
	void update();
	bool saveToFile(string filename);
};

