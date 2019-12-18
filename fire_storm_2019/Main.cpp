#include <SDL.h>
#include <string>
#include "GameEngine.h"
#include "Button.h"
#include "StaticS.h"
#include "System.h"
#include <SDL_image.h>
#include <iostream>

using namespace std;
using namespace fs19;

class Background : public StaticS {

public:
	//remove hardcoded size later
	Background(string s) :StaticS(0,0,800,600) {
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
			

		}
	};

	int main(int argc, char** argv) {
		GameEngine ge;
		newGameButton* ngb = new newGameButton();

		StaticS* bg = new Background("background.png");
		ge.add(bg);
		ge.run();

		return 0;
	};