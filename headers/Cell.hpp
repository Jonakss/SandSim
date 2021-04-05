#ifndef CELL_H
#define CELL_H

#include "SFML/Graphics.hpp"

#include "../headers/World.hpp"

#include "../headers/Particle.hpp"
#include "../headers/Water.hpp"
#include "../headers/Sand.hpp"

class World;

class Cell{

typedef Cell * pCell;
protected:
    //Helpers
    bool emptyBelow(Cell *c);
    bool emptyBelowWater(Cell *c);
private:
    Particle *p; //Particle inside this cell
    World *w;
    pCell n[8]; //Nearest Cells

    int x, y, s; //Position x y, Size s
	sf::RectangleShape rs;
    // sf::Vertex body[6];
    sf::CircleShape body;

    sf::Color particleColor();

public:
    Cell(int s, int x, int y, World *w);
    ~Cell();

    virtual void update();
    void draw(sf::RenderTarget *rt);

	void setNeighborhood(pCell n[8]);
    /*
        Set the particle a this actual Cell
    */
    void setParticle(Particle *p);
    Particle* getParticle();


};

#endif