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
	virtual void populateSpriteList();
	std::vector<Sprite*> getSpriteList();

	

protected:
	//Konstruktor man inte ska kunna bygga objekt av
	Scene();

private:

	std::vector<Sprite*> sceneList;



};

}
#endif
