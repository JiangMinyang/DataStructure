#include "splay.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  Splay* tree = new Splay();
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    tree->insert(x);
    tree->print(0);
    cout << "----------------" << endl;
  }
  for(int i = 0; i < m; i++) {
    int x;
    cin >> x;
    tree->find(x);
    tree->print(0);
    cout << "----------------" << endl;
  }
  return 0;
}