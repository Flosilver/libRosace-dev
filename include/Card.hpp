#ifndef CARD_HPP
#define CARD_HPP

#include "Vector2.hpp"
#include "IMovable.hpp"

namespace rsc
{
class Card //: public IMovable
{
    protected:
        //int id;         // number of the card if needed
        float value;    // value of the card if needed
        //Vect2f size;    // global size of the card
        //Vect2f position;// Position of the Card on the Map if needed

    public:
        Card();//: size(Vect2f()), id(0), value(0), position(Vect2f()) {}

        //Card(float aX, float aY);//: size(Vect2f(aX, aY)), id(0), value(0), position(Vect2f()) {}
        //Card(const Vect2f& aSize);//: size(aSize), id(0), value(0), position(Vect2f()) {}

        //Card(float aX, float aY, int aId);//: size(Vect2f(aX, aY)), id(aId), value(0), position(Vect2f()) {}
        //Card(const Vect2f& aSize, int aId);//: size(aSize), id(aId), value(0), position(Vect2f()) {}

        //Card(float aX, float aY, float aValue);//: size(Vect2f(aX, aY)), value(aValue), id(0), position(Vect2f()) {}
        //Card(const Vect2f& aSize, float aValue);//: size(aSize), id(0), value(aValue), position(Vect2f()) {}

        //Card(float aX, float aY, int aId, float aValue);//: size(Vect2f(aX, aY)), id(aId), value(aValue), position(Vect2f()) {}
        //Card(const Vect2f& aSize, int aId, float aValue);//: size(aSize), id(aId), value(aValue), position(Vect2f()) {} 

        //Card(float aX, float aY, const Vect2f& aPos);//: size(Vect2f(aX, aY)), id(0), value(0), position(aPos) {}
        //Card(const Vect2f& aSize, const Vect2f& aPos);//: size(aSize), id(0), value(0), position(aPos) {}

        //Card(float aX, float aY, int aId, const Vect2f& aPos);//:  size(Vect2f(aX, aY)), id(aId), value(0), position(aPos) {}
        //Card(const Vect2f& aSize, int aId, const Vect2f& aPos);//:  size(aSize), id(aId), value(0), position(aPos) {}

        //Card(float aX, float aY, int aId, float aValue, const Vect2f& aPos);//: size(Vect2f(aX, aY)), id(aId), value(aValue), position(aPos) {}
        //Card(const Vect2f& aSize, int aId, float aValue, const Vect2f& aPos);//: size(aSize), id(aId), value(aValue), position(aPos) {}

        Card(float aV);

        Card(const Card& c);//: size(Vect2f(size.x, size.y)), id(c.id) {}

        ~Card();// {}

        /* Operateurs */
        Card& operator=(const Card& c);

        /* accesseur */
        //const int& getId() const;// {return id;}
        const float& getValue() const;// {return value;}
        //const Vect2f& getSize() const;// {return size;}
        //const Vect2f& getPosition() const;// {return position;}

        /* Méthodes de IMovable */
        //void move(const Vect2f& v);
        //void moveTo(const Vect2f& v);
};

} // namespace rsc

#endif
