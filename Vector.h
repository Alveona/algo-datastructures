//
// Created by Pomavau on 24.08.18.
//

#ifndef DATA_S_VECTOR_H
#define DATA_S_VECTOR_H
typedef int uint;
template<typename T>
class Vector
{
    void extendByAddition(uint value);
    void extendByMultiplication(uint constant);
    T* array;
    uint size = 0;

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

#endif //DATA_S_VECTOR_H
