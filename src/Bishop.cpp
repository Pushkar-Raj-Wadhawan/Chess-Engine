#include "../include/Bishop.h"
#include "../include/Board.h"

vector<Move> Bishop::getPseudoLegalMoves(Position from, const Board& board) const {
    int r = from.row, c = from.col;
    vector<Move> moves;

    vector<int> dr = {-1, -1, 1, 1};
    vector<int> dc = {-1, 1, -1, 1};

    for(int d = 0; d < 4; d++) {
        r += dr[d]; c += dc[d];
        while(r >= 0 && r < 8 && c >= 0 && c < 8) {    
            Position to{r, c};
            Piece* targetPiece = board.getPieceAt(to);
            if(targetPiece == nullptr) {
                Move m;
                m.from = from;
                m.to = to;
                m.movedPiece = PieceType::BISHOP;
                moves.emplace_back(m);
            }
            else if (targetPiece->getColor() != this->getColor()){
                Move m;
                m.from = from;
                m.to = to;
                m.movedPiece = PieceType::BISHOP;
                m.isCapture = true;
                m.capturedPiece = targetPiece->getPieceType();
                moves.emplace_back(m);
                break;
            }
            else {
                // same color piece
                break;
            }
            r += dr[d]; c += dc[d];
        }
        r = from.row;
        c = from.col;
    }
    return moves;
}