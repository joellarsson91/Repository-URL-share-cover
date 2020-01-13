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
		Background(std::string s) :Sprite(0, 0, 800, 600, false) {
			texture = IMG_LoadTexture(sys.get_ren(), s.c_str());
		}
		void draw() const {
			SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());

		}
		~Background() {
			SDL_DestroyTexture(texture);
		}
		void tick() {};
	private:
		SDL_Texture* texture;


	};




	class Boulder : public Sprite {
	public:
		static Boulder* getInstance(int x, int y, bool b, std::string path) {
			return new Boulder(x, y, b, path);
		}

		Boulder(int x, int y, bool b, std::string path) : Sprite(x, y, 40, 40, true) {
			texture = IMG_LoadTexture(sys.get_ren(), "pixelBoulder.jpg");
			turnedLeft = b;
			
		}
		~Boulder() {
			SDL_DestroyTexture(texture);
		}

		void draw() const {

			SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());

		}
		//Kanske måste definieras för att gå snabbare/långsammare
		void tick() {

			//Counter för att ökas för varje gång den studsar.
			
				if (getRect().x < 0 || getRect().x >= 800) {
					ge.remove(this);
				}
				else {
					
					if (turnedLeft) {
						if (getRect().x > xtemp - 300) {

							setPosition(-5, -3);


						}
						else if (getRect().x <= xtemp - 300 && getRect().y < ytemp) {

							setPosition(-5, 3);

						}
						else {
							ge.remove(this);
						}
					}
					else {
						if (getRect().x < xtemp + 300) {

							setPosition(5, -3);


						}
						else if (getRect().x >= xtemp + 300 && getRect().y < ytemp) {

							setPosition(5, 3);

						}
						else {
							ge.remove(this);
						}
					}

				}
				
		};




	private:
		SDL_Texture* texture;
		bool turnedLeft;
		int xtemp = getRect().x;
		int ytemp = getRect().y;

	};

	class Player1 : public PlayerSprite {
	public:
		Player1() : PlayerSprite(1, 300, 50, 25, true, "pixelCatapult2.png","pixelCatapultLeft2.png") {}

		void tick() {
			if (counter>0 && counter<150) {
				counter++;
				isReady = false;
			}
			else {
				counter = 0;
				isReady = true;
			}
			
			setPosition(getXVel(), getYVel());
			xTemp = getXVel();
			yTemp = getYVel();
			
			
			calculateCollision();
			

		}
		void perform() {

			setPosition(-xTemp, -yTemp);;
			
		}



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
				setIsTurnedLeft(true);
			}
			if (currentKeyStates[SDL_SCANCODE_D]) {
				setXVel(3);
				setIsTurnedLeft(false);
			}
			if (currentKeyStates[SDL_SCANCODE_F]) {
				if (isReady) {
					Sprite* boulder = new Boulder(getRect().x, getRect().y, getIsTurnedLeft(), "pixelBoulder.jpg");
					ge.add(boulder);
					counter++;

				}
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
	private:
		//cd
		bool isReady = true;
		int counter = 0;
		int xTemp = 0, yTemp = 0;
		
	};


	class Player2 : public PlayerSprite {
	public:
		Player2() : PlayerSprite(700, 300, 50, 25, true, "pixelCatapult2.png", "pixelCatapultLeft2.png") {}

		void tick() {
			if (counter > 0 && counter < 150) {
				counter++;
				isReady = false;
			}
			else {
				counter = 0;
				isReady = true;
			}
			setPosition(getXVel(), getYVel());
			xTemp = getXVel();
			yTemp = getYVel();

			calculateCollision();
			
		}
		void perform() {
			setPosition(-xTemp, -yTemp);
		
		}

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
				setIsTurnedLeft(true);
			}
			if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
				setXVel(3);
				setIsTurnedLeft(false);
			}
			if (currentKeyStates[SDL_SCANCODE_RCTRL]) {
				if (isReady) {
					Sprite* boulder = new Boulder(getRect().x, getRect().y, getIsTurnedLeft(), "pixelBoulder.jpg");
					ge.add(boulder);
					counter++;

				}
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

	private:
		bool isReady = true;
		int counter = 0;
		int xTemp = 0, yTemp = 0;

	};





	SceneBattlefield::SceneBattlefield() {

		Sprite* background = new Background("battlefieldBackground.png");
		addSprites(background);
		Player1* player1 = new Player1();
		addSprites(player1);
		Player2* player2 = new Player2();
		player2->setIsTurnedLeft(true);
		addSprites(player2);
		


	}
}
