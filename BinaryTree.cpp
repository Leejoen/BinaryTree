#include <iostream>
#include "BinarTree.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    BinaryTree<int>* binaryTree = new BinaryTree<int>();

    if (!binaryTree->addItem(1, 0)) {
        cout << "Ошибка добавления элемента в бинарное дерево\n";
    }
    if (!binaryTree->addItem(2, 1)) {
        cout << "Ошибка добавления элемента в бинарное дерево\n";
    }
    if (!binaryTree->addItem(3, 1)) {
        cout << "Ошибка добавления элемента в бинарное дерево\n";
    }
    if (!binaryTree->addItem(4, 2)) {
        cout << "Ошибка добавления элемента в бинарное дерево\n";
    }
    if (!binaryTree->addItem(6, 4)) {
        cout << "Ошибка добавления элемента в бинарное дерево\n";
    }
    if (!binaryTree->addItem(5, 3)) {
        cout << "Ошибка добавления элемента в бинарное дерево\n";
    }
    if (!binaryTree->addItem(7, 3)) {
        cout << "Ошибка добавления элемента в бинарное дерево\n";
    }

    binaryTree->show();
    cout << "\n";

    if (!binaryTree->remove(5)) {
        cout << "Ошибка удаления элемента из бинарного дерева\n";
    }

    binaryTree->show();
    cout << "\n";

    BinaryTree<std::string>* binaryTreeStr = new BinaryTree<std::string>();
    if (!binaryTreeStr->addItem("Егор", "")) {
        cout << "Ошибка добавления элемента в бинарное дерево\n";
    }
    if (!binaryTreeStr->addItem("Влад", "Егор")) {
        cout << "Ошибка добавления элемента в бинарное дерево\n";
    }
    if (!binaryTreeStr->addItem("Дима", "Егор")) {
        cout << "Ошибка добавления элемента в бинарное дерево\n";
    }
    if (!binaryTreeStr->addItem("Юра", "Дима")) {
        cout << "Ошибка добавления элемента в бинарное дерево\n";
    }
    if (!binaryTreeStr->addItem("Алина", "Дима")) {
        cout << "Ошибка добавления элемента в бинарное дерево\n";
    }
    if (!binaryTreeStr->addItem("Миша", "Влад")) {
        cout << "Ошибка добавления элемента в бинарное дерево\n";
    }

    binaryTreeStr->show();
}
