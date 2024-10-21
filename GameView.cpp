 #include "GameView.h"

 GameView::GameView() {}
 
 void GameView::PrintInput(InputDataType inputType,bool mirror)
 {
     switch (inputType)
     {
     case Rock:
         PrintRock(mirror);
         break;
     case Paper:
         PrintPaper(mirror);
         break;
     case Scissors:
         PrintScissors(mirror);
         break;
     default:
       std::cout << "Unknown input type" << endl;
         break;
     }
 }

void GameView::PrintRock(bool mirror)
{
    if (mirror)
    {
    cout << R"(
               _______
             (____   '---
            (_____)
            (_____)
            (____)
             (___)__.---
    )";
    }
    else
    {
    cout << R"(
        _______
    ---'   ____)
          (_____)
          (_____)
          (____)
    ---.__(___)
    )";
    }
}

void GameView::PrintPaper(bool mirror)
{
    if (mirror)
    {
        cout << R"(
               _______
          ____(___    '---
         (_______
          (_______
           (_______
            (__________.---
    )";
    }
    else
    {
            cout << R"(
         _______
    ---'    ____)____
               ______)
              _______)
             _______)
    ---.__________)
    )";
    }
}

void GameView::PrintScissors(bool mirror)
{
    if (mirror)
    {
        cout << R"(
                   _______
              ____(____   '---
             (______
            (__________
                (____)
                 (___)__.---
    )";
    }
    else
    {
        cout << R"(
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
)";
    }


}

GameView::~GameView() {}
