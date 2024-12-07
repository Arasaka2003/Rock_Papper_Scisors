#include <cassert>
#include <iostream>
#include "../../GameData.h"
#include "../../InputData.h"

int main() {
    // Inițializare GameData
    GameData::Initialize();
    assert(GameData::GetPlayerInput() == InputDataType::null);
    assert(GameData::GetOpponentInput() == InputDataType::null);
    assert(GameData::GetResult().empty());
    std::cout << "Test: Initialize passed.\n";

    // Setare player input
    GameData::SetPlayerInput(InputDataType::Rock);
    assert(GameData::GetPlayerInput() == InputDataType::Rock);
    std::cout << "Test: SetPlayerInput and GetPlayerInput passed.\n";

    // Setare opponent input
    GameData::SetOpponentInput(InputDataType::Paper);
    assert(GameData::GetOpponentInput() == InputDataType::Paper);
    std::cout << "Test: SetOpponentInput and GetOpponentInput passed.\n";

    // Setare rezultat
    GameData::SetResult("You Win!");
    assert(GameData::GetResult() == "You Win!");
    std::cout << "Test: SetResult and GetResult passed.\n";

    // Reinițializare
    GameData::Initialize();
    assert(GameData::GetPlayerInput() == InputDataType::null);
    assert(GameData::GetOpponentInput() == InputDataType::null);
    assert(GameData::GetResult().empty());
    std::cout << "Test: Re-initialize passed.\n";

    std::cout << "All tests passed!\n";
    return 0;
}
