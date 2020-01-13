#include "PlayerSprite.h"
#include <SDL.h>
#include <SDL_image.h>
#include "System.h"
#include "SceneBattlefield.h"
#include "GameEngine.h"
#include <iostream>

namespace fs19 {

	PlayerSprite* PlayerSprite::getInstance(int x, int y, int w, int h, bool collision, std::string path){
		return new PlayerSprite(x, y, w, h,collision, path);
		
	
	}

	PlayerSprite::PlayerSprite(int x, int y, int w, int h, bool collision, std::string path) :Sprite(x,y,w,h,collision){

		pixelCatapult = IMG_LoadTexture(sys.get_ren(), "pixelCatapult2.png");
		pixelCatapultLeft = IMG_LoadTexture(sys.get_ren(),"pixelCatapultLeft2.png");
		
	}


	PlayerSprite::~PlayerSprite(){
		SDL_DestroyTexture(pixelCatapult);
		SDL_DestroyTexture(pixelCatapultLeft);
	}

	void PlayerSprite::calculateCollision() {
		bool collision=true;
		setCollider(false);
		for (Sprite* s : ge.getEventQueue()) {
			if (s->getCollider())
				collision = checkCollision(getRect(), s->getRect());
		}
		if(collision)
			perform();
		
		setCollider(true);
	}
	void PlayerSprite::tick() {	}

	

	void PlayerSprite::draw() const {

		if (isTurnedLeft) {

			SDL_RenderCopy(sys.get_ren(), pixelCatapultLeft, NULL, &getRect());
		}
		else {
			SDL_RenderCopy(sys.get_ren(), pixelCatapult, NULL, &getRect());
		}

		

	}
}
