#include "Pawn3.hpp"

using namespace rsc;

/* constructeurs */

Pawn3::Pawn3(){
  position = Vect3f();
}

Pawn3::Pawn3(const Vect3f& pos){
  position = pos;
}

Pawn3::Pawn3(float aX, float aY, float aZ){
  position = Vect3f(aX, aY, aZ);
}

/* Destructeur */
Pawn3::~Pawn3() {}

/* Operateurs */
Pawn3& Pawn3::operator=(const Pawn3& p){
  position = p.position;

  return *this;
}
/* Accesseur */
const Vect3f& Pawn3::getPosition() const {
  return position;
}

/* methode de IMovable */
void Pawn3::move(const Vect3f& v){
  position += v;
}

void Pawn3::moveTo(const Vect3f& v){
  position = v;
}
