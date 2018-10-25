//
// Created by Pomavau on 05.10.18.
//

#ifndef DATA_S_RBTREE_H
#define DATA_S_RBTREE_H

#include "RBNode.h"
#include <string.h>
#include <vector>

namespace ColorText {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}


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
    void print();
    void print_all(std::string spacing, bool isLast, RBNode<T> *node);
    void rotateRight(RBNode<T> *node);
    void rotateLeft(RBNode<T> *node);
    RBNode<T> *find(T value);
    RBNode<T> *findRecursive(T value, RBNode<T> *currentroot);
};
template<typename T>
RBTree<T>::RBTree(RBNode<T> *root):root(root) {}

template<typename T>
RBTree<T>::RBTree():root(nullptr) {}

template<typename T>
RBNode<T>& RBTree<T>::insert_by_node(RBNode<T> *currentroot, RBNode<T> *node) {
    //printf("adwad\n");
    if(currentroot == nullptr) {
        //root = currentroot; // TODO should do it in normal insertion?
        return *node;
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
}

template<typename T>
void RBTree<T>::insert_by_value(T data) {
    //printf("adjoawiod\n");
    RBNode<T> *rbNode = new RBNode<T>(data);
    insert_by_node(root, rbNode);
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
    ColorText::Modifier red(ColorText::FG_RED);
    ColorText::Modifier def(ColorText::FG_DEFAULT);
    std::cout << spacing; //<< def << red;
    if (isLast)
    {
        printf("%s", "└─");
        spacing += "  ";
    }
    else
    {
        printf("%s", "├─");
        spacing += "| ";
    }
    //printf("%d\n", node->getData());

    std::cout << node->getData() << std::endl; //<< red << std::endl;

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


#endif //DATA_S_RBTREE_H
