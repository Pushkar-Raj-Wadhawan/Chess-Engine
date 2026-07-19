#include "../include/Board.h"

Piece* Board::getPieceAt(Position pos) const {
    int r = pos.row, c = pos.col;
    return grid[r][c];
}
