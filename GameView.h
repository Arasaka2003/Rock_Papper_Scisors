#ifndef _GAME_VIEW_H_
#define _GAME_VIEW_H_

#include <iostream>
#include "InputData.h";
using namespace std;
class GameView
{
public:
    GameView();
    ~GameView();

    void PrintRock(bool mirror);
    void PrintPaper(bool mirror);
    void PrintScissors(bool mirror);
    void PrintInput(InputDataType input,bool mirror);

private:
};

#endif
