#ifndef AI_H
#define AI_H

#include "define.h"
#include "gameB.h"

class AI
{
public:
	MoveType GetNextMove(GameBoard gameBoard);
private:
	bool CanGoUp(GameBoard gameBoard);
};
#endif //AI_H
