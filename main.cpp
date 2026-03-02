#include <iostream>
#include "Container/BinarySearchTree.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    BinarySearchTree tree;

    // todo. csv 파일 읽어서 Insert 필요.

    tree.Insert("minwon", 20);
    tree.Insert("a", 10);
    tree.Insert("b", 50);
    tree.Insert("b", 5);
    tree.Insert("b", 90);

    tree.Show();

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}