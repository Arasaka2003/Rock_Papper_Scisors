#ifndef _GAME_DATA_H_
#define _GAME_DATA_H_

#include "InputData.h"
#include <string>

class GameData {
public:

    static void Initialize();
    static void SetPlayerInput(InputDataType input);
    static void SetOpponentInput(InputDataType input);
    static void SetResult(const std::string& result);

    static InputDataType GetPlayerInput();
    static InputDataType GetOpponentInput();
    static const std::string& GetResult();

private:

    static InputDataType playerInput;
    static InputDataType opponentInput;
    static std::string result;
};

#endif
