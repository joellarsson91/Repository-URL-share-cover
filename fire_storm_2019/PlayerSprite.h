#ifndef PLAYERSPRITE_H
#define PLAYERSPRITE_H
#include <SDL.h>
#include "Sprite.h"
#include <vector>
#include <string>
namespace fs19{

class PlayerSprite : public Sprite
{
public:


	static PlayerSprite* getInstance(int x, int y, int w, int h, std::string path);
	~PlayerSprite();
	void draw() const;
	void tick() {};
	void setIsTurnedLeft(bool b) { isTurnedLeft = b; };
	void keyUp(const SDL_Event&) {};
	virtual void keyDown(const SDL_Event&) {}


protected:
	PlayerSprite(int x, int y, int v, int h, std::string path);

private:
	bool isTurnedLeft = false;
	SDL_Texture* pixelCatapult, * pixelCatapultLeft;
};
}
#endif