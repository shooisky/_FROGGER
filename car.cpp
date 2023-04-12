#include "car.h"
#include<SDL_image.h>
#include <stdlib.h>


// konstruktor
Car::Car(SDL_Renderer* renderer, VehicleType type, int startX, int direction, double speed)
	: ItemBase(renderer, startX, direction, speed)
{
	switch (type)
	{
	case HotRod:
		texture = LoadTexture(renderer, HOTROD_TEXTURE_FILE_PATH);
		rect.w = 46;
		rect.h = 47;
		break;
	case HotRod2:
		texture = LoadTexture(renderer, HOTROD2_TEXTURE_FILE_PATH);
		rect.w = 44;
		rect.h = 46;
		break;
	case Tractor:
		texture = LoadTexture(renderer, TRACTOR_TEXTURE_FILE_PATH);
		rect.w = 40;
		rect.h = 40;
		break;
	case BigRig:
		texture = LoadTexture(renderer, BIGRIG_TEXTURE_FILE_PATH);
		rect.w = 74;
		rect.h = 36;
		break;
	case SmallCar:
		texture = LoadTexture(renderer, SMALLCAR_TEXTURE_FILE_PATH);
		rect.w = 41;
		rect.h = 36;
		break;
	}

	// reset ustawieñ
	Reset();
}

// destruktor
Car::~Car()
{
}


