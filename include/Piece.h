#pragma once
#include<bits/stdc++.h>
#include "Move.h"
using namespace std;

class Board;

class Piece {
    Color color;
    PieceType type;
    bool hasMoved = false;

    Piece(Color c, PieceType t) :
        color(c), type(t) {}
    virtual ~Piece() = default;

    virtual vector<Move> getPseudoLegalMoves(Position from, const Board& board) const = 0;
};