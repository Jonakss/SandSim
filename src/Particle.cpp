#include "../headers/Particle.hpp"
#include "../headers/Water.hpp"

Particle::Particle(type t){
    this->t = t;
};

Particle::Particle(){
};


Particle::~Particle(){
  //  delete neighbor;
};

void Particle::update(){
};

type Particle::getType(){
    return this->t;
};

void Particle::changeType(type t){
    this->t = t;
};
