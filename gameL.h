#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <SDL.h>

class GameLogic
{
public:
	// konstruktor obiektu logiki gry
	GameLogic();

	// destruktor obiektu logiki gry
	~GameLogic();

	// uruchamia grê i implementuje g³ówn¹ pêtlê komunikatów
	int Run();
private:
	// wskaŸnik na okno
	SDL_Window* window;

	// wskaŸnik na renderer
	SDL_Renderer* renderer;
};

#endif // GAME_LOGIC_Hclass gameL


