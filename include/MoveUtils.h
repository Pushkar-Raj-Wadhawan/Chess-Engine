#pragma once

#include <bits/stdc++.h>
#include "Board.h"
#include "Move.h"
#include "Piece.h"

using namespace std;

vector<Move> getSlidingMoves(Position from, const Board& board, const Piece* piece, const vector<pair<int, int>>& directions);