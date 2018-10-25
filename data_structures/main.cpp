#include <iostream>
#include "RBTree.h"
//#include "SinglyLinkedList.h"
//#include "Vector.h"



using namespace std;
void SLL_tests();
void Vector_tests();
void RBTree_tests();
int main()
{
    //Vector_tests();
    RBTree_tests();
    return 0;
}

/*
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
    auto *vector = new Vector<int>(1);
    vector->push_back(5);
    vector->push_back(3);
    vector->push_back(2);
    //printf("vector size: %d\n", vector->getSize());
    for(int i = 0; i < 3; i++) {
        printf("vector size: %d\n", vector->getSize());
        printf("%d\n", vector->pop_back());
    }
        //printf("%d", vector->at(i));
}*/

void RBTree_tests()
{
    auto *rootNode = new RBNode<int>(20);
    auto *rbTree = new RBTree<int>(rootNode);
    rbTree->insert_by_value(12);
    rbTree->insert_by_value(10);
    rbTree->insert_by_value(15);
    rbTree->insert_by_value(25);
    rbTree->insert_by_value(10);
    rbTree->insert_by_value(3);
    rbTree->insert_by_value(11);
    rbTree->insert_by_value(13);
    rbTree->insert_by_value(17);

    /// PRINT TEST
    rbTree->print_from_min_to_max(rbTree->getRoot());
    printf("\n\n");
    rbTree->print();

    /// ROTATION TEST
    RBNode<int> *nodeToFind = rbTree->find(12);
    rbTree->rotateLeft(nodeToFind);
    rbTree->print();
    nodeToFind = rbTree->find(15);
    rbTree->rotateRight(nodeToFind);
    rbTree->print();
}