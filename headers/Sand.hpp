#ifndef SAND_H
#define SAND_H

#include "../headers/Particle.hpp"

class Sand: public Particle{
private:

public:
    Sand();
    ~Sand();

    virtual void update();

};

#endif