#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board {


public:
        Board();
        static char board_array[];
        void ConstructBoard();
        void DrawBoard();
        void SetOldValue(int cursor, char old_value);
        char PlaceCursor(int cursor);
        void MarkSquare(int pos, char marker);
};

#endif
