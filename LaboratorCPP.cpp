#include <iostream>
#include "GameController.h"


int main()
{
   GameView view;
   GameModel model;
   GameController controller1(view, model,4); 
   cout << "Controller1Id:" << controller1;
   GameController controller2(controller1); 
   cout << "Controller2Id:" << controller2;
   GameController controller3;
   cout << "Controller3Id:" << controller3;
   controller3 = controller1; 
   cout << "Controller3Id:" << controller3;
   if (controller1 == controller2) 
   {
       cout << "Controllers are equal!" << endl;
   }
   cout << "Controller3 EnterID:" << endl;
   cin >> controller3;
   cout << "Controller3Id:" << controller3;
   int x;//build
   cin >> x;
return 0;
}

