#ifndef _GAME_CONTROLLER_H_
#define _GAME_CONTROLLER_H_

#include "GameView.h"
#include "GameModel.h"
#include <memory>
#include <iostream>

class GameController {
public:
    GameController();
    GameController(const GameController& controller);
    GameController& operator=(const GameController& controller);
    bool operator==(const GameController& controller) const;
    friend std::ostream& operator<<(std::ostream& os, const GameController& controller);
    friend std::istream& operator>>(std::istream& is, GameController& controller);
    GameController(std::shared_ptr<GameView> view, std::shared_ptr<GameModel> model, int id);
    ~GameController() = default; 
    void StartGame();
private:
    std::shared_ptr<GameModel> gameModelInstance; 
    std::shared_ptr<GameView> gameViewInstance;   
    int instanceId = 0;
};
#endif