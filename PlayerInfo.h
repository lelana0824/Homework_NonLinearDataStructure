//
// Created by Lelana on 2026. 3. 2..
//

#ifndef HOMEWORK_NONLINEARDATASTRUCTURE_PLAYERINFO_H
#define HOMEWORK_NONLINEARDATASTRUCTURE_PLAYERINFO_H
#include <cstring>


class PlayerInfo {
public:
    PlayerInfo(const char* playerName, int score): score(score) {
        int length = strlen(playerName);
        char* newPlayerName = new char[length + 1];

        strcpy(newPlayerName, playerName);

        this->playerName = newPlayerName;
    }
    ~PlayerInfo() {
        if (playerName) {
            delete[] playerName;
            playerName = nullptr;
        }
    }

    char* playerName = nullptr;
    int score;
private:

};

#endif //HOMEWORK_NONLINEARDATASTRUCTURE_PLAYERINFO_H