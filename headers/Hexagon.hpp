#ifndef HEXAGONS_H
#define HEXAGONS_H

#include "SFML/Graphics.hpp"

class Hexagon : public sf::Drawable, public sf::Transformable{
private:
    float x, y, r; // Center, size is the radius
    sf::VertexArray body;

    void setPoints(); 
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Hexagon(float x, float y, float r);
    ~Hexagon();
    void setFillColor(sf::Color);
    void setPosition(sf::Vector2f);
};

#endif