#pragma once

#include<bits/stdc++.h>
#include "Piece.h"
using namespace std;

class Rook : public Piece {
public:
    Rook(Color c) : Piece(c, PieceType::ROOK) {}
    vector<Move> getPseudoLegalMoves(Position from, const Board& board) const override;
};