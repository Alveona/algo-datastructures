#ifndef DATA_S_RBNODE_H
#define DATA_S_RBNODE_H

#include <cstdio>

enum Color{
    BLACK,
    RED,
    UNDEFINED,
};
template<typename T>
class RBNode
{
    T data;
    RBNode *left;
    RBNode *right;
    RBNode *parent;
    Color color = RED;
public:
    RBNode *getLeft() const;

    void setLeft(RBNode *left);

    RBNode *getRight() const;

    void setRight(RBNode *right);

    RBNode *getParent() const;

    void setParent(RBNode *parent);

    Color getColor() const;
    void setColor(Color color);

    explicit RBNode();
    explicit RBNode(T data);
    RBNode(T data, RBNode *left, RBNode *right, RBNode *parent);
    RBNode(const RBNode& node);
    ~RBNode();
    RBNode<T>& operator=(const RBNode& node);
    void print() const;
    T getData() const;
    void setData(T data);
};

template<typename T>
RBNode<T>::RBNode() {
    data = 0;
    right = nullptr;
    left = nullptr;
    parent = nullptr;
}
template<typename T>
RBNode<T>::RBNode(T data) {
    this->data = data;
    right = nullptr;
    left = nullptr;
    parent = nullptr;
}
template<typename T>
RBNode<T>::RBNode(T data, RBNode *right, RBNode *left, RBNode *parent) {
    this->data = data;
    this->right = right;
    this->left = left;
    this->parent = parent;
}
template<typename T>
RBNode<T>::RBNode(const RBNode &node) {
    // TODO
    data = node.data;
    //next = nullptr;
}
template<typename T>
RBNode<T>& RBNode<T>::operator=(const RBNode &node) {
    // TODO
    data = node.data;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    return *this;
}
template<typename T>
RBNode<T>::~RBNode() {
    // TODO
}
template<typename T>
void RBNode<T>::print() const {
    //printf("jfvioafoa");
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
    RBNode<T>::data = data;
}

template<typename T>
Color RBNode<T>::getColor() const {
    return color;
}

template<typename T>
void RBNode<T>::setColor(Color color) {
    RBNode<T>::color = color;
}

template<typename T>
RBNode<T> *RBNode<T>::getLeft() const {
    if (this == nullptr)
        return nullptr;
    return left;
}

template<typename T>
void RBNode<T>::setLeft(RBNode<T> *left) {
    RBNode<T>::left = left;
}

template<typename T>
RBNode<T> *RBNode<T>::getRight() const {
    if (this == nullptr)
        return nullptr;
    return right;
}

template<typename T>
void RBNode<T>::setRight(RBNode<T> *right) {
    RBNode<T>::right = right;
}

template<typename T>
RBNode<T> *RBNode<T>::getParent() const {
    return parent;
}

template<typename T>
void RBNode<T>::setParent(RBNode<T> *parent) {
    RBNode<T>::parent = parent;
}

#endif //DATA_S_RBNODE_H
