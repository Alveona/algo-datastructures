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
    RBNode<T> *findRecursive(T value, RBNode<T> *currentroot);
    RBNode<T> *deleteBSTWay(RBNode<T> *currentroot, T value);
    RBNode<T> *getMinimumInSubtree(RBNode<T> *currentroot);
    RBNode<T> *insertByNode(RBNode<T> *currentroot, RBNode<T> *node);
    void fixInsertion(RBNode<T> *node);
    void fixDelete(RBNode<T> *node);
    void printFromMinToMax(RBNode<T> *currentroot);
    void rotateRight(RBNode<T> *node);
    void rotateLeft(RBNode<T> *node);
    void printAll(std::string spacing, bool isLast, RBNode<T> *node);
public:
    RBTree(RBNode<T> *root);
    RBTree();
    RBNode<T> *getRoot() const;
    void insertByValue(T data);
    void print();
    RBNode<T> *find(T value);
    void deleteValue(T value);

};
template<typename T>
RBTree<T>::RBTree(RBNode<T> *root):root(root) {
    root->setColor(BLACK);
}

template<typename T>
RBTree<T>::RBTree():root(nullptr) {}

template<typename T>
RBNode<T> *RBTree<T>::insertByNode(RBNode<T> *currentroot, RBNode<T> *node) {
    //printf("adwad\n");
    if(currentroot == nullptr) {
        return node;
    }

    if(node->getData() > currentroot->getData())
    {
        if(currentroot->getRight() != nullptr) {
            currentroot = currentroot->getRight();
            insertByNode(currentroot, node);
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
            insertByNode(currentroot, node);
        }
        else {
            currentroot->setLeft(node);
            node->setParent(currentroot);
        }
    }
    //fixInsertion(node);
}

template<typename T>
void RBTree<T>::insertByValue(T data) {
    //printf("adjoawiod\n");
    RBNode<T> *rbNode = new RBNode<T>(data);
    insertByNode(root, rbNode);
    fixInsertion(insertByNode(root, rbNode));
}

template<typename T>
void RBTree<T>::printFromMinToMax(RBNode<T> *currentroot) {
    //printf("akdapwd\n");
    if(currentroot != nullptr)
    {
        printFromMinToMax(currentroot->getLeft());
        currentroot->print();
        printFromMinToMax(currentroot->getRight());
    }
}

template<typename T>
RBNode<T> *RBTree<T>::getRoot() const {
    return root;
}

template<typename T>
void RBTree<T>::print() {
    printAll("", true, root);
}

template<typename T>
void RBTree<T>::printAll(std::string spacing, bool isLast, RBNode<T> *node) {
    //printf("%s", spacing);
    std::cout << spacing; //<< def << red;
    if (isLast)
    {
        printf("%s", "└─");
        spacing += "  ";
    }

    {
        printf("%s", "├─");
//        printf("%s", "└─");
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
        printAll(spacing, i == children.size() - 1, children[i]);
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

template<typename T>
RBNode<T> *RBTree<T>::getMinimumInSubtree(RBNode<T> *currentroot) {
    RBNode<T> *temp = currentroot;
    while(temp->getLeft() != nullptr)
        temp = temp->getLeft();
    return temp;
}

template<typename T>
RBNode<T> *RBTree<T>::deleteBSTWay(RBNode<T> *currentroot, T data) {
    if (currentroot == nullptr)
        return nullptr;
    if (data < currentroot->getData())
    {
        return deleteBSTWay(currentroot->getLeft(), data);
    }
    if (data > currentroot->getData())
    {
        return deleteBSTWay(currentroot->getRight(), data);
    }
    if (currentroot->getLeft() == nullptr || currentroot->getRight() == nullptr)
    {
        return currentroot;
    }
    RBNode<T> *minimum = getMinimumInSubtree(currentroot->getRight());
    T minimumData = minimum->getData();
    currentroot->setData(minimum->getData());
//    return  deleteBSTWay(currentroot->getRight(), minimum->getData());
    return deleteBSTWay(currentroot->getRight(), minimumData);
}
template<typename T>
void RBTree<T>::deleteValue(T value) {
    RBNode<T> *nodeToDelete = deleteBSTWay(root, value);
    fixDelete(nodeToDelete);
}

template<typename T>
void RBTree<T>::fixDelete(RBNode<T> *node) {
    if (node == nullptr)
        return;

    if (node == root) {
        root = nullptr;
        return;
    }

    if (node->getColor() == RED || (node->getLeft() != nullptr && node->getLeft()->getColor() == RED) || (node->getRight() !=
            nullptr && node->getRight()->getColor() == RED))
    { // TODO fix bugs when left/right is nullptr
        RBNode<T> *child = node->getLeft() != nullptr ? node->getLeft() : node->getRight();

        if (node == node->getParent()->getLeft()) {
            node->getParent()->setLeft(child);
            if (child != nullptr) {
                child->setParent(node->getParent());
                child->setColor(BLACK);
            }
        } else {
            node->getParent()->setRight(child);
            if (child != nullptr) {
                child->setParent(node->getParent());
                child->setColor(BLACK);
            }

        }
    } else {
        RBNode<T> *brother = nullptr;
        RBNode<T> *parent = nullptr;
        RBNode<T> *currentnode = node;
        currentnode->setColor(BLACK_D);
        while (currentnode != root && currentnode->getColor() == BLACK_D) {
            parent = currentnode->getParent();
            if (currentnode == parent->getLeft()) {
                brother = parent->getRight();
                if (brother->getColor() == RED) {
                    brother->setColor(BLACK);
                    parent->setColor(RED);
                    rotateLeft(parent);
                } else {
                    if (brother->getLeft()->getColor() == BLACK && brother->getRight()->getColor() == BLACK) {
                        brother->setColor(RED);
                        if(parent->getColor() == RED)
                            parent->setColor(BLACK);
                        else
                            parent->setColor(BLACK_D);
                        currentnode = parent;
                    } else {
                        if (brother->getRight()->getColor() == BLACK) {
                            brother->getLeft()->setColor(BLACK);
                            brother->setColor(RED);
                            rotateRight(brother);
                            brother = parent->getRight();
                        }
                        brother->setColor(parent->getColor());
                        parent->setColor(BLACK);
                        brother->getRight()->setColor(BLACK);
                        rotateLeft(parent);
                        break;
                    }
                }
            } else {
                brother = parent->getLeft();
                if (brother->getColor() == RED) {
                    brother->setColor(RED);
                    parent->setColor(RED);
                    rotateRight(parent);
                } else {
                    if (brother->getLeft()->getColor() == BLACK && brother->getRight()->getColor() == BLACK) {
                        brother->setColor(RED);
                        if (parent->getColor() == RED)
                            parent->setColor(BLACK);
                        else
                            parent->setColor(BLACK_D);
                        currentnode = parent;
                    } else {
                        if (brother->getLeft()->getColor() == BLACK) {
                            brother->getRight()->setColor(BLACK);
                            brother->setColor(RED);
                            rotateLeft(brother);
                            brother = parent->getLeft();
                        }
                        brother->setColor(parent->getColor());
                        parent->setColor(BLACK);
                        brother->getLeft()->setColor(BLACK);
                        rotateRight(parent);
                        break;
                    }
                }
            }
        }
        if (node == node->getParent()->getLeft())
            node->getParent()->setLeft(nullptr);
        else
            node->getParent()->setRight(nullptr);
        root->setColor(BLACK);
    }
}



#endif //DATA_S_RBTREE_H
