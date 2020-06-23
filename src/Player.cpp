#include "Player.hpp"

using namespace rsc;
using namespace std;

/* Constructeur */
Player::Player(){
  name = "-";
  dir = -1;
  connected = false;
}

Player::Player(std::string n, int aDir){
  name = n;
  dir = aDir;
}

/* Destructeur */
Player::~Player() {}

/* Operateur = */
Player& Player::operator=(const Player& p){
  name = p.name;
  dir = p.dir;
  
  return *this;
}

/* accesseur */
const std::string& Player::getName() const {
  return name;
}

const int& Player::getDir() const {
  return dir;
}

const bool& Player::isConnected() const{
  if (connected){
    cout << dir << " is connected" << endl;
  }
  else{
    cout << dir << " is already connected" << endl;
  }
  return connected;
}

/* Methodes */

void Player::login(){
  connected = true;
}

void Player::logout(){
  connected = false;
}
