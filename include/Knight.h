#pragma once

#include <bits/stdc++.h>
#include "Piece.h"
using namespace std;

class Knight : public Piece {
public:
    Knight(Color c) : Piece(c, PieceType::KNIGHT) {}
    vector<Move> getPseudoLegalMoves(Position from, const Board& board) const override;
};