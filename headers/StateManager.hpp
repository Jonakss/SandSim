#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "SFML/Graphics.hpp"
#include "./State.hpp"

class StateManager{
private:
  //States
  std::vector<State*> states;
  State* cState;
public:
  StateManager();
  ~StateManager();

  void draw(sf::RenderTarget* rt);
  void update(float dt);
  void updateEvents(sf::Event &e);

  void changeState(char* id);
  void pushState(State* s);
  void popState(State* s);
};

#endif
