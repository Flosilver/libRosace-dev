#ifndef IMOVABLE_HPP
#define IMOVABLE_HPP

namespace rsc
{

template<typename T>
class IMovable
{
    public:
        virtual void move(const T& v) = 0;      // move the object by T according to it's current state
        virtual void moveTo(const T& v) = 0;    // move the object to T no matter it's current state
};

}   // namespace rsc

#endif