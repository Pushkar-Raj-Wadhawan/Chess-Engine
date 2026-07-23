#include "../include/Board.h"
#include "../include/Pawn.h"
#include "../include/Move.h"

vector<Move> Pawn::getPseudoLegalMoves(Position from, const Board& board) const {
    vector<Move> moves;

    int r = from.row, c = from.col;
    Color pieceColor = this->getColor();
    int dr = (pieceColor == Color::WHITE ? -1 : 1);
    int promotionRow = (pieceColor == Color::WHITE ? 0 : 7);
    vector<PieceType> promotionChoices = {PieceType::QUEEN, PieceType::ROOK, PieceType::BISHOP, PieceType::KNIGHT};
    Position to {r+dr, c};

    if(to.isValid()) {
        Piece* targetPiece = board.getPieceAt(to);
        if(targetPiece == nullptr) {
            Move m;
            m.from = from;
            m.to = to;
            m.movedPiece = PieceType::PAWN;
            if(to.row == promotionRow) {
                m.isPromotion = true;
                for(auto& pt: promotionChoices) {
                    m.promotedTo = pt;
                    moves.emplace_back(m);
                }
            }
            else {
                moves.emplace_back(m);
                // checking for doublestep
                if(r == (pieceColor == Color::WHITE ? 6 : 1)) {
                    to.row += dr;
                    targetPiece = board.getPieceAt(to);
                    if(targetPiece == nullptr) {
                        Move m1;
                        m1.from = from;
                        m1.to = to;
                        m1.movedPiece = PieceType::PAWN;
                        moves.emplace_back(m1);
                    }
                }
            }

        }

        // checking captures && enPassant
        to.row = r + dr;
        vector<int> dc = {-1, 1};

        for(int d = 0; d < 2; d++) {
            to.col = c + dc[d];
            if(to.isValid()) {
                targetPiece = board.getPieceAt(to);
                if(targetPiece != nullptr && targetPiece->getColor() != pieceColor) {
                    Move m;
                    m.from = from;
                    m.to = to;
                    m.movedPiece = PieceType::PAWN;
                    m.isCapture = true;
                    m.capturedPiece = targetPiece->getPieceType();
                    if(to.row == promotionRow) {
                        m.isPromotion = true;
                        for(auto& pt: promotionChoices) {
                            m.promotedTo = pt;
                            moves.emplace_back(m);
                        }
                    }
                    else moves.emplace_back(m);
                }
                else if (targetPiece == nullptr && to == board.enPassantTarget) {
                    Move m;
                    m.from = from;
                    m.to = to;
                    m.movedPiece = PieceType::PAWN;
                    m.isEnPassant = true;
                    moves.emplace_back(m);
                }
            }
        }
    }
    return moves;
}