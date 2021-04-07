#include "SFML/Graphics.hpp"
#include <vector>

class ui{
private:
    std::vector<sf::RectangleShape *> elements;
public:
    ui(/* args */);
    ~ui();

    void addElement(); //add new element, possible parameter -> type, x, y 

    void render(sf::RenderTarget *rt);
    void update();
};

