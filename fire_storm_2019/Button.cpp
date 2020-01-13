#include "Button.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "System.h"
#include <SDL_image.h>


namespace fs19 {    
    Button::Button(int x, int y, int w, int h, bool collision, std::string txt) :Sprite(x, y, w, h,collision) {
        SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), txt.c_str(), { 0,0,0 });
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        SDL_FreeSurface(surf);
      

    }

    Button::~Button() {

        SDL_DestroyTexture(texture);
       
    }

    Button* Button::getInstance(int x, int y, int w, int h, bool collision, std::string txt) {
        return new Button(x, y, w, h,collision, txt);
    }
    void Button::mouseDown(const SDL_Event& eve) {
        //Ska man se om knappen är över komponentarean
        SDL_Point p = { eve.button.x, eve.button.y };
        if (SDL_PointInRect(&p, &getRect()))
            isDown = true;


    }
    void Button::mouseUp(const SDL_Event& eve) {
        SDL_Point p = { eve.button.x, eve.button.y };

        if (SDL_PointInRect(&p, &getRect()))
            perform(this);

        isDown = false;

    }
    void Button::draw() const {
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
    }


}