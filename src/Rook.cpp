#include "Board.h"
#include "Rook.h"
#include "MoveUtils.h"

vector<Move> Rook::getPseudoLegalMoves(Position from, const Board& board) const {
    const vector<pair<int, int>> directions = {
        {-1,0}, {1,0}, {0,-1}, {0,1}
    };

    return getSlidingMoves(from, board, this, directions);
}