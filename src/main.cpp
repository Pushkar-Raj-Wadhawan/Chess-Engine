#include <bits/stdc++.h>
using namespace std;

#include "../include/Board.h"
#include "../include/Move.h"
#include "../include/Piece.h"
#include "../include/Knight.h"
#include "../include/Bishop.h"

int main() {
    Board board;

    Position center{3, 3};
    Position p1{5, 5};
    Position p2{1, 1};
    auto bishop = make_unique<Bishop>(Color::BLACK);
    auto knight = make_unique<Knight>(Color::WHITE);
    auto knight2 = make_unique<Knight>(Color::BLACK);
    board.placePieceAt(move(bishop), center);
    board.placePieceAt(move(knight), p1);
    board.placePieceAt(move(knight2), p2);
    vector<Move> possibleMoves = board.getPieceAt(center)->getPseudoLegalMoves(center, board);
    cout << "Possible Moves: " << possibleMoves.size() << "\n";
    
    for(const auto& move: possibleMoves) {
        cout << move.to.row << ", " << move.to.col << (move.isCapture ? " [capture]\n" : "\n");
    }
}