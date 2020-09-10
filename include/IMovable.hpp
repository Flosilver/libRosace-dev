#ifndef IMOVABLE_HPP
#define IMOVABLE_HPP

namespace rsc
{

template<typename T>
class IMovable
{
    public:
        /**
         * Délace la classe IMovable d'une valeur v par raport à sa position actuelle
         * */
        virtual void move(const T& v) = 0;      // move the object by T according to it's current state
        /**
         * Déplace la classe IMovable à v par rapport au repère absolue.
         * */
        virtual void moveTo(const T& v) = 0;    // move the object to T no matter it's current state
};

}   // namespace rsc

#endif