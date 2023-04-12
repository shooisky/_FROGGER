#include "row.h"
#include "define.h"

Row::Row(int y, int height)
{
	roadRect.x = 0;
	roadRect.y = y;
	roadRect.w = GAME_WIDTH;
	roadRect.h = height;
}

Row::~Row()
{

}
