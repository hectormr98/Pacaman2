#include "PacMan.h"
#include"Game.h"
#include"GameMap.h"

PacMan::PacMan() {
	posX = posY = IniX = IniY = 0;
	//si no le pasamos parametros, asumiremos que PacMan esta en la posicion (0,0)
}
//Constructora predeterminada

PacMan::PacMan(Game* game, int x, int y, SDL_Renderer* rend)
{
	this->game = game;
	posX = IniX = x;
	posY = IniY = y;
	dir = 0;
	render = rend;
	if (!textPac->loadText(("..\\images\\characters1.png"), 4, 14, render)) game->error = true;
	//le pasamos como parametros una x y una y, y situamos un PacMan en la posicion dada
}
//Constructora que coloca al Pac-Man

int PacMan::getPosX() {
	return posX;
}
//Devuelve la X

int PacMan::getPosY() {
	return posY;
}
//Devuelve la Y

int PacMan::GetDir()
{
	return dir;
}
//Devuelve la dirección actual

int PacMan::getTicks() {
	return numTicks;
}

void PacMan::CambiaEstado(int i)
{
	if (i == 0)
	{
		estado = DerCerrado;
	}
	else if (i == 1)
	{
		estado = DerAbierto;
	}
	else if (i == 2)
	{
		estado = BotCerrado;
	}
	else if (i == 3)
	{
		estado = BotAbierto;
	}
	else if (i == 4)
	{
		estado = IzqCerrado;
	}
	else if (i == 5)
	{
		estado = IzqAbierto;
	}
	else if (i == 6)
	{
		estado = TopCerrado;
	}
	else if (i == 7)
	{
		estado = TopAbierto;
	}
}
//Cambia la animación actual del Pac-Man

void PacMan::Mueve(int fils, int cols) 
{
	if ((dir2 == 0) && game->NextCell(posX, posY,dir2))
	{
		posY = (posY + 1)%cols;
		dir = dir2;
		dir2 = -1;
		estado = DerCerrado;
	}
	else if ((dir2 == 1) && game->NextCell(posX, posY, dir2))
	{
		posX = (posX+1)%fils;
		dir = dir2;
		dir2 = -1;
		estado = BotCerrado;
	}
	else if ((dir2 == 2) && game->NextCell(posX, posY, dir2))
	{
		if (posY - 1 < 0) posY = cols - 1;

		else posY--;
		dir = dir2;
		dir2 = -1;
		estado = IzqCerrado;
	}
	else if ((dir2 == 3) && game->NextCell(posX, posY, dir2))
	{
		if (posX - 1 < 0) posX = fils - 1;
		else posX--;

		dir = dir2;
		dir2 = -1;
		estado = TopCerrado;
	}


	else if ((dir == 0) && game->NextCell(posX, posY, dir))
	{
		posY = (posY + 1)%cols;
	}
	else if ((dir == 1) && game->NextCell(posX, posY, dir))
	{
		posX= (posX + 1) % fils;
	}
	else if ((dir == 2) && game->NextCell(posX, posY, dir))
	{
		if (posY - 1 < 0) posY = cols - 1;

		else posY--;
	}
	else if ((dir == 3) && game->NextCell(posX, posY, dir))
	{
		if (posX - 1 < 0) posX = fils - 1;

		else posX--;
	}

}
//Mueve a Pac-Man en la nueva dirección proporcionada, o en la dirección anterior en su defecto

void PacMan::CambiaDir(int newdir)
{
	dir2 = newdir;
}
//Cambia la nueva direccion de Pac-Man

estadoPacMan PacMan::getEstado() {
	return estado;
}
//Devuelve la animación actual de Pac-Man

PacMan::~PacMan()
{
	delete textPac;
}
//Destructora de Pac-Man

void PacMan::Contador()
{
	if (Come)
	{
		if (contador <= 50)
		{
			contador++;
		}
		else
		{
			Come = false;
		}
	}
}
//Calcula el tiempo que esta Pac-Man en modo "COME"

void PacMan::RestartContador()
{
	contador = 0;
}
//Devuelve el contador a 0

void PacMan::RenderPac(SDL_Rect recta)
{
	int f = 0;
	bool acaba = false;
	while (f< 4 && !acaba)
	{
		if (dir == f)
		{
			if (estado == f * 2)
			{
				CambiaEstado(f * 2 + 1);
				textPac->RenderFrame(10, f, recta, render);
				acaba = true;
			}
			else
			{
				CambiaEstado(f * 2);
				textPac->RenderFrame(11, f, recta, render);
			}
		}
		f++;
	}
}
//Pinta a Pac-Man y a sus respectivas animaciones