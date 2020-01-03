#include "System.h"
#include <SDL.h>

//objekt av klassen system, utanför funktioner, ett statiskt objekt, dess konstruktor körs före programmet startas
//dess destruktor efter programmet är klart. 
namespace fs19 {
	System::System() {
		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow("FIRE STORM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
		TTF_Init();
		font = TTF_OpenFont("c:/Windows/Fonts/arial.ttf", 36);
		SDL_StartTextInput();
	}

	System::~System() {
		TTF_CloseFont(font);
		TTF_Quit();
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_Quit();
		SDL_StopTextInput();
	}

	SDL_Renderer* System::get_ren() const {
		return ren;
	}
	TTF_Font* System::get_font() const {
		return font;
	}
	System sys;
}