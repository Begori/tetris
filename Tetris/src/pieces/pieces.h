#pragma once

namespace core {
namespace pieces {

	class Pieces
	{
	public:
		int GetBlockType(int x, int y, int piece, int rotation);
		int GetXInitialPosition(int piece, int rotation);
		int GetYInitialPosition(int piece, int rotation);
	};

}}