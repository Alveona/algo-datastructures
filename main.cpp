#include <iostream>
#include "singlylinkedlist.h"
#include <vector>
#include <stack>
using namespace std;

int main()
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
    return 0;
}