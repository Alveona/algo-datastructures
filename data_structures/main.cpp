#include <iostream>
#include "SinglyLinkedList.h"
#include "Vector.h"
using namespace std;
void SLL_tests();
void Vector_tests();
int main()
{
    Vector_tests();
    return 0;
}

void SLL_tests()
{
    Node<int> *node1 = new Node<int>(10);
    Node<int> *node2 = new Node<int>(8);
    node1->setNext(node2);
    SinglyLinkedList<int> *singlyLinkedList = new SinglyLinkedList<int>();
    int a = 12;
    int b = 20;
    singlyLinkedList->push_front(a);
    singlyLinkedList->push_front(b);
    singlyLinkedList->push_front(node1);
    singlyLinkedList->push_front(node2);
    singlyLinkedList->print();
    //singlyLinkedList->pop_front();
    printf("\n");
    singlyLinkedList->getHead()->print();
    printf("\n");
    singlyLinkedList->find(12)->print();
    printf("\n");
    singlyLinkedList->getHead()->print();
}

void Vector_tests()
{
    auto *vector = new Vector<int>(5);
    vector->push_back(5);

    for(int i = 0; i < vector->getSize(); i++)
        printf("%d", vector->at(i));
}