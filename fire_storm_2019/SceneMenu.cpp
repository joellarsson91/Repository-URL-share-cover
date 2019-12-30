#include "SceneMenu.h"
#include <SDL.h>
#include <SDL_image.h>
#include "System.h"

namespace fs19 {

	class Background : public Sprite {
	public:
		//remove hardcoded size later
		Background(std::string s) :Sprite(0, 0, 800, 600) {
			texture = IMG_LoadTexture(sys.get_ren(), s.c_str());
		}
		void draw() const {
			SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());

		}
	private:
		SDL_Texture* texture;


	};


	SceneMenu::SceneMenu() {
		Sprite* background = new Background("background.png");
		addSprites(background);

	}
	SceneMenu::~SceneMenu() {

	}


	void SceneMenu::populateSpriteList() {};

}