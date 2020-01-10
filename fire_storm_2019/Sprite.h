#ifndef SPRITE_H
#define SPRITE_H
#include<SDL.h>
namespace fs19 {
	//A general class that all components like player etc will inherit from. Header.
	class Sprite
	{
	public:
		virtual ~Sprite();
		virtual void tick() = 0; //Virtuel, måste implementeras i subclasser. An incremential tick that updates the game with each tick at end of the loop
		virtual void draw() const = 0; //draws the components
		virtual void mouseDown(const SDL_Event&) {}; //Whatever happens when you hold the mouse button down.
		virtual void mouseUp(const SDL_Event&) {};
		virtual void keyDown(const SDL_Event&) {};
		virtual void keyUp(const SDL_Event&) {};
		virtual void textInput(const SDL_Event&) {};
		bool checkCollision(SDL_Rect a, SDL_Rect b);
		const SDL_Rect& getRect() const { return rect; } // Each Sprite holds a rectangel where its drawn up upon
														//which coordinates
		void setPosition(int dx, int dy) { rect.x += dx; rect.y += dy; }
	protected:
		//Protects Sprite for being created as an object since its a templateclass
		Sprite(int x, int y, int w, int h, bool collision);

	private:
		SDL_Rect rect;
		//Removes possabilities of allocate and copy Sprites
		Sprite(const Sprite&) = delete;
		const Sprite& operator=(const Sprite&) = delete;
		bool collider;
	};
}
#endif
