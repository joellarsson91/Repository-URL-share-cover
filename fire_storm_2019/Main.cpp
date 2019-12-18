#include <SDL.h>
#include <string>
#include "GameEngine.h"
#include "Button.h"

using namespace fs19;
using namespace std;

	class newGameButton : public Button {
	public:
		newGameButton() :Button(100, 100, 100, 50, "New Game") {}
		void perform(Button* source) {

		}
	};

	int main(int argc, char** argv) {
		GameEngine ge;
		newGameButton* ngb = new newGameButton();
		ge.add(ngb);
		ge.run();

		return 0;
	


};