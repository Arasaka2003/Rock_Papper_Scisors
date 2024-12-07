#ifndef _GAME_DATA_H_
#define _GAME_DATA_H_

#include "InputData.h"
#include <string>

/**
 * @file GameData.h
 * @brief Definiția clasei GameData.
 *
 * Proiect: Rock-Paper-Scissors
 * Autor: Crăciunel Daniel
 * An: 2024
 */

 /**
  * @class GameData
  * @brief Clasă statică ce reține starea internă a jocului (input jucător, input adversar, rezultat).
  */
class GameData {
public:
    /**
     * @brief Inițializează starea jocului la valori implicite.
     */
    static void Initialize();

    /**
     * @brief Setează inputul jucătorului.
     * @param input Valoare de tip InputDataType (Rock, Paper, Scissors, null).
     */
    static void SetPlayerInput(InputDataType input);

    /**
     * @brief Setează inputul adversarului.
     * @param input Valoare de tip InputDataType (Rock, Paper, Scissors, null).
     */
    static void SetOpponentInput(InputDataType input);

    /**
     * @brief Setează rezultatul jocului.
     * @param result String ce reprezintă rezultatul final ("You Win!", "You Lose!", "Draw!").
     */
    static void SetResult(const std::string& result);

    /**
     * @brief Obține inputul jucătorului.
     * @return InputDataType
     */
    static InputDataType GetPlayerInput();

    /**
     * @brief Obține inputul adversarului.
     * @return InputDataType
     */
    static InputDataType GetOpponentInput();

    /**
     * @brief Obține rezultatul jocului.
     * @return Referință constantă la std::string
     */
    static const std::string& GetResult();

private:
    /**
     * @brief Inputul curent al jucătorului.
     */
    static InputDataType playerInput;

    /**
     * @brief Inputul curent al adversarului.
     */
    static InputDataType opponentInput;

    /**
     * @brief Rezultatul curent al jocului.
     */
    static std::string result;
};

#endif
