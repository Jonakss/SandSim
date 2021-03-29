 
#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <chrono>

#include "SFML/Graphics.hpp"
#include "./types.hpp"

class Particle{
private:
	int x, y;
	type_ type;
	Particle *neighbor[8];

	sf::RectangleShape shape;

public:
	bool updated=false;

	Particle(type_ t, int x, int i);
	~Particle();

	void _interchangeShape(Particle *a, Particle *b);
	void setneighborhood(Particle *n[]);

	void draw(sf::RenderTarget* w);
	void update();
	type_ getType();
	void changeType(type_ t);
	int getX();
	int getY();
};

#endif