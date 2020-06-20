#include "Player.hpp"

using namespace rsc;

/* Constructeur */
Player::Player(){
  name = " ";
  id = 0;
}

Player::Player(std::string n){
  name = n;
  id = 0;
}

Player::Player(std::string n, int aId){
  name = n;
  id = aId;
}

/* Destructeur */
Player::~Player() {}

/* Operateur = */
Player& Player::operator=(const Player& p){
  name = p.name;
  id = p.id;
  
  return *this;
}

/* accesseur */
const std::string& Player::getName() const {
  return name;
}

const int& Player::getId() const {
  return id;
}

/* Methodes */

void Player::login(){
  //TODO
}

void Player::logout(){
  //TODO
}
