#include "assignment/linked_list.hpp"

#include <utility>  // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    // Напишите здесь свой код ...
    Node *next_node = nullptr;
    Node *prev = nullptr;
    Node *current = front_;
    Node *back_node = nullptr;
    while (current != nullptr) {
      next_node = current->next;
      current->next = prev;
      prev = current;
      current = next_node;
    }
    back_node = back_;
    back_ = front_;
    front_ = back_node;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (size_ > 0) {
      reverse_recursive_helper(front_, nullptr);
      Node* back_node = back_;
      back_ = front_;
      front_ = back_node;
    }
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node *&curr, Node *prev) {
    Node* node = curr->next;
    curr->next = prev;
    if (node != nullptr) {
      reverse_recursive_helper(node, curr);
    }
  }

}  // namespace assignment
