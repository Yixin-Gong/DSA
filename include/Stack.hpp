#include "Stack.h"
#include <iostream>

template<typename T>
Stack<T>::Stack(int size) {
  arr_ = new T[size];
  capacity_ = size;
  top_ = -1;
}

template<typename T>
Stack<T>::~Stack() {
  delete[] arr_;
}

template<typename T>
bool Stack<T>::isEmpty() {
  return top_ == -1;
}

template<typename T>
bool Stack<T>::isFull() {
  return top_ == capacity_ - 1;
}

template<typename T>
T Stack<T>::pop() {
  if (isEmpty()) {
    std::cout << "overflow" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::cout << "removing" << top() << std::endl;
  return arr_[top_--];
}

template<typename T>
void Stack<T>::push(T elem) {
  if (isFull()) {
    std::cout << "overflow" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::cout << "inserting" << elem << std::endl;
  arr_[++top_] = elem;
}

template<typename T>
T Stack<T>::top() {
  if (!isEmpty()) {
    return arr_[top_];
  } else {
    exit(EXIT_FAILURE);
  }
}