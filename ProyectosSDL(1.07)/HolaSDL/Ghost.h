#pragma once
#include"Texture.h"
#include "SDL.h"
#include "SDL_image.h"
#include "PacMan.h"
#include"GameCharacter.h"

class Game;

class Ghost:public GameCharacter
{
private:

	PacMan* pacman = nullptr;

	Texture* textGhost = new Texture();

	SDL_Renderer* render = nullptr;

	int IniX=0, IniY=0;
	int posX = IniX,
		posY = IniY;
	//posiciones actuales e iniciales del fantasma

	int dir = 0;
	int anim = 0;

	Game* game = nullptr;
	/*
	     /\
	     |
       	 3
	<--2 X	0-->
	     1
	     |
	    \/
	*/

public:
	Ghost();
	//constructora default, situa fantasma en (0,0)

	Ghost(Game* game, int x, int y, SDL_Renderer* rend);
	//constructora que situa al fantasma en posicion (x,y)

	~Ghost();
	//destructora

	void RenderGhost(SDL_Rect rekt, int d, PacMan* pacman);

	int getPosX();
	int getPosY();
	//metodos auxiliares
	int GetAnim();
	void Mueve(int fils, int cols);
	void CambiaDir();
	void SetInicio();
};

