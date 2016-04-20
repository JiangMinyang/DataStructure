#include "splay.h"
#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

Node::Node(int key, Node* parent) {
  this->key = key;
  this->parent = parent;
  this->left = this->right = NULL;
}

Splay::Splay() {
  root = NULL;
  treeSize = 0;
}
void Splay::insert(int key) {
  if (root == NULL) {
    root = new Node(key, NULL);
    return;
  }
  Node *now = root;
  while (true) {
    if (now->key > key) {
      if (now->left == NULL) {
        now->left = new Node(key, now);
        now = now->left;
        break;
      }
      now = now->left;
    }
    else {
      if (now->right == NULL) {
        now->right = new Node(key, now);
        now = now->right;
        break;
      }
      now = now->right;
    }
  }
  treeSize++;
  splay(now);
}
bool Splay::find(int key) {
  Node *now = root;
  while (true) {
    if (now == NULL) {
      return false;
    }
    if (now->key == key) {
      break;
    }
    if (now->key > key) {
      now = now->left;
    }
    else {
      now = now->right;
    }
  }
  splay(now);
  return true;
}
void Splay::splay(Node *now) {
  while (now->parent != NULL) {
    if (now->parent->parent == NULL) {
      now->parent->left == now ? zig(now) : zag(now);
      break;
    }
    if (now->parent->parent->left == now->parent) {
      if (now->parent->left == now) {
        zig(now); zig(now);
      }
      else {
        zag(now); zig(now);
      }
    }
    else {
      if (now->parent->left == now) {
        zig(now); zag(now);
      }
      else {
        zag(now); zag(now);
      }
    }
  }
}
void Splay::zig(Node *x) {
  Node *y = x->parent;
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
void Splay::zag(Node *x) {
  Node *y = x->parent;
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
bool Splay::empty() {
  return root == NULL;
}

void Splay::print(int type) {
  if (type == 0) {
    print_in(root, 0);
  } else {
    print_post(root, 0);
  }
}

void Splay::print_in(Node *now, int dep) {
  if (now == NULL) return;
  print_in(now->left, dep + 1);
  cout << now->key << " " << dep << endl;
  print_in(now->right, dep + 1);
}

void Splay::print_post(Node *now, int dep) {
  if (now == NULL) return;
  print_post(now->left, dep + 1);
  print_post(now->right, dep + 1);
  cout << now->key << " " << dep << endl;
}