// Slider object
/*
Posible implementación
Element -> rezisable -> slider
Slider child of another element
*/

#include "SFML/Graphics.hpp"

class Slider{
private:
    sf::Vector2f size;
    sf::Vector2f pos;

    sf::RectangleShape outerShape;
    sf::RectangleShape dialerShape;
    sf::RectangleShape selectorShape;

    sf::Text name;

    sf::Color background;
    
    unsigned int value;
public:
    Slider();
    Slider(sf::Vector2f pos);
    Slider(sf::Vector2f pos, sf::Vector2f size);
    ~Slider();

    void update();
    void draw(sf::RenderTarget *rt);

    void setValue();
    unsigned int getValue();

    void setPosition(sf::Vector2f pos);
    void setSize(sf::Vector2f size);
};