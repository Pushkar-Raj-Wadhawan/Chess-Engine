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

    // Position center = {3, 3};
    Position p1 = {0, 0};
    Position p2 = {0, 4};
    // Position p3 = {0, 1};
    // Position p4 = {0, 7};

    // auto pawn = make_unique<Pawn>(Color::BLACK);
    auto bishop = make_unique<Bishop>(Color::WHITE);
    auto king = make_unique<King>(Color::BLACK);
    auto rook = make_unique<Rook>(Color::BLACK);
    auto rookB = make_unique<Rook>(Color::BLACK);
    // auto wPawn = make_unique<Pawn>(Color::WHITE);

    board.placePieceAt(move(rook), p1);
    // board.placePieceAt(move(rookB), p4);
    board.placePieceAt(move(king), p2);

    Move m;
    m.from = p2;
    m.to = {0, 2};
    m.movedPiece = PieceType::KING;
    m.isCastle = true;
    m.rookFrom = p1;
    m.rookTo = {0, 3};

    UndoInfo info = board.makeMove(m);
    if(board.getPieceAt({0, 2})->getPieceType() == PieceType::KING) cout << "King castled";
    if(board.getPieceAt({0, 3})->getPieceType() == PieceType::ROOK) cout << "Rook castled";

    board.undoMove(m, info);
    if(board.getPieceAt(p2)->getPieceType() == PieceType::KING) cout << "King castled undone";
    if(board.getPieceAt(p1)->getPieceType() == PieceType::ROOK) cout << "Rook castled undone";


    // board.placePieceAt(move(bishop), p3);
    // board.placePieceAt(move(pawn), p3);
    // board.placePieceAt(move(knight), p1);

    // cout << board.isInCheck(Color::WHITE);

    // vector<Move> m1 = board.getPieceAt(p2)->getPseudoLegalMoves(p2, board);
    // vector<Move> m1 = board.getLegalMoves(Color::BLACK);
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

    // cout << "Possible Moves: " << (int)m1.size() << "\n";
    // for(auto& move: m1) {
    //     cout << move.to.row << ", " << move.to.col << (move.isCapture ? " [capture]\n" : "\n");
    // }
}