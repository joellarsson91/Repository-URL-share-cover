#include "SceneMenu.h"
#include <SDL_image.h>
#include "Sprite.h"
#include <SDL.h>
#include "Button.h"
#include "System.h"
#include "GameEngine.h"
#include "Label.h"
#include "SceneBattlefield.h"
#include "TextBox.h"
namespace fs19{


	SceneMenu::~SceneMenu() {


	}

	class PlayerLabel : public Label {
	public:

		PlayerLabel() : Label(150, 250, 200, 50, "Player 1 name"){}

	};


	class PlayerLabelTwo : public Label {
	public:

		PlayerLabelTwo() : Label(500, 250, 200, 50, "Player 2 name") {}

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
		void tick() {};
	private:
		SDL_Texture* texture;


	};
	class TextEditor1 : public TextBox {
	public:
		TextEditor1() :TextBox(150, 300, 200, 75,"player 1") {}
		void tick() {

		}
	};
	
	class TextEditor2 : public TextBox {
	public:
		TextEditor2() :TextBox(500, 300, 200, 75, "player 2") {}
		void tick() {

		}
	};



	class StartGameButton : public Button {
	public:
		StartGameButton() :Button(375, 500, 100, 50, "START GAME!") { }

		void perform(Button* source) {
			
				ge.clearQueue();
				SceneBattlefield* bf = new SceneBattlefield();
				for (Sprite* s : bf->getSpriteList()) {
					ge.add(s);
				}
			

		}
	};

	SceneMenu::SceneMenu() {
		
		Sprite* background = new Background("battlefieldBackground.jpg");
		addSprites(background);
		addSprites(new StartGameButton());
		//addSprites(new SettingsButton());
		addSprites(new PlayerLabel());
		addSprites(new PlayerLabelTwo());
		addSprites(new TextEditor1());
		addSprites(new TextEditor2());

	}

}