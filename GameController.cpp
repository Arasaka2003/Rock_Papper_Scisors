 #include "GameController.h"

GameController::GameController() :InstanceId(0), GameModelInstance(nullptr), GameViewInstance(nullptr) {};
GameController::GameController(const GameController& controller) 
{
	GameModelInstance = controller.GameModelInstance;
	GameViewInstance = controller.GameViewInstance;
	InstanceId = controller.InstanceId;
}
GameController::GameController(GameView& View, GameModel& Model,int id):InstanceId(id), GameViewInstance(&View), GameModelInstance(&Model) {}
GameController& GameController::operator=(const GameController& controller) 
{
	GameModelInstance = controller.GameModelInstance;
	GameViewInstance = controller.GameViewInstance;
	InstanceId = controller.InstanceId;
	return *this;
}
bool GameController::operator==(const GameController& controller)
{
	if (GameModelInstance == controller.GameModelInstance && GameViewInstance == controller.GameViewInstance)
		return true;
	else
		return false;
}
istream& operator>>(istream& is, GameController& controller) 
{
	is >> controller.InstanceId;
	return is;
}
ostream& operator<<(ostream& os, const GameController& controller)
{
	os << controller.InstanceId << endl;
	return os;
}

 void GameController::StartGame() 
 {
	 int input;
	 InputDataType Result = InputDataType::null;
	 InputDataType OponentResult = InputDataType::null;
	 do {
	     cout << "EnterInput,1-Rock,2-Paper,3-Scissors:" << endl;
	     cin >> input;
		 Result=GameModelInstance->WrapInput(input);
	 }
	 while (Result==null);
	
	 OponentResult= GameModelInstance->WrapInput((rand()%3)+1);
	
	 cout << "Player:" << endl;
	 GameViewInstance->PrintInput(Result,false);
	 cout << "Computer:" << endl;
	 GameViewInstance->PrintInput(OponentResult,true);
	 GameModelInstance->CheckWinner(Result, OponentResult);
	 StartGame();
 }

GameController::~GameController() {}
