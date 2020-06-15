#ifndef PAWN_HPP
#define PAWN_HPP

#include "Vector2.hpp"
#include "IMovable.hpp"

namespace rsc
{
class Pawn : public IMovable
{
    protected:
        Vect2f position;    // position of the pawn

    public:
        Pawn(): position(Vect2f()) {}
        Pawn(Vect2f pose): position(pose) {}
        Pawn(float aX, float aY): position(Vect2f(aX,aY)) {}
        ~Pawn() {}

        /* Operateurs */

        /* accesseur */
        const Vect2f& getPosition() const {return position;}

        /* méthode de IMovable */
        void move(const Vect2f& v);
        void moveTo(const Vect2f& v);

        /* méthode */
};

} // namespace rsc

#endif
