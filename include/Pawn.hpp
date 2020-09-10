#ifndef PAWN_HPP
#define PAWN_HPP

#include "IMovable.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"

namespace rsc
{

template<typename T>
class Pawn : public IMovable<T>
{
    protected:
        T position;    // position of the pawn

    public:
        Pawn();
        Pawn(const T& pos);
        ~Pawn();

        /* Operateurs */

        Pawn<T>& operator=(const Pawn<T>& p);

        /* accesseur */

        const T& getPosition() const;

        /* méthode de IMovable */

        void move(const T& v);
        void moveTo(const T& v);

        /* méthode */
};


typedef Pawn<Vect2i> Pawn_2i;
typedef Pawn<Vect2f> Pawn_2f;
typedef Pawn<Vect2u> Pawn_2u;

typedef Pawn<Vect3i> Pawn_3i;
typedef Pawn<Vect3f> Pawn_3f;
typedef Pawn<Vect3u> Pawn_3u;


/* Constructeurs */
template<typename T>
Pawn<T>::Pawn(){
  position = T();
}

template<typename T>
Pawn<T>::Pawn(const T& pos){
  position = pos;
}

/* Destructeur */
template<typename T>
Pawn<T>::~Pawn() {}

/* Operateurs */
template<typename T>
Pawn<T>& Pawn<T>::operator=(const Pawn<T>& p){
  position = p.position;

  return *this;
}

/* Accesseur */

/**
 * Renvoie la positon du Pawn
 * */
template<typename T>
const T& Pawn<T>::getPosition() const {
  return position;
}

/* methode de IMovable */
template<typename T>
void Pawn<T>::move(const T& v){
  position += v;
}

template<typename T>
void Pawn<T>::moveTo(const T& v){
  position = v;
}

} // namespace rsc

#endif
