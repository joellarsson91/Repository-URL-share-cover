#include <SDL.h>
#include <string>
#include "GameEngine.h"
#include "Button.h"
#include "System.h"
#include <SDL_image.h>
#include <iostream>
#include "Sprite.h"
#include "Scene0.h"
#include "SceneMenu.h"

using namespace std;
using namespace fs19;




class Background : public Sprite {
public:
	//remove hardcoded size later
	Background(string s) :Sprite(0,0,800,600) {
		texture = IMG_LoadTexture(sys.get_ren(), s.c_str());
	}
	void draw() const{
		SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());

	}
	void tick() {};
private:
	SDL_Texture* texture;


};
	class newGameButton : public Button {
	public:
		newGameButton() :Button(100, 100, 100, 50, "New Game") {}
		
		
		void perform(Button* source) {
		
		ge.clearQueue();
		//ge.nyttObject(scen1)->eventque.
		}
	};

	//Ska skapa en objekt av f�rsta scenen. Addera alla dess
	//Spriteobjekt till GameEngine.
	//Starta Game Engine med run();
	int main(int argc, char** argv) {
	


		ge.clearQueue();
		newGameButton* ngb = new newGameButton();
		Sprite* bg = new Background("background.png");

		Scene* sc0 = new Scene0();
		for (Sprite* s : sc0->getSpriteList()) {
			ge.add(s);
		}
		ge.run();
		return 0;
	};