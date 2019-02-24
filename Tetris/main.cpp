#include <Windows.h>
#include <iostream>

#include <SDL.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << ("%s", SDL_GetError()) << std::endl;
		return 1;
	}

	SDL_Quit();

	return 0;
}