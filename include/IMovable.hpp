#ifndef IMOVABLE_HPP
#define IMOVABLE_HPP

#include "Vector2.hpp"

namespace rsc
{
class IMovable
{
    public:
        virtual void move(const Vect2f& v) = 0;
        virtual void moveTo(const Vect2f& v) = 0;
};

}   // namespace rsc

#endif