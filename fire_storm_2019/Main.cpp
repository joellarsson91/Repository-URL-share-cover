#include <SDL.h>
#include <string>
#include "GameEngine.h"
#include "Button.h"
#include "System.h"
#include <SDL_image.h>
#include <iostream>
#include "Sprite.h"
#include "Scene0.h"
#include "SceneMenu.h"

using namespace std;
using namespace fs19;




	//Ska skapa en objekt av första scenen. Addera alla dess
	//Spriteobjekt till GameEngine.
	//Starta Game Engine med run();
	int main(int argc, char** argv) {
	


		ge.clearQueue();
	

		Scene* sc0 = new Scene0();
		for (Sprite* s : sc0->getSpriteList()) {
			ge.add(s);
		}
		ge.run();
		return 0;
	};