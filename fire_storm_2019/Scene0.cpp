#include "Scene0.h"
#include "Button.h"
namespace fs19 {


	Scene0::Scene0()   {
		populateSpriteList();



	}

	Scene0::~Scene0() {

	}

	void Scene0::populateSpriteList() {

		//getSpriteList().push_back(new newGameButton*());
		
	}

	class newGameButton : public Button {
	public:
		newGameButton() :Button(100, 100, 100, 50, "New Game") {}


		void perform(Button* source) {

		}
	};






}

