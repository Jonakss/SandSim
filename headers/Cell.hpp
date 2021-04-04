#include "SFML/Graphics.hpp"

#include "../headers/Particle.hpp"


class Cell{

typedef Cell * pCell;

private:
    Particle *p; //Particle inside this cell
    pCell n[8]; //Nearest Cells

    int x, y, s; //Position x y, Size s
	sf::RectangleShape rs;

    sf::Color particleColor();
public:
    Cell(int s, int x, int y);
    ~Cell();

    void update();
    void draw(sf::RenderTarget *rt);

	void setNeighborhood(pCell n[8]);
    /*
        Set the particle a this actual Cell
    */
    void setParticle(Particle *p);
};
