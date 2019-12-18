#include <SDL.h>
#include <string>
#include "GameEngine.h"
#include "Button.h"
#include "System.h"
#include <SDL_image.h>
#include <iostream>
#include "Sprite.h"

using namespace std;
using namespace fs19;

GameEngine ge;


class Background : public Sprite {
public:
	//remove hardcoded size later
	Background(string s) :Sprite(0,0,800,600) {
		texture = IMG_LoadTexture(sys.get_ren(), s.c_str());
	}
	void draw() const{
		SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());

	}
private:
	SDL_Texture* texture;


};
	class newGameButton : public Button {
	public:
		newGameButton() :Button(100, 100, 100, 50, "New Game") {}
		
		
		void perform(Button* source) {
		ge.clearQueue();

		}
	};

	int main(int argc, char** argv) {
	
		newGameButton* ngb = new newGameButton();

		Sprite* bg = new Background("background.png");
		ge.add(bg);
		ge.add(ngb);
		ge.run();

		return 0;
	};