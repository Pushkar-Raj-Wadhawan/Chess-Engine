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
    // Board board;

    // // Position center = {3, 3};
    // Position p1 = {1, 0};
    // Position p2 = {3, 1};
    // Position p3 = {3, 0};
    // // Position p4 = {0, 7};

    // auto pawn = make_unique<Pawn>(Color::BLACK);
    // // auto bishop = make_unique<Bishop>(Color::WHITE);
    // // auto king = make_unique<King>(Color::BLACK);
    // // auto rook = make_unique<Rook>(Color::BLACK);
    // // auto rookB = make_unique<Rook>(Color::BLACK);
    // auto wPawn = make_unique<Pawn>(Color::WHITE);

    // board.placePieceAt(move(pawn), p1);
    // // board.placePieceAt(move(rookB), p4);
    // board.placePieceAt(move(wPawn), p2);

    // Move m;
    // m.from = p1;
    // m.to = p3;
    // m.movedPiece = PieceType::PAWN;

    // board.makeMove(m);
    // // vector<Move> m1 = board.getPieceAt(p2)->getPseudoLegalMoves(p2, board);

    // Move enMove;
    // enMove.from = p2;
    // enMove.to = {2,0};
    // enMove.movedPiece = PieceType::PAWN;
    // enMove.isEnPassant = true;

    // UndoInfo info = board.makeMove(enMove);

    // if(board.getPieceAt({2, 0})->getPieceType() == PieceType::PAWN) cout << "En Passant Success\n";
    // if(board.getPieceAt({3, 0}) == nullptr) cout << "En Passant Success\n";

    // board.undoMove(enMove, info);
    
    // if(board.getPieceAt({2, 0}) == nullptr) cout << "En Passant Success\n";
    // if(board.getPieceAt({3, 0})->getPieceType() == PieceType::PAWN) cout << "En Passant Success\n";
    // if(board.getPieceAt({3, 1})->getPieceType() == PieceType::PAWN) cout << "En Passant Success\n";
    
    // // UndoInfo info = board.makeMove(m);
    // if(board.getPieceAt({0, 2})->getPieceType() == PieceType::KING) cout << "King castled";
    // if(board.getPieceAt({0, 3})->getPieceType() == PieceType::ROOK) cout << "Rook castled";

    // board.undoMove(m, info);
    // if(board.getPieceAt(p2)->getPieceType() == PieceType::KING) cout << "King castled undone";
    // if(board.getPieceAt(p1)->getPieceType() == PieceType::ROOK) cout << "Rook castled undone";


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
    // // }
    // Board board;
    //     Position blackPawnStart = {1, 0};
    //     Position whitePawnPos   = {3, 1};
    //     Position knightPos      = {7, 1}; // used for the "unrelated move" in between

    //     auto blackPawn = make_unique<Pawn>(Color::BLACK);
    //     auto whitePawn = make_unique<Pawn>(Color::WHITE);
    //     auto knight    = make_unique<Knight>(Color::WHITE);

    //     board.placePieceAt(move(blackPawn), blackPawnStart);
    //     board.placePieceAt(move(whitePawn), whitePawnPos);
    //     board.placePieceAt(move(knight), knightPos);
    // Move doubleStep;
    //     doubleStep.from = blackPawnStart;
    //     doubleStep.to = {3, 0};
    //     doubleStep.movedPiece = PieceType::PAWN;
    //     board.makeMove(doubleStep);

    //     cout << "[Test a] After double-step, enPassantTarget = ("
    //          << board.enPassantTarget.row << "," << board.enPassantTarget.col << ") "
    //          << "(expected (2,0))\n";

    //     // White plays a totally unrelated knight move — this should CLEAR enPassantTarget.
    //     Move unrelatedMove;
    //     unrelatedMove.from = knightPos;
    //     unrelatedMove.to = {5, 2};
    //     unrelatedMove.movedPiece = PieceType::KNIGHT;
    //     board.makeMove(unrelatedMove);

    //     cout << "[Test a] After unrelated move, enPassantTarget = ("
    //          << board.enPassantTarget.row << "," << board.enPassantTarget.col << ") "
    //          << "(expected (-1,-1))\n";

    //     // Now check white pawn's pseudo-legal moves — en passant capture should NOT appear.
    //     vector<Move> whitePawnMoves = board.getPieceAt(whitePawnPos)->getPseudoLegalMoves(whitePawnPos, board);
    //     bool foundEnPassant = false;
    //     for (auto& m : whitePawnMoves) {
    //         if (m.isEnPassant) {
    //             foundEnPassant = true;
    //             cout << m.to.row << " " << board.enPassantTarget.row << "\n";
    //         }
    
    //     }
    //     cout << "[Test a] En passant move found: " << (foundEnPassant ? "YES (BUG!)" : "NO (correct)") << "\n\n";
    

    // ---------- Test (b): undo of a normal move shouldn't corrupt enPassantTarget ----------
    {
        Board board;
        Position knightStart = {4, 4};
        auto knight = make_unique<Knight>(Color::WHITE);
        board.placePieceAt(move(knight), knightStart);

        cout << "[Test b] Before any move, enPassantTarget = ("
             << board.enPassantTarget.row << "," << board.enPassantTarget.col << ") "
             << "(expected (-1,-1))\n";

        Move normalMove;
        normalMove.from = knightStart;
        normalMove.to = {2, 3};
        normalMove.movedPiece = PieceType::KNIGHT;

        UndoInfo info = board.makeMove(normalMove);
        cout << "[Test b] After normal move, enPassantTarget = ("
             << board.enPassantTarget.row << "," << board.enPassantTarget.col << ") "
             << "(expected (-1,-1))\n";

        board.undoMove(normalMove, info);
        cout << "[Test b] After undo, enPassantTarget = ("
             << board.enPassantTarget.row << "," << board.enPassantTarget.col << ") "
             << "(expected (-1,-1), NOT corrupted)\n";
    } 

}