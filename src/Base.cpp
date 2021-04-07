#include "../headers/Base.hpp"

void Base::initWindow(){

	std::ifstream ifs("config/window.conf");

	sf::VideoMode windowConf(800,600);
	std::string title = "None";
	unsigned frameRateLimit = 120;
	bool vSync = false;

	this->cursor = sf::RectangleShape(sf::Vector2f(5, 5));
	this->cursor.setFillColor(sf::Color::Transparent);
	this->cursor.setOutlineColor(sf::Color::Red);
	this->cursor.setOutlineThickness(1);

	if(ifs.is_open()){
		std::getline(ifs, title);
		ifs >> windowConf.width >> windowConf.height;
		ifs >> frameRateLimit;
		ifs >> vSync;
	}

	ifs.close();

	this->window = new sf::RenderWindow(windowConf, title);
	this->window->setFramerateLimit(frameRateLimit);
	this->window->setVerticalSyncEnabled(vSync);

	this->UI.addElement();
};

Base::Base(){
	this->paused = false;
	this->initWindow();
};

Base::~Base(){
	delete this->window;
};

void Base::updateDt(){
	//Update the dt variable with the time it takes to update and render one frame
	this->dt = this->dtClock.restart().asSeconds();
};

void Base::render(){
	this->window->clear();

	//render functions
	for (int i = 0; i < COLS; i++){
		for (int j = 0; j < ROWS; j++){
			particles[i][j]->draw(this->window);
		};
	};
	this->UI.render(this->window);
	this->window->draw(this->cursor);

	this->window->display();
};

void Base::update(){
	this->updateEvents();
	if(!paused){
		int x=0;
		for (int i = 0; i < COLS; i++)
			for (int j = 0; j < ROWS; j++){
				particles[i][j]->update();
			};
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){		
		if(((this->mx>=0)&&(this->mx<COLS))&&((this->my>=0)&&(this->my<ROWS)))
			if(particles[mx][my]->getType() == type_::VOID)
				particles[mx][my]->changeType(type_::SAND);
			else
				particles[mx][my]->changeType(type_::VOID);	
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
					initGrid();
				break;
				case sf::Keyboard::P:				
					this->paused = !this->paused;
				break;
				default:
					break;
				}
			break;
			case sf::Event::MouseMoved:
				if(!sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)) 
				this->mx = sf::Mouse::getPosition(*this->window).x/6;
				if(!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) 
					this->my = sf::Mouse::getPosition(*this->window).y/6;
				if(((this->mx>=0)&&(this->mx<COLS))&&((this->my>=0)&&(this->my<ROWS))){
					this->cursor.setPosition(this->mx*6, this->my*6);
				}
			break;
			// case sf::Event::MouseButtonPressed:
			// 	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

			// 		this->mx = sf::Mouse::getPosition(*this->window).x/6;
			// 		this->my = sf::Mouse::getPosition(*this->window).y/6;
			// 			if(((this->mx>=0)&&(this->mx<COLS))&&((this->my>=0)&&(this->my<ROWS)))
			// 				if(particles[mx][my]->getType() == type_::VOID)
			// 					particles[mx][my]->changeType(type_::SAND);
			// 				else
			// 					particles[mx][my]->changeType(type_::VOID);							
			// 			else if (event.mouseButton.button == sf::Mouse::Right)
			// 				continue;
			// 			else if (event.mouseButton.button == sf::Mouse::Middle)
			// 				continue;
			// 	};
			// break;
			default:
				continue;
		}
	}
};

void Base::initGrid(){
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	srand(seed);
	int a = 0;
	for (int i = 0; i < COLS; i++)
		for (int j = 0; j < ROWS; j++){
			a = rand() % 100;
			if (a<30)
				particles[i][j] = new Particle(type_::VOID, i*6, j*6);
			else if (a>60)
				particles[i][j]= new Particle(type_::SAND, i*6, j*6);
			else
				particles[i][j]= new Particle(type_::VOID, i*6, j*6);
		};

	Particle *n[8];

	for (int i = 0; i < COLS; i++)
	for (int j = 0; j < ROWS; j++){
		
		if (j>0 && i>0) n[0] = particles[i-1][j-1]; else n[0] = nullptr;
		if(j>0) n[1] = particles[i][j-1]; else n[1] = nullptr;
		if(i<COLS-1 && j>0) n[2] = particles[i+1][j-1]; else n[2] = nullptr;
		if(i<COLS-1) n[3] = particles[i+1][j]; else n[3] = nullptr;
		if(i<COLS-1 && j<ROWS-1) n[4] = particles[i+1][j+1]; else n[4] = nullptr;
		if(j<ROWS-1) n[5] = particles[i][j+1]; else n[5] = nullptr;
		if(i>0 && j<ROWS-1) n[6] = particles[i-1][j+1]; else n[6] = nullptr;
		if(i>0) n[7] = particles[i-1][j]; else n[7] = nullptr;

		particles[i][j]->setneighborhood(n);
	};
}

void Base::run(){
	initGrid();

	while(this->window->isOpen()){
		this->updateDt();
		this->update();
		this->render();
	}
};
