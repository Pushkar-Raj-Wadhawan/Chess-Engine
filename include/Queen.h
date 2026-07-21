#pragma once

#include <bits/stdc++.h>
#include "Piece.h"
using namespace std;

class Queen : public Piece {
public:
    Queen(Color c) : Piece(c, PieceType::QUEEN) {}
    vector<Move> getPseudoLegalMoves(Position from, const Board& board) const override;
};