#ifndef IMOVABLE3_HPP
#define IMOVABLE3_HPP

#include "Vector3.hpp"

namespace rsc
{
class IMovable3
{
    public:
        virtual void move(const Vect3f& v) = 0;     // move the object by a
        virtual void moveTo(const Vect3f& v) = 0;
};

}   // namespace rsc

#endif