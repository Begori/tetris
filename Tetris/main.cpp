#include <Windows.h>
#include "src\game\game.h"

using namespace core::game;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	IO io;
	int screenHeight = io.GetScreenHeight();

	Pieces pieces;
	Board board(&pieces, screenHeight);
	Game game(&board, &pieces, &io, screenHeight);

	int score = 0;
	unsigned long time1 = SDL_GetTicks();

	while (!io.IsKeyDown(SDLK_ESCAPE))
	{
		io.ClearScreen();
		game.DrawScene(score);
		io.UpdateScreen();

		int key = io.PollKey();
		switch (key)
		{
			case SDLK_RIGHT:
			{
				if (board.IsPossibleMovement(game.x + 1, game.y, game.piece, game.rotation))
					game.x++;

				break;
			}
			case SDLK_LEFT:
			{
				if (board.IsPossibleMovement(game.x - 1, game.y, game.piece, game.rotation))
					game.x--;

				break;
			}

			case SDLK_DOWN:
			{
				if (board.IsPossibleMovement(game.x, game.y + 1, game.piece, game.rotation))
					game.y++;

				break;
			}

			case SDLK_x:
			{
				while (board.IsPossibleMovement(game.x, game.y, game.piece, game.rotation))
					game.y++;

				board.StorePiece(game.x, game.y - 1, game.piece, game.rotation);
				score += (board.DeletePossibleLines() * 25);

				if (board.IsGameOver())
				{
					io.GetKey();
					exit(0);
				}

				game.CreateNewPiece();

				break;
			}

			case SDLK_z:
			{
				if (board.IsPossibleMovement(game.x, game.y, game.piece, (game.rotation + 1) % 4))
					game.rotation = (game.rotation + 1) % 4;

				break;
			}
		}

		unsigned long time2 = SDL_GetTicks();

		if (time2 - time1 > WAIT_TIME)
		{
			if (board.IsPossibleMovement(game.x, game.y + 1, game.piece, game.rotation))
			{
				game.y++;
			}
			else
			{
				board.StorePiece(game.x, game.y, game.piece, game.rotation);
				score += (board.DeletePossibleLines() * 25);

				if (board.IsGameOver())
				{
					io.GetKey();
					exit(0);
				}

				game.CreateNewPiece();
			}

			time1 = SDL_GetTicks();
		}
	}

	return 0;
}