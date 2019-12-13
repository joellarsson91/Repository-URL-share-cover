#include "System.h"
#include <SDL.h>
namespace fs19 {
	System::System() {
		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow("FIRE STORM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
		TTF_Init();
		font = TTF_OpenFont("c:/Windows/Fonts/arial.ttf", 36);
	}

	System::~System() {
		TTF_CloseFont(font);
		TTF_Quit();
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_Quit();
	}
	//objekt av klassen system, utanf�r funktioner, ett statiskt objekt, dess konstruktor k�rs f�re programmet startas
	//dess destruktor efter programmet �r klart. 

	SDL_Renderer* System::get_ren() const {
		return ren;
	}
	TTF_Font* System::get_font() const {
		return font;
	}
	System sys;
}