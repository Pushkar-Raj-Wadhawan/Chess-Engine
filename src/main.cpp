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
    Position p1 = {1, 5};
    Position p2 = {4, 2};
    Position p3 = {5, 3};
    Position p4 = {1, 1};

    auto pawn = make_unique<Pawn>(Color::BLACK);
    auto bishop = make_unique<Bishop>(Color::BLACK);
    auto king = make_unique<King>(Color::WHITE);
    auto rook = make_unique<Rook>(Color::WHITE);
    auto rookB = make_unique<Rook>(Color::BLACK);
    // auto wPawn = make_unique<Pawn>(Color::WHITE);

    board.placePieceAt(move(rook), center);
    board.placePieceAt(move(rookB), p4);
    board.placePieceAt(move(king), p2);
    board.placePieceAt(move(bishop), p1);
    board.placePieceAt(move(pawn), p3);
    // board.placePieceAt(move(knight), p1);

    // cout << board.isInCheck(Color::WHITE);

    // vector<Move> m1 = board.getPieceAt(center)->getPseudoLegalMoves(center, board);
    vector<Move> m2 = board.getLegalMoves(Color::WHITE);
    // cout << (m2.size() == m1.size() ? "1" : "0");
 
    // Move m;
    // m.from = center;
    // m.to = p1;
    // m.movedPiece = PieceType::KNIGHT;
    // m.isCapture = true;
    // m.capturedPiece = PieceType::BISHOP;

    // UndoInfo info = board.makeMove(m);
    // if(board.getPieceAt(m.to)->getPieceType() == PieceType::KNIGHT) cout << "Knight is here\n";

    // if(board.getPieceAt(m.from) == nullptr) cout << "Nothing here\n";
    // cout << board.getPieceAt(m.to)->getHasMoved();

    // board.undoMove(m, info);
    
    // if(board.getPieceAt(m.to)->getPieceType() == PieceType::BISHOP) cout << "Bishop is here\n";
    // if(board.getPieceAt(m.from)->getPieceType() == PieceType::KNIGHT) cout << "Knight is here\n";

    // if(board.getPieceAt(m.from) == nullptr) cout << "Nothing here\n";
    // cout << board.getPieceAt(m.to)->getHasMoved();

    // vector<Move> moves = board.getPieceAt(p4)->getPseudoLegalMoves(p4, board);

    cout << "Possible Moves: " << (int)m2.size() << "\n";
    for(auto& move: m2) {
        cout << move.to.row << ", " << move.to.col << (move.isCapture ? " [capture]\n" : "\n");
    }
}