#include "Player.hpp"

using namespace rsc;

/* Constructeur */
Player::Player(){
  name = " ";
  id = 0;
  pawn = Pawn();
  hand = Deck();
}

Player::Player(std::string n){
  name = n;
  id = 0;
  pawn = Pawn();
  hand = Deck();
}

Player::Player(std::string n, int aId, Pawn& pa){
  name = n;
  id = aId;
  pawn = pa;
  hand = Deck();
}

Player::Player(std::string n, int aId, Deck& d){
  name = n;
  id = aId;
  pawn = Pawn();
  hand = d;
}

Player::Player(std::string n, int aId, Pawn& pa, Deck& d){
  name = n;
  id = aId;
  pawn = pa;
  hand = d;
}

/* Destructeur */
Player::~Player() {}

/* Operateur = */
Player& Player::operator=(const Player& p){
  name = p.name;
  id = p.id;
  pawn = p.pawn;
  hand = p.hand;
  return *this;
}

/* accesseur */
const std::string& Player::getName() const {
  return name;
}

const int& Player::getId() const {
  return id;
}

const Pawn& Player::getPawn() const {
  return pawn;
}

const Vect2f& Player::getPawnPosition() const {
  return pawn.getPosition();
}

const Deck& Player::getHand() const {
  return hand;
}

/* Methodes */

void Player::login(){
  //TODO
}

void Player::logout(){
  //TODO
}

void Player::movePawn(const Vect2f& v){
  pawn.move(v);
}

void Player::movePawnTo(const Vect2f& v){
  pawn.moveTo(v);
}
