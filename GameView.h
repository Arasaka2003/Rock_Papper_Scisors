#ifndef _GAME_VIEW_H_
#define _GAME_VIEW_H_

#include <SFML/Graphics.hpp>
#include <string>
#include "InputData.h"

/**
 * @file GameView.h
 * @brief Definiția clasei GameView.
 *
 * Proiect: Rock-Paper-Scissors
 * Autor: Crăciunel Daniel
 * An: 2024
 */

 /**
  * @class GameView
  * @brief Clasă responsabilă cu afișarea grafică a elementelor jocului.
  *
  * Clasa încarcă texturile pentru Rock, Paper și Scissors și le desenează în fereastră.
  */
class GameView {
public:
    /**
     * @brief Constructorul clasei GameView, încarcă resursele grafice.
     */
    GameView();

    /**
     * @brief Destructorul clasei GameView.
     */
    ~GameView();

    /**
     * @brief Încarcă texturile și initializează sprite-urile.
     */
    void LoadAssets();

    /**
     * @brief Desenează inputul (Rock/Paper/Scissors) unui jucător în fereastră.
     * @param window Referință la fereastra SFML în care se desenează.
     * @param input InputDataType al jucătorului (Rock/Paper/Scissors).
     * @param isPlayer Dacă true, simbolul este jucătorul, altfel adversarul.
     */
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
