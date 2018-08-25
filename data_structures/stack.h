//
// Created by Pomavau on 24.05.2018.
//

#ifndef DATA_S_STACK_H
#define DATA_S_STACK_H

#include "Vector.h"

typedef unsigned int uint;
template<typename T>
class Stack
{
    Vector<T> vector;

public:
    bool empty() const;
    void clear();
    T pop();
    T& top();
    void push(const T& data);

    uint getSize() const {
        return vector.getSize();
    }

};

template<typename T>
void Stack<T>::push(const T &data) {
    vector.push_back(data);
}

template<typename T>
T &Stack<T>::top() {
    return vector.back();
}

template<typename T>
T Stack<T>::pop() {
    return vector.pop_back();
}

template<typename T>
bool Stack<T>::empty() const {
    return vector.empty();
}

template<typename T>
void Stack<T>::clear() {
    vector.clear();
}


#endif //DATA_S_STACK_H
