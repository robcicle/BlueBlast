#pragma once

//dimensions in 2D that are whole numbers
struct Dim2Di{ int x, y; };

//dimensions in 2D that are floating point numbers
struct Dim2Df{ float x, y; };

namespace GC
{
	//game play related constants to tweak
	const Dim2Di SCREEN_RES{ 1200,800 };

	const char ESCAPE_KEY{ 27 };
}