#pragma once

#include <bits/stdc++.h>
#include "Board.h"
#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(Color c) : Piece(c, PieceType::PAWN) {}
    vector<Move> getPseudoLegalMoves(Position from, const Board& board) const override;
};