#pragma once
#include <iostream>
template<class T>
class BinaryTree {
 public:
  BinaryTree() : root_(nullptr) {};

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

template<class K, class V>
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

template<class T>
void BinaryTree<T>::PreOrder(BinaryTree::TreeNode *cur) {
  if (cur) {
    std::cout << cur->data << std::endl;
    PreOrder(cur->left);
    PreOrder(cur->right);
  }
}

template<class T>
void BinaryTree<T>::InOrder(BinaryTree::TreeNode *cur) {
  if (cur) {
    InOrder(cur->left);
    std::cout << cur->data << std::endl;
    InOrder(cur->right);
  }
}

template<class T>
void BinaryTree<T>::PostOrder(BinaryTree::TreeNode *cur) {
  if (cur) {
    PostOrder(cur->left);
    PostOrder(cur->right);
    std::cout << cur->data << std::endl;
  }
}

template<class K, class V>
typename BST<K, V>::TreeNode *&BST<K, V>::_find(TreeNode *&root, K &key) const {
  if (root == nullptr) {
    return root;
  } else if (root->key == key) {
    return root;
  } else if (root->key > key) {
    return _find(root->left, key);
  } else {
    return _find(root->right, key);
  }
}

template<class K, class V>
void BST<K, V>::_insert(BST::TreeNode *&root, K &key, V &value) const {
  TreeNode *&loc = _find(root, key);
  if (loc == nullptr) {
    loc = new TreeNode(key, value);
  }
}

template<class K, class V>
typename BST<K, V>::TreeNode *&BST<K, V>::_ios(BST::TreeNode *&root) const {
  TreeNode *&cur = root;
  while (cur && cur->left != nullptr) cur = cur->left;
  return cur;
}

template<class K, class V>
typename BST<K, V>::TreeNode *&BST<K, V>::_remove(BST::TreeNode *&root,
                                                  K &key) const {
  if (root == nullptr) {
    return root;
  }
  if (key < root->key) {
    root->right = _remove(root->left, key);
  } else if (key > root->key) {
    root->right = _remove(root->right, key);
  } else {
    if (root->left == nullptr) {
      TreeNode *&temp = root->right;
      delete (root);
      return temp;
    } else if (root->right == nullptr) {
      TreeNode *&temp = root->left;
      delete (root);
      return temp;
    }
    TreeNode *&temp = _ios(root->right);
    root->key = temp->key;
    root->right = _remove(root->right, temp->key);
  }
  return root;
}

template<class K, class V>
void BST<K, V>::insert(K key, V value) {
  TreeNode *&loc = _find(root_, key);
  return _insert(loc, key, value);
}

template<class K, class V>
V BST<K, V>::find(K key) {
  TreeNode *&loc = _find(root_, key);
  if (loc == nullptr) {
    std::cout << "not find";
    exit(1);
  } else {
    return loc->value;
  }
}

template<class K, class V>
void BST<K, V>::remove(K key) {
  _remove(root_, key);
}

