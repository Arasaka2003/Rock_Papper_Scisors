#ifndef _GAME_CONTROLLER_H_
#define _GAME_CONTROLLER_H_

#include "GameView.h"
#include "GameModel.h"

class GameController
{
public:
    GameController(GameView& View, GameModel& Model);
    ~GameController();
    void StartGame();
private:
    GameModel* GameModelInstance;
    GameView* GameViewInstance;
};
#endif
