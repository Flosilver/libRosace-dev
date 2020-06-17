#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <iostream>

namespace rsc
{
template<typename T>
class Vector2
{
    public:
        /* Attributs publics */
        T x;
        T y;

        /* Constructeurs et destructeurs */
        Vector2();
        Vector2(T& aX, T& aY);
        Vector2(const Vector2<T>& v);
        ~Vector2();

        /* Opérateurs */
        Vector2<T>& operator=(const Vector2<T>& v);
        bool operator==(const Vector2<T>& v) const;
        bool operator!=(const Vector2<T>& v) const;

        bool operator<(const Vector2<T>& v) const;
        bool operator<=(const Vector2<T>& v) const;
        bool operator>(const Vector2<T>& v) const;
        bool operator>=(const Vector2<T>& v) const;

        /* Arithmétique */
        Vector2<T>& operator+=(const Vector2<T>& v);
        Vector2<T>& operator-=(const Vector2<T>& v);
        Vector2<T> operator+(const Vector2<T>& v) const;
        Vector2<T> operator-(const Vector2<T>& v) const;
        T operator*(const Vector2<T>& v) const;
        Vector2<T> operator*(T t) const;

        /* Flux */
        //friend std::ostream& operator<<(std::ostream& ofs, const Vector2<T>& v);
        //friend std::istream& operator>>(std::istream& ifs, Vector2<T>& v);
};

// Define the most common types
typedef Vector2<int>          Vect2i;
typedef Vector2<unsigned int> Vect2u;
typedef Vector2<float>        Vect2f;

} // namespace rsc

#endif
