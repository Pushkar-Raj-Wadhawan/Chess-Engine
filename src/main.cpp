#include <bits/stdc++.h>
using namespace std;

#include "../include/Board.h"
#include "../include/Move.h"
#include "../include/Piece.h"
#include "../include/Knight.h"
#include "../include/Bishop.h"
#include "../include/Rook.h"

int main() {
    Board board;

    Position center = {3, 3};
    Position p1 = {3, 6};
    Position p2 = {6, 3};

    auto rook = make_unique<Rook>(Color::BLACK);
    auto bishop = make_unique<Bishop>(Color::WHITE);
    auto knight = make_unique<Knight>(Color::BLACK);

    board.placePieceAt(move(rook), center);
    board.placePieceAt(move(knight), p1);
    board.placePieceAt(move(bishop), p2);

    vector<Move> moves = board.getPieceAt(center)->getPseudoLegalMoves(center, board);

    cout << "Possible Moves: " << (int)moves.size() << "\n";
    for(auto& move: moves) {
        cout << move.to.row << ", " << move.to.col << (move.isCapture ? " [capture]\n" : "\n");
    }
}