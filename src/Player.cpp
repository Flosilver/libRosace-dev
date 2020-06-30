#include "Player.hpp"

using namespace rsc;
using namespace std;

/* Constructeur */
Player::Player(){
  dir = -1;
  connected = false;
}

Player::Player(int aDir){
  dir = aDir;
}

/* Destructeur */
Player::~Player() {}

/* Operateur = */
Player& Player::operator=(const Player& p){
  dir = p.dir;
  connected = p.connected;
  
  return *this;
}

/* accesseur */

const int& Player::getDir() const {
  return dir;
}

const bool& Player::isConnected() const{
  if (connected){
    cout << dir << " is connected" << endl;
  }
  else{
    cout << dir << " isn't connected" << endl;
  }
  return connected;
}

/* Methodes */

void Player::login(){
  cout << dir << "Connection" << endl;
  connected = true;
}

void Player::logout(){
  cout << dir << "Deconnexion" << endl;
  connected = false;
}
