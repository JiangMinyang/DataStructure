#include "red_black_tree.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  RedBlackTree *tree = new RedBlackTree();
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    tree->insert(x);
    tree->print();
  }
  return 0;
}