#include "GameEngine.h"
#include <SDL.h>
#include "System.h"
#include <iostream>
#define FPS 60

namespace fs19 {

	void GameEngine::remove(int b, int e) {
		eventQueue.erase(eventQueue.begin()+b,eventQueue.begin()+e);					
	}

	void GameEngine::clearQueue() {
		eventQueue.clear();
	}
	int GameEngine::size() {
		return eventQueue.size();
	}

	void GameEngine::add(Sprite* s) {
		eventQueue.push_back(s);
	}

	void GameEngine::run() {
		bool quit = false;
		Uint32 tickInterval = 1000 / FPS;
		while (!quit){//h�ndelse-loopen
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event eve;//h�ndelsek�n
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
			//Rita upp alla h�ndelser men m�ste b�rja med att sudda.
			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());
			for (Sprite* s : eventQueue) {
				
				s->draw();
			}
			SDL_RenderPresent(sys.get_ren());

			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);

			
		}





	}

	GameEngine::~GameEngine()
	{
	}

	GameEngine ge;

	//Initializes the gameloop and adding Sprite components to the gameloop que

}