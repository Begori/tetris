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
		for (int i = 0; i < BOARD_WIDTH; i++)
			for (int j = 0; j < BOARD_HEIGHT; j++)
				board[i][j] = POS_FREE;
	}

	int Board::GetXPosInPixels(int pos)
	{
		return (BOARD_POSITION - BLOCK_SIZE * (BOARD_WIDTH / 2)) + pos * BLOCK_SIZE;
	}

	int Board::GetYPosInPixels(int pos)
	{
		return (screenHeight - BOARD_HEIGHT * BLOCK_SIZE) + pos * BLOCK_SIZE;
	}

	bool Board::IsGameOver()
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			if (board[i][0] == POS_FILLED)
				return true;
		}

		return false;
	}

	void Board::DeleteLine(int y)
	{
		for (int i = y; i > 0 ; i--)
		{
			for (int j = 0; j < BOARD_WIDTH; j++)
			{
				board[j][i] = board[j][i - 1];
			}
		}
	}

	int Board::DeletePossibleLines()
	{
		int count = 0;

		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			int i = 0;
			while (i < BOARD_WIDTH)
			{
				if (board[i][j] != POS_FILLED)
					break;
				
				++i;
			}

			if (i == BOARD_WIDTH)
			{
				DeleteLine(j);
				count++;
			}
		}

		return count;
	}

	void Board::StorePiece(int x, int y, int piece, int rotation)
	{
		for (int i1 = 0, i2 = x; i1 < PIECE_BLOCKS; i1++, i2++)
		{
			for (int j1 = 0, j2 = y; j1 < PIECE_BLOCKS; j1++, j2++)
			{
				if (pieces->GetBlockType(i1, j1, piece, rotation) != 0)
				{
					board[i2][j2] = POS_FILLED;
				}
 			}
		}
	}

	bool Board::IsFreeBlock(int x, int y)
	{
		if (board[x][y] == POS_FREE)
			return true;

		return false;
	}

	bool Board::IsPossibleMovement(int x, int y, int piece, int rotation)
	{
		for (int i1 = 0, i2 = x; i1 < PIECE_BLOCKS; i1++, i2++)
		{
			for (int j1 = 0, j2 = y; j1 < PIECE_BLOCKS; j1++, j2++)
			{
				if (i2 > BOARD_WIDTH - 1 || j2 > BOARD_HEIGHT - 1|| i2 < 0)
				{
					if (pieces->GetBlockType(i1, j1, piece, rotation) != 0)
						return false;
				}

				if (j2 >= 0)
				{
					if (pieces->GetBlockType(i1, j1, piece, rotation) != 0 && !IsFreeBlock(i2, j2))
						return false;
				}
			}
		}

		return true;
	}

}}