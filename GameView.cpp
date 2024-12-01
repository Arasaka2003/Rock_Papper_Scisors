#include "GameView.h"
#include <iostream>

GameView::GameView() {
    LoadAssets();
}

GameView::~GameView() {}

void GameView::LoadAssets() {
    if (!rockTexture.loadFromFile("assets/rock.png")) {
        std::cerr << "Failed to load rock.png\n";
    }
    if (!paperTexture.loadFromFile("assets/paper.png")) {
        std::cerr << "Failed to load paper.png\n";
    }
    if (!scissorsTexture.loadFromFile("assets/scissors.png")) {
        std::cerr << "Failed to load scissors.png\n";
    }

    rockSprite.setTexture(rockTexture);
    paperSprite.setTexture(paperTexture);
    scissorsSprite.setTexture(scissorsTexture);

   
    float scaleFactor = 150.f / 640.f;
    rockSprite.setScale(scaleFactor, scaleFactor);
    paperSprite.setScale(scaleFactor, scaleFactor);
    scissorsSprite.setScale(scaleFactor, scaleFactor);
}

void GameView::Render(sf::RenderWindow& window, InputDataType input, bool isPlayer) {
    sf::Sprite* sprite = nullptr;

    switch (input) {
    case Rock:
        sprite = &rockSprite;
        break;
    case Paper:
        sprite = &paperSprite;
        break;
    case Scissors:
        sprite = &scissorsSprite;
        break;
    default:
        std::cerr << "Invalid input type for rendering\n";
        return;
    }

  
    if (isPlayer) {
        sprite->setPosition(100.f, 300.f); 
    }
    else {
        sprite->setPosition(500.f, 300.f); 
    }

    window.draw(*sprite);
}
