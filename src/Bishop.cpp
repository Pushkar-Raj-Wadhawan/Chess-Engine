#include "../include/Bishop.h"
#include "../include/Board.h"
#include "../include/Move.h"
#include "../include/MoveUtils.h"

vector<Move> Bishop::getPseudoLegalMoves(Position from, const Board& board) const {
    const vector<pair<int, int>> directions = {
        {-1,-1}, {-1,1}, {1,-1}, {1,1}
    };

    return getSlidingMoves(from, board, this, directions);
}