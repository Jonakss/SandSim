#ifndef WORLD_H
#define WORLD_H
#include "../headers/Particle.hpp"

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Color.hpp"


class World{
private:
	static const int COLS=25;
	static const int ROWS=25;

	Particle *particles[COLS*ROWS];
    sf::RectangleShape particlesBody[COLS*ROWS];
public:
    World();    
    //Particle* getParticle(int x, int y){ return (x<=COLS)&&(y<=ROWS)&&(y>=0)&&(x>=0)?this->particles[x][y]:nullptr;};

    void draw(sf::RenderWindow* w);
    void update();
};

#endif