#ifndef DATA_S_NODE_H
#define DATA_S_NODE_H

#include <cstdio>

template<typename T>
class Node
{
    T data;
    Node *next;
public:
    explicit Node();
    explicit Node(T data);
    Node(T data, Node *next);
    Node(const Node& node);
    ~Node();
    Node<T>& operator=(const Node& node);
    void print() const;
    T getData() const;
    void setData(T data);
    Node *getNext() const;
    void setNext(Node *next);
};

template<typename T>
Node<T>::Node() {
    data = 0;
    next = nullptr;
}
template<typename T>
Node<T>::Node(T data) {
    this->data = data;
    next = nullptr;
}
template<typename T>
Node<T>::Node(T data, Node *next) {
    this->data = data;
    this->next = next;
}
template<typename T>
Node<T>::Node(const Node &node) {
    // tbd
    data = node.data;
    //next = nullptr;
}
template<typename T>
Node<T>& Node<T>::operator=(const Node &node) {
    // tbd
    data = node.data;
    next = nullptr;
    return *this;
}
template<typename T>
Node<T>::~Node() {
    // tbd
}
template<typename T>
void Node<T>::print() const {
    if(this != nullptr)
        printf("%d ", data);
}
template<typename T>
T Node<T>::getData() const
{
    return data;
}
template<typename T>
void Node<T>::setData(T data)
{
    Node::data = data;
}
template<typename T>
Node<T> *Node<T>::getNext() const
{
    return next;
}
template<typename T>
void Node<T>::setNext(Node *next)
{
    Node::next = next;
}

#endif //DATA_S_NODE_H
