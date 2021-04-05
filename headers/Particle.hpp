 
#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <chrono>

#include "SFML/Graphics.hpp"

enum Types{
	SAND, WATER
};
typedef enum Types type;


class Particle{
public:
	Particle();
	Particle(type t);
	~Particle();

	sf::Color c = sf::Color::White;

	virtual void update();
	type getType();
	void changeType(type t);

private:
	type t;
	uint energy; //Like protons
	uint mass;
};

#endif