//
// Created by Lelana on 2026. 3. 3..
//

#ifndef HOMEWORK_NONLINEARDATASTRUCTURE_ITEM_H
#define HOMEWORK_NONLINEARDATASTRUCTURE_ITEM_H
#include <string>

class Item {
public:
    Item(std::string name, std::string type, int value)
        : name(name), type(type), value(value) {

    }
    ~Item() {};
public:
    std::string name;
    std::string type;
    int value;
private:

};
#endif //HOMEWORK_NONLINEARDATASTRUCTURE_ITEM_H