//
// Created by Lelana on 2026. 3. 3..
//

#ifndef HOMEWORK_NONLINEARDATASTRUCTURE_PAIR_H
#define HOMEWORK_NONLINEARDATASTRUCTURE_PAIR_H
template<typename KeyType, typename ValueType>
class Pair {
public:
    Pair(KeyType key, ValueType value)
        : key(key), value(value) {

    }
    ~Pair() {

    }
    inline KeyType Key() { return key; }
    inline ValueType Value() { return value; }
private:
    KeyType key;
    ValueType value;;
};
#endif //HOMEWORK_NONLINEARDATASTRUCTURE_PAIR_H