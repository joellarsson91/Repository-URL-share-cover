#ifndef ANIMATIONSPRITE_H
#define ANIMATION_H
#include "Sprite.h"
#include <string>


namespace fs19 {
	class AnimationSprite : public Sprite
	{
	public:
		static AnimationSprite* getInstance(int x, int y, int w, int h, bool collision, std::string path, int xFrames, int yFrames);
		~AnimationSprite();
		void tick(); //An incremential tick that updates the game with each tick at end of the loop
		void draw() const; //draws the components
		void mouseDown(const SDL_Event&) {}; //Whatever happens when you hold the mouse button down.
		void mouseUp(const SDL_Event&) {};
		void keyDown(const SDL_Event&) {};
		void keyUp(const SDL_Event&) {};
		void textInput(const SDL_Event&) {};
	protected:
		AnimationSprite(int x, int y, int w, int h, bool collision, std::string path, int xFrames, int yFrames);
	private:
		//SDL_Texture* texture;
		SDL_Texture* animationSheet;
		SDL_Rect frameClip;
		int xFrameCount, yFrameCount;
	};
}
#endif

