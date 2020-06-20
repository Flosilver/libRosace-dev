#ifndef IMOVABLE2_HPP
#define IMOVABLE2_HPP

#include "Vector2.hpp"

namespace rsc
{
class IMovable2
{
    public:
        virtual void move(const Vect2f& v) = 0;     // move the object by a
        virtual void moveTo(const Vect2f& v) = 0;
};

}   // namespace rsc

#endif