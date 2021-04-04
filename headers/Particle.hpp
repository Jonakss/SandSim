 
#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <chrono>

#include "SFML/Graphics.hpp"

enum Types{
	SAND
};
typedef enum Types type;


class Particle{
public:
	Particle();
	Particle(type t);
	~Particle();


	void update();
	type getType();
	void changeType(type t);

private:
	type t;
	uint energy; //Like protons
	uint mass;
};

#endif