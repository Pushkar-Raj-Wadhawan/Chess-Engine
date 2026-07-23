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
     for (int d = 1; d <= 5; d++) {
          Board b;
          b.setupStartingPosition();
          auto start = chrono::high_resolution_clock::now();
          long nodes = b.perft(d, Color::WHITE);
          auto end = chrono::high_resolution_clock::now();
          double seconds = chrono::duration<double>(end - start).count();
          cout << "perft(" << d << ") = " << nodes << " in " << seconds << "s\n";
     }
}