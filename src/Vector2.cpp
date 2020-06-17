#include "Vector2.hpp"

using namespace rsc;

/* Constructeur */
template<typename T>
Vector2<T>::Vector2(){
    x = 0;
    y = 0;
}

template<typename T>
Vector2<T>::Vector2(T& aX, T& aY){
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
    return Vector2(x, y) += v;
}

/* Operateur - */
template<typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T>& v) const{
    return Vector2(x, y) -= v;
}

/* Operateur * un Vector2<T> */
template<typename T>
T Vector2<T>::operator*(const Vector2<T>& v) const{
    return x * v.x + y * v.y;
}

/* Operateur * un type T */
template<typename T>
Vector2<T> Vector2<T>::operator*(T t) const{
    return Vector2(x * t, y * t);
}

/* Flux Opérateur << */
/*template<typename T>
std::ostream& operator<<(std::ostream& ofs, const Vector2<T>& v){
    ofs << "[" << v.x << ":" << v.y << "]";
    return ofs;
}*/

/* Flux Operateur >> */
/*template<typename T>
std::istream& operator>>(std::istream& ifs, Vector2<T>& v){
    ifs >> v.x >> v.y;
    return ifs;
}*/
