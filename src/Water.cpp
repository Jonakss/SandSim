#include "../headers/Water.hpp"

Water::Water():Particle(WATER){
    this->c = sf::Color::Blue;
    this->c.r = sf::Color::Blue.r / this->pressure * 2;
    this->c.g = sf::Color::Blue.g / this->pressure * 2;
    this->c.b = sf::Color::Blue.b / this->pressure * 2;
};

Water::~Water(){};

void Water::update(){
    
};

void Water::setPressure(unsigned int p){
    this->pressure = p;
    this->c.r = sf::Color::Blue.r / this->pressure * 2;
    this->c.g = sf::Color::Blue.g / this->pressure * 2;
    this->c.b = sf::Color::Blue.b / this->pressure * 2;
};

unsigned int Water::getPressure(){
    return this->pressure;
};
