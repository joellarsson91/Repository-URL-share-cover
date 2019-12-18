#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include<SDL.h>
#include<vector>
#include"Sprite.h"
namespace fs19 {
	//Declares the gameloop and adding Sprite components to the gameloop que
	class GameEngine
	{
	public:
		void clearQueue();
		void add(Sprite* s);
		void run();
		~GameEngine();
	private:
		//Gameloop que
		std::vector<Sprite*> eventQueue;

	};
}
#endif // !GAMEENGINE_H


