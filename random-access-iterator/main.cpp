#include "tree.hpp"
#include <iostream>

int main() {
    // Создаем дерево
    tree my_tree{tree_node(nil, 10, tree_node(nil, 5, 15))};

    // Пример использования итераторов
    auto it = my_tree.begin();
    std::cout << "Tree elements in order: ";
    while (it != my_tree.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    // Использование operator[]
    try {
        std::cout << "Element at index 0: " << my_tree[0] << std::endl;
        std::cout << "Element at index 1: " << my_tree[1] << std::endl;
        std::cout << "Element at index 2: " << my_tree[2] << std::endl;
    } catch (const std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
