struct Node {
  Node *left, *right;
  Node *parent;
  int value, key;
  Node(int value, Node* parent);
};

class Splay {
private:
  Node *root;
  int treeSize;
  void zig(Node *now);
  void zag(Node *now); 
public:
  Splay();
  void insert(int value);
  bool find(int value);
  void splay(Node *now);
  bool empty();
  void print(int type);
  void print_pre(Node *now, int dep);
  void print_post(Node *now, int dep);
};