#include "game.h"

namespace core {
namespace game {

	Game::Game(Board* board, Pieces* pieces, IO* io, int screenHeight)
	{
		this->board = board;
		this->pieces = pieces;
		this->io = io;

		this->screenHeight = screenHeight;

		InitGame();
	}

	int Game::GetRnd(int a, int b)
	{
		return rand() % (b - a + 1) + a;
	}

	void Game::InitGame()
	{
		srand((unsigned int)time(NULL));

		piece = GetRnd(0, 6);
		rotation = GetRnd(0, 3);
		x = (BOARD_WIDTH / 2) + pieces->GetXInitialPosition(piece, rotation);
		y = pieces->GetYInitialPosition(piece, rotation);

		nextPiece = GetRnd(0, 6);
		nextRotation = GetRnd(0, 3);
		nextX = BOARD_WIDTH + 5;
		nextY = 5;
	}

	void Game::CreateNewPiece()
	{
		piece = nextPiece;
		rotation = nextRotation;
		x = (BOARD_WIDTH / 2) + pieces->GetXInitialPosition(piece, rotation);
		y = pieces->GetYInitialPosition(piece, rotation);

		nextPiece = GetRnd(0, 6);
		nextRotation = GetRnd(0, 3);
	}

	void Game::DrawPiece(int x, int y, int piece, int rotation)
	{
		color color;
		int pixelsX = board->GetXPosInPixels(x);
		int pixelsY = board->GetYPosInPixels(y);

		for (int i = 0; i < PIECE_BLOCKS; i++)
		{
			for (int j = 0; j < PIECE_BLOCKS; j++)
			{
				int blockType = pieces->GetBlockType(i, j, piece, rotation);
				switch (blockType)
				{
				case 1: color = GREEN; break;
				case 2: color = BLUE; break;
				}

				if (blockType != 0)
				{
					int x1 = pixelsX + i * BLOCK_SIZE;
					int y1 = pixelsY + j * BLOCK_SIZE;
					int x2 = x1 + BLOCK_SIZE - 1;
					int y2 = y1 + BLOCK_SIZE - 1;

					io->DrawRectangle(x1, y1, x2, y2, color);
				}
			}
		}
	}

	void Game::DrawBoard()
	{
		int leftBorderPosition = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2));
		int rightBorderPosition = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2)) + 1;
		int topBorderPosition = screenHeight - (BLOCK_SIZE * BOARD_HEIGHT);
		
		io->DrawRectangle(leftBorderPosition, topBorderPosition, rightBorderPosition, screenHeight, BLACK);
		io->DrawRectangle(leftBorderPosition - BOARD_LINE_WIDTH, topBorderPosition, leftBorderPosition, screenHeight, BLUE);
		io->DrawRectangle(rightBorderPosition, topBorderPosition, rightBorderPosition + BOARD_LINE_WIDTH, screenHeight, BLUE);

		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			for (int j = 0; j < BOARD_HEIGHT; j++)
			{
				if (!board->IsFreeBlock(i, j))
				{
					int x1 = leftBorderPosition + i * BLOCK_SIZE + 1;
					int y1 = topBorderPosition + j * BLOCK_SIZE;
					int x2 = x1 + BLOCK_SIZE - 1;
					int y2 = y1 + BLOCK_SIZE - 1;
					
					io->DrawRectangle(x1, y1, x2, y2, RED);
				}
			}
		}
	}

	void Game::DrawScene()
	{
		DrawBoard();
		DrawPiece(x, y, piece, rotation);
		DrawPiece(nextX, nextY, nextPiece, nextRotation);
	}

}}