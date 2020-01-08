#include "AnimationSprite.h"
#include <SDL_image.h>
#include "System.h"
#include <iostream>

namespace fs19 {

	AnimationSprite::AnimationSprite(int x, int y, int w, int h, std::string path, int xFrames, int yFrames) : Sprite(x, y, w, h) {
		xFrameCount = xFrames;
		yFrameCount = yFrames;
		animationSheet = IMG_LoadTexture(sys.get_ren(), path.c_str());
		frameClip = {0,0,w,h};
	}
	AnimationSprite* AnimationSprite::getInstance(int x, int y, int w, int h, std::string path,int xFrames, int yFrames) {
		return new AnimationSprite( x, y, w, h, path, xFrames, yFrames);
	}
	AnimationSprite::~AnimationSprite() {
		SDL_DestroyTexture(animationSheet);
	}
	void AnimationSprite::draw() const {
		SDL_RenderCopy(sys.get_ren(), animationSheet, &frameClip, &getRect());
	}
	void AnimationSprite::tick() {
		static int frame = 0;
		frame++;
		static int clips = 0;
		if (frame % 5 == 0) {
			frameClip.x += getRect().w;
			if (clips%xFrameCount == 0) {
				frameClip.y += getRect().h;	
				frameClip.x = 0;
			}
			std::cout << clips;
			std::cout << " ";
			clips++;
		}
		 



		if (clips == xFrameCount*yFrameCount) {
			frameClip.y = 0;
			clips = 0;
		 }
		 
		 
		if (frame == 60) 
			frame = 0;
		 
			
	}

}