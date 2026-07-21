#pragma once

enum class Color {WHITE, BLACK};
enum class PieceType {PAWN, KNIGHT, BISHOP, ROOK, KING, QUEEN};

struct Position {   
    int row, col;
    bool operator==(const Position& other) const {
        return row == other.row && col == other.col;
    }
    bool isValid() const {
        return row >= 0 && col >= 0 && row < 8 && col < 8;
    }
};

struct Move {
    Position from, to;
    PieceType movedPiece;
    bool isCapture = false;
    PieceType capturedPiece;
    // some other things as well
};