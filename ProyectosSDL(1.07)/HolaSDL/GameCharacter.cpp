#include "GameCharacter.h"



GameCharacter::GameCharacter(int posx, int posy)
{
	PosX = posx;
	PosY = posy;

	IniX = posx;
	IniY = posy;

	text = new Texture();
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
void GameCharacter::render(){}
void GameCharacter::update(){}
bool GameCharacter::saveToFile(string filename) { return true; }
