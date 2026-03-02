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

    T& Value() const { return value; };
private:
    Node* parent = nullptr;
    Node left = nullptr;
    Node right = nullptr;

    T value;
};




#endif //HOMEWORK_NONLINEARDATASTRUCTURE_NODE_H