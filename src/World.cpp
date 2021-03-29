#include "../headers/World.hpp"

World::World(){
    for (int i = 0; i < COLS; i++){
        for (int j = 0; j < ROWS; j++){
            this->particlesBody[i*COLS+j] = sf::RectangleShape();
            this->particlesBody[i*COLS+j].setFillColor(sf::Color::Black);
            this->particlesBody[i*COLS+j].setSize(sf::Vector2f(1,1));
            if(i/(j+2)==2){
                this->particles[i*COLS+j] = new Particle(type_::SAND, i, j);
                this->particlesBody[i*COLS+j].setFillColor(sf::Color::Yellow);
            }else
                this->particles[i*COLS+j] = new Particle(type_::VOID, i, j);
            this->particlesBody[i*COLS+j].setPosition(sf::Vector2f(this->particles[i*COLS+j]->getX(), this->particles[i*COLS+j]->getY()));
        }
    }
};
void World::draw(sf::RenderWindow* w){
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            w->draw(this->particlesBody[i*COLS+j]);
        };
    };
};
void World::update(){
    for (int i = 0; i < COLS; i++){
        for (int j = 0; j < ROWS; j++){
            if(j<ROWS-1){
                if(this->particles[i*COLS+j+1]->getType() == type_::VOID){
                    Particle *pp = this->particles[i*COLS+j+1];
                    this->particles[i*COLS+j+1] = this->particles[i*COLS+j];
                    this->particles[i*COLS+j] = pp;
                    this->particlesBody[i*COLS+j].setPosition(sf::Vector2f(this->particles[i*COLS+j]->getX(), this->particles[i*COLS+j]->getY()+1));
                };
            };
        };
    };
};