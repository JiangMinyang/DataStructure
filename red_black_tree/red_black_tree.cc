#include "red_black_tree.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

Node* Node :: getGrandparent() {
  if (this->parent == NULL) return NULL;
  return this->parent->parent;
}

Node* Node :: getUncle() {
  if (this->getGrandparent() == NULL) return NULL;
  if (this->parent == this->getGrandparent()->left) return this->getGrandparent()->right;
  return this->getGrandparent()->left;
}


RedBlackTree :: RedBlackTree() {
  this->root = NULL;
}

RedBlackTree :: ~RedBlackTree() {
  delete this->root;
}

void RedBlackTree :: insert(int key) {
  this->insert(key, 0);
}

void RedBlackTree :: insert(int key, int value) {
  if (root == NULL) {
    root = new Node(key, value, NULL, 0); 
    return;
  }
  Node *now = root;
  while (true) {
    if (now->key > key) {
      if (now->left == NULL) {
        now->left = new Node(key, value, now, 1);
        now = now->left;
        break;
      }
      else {
        now = now->left;
      }
    }
    else {
      if (now->right == NULL) {
        now->right = new Node(key, value, now, 1);
        now = now->right;
        break;
      }
      else {
        now = now->right;
      }
    }
  }
  RBFix(now);
}

void RedBlackTree :: leftRotate(Node *y) {
  Node *x = y->right;
  y->right = x->left;
  if (x->left != NULL) {
    x->left->parent = y;
  }
  x->left = y;
  x->parent = y->parent;
  if (y->parent == NULL) {
    root = x;
  } else {
    if (y->parent->left == y) {
      y->parent->left = x;
    }
    else {
      y->parent->right = x;
    }
  }
  y->parent = x;
}

void RedBlackTree :: rightRotate(Node *y) {
  Node *x = y->left;
  y->left = x->right;
  if (x->right != NULL) {
    x->right->parent = y;
  }
  x->right = y;
  x->parent = y->parent;
  if (y->parent == NULL) {
    root = x;
  } else {
    if (y->parent->left == y) {
      y->parent->left = x;
    }
    else {
      y->parent->right = x;
    }
  }
  y->parent = x;
}

void RedBlackTree :: RBFix(Node *now) {
  //now is not root and parent of now is red
  while (now->parent != NULL && now->parent->type) {
    Node *grandparent = now == NULL ? NULL : now->getGrandparent();
    Node *uncle = now == NULL ? NULL : now->getUncle();
    if (uncle != NULL && uncle->type) {
      grandparent->type = true;
      uncle->type = now->parent->type = false;
      now = grandparent;
      continue;
    }
    else {
      if (now->parent->right == now) {
        now = now->parent;
        leftRotate(now);
        continue;
      }
      else {
        now->parent->type = false;
        grandparent->type = true;
        now = grandparent;
        rightRotate(grandparent);
        continue;
      }
    }
  }
  if (root != NULL) {
    root->type = false;
  }
}

Node* RedBlackTree :: find(int key) {
  Node *now = root;
  while(true) {
    if (now->key == NULL) return NULL;
    if (now->key == key) break;
    if (now->key > key) {
      now = now->left;
    }
    else {
      now = now->right;
    }
  }
  return now;
}
Node* RedBlackTree :: findPre(Node *now) {
  if (now->left == NULL) return NULL;
  Node *pre = now->left;
  while (pre->right != NULL) {
    pre = pre->right;
  }
  return pre;
} 
bool RedBlackTree :: contains(int key) {
  return find(key) != NULL;
}
bool RedBlackTree :: remove(int key);

void RedBlackTree :: print() {
  print(root, 0);
}

void RedBlackTree :: print(Node *now, int dep) {
  if (now == NULL) return;
  print(now->left, dep + 1);
  cout << now->key << " " << (now->type ? "red" : "black") << " " << dep << endl;
  print(now->right, dep + 1);
}