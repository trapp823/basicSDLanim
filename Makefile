CFLAGS=`sdl-config --cflags` -g -W -Wall -Weffc++ -Wextra -pedantic -O0
SDL_LIB=`sdl-config --libs` -lSDL_ttf -lSDL_image
CCC=g++

OBJECTS = generateFrames.o sprite.o manager.o

run: eyeanimate.o $(OBJECTS)
	$(CCC) $(CFLAGS) eyeanimate.cpp -o run $(OBJECTS) $(SDL_LIB)

eyeanimate.o: eyeanimate.cpp generateFrames.h sprite.h manager.h
	$(CCC) $(CFLAGS) -c eyeanimate.cpp

generateFrames.o: generateFrames.cpp generateFrames.h 
	$(CCC) $(CFLAGS) -c generateFrames.cpp
	
sprite.o: sprite.cpp sprite.h 
	$(CCC) $(CFLAGS) -c sprite.cpp
	
manager.o: manager.cpp manager.h 
	$(CCC) $(CFLAGS) -c manager.cpp

clean:
	rm -f run *.o
	rm -f *~
	rm -f frames/*.bmp
