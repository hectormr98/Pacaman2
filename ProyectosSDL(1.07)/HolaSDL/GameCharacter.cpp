#include "GameCharacter.h"

GameCharacter::GameCharacter(int posx, int posy, Game* game, SDL_Renderer* rend) : GameObject()
{
	PosX = posx;
	PosY = posy;

	IniX = posx;
	IniY = posy;

	text = new Texture();

	dir = 0;

	gueim = game;

	render = rend;
	/*GO->render = {
	
	};*/
	//GameObject::gueim

}
/*
bool GameCharacter::loadFromFile(string filename) {
	ifstream archivo;
	archivo.open;
	archivo >> IniX >> " " >> IniY >> " " >> PosX >> " " >> PosY >> " " >> dir;
	archivo.close;
	return !(archivo.fail);
}
*/
GameCharacter::~GameCharacter()
{
}

bool GameCharacter::loadFromFile(string filename) { return true; }
void GameCharacter::Render(){}
void GameCharacter::update(){}
bool GameCharacter::saveToFile(string filename) { return true; }
