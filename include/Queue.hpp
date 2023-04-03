#include "Queue.h"
#include <iostream>

template<typename T>
int Queue<T>::size() {
  return count_;
}

template<typename T>
T Queue<T>::top() {
  if (isEmpty()) {
    std::cout << "underflow" << std::endl;
    exit(EXIT_FAILURE);
  }
  return arr_[front_];
}

template<typename T>
bool Queue<T>::isFull() {
  return (size() == capacity_);
}

template<typename T>
bool Queue<T>::isEmpty() {
  return (size() == 0);
}

template<typename T>
void Queue<T>::enqueue(T elem) {
  if (isFull()) {
    std::cout << "overflow" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::cout << "inserting" << elem << std::endl;
  rear_ = (rear_ + 1) % capacity_;
  arr_[rear_] = elem;
  count_++;
}

template<typename T>
T Queue<T>::dequeue() {
  T elem = arr_[front_];
  std::cout << "removing" << elem << std::endl;
  front_ = (front_ + 1) % capacity_;
  count_--;
  return elem;
}

template<typename T>
Queue<T>::~Queue() {
  delete[] arr_;
}

template<typename T>
Queue<T>::Queue(int size) {
  arr_ = new T[size];
  capacity_ = size;
  front_ = 0;
  rear_ = -1;
  count_ = 0;
}