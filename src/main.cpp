//
// Created by eric on 1/31/23.
//
#include "../include/List.hpp"
#include <iostream>
int main() {
  List<int> list;
  list.insert(1, 3);
  std::cout << list[0] << std::endl;
  return 0;
}
