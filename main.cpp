//
// Created by eric on 1/31/23.
//
#include "List/List.h"
#include <iostream>
int main() {
  List<int> list;
  list.insert(1, 3);
  std::cout << list[0];
  return 0;
}