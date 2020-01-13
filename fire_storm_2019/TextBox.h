#ifndef TEXTBOX_H
#define TEXTBOX_H
#include "Sprite.h"
#include <string>


namespace fs19 {
	class TextBox : public Sprite
	{
	public:
		static TextBox* getInstance(int x, int y, int w, int h, bool collision,std::string temp);
		~TextBox();
		void tick() {}; //An incremential tick that updates the game with each tick at end of the loop
		void draw() const ; //draws the components
		void mouseDown(const SDL_Event&) {}; //Whatever happens when you hold the mouse button down.
		void mouseUp(const SDL_Event&);
		void keyDown(const SDL_Event&) ;
		void keyUp(const SDL_Event&) {};
		void textInput(const SDL_Event&);
		std::string getInputText() { return inputText; };
	protected:
		TextBox(int x, int y, int w, int h, bool collision, std::string temp);
	private:
		std::string inputText, tempText;
		bool renderText = false;
		bool editingActive = false;
		SDL_Texture* texture;
		
	};
}
#endif 