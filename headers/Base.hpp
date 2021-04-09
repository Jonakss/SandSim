#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <chrono>

//#include "../headers/World.hpp"
#include "../headers/Particle.hpp"

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

#include "../headers/World.hpp"

#include "../headers/Hexagon.hpp"

class Base{
private:
	const int HEIGHT = 800;
	const int WIDTH = 600;
	const char* TITLE = "SFML BASE";
	
	sf::RenderWindow* window;
	sf::View* v;
	
	sf::Event event;

	bool paused=1;
	bool outline = 0;

	//Clock system
	sf::Clock dtClock;
	//delta time
	float dt;

	sf::Color background = sf::Color(169, 169, 169);

	sf::RectangleShape cursor;
	int my, mx;
	
	World *world;
	// World *world2;

	void initWindow();
public:
	Base();
	~Base();

	void updateDt();
	void render();

	void update();
	void updateEvents();
	void run();
};

#endif
