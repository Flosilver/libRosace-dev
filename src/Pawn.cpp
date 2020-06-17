#include "Pawn.hpp"

using namespace rsc;

/* constructeurs */

Pawn::Pawn(){
  position = Vect2f();
}

Pawn::Pawn(const Vect2f& pos){
  position = pos;
}

Pawn::Pawn(float aX, float aY){
  position = Vect2f(aX,aY);
}

/* Destructeur */
Pawn::~Pawn() {}

/* Operateurs */
Pawn& Pawn::operator=(const Pawn& p){
  position = p.position;
}
/* Accesseur */
const Vect2f& Pawn::getPosition() const {
  return position;
}

/* methode de IMovable */
void Pawn::move(const Vect2f& v){
  position += v;
}

void Pawn::moveTo(const Vect2f& v){
  position = v;
}
