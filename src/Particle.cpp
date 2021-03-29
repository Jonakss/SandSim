#include "../headers/Particle.hpp"
#include "../headers/types.hpp"

Particle::Particle(type_ t, int x, int y){
    this->x = x;
    this->y = y;
    this->type = t;
    this->shape= sf::RectangleShape(sf::Vector2f(5,5));
    this->shape.setPosition(sf::Vector2f(x,y));
};

Particle::~Particle(){
  //  delete neighbor;
};

void Particle::_interchangeShape(Particle *a, Particle *b){
    type_ t = a->type;
    a->type=b->type;
    b->type = t;
};

void Particle::draw(sf::RenderTarget * w){
    switch (this->type){
    case type_::VOID:
        shape.setFillColor(sf::Color::Black);
    break;
    case type_::SAND:
        shape.setFillColor(sf::Color::Yellow);
    break;
    default:
        break;
    }
    w->draw(this->shape);
};

void Particle::update(){
    if(neighbor[5] != nullptr && neighbor[5]->getType()==type_::VOID)//down;
        _interchangeShape(this, neighbor[5]);
    else if(neighbor[6] != nullptr && neighbor[6]->getType()==type_::VOID&&rand())//down left
        _interchangeShape(this, neighbor[6]);
    else if(neighbor[4] != nullptr && neighbor[4]->getType()==type_::VOID)//down right
        _interchangeShape(this, neighbor[4]);
};

void Particle::setneighborhood(Particle *n[]){
    this->neighbor[0] = n[0];
    this->neighbor[1] = n[1];
    this->neighbor[2] = n[2];
    this->neighbor[3] = n[3];
    this->neighbor[4] = n[4];
    this->neighbor[5] = n[5];
    this->neighbor[6] = n[6];
    this->neighbor[7] = n[7];
};

type_ Particle::getType(){
    return this->type;
};
void Particle::changeType(type_ t){
    this->type = t;
};
int Particle::getX(){
    return this->x;
};
int Particle::getY(){
    return this->y;
};