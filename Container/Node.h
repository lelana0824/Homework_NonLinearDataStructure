//
// Created by Lelana on 2026. 3. 2..
//

#ifndef HOMEWORK_NONLINEARDATASTRUCTURE_NODE_H
#define HOMEWORK_NONLINEARDATASTRUCTURE_NODE_H

template<typename T>
class Node {
public:
    Node(): value(T()) {}
    Node(T value): value(value) {}
    ~Node() {}

    void AddLeft(Node<T>* node, Node<T>* inParent) {
        node->parent = inParent;
        this->left = node;
    }
    void AddRight(Node<T>* node, Node<T>* inParent) {
        node->parent = inParent;
        this->right = node;
    }
    void SetValue(const T& value) {
        this->value = value;
    }

    const T& Value()  { return value; };
    Node<T>* Parent()  { return parent;}
    Node<T>* Left()  { return left;}
    Node<T>* Right()  { return right;}
private:
    Node<T>* parent = nullptr;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;

    T value;
};




#endif //HOMEWORK_NONLINEARDATASTRUCTURE_NODE_H