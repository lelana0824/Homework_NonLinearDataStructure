#include <iostream>
#include "Container/BinarySearchTree.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    BinarySearchTree tree;
    FILE* file = nullptr;

    file = fopen("./players.csv", "rb");

    char buffer[1024];
    int lineNumber = 0;

    while (fgets(buffer, 1024, file)) {
        if (lineNumber > 0) {
            char* token = strtok(buffer, ",");

            if (!token) continue;
            int nameLen = 0;
            while (token[nameLen] != '\0') nameLen++;
            char* name = new char[nameLen + 1];
            for (int i = 0; i <= nameLen; ++i) {
                name[i] = token[i];
            }

            token = strtok(nullptr, ",");

            if (!token) continue;
            int score = std::atoi(token);
            tree.Insert(name, score);
            delete[] name;
        }

        lineNumber++;
    }

    fclose(file);
    tree.Top(3);

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}