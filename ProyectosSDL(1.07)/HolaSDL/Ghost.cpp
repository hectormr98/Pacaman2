#include "Ghost.h"
#include"Game.h"
#include"GameMap.h"

Ghost::Ghost() {
	IniX = IniY = posX = posY = 0;
}
//constructora default que deja el fantasma en la posicion (0,0)

Ghost::Ghost(Game* game, int x, int y, SDL_Renderer* rend)
{
	this->game = game;
	posX = IniX = x;
	posY = IniY = y;
	dir = 0;
	render = rend;
	if (!textGhost->loadText(("..\\images\\characters1.png"), 4, 14, render)) game->error = true;
}
//Constructora que situa al fantasma en una posicion dada

int Ghost::getPosX() {
	return posX;
}
//Devuelve su X

int Ghost::getPosY() {
	return posY;
}
//Devuelve su Y

Ghost::~Ghost()
{
	delete textGhost;
}
//Destructora de Ghost

void Ghost::CambiaDir()
{
	int auxDir = 0;
	int contador = 0;
	vector<int> posible;
	for (int i = 0; i < 4; i++)
	{
		if (game->NextCell(posX, posY, i) && i != (dir + 2) % 4)
		{
			contador++;
			posible.push_back(i);
		}
		
	}
	if (contador >= 1)
	{
		auxDir = rand() % contador;
		dir = posible[auxDir];
	}
	else if(contador == 0)
	{
		dir = (dir + 2) % 4;
	}
}
//Comprueba las 4 posibles direcciones del Fantasma, descarta las inválidas y elige una de las posibles al azar

int Ghost::GetAnim()
{
	return anim;
}
//Devuelve la animacion actual del fantasma

void Ghost::Mueve(int fils, int cols)
{

	CambiaDir();
		if (dir == 0)
		{
			posY = (posY + 1) % cols;
		}
		else if (dir == 1)
		{
			posX = (posX + 1) % fils;
		}
		else if (dir == 2)
		{
			if (posY - 1 < 0) posY = cols - 1;

			else posY--;
		}
		else if (dir == 3)
		{
			if (posX - 1 < 0) posX = fils - 1;

			else posX--;
		}
		if (anim == 1) anim = 0;
		else anim = 1;

}
//Mueve al fantasma en la direccion proporcionada por CambiaDir()

void Ghost::SetInicio(){
	posX = IniX;
	posY = IniY;
}
//Devuelve al fantasma a su posicion inicial

void Ghost::RenderGhost(SDL_Rect rekt, int d, PacMan* pacman)
{
	
	if (pacman->Come)
	{
		textGhost->RenderFrame(12, 0, rekt, render);
	}
	else
	{
		if (GetAnim() == 0)
			textGhost->RenderFrame(d * 2, 0, rekt, render);
		else
			textGhost->RenderFrame(d * 2 + 1, 0, rekt, render);
	}
}
//Pinta al fantasma y lo anima en sus distintos casos