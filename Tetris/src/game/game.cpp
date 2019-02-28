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
		x = (BOARD_WIDRH / 2) + pieces->GetXInitialPosition(piece, rotation);
		y = pieces->GetYInitialPosition(piece, rotation);

		nextPiece = GetRnd(0, 6);
		nextRotation = GetRnd(0, 3);
		nextX = BOARD_WIDRH + 5;
		nextY = 5;
	}

	void Game::CreateNewPiece()
	{
		piece = nextPiece;
		rotation = nextRotation;
		x = (BOARD_WIDRH / 2) + pieces->GetXInitialPosition(piece, rotation);
		y = pieces->GetYInitialPosition(piece, rotation);

		nextPiece = GetRnd(0, 6);
		nextRotation = GetRnd(0, 3);
	}

	void Game::DrawPiece(int x, int y, int piece, int rotation)
	{

	}

	void Game::DrawBoard()
	{

	}

	void Game::DrawScene()
	{
		DrawBoard();
		DrawPiece(x, y, piece, rotation);
		DrawPiece(nextX, nextY, nextPiece, nextRotation);
	}

}}