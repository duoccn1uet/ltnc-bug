#ifndef GAME_H
#define GAME_H

#include "CommonFunc.h"

class Game
{
public:


    string MAP_NAME;

    Game();
    Game(const string& _MAP_NAME);
    ~Game();
    void ShowMenu();

private:
};

#endif // GAME_H

