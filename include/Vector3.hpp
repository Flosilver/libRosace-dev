#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <iostream>

namespace rsc
{
template<typename T>
class Vector3
{
    public:
        /* Attributs publics */
        T x;
        T y;
        T z;

        /* Constructeurs et destructeurs */
        Vector3();//: x(0), y(0), z(0) {}
        Vector3(T& aX, T& aY, T& aZ);//: x(aX), y(aY), z(aZ) {}
        Vector3(const Vector3<T>& v);//: x(v.x), y(v.y), z(v.z) {}
        ~Vector3();
        
        /* Opérateurs */
        Vector3<T>& operator=(const Vector3<T>& v);
        bool operator==(const Vector3<T>& v) const;
        bool operator!=(const Vector3<T>& v) const;

        bool operator<(const Vector3<T>& v) const;
        bool operator<=(const Vector3<T>& v) const;
        bool operator>(const Vector3<T>& v) const;
        bool operator>=(const Vector3<T>& v) const;

        /* Arithmétique */
        Vector3<T>& operator+=(const Vector3<T>& v);
        Vector3<T>& operator-=(const Vector3<T>& v);
        Vector3<T> operator+(const Vector3<T>& v) const;
        Vector3<T> operator-(const Vector3<T>& v) const;
        T operator*(const Vector3<T>& v) const;
        Vector3<T> operator*(T t) const;

        /* Flux */
        //friend std::ostream& operator<<(std::ostream& ofs, const Vector3<T>& v);
        //friend std::istream& operator>>(std::istream& ifs, Vector3<T>& v);
};

// Define the most common types
typedef Vector3<int>          Vect3i;
typedef Vector3<unsigned int> Vect3u;
typedef Vector3<float>        Vect3f;

} // namespace rsc

#endif
