//
// Created by Lelana on 2026. 3. 3..
//

#include "HashTable.h"
#include <iostream>

// 해시생성함수
static int GenerateHash(std::string key) {
    int res = 0;

    res += (res * 31) + atoi(key.c_str());
    return std::abs(res);
}

bool HashTable::Add(std::string name, std::string type, int value) {
    int hash = GenerateHash(name) % listCount;

    std::vector<Entry*>& position = list[hash];

    for (Entry* e : position) {
        if (e->Key() == name) {
            return false;
        }
    }

    position.emplace_back(new Pair<std::string, Item*>(
        name,
        new Item(name, type, value)
        )
    );
    return true;
}

bool HashTable::Find(std::string name) {

}

bool HashTable::Remove(std::string name) {

}

bool HashTable::List() {
    for (int i = 0; i < listCount; i++) {
        std::vector<Entry*> position = list[i];
        if (!list->size()) continue;

        for (Entry* e : position) {
            std::cout << "이름:  " << e->Value()->name << "\n";
            std::cout << "타입:  " << e->Value()->type << "\n";
            std::cout << "밸류:  " << e->Value()->value << "\n";
            std::cout << "\n\n";
        }
    }

    return true;
}