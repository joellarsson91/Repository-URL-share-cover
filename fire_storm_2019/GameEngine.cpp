#include "GameEngine.h"
#include <SDL.h>
#include "System.h"
#include <iostream>
#include "Sprite.h"

#define FPS 60

namespace fs19 {

	// lägger till i temporär vector
	void GameEngine::add(Sprite* s) {
		added.push_back(s);
	}

	void GameEngine::remove(Sprite* s) {
		//eventQueue.erase(eventQueue.begin()+b,eventQueue.begin()+e);
		removed.push_back(s);
	}

	void GameEngine::clearQueue() {
		eventQueue.clear();
	}
	int GameEngine::size() {
		return eventQueue.size();
	}

	

	void GameEngine::run() {
		bool quit = false;

		// 32-bits heltal, hur många millisec mellan tick
		Uint32 tickInterval = 1000 / FPS;
		while (!quit){//händelse-loopen
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event eve;//händelsekön



			while (SDL_PollEvent(&eve)) {
				//User requests quit
				if (eve.type == SDL_QUIT)
				{
					quit = true;
				}
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
				case SDL_TEXTINPUT:
					for (Sprite* s : eventQueue) {
						s->textInput(eve);
					}
					break;

				case SDLK_SPACE:
					for (Sprite* s : eventQueue) {
						s->keyDown(eve);
					}
				}


			} //Poll_Event While

		
			//Tick
			for (Sprite* s : eventQueue) {
				s->tick();
			}

			//lägger till i eventQueue när man inte längre itererar i den
			for (Sprite* s : added) {
				eventQueue.push_back(s);
			}
			added.clear();

			//går igenom removed och tar bort från eventQueue
			for (Sprite* s : removed)
				for (std::vector<Sprite*>::iterator i = eventQueue.begin();
					i != eventQueue.end();)
					if (*i == s) {
						// i sätts till nästa plats i iteratorn
						i = eventQueue.erase(i);
					}
					else
						i++;
			removed.clear();
			

			//Rita upp alla händelser men måste börja med att sudda.
			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());
			for (Sprite* s : eventQueue) {
				
				s->draw();
			}
			SDL_RenderPresent(sys.get_ren());
			

			// fördröjer hela programmet, inte enskilda Sprites
			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);
			
			
		}





	}

	GameEngine::~GameEngine()
	{
		for (Sprite* s : eventQueue) {
			delete s;
		}
		for (Sprite* s : added) {
			delete s;
		}
		for (Sprite* s : removed) {
			delete s;
		}
	}

	GameEngine ge;

	//Initializes the gameloop and adding Sprite components to the gameloop que

}