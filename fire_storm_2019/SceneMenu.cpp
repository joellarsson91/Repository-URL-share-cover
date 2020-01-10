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
#include "TextBox.h"
namespace fs19{


	SceneMenu::~SceneMenu() {


	}

	class PlayerLabel : public Label {
	public:

		PlayerLabel() : Label(400, 400, 200, 50,false, "Player 1"){}

	};


	class PlayerLabelTwo : public Label {
	public:

		PlayerLabelTwo() : Label(200, 200, 200, 50,false, "Player 2") {}

	};


	class StartGameButton : public Button {
	public:
	StartGameButton() :Button(300, 300, 100, 50,false, "START GAME!"){ }

	void perform(Button* source) {
		ge.clearQueue();
		SceneBattlefield* bf = new SceneBattlefield();
		for (Sprite* s : bf->getSpriteList()) {
			ge.add(s);
			}

		}
	};





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
	class TextEditor : public TextBox {
	public:
		TextEditor() :TextBox(200, 100, 100, 100,false) {}
	};


	SceneMenu::SceneMenu() {
		
		Sprite* background = new Background("fireStormBackground.jpg");
		addSprites(background);
		addSprites(new StartGameButton());
		//addSprites(new SettingsButton());
		addSprites(new PlayerLabel());
		addSprites(new PlayerLabelTwo());
		addSprites(new TextEditor());
		
	}

}