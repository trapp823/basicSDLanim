#include "sprite.h"

Sprite::Sprite(const std::string& file, float xCoor,float yCoor, bool colorKey) :
	mySprite(getImage(file,colorKey)), x(xCoor), y(yCoor) { }
	
Sprite::Sprite(const Sprite& copySprite) :
	mySprite(copySprite.getImage()), x(copySprite.getX()), y(copySprite.getY()) { }
	
Sprite& Sprite::operator=(const Sprite& s) {
	if (this == & s) return *this;
	mySprite = s.getImage();
	x = s.getX();
	y = s.getY();
	return *this;  
}

SDL_Surface* Sprite::getImage(const std::string& filename, bool setColorKey) {
  SDL_Surface *temp = SDL_LoadBMP(filename.c_str());
  if (temp == NULL) {
    throw std::string("Unable to load bitmap.")+SDL_GetError();
  }
  if ( setColorKey ) {
    Uint32 colorkey = SDL_MapRGB(temp->format, 255, 0, 255);
    SDL_SetColorKey(temp, SDL_SRCCOLORKEY|SDL_RLEACCEL, colorkey);
  }
  SDL_Surface* image = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  return image;
}

void Sprite::draw(SDL_Surface* screen) {
  Uint16 w = mySprite->w;
  Uint16 h = mySprite->h;
  Sint16 xCoord = static_cast<Sint16>(x);
  Sint16 yCoord = static_cast<Sint16>(y);
  SDL_Rect src = { 0, 0, w, h };
  SDL_Rect dest = {xCoord, yCoord, 0, 0 };
  SDL_BlitSurface(mySprite, &src, screen, &dest);
}
