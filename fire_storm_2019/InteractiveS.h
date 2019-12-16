#ifndef INTERACTIVES_H
#define INTERACTIVES_H

#include "Sprite.h"
namespace fs19 {
	class InteractiveS : public Sprite
	{
	public:
		virtual ~InteractiveS();
		virtual void tick() {} //An incremential tick that updates the game with each tick at end of the loop
		virtual void draw() const = 0; //draws the components
		virtual void mouseDown(const SDL_Event&) {}; //Whatever happens when you hold the mouse button down.
		virtual void mouseUp(const SDL_Event&) {};
		virtual void keyDown(const SDL_Event&) {};
		virtual void keyUp(const SDL_Event&) {};

	protected:
		//Protects Sprite for being created as an object since its a templateclass
		InteractiveS(int x, int y, int w, int h);


	};
}
#endif
