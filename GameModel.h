#ifndef _GAME_MODEL_H_
#define _GAME_MODEL_H_

#include <iostream>
#include "InputData.h"

using namespace std;

/**
 * @file GameModel.h
 * @brief Definiția clasei GameModel.
 *
 * Proiect: Rock-Paper-Scissors
 * Autor: Crăciunel Daniel
 * An: 2024
 */

 /**
  * @class GameModel
  * @brief Clasă responsabilă cu interpretarea inputului utilizatorului și determinarea câștigătorului.
  *
  * GameModel oferă funcționalități pentru conversia inputului numeric (1,2,3) în tipul enumerat InputDataType
  * și pentru verificarea câștigătorului între două valori InputDataType (cea a jucătorului și cea a calculatorului).
  */
class GameModel
{
public:
    /**
     * @brief Constructorul clasei GameModel.
     */
    GameModel();

    /**
     * @brief Destructorul clasei GameModel.
     */
    ~GameModel();

    /**
     * @brief Convertește un input numeric de la utilizator (1,2,3) în InputDataType (Rock, Paper, Scissors).
     *
     * @param playerInput Un număr întreg (1 = Rock, 2 = Paper, 3 = Scissors).
     * @return Valoarea InputDataType corespunzătoare (Rock, Paper, Scissors) sau null dacă inputul este invalid.
     */
    InputDataType WrapInput(int playerInput);

    /**
     * @brief Verifică câștigătorul dintre jucător și calculator bazat pe InputDataType.
     *
     * @param Player InputDataType al jucătorului (Rock, Paper, Scissors).
     * @param Computer InputDataType al calculatorului (Rock, Paper, Scissors).
     *
     * Această metodă afișează rezultatul ("YouWin", "ComputerWins" sau "DRAW") direct în consolă.
     */
    void CheckWinner(InputDataType Player, InputDataType Computer);


};

#endif
