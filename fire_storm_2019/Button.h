#ifndef BUTTON_H
#define BUTTON_H
#include <string>
#include <SDL.h>
#include "Sprite.h"
namespace fs19{
class Button : public Sprite
{
public:
	static Button* getInstance(int x, int y, int w, int h, bool collision, std::string txt);
	void mouseDown(const SDL_Event&);
	void mouseUp(const SDL_Event&);
	void draw() const;
	void tick() {};
	virtual void perform(Button* source) {}
	~Button();
protected:
	Button(int x, int y, int w, int h, bool collision, std::string txt);


private:
	std::string text;
	SDL_Texture* texture;
	bool isDown = false;


};
}
#endif