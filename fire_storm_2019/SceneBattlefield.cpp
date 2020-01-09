#include "SceneBattlefield.h"
#include "GameEngine.h"
#include <SDL.h>
#include <SDL_image.h>
#include "System.h"
#include "PlayerSprite.h"
#include "Scene.h"

namespace fs19 {

	SceneBattlefield sb;

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

		Boulder(int x, int y) : Sprite(x, y, 100, 100) {
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

			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

			if (currentKeyStates[SDL_SCANCODE_W] && currentKeyStates[SDL_SCANCODE_A]) {
				setPosition(-3, -3);

			}
			else if (currentKeyStates[SDL_SCANCODE_W] && currentKeyStates[SDL_SCANCODE_D]) {
				setPosition(3, -3);

			}
			else if (currentKeyStates[SDL_SCANCODE_S] && currentKeyStates[SDL_SCANCODE_A]) {
				setPosition(-3, 3);

			}
			else if (currentKeyStates[SDL_SCANCODE_S] && currentKeyStates[SDL_SCANCODE_D]) {
				setPosition(3, 3);

			}
			else if (currentKeyStates[SDL_SCANCODE_W]) {
				setPosition(0, -3);
			}
			else if (currentKeyStates[SDL_SCANCODE_S]) {
				setPosition(0, 3);
			}
			else if (currentKeyStates[SDL_SCANCODE_A]) {
				setPosition(-3, 0);

			}
			else if (currentKeyStates[SDL_SCANCODE_D]) {
				setPosition(3, 0);

			}
		}


	};


	class Player2 : public PlayerSprite {
	public:
		Player2() : PlayerSprite(700, 300, 100, 50, "pixelCatapult.png") {}



		void keyDown(const SDL_Event& eve) {

			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

			if (currentKeyStates[SDL_SCANCODE_UP] && currentKeyStates[SDL_SCANCODE_LEFT]) {
				setPosition(-3, -3);

			}
			else if (currentKeyStates[SDL_SCANCODE_UP] && currentKeyStates[SDL_SCANCODE_RIGHT]) {
				setPosition(3, -3);

			}
			else if (currentKeyStates[SDL_SCANCODE_DOWN] && currentKeyStates[SDL_SCANCODE_LEFT]) {
				setPosition(-3, 3);

			}
			else if (currentKeyStates[SDL_SCANCODE_DOWN] && currentKeyStates[SDL_SCANCODE_RIGHT]) {
				setPosition(3, 3);

			}
			else if (currentKeyStates[SDL_SCANCODE_UP]) {
				setPosition(0, -3);
			}
			else if (currentKeyStates[SDL_SCANCODE_DOWN]) {
				setPosition(0, 3);
			}
			else if (currentKeyStates[SDL_SCANCODE_LEFT]) {
				setPosition(-3, 0);

			}
			else if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
				setPosition(3, 0);

			}

			if (eve.key.keysym.sym == SDLK_f) {
				Sprite* boulder = new Boulder(getRect().x, getRect().y);
				sb.addSprites(boulder);
				
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
