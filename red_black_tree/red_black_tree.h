#include <cstdio>
struct Node {
  Node *left, *right;
  Node *parent;
  int key, value;
  bool type; // true : red, false : black
  Node(int key, int value, Node *parent, bool type) : key(key), value(value), type(type), parent(parent), left(NULL), right(NULL) {}
  Node(int key, Node *parent, bool type) : key(key), type(type), parent(parent), left(NULL), right(NULL) {}
  ~Node() {
    delete this->left;
    delete this->right;
  }
  Node* getGrandparent();
  Node* getUncle();
};

class RedBlackTree {
private:
  Node *root;
  int treeSize;
  void leftRotate(Node *x);
  void rightRotate(Node *x);
  void RBFix(Node *x);
  void print(Node *now, int dep);
  Node* find(int key);
  Node* findPre(Node *now); 
  void fixUp(Node *now);
public:
  RedBlackTree();
  ~RedBlackTree();
  bool contains(int key);
  bool remove(int key);
  void insert(int key);
  void insert(int key, int value);
  void print();
};
