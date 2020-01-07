#include "AnimationSprite.h"
#include <SDL_image.h>
#include "System.h"

namespace fs19 {

	AnimationSprite::AnimationSprite(int x, int y, int w, int h, std::string path, int frames) : Sprite(x, y, w, h) {
		frameCount = frames;
		animationSheet = IMG_LoadTexture(sys.get_ren(), path.c_str());
		frameClip = {0,0,w,h};
	}
	AnimationSprite* AnimationSprite::getInstance(int x, int y, int w, int h, std::string path,int frames) {
		return new AnimationSprite( x, y, w, h, path, frames);
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
			frameClip.x += getRect().x;
			frameClip.y += getRect().y;
			clips++;
			/*frameClip.w += getRect().w;
			frameClip.h += getRect().h;*/
		 }
		 
		if (clips == frameCount) {
			frameClip.x = 0;
			frameClip.y = 0;
			clips = 0;
		 }
		 
		 
		if (frame == 60) 
			frame = 0;
		 
			
	}

}