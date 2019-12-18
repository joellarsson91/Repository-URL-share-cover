#include "Button.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "System.h"
#include <SDL_image.h>


namespace fs19 {
    Button::Button(int x, int y, int w, int h, std::string txt) :InteractiveS(x, y, w, h) {
        SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), txt.c_str(), { 0,0,0 });
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        SDL_FreeSurface(surf);
        upIcon = IMG_LoadTexture(sys.get_ren(), "c:/users/joel_/OneDrive/Bilder/BorderPng.png");//Hitta ny bakgrund
        //för button down and up
        downIcon = IMG_LoadTexture(sys.get_ren(), "c:/users/joel_/OneDrive/Bilder/BorderPngRed.png");

    }

    Button::~Button() {
        //3 textures som måste städas bort
        SDL_DestroyTexture(texture);
        SDL_DestroyTexture(upIcon);
        SDL_DestroyTexture(downIcon);
    }

    Button* Button::getInstance(int x, int y, int w, int h, std::string txt) {
        return new Button(x, y, w, h, txt);
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
        //måste veta om knappen är nedtryckt eller ej.
        if (isDown)
            SDL_RenderCopy(sys.get_ren(), downIcon, NULL, &getRect());
        else
            SDL_RenderCopy(sys.get_ren(), upIcon, NULL, &getRect());

        SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
    }


}