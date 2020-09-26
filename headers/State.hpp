#ifndef STATE_H
#define STATE_H

#include "SFML/Graphics.hpp"

class StateManager;

class State;

class State{
private:
  char* ID;
protected:
  State();
  virtual ~State();
public:
  void setId(char* id){ this->ID = id;}

  virtual void init();
  virtual void draw(sf::RenderTarget* rt);
  virtual void update(float dt);
  virtual void updateEvents(sf::Event &e);

  void changeState(StateManager* sm, State* s);
};

#endif
