#ifndef __DEFINE_H__
#define __DEFINE_H__

#define GAME_TITLE "Frogger"
#define GAME_WIDTH 600
#define GAME_HEIGHT 690

// stany gry
#define GAME_STATE_MAIN_MENU 0
#define GAME_STATE_RUNNING 1
#define GAME_STATE_LOSER 2
#define GAME_STATE_WINNER 3
#define GAME_STATE_QUIT 4
#define GAME_STATE_AUTO 5

enum VehicleType
{
	HotRod = 0,
	HotRod2 = 1,
	Tractor = 2,
	BigRig = 3,
	SmallCar = 4
};

enum MoveType {
	DoNothing = 0,
	GoUp = 1,
	GoDown = 2,
	GoLeft = 3,
	GoRight = 4
};

#endif

