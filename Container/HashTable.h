//
// Created by Lelana on 2026. 3. 3..
//


#ifndef HOMEWORK_NONLINEARDATASTRUCTURE_HASHTABLE_H
#define HOMEWORK_NONLINEARDATASTRUCTURE_HASHTABLE_H

#include "Pair.h"
#include "../Item.h"
#include <vector>

class HashTable {
    using Entry = Pair<std::string, Item*>;
public:
    bool Add(std::string name, std::string type, int value);
    Entry* Find(std::string name);
    bool Remove(std::string name);
    bool List();
private:
    static const int listCount = 31;
    std::vector<Entry*> list[listCount];
};


#endif //HOMEWORK_NONLINEARDATASTRUCTURE_HASHTABLE_H