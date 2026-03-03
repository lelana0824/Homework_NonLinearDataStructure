//
// Created by Lelana on 2026. 3. 3..
//

#include "HashTable.h"
#include <iostream>

static int GenerateHash(std::string key) {
    int hash = 0;

    const int length = static_cast<int>(key.length());
    for (int i = 0; i < length; i++)
    {
        hash = hash * 31 + key[i];
    }
    return std::abs(hash);
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

Pair<std::string, Item*>* HashTable::Find(std::string name) {
    int hash = GenerateHash(name) % listCount;
    std::vector<Entry*>& position = list[hash];

    for (Entry* e : position) {
        if (e->Key() == name) {
            return e;
        }
    }

    return nullptr;
}

bool HashTable::Remove(std::string name) {
    int hash = GenerateHash(name) % listCount;
    std::vector<Entry*>& position = list[hash];

    for (int i = 0; i < position.size(); i++) {
        Entry*& e = position[i];
        if (e->Key() == name) {
            // 리스트에서 먼저 빼야한다.
            position.erase(position.begin(), position.begin() + 1);
            delete e;
            e = nullptr;
            return true;
        }
    }

    return false;
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