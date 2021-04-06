#ifndef WORLD_H
#define WORLD_H

#include "../headers/Cell.hpp"

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Color.hpp"
#include <math.h>

#include <vector>

class Cell;

class World{
private:
    typedef struct _chunk *chunk;
    typedef struct couple{
        Cell* a;
        Cell* b;
    } c; 

    std::vector<c> changes;

	static const int COLS=35;
	static const int ROWS=35;
    static const int CELL_SIZE = 15;

    int x = 0;
    int y = 0;

	Cell *Cells[COLS][ROWS];

    void setNeighborghood(int i, int j, int x, Cell *tn[8]);
public:
    World();    
    World(int x, int y);
    ~World();

    void initCells();
    
    int getY();
    void setY(int y);

    int getX();
    void setX(int x);

    void draw(sf::RenderTarget* w);
    void update();

    void stackChanges(Cell *a, Cell *b);
    void newParticle(int i, int j);
};

#endif