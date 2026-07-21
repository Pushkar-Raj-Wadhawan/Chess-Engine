#include "../include/Board.h"
#include "../include/Rook.h"
#include "../include/MoveUtils.h"

vector<Move> Rook::getPseudoLegalMoves(Position from, const Board& board) const {
    const vector<pair<int, int>> directions = {
        {-1,0}, {1,0}, {0,-1}, {0,1}
    };

    return getSlidingMoves(from, board, this, directions);
}