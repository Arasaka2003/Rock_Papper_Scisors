#ifndef _GAME_MODEL_H_
#define _GAME_MODEL_H_
#include <iostream>
#include "InputData.h"
using namespace std;

class GameModel
{
public:
    GameModel();
    ~GameModel();
    InputDataType WrapInput(int playerInput);
    void CheckWinner(InputDataType Player, InputDataType Computer);
private:
};

#endif
