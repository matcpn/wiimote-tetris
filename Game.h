#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Board.h"

class Game {
        Board *board;
        int turn;
        int cursor;
        char temp;
        int game_ended;

public:
        Game(Board *board);
        int GetGameEnded();
        void StartGame();
        void MoveCursor(char dir);
        void MarkSquare(int cursor, char marker);
        void Update();
        int CheckWin();

};

#endif
