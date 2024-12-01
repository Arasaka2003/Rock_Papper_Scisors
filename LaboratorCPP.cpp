#include "GameController.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <algorithm>

int main() {
    // Создание экземпляров GameView и GameModel
    auto gameView = std::make_shared<GameView>();
    auto gameModel = std::make_shared<GameModel>();

    // Создание GameController и передача зависимостей
    GameController controller(gameView, gameModel, 1);

    // Запуск игры
    try {
        controller.StartGame();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}