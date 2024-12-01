#include "GameData.h"


InputDataType GameData::playerInput = InputDataType::null;
InputDataType GameData::opponentInput = InputDataType::null;
std::string GameData::result = "";


void GameData::Initialize() {
    playerInput = InputDataType::null;
    opponentInput = InputDataType::null;
    result = "";
}


void GameData::SetPlayerInput(InputDataType input) {
    playerInput = input;
}


void GameData::SetOpponentInput(InputDataType input) {
    opponentInput = input;
}


void GameData::SetResult(const std::string& res) {
    result = res;
}


InputDataType GameData::GetPlayerInput() {
    return playerInput;
}


InputDataType GameData::GetOpponentInput() {
    return opponentInput;
}


const std::string& GameData::GetResult() {
    return result;
}
