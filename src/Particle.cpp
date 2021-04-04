#include "../headers/Particle.hpp"

Particle::Particle(){
};

Particle::Particle(type t){
    this->t = t;
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
