#include "SceneMenu.h"
#include <SDL_image.h>
#include "Sprite.h"
#include <SDL.h>
#include "Button.h"
#include "System.h"
#include "GameEngine.h"
#include "Scene0.h"
namespace fs19{


	SceneMenu::~SceneMenu() {


	}

	class StartGameButton : public Button {
	public:
		StartGameButton() :Button(100, 100, 100, 50, "Start 2 Player Game"){ }

		void perform(Button* source) {

		}
	};

	class SettingsButton : public Button {
	public:
		SettingsButton() :Button(100, 200, 100, 50, "Settings") { }

		void perform(Button* source) {

		}
	};



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
		
		Sprite* background = new Background("fireStormBackground.jpg");
		addSprites(background);
		addSprites(new StartGameButton());
		addSprites(new SettingsButton());



	}

}