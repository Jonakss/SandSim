#include "../headers/Slider.hpp"

Slider::Slider(){
    this->pos = sf::Vector2f(150, 150);

    this->background = sf::Color::Green;
    this->background.a = 90;

    this->outerShape = sf::RectangleShape(sf::Vector2f(100, 30));
    this->outerShape.setPosition(pos);
    this->outerShape.setFillColor(background);

    this->dialerShape = sf::RectangleShape(sf::Vector2f(80, 5));
    this->dialerShape.setPosition(sf::Vector2f(pos.x+10, pos.y+(30/2)));
    this->dialerShape.setFillColor(sf::Color::Red);

    this->selectorShape = sf::RectangleShape(sf::Vector2f(10, 20));
    this->selectorShape.setPosition(sf::Vector2f(this->dialerShape.getPosition().x+25,this->dialerShape.getPosition().y-(20/2)));
    this->selectorShape.setFillColor(sf::Color::Black);




};

Slider::Slider(sf::Vector2f pos){

};

Slider::Slider(sf::Vector2f pos, sf::Vector2f size){

};

Slider::~Slider(){

};

void Slider::update(){

};

void Slider::draw(sf::RenderTarget *rt){
    rt->draw(this->outerShape);
    rt->draw(this->dialerShape);
    rt->draw(this->selectorShape);
};

void Slider::setValue(){

};

unsigned int Slider::getValue(){

};

void Slider::setPosition(sf::Vector2f pos){

};

void Slider::setSize(sf::Vector2f size){

};
