#ifndef SCENE_H
#define SCENE_H
#include<SDL.h>
#include <iostream>
#include "Sprite.h"
#include <vector>


namespace fs19{
class Scene{

public:
	
	~Scene();
	//Populate Scenelist with sprites
	//virtual void populateSpriteList();
	const std::vector<Sprite*> getSpriteList() const { return spriteList; }
	void addSprites(Sprite* s);

protected:
	//Konstruktor man inte ska kunna bygga objekt av
	Scene();
	std::vector<Sprite*> spriteList;
private:

	

};

}
#endif
