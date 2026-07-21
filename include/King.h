#pragma once

#include <bits/stdc++.h>
#include "Board.h"
#include "Piece.h"

using namespace std;

class King : public Piece {
public:
    King(Color c) : Piece(c, PieceType::KING) {}
    vector<Move> getPseudoLegalMoves(Position from, const Board& board) const override;
};
