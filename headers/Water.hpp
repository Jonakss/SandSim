#ifndef WATER_H
#define WATER_H

 #include "../headers/Particle.hpp"

class Water : public Particle{
private:
    unsigned int pressure = 1;
public:
    Water();
    ~Water();

    void update();
    void setPressure(unsigned int pressure);
    unsigned int getPressure();
};


#endif