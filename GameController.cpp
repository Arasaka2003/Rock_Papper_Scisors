 #include "GameController.h"


GameController::GameController(GameView& View, GameModel& Model):GameViewInstance(&View), GameModelInstance(&Model) {}

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
