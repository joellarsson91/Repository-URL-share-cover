#include "PlayerSprite.h"
#include <SDL.h>
#include <SDL_image.h>
#include "System.h"
#include "SceneBattlefield.h"

namespace fs19 {

	PlayerSprite* PlayerSprite::getInstance(int x, int y, int w, int h, std::string path){
		return new PlayerSprite(x, y, w, h, path);
		
	
	}

	PlayerSprite::PlayerSprite(int x, int y, int w, int h, std::string path) :Sprite(x,y,w,h){

		pixelCatapult = IMG_LoadTexture(sys.get_ren(), path.c_str());
		pixelCatapultLeft = IMG_LoadTexture(sys.get_ren(),"pixelCatapultLeft.png");
		center = { x + (w / 2), y + (h / 2) };
		
	}


	PlayerSprite::~PlayerSprite(){
		SDL_DestroyTexture(pixelCatapult);
		SDL_DestroyTexture(pixelCatapultLeft);
	}



	void PlayerSprite::draw() const {

		if (isTurnedLeft) {

			SDL_RenderCopy(sys.get_ren(), pixelCatapultLeft, NULL, &getRect());
		}
		else {
			SDL_RenderCopy(sys.get_ren(), pixelCatapult, NULL, &getRect());
		}

		

	}
}
