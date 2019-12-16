#ifndef STATICS_H
#define STATICS_H

#include "Sprite.h"
namespace fs19{
class StaticS : public Sprite
{
public:
	virtual ~StaticS();
	virtual void tick() {} //An incremential tick that updates the game with each tick at end of the loop
	virtual void draw() const = 0; //draws the components

protected:
	//Protects Sprite for being created as an object since its a templateclass
	StaticS(int x, int y, int w, int h);


};
}
#endif
