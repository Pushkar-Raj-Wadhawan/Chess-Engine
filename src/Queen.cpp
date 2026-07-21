#include "../include/Board.h"
#include "../include/Queen.h"
#include "../include/Move.h"
#include "../include/MoveUtils.h"

vector<Move> Queen::getPseudoLegalMoves(Position from, const Board& board) const {
    const vector<pair<int, int>> directions = {
        {-1,0}, {1,0}, {0,-1}, {0,1},
        {-1,-1}, {-1,1}, {1,-1}, {1,1}
    };
    return getSlidingMoves(from, board, this, directions);
}
