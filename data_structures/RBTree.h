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
    RBNode<T> *deleteByNodeRecursive(RBNode<T> *currentroot, RBNode<T> *node);
    RBNode<T> *deleteByNode(RBNode<T> *node);
    void insert_by_value(T data);
    void fixInsertion(RBNode<T> *node);
    void fixDelete(RBNode<T> *node);
    void printFromMinToMax(RBNode<T> *currentroot);
    void print();
    void printAll(std::string spacing, bool isLast, RBNode<T> *node);
    void rotateRight(RBNode<T> *node);
    void rotateLeft(RBNode<T> *node);
    RBNode<T> *find(T value);
    RBNode<T> *findRecursive(T value, RBNode<T> *currentroot);
    RBNode<T> *getMinimumInSubtree(RBNode<T> *currentroot);
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
RBNode<T> *RBTree<T>::deleteByNode(RBNode<T> *node) {
    /*fixDelete(deleteByNodeRecursive(root, node));
    return nullptr;*/
    if(node->getLeft() == nullptr && node->getRight() == nullptr)
    {
        if (node == root)
        {
            root = nullptr;
        }
        else
        {
            if (node = node->getParent()->getLeft())
            {
                node->getParent()->setLeft(nullptr);
            }
            else
            {
                node->getParent()->setRight(nullptr);
            }
        }
        return nullptr;
    }
    RBNode *currentnode = nullptr;
    RBNode *q = nullptr;
    //if (node.)

}

template<typename T>
RBNode<T> *RBTree<T>::deleteByNodeRecursive(RBNode<T> *currentroot, RBNode<T> *node) {
    if (currentroot == nullptr)
        return nullptr;
    if (node->getData() < currentroot->getData())
    {
        currentroot = currentroot->getLeft();
        deleteByNodeRecursive(currentroot, node);
        return nullptr;
    }
    if (node->getData() > currentroot->getData())
    {
        currentroot = currentroot->getRight();
        deleteByNodeRecursive(currentroot, node);
        return nullptr;
    }
    if(node->getRight() == nullptr && node->getLeft() == nullptr)
    {
        if (node == node->getParent()->getLeft())
            node->getParent()->setLeft(nullptr);
        if (node == node->getParent()->getRight())
            node->getParent()->setRight(nullptr);
        node->setParent(nullptr); // TODO delete node

        return nullptr;
    }
    if(node->getRight() != nullptr && node->getLeft() == nullptr)
    {
        if(node == node->getParent()->getRight())
            node->getParent()->setRight(node->getRight());
        if(node == node->getParent()->getLeft())
            node->getParent()->setLeft(node->getRight());
        //node->setData(node->getRight()->getData());
        //node->setRight(nullptr);
        //node->getRight()->setParent(nullptr);
        return nullptr;
    }
    if(node->getLeft() != nullptr && node->getRight() == nullptr)
    {
        if(node == node->getParent()->getRight())
            node->getParent()->setRight(node->getLeft());
        if(node == node->getParent()->getLeft())
            node->getParent()->setLeft(node->getLeft());
       // node->setData(node->getLeft()->getData());
        //node->setLeft(nullptr);
        //node->getLeft()->setParent(nullptr);
        return nullptr;
    }
    if(node->getRight() != nullptr && node->getLeft() != nullptr)
    {
        if (node->getRight()->getLeft() == nullptr) {
            node->setData(node->getRight()->getData());
            node->setRight(node->getRight()->getRight());

        } else {
            RBNode<T> *nodeToDelete = getMinimumInSubtree(currentroot->getRight());
            //printf("current min: %d\n", nodeToDelete->getData());
            currentroot->setData(nodeToDelete->getData());
            return deleteByNodeRecursive(currentroot->getRight(), nodeToDelete);
        }
    }
}

template<typename T>
void RBTree<T>::fixDelete(RBNode<T> *node) {
    if (node == nullptr)
        return;

    if (node == root) {
        root = nullptr;
        return;
    }

    if (node->getColor() == RED || node->getLeft()->getColor() == RED || node->getRight()->getColor() == RED) {
        RBNode *child = node->getLeft() != nullptr ? node->getLeft() : node->getRight();

        if (node == node->getParent()->getLeft()) {
            node->getParent()->setLeft(child);
            if (child != nullptr)
                child->setParent(node->getParent());
            //setColor(child, BLACK);
            child->setColor(BLACK);
            delete (node);
        } else {
            node->getParent()->setRight(child);
            if (child != nullptr)
                child->setParent(node->getParent());
            //setColor(child, BLACK);
            child->setColor(BLACK);
            delete (node);
        }
    } else {
        RBNode *brother = nullptr;
        RBNode *parent = nullptr;
        RBNode *currentnode = node;
        //setColor(currentnode, DOUBLE_BLACK);
        currentnode->setColor(UNDEFINED);
        while (currentnode != root && currentnode->getColor() == UNDEFINED) {
            //parent = currentnode->parent;
            parent = currentnode->getParent();
            if (currentnode == parent->getLeft()) {
                brother = parent->getRight();
                if (brother->getColor() == RED) {
                    //setColor(brother, BLACK);
                    brother->setColor(BLACK);
                    //setColor(parent, RED);
                    parent->setColor(RED);
                    rotateLeft(parent);
                } else {
                    if (brother->getLeft()->getColor() == BLACK &&brother->getRight()->getColor() == BLACK) {
                        //setColor(brother, RED);
                        brother->setColor(RED);
                        if(parent->getColor() == RED)
                            parent->setColor(BLACK);
                        else
                            parent->setColor(UNDEFINED);
                        currentnode = parent;
                    } else {
                        if (brother->getRight()->getColor() == BLACK) {
                            setColor(brother->left, BLACK);
                            setColor(brother, RED);
                            rotateRight(brother);
                            brother = parent->right;
                        }
                        setColor(brother, parent->color);
                        setColor(parent, BLACK);
                        setColor(brother->right, BLACK);
                        rotateLeft(parent);
                        break;
                    }
                }
            } else {
                brother = parent->left;
                if (getColor(brother) == RED) {
                    setColor(brother, BLACK);
                    setColor(parent, RED);
                    rotateRight(parent);
                } else {
                    if (getColor(brother->left) == BLACK && getColor(brother->right) == BLACK) {
                        setColor(brother, RED);
                        if (getColor(parent) == RED)
                            setColor(parent, BLACK);
                        else
                            setColor(parent, DOUBLE_BLACK);
                        currentnode = parent;
                    } else {
                        if (getColor(brother->left) == BLACK) {
                            setColor(brother->right, BLACK);
                            setColor(brother, RED);
                            rotateLeft(brother);
                            brother = parent->left;
                        }
                        setColor(brother, parent->color);
                        setColor(parent, BLACK);
                        setColor(brother->left, BLACK);
                        rotateRight(parent);
                        break;
                    }
                }
            }
        }
        if (node == node->parent->left)
            node->parent->left = nullptr;
        else
            node->parent->right = nullptr;
        delete(node);
        setColor(root, BLACK);
    }
}



#endif //DATA_S_RBTREE_H
