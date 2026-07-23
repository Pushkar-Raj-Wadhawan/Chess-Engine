#pragma once

#include <bits/stdc++.h>
#include "Piece.h"
using namespace std;

class Board {
private:
    array<array<unique_ptr<Piece>, 8>, 8> grid; // board on heap, pieces will be dynamic    

public:
    Board();
    Piece* getPieceAt(Position pos) const;
    Position enPassantTarget{-1, -1};

    void placePieceAt(unique_ptr<Piece>, Position pos);
    UndoInfo makeMove(const Move& m);
    void undoMove(const Move& m, UndoInfo& info);
    bool isSquareAttacked (Position target, Color attacker) const;
    bool isInCheck(Color c); // will check if c color king in check or not
    vector<Move> getLegalMoves(Color color);
    void setupStartingPosition();

    long perft(int depth, Color color);
};