//
// Created by Lelana on 2026. 3. 3..
//

#ifndef HOMEWORK_NONLINEARDATASTRUCTURE_PAIR_H
#define HOMEWORK_NONLINEARDATASTRUCTURE_PAIR_H
template<typename KeyType, typename ValueType>
class Pair {
public:
    Pair(KeyType key, ValueType* value)
        : key(key), value(value) {

    }
    ~Pair() {
        if (value) {
            delete value;
            value = nullptr;
        }
    }

private:
    KeyType key;
    ValueType* value = nullptr;
};
#endif //HOMEWORK_NONLINEARDATASTRUCTURE_PAIR_H