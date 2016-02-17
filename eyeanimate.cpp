#include <iostream>
#include "manager.h"

const unsigned int WIDTH = 1000;
const unsigned int HEIGHT = 750;

const float START_X = 1.0;
const float START_Y = 0.0;
const float INCR_X = 0.3;
const float X_VELOCITY = 450.0;
const float Y_VELOCITY = 450.0;
const float DISC_VELOCITY = 100.0;
const unsigned int DT = 17u;

void init() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    throw( std::string("Unable to initialize SDL: ")+ SDL_GetError());
  }
  atexit(SDL_Quit);
}

int main() {
	try {
		init();
		SDL_Surface *screen = SDL_SetVideoMode(WIDTH, HEIGHT, 0, SDL_DOUBLEBUF);
		if (screen == NULL) {
			throw std::string("Unable to set video mode: ")+SDL_GetError();
		}
		
		Sprite background("images/falsemirror.bmp", 0.0, 0.0, false);
		Sprite trees("images/ringotrees.bmp", 1.0, 0.0, true);
		Sprite flowers("images/ringoflowers.bmp", 1.0, 0.0, true);
		Sprite cells("images/lastring.bmp", 1.0, 0.0, true);
		Sprite glob1("images/oil.bmp", 430.0, 315.0, true);
		Sprite glob2("images/oil.bmp", 430.0, 315.0, true);
		Sprite glob3("images/oil.bmp", 430.0, 315.0, true);	
		
		Manager manager(START_X, START_Y, INCR_X, X_VELOCITY, Y_VELOCITY, DISC_VELOCITY, DT);
		manager.animate(screen, background, trees, flowers, cells, glob1, glob2, glob3);
		
		SDL_FreeSurface(screen);
	 }
	 catch(const std::string& msg) { std::cout << msg << std::endl;  }
	 catch(...) { std::cout << "oops" << std::endl;  }
}
