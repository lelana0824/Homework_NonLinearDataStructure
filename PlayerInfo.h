//
// Created by Lelana on 2026. 3. 2..
//

#ifndef HOMEWORK_NONLINEARDATASTRUCTURE_PLAYERINFO_H
#define HOMEWORK_NONLINEARDATASTRUCTURE_PLAYERINFO_H
#include <cstring>
#include <string>


class PlayerInfo {
public:
    PlayerInfo(std::string playerName, int score): score(score) {
        this->playerName = playerName;
    }
    ~PlayerInfo() {

    }

    std::string playerName;
    int score;
private:

};

#endif //HOMEWORK_NONLINEARDATASTRUCTURE_PLAYERINFO_H