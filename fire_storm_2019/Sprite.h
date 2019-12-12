#ifndef SPRITE_H
#define SPRITE_H
#include<SDL.h>
namespace fs19 {
	class Sprite
	{
	public:
		virtual ~Sprite();
		virtual void tick() {}
		virtual void draw() const = 0;
		virtual void mouseDown(const SDL_Event&) {};
		virtual void mouseUp(const SDL_Event&) {};
		virtual void keyDown(const SDL_Event&) {};
		virtual void keyUp(const SDL_Event&) {};
		const SDL_Rect& getRect() const { return rect; }
	protected:
		Sprite(int x, int y, int w, int h);

	private:
		SDL_Rect rect;
	};
}
#endif
