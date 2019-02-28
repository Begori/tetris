#pragma once

#include "../board/board.h"
#include "../pieces/pieces.h"
#include "../io/io.h"
#include <time.h>

#define WAIT_TIME 700

using namespace core::pieces;
using namespace core::board;
using namespace core::io;

namespace core {
namespace game {
	
	class Game
	{
	public:
		Game(Board* board, Pieces* pieces, IO* io, int screenHeight);

		int x, y;
		int piece, rotation;

		void DrawScene();
		void CreateNewPiece();

	private:
		int screenHeight;
		int nextX, nextY;
		int nextPiece, nextRotation;


		Board* board;
		IO* io;
		Pieces* pieces;

		int GetRnd(int a, int b);
		void InitGame();
		void DrawBoard();
		void DrawPiece(int x, int y, int piece, int rotation);
	};

}}