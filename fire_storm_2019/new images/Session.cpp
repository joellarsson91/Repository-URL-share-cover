#include "Session.h"
#include <SDL.h>
#include "Component.h"
#include "System.h"
using namespace std;

void Session::add(Component* comp) {
	comps.push_back(comp);
}

void Session::run() {
	bool quit = false;
	while (!quit) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT: quit = true; break;
			case SDL_MOUSEBUTTONDOWN:
				for (Component* c : comps)
					c->mouseDown(event.button.x, event.button.y);
				break;
			case SDL_MOUSEBUTTONUP:
				for (Component* c : comps)
					c->mouseUp(event.button.x, event.button.y);
				break;
			} //switch
		} //inre while

		SDL_SetRenderDrawColor(sys.ren, 255, 255, 255, 255);
		SDL_RenderClear(sys.ren);
		for (Component* c : comps)
			c->draw();
		SDL_RenderPresent(sys.ren);

	} // yttre while
}
