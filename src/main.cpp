#include <bits/stdc++.h>
using namespace std;

#include "../include/Board.h"
#include "../include/Move.h"
#include "../include/Piece.h"
#include "../include/Knight.h"
#include "../include/Bishop.h"
#include "../include/Rook.h"
#include "../include/Queen.h"

int main() {
    Board board;

    Position center = {3, 3};
    Position p1 = {7, 3};
    Position p2 = {1, 5};
    Position p3 = {1, 3};

    auto queen = make_unique<Queen>(Color::BLACK);
    auto bishop = make_unique<Bishop>(Color::WHITE);
    auto knight = make_unique<Knight>(Color::WHITE);
    auto rook = make_unique<Rook>(Color::BLACK);

    board.placePieceAt(move(queen), center);
    board.placePieceAt(move(knight), p2);
    board.placePieceAt(move(bishop), p1);
    board.placePieceAt(move(rook), p3);

    vector<Move> moves = board.getPieceAt(center)->getPseudoLegalMoves(center, board);

    cout << "Possible Moves: " << (int)moves.size() << "\n";
    for(auto& move: moves) {
        cout << move.to.row << ", " << move.to.col << (move.isCapture ? " [capture]\n" : "\n");
    }
}