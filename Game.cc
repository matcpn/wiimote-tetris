#include <iostream>
#include <stdio.h>
#include "Board.h"
#include "Game.h"

Game::Game(Board *board)
{
        this->board = board;
        this->turn = 0;
        this->cursor = 4;
        this->temp = this->board->board_array[cursor];
        this->game_ended = -1;
};


void Game::StartGame()
{
        temp = board->PlaceCursor(cursor);

        board->SetOldValue(cursor, '_');
}

void Game::Update()
{
        board->DrawBoard();
}

void Game::MoveCursor(char dir)
{
        if (dir == 'w')
        {
                board->SetOldValue(cursor, temp);
                cursor = ((cursor - 3) + 9) % 9;
                temp = board->PlaceCursor(cursor);
        }
        else if (dir == 'a')
        {
                board->SetOldValue(cursor, temp);
                cursor = ((cursor - 1) + 9) % 9;
                temp = board->PlaceCursor(cursor);
        }
        else if (dir == 's')
        {
                board->SetOldValue(cursor, temp);
                cursor = ((cursor + 3) + 9) % 9;
                temp = board->PlaceCursor(cursor);
        }
        else if (dir == 'd')
        {
                board->SetOldValue(cursor, temp);
                cursor = ((cursor + 1) + 9) % 9;
                temp = board->PlaceCursor(cursor);
        }
        else if(dir == 'b') {
                char marker = turn == 0 ? 'X' : 'O';
                temp = marker;
                board->MarkSquare(cursor, marker);

                game_ended = CheckWin();

                if (game_ended == 1)
                {
                        std::cout << "The " << marker << "'s have won!\n";
                }
                else if (game_ended == 0)
                {
                        std::cout << "Looks like a tie!\n";
                }
                else
                {
                        turn = (turn + 1) % 2;
                }

        }
        else {
                std::cout << "Try using the DPAD and the A Button on the Wiimote\n";
                // Consider learning how to clear stdin
        }
}

int Game::CheckWin()
{

        // Win Cases:
        if(board->board_array[0] == board->board_array[1] &&
                board->board_array[2] == board->board_array[1])
        {
                return 1;
        }
        else if(board->board_array[3] == board->board_array[4] &&
                board->board_array[5] == board->board_array[4])
        {
                return 1;
        }
        else if(board->board_array[6] == board->board_array[7] &&
                board->board_array[8] == board->board_array[7])
        {
                return 1;
        }
        else if(board->board_array[0] == board->board_array[3] &&
                board->board_array[6] == board->board_array[3])
        {
                return 1;
        }
        else if(board->board_array[1] == board->board_array[4] &&
                board->board_array[7] == board->board_array[4])
        {
                return 1;
        }
        else if(board->board_array[2] == board->board_array[5] &&
                board->board_array[8] == board->board_array[5])
        {
                return 1;
        }
        else if(board->board_array[0] == board->board_array[4] &&
                board->board_array[8] == board->board_array[4])
        {
                return 1;
        }
        else if(board->board_array[2] == board->board_array[4] &&
                board->board_array[6] == board->board_array[4])
        {
                return 1;
        }

        // Draw Case
        int draw = 0;
        for(int index = 0; index < 9; index++)
        {
                if(board->board_array[index] == 'X' ||
                        board->board_array[index] == 'O')
                {
                        draw++;
                }
        }

        if (draw == 9)
        {
                return 0;
        }

        return -1;
}

int Game::GetGameEnded()
{
        return game_ended;
}

