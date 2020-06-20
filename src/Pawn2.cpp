#include "Pawn2.hpp"

using namespace rsc;

/* constructeurs */

Pawn2::Pawn2(){
  position = Vect2f();
}

Pawn2::Pawn2(const Vect2f& pos){
  position = pos;
}

Pawn2::Pawn2(float aX, float aY){
  position = Vect2f(aX,aY);
}

/* Destructeur */
Pawn2::~Pawn2() {}

/* Operateurs */
Pawn2& Pawn2::operator=(const Pawn2& p){
  position = p.position;

  return *this;
}
/* Accesseur */
const Vect2f& Pawn2::getPosition() const {
  return position;
}

/* methode de IMovable */
void Pawn2::move(const Vect2f& v){
  position += v;
}

void Pawn2::moveTo(const Vect2f& v){
  position = v;
}
