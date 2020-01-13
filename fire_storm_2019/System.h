#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include<SDL_ttf.h>
namespace fs19 {
	//Declare the SDL System parts like renderer and windows
	class System
	{
	public:
		System();
		~System();
		SDL_Renderer* get_ren() const;
		TTF_Font* get_font() const;
		SDL_Window* get_win() const;


	private:
		SDL_Window* win;
		SDL_Renderer* ren;
		TTF_Font* font;



	};
	
	extern System sys;
}
#endif
