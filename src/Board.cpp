#include "../include/Board.h"
#include "../include/MoveUtils.h"
#include "../include/Pawn.h"
#include "../include/Knight.h"
#include "../include/Bishop.h"
#include "../include/Rook.h"
#include "../include/King.h"
#include "../include/Queen.h"

Board::Board() {}

Piece* Board::getPieceAt(Position pos) const {
    int r = pos.row, c = pos.col;
    return grid[r][c].get();
}


void Board::placePieceAt(unique_ptr<Piece> piece, Position pos) {
    int r = pos.row, c = pos.col;
    grid[r][c] = move(piece);
}

UndoInfo Board::makeMove(const Move& m) {
    UndoInfo info;
    info.prevEnPassantTarget = enPassantTarget;
    // unique ptr operations
    // checking for enPassantAvailability for next move
    if(m.movedPiece == PieceType::PAWN && abs(m.from.row-m.to.row) == 2) {
        enPassantTarget = m.from;
        enPassantTarget.row += (grid[m.from.row][m.from.col]->getColor() == Color::WHITE ? -1 : 1);
    } else {
        enPassantTarget = {-1, -1};
    }

    if(m.isEnPassant) {
        info.capturedPiece = move(grid[m.from.row][m.to.col]);
        info.movedPieceHadMoved = true;
        grid[m.to.row][m.to.col] = move(grid[m.from.row][m.from.col]);
        grid[m.to.row][m.to.col]->setHasMoved(true);
        return info;
    }

    info.capturedPiece = move(grid[m.to.row][m.to.col]);
    info.movedPieceHadMoved = grid[m.from.row][m.from.col]->getHasMoved();
    grid[m.to.row][m.to.col] = move(grid[m.from.row][m.from.col]);
    grid[m.to.row][m.to.col]->setHasMoved(true);

    if(m.isCastle) {
        grid[m.rookTo.row][m.rookTo.col] = move(grid[m.rookFrom.row][m.rookFrom.col]);
        grid[m.rookTo.row][m.rookTo.col]->setHasMoved(true);
    }
    if(m.isPromotion) {
        Color c = grid[m.to.row][m.to.col]->getColor();
        unique_ptr<Piece> promotedPiece = createPiece(m.promotedTo, c);
        info.promotedFromPawn = move(grid[m.to.row][m.to.col]);
        grid[m.to.row][m.to.col] = move(promotedPiece);
        grid[m.to.row][m.to.col]->setHasMoved(true);
    }

    
    return info;
}

void Board::undoMove(const Move& m, UndoInfo& info) {

    if(m.isEnPassant) {
        grid[m.from.row][m.to.col] = move(info.capturedPiece);
        grid[m.from.row][m.from.col] = move(grid[m.to.row][m.to.col]);
        enPassantTarget = info.prevEnPassantTarget;
        return;
    }
    if(m.isPromotion) {
        grid[m.to.row][m.to.col] = move(info.promotedFromPawn);
    }

    grid[m.from.row][m.from.col] = move(grid[m.to.row][m.to.col]);
    grid[m.to.row][m.to.col] = move(info.capturedPiece);
    grid[m.from.row][m.from.col]->setHasMoved(info.movedPieceHadMoved);
    enPassantTarget = info.prevEnPassantTarget;

    if(m.isCastle) {
        grid[m.rookFrom.row][m.rookFrom.col] = move(grid[m.rookTo.row][m.rookTo.col]);
        grid[m.rookFrom.row][m.rookFrom.col]->setHasMoved(false);
    }
}

