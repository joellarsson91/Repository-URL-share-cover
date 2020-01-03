#ifndef SCENEKEYBINDINGS_H
#define SCENEKEYBINDINGS_H
#include "Scene.h"
#include <iostream>
#include <string>

namespace fs19 {

class SceneKeyBindings : public Scene
{
	SceneKeyBindings();

	~SceneKeyBindings();

	//assigns the keys
	void assignKeyBindings();

	//method that links keys on the keyboard to user input controls in the game, e.g. right arrow to aim right, left arrow to aim left, space for shoot

	//might not be necessary here
	void populateSpriteList();
};
}
#endif