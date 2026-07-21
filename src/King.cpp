#include "../include/Board.h"
#include "../include/King.h"
#include "../include/Move.h"
#include "../include/MoveUtils.h"

vector<Move> King::getPseudoLegalMoves(Position from, const Board& board) const {
    const vector<pair<int, int>> offsets = {
        {-1,0}, {1,0}, {0,-1}, {0,1},
        {-1,-1}, {-1,1}, {1,-1}, {1,1}
    };
    return tryOffsets(from, board, this, offsets);
}