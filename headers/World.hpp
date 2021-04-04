#ifndef WORLD_H
#define WORLD_H
#include "../headers/Cell.hpp"

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Color.hpp"


class World{
private:
    typedef struct _chunk *chunk; 
	static const int COLS=25;
	static const int ROWS=25;
    static const int CELL_SIZE = 5;

	Cell *Cells[COLS*ROWS];
public:
    World();    

    void draw(sf::RenderTarget* w);
    void update();
};

#endif