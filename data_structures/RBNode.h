#ifndef DATA_S_NODE_H
#define DATA_S_NODE_H

#include <cstdio>

enum Color{
    BLACK,
    RED
};
template<typename T>
class RBNode
{
    T data;
    RBNode *next;
    Color color = BLACK;
public:
    Color getColor() const;

    void setColor(Color color);

public:
    explicit RBNode();
    explicit RBNode(T data);
    RBNode(T data, RBNode *next);
    RBNode(const RBNode& node);
    ~Node();
    RBNode<T>& operator=(const RBNode& node);
    void print() const;
    T getData() const;
    void setData(T data);
    RBNode *getNext() const;
    void setNext(RBNode *next);
};

template<typename T>
RBNode<T>::RBNode() {
    data = 0;
    next = nullptr;
}
template<typename T>
RBNode<T>::RBNode(T data) {
    this->data = data;
    next = nullptr;
}
template<typename T>
RBNode<T>::RBNode(T data, RBNode *next) {
    this->data = data;
    this->next = next;
}
template<typename T>
RBNode<T>::RBNode(const RBNode &node) {
    // tbd
    data = node.data;
    //next = nullptr;
}
template<typename T>
RBNode<T>& RBNode<T>::operator=(const RBNode &node) {
    // tbd
    data = node.data;
    next = nullptr;
    return *this;
}
template<typename T>
RBNode<T>::~Node() {
    // tbd
}
template<typename T>
void RBNode<T>::print() const {
    if(this != nullptr)
        printf("%d ", data);
}
template<typename T>
T RBNode<T>::getData() const
{
    return data;
}
template<typename T>
void RBNode<T>::setData(T data)
{
    RBNode::data = data;
}
template<typename T>
RBNode<T> *RBNode<T>::getNext() const
{
    return next;
}
template<typename T>
void RBNode<T>::setNext(RBNode *next)
{
    RBNode::next = next;
}

template<typename T>
Color RBNode<T>::getColor() const {
    return color;
}

template<typename T>
void RBNode<T>::setColor(Color color) {
    RBNode::color = color;
}

#endif //DATA_S_NODE_H
