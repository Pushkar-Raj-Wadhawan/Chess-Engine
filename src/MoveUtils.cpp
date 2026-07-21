#include "../include/MoveUtils.h"

vector<Move> getSlidingMoves(Position from, const Board& board, const Piece* piece, const vector<pair<int, int>>& directions) {
    int r, c;
    vector<Move> moves;
    Color pieceColor = piece->getColor();
    PieceType pieceType = piece->getPieceType();
    for(auto &[dr, dc] : directions) {
        r = from.row + dr; c = from.col + dc;
        while(r >= 0 && r < 8 && c >= 0 && c < 8) {    
            Position to{r, c};
            Piece* targetPiece = board.getPieceAt(to);
            if(targetPiece == nullptr) {
                Move m;
                m.from = from;
                m.to = to;
                m.movedPiece = pieceType;
                moves.emplace_back(m);
            }
            else if (targetPiece->getColor() != pieceColor){
                Move m;
                m.from = from;
                m.to = to;
                m.movedPiece = pieceType;
                m.isCapture = true;
                m.capturedPiece = targetPiece->getPieceType();
                moves.emplace_back(m);
                break;
            }
            else {
                // same color piece
                break;
            }
            r += dr; c += dc;
        }
    }
    return moves;
}

vector<Move> tryOffsets(Position from, const Board& board, const Piece* piece, const vector<pair<int, int>>& offsets) {
    int r, c;
    vector<Move> moves;
    PieceType pieceType = piece->getPieceType();
    Color pieceColor = piece->getColor();
    for(auto &[dr, dc] : offsets) {
        r = from.row + dr;
        c = from.col + dc;
        Position to {r, c};
        Piece* targetPiece = board.getPieceAt(to);
        if(targetPiece == nullptr) {
            Move m;
            m.from = from;
            m.to = to;
            m.movedPiece = pieceType;
            moves.emplace_back(m);
        }
        else if(targetPiece->getColor() != pieceColor) {
            Move m;
            m.from = from;
            m.to = to;
            m.movedPiece = pieceType;
            m.isCapture = true;
            m.capturedPiece = targetPiece->getPieceType();
            moves.emplace_back(m);
        }
        else continue;
    }
    return moves;
}