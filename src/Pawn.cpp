#include "Pawn.hpp"

using namespace rsc;

/* move */
void Pawn::move(const Vect2f& v){
  position += v;
}

void Pawn::moveTo(const Vect2f& v){
  position = v;
}
