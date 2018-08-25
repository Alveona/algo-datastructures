//
// Created by Pomavau on 24.08.18.
//

#ifndef DATA_S_VECTOR_H
#define DATA_S_VECTOR_H

typedef unsigned int uint;
template<typename T>
class Vector
{
    void extendByMultiplication(float constant);
    T* array = nullptr;
    uint size = 0;
    uint reserved = 0;
    const float extendingConstant = 1.5;
public:
    explicit Vector(uint size);
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

    /*void setSize(uint size) {
        Vector::size = size;
    }*/
};

template<typename T>
void Vector<T>::extendByMultiplication(float constant) {
    T* temp_array = (T*)realloc(array, (size_t)(constant * sizeof(T)));
    if(temp_array == nullptr)
        throw "Realloc failed";
    reserved*=constant;
    array = temp_array;
}

template<typename T>
Vector<T>::Vector(uint size)
{
    array = (T*)malloc(size * sizeof(T));
    if(array == nullptr)
        throw "Malloc failed";
    reserved = size > 2 ? size : 2;
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

template<typename T>
T &Vector<T>::pop_back() {
    if(size <= 0)
        throw "Nothing to pop";
    T data = array[size - 1];
    size--;
    return data;
}

template<typename T>
void Vector<T>::clear() {

}

template<typename T>
T &Vector<T>::front() const {
    if(size <= 0)
        throw "Nothing to return";
    return array[0];
}

template<typename T>
T &Vector<T>::back() const {
    if(size <= 0)
        throw "Nothing to return";
    return array[size - 1];
}

#endif //DATA_S_VECTOR_H
