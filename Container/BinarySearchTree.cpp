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

bool BinarySearchTree::Delete(std::string name) {
    InOrderRecursive(root, [&name](TreeNode* node) {
        if (node->Value().playerName == name) {
            TreeNode* parent = node->Parent();

            if (!node->Left() && !node->Right()) {
                delete node;
                node = nullptr;
                return true;
            }

            if (!node->Left()) {
                TreeNode* child = node->Right();
                if (node->Value().score < parent->Value().score) {
                    parent->AddLeft(child, parent);
                }
                else {
                    parent->AddRight(child, parent);
                }

                delete node;
                node = nullptr;
                return true;
            }

            if (!node->Right()) {
                TreeNode* child = node->Left();
                if (node->Value().score < parent->Value().score) {
                    parent->AddLeft(child, parent);
                }
                else {
                    parent->AddRight(child, parent);
                }

                delete node;
                node = nullptr;
                return true;
            }

            // 1. 오른쪽 서브트리에서 가장 작은 노드(Successor)와 그 부모를 찾습니다.
            TreeNode* successor = node->Right();
            TreeNode* successorParent = node;

            while (successor->Left()) {
                successorParent = successor;
                successor = successor->Left();
            }

            // 2. 후계자의 데이터를 현재 삭제하려는 노드에 덮어씌웁니다.
            node->SetValue(successor->Value());

            // 3. 후계자 노드를 트리 구조에서 안전하게 분리합니다.
            TreeNode* successorChild = successor->Right();

            if (successorParent->Left() == successor) {
                successorParent->AddLeft(successorChild, successorParent);
            } else {
                // 후계자가 삭제할 노드의 바로 오른쪽 자식이었을 경우
                successorParent->AddRight(successorChild, successorParent);
            }

            // 4. 데이터가 복사되고 트리에서 분리된 원본 후계자 노드의 메모리를 해제합니다.
            delete successor;
            successor = nullptr;

            return true;
        }

        return false;
    });

    return false;
}

Node<PlayerInfo>& BinarySearchTree::Find(std::string name) {
    TreeNode* finded = nullptr;
    InOrderRecursive(root, [&name, &finded](TreeNode* node) {
        if (node->Value().playerName == name) {
            finded = node;
        }
    });

    return *finded;
}

void BinarySearchTree::Top(int count) {
    int k = 0;
    InOrderRecursive(root, [&count, &k](TreeNode* node) {
        if (k >= count) return;

        k++;
        std::cout << "이름: " << node->Value().playerName
         << "    점수:  "  << node->Value().score << "\n";
    });
}

void BinarySearchTree::InOrder(TreeNode* node) {
    InOrderRecursive(node, [](TreeNode* node) {
        std::cout << "이름: " << node->Value().playerName
         << "    점수:  "  << node->Value().score << "\n";
    });
}

void BinarySearchTree::InOrderRecursive(TreeNode* node, InOrderFunction func) {
    if (!node) return;

    InOrderRecursive(node->Right(), func);
    func(node);
    InOrderRecursive(node->Left(), func);
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