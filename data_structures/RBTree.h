//
// Created by Pomavau on 05.10.18.
//

#ifndef DATA_S_RBTREE_H
#define DATA_S_RBTREE_H

#include "RBNode.h"

template<typename T>
class RBTree{
    RBNode *root;

public:
    void insert(RBNode node);
};
#endif //DATA_S_RBTREE_H
