#ifndef DATA_S_SINGLE_LINKED_LIST_H
#define DATA_S_SINGLE_LINKED_LIST_H
#include "Node.h"
typedef unsigned int uint;
template<typename T>
class SinglyLinkedList
{
    Node<T> *head;
    Node<T> *tail;
    uint size;

public:
    SinglyLinkedList();

    void print() const;
    bool empty() const;
    Node<T>* find(const T &data) const;
    bool contains(const T &data) const;
    void push_front(Node<T> *node);
    void push_front(T &data);
    void pop_front();
    void insert_after(uint index);
    void erase(const T &data);
    void erase_after(uint index);
    void clear();

    uint getSize() const;

    void setSize(uint size);

    Node<T>* getHead() const;

    void setHead(Node<T> *head);

    Node<T>* getTail() const;

    void setTail(Node<T> *tail);


};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template<typename T>
void SinglyLinkedList<T>::push_front(Node<T> *node) {
    if(head == nullptr)
    {
        node->setNext(head);
        this->head = node;
        this->tail = node;
        size++;
    }
    else
    {
        node->setNext(head);
        this->head = node;
        size++;
    }

}
template<typename T>
Node<T>* SinglyLinkedList<T>::find(const T &data) const {
    Node<T> *current = head;
    while(current != nullptr)
    {
        if(current->getData() == data)
            return current;
        current = current->getNext();
    }
    return nullptr;
}
template<typename T>
void SinglyLinkedList<T>::push_front(T &data) {
    Node<T> *node = new Node<T>(data);
    push_front(node);
}
template<typename T>
void SinglyLinkedList<T>::print() const {
    Node<T> *current = head;
    while(current != nullptr)
    {
        current->print();
        current = current->getNext();
    }
}
template<typename T>
void SinglyLinkedList<T>::pop_front() {
    if(head->getNext() != nullptr)
    {
        head = head->getNext();
        size--;
    }

}
template<typename T>
Node<T> *SinglyLinkedList<T>::getHead() const
{
    return head;
}
template<typename T>
void SinglyLinkedList<T>::setHead(Node<T> *head)
{
    SinglyLinkedList<T>::head = head;
}
template<typename T>
Node<T> *SinglyLinkedList<T>::getTail() const
{
    return tail;
}
template<typename T>
void SinglyLinkedList<T>::setTail(Node<T> *tail)
{
    SinglyLinkedList<T>::tail = tail;
}
template<typename T>
uint SinglyLinkedList<T>::getSize() const
{
    return size;
}
template<typename T>
void SinglyLinkedList<T>::setSize(uint size)
{
    SinglyLinkedList<T>::size = size;
}

#endif //DATA_S_SINGLE_LINKED_LIST_H
