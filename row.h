#ifndef ROW_H
#define ROW_H

#include <SDL_image.h>

class Row
{
public:
	Row(int y, int height);
	~Row();

	SDL_Rect roadRect;
};


#endif ROW_H
