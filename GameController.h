#ifndef _GAME_CONTROLLER_H_
#define _GAME_CONTROLLER_H_

#include "GameView.h"
#include "GameModel.h"

class GameController
{
public:
    GameController();
    GameController(const GameController& controller);
    GameController& operator=(const GameController& controller);
    bool operator==(const GameController& controller);
    friend ostream& operator<<(ostream& os, const GameController& controller);
    friend istream& operator>>(istream& is, GameController& controller);
    GameController(GameView& View, GameModel& Model,int id);
    ~GameController();
    void StartGame();
private:
    GameModel* GameModelInstance;
    GameView* GameViewInstance;
    int InstanceId = 0;
};
#endif
