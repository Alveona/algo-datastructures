//
// Created by Pomavau on 05.10.18.
//

#ifndef DATA_S_RBTREE_H
#define DATA_S_RBTREE_H

#include "RBNode.h"

template<typename T>
class RBTree{
    RBNode<T> *root = nullptr;



public:
    RBNode<T> *getRoot() const;
    RBTree(RBNode<T> *root);
    RBTree();
    RBNode<T>& insert_by_node(RBNode<T> *currentroot, RBNode<T> *node); // inserting as we would in BST
    void insert_by_value(T data);
    void print_from_min_to_max(RBNode<T> *currentroot);
};
template<typename T>
RBTree<T>::RBTree(RBNode<T> *root):root(root) {}

template<typename T>
RBTree<T>::RBTree():root(nullptr) {}

template<typename T>
RBNode<T>& RBTree<T>::insert_by_node(RBNode<T> *currentroot, RBNode<T> *node) {
    printf("adwad\n");
    if(currentroot == nullptr)
        return *node;

    if(node->getData() > currentroot->getData())
    {
        if(currentroot->getRight() != nullptr) {
            currentroot = currentroot->getRight();
            insert_by_node(currentroot, node);
        }
        else {
            currentroot->setRight(node);
        }

    }
    else if (node->getData() < currentroot->getData())
    {
        if(currentroot->getLeft() != nullptr) {
            currentroot = currentroot->getLeft();
            insert_by_node(currentroot, node);
        }
        else {
            currentroot->setLeft(node);
        }
    }
}

template<typename T>
void RBTree<T>::insert_by_value(T data) {
    printf("adjoawiod\n");
    RBNode<T> *rbNode = new RBNode<T>(data);
    insert_by_node(root, rbNode);
}

template<typename T>
void RBTree<T>::print_from_min_to_max(RBNode<T> *currentroot) {
    printf("akdapwd\n");
    if(currentroot != nullptr)
    {
        print_from_min_to_max(currentroot->getLeft());
        currentroot->print();
        print_from_min_to_max(currentroot->getRight());
    }
}

template<typename T>
RBNode<T> *RBTree<T>::getRoot() const {
    return root;
}


#endif //DATA_S_RBTREE_H
