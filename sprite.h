#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <string>

class Sprite {
	public:
		Sprite(const Sprite& copySprite);
		Sprite(const std::string& file, float xCoor, float yCoor, bool colorKey);
		~Sprite() { SDL_FreeSurface(mySprite); }
		
		SDL_Surface* getImage(const std::string& filename, bool setColorKey);
		SDL_Surface* getImage() const { return mySprite; }
		void draw(SDL_Surface* screen);
		
		float getX() const { return x; }
		float getY() const { return y; }
		void setX(float xCoor) { x = xCoor; }
		void setY(float yCoor) { y = yCoor; }
		
		Sprite& operator=(const Sprite&);
	private:
		SDL_Surface* mySprite;
		float x, y;
};

#endif
