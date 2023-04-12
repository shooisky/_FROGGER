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

	// uruchamia gr� i implementuje g��wn� p�tl� komunikat�w
	int Run();
private:
	// wska�nik na okno
	SDL_Window* window;

	// wska�nik na renderer
	SDL_Renderer* renderer;
};

#endif // GAME_LOGIC_Hclass gameL


