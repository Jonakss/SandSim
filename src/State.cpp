#include "../headers/StateManager.hpp"
#include "../headers/State.hpp"

void State::changeState(StateManager* sm, State* s){
  sm->changeState(s);
};
