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


	static PlayerSprite* getInstance(int x, int y, int w, int h, bool collision, std::string path1, std::string path2);
	~PlayerSprite();
	void draw() const;
	void tick();
	void setIsTurnedLeft(bool b) { isTurnedLeft = b; };
	bool getIsTurnedLeft() { return isTurnedLeft; };
	void keyUp(const SDL_Event&) {};
	virtual void keyDown(const SDL_Event&) {}
	void setXVel(int i) { xVel=i; }
	void setYVel(int i) { yVel = i; }
	int getXVel() { return xVel; }
	int getYVel() { return yVel; }
	void calculateCollision();
	virtual void perform() {};

protected:
	PlayerSprite(int x, int y, int v, int h, bool collision, std::string path1,std::string path2);

private:
	bool isTurnedLeft = false;
	SDL_Texture* pixelCatapult, * pixelCatapultLeft;
	int xVel = 0, yVel = 0;
	
};
}
#endif