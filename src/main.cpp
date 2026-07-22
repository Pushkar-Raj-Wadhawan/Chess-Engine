#include <bits/stdc++.h>
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

    Position center = {3, 3};
    Position p1 = {1, 4};
    // Position p2 = {3, 1};
    // Position p3 = {2, 2};
    // Position p4 = {1, 1};

    auto knight = make_unique<Knight>(Color::BLACK);
    auto bishop = make_unique<Bishop>(Color::WHITE);
    // auto king = make_unique<King>(Color::WHITE);
    // auto rook = make_unique<Rook>(Color::BLACK);
    // auto pawn = make_unique<Pawn>(Color::BLACK);
    // auto wPawn = make_unique<Pawn>(Color::WHITE);

    board.placePieceAt(move(knight), center);
    // board.placePieceAt(move(queen), p1);
    board.placePieceAt(move(bishop), p1);
    // board.placePieceAt(move(rook), p2);
    // board.placePieceAt(move(pawn), p4);
    // board.placePieceAt(move(wPawn), p3);

    Move m;
    m.from = center;
    m.to = p1;
    m.movedPiece = PieceType::KNIGHT;
    m.isCapture = true;
    m.capturedPiece = PieceType::BISHOP;

    UndoInfo info = board.makeMove(m);
    if(board.getPieceAt(m.to)->getPieceType() == PieceType::KNIGHT) cout << "Knight is here\n";

    if(board.getPieceAt(m.from) == nullptr) cout << "Nothing here\n";
    cout << board.getPieceAt(m.to)->getHasMoved();

    board.undoMove(m, info);
    
    if(board.getPieceAt(m.to)->getPieceType() == PieceType::BISHOP) cout << "Bishop is here\n";
    if(board.getPieceAt(m.from)->getPieceType() == PieceType::KNIGHT) cout << "Knight is here\n";

    if(board.getPieceAt(m.from) == nullptr) cout << "Nothing here\n";
    cout << board.getPieceAt(m.to)->getHasMoved();

    // vector<Move> moves = board.getPieceAt(p4)->getPseudoLegalMoves(p4, board);

    // cout << "Possible Moves: " << (int)moves.size() << "\n";
    // for(auto& move: moves) {
    //     cout << move.to.row << ", " << move.to.col << (move.isCapture ? " [capture]\n" : "\n");
    // }
}