#include "Scene0.h"
#include "Button.h"
#include <string>
#include "System.h"
#include <SDL_image.h>
#include "Sprite.h"
#include <SDL.h>
#include "SceneMenu.h"
#include "GameEngine.h"
#include "TextBox.h"
#include "AnimationSprite.h"
namespace fs19 {


	Scene0::~Scene0() {

	}


	class NewGameButton : public Button {
	public:
		NewGameButton() :Button(100, 100, 100, 50,false, "New Game") {}


		void perform(Button* source) {
			ge.clearQueue();
			SceneMenu* scM = new SceneMenu();
			for (Sprite* s : scM->getSpriteList()) {
				ge.add(s);
			}
		}

		void tick() {};
	};
	class Background : public Sprite {
	public:
		//remove hardcoded size later
		Background(std::string s) :Sprite(0, 0, 800, 600, false) {
			texture = IMG_LoadTexture(sys.get_ren(), s.c_str());
		}
		void draw() const {
			SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());

		}
		void tick() {};
		~Background() {
			SDL_DestroyTexture(texture);
		}
	private:
		SDL_Texture* texture;


	};

	class walkAnimation : public AnimationSprite {
	public:
		walkAnimation(): AnimationSprite(400,400,95,161,false,"Walkanimation.png",7,3){}

	};
	
	
	
	class runAnimation : public AnimationSprite {
	public:
		runAnimation() : AnimationSprite(300, 200, 128, 128,false, "fireAnim.png", 8, 8) {}
	};

	class FireAnimation : public AnimationSprite {
	public:
		FireAnimation() : AnimationSprite(500, 200, 128, 128, false, "fireAnim.png", 8, 8) {}
	};


	//Moved constructor down so the encapsulated classes
	//could be reached.

	Scene0::Scene0() {
		

		

		Sprite* background = new Background("background.png");
		addSprites(background);
		addSprites(new NewGameButton());
		//addSprites(new walkAnimation());
		addSprites(new runAnimation());
		

	}
}

