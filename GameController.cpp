#include "GameController.h"
#include <cstdlib>
#include <ctime>


GameController::GameController()
    : gameModelInstance(std::make_shared<GameModel>()),
    gameViewInstance(std::make_shared<GameView>()),
    instanceId(0) {
    std::srand(static_cast<unsigned>(std::time(0))); 
}


GameController::GameController(const GameController& controller)
    : gameModelInstance(controller.gameModelInstance),
    gameViewInstance(controller.gameViewInstance),
    instanceId(controller.instanceId) {}


GameController& GameController::operator=(const GameController& controller) {
    if (this != &controller) {
        gameModelInstance = controller.gameModelInstance;
        gameViewInstance = controller.gameViewInstance;
        instanceId = controller.instanceId;
    }
    return *this;
}


bool GameController::operator==(const GameController& controller) const {
    return (instanceId == controller.instanceId) &&
        (gameModelInstance == controller.gameModelInstance) &&
        (gameViewInstance == controller.gameViewInstance);
}


GameController::GameController(std::shared_ptr<GameView> view, std::shared_ptr<GameModel> model, int id)
    : gameModelInstance(std::move(model)),
    gameViewInstance(std::move(view)),
    instanceId(id) {}


std::ostream& operator<<(std::ostream& os, const GameController& controller) {
    os << "GameController Instance ID: " << controller.instanceId << "\n";
    return os;
}


std::istream& operator>>(std::istream& is, GameController& controller) {
    std::cout << "Enter Instance ID: ";
    is >> controller.instanceId;
    return is;
}

void GameController::StartGame() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Rock-Paper-Scissors");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        int input;
        InputDataType playerResult = InputDataType::null;
        InputDataType opponentResult = InputDataType::null;


        std::cout << "Enter Input (1-Rock, 2-Paper, 3-Scissors): ";
        std::cin >> input;
        playerResult = gameModelInstance->WrapInput(input);

        if (playerResult == InputDataType::null) {
            std::cout << "Invalid input, try again.\n";
            continue;
        }


        GameData::SetPlayerInput(playerResult);


        opponentResult = gameModelInstance->WrapInput((std::rand() % 3) + 1);


        GameData::SetOpponentInput(opponentResult);

        std::string result;
        if (playerResult == opponentResult) {
            result = "Draw!";
        }
        else if ((playerResult == Rock && opponentResult == Scissors) ||
            (playerResult == Scissors && opponentResult == Paper) ||
            (playerResult == Paper && opponentResult == Rock)) {
            result = "You Win!";
        }
        else {
            result = "You Lose!";
        }


        GameData::SetResult(result);


        RenderInputs(window, GameData::GetPlayerInput(), GameData::GetOpponentInput(), GameData::GetResult());
    }
}
    void GameController::RenderInputs(sf::RenderWindow & window, InputDataType player, InputDataType opponent, const std::string & result) {
        window.clear(sf::Color::White);

     
        gameViewInstance->Render(window, player, true);

  
        gameViewInstance->Render(window, opponent, false);

  
        sf::Font font;
        if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
            std::cerr << "Failed to load font\n";
            return;
        }

        sf::Text text;
        text.setFont(font);
        text.setString(result);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Black);

     
        sf::FloatRect textBounds = text.getLocalBounds();
        text.setPosition(
            (window.getSize().x - textBounds.width) / 2,
            (window.getSize().y - textBounds.height) / 2
        );

        window.draw(text);
        window.display();
    }


