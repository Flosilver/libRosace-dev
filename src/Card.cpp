#include "Card.hpp"

using namespace rsc;

Card& Card::operator=(const Card& c){
    id = c.id;
    value = c.value;
    size = c.size;
    position = c.position;

    return *this;
}

void Card::move(const Vect2f& v){
    position += v;
}

void Card::moveTo(const Vect2f& v){
    position = v;
}