#ifndef CARD_HPP
#define CARD_HPP

#include "Vector2.hpp"
#include "IMovable.hpp"

namespace rsc
{
class Card
{
    protected:
        float value;    // value of the card if needed

    public:
        Card();
        Card(float aV);
        Card(const Card& c);

        ~Card();

        /* Operateurs */
        Card& operator=(const Card& c);

        /* accesseur */
        const float& getValue() const;// {return value;}
};

} // namespace rsc

#endif
