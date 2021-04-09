#include "../headers/Cell.hpp"
#include <math.h>
#include <stdlib.h> 

Cell::Cell(int s, int x, int y, World *w){
    this->x = x;
    this->y = y;
    this->s = s; //Diameter

    // this->body = sf::CircleShape(this->s, 6);
    // this->body.setOrigin(this->s/2, this->s/2);

    // this->body.setPosition(sf::Vector2f((this->y % 2 * this->s/2)+this->x*this->s, (this->y % 2 * this->s/2)+this->s * this->y));

    this->hex = new Hexagon(x*this->s/2, y*this->s/2, s);


    
    // this->body.setPosition(sf::Vector2f(this->x*this->s, this->y*this->s));

    // this->rs = sf::RectangleShape(sf::Vector2f(this->s, this->s));
    // this->rs.setPosition(sf::Vector2f(this->x*this->s, this->y*this->s));
    this->w = w;
}

Cell::~Cell(){

}

void Cell::draw(sf::RenderTarget *rt){
    this->hex->setFillColor(particleColor());

    // rt->draw(body);
    rt->draw(*this->hex);
}

bool Cell::emptyBelow(Cell *c){
   return c != nullptr && (c->p == nullptr || c->p->getType() == WATER);
};

bool Cell::emptyBelowWater(Cell *c){
    return c != nullptr && c->p == nullptr;
};

void Cell::update(){
    if(this->p!=nullptr){
        this->p->update();
        switch (this->p->getType()){
        case WATER:
            if(n[1]!=nullptr && n[1]->p!=nullptr && n[1]->p->getType() == type::WATER)
                ((Water *)this->p)->setPressure(((Water *)n[1]->p)->getPressure()+1);
            else
                ((Water *)this->p)->setPressure(1);
            
            if(emptyBelowWater(n[5]))
                this->w->stackChanges(this, n[5]);
            else if(emptyBelowWater(n[6]))
                    this->w->stackChanges(this, n[6]);
            else if(emptyBelowWater(n[4]))
                    this->w->stackChanges(this, n[4]);
            else if(emptyBelowWater(n[3]))
                this->w->stackChanges(this, n[3]);
            // else if(emptyBelowWater(n[7]))
            //     this->w->stackChanges(this, n[7]);
            
            
        break;
        case SAND:
            if(emptyBelow(n[5]))
                this->w->stackChanges(this, n[5]);                
            else if(emptyBelow(n[6]) && rand()&1)
                this->w->stackChanges(this, n[6]);
            else if(emptyBelow(n[4]))
                this->w->stackChanges(this, n[4]);
            
        break;
        default:
            break;
        }
    };
};

sf::Color Cell::particleColor(){
    if(this->p == nullptr) return sf::Color::Black;
    return this->p->c;
};

void Cell::setNeighborhood(pCell n[8]){
    this->n[0] = n[0];
    this->n[1] = n[1];
    this->n[2] = n[2];
    this->n[3] = n[3];
    this->n[4] = n[4];
    this->n[5] = n[5];
    this->n[6] = n[6];
    this->n[7] = n[7];
};

void Cell::setParticle(Particle *p){
    this->p = p;   
}

Particle* Cell::getParticle(){
    return this->p;
};

