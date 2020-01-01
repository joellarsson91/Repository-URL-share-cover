#include "GameEngine.h"
#include <SDL.h>
#include "System.h"
#include <iostream>

namespace fs19 {


	void GameEngine::clearQueue() {
		eventQueue.clear();
	}

	void GameEngine::add(Sprite* s) {
		eventQueue.push_back(s);
	}

	void GameEngine::run() {
		bool quit = false;

		while (!quit){//händelse-loopen
			SDL_Event eve;//händelsekön
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT: quit = true; break;
				case SDL_MOUSEBUTTONDOWN:
					for (Sprite* s : eventQueue) {
						s->mouseDown(eve);
					}
					break;
				case SDL_MOUSEBUTTONUP:
					for (Sprite* s : eventQueue) {
						s->mouseUp(eve);
					}
					break;
				case SDL_KEYDOWN:
					for (Sprite* s : eventQueue) {
						s->keyDown(eve);
					}
					break;

				case SDL_KEYUP:
					for (Sprite* s : eventQueue) {
						s->keyUp(eve);
					}
					break;
				}
			}
			//Rita upp alla händelser men måste börja med att sudda.
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

	GameEngine ge;
	//Initializes the gameloop and adding Sprite components to the gameloop que
	
}