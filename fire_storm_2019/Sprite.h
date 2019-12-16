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
		const SDL_Rect& getRect() const { return rect; } // Each Sprite holds a rectangel where its drawn up upon
														//which coordinates
	protected:
		//Protects Sprite for being created as an object since its a templateclass
		Sprite(int x, int y, int w, int h);

	private:
		SDL_Rect rect;
		//Removes possabilities of allocate and copy Sprites
		Sprite(const Sprite&) = delete;
		const Sprite& operator=(const Sprite&) = delete;
	};
}
#endif
