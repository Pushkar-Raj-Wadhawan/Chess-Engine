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

    if(m.isCastle) {
        grid[m.rookTo.row][m.rookTo.col] = move(grid[m.rookFrom.row][m.rookFrom.col]);
        grid[m.rookTo.row][m.rookTo.col]->setHasMoved(true);
    }
    return info;
}

void Board::undoMove(const Move& m, UndoInfo& info) {
    grid[m.from.row][m.from.col] = move(grid[m.to.row][m.to.col]);
    grid[m.to.row][m.to.col] = move(info.capturedPiece);
    grid[m.from.row][m.from.col]->setHasMoved(info.movedPieceHadMoved);

    if(m.isCastle) {
        grid[m.rookFrom.row][m.rookFrom.col] = move(grid[m.rookTo.row][m.rookTo.col]);
        grid[m.rookFrom.row][m.rookFrom.col]->setHasMoved(false);
    }
}

bool Board::isSquareAttacked(Position target, Color attacker) const {
    for(int r = 0; r < 8; r++) {
        for(int c = 0; c < 8; c++) {
            if(grid[r][c] == nullptr || grid[r][c]->getColor() != attacker) continue;
            Position from{r, c};
            vector<Move> moves = grid[r][c]->getPseudoLegalMoves(from, *this);
            for(auto& m: moves) {
                if(m.to == target) return true;
            }
        }
    }
    return false;
}

bool Board::isInCheck(Color kingColor) {
    // find c king's position
    Position kingPos {-1, -1};
    for(int r = 0; r < 8; r++) {
        for(int c = 0; c < 8; c++) {
            if(grid[r][c] != nullptr && grid[r][c]->getPieceType() == PieceType::KING && grid[r][c]->getColor() == kingColor) {
                kingPos.row = r;
                kingPos.col = c;
                break;
            }
        }
        if(kingPos.row != -1) break;
    }
    if(kingPos == Position{-1, -1}) return false;
    return isSquareAttacked(kingPos, (kingColor == Color::WHITE ? Color::BLACK : Color::WHITE));
}

vector<Move> Board::getLegalMoves(Color color) {
    vector<Move> legalMoves;
    for(int r = 0; r < 8; r++) {
        for(int c = 0; c < 8; c++) {
            if(grid[r][c] == nullptr || grid[r][c]->getColor() != color) continue;
            Position from {r, c};
            vector<Move> pseudoMoves = grid[r][c]->getPseudoLegalMoves(from, *this);
            for(auto& m : pseudoMoves) {
                UndoInfo info = makeMove(m);
                if(!isInCheck(color)) legalMoves.emplace_back(m);
                undoMove(m, info);
            }
        }
    }
    return legalMoves;
}