//
// Created by Lelana on 2026. 3. 2..
//

#ifndef HOMEWORK_NONLINEARDATASTRUCTURE_BINARYSEARCHTREE_H
#define HOMEWORK_NONLINEARDATASTRUCTURE_BINARYSEARCHTREE_H

#include "Node.h"
#include "../PlayerInfo.h"

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    bool Insert(const char* name, int score);
    bool Delete();
    const Node<PlayerInfo>& Find(const char* name);
    void Top(int count);

private:

private:
    Node<PlayerInfo>* root = nullptr;
};


#endif //HOMEWORK_NONLINEARDATASTRUCTURE_BINARYSEARCHTREE_H