#include "AnimationSprite.h"
#include <SDL_image.h>
#include "System.h"

namespace fs19 {

	AnimationSprite::AnimationSprite(int x, int y, int w, int h, std::string path) : Sprite(x, y, w, h) {
		
		animationSheet = IMG_LoadTexture(sys.get_ren(), path.c_str());
	}


}