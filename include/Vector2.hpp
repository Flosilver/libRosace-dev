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
        Vector2(T aX, T aY);
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
        template<typename T2>
        friend std::ostream& std::operator<<(std::ostream& ofs, const Vector2<T2>& v);
        template<typename T2>
        friend std::istream& std::operator>>(std::istream& ifs, Vector2<T2>& v);
};

// Define the most common types
typedef Vector2<int>          Vect2i;
typedef Vector2<unsigned int> Vect2u;
typedef Vector2<float>        Vect2f;

/* Constructeur */
template<typename T>
Vector2<T>::Vector2(){
    x = T();
    y = T();
}

template<typename T>
Vector2<T>::Vector2(T aX, T aY){
    x = aX;
    y = aY;
}

template<typename T>
Vector2<T>::Vector2(const Vector2<T>& v){
    x = v.x;
    y = v.y;
}

/* Destructeur */
template<typename T>
Vector2<T>::~Vector2() {}


/* Operateur = */
template<typename T>
Vector2<T>& Vector2<T>::operator=(const Vector2<T>& v){
    x = v.x;
    y = v.y;
    return *this;
}

/* Operateur == */
template<typename T>
bool Vector2<T>::operator==(const Vector2<T>& v) const {
    return (x == v.x) && (y == v.y);
}

/* Operateur != */
template<typename T>
bool Vector2<T>::operator!=(const Vector2<T>& v) const {
    return !(this->operator==(v));
}

/* Operateur < */
template<typename T>
bool Vector2<T>::operator<(const Vector2<T>& v) const{
    if( x < v.x ){
        return true;
    }
    if ( x == v.x && y < v.y ){
        return true;
    }
    return false;
}

/* Operateur <= */
template<typename T>
bool Vector2<T>::operator<=(const Vector2<T>& v) const{
    return ((*this == v) || (*this < v));
}

/* Operateur > */
template<typename T>
bool Vector2<T>::operator>(const Vector2<T>& v) const{
    return v < *this;
}

/* Operateur >= */
template<typename T>
bool Vector2<T>::operator>=(const Vector2<T>& v) const{
    return ((*this == v) || (v > *this));
}

/* Operateur += */
template<typename T>
Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& v){
    x += v.x;
    y += v.y;
    return *this;
}

/* Operateur -= */
template<typename T>
Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& v){
    x -= v.x;
    y -= v.y;
    return *this;
}

/* Operateur + */
template<typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T>& v) const{
    return Vector2<T>(x, y) += v;
}

/* Operateur - */
template<typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T>& v) const{
    return Vector2<T>(x, y) -= v;
}

/* Operateur * un Vector2<T> */
template<typename T>
T Vector2<T>::operator*(const Vector2<T>& v) const{
    return x * v.x + y * v.y;
}

/* Operateur * un type T */
template<typename T>
Vector2<T> Vector2<T>::operator*(T t) const{
    return Vector2<T>(x * t, y * t);
}




} // namespace rsc

/* Flux Opérateur << */
template<typename T2>
std::ostream& operator<<(std::ostream& ofs, const rsc::Vector2<T2>& v){
    ofs << "[ " << v.x << " : " << v.y << " ]";
    return ofs;
}

/* Flux Operateur >> */
template<typename T2>
std::istream& operator>>(std::istream& ifs, rsc::Vector2<T2>& v){
    ifs >> v.x >> v.y;
    return ifs;
}



#endif
