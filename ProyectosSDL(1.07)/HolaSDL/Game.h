#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include<iostream>
#include<fstream>
#include "Texture.h"
#include<vector>

class GameCharacter;
class PacMan;
class Ghost;
class GameMap;


using namespace std;

class Game 
{
private:
	SDL_Window*window = nullptr;
	//variables window de la SDL

	SDL_Renderer* render = nullptr;
	//variable render de la SDL

	GameMap* map = nullptr;
	//puntero a mapa del juego

	PacMan* pacman = nullptr;
	//puntero a pacman

	Ghost* ghosts[4];
	//array de punteros a fantasmas

	vector<Texture*>texturas;
	//vector de punteros a texturas
	Texture* menu = new Texture();

	SDL_Rect destRec;
	//rectangulo destino, donde se pintara algo en pantalla

	SDL_Event evento;

	bool exit = false;
	//variable para controlar el final de la ventana

	bool comienza = false;

	int menuAnim = 0;

	int WinWidth = 800;
	int WinHeight = 600;
	//dimensiones de la pantalla


	int Fils = 0,
		Cols = 0;
	//filas y columnas del mapa

	int puntos = 0;
	int maxPunt = 0;

	const int numText = 4;
	//numero de imagenes o texturas que se van a cargar

public:

	bool error = false;
	//variable para comprobar si ha habido un error en la carga de un archivo

	Game();
	//constructora, inicializa todo

	~Game();
	//destructora, deja todo a nullptr o lo destruye

	bool SetMap(string filename);
	//carga un mapa de un fichero de texto dado

	void LoadTextures();
	//carga todas las texturas (en este caso, 4)
	
	void GUI();

	void run();
	
	void Renderizado();
	
	void handleEvents();
	bool NextCell(int x, int y, int dir);
	void Update();
	void Colision();
	bool finJuego();
	void Menu();
	void MenuEvents();
};

