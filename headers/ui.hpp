#include "SFML/Graphics.hpp"
#include <vector>

//Elements
#include "../headers/Slider.hpp"

class ui{
private:
    std::vector<sf::RectangleShape *> elements;

    Slider s1;
public:
    ui(/* args */);
    ~ui();

    void addElement(); //add new element, possible parameter -> type, x, y 

    void render(sf::RenderTarget *rt);
    void update();
};

