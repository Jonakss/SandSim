#include "../headers/ui.hpp"

ui::ui(){};

ui::~ui(){};

void ui::addElement(){
    sf::RectangleShape * r = new sf::RectangleShape(sf::Vector2f(100,100));
    r->setPosition(sf::Vector2f(50,50));
    sf::Color c = sf::Color::Magenta;
    c.a = 80;
    r->setFillColor(c);
    this->elements.push_back(r);
};

void ui::render(sf::RenderTarget *rt){
    for (int i = 0; i < this->elements.size(); i++){
        rt->draw(*this->elements[i]);
    }
    
};

void ui::update(){

};
