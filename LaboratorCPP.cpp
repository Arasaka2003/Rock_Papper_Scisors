#include <iostream>
#include "GameController.h"


int main()
{
	srand(time(NULL));
	GameModel Model;
	GameView View;
	GameController Controller(View,Model);
	Controller.StartGame();
	return 0;
}

