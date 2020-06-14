#ifndef CARD_HPP
#define CARD_HPP

#include "Vector2.hpp"

namespace rsc
{
class Card
{
    protected:
        Vect2f size;    // global size of the card
        int id;         // number of the card if needed

    public:
        Card(): size(Vect2f()), id(0) {}
        Card(float aX, float aY): size(Vect2f(aX, aY)), id(0) {}
        Card(float aX, float aY, int aId): size(Vect2f(aX, aY)), id(aId) {}
        Card(const Card& c): size(Vect2f(size.x, size.y)), id(c.id) {}
        ~Card() {}

        /* Operateurs */
        Card& operator=(const Card& c);

        /* accesseur */
        const Vect2f& getSize() const {return size;}
        const int& getId() const {return id;}
};

} // namespace rsc

#endif