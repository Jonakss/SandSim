#include "SFML/Graphics.hpp"

class ui{
private:
    /* data */
public:
    ui(/* args */);
    ~ui();

    void addElement(); //add new element, possible parameter -> type, x, y 

    void render(sf::RenderTarget *rt);
    void update();
};

