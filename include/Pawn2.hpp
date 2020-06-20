#ifndef PAWN2_HPP
#define PAWN2_HPP

#include "Vector2.hpp"
#include "IMovable2.hpp"

namespace rsc
{
class Pawn2 : public IMovable2
{
    protected:
        Vect2f position;    // position of the pawn

    public:
        Pawn2();
        Pawn2(const Vect2f& pos);
        Pawn2(float aX, float aY);
        ~Pawn2();

        /* Operateurs */
        Pawn2& operator=(const Pawn2& p);

        /* accesseur */
        const Vect2f& getPosition() const;

        /* méthode de IMovable */
        void move(const Vect2f& v);
        void moveTo(const Vect2f& v);

        /* méthode */
};

} // namespace rsc

#endif
