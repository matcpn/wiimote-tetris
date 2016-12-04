#include "Board.h"
#include <stdio.h>
#include <iostream>

Board::Board(){};

char Board::board_array[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void Board::DrawBoard()
{

        std::system("clear"); // OS X
        // Uncomment for Linux architectures
        // std::system("cls");

        std::cout << "\n\n\tTic-Tac-Toe\t\n\n";
        std::cout << "Player 1 (X)  -  Player 2 (O)\n";

        std::cout << "     |     |     \n";
        std::cout << "  " << board_array[0] << "  |  " << board_array[1] << "  |  " << board_array[2] << "  \n";
        std::cout << "     |     |     \n";
        std::cout << "-----|-----|-----\n";

        std::cout << "     |     |     \n";
        std::cout << "  " << board_array[3] << "  |  " << board_array[4] << "  |  " << board_array[5] << "  \n";
        std::cout << "     |     |     \n";
        std::cout << "-----|-----|-----\n";

        std::cout << "     |     |     \n";
        std::cout << "  " << board_array[6] << "  |  " << board_array[7] << "  |  " << board_array[8] << "  \n";
        std::cout << "     |     |     \n";
}

void Board::SetOldValue(int cursor, char old_value)
{
        board_array[cursor] = old_value;
}

char Board::PlaceCursor(int cursor)
{
        char old_value = board_array[cursor];
        board_array[cursor] = '_';
        return old_value;
}

void Board::MarkSquare(int pos, char marker)
{
        if(board_array[pos] != 'X' && board_array[pos] != 'O')
        {
                board_array[pos] = marker;
        }
}


