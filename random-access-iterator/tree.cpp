#include "tree.hpp"
#include <stdexcept>

// Реализация operator+
tree::iterator operator+(tree::iterator const &self, ptrdiff_t diff) {
    tree_node *current = self.p;

    while (diff != 0) {
        if (!current) {
            throw std::out_of_range("Iterator out of bounds");
        }

        if (diff > 0) {
            // Движение вперед
            if (current->right) {
                current = current->right.get();
                while (current->left) {
                    current = current->left.get();
                }
            } else {
                while (current->up && current == current->up->right.get()) {
                    current = current->up;
                }
                current = current->up;
            }
            --diff;
        } else {
            // Движение назад
            if (current->left) {
                current = current->left.get();
                while (current->right) {
                    current = current->right.get();
                }
            } else {
                while (current->up && current == current->up->left.get()) {
                    current = current->up;
                }
                current = current->up;
            }
            ++diff;
        }
    }

    return tree::iterator{current};
}

// Реализация operator-
ptrdiff_t operator-(tree::iterator const &self, tree::iterator other) {
    auto left = self.p;
    auto right = other.p;

    if (!left || !right) {
        throw std::out_of_range("Iterator comparison out of range");
    }

    ptrdiff_t diff = 0;

    // Для простоты считаем симметричный обход дерева
    while (left != right) {
        if (left->value < right->value) {
            right = right->up;
            --diff;
        } else {
            left = left->up;
            ++diff;
        }
    }

    return diff;
}

// Реализация begin()
tree::iterator tree::begin() const {
    tree_node *current = root.get();
    if (!current) {
        return iterator{nullptr};
    }

    while (current->left) {
        current = current->left.get();
    }

    return iterator{current};
}

// Реализация end()
tree::iterator tree::end() const {
    return iterator{nullptr};
}
