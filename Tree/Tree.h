#pragma once

template <class T>
class BinaryTree {
 public:
  BinaryTree() : root_(nullptr){};

 private:
  struct TreeNode {
    T data;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
  };
  TreeNode *root_;
  void PreOrder(TreeNode *cur);
  void InOrder(TreeNode *cur);
  void PostOrder(TreeNode *cur);
};

template <class K, class V>
class BST {
 public:
  BST() : root_(nullptr) {}
  void insert(K key, V value);
  void remove(K key);
  V find(K key);

 private:
  struct TreeNode {
    K key;
    V value;
    TreeNode *left, *right;
    explicit TreeNode(K key, V value)
        : key(key), value(value), left(nullptr), right(nullptr) {}
  };
  TreeNode *root_;

  TreeNode *&_ios(TreeNode *&root) const;
  TreeNode *&_find(TreeNode *&root, K &key) const;
  TreeNode *&_remove(TreeNode *&root, K &key) const;
  void _insert(BST::TreeNode *&root, K &key, V &value) const;
};

#include "Tree.hpp"
