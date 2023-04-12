#ifndef CAR_H
#define CAR_H

#include "base.h"


const int CAR_Y_OFFSET = 10;
#define HOTROD_TEXTURE_FILE_PATH "hotrod.png"
#define HOTROD2_TEXTURE_FILE_PATH "hotrod2.png"
#define TRACTOR_TEXTURE_FILE_PATH "tractor.png"
#define BIGRIG_TEXTURE_FILE_PATH "bigrig.png"
#define SMALLCAR_TEXTURE_FILE_PATH "car.png"

class Car : public ItemBase
{
public:
	// konstruktor
	Car(SDL_Renderer* renderer, VehicleType type, int startX, int direction, double speed);

	// destruktor
	~Car();

};

#endif // CAR_H