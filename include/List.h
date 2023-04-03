#pragma once

template<typename T>
class List {
 public:
  List() : head_(nullptr) {};
  const T &operator[](unsigned index);
  void insert(const T &data, unsigned index);
  const T &remove(unsigned index);

 private:
  struct ListNode {
    T data;
    ListNode *next;
    explicit ListNode(T data) : data(data), next(nullptr) {}
  };
  ListNode *head_;
  ListNode *&_index_helper(unsigned index, ListNode *&node);
  ListNode *&_index(unsigned index);
};

#include "List.hpp"