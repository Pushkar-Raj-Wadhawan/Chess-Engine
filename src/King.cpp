#include "../include/Board.h"
#include "../include/King.h"
#include "../include/Move.h"
#include "../include/MoveUtils.h"

vector<Move> King::getPseudoLegalMoves(Position from, const Board& board) const {
    const vector<pair<int, int>> offsets = {
        {-1,0}, {1,0}, {0,-1}, {0,1},
        {-1,-1}, {-1,1}, {1,-1}, {1,1}
    };
    vector<Move> pseudoMoves = tryOffsets(from, board, this, offsets);

    Piece* king = board.getPieceAt(from);
    Color attacker = (king->getColor() == Color::WHITE ? Color::BLACK : Color::WHITE);
    if(king->getHasMoved() == false && !board.isSquareAttacked(from, attacker)) {
        // king side castling
        Position rookPos{-1, 7};
        int r = rookPos.row = king->getColor() == Color::WHITE ? 7 : 0;
        Piece* rook = board.getPieceAt(rookPos);
        if(rook != nullptr && rook->getPieceType() == PieceType::ROOK &&
            rook->getColor() == king->getColor() && rook->getHasMoved() == false) {
            Position p1 {r, 5};
            Position p2 {r, 6};
            if(board.getPieceAt(p1) == nullptr && !board.isSquareAttacked(p1, attacker) && 
                board.getPieceAt(p2) == nullptr && !board.isSquareAttacked(p2, attacker)) {
                    Move m;
                    m.to = p2;
                    m.from = from;
                    m.movedPiece = PieceType::KING;
                    m.isCastle = true;
                    m.rookFrom = rookPos;
                    m.rookTo = p1;
                    pseudoMoves.emplace_back(m);
                }
            }

        // queen side castling
        rookPos = {-1, 0};
        r = rookPos.row = king->getColor() == Color::WHITE ? 7 : 0;
        rook = board.getPieceAt(rookPos);
        if(rook != nullptr && rook->getPieceType() == PieceType::ROOK &&
            rook->getColor() == king->getColor() && rook->getHasMoved() == false) {
            Position p1 {r, 1};
            Position p2 {r, 2};
            Position p3 {r, 3};
            if(board.getPieceAt(p1) == nullptr && 
                board.getPieceAt(p2) == nullptr && !board.isSquareAttacked(p2, attacker) && 
                board.getPieceAt(p3) == nullptr && !board.isSquareAttacked(p3, attacker)) {
                    Move m;
                    m.to = p2;
                    m.from = from;
                    m.movedPiece = PieceType::KING;
                    m.isCastle = true;
                    m.rookFrom = rookPos;
                    m.rookTo = p3;
                    pseudoMoves.emplace_back(m);
                }
        }
    }

    return pseudoMoves;
    
}