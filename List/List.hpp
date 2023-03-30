#include "List.h"

template <typename T>
typename List<T>::ListNode *&List<T>::_index(unsigned index) {
  return _index_helper(index, head_);
}

template <typename T>
typename List<T>::ListNode *&List<T>::_index_helper(unsigned index,
                                                    List::ListNode *&node) {
  if (index == 0 || node == nullptr) {
    return node;
  } else {
    return _index_helper(index - 1, node->next);
  }
}

template <typename T> const T &List<T>::operator[](unsigned index) {
  ListNode *&node = _index(index);
  return node->data;
}

template <typename T> void List<T>::insert(const T &data, unsigned int index) {
  auto *new_node = new ListNode(data);
  auto *&node = _index(index);
  new_node->next = node;
  node = new_node;
}

template <typename T> const T &List<T>::remove(unsigned index) {
  auto *&node = _index(index);
  auto *tmp = node;
  const T &data = tmp->data;
  node = node->next;
  delete tmp;
  return data;
}