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

	class Boulder : public Sprite {
	public:
		static Boulder* getInstance(int x, int y, std::string path) {
			return new Boulder(x, y, path);
		}

		Boulder(int x, int y, std::string path) : Sprite(x, y, 40, 40,true) {
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
		Player1() : PlayerSprite(0, 300, 100, 50,true, "pixelCatapult.png") {}




		void keyDown(const SDL_Event& eve) {

			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);


			if (currentKeyStates[SDL_SCANCODE_W]) {
				setYVel(-3);
			}
			if (currentKeyStates[SDL_SCANCODE_S]) {
				setYVel(3);
			}
			if (currentKeyStates[SDL_SCANCODE_A]) {
				setXVel(-3);

			}
			if (currentKeyStates[SDL_SCANCODE_D]) {
				setXVel(3);

			}
			if (currentKeyStates[SDL_SCANCODE_F]) {
				Sprite* boulder = new Boulder(getRect().x, getRect().y, "pixelBoulder.jpg");
				ge.add(boulder);

			}
		}
		void keyUp(const SDL_Event& eve) {
			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

			if (!currentKeyStates[SDL_SCANCODE_W]) {

				if (getYVel() < 0)
					setYVel(0);
			}
			if (!currentKeyStates[SDL_SCANCODE_S]) {
				if (getYVel() > 0)
					setYVel(0);
			}
			if (!currentKeyStates[SDL_SCANCODE_A]) {
				if (getXVel() < 0)
					setXVel(0);

			}
			if (!currentKeyStates[SDL_SCANCODE_D]) {
				if (getXVel() > 0)
					setXVel(0);

			}
		}


	};


	class Player2 : public PlayerSprite {
	public:
		Player2() : PlayerSprite(700, 300, 100, 50,true, "pixelCatapult.png") {}



		void keyDown(const SDL_Event& eve) {

			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

			if (currentKeyStates[SDL_SCANCODE_UP]) {
				setYVel(-3);
			}
			if (currentKeyStates[SDL_SCANCODE_DOWN]) {
				setYVel(3);
			}
			if (currentKeyStates[SDL_SCANCODE_LEFT]) {
				setXVel(-3);
			}
			if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
				setXVel(3);
			}
		}
		void keyUp(const SDL_Event& eve) {
			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

			if (!currentKeyStates[SDL_SCANCODE_UP]) {

				if (getYVel() < 0)
					setYVel(0);
			}
			if (!currentKeyStates[SDL_SCANCODE_DOWN]) {
				if (getYVel() > 0)
					setYVel(0);
			}
			if (!currentKeyStates[SDL_SCANCODE_LEFT]) {
				if (getXVel() < 0)
					setXVel(0);

			}
			if (!currentKeyStates[SDL_SCANCODE_RIGHT]) {
				if (getXVel() > 0)
					setXVel(0);

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
