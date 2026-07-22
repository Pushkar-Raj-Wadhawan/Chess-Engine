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

UndoInfo Board::makeMove(const Move& m) {
    UndoInfo info;
    // unique ptr operations
    info.capturedPiece = move(grid[m.to.row][m.to.col]);
    info.movedPieceHadMoved = grid[m.from.row][m.from.col]->getHasMoved();
    grid[m.to.row][m.to.col] = move(grid[m.from.row][m.from.col]);
    grid[m.to.row][m.to.col]->setHasMoved(true);
    return info;
}

void Board::undoMove(const Move& m, UndoInfo& info) {
    grid[m.from.row][m.from.col] = move(grid[m.to.row][m.to.col]);
    grid[m.to.row][m.to.col] = move(info.capturedPiece);
    grid[m.from.row][m.from.col]->setHasMoved(info.movedPieceHadMoved);
}