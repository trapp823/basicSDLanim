#ifndef MANAGER_H
#define MANAGER_H

#include <SDL.h>
#include "sprite.h"
#include "generateFrames.h"

class Manager {
	public:
		Manager(float xs, float ys, float xi, float xv,
				  float yv, float dv, unsigned int dt);
		void animate(SDL_Surface* screen, Sprite& background, Sprite& trees, 
						 Sprite& flowers, Sprite& cells, Sprite& glob1,
						 Sprite& glob2, Sprite& glob3);
		bool update(Sprite& one, Sprite& two, Sprite& three, int& drawThis);
		
	private:
		float START_X;
		float START_Y;
		float INCR_X ;
		float X_VELOCITY;
		float Y_VELOCITY;
		float DISC_VELOCITY;
		unsigned int DT;
};

#endif
