#include "SceneBattlefield.h"
#include "GameEngine.h"
#include <SDL.h>
#include <SDL_image.h>
#include "System.h"
#include "PlayerSprite.h"
#include "Scene.h"

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
		static Boulder* getInstance(int x, int y, std::string path) {
			return new Boulder(x, y, path);
		}

		Boulder(int x, int y, std::string path) : Sprite(x, y, 40, 40) {
			texture = IMG_LoadTexture(sys.get_ren(), "pixelBoulder.jpg");
		}

		void draw() const {

			SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());

		}
		//Kanske måste definieras för att gå snabbare/långsammare
		void tick() {
			int xtemp = getRect().x;
			int ytemp = getRect().y;

			//Counter för att ökas för varje gång den studsar.

			if (getRect().x <= 0 || getRect().x >= 800) {
				ge.remove(this);
			} else {
			
				if (getRect().x < xtemp + 10) {

					setPosition(2, -1);

				}
				else if (getRect().x >= xtemp + 10 && getRect().y < ytemp) {

					setPosition(2, 1);
				} 
				
			
			}
		};

		~Boulder() {
		};

	private:
		SDL_Texture* texture;
		int counter = 0;
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
			
			if (currentKeyStates[SDL_SCANCODE_F]) {
				Sprite* boulder = new Boulder(getRect().x, getRect().y, "pixelBoulder.jpg");
				ge.add(boulder);

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

			if (currentKeyStates[SDL_SCANCODE_RCTRL]) {
				Sprite* boulder = new Boulder(getRect().x, getRect().y, "pixelBoulder.jpg");
				ge.add(boulder);

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
