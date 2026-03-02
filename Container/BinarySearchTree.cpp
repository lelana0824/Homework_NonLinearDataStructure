//
// Created by Lelana on 2026. 3. 2..
//

#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() {

}

BinarySearchTree::~BinarySearchTree() {
    if (root) {
        // todo. 탐색하면서 모든 노드 지워야 함.
    }
}

bool BinarySearchTree::Insert(const char* name, int score) {
    if (!root) {
        root = new Node(PlayerInfo(name, score));
        return true;
    }

    return InsertRecursive(root, name, score);
}

bool BinarySearchTree::Delete(const char* name) {}

const Node<PlayerInfo>& BinarySearchTree::Find(const char* name) {}

void BinarySearchTree::Top(int count) {}

void BinarySearchTree::InOrder(TreeNode* node) {
    InOrderRecursive(node);
}

void BinarySearchTree::InOrderRecursive(TreeNode* node) {
    if (!node) return;

    InOrderRecursive(node->Left());
    std::cout << "이름: " << node->Value().playerName
         << "    점수:  "  << node->Value().score << "\n";
    InOrderRecursive(node->Right());
}


bool BinarySearchTree::InsertRecursive(
    Node<PlayerInfo>* current, const char* name, int score) {

    if (!current) return false;

    if (score < current->Value().score) {
        if (!current->Left()) {
            current->AddLeft(new Node(PlayerInfo(name, score)), current);
            return true;
        }

        return InsertRecursive(current->Left(), name, score);
    }
    else {
        if (!current->Right()) {
            current->AddRight(new Node(PlayerInfo(name, score)), current);
            return true;
        }

        return InsertRecursive(current->Right(), name, score);
    }
}