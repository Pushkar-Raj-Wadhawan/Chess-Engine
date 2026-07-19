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
    void placePieceAt(unique_ptr<Piece>, Position pos);
};