#include "AI.h"

MoveType AI::GetNextMove(GameBoard gameBoard)
{
	Frog* frog = gameBoard.GetFrog();
	SDL_Rect* frogRect = frog->GetRect();
	list<ItemBase> cars = gameBoard.cars;

	if (CanGoUp(gameBoard)) {
		return GoUp;
	}

	list<ItemBase>::iterator it2;
	for (it2 = cars.begin(); it2 != cars.end(); ++it2) {
		SDL_Rect* frogRectPredict2 = new SDL_Rect();
		frogRectPredict2->x = frogRect->x - 20;
		frogRectPredict2->y = frogRect->y;
		frogRectPredict2->w = frogRect->w;
		frogRectPredict2->h = frogRect->h;

		if (SDL_HasIntersection(frogRectPredict2, (*it2).GetRect())) {
			return GoRight;
		}
	}

	list<ItemBase>::iterator it3;
	for (it3 = cars.begin(); it3 != cars.end(); ++it3) {
		SDL_Rect* frogRectPredict2 = new SDL_Rect();
		frogRectPredict2->x = frogRect->x + 20;
		frogRectPredict2->y = frogRect->y;
		frogRectPredict2->w = frogRect->w;
		frogRectPredict2->h = frogRect->h;

		if (SDL_HasIntersection(frogRectPredict2, (*it3).GetRect())) {
			return GoLeft;
		}
	}

	return DoNothing;
}

bool AI::CanGoUp(GameBoard gameBoard)
{
	Frog* frog = gameBoard.GetFrog();
	SDL_Rect* frogRect = frog->GetRect();
	list<ItemBase> cars = gameBoard.cars;

	list<ItemBase>::iterator it;
	for (it = cars.begin(); it != cars.end(); ++it)
	{
		SDL_Rect* frogRectPredict = new SDL_Rect();
		frogRectPredict->x = frogRect->x - 5;
		frogRectPredict->y = gameBoard.GetYLocation(frog->GetRect()->h, frog->GetCurrentRow() + 1);
		frogRectPredict->w = frogRect->w + 10;
		frogRectPredict->h = frogRect->h;

		if (SDL_HasIntersection(frogRectPredict, (*it).GetRect())) {
			return false;
		}
	}
	return true;
}
