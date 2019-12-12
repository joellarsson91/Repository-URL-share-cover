#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include<SDL.h>
#include<vector>
#include"Sprite.h"
namespace fs19 {
	class GameEngine
	{
	public:
		void add(Sprite* s);
		void run();
		~GameEngine();
	private:
		std::vector<Sprite*> spr;

	};
}
#endif // !GAMEENGINE_H


