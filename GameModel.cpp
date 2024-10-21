#include "GameModel.h"
#include "InputData.h"
GameModel::GameModel(){}
InputDataType GameModel::WrapInput(int playerInput)
{
    switch (playerInput)
    {
    case 1:
        return Rock;
    case 2:
        return Paper;
    case 3:
        return Scissors;
    default:
        cout << "Input Again" << endl;
        return null;
    }
}
void GameModel::CheckWinner(InputDataType Player, InputDataType AI)
{
    if (Player == AI)
    {
        cout << "DRAW" << endl;
        return;
    }
    if ((Player == Rock && AI == Scissors) || (Player == Scissors && AI == Paper) || (Player == Paper && AI == Rock))
        cout << "YouWin"<< endl;
    else
        cout << "ComputerWins"<< endl;


}

GameModel::~GameModel() {}
