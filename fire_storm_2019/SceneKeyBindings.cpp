#include "SceneKeyBindings.h"
#include <SDL.h>
#include <SDL_image.h>
#include "System.h"
#include "Scene.h"

namespace fs19 {

	class Background : public Sprite {
	public:
		//took this from SceneMenu.cpp
		//remove hardcoded size later
		Background(std::string s) :Sprite(0, 0, 800, 600) {
			texture = IMG_LoadTexture(sys.get_ren(), s.c_str());

		}
		void draw() const {
			SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
		}

		void tick() {};
	private:
		SDL_Texture* texture;
	};
	SceneKeyBindings::SceneKeyBindings() {
		Sprite* background = new Background("keyBindingMenuBackground.png");
		addSprites(background);

	}
	SceneKeyBindings::~SceneKeyBindings() {

	}

	//assigns the keys
	void SceneKeyBindings::assignKeyBindings() {};
	//might not be needed here?
	void SceneKeyBindings::populateSpriteList() {};

}
