#include "TextBox.h"
#include "System.h"
#include <iostream>
namespace fs19 {
	
	
	
	TextBox::~TextBox() {
		SDL_StopTextInput();
		SDL_DestroyTexture(texture);

	}
	TextBox::TextBox(int x, int y, int w, int h, std::string temp) : Sprite(x, y, w, h) {
		inputText = temp;
		tempText = temp;
		renderText = true;
		SDL_DestroyTexture(texture);
		SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), inputText.c_str(), { 0,0,0 });
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
		SDL_FreeSurface(surf);

	}

	TextBox* TextBox::getInstance(int x, int y, int w, int h, std::string temp) {
		return new TextBox(x, y, w, h,temp);


	}
	
	
	
	void TextBox::draw() const {

			SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
		
	}

	 //draws the components
	void TextBox::mouseUp(const SDL_Event& eve) {
		SDL_Point p = { eve.button.x, eve.button.y };
		if (SDL_PointInRect(&p, &getRect())) {
			SDL_StartTextInput();
			editingActive = true;
		}
	}
	void TextBox::keyDown(const SDL_Event& eve) {
		//Handle backspace
		if (eve.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 && editingActive)
		{
			//lop off character
			inputText.pop_back();
			renderText = true;
		}
		//Handle copy
		else if (eve.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL && editingActive)
		{
			SDL_SetClipboardText(inputText.c_str());
		}
		//Handle paste
		else if (eve.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL && editingActive)
		{
			inputText = SDL_GetClipboardText();
			renderText = true;
		}
		else if (eve.key.keysym.sym == SDLK_RETURN || eve.key.keysym.sym == SDLK_KP_ENTER && editingActive) {
			editingActive = false;
			SDL_StopTextInput();
		}
		SDL_DestroyTexture(texture);
		SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), inputText.c_str(), { 0,0,0 });
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
		SDL_FreeSurface(surf);
		
	}


	void TextBox::textInput(const SDL_Event& eve) {
		if (!(SDL_GetModState() & KMOD_CTRL && (eve.text.text[0] == 'c' || eve.text.text[0] == 'C' || eve.text.text[0] == 'v' || eve.text.text[0] == 'V') ) && editingActive)
		{
			if (inputText == tempText)
				inputText.clear();
			//Append character
			inputText += eve.text.text;
			renderText = true;
			SDL_DestroyTexture(texture);
			SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), inputText.c_str(), { 0,0,0 });
			texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
			SDL_FreeSurface(surf);

			
		
		}
	}
}