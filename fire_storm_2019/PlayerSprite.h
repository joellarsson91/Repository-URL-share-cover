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

protected:
	PlayerSprite(int x, int y, int v, int h);

private:
	bool isTurnedLeft = false;

	SDL_Texture* pixelCatapult, * pixelCatapultLeft;
};
}
#endif