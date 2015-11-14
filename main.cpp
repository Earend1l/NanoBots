#include <iostream>
#include "GameClient.h"

using namespace std;

int main()
{
    GameClient& game = GameClient::getInstance();
    game.start();
    return 0;
}
