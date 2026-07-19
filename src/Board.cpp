#include "../include/Board.h"

Board::Board() {}

Piece* Board::getPieceAt(Position pos) const {
    int r = pos.row, c = pos.col;
    return grid[r][c].get();
}


void Board::placePieceAt(unique_ptr<Piece> piece, Position pos) {
    int r = pos.row, c = pos.col;
    grid[r][c] = move(piece);
}