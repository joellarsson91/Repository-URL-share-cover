#include "SceneSettings.h"
#include "Button.h"
#include <string>
#include "System.h"
#include <SDL_image.h>
#include "Sprite.h"
#include <SDL.h>

namespace fs19 {
	//börjat planka från Scene0, kanske är helt fel?

	SceneSettings::~SceneSettings() {

	}

	void SceneSettings::populateSpriteList() {

	}

	class KeyBindingsButton : public Button {
	public:
		KeyBindingsButton() :Button(100, 100, 100, 50,false, "Keybindings") {}

		void perform(Button* source) {

		}
	};

	// reminder to maybe implement fps functionality here if fps is not auto only

	class Background : public Sprite {
	public:
		//remove hardcoded size later
		Background(std::string s) :Sprite(0, 0, 800, 600,false) {
			texture = IMG_LoadTexture(sys.get_ren(), s.c_str());
		}
		void draw() const {
			SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());

		}
		void tick() {};
	private:
		SDL_Texture* texture;

	};

	SceneSettings::SceneSettings() {

		Sprite* background = new Background("background.png");
		addSprites(background);
		addSprites(new KeyBindingsButton());
	}
}