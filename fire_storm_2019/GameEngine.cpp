#include "GameEngine.h"
#include <SDL.h>
#include "System.h"
#include <iostream>

namespace fs19 {


	void GameEngine::add(Sprite* s) {
		eventQueue.push_back(s);
	}

	void GameEngine::run() {
		bool quit = false;
		while (!quit){//h�ndelse-loopen
			SDL_Event eve;//h�ndelsek�n
			switch (SDL_PollEvent(&eve)) {

			case SDL_QUIT: quit = true; break;

	 
			}
			//Rita upp alla h�ndelser men m�ste b�rja med att sudda.
			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());
			for (Sprite* s : eventQueue) {
				
				s->draw();
			}
			SDL_RenderPresent(sys.get_ren());

			
		}





	}

	GameEngine::~GameEngine()
	{
	}

	//Initializes the gameloop and adding Sprite components to the gameloop que

}