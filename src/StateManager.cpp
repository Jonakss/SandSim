#include "../headers/StateManager.hpp"

void StateManager::changeState(char* id){
  int i = 0;
  bool e = false
  while ((i<states.size()) && (e)) {
    i++;
    if(states[i]==id){
      cState = states[i];
      e = true;
    }
  };
};

void StateManager::pushState(State* s){
  this->states.push(s);
};

void StateManager::popState(State* s){
  this->states.pop(s);
};

void StateManager::draw(sf::RenderTarget* rt){
  this->cState->draw(rt);
};

void StateManager::update(float dt){
  this->cState->update(dt);
};

void StateManager::updateEvents(sf::Event &e){
  this->cState->updateEvents(e);
};
