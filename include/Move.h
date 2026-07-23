#pragma once

#include <bits/stdc++.h>
#include "Piece.h"

using namespace std;

enum class Color {WHITE, BLACK};
enum class PieceType {PAWN, KNIGHT, BISHOP, ROOK, KING, QUEEN};

class Piece;

struct Position {   
    int row, col;
    bool operator==(const Position& other) const {
        return row == other.row && col == other.col;
    }
    bool isValid() const {
        return row >= 0 && col >= 0 && row < 8 && col < 8;
    }
};

struct UndoInfo {
    unique_ptr<Piece> capturedPiece;
    bool movedPieceHadMoved;
    Position prevEnPassantTarget;
    unique_ptr<Piece> promotedFromPawn;
};


struct Move {
    Position from, to;
    PieceType movedPiece;

    bool isCapture = false;
    PieceType capturedPiece;

    bool isCastle = false;
    Position rookFrom, rookTo;

    bool isEnPassant = false;

    bool isPromotion = false;
    PieceType promotedTo;
};