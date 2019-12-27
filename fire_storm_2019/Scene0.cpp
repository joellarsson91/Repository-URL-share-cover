#include "Scene0.h"
#include "Button.h"
#include <string>
#include "System.h"
#include <SDL_image.h>
#include "Sprite.h"
namespace fs19 {



	Scene0::Scene0() : Scene()   {
		//populateSpriteList();



		Sprite* ngb = new NewGameButton();
		Sprite* background = new Background("background.png");

		addSprites(ngb);
		addSprites(background);

	}

	Scene0::~Scene0() {

	}

	void Scene0::populateSpriteList() {



		
	}

	class NewGameButton : public Button {
	public:
		NewGameButton() :Button(100, 100, 100, 50, "New Game") {}


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






}

