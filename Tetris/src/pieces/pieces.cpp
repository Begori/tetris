#include "pieces.h"

namespace core {
namespace pieces {

	static int pieces[7 * 25] = 
	{
		// Square
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 2, 1, 0,
		0, 0, 1, 1, 0,
		0, 0, 0, 0, 0,
		// I
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 1, 2, 1, 1,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		// L
		0, 0, 0, 0, 0,
		0, 0, 1, 0, 0,
		0, 0, 2, 0, 0,
		0, 0, 1, 1, 0,
		0, 0, 0, 0, 0,
		// L mirrored
		0, 0, 0, 0, 0,
		0, 0, 1, 0, 0,
		0, 0, 2, 0, 0,
		0, 1, 1, 0, 0,
		0, 0, 0, 0, 0,
		// N
		0, 0, 0, 0, 0,
		0, 0, 0, 1, 0,
		0, 0, 2, 1, 0,
		0, 0, 1, 0, 0,
		0, 0, 0, 0, 0,
		// N mirrored
		0, 0, 0, 0, 0,
		0, 0, 1, 0, 0,
		0, 0, 2, 1, 0,
		0, 0, 0, 1, 0,
		0, 0, 0, 0, 0,
		// T
		0, 0, 0, 0, 0,
		0, 0, 1, 0, 0,
		0, 0, 2, 1, 0,
		0, 0, 1, 0, 0,
		0, 0, 0, 0, 0
	};

	static char piecesInitialPosition[7][4][2] = 
	{
		// Square
		{
			{-2, -3},
			{-2, -3},
			{-2, -3},
			{-2, -3}
		},
		// I
		{
			{-2, -2},
			{-2, -3},
			{-2, -2},
			{-2, -2}
		},
		// L
		{
			{-2, -3},
			{-2, -3},
			{-2, -3},
			{-2, -2}
		},
		// L mirrored
		{
			{-2, -3},
			{-2, -2},
			{-2, -3},
			{-2, -3}
		},
		// N
		{
			{-2, -3},
			{-2, -3},
			{-2, -3},
			{-2, -2}
		},
		// N mirrored
		{
			{-2, -3},
			{-2, -3},
			{-2, -3},
			{-2, -2}
		},
		// T
		{
			{-2, -3},
			{-2, -3},
			{-2, -3},
			{-2, -2}
		}
	};

	int Pieces::GetBlockType(int x, int y, int piece, int rotation)
	{
		switch (rotation)
		{
			case 0:
			{
				return pieces[(piece * 25) + (y * 5) + x];
			}
		
			case 1:
			{
				return pieces[(piece * 25) + (20 + y) - (x * 5)];
			}
		
			case 2:
			{
				return pieces[(piece * 25) + 24 - (y * 5) - x];
			}
		
			case 3:
			{
				return pieces[(piece * 25) + 4 - y + (x * 5)];
			}
		}

	}

	int Pieces::GetXInitialPosition(int piece, int rotation)
	{
		return piecesInitialPosition[piece][rotation][0];
	}

	int Pieces::GetYInitialPosition(int piece, int rotation)
	{
		return piecesInitialPosition[piece][rotation][1];
	}

}}