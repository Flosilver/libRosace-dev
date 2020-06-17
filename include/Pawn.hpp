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
        Pawn();
        Pawn(const Vect2f& pos);
        Pawn(float aX, float aY);
        ~Pawn() {}

        /* Operateurs */
        Pawn& operator=(const Pawn& p);

        /* accesseur */
        const Vect2f& getPosition() const;

        /* méthode de IMovable */
        void move(const Vect2f& v);
        void moveTo(const Vect2f& v);

        /* méthode */
};

} // namespace rsc

#endif
