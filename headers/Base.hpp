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

#include "./types.hpp"

class Base{
private:
	const int HEIGHT = 800;
	const int WIDTH = 600;
	static const int COLS=100;
	static const int ROWS=100;
	const char* TITLE = "SFML BASE";
	sf::RenderWindow* window;
	sf::Event event;

	//Clock system
	sf::Clock dtClock;
	//delta time
	float dt;

	//World world;
	// struct Particle{
	// 	sf::Vector2f pos;
	// 	sf::Vector2f size;
	// 	sf::Color color;
	// 	sf::RectangleShape body;
	// 	_type type;
	// };

	sf::RectangleShape cursor;
	int my, mx;
	
	Particle *particles[COLS][ROWS];

	void initWindow();
public:
	Base();
	~Base();

	void updateDt();
	void render();

	void update();
	void updateEvents();
	void run();
	void initGrid();
};

#endif
