#ifndef PLAYERSPRITE_H
#define PLAYERSPRITE_H
#include <SDL.h>
#include "Sprite.h"
#include <vector>
namespace fs19{

class PlayerSprite : public Sprite
{
public:


	static PlayerSprite* getInstance(int x, int y, int w, int h);
	~PlayerSprite();
	void draw() const;
	void setIsTurnedLeft(bool b) { isTurnedLeft = b; };
	void keyUp(const SDL_Event&) {};
	virtual void keyDown(const SDL_Event&) {}

protected:
	PlayerSprite(int x, int y, int v, int h);

private:
	bool isTurnedLeft = false;

	SDL_Texture* pixelCatapult, * pixelCatapultLeft;
};
}
#endif