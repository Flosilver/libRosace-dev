#ifndef CARD_HPP
#define CARD_HPP

#include "Vector2.hpp"
#include "IMovable.hpp"

namespace rsc
{
class Card : public IMovable
{
    protected:
        int id;         // number of the card if needed
        float value;    // value of the card if needed
        Vect2f size;    // global size of the card
        Vect2f position;// Position of the Card on the Map if needed

    public:
        Card(): size(Vect2f()), id(0), value(0), position(Vect2f()) {}

        Card(float aX, float aY): size(Vect2f(aX, aY)), id(0), value(0), position(Vect2f()) {}
        Card(const Vect2f& v): size(v), id(0), value(0), position(Vect2f()) {}

        Card(float aX, float aY, int aId): size(Vect2f(aX, aY)), id(aId), value(0), position(Vect2f()) {}
        Card(const Vect2f& v, int aId): size(v), id(aId), value(0), position(Vect2f()) {}

        Card(float aX, float aY, float aValue): size(Vect2f(aX, aY)), value(aValue), id(0), position(Vect2f()) {}
        Card(const Vect2f& v, float aValue): size(v), id(0), value(aValue), position(Vect2f()) {}

        Card(float aX, float aY, int aId, float aValue): size(Vect2f(aX, aY)), id(aId), value(aValue), position(Vect2f()) {}
        Card(const Vect2f& v, int aId, float aValue): size(v), id(aId), value(aValue), position(Vect2f()) {} 

        Card(float aX, float aY, const Vect2f& aPos): size(Vect2f(aX, aY)), id(0), value(0), position(aPos) {}
        Card(const Vect2f& v, const Vect2f& aPos): size(v), id(0), value(0), position(aPos) {}

        Card(float aX, float aY, int aId, const Vect2f& aPos):  size(Vect2f(aX, aY)), id(aId), value(0), position(aPos) {}
        Card(const Vect2f& v, int aId, const Vect2f& aPos):  size(v), id(aId), value(0), position(aPos) {}

        Card(float aX, float aY, int aId, float aValue, const Vect2f& aPos): size(Vect2f(aX, aY)), id(aId), value(aValue), position(aPos) {}
        Card(const Vect2f& v, int aId, float aValue, const Vect2f& aPos): size(v), id(aId), value(aValue), position(aPos) {}

        Card(const Card& c): size(Vect2f(size.x, size.y)), id(c.id) {}

        ~Card() {}

        /* Operateurs */
        Card& operator=(const Card& c);

        /* accesseur */
        const Vect2f& getSize() const {return size;}
        const int& getId() const {return id;}

        /* Méthodes de IMovable */
        void move(const Vect2f& v);
        void moveTo(const Vect2f& v);
};

} // namespace rsc

#endif
