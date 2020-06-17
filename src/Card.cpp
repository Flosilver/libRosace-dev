#include "Card.hpp"

using namespace rsc;

Card::Card(){
    id = 0;
    value = 0.f;
    size = Vect2f();
    position = Vect2f();
}

Card::Card(float aX, float aY){
    id = 0;
    value = 0.f;
    size = Vect2f(aX, aY);
    position = Vect2f();
}

Card::Card(const Vect2f& aSize){
    id = 0;
    value = 0.f;
    size = aSize;
    position = Vect2f();
}

Card::Card(float aX, float aY, int aId){
    id = aId;
    value = 0.f;
    size = Vect2f(aX, aY);
    position = Vect2f();
}

Card::Card(const Vect2f& aSize, int aId){
    id = aId;
    value = 0.f;
    size = aSize;
    position = Vect2f();
}

Card::Card(float aX, float aY, float aValue){
    id = 0;
    value = aValue;
    size = Vect2f(aX, aY);
    position = Vect2f();
}

Card::Card(const Vect2f& aSize, float aValue){
    id = 0;
    value = aValue;
    size = aSize;
    position = Vect2f();
}

Card::Card(float aX, float aY, int aId, float aValue){
    id = aId;
    value = aValue;
    size = Vect2f(aX, aY);
    position = Vect2f();
}

Card::Card(const Vect2f& aSize, int aId, float aValue){
    id = aId;
    value = aValue;
    size = aSize;
    position = Vect2f();
}

Card::Card(float aX, float aY, const Vect2f& aPos){
    id = 0;
    value = 0.f;
    size = Vect2f(aX, aY);
    position = aPos;
}

Card::Card(const Vect2f& aSize, const Vect2f& aPos){
    id = 0;
    value = 0.f;
    size = aSize;
    position = aPos;
}

Card::Card(float aX, float aY, int aId, const Vect2f& aPos){
    id = aId;
    value = 0.f;
    size = Vect2f(aX, aY);
    position = aPos;
}

Card::Card(const Vect2f& aSize, int aId, const Vect2f& aPos){
    id = aId;
    value = 0.f;
    size = aSize;
    position = aPos;
}

Card::Card(float aX, float aY, int aId, float aValue, const Vect2f& aPos){
    id = aId;
    value = aValue;
    size = Vect2f(aX, aY);
    position = aPos;
}

Card::Card(const Vect2f& aSize, int aId, float aValue, const Vect2f& aPos){
    id = aId;
    value = aValue;
    size = aSize;
    position = aPos;
}

Card::Card(const Card& c){
    id = c.id;
    value = c.value;
    size = c.size;
    position = c.position;
}

Card::~Card(){}



Card& Card::operator=(const Card& c){
    id = c.id;
    value = c.value;
    size = c.size;
    position = c.position;

    return *this;
}

const int& Card::getId() const{
    return id;
}

const float& Card::getValue() const{
    return value;
}

const Vect2f& Card::getSize() const{
    return size;
}

const Vect2f& Card::getPosition() const{
    return position;
}

void Card::move(const Vect2f& v){
    position += v;
}

void Card::moveTo(const Vect2f& v){
    position = v;
}