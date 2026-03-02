//
// Created by Lelana on 2026. 3. 2..
//

#ifndef HOMEWORK_NONLINEARDATASTRUCTURE_BINARYSEARCHTREE_H
#define HOMEWORK_NONLINEARDATASTRUCTURE_BINARYSEARCHTREE_H

#include "Node.h"
#include "../PlayerInfo.h"

class BinarySearchTree {
    using TreeNode = Node<PlayerInfo>;
public:
    BinarySearchTree();
    ~BinarySearchTree();

    bool Insert(const char* name, int score);
    bool Delete(const char* name);
    const TreeNode& Find(const char* name);
    void Top(int count);
    inline void Show() {
        InOrder(root);
    };
private:
    bool InsertRecursive(TreeNode* node, const char* name, int score);
    void InOrder(TreeNode* node);
    void InOrderRecursive(TreeNode* node);
private:
    TreeNode* root = nullptr;
};


#endif //HOMEWORK_NONLINEARDATASTRUCTURE_BINARYSEARCHTREE_H