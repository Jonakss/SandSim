#ifndef WATER_H
#define WATER_H

 #include "../headers/Particle.hpp"

class Water : public Particle{
private:
    unsigned int pressure = 1;
public:
    Water();
    ~Water();

    static const unsigned int MAX_PRESSURE = 10;

    void update();
    void setPressure(unsigned int pressure);
    unsigned int getPressure();
};


#endif