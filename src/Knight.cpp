#include "../include/Knight.h"
#include "../include/Board.h"

static void tryAddingMove(const Piece* piece, Position from, Position to, const Board& board, vector<Move>& moves) {
    if(to.isValid()) {
        Piece* targetPiece = board.getPieceAt(to);
        if(targetPiece == nullptr) {
            Move m;
            m.from = from;
            m.to = to;
            m.movedPiece = PieceType::KNIGHT;
            moves.emplace_back(m);
        } 
        else if(targetPiece->getColor() != piece->getColor()) {
            Move m;
            m.from = from;
            m.to = to;
            m.movedPiece = PieceType::KNIGHT;
            m.isCapture = true;
            m.capturedPiece = targetPiece->getPieceType();
            moves.emplace_back(m);
        }
    }
}

vector<Move> Knight::getPseudoLegalMoves(Position from, const Board& board) const {
    int r = from.row, c = from.col;
    vector<Move> moves;

    if(r-2 >= 0 && r-2 < 8) {
        Position to{r-2, c-1};
        tryAddingMove(this, from, to, board, moves);
        to.col = c+1;
        tryAddingMove(this, from, to, board, moves);
    }

    if(r-1 >= 0 && r-1 < 8) {
        Position to{r-1, c-2};
        tryAddingMove(this, from, to, board, moves);
        to.col = c+2;
        tryAddingMove(this, from, to, board, moves);
    }

    if(r+1 >= 0 && r+1 < 8) {
        Position to{r+1, c-2};
        tryAddingMove(this, from, to, board, moves);
        to.col = c+2;
        tryAddingMove(this, from, to, board, moves);
    }

    if(r+2 >= 0 && r+2 < 8) {
        Position to{r+2, c-1};
        tryAddingMove(this, from, to, board, moves);
        to.col = c+1;
        tryAddingMove(this, from, to, board, moves);
    }

    return moves;
}

