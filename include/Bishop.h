#pragma once

#include<bits/stdc++.h>
#include "Piece.h"
using namespace std;

class Bishop : public Piece {
public:
    Bishop(Color c) : Piece(c, PieceType::BISHOP) {}
    vector<Move> getPseudoLegalMoves(Position from, const Board& board) const override;
};