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

	int IO::InitGraph()
	{
		return 0;
	}


	void IO::DrawRectangle(int x1, int y1, int x2, int y2, enum color color)
	{

	}

	void IO::ClearScreen()
	{

	}

	void IO::UpdateScreen()
	{

	}

	int IO::PollKey()
	{
		return 0;
	}

	int IO::GetKey()
	{
		return 0;
	}

	bool IO::IsKeyDown(int key)
	{
		return false;
	}

	int IO::GetScreenHeight()
	{
		return 0;
	}

}}