#pragma once

template<typename T>
class Queue {
 public:
  explicit Queue(int size = 10);
  ~Queue();
  T dequeue();
  void enqueue(T elem);
  bool isEmpty();
  bool isFull();
  T top();
  int size();
 private:
  T *arr_;
  int capacity_;
  int front_;
  int rear_;
  int count_;
};

#include "Queue.hpp"