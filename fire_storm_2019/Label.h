#ifndef LABEL_H
#define LABEL_H
#include <vector>
#include "Sprite.h"
#include <string>
#include <SDL.h>
//using namespace std; gör man inte som en headerfil här uppe.
namespace fs19 {
	class Label : public Sprite
	{
	public:
		static Label* getInstance(int x, int y, int w, int h, bool collision, std::string txt);
		//label måste ha draw från component
		void draw() const;
		void tick() {};
		std::string getText() const;
		void setText(std::string newText);
		~Label();

	protected:
		//så man inte kan skapa objekt av detta
		Label(int x, int y, int v, int h, bool collision, std::string txt);

	private:
		std::string text;
		SDL_Texture* texture;
	};
}
#endif