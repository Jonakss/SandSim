#include "../headers/Hexagon.hpp"
#include <math.h> 
#define PI 3.14159265
#define ANGLE 60
#define SIDES 6

void Hexagon::setPoints(){
    this->body[0] = sf::Vertex(sf::Vector2f(x, y), sf::Color::Green);
    for (int i = 1; i <= SIDES+1; i++){
        float angle_deg = ANGLE * i - 30;
        float angle_rad = PI / 180 * angle_deg;
        
        this->body[i] = sf::Vertex(sf::Vector2f(this->x + this->r * cos(angle_rad),
            (this->y + this->r * sin(angle_rad))), sf::Color::Red);
    };    
};

Hexagon::Hexagon(float x, float y, float r){
    this->x = x;
    this->y = y;
    this->r = r;

    this->body = sf::VertexArray(sf::TriangleFan, 8);
    setPoints();

};

Hexagon::~Hexagon(){

};

void Hexagon::setPosition(sf::Vector2f pos){
    this->body[0].position = pos;
    for (int i = 0; i <= SIDES; i++){
        float angle_deg = ANGLE * i - 30;
        float angle_rad = PI / 180 * angle_deg;
        
        this->body[i] = sf::Vertex(sf::Vector2f((pos.x + this->r * cos(angle_rad))+this->r*2,
            pos.y + this->r * sin(angle_rad)), sf::Color::Red);
    };    
};

void Hexagon::setFillColor(sf::Color c){
    this->body[0].color = c;
    this->body[1].color = c;
    this->body[2].color = c;
    this->body[3].color = c;
    this->body[4].color = c;
    this->body[5].color = c;
    this->body[6].color = c;
    this->body[7].color = c;

};

void Hexagon::draw(sf::RenderTarget& target, sf::RenderStates states)  const{
    states.transform *= getTransform();
    states.texture = NULL;
    target.draw(this->body, states);
};