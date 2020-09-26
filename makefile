CC=g++
CLIB=-L/opt/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
CINCLUDE=-I/opt/SFML-2.5.1/include
CFLAGS=-Wall -std=c++11
DEPS=./headers/main.hpp ./headers/Base.hpp
OF=./out/
OBJ_MAIN=$(patsubst ./src/%,./out/%,$(patsubst %.cpp,%.o,$(wildcard ./src/*.cpp)))
EXEC=SFML_Base

$(EXEC): clean $(OBJ_MAIN)
	$(CC) $(OBJ_MAIN) -o $(EXEC) $(CLIB) $(CINCLUDE)

$(OBJ_MAIN):
	$(CC) -c src/$(basename $(notdir $@)).cpp $(CINCLUDE) -o $(basename $@).o

clean:
	rm -fr ./out/*.o
	echo "Cleaning done"
