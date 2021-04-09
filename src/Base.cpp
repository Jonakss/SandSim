#include "../headers/Base.hpp"

void Base::initWindow(){

	std::ifstream ifs("config/window.conf");

	sf::VideoMode windowConf(800,600);
	std::string title = "None";
	unsigned frameRateLimit = 120;
	bool vSync = false;

	this->cursor = sf::RectangleShape(sf::Vector2f(15, 15));
	this->cursor.setFillColor(sf::Color::Transparent);
	this->cursor.setOutlineColor(sf::Color::Red);
	this->cursor.setOutlineThickness(1);

	if(ifs.is_open()){
		std::getline(ifs, title);
		ifs >> windowConf.width >> windowConf.height;
		ifs >> frameRateLimit;
		ifs >> vSync;
	}

	world = new World(4, 4);
	// world2 = new World(50, 50);

	ifs.close();

	this->window = new sf::RenderWindow(windowConf, title);
	this->window->setFramerateLimit(frameRateLimit);
	this->window->setVerticalSyncEnabled(vSync);
	// v = new sf::View();
	// v->reset(sf::FloatRect(10, 10, 100, 100));
};

Base::Base(){
	this->paused = false;
	this->initWindow();
	//Inicialice World
};

Base::~Base(){
	delete this->window;
};

void Base::updateDt(){
	//Update the dt variable with the time it takes to update and render one frame
	this->dt = this->dtClock.restart().asSeconds();
};

void Base::render(){
	this->window->clear(this->background);
	// window->setView(*v);

	world->draw(this->window);
	// world2->draw(this->window);

	//World draw, draw chuncks, return the pointers of the chunck
	
	// window->setView(window->getDefaultView());
	this->window->draw(this->cursor);
	
	this->window->display();
};

void Base::update(){
	this->updateEvents();
	if(!paused){
		world->update();
	};
};

void Base::updateEvents(){
	while(this->window->pollEvent(this->event)){
		switch (this->event.type){
			case sf::Event::Closed:
				this->window->close();
			break;
			case sf::Event::KeyPressed:
				switch (this->event.key.code){
				case sf::Keyboard::R:				
					//initGrid();
				break;
				case sf::Keyboard::P:				
					this->paused = !this->paused;
				break;
				case sf::Keyboard::O:				
				break;
				default:
					break;
				}
			break;
			case sf::Event::MouseMoved:
				if(!sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)) 
				this->mx = sf::Mouse::getPosition(*this->window).x/15+this->outline;
				if(!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
					this->my = sf::Mouse::getPosition(*this->window).y/15+this->outline;
					this->cursor.setPosition(this->mx*15+this->outline, this->my*15+this->outline);
				}
			break;
			case sf::Event::MouseButtonPressed:
			if (this->event.mouseButton.button == sf::Mouse::Left)
				if(mx >= this->world->getX() && my >= this->world->getY())
					this->world->newParticle(mx-this->world->getX(), my-this->world->getX());
			break;
			default:
				continue;
		}
	}
};

void Base::run(){
	//initGrid();

	while(this->window->isOpen()){
		this->updateDt();
		this->update();
		this->render();
	}
};
