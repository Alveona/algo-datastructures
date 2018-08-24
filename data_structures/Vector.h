//
// Created by Pomavau on 24.08.18.
//

#ifndef DATA_S_VECTOR_H
#define DATA_S_VECTOR_H

typedef unsigned int uint;
template<typename T>
class Vector
{
    void extendByAddition(uint constant);
    void extendByMultiplication(float constant);
    T* array = nullptr;
    uint size = 0;
    uint reserved = 0;
    const float extendingConstant = 1.5;
public:
    Vector(uint size);
    bool empty() const;
    void push_back(T data);
    T& pop_back();
    void clear();
    void insert(uint position, T data);
    T& at(uint position) const;
    T& front() const;
    T& back() const;


    uint getSize() const {
        return size;
    }

    void setSize(uint size) {
        Vector::size = size;
    }
};

template<typename T>
void Vector<T>::extendByMultiplication(float constant) {
    T* temp_array = (int*)realloc(array, constant * sizeof(T));
    if(temp_array == nullptr)
        throw "Realloc failed";
    reserved*=constant;
    array = temp_array;
}

template<typename T>
Vector<T>::Vector(uint size)
{
    array = (int*)malloc(size * sizeof(T));
    if(array == nullptr)
        throw "Malloc failed";
    reserved = size;
}

template <typename T>
void Vector<T>::insert(uint position, T data) {
    if(position < 0 || position >= size)
        throw "Index out of bounds";
    array[position] = data;
    size++;
    if(size == reserved)
        extendByMultiplication(extendingConstant);
}

template <typename T>
void Vector<T>::push_back(T data) {
    size++;
    array[size - 1] = data;
    if(size == reserved)
        extendByMultiplication(extendingConstant);
}

template<typename T>
bool Vector<T>::empty() const {
    return size > 0;
}

template<typename T>
T& Vector<T>::at(uint position) const {
    if(position < 0 || position >= size)
        throw "Index out of bounds exception";
    return array[position];
}
#endif //DATA_S_VECTOR_H
