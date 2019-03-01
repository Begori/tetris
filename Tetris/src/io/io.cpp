#include "io.h"

namespace core {
namespace io {

	static SDL_Surface* screen;
	static Uint32 colors[COLOR_MAX] =
	{
		0x000000ff,
		0xff0000ff,
		0x00ff00ff,
		0x0000ffff,
		0x00ffffff,
		0xff00ffff,
		0xffff00ff,
		0xffffffff
	};

	IO::IO()
	{
		InitGraph();
	}

	IO::~IO()
	{
		SDL_Quit();
	}

	bool IO::InitGraph()
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			fprintf(stderr, "Could not initialize SDL. %s\n", SDL_GetError());
			return false;
		}

		const SDL_VideoInfo* videoInfo = SDL_GetVideoInfo();
		Uint8 video_bpp = 16;

		if (videoInfo->vfmt->BitsPerPixel > 8)
			video_bpp = videoInfo->vfmt->BitsPerPixel;

		if ((screen = SDL_SetVideoMode(640, 480, video_bpp, SDL_DOUBLEBUF | SDL_SWSURFACE)) == NULL)
		{
			fprintf(stderr, "Could not set video mode. %s\n", SDL_GetError());
			return false;
		}

		return true;
	}


	void IO::DrawRectangle(int x1, int y1, int x2, int y2, enum color color)
	{
		boxColor(screen, x1, y1, x2, y2, colors[color]);
	}

	void IO::ClearScreen()
	{
		boxColor(screen, 0, 0, screen->w - 1, screen->h - 1, colors[BLACK]);
	}

	void IO::UpdateScreen()
	{
		SDL_Flip(screen);
	}

	int IO::PollKey()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				return event.key.keysym.sym;
			case SDL_QUIT:
				exit(3);
			}
		}

		return -1;
	}

	int IO::GetKey()
	{
		SDL_Event event;
		while (true)
		{
			SDL_WaitEvent(&event);
			if (event.type == SDL_KEYDOWN)
				break;
			
			if (event.type == SDL_QUIT)
				exit(3);
		}

		return event.key.keysym.sym;
	}

	bool IO::IsKeyDown(int key)
	{
		SDL_PumpEvents();
		Uint8* keyTable = SDL_GetKeyState(NULL);

		return keyTable[key];
	}

	int IO::GetScreenHeight()
	{
		return screen->h;
	}

}}