#include "GameController.h"

GameController::GameController()
    : gameModelInstance(std::make_shared<GameModel>()),
    gameViewInstance(std::make_shared<GameView>()),
    instanceId(0) {}

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
 void GameController::StartGame() 
 {
	 int input;
	 InputDataType Result = InputDataType::null;
	 InputDataType OponentResult = InputDataType::null;
	 do {
	     cout << "EnterInput,1-Rock,2-Paper,3-Scissors:" << endl;
	     cin >> input;
		 Result=gameModelInstance->WrapInput(input);
	 }
	 while (Result==null);
	
	 OponentResult= gameModelInstance->WrapInput((rand()%3)+1);
	
	 cout << "Player:" << endl;
	 gameViewInstance->PrintInput(Result,false);
	 cout << "Computer:" << endl;
	 gameViewInstance->PrintInput(OponentResult,true);
	 gameModelInstance->CheckWinner(Result, OponentResult);
	 StartGame();
 }


