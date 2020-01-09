#include "SceneBattlefield.h"
#include "GameEngine.h"
#include <SDL.h>
#include <SDL_image.h>
#include "System.h"
#include "PlayerSprite.h"


namespace fs19 {

	SceneBattlefield::~SceneBattlefield() {


	}



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

	class Boulder : public Sprite {
	public:
		static Boulder* getInstance(int x, int y) {
			return new Boulder(x, y);
		}

		Boulder(int x, int y) : Sprite(x, y, 40, 40) {
			texture = IMG_LoadTexture(sys.get_ren(), "pixelBoulder.jpg");
		}

		void draw() const {
			SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());

		}
		void tick() {
			//Kanske måste definieras för att gå snabbare/långsammare
		};

		~Boulder() {
		};

	private:
		SDL_Texture* texture;

	};

	class Player1 : public PlayerSprite {
	public:
		Player1() : PlayerSprite(0, 300, 100, 50, "pixelCatapult.png") {}




		void keyDown(const SDL_Event& eve) {
			if (eve.key.keysym.sym == SDLK_w) {
				setPosition(0, -3);
			}
			if (eve.key.keysym.sym == SDLK_s) {
				setPosition(0, +3);
			}
			if (eve.key.keysym.sym == SDLK_a) {
				setPosition(-3, 0);

			}
			//scancodes SDLK_RIGHT
			if (eve.key.keysym.sym == SDLK_d) {
				setPosition(+3, 0);

			}
		}


	};


	class Player2 : public PlayerSprite {
	public:
		Player2() : PlayerSprite(700, 300, 100, 50, "pixelCatapult.png") {}



		void keyDown(const SDL_Event& eve) {
			if (eve.key.keysym.sym == SDLK_UP) {
				setPosition(0, -3);
			}
			if (eve.key.keysym.sym == SDLK_DOWN) {
				setPosition(0, +3);
			}
			if (eve.key.keysym.sym == SDLK_LEFT) {
				setPosition(-3, 0);

			}
			if (eve.key.keysym.sym == SDLK_RIGHT) {
				setPosition(+3, 0);

			}

			if (eve.key.keysym.sym == SDLK_SPACE) {
				Sprite* boulder = new Boulder(getRect().x, getRect().y);
			}
		}

	};





	SceneBattlefield::SceneBattlefield() {

		Sprite* background = new Background("battlefieldBackground.png");
		addSprites(background);
		addSprites(new Player1());
		Player2* player2 = new Player2();
		player2->setIsTurnedLeft(true);
		addSprites(player2);


	}
}
