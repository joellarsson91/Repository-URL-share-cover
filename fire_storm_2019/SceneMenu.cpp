#include "SceneMenu.h"
#include <SDL_image.h>
#include "Sprite.h"
#include <SDL.h>
#include "Button.h"
#include "System.h"
#include "GameEngine.h"
#include "Scene0.h"
#include "Label.h"
#include "SceneBattlefield.h"

namespace fs19{


	SceneMenu::~SceneMenu() {


	}

	class PlayerLabel : public Label {
	public:

		PlayerLabel() : Label(400, 400, 200, 50, "Player 1"){}

	};


	class PlayerLabelTwo : public Label {
	public:

		PlayerLabelTwo() : Label(200, 200, 200, 50, "Player 2") {}

	};


	class StartGameButton : public Button {
	public:
	StartGameButton() :Button(300, 300, 100, 50, "START GAME!"){ }

	void perform(Button* source) {
		ge.clearQueue();
		SceneBattlefield* bf = new SceneBattlefield();
		for (Sprite* s : bf->getSpriteList()) {
			ge.add(s);
			}

		}
	};


	//class SettingsButton : public Button {
	//public:
	//	SettingsButton() :Button(100, 200, 100, 50, "Settings") { }

	//	void perform(Button* source) {

	//	}
	//};



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
		//addSprites(new SettingsButton());
		addSprites(new PlayerLabel());
		addSprites(new PlayerLabelTwo());
		
	}

}