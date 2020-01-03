#ifndef PLAYERSPRITE_H
#define PLAYERSPRITE_H
#include "Sprite.h"
#include <SDL.h>
namespace fs19{

class PlayerSprite : public Sprite
{
public:
	static PlayerSprite getInstance(int x, int y, int w, int h);
	void draw() const;
	~PlayerSprite();
	


protected:
	PlayerSprite(int x, int y, int v, int h);

private:

	bool isTurnedRight;
	SDL_Texture* texture;

};
}
#endif