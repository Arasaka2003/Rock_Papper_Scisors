#ifndef _GAME_CONTROLLER_H_
#define _GAME_CONTROLLER_H_

#include "GameView.h"
#include "GameModel.h"
#include "GameData.h"
#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>

/**
 * @file GameController.h
 * @brief Definiția clasei GameController.
 *
 * Proiect: Rock-Paper-Scissors
 * Autor: Crăciunel Daniel 
 * An: 2024
 */

 /**
  * @class GameController
  * @brief Clasă ce gestionează logica jocului, interacțiunea cu utilizatorul și afișarea grafică.
  *
  * GameController folosește GameModel pentru a interpreta inputul, GameView pentru a afișa
  * elementele grafice și GameData pentru a menține starea jocului.
  */
class GameController {
public:
    /**
     * @brief Constructor implicit.
     */
    GameController();

    /**
     * @brief Constructor de copiere.
     * @param controller Obiectul GameController sursă.
     */
    GameController(const GameController& controller);

    /**
     * @brief Operator de atribuire.
     * @param controller Obiectul GameController sursă.
     * @return Referință la *this.
     */
    GameController& operator=(const GameController& controller);

    /**
     * @brief Operator de egalitate.
     * @param controller Obiectul GameController cu care se compară.
     * @return true dacă sunt egale, altfel false.
     */
    bool operator==(const GameController& controller) const;

    /**
     * @brief Operator de afișare pentru GameController.
     * @param os Streamul de ieșire.
     * @param controller Obiectul GameController.
     * @return Referință la stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const GameController& controller);

    /**
     * @brief Operator de citire pentru GameController.
     * @param is Streamul de intrare.
     * @param controller Obiectul GameController în care se citește.
     * @return Referință la stream.
     */
    friend std::istream& operator>>(std::istream& is, GameController& controller);

    /**
     * @brief Constructor care primește instanțe de GameView și GameModel și un ID.
     * @param view Instanță GameView.
     * @param model Instanță GameModel.
     * @param id ID-ul unic al controller-ului.
     */
    GameController(std::shared_ptr<GameView> view, std::shared_ptr<GameModel> model, int id);

    /**
     * @brief Destructor implicit.
     */
    ~GameController() = default;

    /**
     * @brief Pornește bucla principală a jocului, primește input utilizator și afișează rezultatele.
     */
    void StartGame();

private:
    std::shared_ptr<GameModel> gameModelInstance;
    std::shared_ptr<GameView> gameViewInstance;
    int instanceId = 0;

    /**
     * @brief Renderizează inputul jucătorului, inputul adversarului și rezultatul pe fereastră.
     * @param window Referință la fereastra SFML.
     * @param player Inputul jucătorului.
     * @param opponent Inputul adversarului.
     * @param result Rezultatul jocului.
     */
    void RenderInputs(sf::RenderWindow& window, InputDataType player, InputDataType opponent, const std::string& result);
};

#endif
