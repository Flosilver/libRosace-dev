#include "Vector3.hpp"

using namespace rsc;

template<typename T>
Vector3<T>::Vector3(){
    x = 0;
    y = 0;
    z = 0;
}

template<typename T>
Vector3<T>::Vector3(T& aX, T& aY, T& z){
    x = aX;
    y = aY;
    z = aZ;
}

template<typename T>
Vector3<T>::Vector3(const Vector3<T>& v){
    x = v.x;
    y = v.y;
    z = v.z;
}

template<typename T>
Vector3<T>::~Vector3(){}

/* Operateur = */
template<typename T>
Vector3<T>& Vector3<T>::operator=(const Vector3<T>& v){
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

/* Operateur == */
template<typename T>
bool Vector3<T>::operator==(const Vector3<T>& v) const {
    return (x == v.x) && (y == v.y) && (z == v.z);
}

/* Operateur != */
template<typename T>
bool Vector3<T>::operator!=(const Vector3<T>& v) const {
    return !(this->operator==(v));
}

/* Operateur < */
template<typename T>
bool Vector3<T>::operator<(const Vector3<T>& v) const{
    if( x < v.x ){
        return true;
    }
    if ( x == v.x && y < v.y ){
        return true;
    }
    if ( x == v.x && y == v.y && z < v.z){
        return true;
    }
    return false;
}

/* Operateur <= */
template<typename T>
bool Vector3<T>::operator<=(const Vector3<T>& v) const{
    return ((*this == v) || (*this < v));
}

/* Operateur > */
template<typename T>
bool Vector3<T>::operator>(const Vector3<T>& v) const{
    return v < *this;
}

/* Operateur >= */
template<typename T>
bool Vector3<T>::operator>=(const Vector3<T>& v) const{
    return ((*this == v) || (v > *this));
}

/* Operateur += */
template<typename T>
Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& v){
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

/* Operateur -= */
template<typename T>
Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& v){
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

/* Operateur + */
template<typename T>
Vector3<T> Vector3<T>::operator+(const Vector3<T>& v) const{
    return Vector3(x, y, z) += v;
}

/* Operateur - */
template<typename T>
Vector3<T> Vector3<T>::operator-(const Vector3<T>& v) const{
    return Vector3(x, y, z) -= v;
}

/* Operateur * un Vector3<T> */
template<typename T>
T Vector3<T>::operator*(const Vector3<T>& v) const{
    return x * v.x + y * v.y + z * v.z;
}

/* Operateur * un type T */
template<typename T>
Vector3<T> Vector3<T>::operator*(T t) const{
    return Vector3(x * t, y * t, z * t);
}

/* Flux Opérateur << */
template<typename T>
std::ostream& operator<<(std::ostream& ofs, const Vector3<T>& v){
    ofs << "[" << v.x << ":" << v.y << ":" << v.z << "]";
    return ofs;
}

/* Flux Operateur >> */
template<typename T>
std::istream& operator>>(std::istream& ifs, Vector3<T>& v){
    ifs >> v.x >> v.y >> v.z;
    return ifs;
}
