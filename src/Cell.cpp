#include "../headers/Cell.hpp"

Cell::Cell(int s, int x, int y, World *w){
    this->x = x;
    this->y = y;
    this->s = s;

    this->rs = sf::RectangleShape(sf::Vector2f(this->s, this->s));
    this->rs.setPosition(sf::Vector2f(this->x*this->s, this->y*this->s));
    this->w = w;
}

Cell::~Cell(){

}

void Cell::draw(sf::RenderTarget *rt){
    this->rs.setFillColor(particleColor());

    rt->draw(rs);
}

void Cell::update(){
    if(this->p!=nullptr){
        this->p->update();
        if(n[5] != nullptr && n[5]->p == nullptr){
            this->w->stackChanges(this, n[5]);
        }
    };
};

sf::Color Cell::particleColor(){
    if(this->p == nullptr) return sf::Color::Black;
    if(this->p->getType() == Types::SAND) return sf::Color::Yellow;
    return sf::Color::White;
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

