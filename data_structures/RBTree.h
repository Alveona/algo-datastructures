//
// Created by Pomavau on 05.10.18.
//

#ifndef DATA_S_RBTREE_H
#define DATA_S_RBTREE_H

#include "RBNode.h"
#include <string.h>
#include <vector>
#include <stdlib.h>
#include "rlutil.h"


template<typename T>
class RBTree{
    RBNode<T> *root = nullptr;



public:
    RBNode<T> *getRoot() const;
    RBTree(RBNode<T> *root);
    RBTree();
    RBNode<T> *insert_by_node(RBNode<T> *currentroot, RBNode<T> *node); // inserting as we would in BST
    void insert_by_value(T data);
    void fixInsertion(RBNode<T> *node);
    void print_from_min_to_max(RBNode<T> *currentroot);
    void print();
    void print_all(std::string spacing, bool isLast, RBNode<T> *node);
    void rotateRight(RBNode<T> *node);
    void rotateLeft(RBNode<T> *node);
    RBNode<T> *find(T value);
    RBNode<T> *findRecursive(T value, RBNode<T> *currentroot);
};
template<typename T>
RBTree<T>::RBTree(RBNode<T> *root):root(root) {
    root->setColor(BLACK);
}

template<typename T>
RBTree<T>::RBTree():root(nullptr) {}

template<typename T>
RBNode<T> *RBTree<T>::insert_by_node(RBNode<T> *currentroot, RBNode<T> *node) {
    //printf("adwad\n");
    if(currentroot == nullptr) {
        //root = currentroot; // TODO should do it in normal insertion?
        //root = node;
        return node;
    }

    if(node->getData() > currentroot->getData())
    {
        if(currentroot->getRight() != nullptr) {
            currentroot = currentroot->getRight();
            insert_by_node(currentroot, node);
        }
        else {
            currentroot->setRight(node);
            node->setParent(currentroot);
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
            node->setParent(currentroot);
        }
    }
    //fixInsertion(node);
}

template<typename T>
void RBTree<T>::insert_by_value(T data) {
    //printf("adjoawiod\n");
    RBNode<T> *rbNode = new RBNode<T>(data);
    insert_by_node(root, rbNode);
    fixInsertion(insert_by_node(root, rbNode));
}

template<typename T>
void RBTree<T>::print_from_min_to_max(RBNode<T> *currentroot) {
    //printf("akdapwd\n");
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

template<typename T>
void RBTree<T>::print() {
    print_all("", true, root);
}

template<typename T>
void RBTree<T>::print_all(std::string spacing, bool isLast, RBNode<T> *node) {
    //printf("%s", spacing);
    std::cout << spacing; //<< def << red;
    if (isLast)
    {
        printf("%s", "└─");
        spacing += "  ";
    }

    {
        printf("%s", "├─");
        spacing += "| ";
    }

    rlutil::setColor((node->getColor() == RED ? rlutil::RED : rlutil::BLACK));
    std::cout << node->getData() << std::endl;
    rlutil::setColor(rlutil::BLACK);

    std::vector<RBNode<T>*> children;
    if (node->getLeft() != nullptr)
        children.push_back(node->getLeft());
    if (node->getRight() != nullptr)
        children.push_back(node->getRight());

    for (int i = 0; i < children.size(); i++)
        print_all(spacing, i == children.size() - 1, children[i]);
}

template<typename T>
void RBTree<T>::rotateRight(RBNode<T> *node) {
    RBNode<T> *wasLeft = node->getLeft();
    if (wasLeft == nullptr)
        return;
    node->setLeft(wasLeft->getRight());
    if (node->getLeft() != nullptr) {
        RBNode<T> *currentLeft = node->getLeft();
        currentLeft->setParent(node);
    }
    RBNode<T> *parentNode = node->getParent();
    wasLeft ->setParent(parentNode);

    if (parentNode == nullptr)
    {
        root = wasLeft;
    } else if (node == parentNode->getLeft())
    {
        parentNode->setLeft(wasLeft);
    }
    else
    {
        parentNode->setRight(wasLeft);
    }

    wasLeft->setRight(node);
    node->setParent(wasLeft);
}

template<typename T>
void RBTree<T>::rotateLeft(RBNode<T> *node) {
    RBNode<T> *wasRight = node->getRight();
    if (wasRight == nullptr)
        return;
    node->setRight(wasRight->getLeft());
    if (node->getRight() != nullptr) {
        RBNode<T> *currentRight = node->getRight();
        currentRight->setParent(node);
    }
    RBNode<T> *parentNode = node->getParent();
    wasRight->setParent(parentNode);

    if (parentNode == nullptr)
    {
        root = wasRight;
    } else if (node == parentNode->getLeft())
    {
        parentNode->setLeft(wasRight);
    }
    else
    {
        parentNode->setRight(wasRight);
    }

    wasRight->setLeft(node);
    node->setParent(wasRight);
}

template<typename T>
RBNode<T> *RBTree<T>::find(T value) {
    return findRecursive(value, root);
}

template<typename T>
RBNode<T> *RBTree<T>::findRecursive(T value, RBNode<T> *currentroot) {
    if(currentroot->getData() == value) {
        return currentroot;
    }
    if(value > currentroot->getData())
    {
        currentroot = currentroot->getRight();
        return findRecursive(value, currentroot);
    }
    if(value < currentroot->getData())
    {
        currentroot = currentroot->getLeft();
        return findRecursive(value, currentroot);
    }
}

template<typename T>
void RBTree<T>::fixInsertion(RBNode<T> *node) {
    RBNode<T> *parent = nullptr;
    RBNode<T> *grandparent = nullptr;
    while (node != root && node->getColor() == RED && node->getParent()->getColor() == RED) {
        parent = node->getParent();
        grandparent = parent->getParent();
        if (parent == grandparent->getLeft())
        {
            RBNode<T> *uncle = grandparent->getRight();
            if (uncle != nullptr && uncle->getColor() == RED)
            {
                uncle->setColor(BLACK);
                parent->setColor(BLACK);
                grandparent->setColor(RED);
                node = grandparent;
            }
            else if(uncle == nullptr || uncle->getColor() == BLACK)
            {
                if (node == parent->getRight()) {
                    rotateLeft(parent);
                    node = parent;
                    parent = node->getParent();
                }
                rotateRight(grandparent);
                if (parent->getColor() == RED) {
                    parent->setColor(BLACK);
                    grandparent->setColor(RED);
                } else {
                    parent->setColor(RED);
                    grandparent->setColor(BLACK);
                }
                node = parent;
            }
        } else
        {
            RBNode<T> *uncle = grandparent->getLeft();
            if (uncle != nullptr && uncle->getColor() == RED)
            {
                uncle->setColor(BLACK);
                parent->setColor(BLACK);
                grandparent->setColor(RED);
                node = grandparent;
            }
            else if(uncle == nullptr || uncle->getColor() == BLACK)
            {
                if (node == parent->getLeft()) {
                    rotateRight(parent);
                    node = parent;
                    parent = node->getParent();
                }
                rotateLeft(grandparent);
                if (parent->getColor() == RED) {
                    parent->setColor(BLACK);
                    grandparent->setColor(RED);
                } else {
                    parent->setColor(RED);
                    grandparent->setColor(BLACK);
                }
                node = parent;
            }
        }
        root->setColor(BLACK);
    }
}


#endif //DATA_S_RBTREE_H