bool Board::isSquareAttacked(Position target, Color attacker) const {
    for(int r = 0; r < 8; r++) {
        for(int c = 0; c < 8; c++) {
            if(grid[r][c] == nullptr || grid[r][c]->getColor() != attacker) continue;
            Position from{r, c};
            if(grid[r][c]->getPieceType() == PieceType::KING) {
                static const vector<pair<int,int>> kingOffsets = {
                    {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}
                };
                for (auto& [dr, dc] : kingOffsets) {
                    Position to{r+dr, c+dc};
                    if (to == target) return true;
                }
                continue;
            }
            if(grid[r][c]->getPieceType() == PieceType::PAWN) {
                int dr = (attacker == Color::WHITE ? -1 : 1);
                Position d1{r+dr, c-1}, d2{r+dr, c+1};
                if (d1 == target || d2 == target) return true;
                continue;
            }
            vector<Move> moves = grid[r][c]->getPseudoLegalMoves(from, *this);
            for(auto& m: moves) {
                if(m.to == target) return true;
            }
        }
    }
    return false;
}

bool Board::isInCheck(Color kingColor) {
    // find c king's position
    Position kingPos {-1, -1};
    for(int r = 0; r < 8; r++) {
        for(int c = 0; c < 8; c++) {
            if(grid[r][c] != nullptr && grid[r][c]->getPieceType() == PieceType::KING && grid[r][c]->getColor() == kingColor) {
                kingPos.row = r;
                kingPos.col = c;
                break;
            }
        }
        if(kingPos.row != -1) break;
    }
    if(kingPos == Position{-1, -1}) return false;
    return isSquareAttacked(kingPos, (kingColor == Color::WHITE ? Color::BLACK : Color::WHITE));
}

vector<Move> Board::getLegalMoves(Color color) {
    vector<Move> legalMoves;
    for(int r = 0; r < 8; r++) {
        for(int c = 0; c < 8; c++) {
            if(grid[r][c] == nullptr || grid[r][c]->getColor() != color) continue;
            Position from {r, c};
            vector<Move> pseudoMoves = grid[r][c]->getPseudoLegalMoves(from, *this);
            for(auto& m : pseudoMoves) {
                UndoInfo info = makeMove(m);
                if(!isInCheck(color)) legalMoves.emplace_back(m);
                undoMove(m, info);
            }
        }
    }
    return legalMoves;
}

void Board::setupStartingPosition() {
    // pawns
    for(int c = 0; c < 8; c++) {
        placePieceAt(make_unique<Pawn>(Color::BLACK), {1, c});
        placePieceAt(make_unique<Pawn>(Color::WHITE), {6, c});
    }

    // king
    placePieceAt(make_unique<King>(Color::BLACK), {0, 4});
    placePieceAt(make_unique<King>(Color::WHITE), {7, 4});

    // queen
    placePieceAt(make_unique<Queen>(Color::BLACK), {0, 3});
    placePieceAt(make_unique<Queen>(Color::WHITE), {7, 3});

    // rooks
    placePieceAt(make_unique<Rook>(Color::BLACK), {0, 0});
    placePieceAt(make_unique<Rook>(Color::BLACK), {0, 7});
    placePieceAt(make_unique<Rook>(Color::WHITE), {7, 7});
    placePieceAt(make_unique<Rook>(Color::WHITE), {7, 0});

    // bishops
    placePieceAt(make_unique<Bishop>(Color::BLACK), {0, 2});
    placePieceAt(make_unique<Bishop>(Color::BLACK), {0, 5});
    placePieceAt(make_unique<Bishop>(Color::WHITE), {7, 2});
    placePieceAt(make_unique<Bishop>(Color::WHITE), {7, 5});

    // knights
    placePieceAt(make_unique<Knight>(Color::BLACK), {0, 1});
    placePieceAt(make_unique<Knight>(Color::BLACK), {0, 6});
    placePieceAt(make_unique<Knight>(Color::WHITE), {7, 1});
    placePieceAt(make_unique<Knight>(Color::WHITE), {7, 6});
}

long Board::perft(int depth, Color color) {
    if (depth == 0) return 1;
    long nodes = 0;
    vector<Move> legalMoves = getLegalMoves(color);
    Color nextColor = (color == Color::WHITE ? Color::BLACK : Color::WHITE);
    for (auto& m : legalMoves) {
        UndoInfo info = makeMove(m);
        nodes += perft(depth - 1, nextColor);
        undoMove(m, info);
    }
    return nodes;
}