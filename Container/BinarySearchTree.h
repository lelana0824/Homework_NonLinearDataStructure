//
// Created by Lelana on 2026. 3. 2..
//

#ifndef HOMEWORK_NONLINEARDATASTRUCTURE_BINARYSEARCHTREE_H
#define HOMEWORK_NONLINEARDATASTRUCTURE_BINARYSEARCHTREE_H

#include "Node.h"
#include "../PlayerInfo.h"
#include <functional>

using InOrderFunction = std::function<void(Node<PlayerInfo>* node)>;

class BinarySearchTree {
    using TreeNode = Node<PlayerInfo>;
public:
    BinarySearchTree();
    ~BinarySearchTree();

    bool Insert(const char* name, int score);
    bool Delete(std::string name);
    TreeNode& Find(std::string name);
    void Top(int count);
    inline void Show() {
        InOrder(root);
    };
private:
    bool InsertRecursive(TreeNode* node, const char* name, int score);
    void InOrder(TreeNode* node);
    void InOrderRecursive(TreeNode* node, InOrderFunction func);
private:
    TreeNode* root = nullptr;
};


#endif //HOMEWORK_NONLINEARDATASTRUCTURE_BINARYSEARCHTREE_H