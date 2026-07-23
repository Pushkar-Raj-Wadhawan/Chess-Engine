#pragma once

#include <bits/stdc++.h>
#include "Board.h"
#include "Move.h"
#include "Piece.h"

using namespace std;

// bishop, rook, queen
vector<Move> getSlidingMoves(Position from, const Board& board, const Piece* piece, const vector<pair<int, int>>& directions);

// knight, king
vector<Move> tryOffsets(Position from, const Board& board, const Piece* piece, const vector<pair<int, int>>& offsets);

unique_ptr<Piece> createPiece(PieceType type, Color color);