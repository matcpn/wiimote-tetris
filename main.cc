#include "Board.h"
#include "Game.h"
#include <stdio.h>
#include <iostream>

int main()
{
        Board *board = new Board();
        Game *game = new Game(board);
        char input;
        game->StartGame();

        do
        {

                game->Update();
                input = std::cin.get();
                game->MoveCursor(input);
        } while (game->GetGameEnded() == -1);




        return 0;
}
