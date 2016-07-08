#pragma once
#include <cinttypes>

struct CutValues
{
	uint16_t posX;
	uint16_t posY;
	uint16_t sizeX;
	uint16_t sizeY;

	CutValues(uint16_t x = 0, uint16_t y = 0, uint16_t sX = 0, uint16_t sY = 0)
	{
		posX = x;
		posY = y;
		sizeX = sX;
		sizeY = sX;
	}
};