#pragma once
#include<bits/stdc++.h>
#include "Move.h"
using namespace std;

class Board;

class Piece {
    Color color;
    PieceType type;
    bool hasMoved = false;

public:
    Piece(Color c, PieceType t) :
        color(c), type(t) {}
    virtual ~Piece() = default;
    virtual vector<Move> getPseudoLegalMoves(Position from, const Board& board) const = 0;
    Color getColor() const {
        return this->color;
    }
    PieceType getPieceType() const {
        return this->type;
    }
};