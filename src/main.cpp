#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#include "../include/Board.h"
#include "../include/Move.h"
#include "../include/Piece.h"
#include "../include/Knight.h"
#include "../include/Bishop.h"
#include "../include/Rook.h"
#include "../include/Queen.h"
#include "../include/King.h"
#include "../include/Pawn.h"

int main() {
     Board board;
     board.setupStartingPosition();
     cout << "Starting...\n";
     long nodes = board.perft(1, Color::WHITE);
     cout << "perft(1) = " << nodes << " (expected 20)\n";
     cout << "hi";
}