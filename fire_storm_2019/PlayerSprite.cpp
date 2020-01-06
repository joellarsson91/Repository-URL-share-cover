#include "PlayerSprite.h"
#include <SDL.h>
#include <SDL_image.h>
#include "System.h"
#include "Sprite.h"

namespace fs19 {

	PlayerSprite* PlayerSprite::getInstance(int x, int y, int w, int h){
		return new PlayerSprite(x, y, w, h);
	
	}

	PlayerSprite::PlayerSprite(int x, int y, int w, int h) :Sprite(x,y,w,h){

		pixelCatapult = IMG_LoadTexture(sys.get_ren(), "pixelCatapult.png");
		pixelCatapultLeft = IMG_LoadTexture(sys.get_ren(), "pixelCatapultLeft.png");
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
