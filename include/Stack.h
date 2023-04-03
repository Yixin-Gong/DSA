#pragma onces

template<typename T>
class Stack {
 public:
  explicit Stack(int size = 10);
  ~Stack();
  T pop();
  void push(T elem);
  T top();
  bool isEmpty();
  bool isFull();

 private:
  T *arr_;
  int capacity_;
  int top_;
};

#include "Stack.hpp"