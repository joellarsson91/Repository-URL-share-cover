#ifndef SPRITE_H
#define SPRITE_H
#include<SDL.h>
namespace fs19 {
	//A general class that all components like player etc will inherit from. Header.
	class Sprite
	{
	public:
		virtual ~Sprite();
		virtual void tick() {} //An incremential tick that updates the game with each tick at end of the loop
		virtual void draw() const = 0; //draws the components
		virtual void mouseDown(const SDL_Event&) {}; //Whatever happens when you hold the mouse button down.
		virtual void mouseUp(const SDL_Event&) {};
		virtual void keyDown(const SDL_Event&) {};
		virtual void keyUp(const SDL_Event&) {};
		const SDL_Rect& getRect() const { return rect; } // Each Sprite holds a rectangel where its drawn up upon
														//which coordinates
	protected:
		Sprite(int x, int y, int w, int h);

	private:
		SDL_Rect rect;
	};
}
#endif
