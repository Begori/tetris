#pragma once
#include "..\pieces\pieces.h"

#define PIECE_BLOCKS 5
#define BOARD_POSITION 320
#define BOARD_WIDRH 10
#define BOARD_HEIGHT 20
#define BOARD_LINE_WIDTH 6
#define BLOCK_SIZE 16

using namespace core::pieces;

namespace core {
namespace board {

	class Board
	{
	public:
		Board(Pieces* pieces, int screenHeight);

		int GetXPosInPixels(int pos);
		int GetYPosInPixels(int pos);

		void StorePiece(int x, int y, int piece, int rotation);
		void DeletePossibleLines();

		bool IsFreeBlock(int x, int y);
		bool IsPossibleMovement(int x, int y, int piece, int rotation);
		bool IsGameOver();
	private:
		enum {POS_FREE, POS_FILLED};
		int board[BOARD_WIDRH][BOARD_HEIGHT];
		Pieces* pieces;
		int screenHeight;

		void InitBoard();
		void DeleteLine(int y);
	};

}}