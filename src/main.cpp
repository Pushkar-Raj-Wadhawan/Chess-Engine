#include <bits/stdc++.h>
using namespace std;

#include "../include/Board.h"
#include "../include/Move.h"
#include "../include/Knight.h"
#include "../include/Piece.h"

int main() {
    Board board;
    auto knight = make_unique<Knight>(Color::WHITE);
    Position center{3, 3};
    board.placePieceAt(move(knight), center);
    vector<Move> possibleMoves = board.getPieceAt(center)->getPseudoLegalMoves(center, board);
    
    for(const auto& move: possibleMoves) {
        cout << move.to.row << ", " << move.to.col << (move.isCapture ? " [capture]\n" : "\n");
    }
    cout << "Possible Moves: " << possibleMoves.size() << "\n";
}