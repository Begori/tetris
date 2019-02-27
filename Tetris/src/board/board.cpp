#include "board.h"

namespace core {
namespace board {

	Board::Board(Pieces* pieces, int screenHeight)
	{
		this->pieces = pieces;
		this->screenHeight = screenHeight;

		InitBoard();
	}

	void Board::InitBoard()
	{
		for (int i = 0; i < BOARD_WIDRH; i++)
			for (int j = 0; j < BOARD_HEIGHT; j++)
				board[i][j] = POS_FREE;
	}

}}