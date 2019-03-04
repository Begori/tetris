#pragma once
#include <SDL.h>
#include <sdl_gfxprimitives.h>

namespace core {
namespace io {
	enum color {BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX};

	class IO
	{
	public:
		IO();
		~IO();

		void DrawRectangle(int x1, int y1, int x2, int y2, enum color color);
		void PrintText(int x, int y, char* text);

		void ClearScreen();
		void UpdateScreen();

		int GetScreenHeight();
		int PollKey();
		int GetKey();
		bool InitGraph();
		bool IsKeyDown(int key);
	};

}}