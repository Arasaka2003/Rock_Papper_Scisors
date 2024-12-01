#ifndef _GAME_VIEW_H_
#define _GAME_VIEW_H_

#include <SFML/Graphics.hpp>
#include <string>
#include "InputData.h"

class GameView {
public:
    GameView();
    ~GameView();

    void LoadAssets();
    void Render(sf::RenderWindow& window, InputDataType input, bool isPlayer);

private:
    sf::Texture rockTexture;
    sf::Texture paperTexture;
    sf::Texture scissorsTexture;

    sf::Sprite rockSprite;
    sf::Sprite paperSprite;
    sf::Sprite scissorsSprite;
};

#endif
