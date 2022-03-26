//
// Created by Tom Danvers on 05/01/2022.
// 2022 TeamSunride.
//

#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector {
public:
    T _dimensions[3];
    T getX();
    T getY();
    T getZ();

    /// I (sam) have added the [] operator because it's just easier than getX,Y,Z etc sometimes
    const T & operator[](size_t index) const;
    T & operator[](size_t index);

    T at    (size_t n);
    void setX(T value);
    void setY(T value);
    void setZ(T value);

    Vector<double> divideScalar(double factor);
};



template<typename T>
Vector<double> Vector<T>::divideScalar(double factor) {
    Vector<double> returnVector{};
    for (int i=0; i<3; i++) {
        returnVector._dimensions[i] = _dimensions[i] / factor;
    }
    return returnVector;
}

template<typename T>
T Vector<T>::getX() {
    return _dimensions[0];
}

template<typename T>
T Vector<T>::getY() {
    return _dimensions[1];
}

template<typename T>
T Vector<T>::getZ() {
    return _dimensions[2];
}


// From https://github.com/janelia-arduino/Vector
template <typename T>
const T & Vector<T>::operator[](size_t index) const
{
    return _dimensions[index];
}

template <typename T>
T & Vector<T>::operator[](size_t index)
{
    return _dimensions[index];
}


template<typename T>
void Vector<T>::setX(T value) {
    _dimensions[0] = value;
}

template<typename T>
void Vector<T>::setY(T value) {
    _dimensions[1] = value;
}

template<typename T>
void Vector<T>::setZ(T value) {
    _dimensions[2] = value;
}

template<typename T>
T Vector<T>::at(size_t n) {
    return nullptr;
}


#endif //VECTOR_H
