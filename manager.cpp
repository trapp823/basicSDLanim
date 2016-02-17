#include "manager.h"

int drawCycle = 0;

Manager::Manager(float xs, float ys, float xi, float xv, float yv, float dv, unsigned int dt) :
	START_X(xs), START_Y(ys), INCR_X(xi), X_VELOCITY(xv), Y_VELOCITY(yv), DISC_VELOCITY(dv),
	DT(dt)
	{ }
	
void Manager::animate(SDL_Surface* screen, Sprite& background, Sprite& trees, 
							 Sprite& flowers, Sprite& cells, Sprite& glob1,
							 Sprite& glob2, Sprite& glob3) {
	int drawWhat = 0;
	SDL_Event event;
	bool makeVideo = false;
	bool done = false;
	bool freshFrame = false; // ***
	GenerateFrames genFrames(screen);
	while ( !done) {
	  while ( SDL_PollEvent(&event) ) {
	    if (event.type == SDL_QUIT) done = true;
	    if (event.type == SDL_KEYDOWN) {
	      if (event.key.keysym.sym == SDLK_ESCAPE) done = true;
	      if (event.key.keysym.sym == SDLK_F4) {
	        makeVideo = true;
	      }
	    }
	  }
	  if ( drawCycle < 3 ) {
	    freshFrame = update(glob1, glob2, glob3, drawWhat);
	  }
	  else {
	    makeVideo = false;
	  }
	
	  if(freshFrame){
	    freshFrame=false;
	    if ( makeVideo ) {
	      genFrames.makeFrame();
	    }
	  }
	  
	  background.draw(screen);
	  if ( drawWhat > 25 )
	  	 trees.draw(screen);
	  if ( drawWhat > 50 )
	  	 flowers.draw(screen);
	  if ( drawWhat > 75 ) {
	  	 cells.draw(screen);
	  	 glob1.draw(screen);
	  	 glob2.draw(screen);
	  	 glob3.draw(screen);	
	  }
	  if ( drawWhat > 100 )
	  	 flowers.draw(screen);
	  if ( drawWhat > 125 ) {
	  	 glob1.setX(430.0);
		 glob1.setY(315.0);
		 glob2.setX(430.0);
		 glob2.setY(315.0);
		 glob3.setX(430.0);
		 glob3.setY(315.0);
		 background.draw(screen);
		 trees.draw(screen);
	  }
	  SDL_Flip(screen);
	}
	
}

bool Manager::update(Sprite& one, Sprite& two, Sprite& three, int& drawThis) {
  float y1 = one.getY();
  float x2 = two.getX();
  float y2 = two.getY();
  float x3 = three.getX();
  float y3 = three.getY();

  static unsigned int remainder = 0u; // ***
  static unsigned int currentTicks = 0u;
  static unsigned int prevTicks = SDL_GetTicks();
  currentTicks = SDL_GetTicks();
  unsigned int elapsedTicks = currentTicks - prevTicks + remainder; // ***

  if( elapsedTicks < DT ) return false; // ***

  float disc_incr = DISC_VELOCITY * DT * 0.001; // ***
  drawThis += disc_incr;
  
  if ( drawThis >= 150 ) {
  		drawThis = 0;
  		drawCycle++;
  }
  	
  if (drawThis > 75 && drawThis < 100) {
  		float y1_incr = Y_VELOCITY * DT * 0.001;
  		y1 += y1_incr;
  		one.setY(y1);
  		
  		float x2_incr = X_VELOCITY * DT * 0.001;
  		x2 -= x2_incr;
  		two.setX(x2);
  		float y2_incr = Y_VELOCITY * DT * 0.001;
  		y2 -= y2_incr;
  		two.setY(y2);
  		
  		float x3_incr = X_VELOCITY * DT * 0.001;
  		x3 += x3_incr;
  		three.setX(x3);
  		float y3_incr = Y_VELOCITY * DT * 0.001;
  		y3 -= y3_incr;
  		three.setY(y3);
  }
  
  if (drawThis > 100 && drawThis < 150) {
  		float y1_incr = Y_VELOCITY * DT * 0.001;
  		y1 -= y1_incr;
  		one.setY(y1);
  		
  		float x2_incr = X_VELOCITY * DT * 0.001;
  		x2 += x2_incr;
  		two.setX(x2);
  		float y2_incr = Y_VELOCITY * DT * 0.001;
  		y2 += y2_incr;
  		two.setY(y2);
  		
  		float x3_incr = X_VELOCITY * DT * 0.001;
  		x3 -= x3_incr;
  		three.setX(x3);
  		float y3_incr = Y_VELOCITY * DT * 0.001;
  		y3 += y3_incr;
  		three.setY(y3);
  }

  prevTicks = currentTicks;
  remainder = elapsedTicks - DT; // ***

  return true;
}
