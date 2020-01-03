#include "TextBox.h"
namespace fs19 {
	
	
	
	TextBox::~TextBox() {

	}
	TextBox::TextBox(int x, int y, int w, int h): Sprite(x, y, w, h){


	}

	TextBox* TextBox::getInstance(int x, int y, int w, int h) {
		return new TextBox(x, y, w, h);
	}


	void TextBox::tick() {} //An incremential tick that updates the game with each tick at end of the loop
	void TextBox::draw() const {
		
	} //draws the components
	void TextBox::mouseDown(const SDL_Event&) {} //Whatever happens when you hold the mouse button down.
	void TextBox::mouseUp(const SDL_Event&) {}
	void TextBox::keyDown(const SDL_Event& eve) {
		//Handle backspace
		if (eve.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0)
		{
			//lop off character
			inputText.pop_back();
			renderText = true;
		}
		//Handle copy
		else if (eve.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
		{
			SDL_SetClipboardText(inputText.c_str());
		}
		//Handle paste
		else if (eve.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
		{
			inputText = SDL_GetClipboardText();
			renderText = true;
		}
	}
	void TextBox::keyUp(const SDL_Event&) {}

	void TextBox::textInput(const SDL_Event& eve) {
		if (!(SDL_GetModState() & KMOD_CTRL && (eve.text.text[0] == 'c' || eve.text.text[0] == 'C' || eve.text.text[0] == 'v' || eve.text.text[0] == 'V')))
		{
			//Append character
			inputText += eve.text.text;
			renderText = true;
		}
	}
}