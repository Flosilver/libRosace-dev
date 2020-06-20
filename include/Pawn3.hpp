#ifndef PAWN3_HPP
#define PAWN3_HPP

#include "Vector3.hpp"
#include "IMovable3.hpp"

namespace rsc
{
class Pawn3 : public IMovable3
{
    protected:
        Vect3f position;    // position of the pawn

    public:
        Pawn3();
        Pawn3(const Vect3f& pos);
        Pawn3(float aX, float aY, float aZ);
        ~Pawn3();

        /* Operateurs */
        Pawn3& operator=(const Pawn3& p);

        /* accesseur */
        const Vect3f& getPosition() const;

        /* méthode de IMovable */
        void move(const Vect3f& v);
        void moveTo(const Vect3f& v);

        /* méthode */
};

} // namespace rsc

#endif
