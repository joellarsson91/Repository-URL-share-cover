#ifndef LABEL_H
#define LABEL_H
#include <vector>
#include "Sprite.h"
#include <string>
#include <SDL.h>
//using namespace std; g�r man inte som en headerfil h�r uppe.
namespace fs19 {
	class Label : public Sprite
	{
	public:
		static Label* getInstance(int x, int y, int w, int h, std::string txt);
		//label m�ste ha draw fr�n component
		void draw() const;
		std::string getText() const;
		void setText(std::string newText);
		~Label();

	protected:
		//s� man inte kan skapa objekt av detta
		Label(int x, int y, int v, int h, std::string txt);

	private:
		std::string text;
		SDL_Texture* texture;
	};
}
#endif