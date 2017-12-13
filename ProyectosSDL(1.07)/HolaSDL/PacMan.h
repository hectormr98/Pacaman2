#pragma once
#include<iostream>
#include"Texture.h"
#include "SDL.h"
#include "SDL_image.h"
#include"GameCharacter.h"

class Game;

enum estadoPacMan
{
	DerCerrado,
	DerAbierto,
	BotCerrado,
	BotAbierto,
	IzqCerrado,
	IzqAbierto,
	TopCerrado,
	TopAbierto,
};


class PacMan: public GameCharacter
{
private:

	Texture* textPac = new Texture();

	SDL_Renderer* render = nullptr;

	int IniX=0, IniY=0;
	int posX = IniX,
		posY = IniY;
	int auxDir=0;
	Game * game = nullptr;
	estadoPacMan estado;
	//posicion de pacman
	int contador = 0;
	const int numTicks = 50;


	int dir = 0;
	int dir2 = 0;
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

	bool Come = false;


	PacMan();
	//constructora default

 	PacMan(Game* game, int x, int y, SDL_Renderer* render);
	//constructora que situa pacman en una posicion

	~PacMan();
	//destructora
	void RestartContador();
	void Mueve(int fils, int cols);
	void CambiaDir(int newdir);

	void RenderPac(SDL_Rect rekt);
	int getPosX();
	int getPosY();
	estadoPacMan getEstado();
	int GetDir();
	int getTicks();
	void CambiaEstado(int i);
	void Contador();
	//metodos auxiliares
};

