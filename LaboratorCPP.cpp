#include <iostream>
#include "GameController.h"


int main()
{
   auto view=std::make_shared<GameView>();
   auto model=std::make_shared<GameModel>();
   GameController controller1(view, model,4); 
   cout << "Controller1Id:" << endl << controller1;
   GameController controller2(controller1); 
   cout << "Controller2Id:"<<endl << controller2;
   GameController controller3;
   cout << "Controller3Id:"<<endl << controller3;
   controller3 = controller1; 
   cout << "Controller3Id:" <<endl<< controller3;
   if (controller1 == controller2) 
   {
       cout << "Controllers 1 and 2 are equal!" << endl;
   }
   cout << "Controller3 EnterID:" << endl;
   cin >> controller3;
   cout << "Controller3Id:"<<endl << controller3;
   int x;
   cin >> x;
return 0;
}

