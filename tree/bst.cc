#include <iostream>
#include <queue>


struct Node {
  int data;
  Node* left;
  Node* right;
  Node() : left(NULL), right(NULL) {};
  Node(int val): left(NULL), right(NULL), data(val) {};
};

class BST {
public:
  BST(int val);
  void printtree();
  void insert(int val);
  bool search(int val);
  void remove(int val);
  int min();
  int max();
  int findheight();
  void printLevelOrder();
  bool isBST();

private:
  Node* _root;
  void _add(Node* node, int data);
  void _print(Node* node);
  bool _search(Node* node, int val);
  void _remove(Node* node, int val);
  int _min(Node* node);
  int _max(Node* node);
  int _findheight(Node* node);
  void _printLevelOrder(std::queue<Node *>& q);
  bool _isBST(Node* node);
};

BST::BST(int val) {
  _root = new Node(val);
}

bool BST::isBST() {
  return _isBST(_root);
}

bool BST::_isBST(Node* node) {
  bool l = true; bool r = true;
  if (node) {
    if (node->left) 
      l = (node->left->data <= node->data) &&  _isBST(node->left);
    if (node->right)
      r = (node->data < node->right->data) && _isBST(node->right);
    return l && r;
  }
  return true;
}

void BST::_print(Node* node) {
  if (node) {
    std::cout << node->data << ", ";
    _print(node->left);
    _print(node->right);
  }
}

void BST::printtree() {
  _print(_root);
}

void BST::printLevelOrder() {
  if (!_root) return;
  std::queue<Node *> q;
  q.push(_root);
  _printLevelOrder(q);
}

void BST::_printLevelOrder(std::queue<Node *>& q) {
  if (q.size() == 0) {
    return;
  }
  else {
    Node* n = q.front();
    if (n->left) q.push(n->left);
    if (n->right) q.push(n->right);
    std::cout << n->data << ", ";
    q.pop();
    _printLevelOrder(q);
  }
}


void BST::_add(Node* node, int val) {
  if (!node) { // node is null)
    return;
  }
  else if (val > node->data) { // go right
    _add(node->right, val); 
    if (!node->right) {
      Node* n = new Node(val);
      node->right = n;
    }
  }
  else {
    _add(node->left, val);
    if (!node->left) {
      Node* n = new Node(val);
      node->left = n;
    }
  }
  return;
}

void BST::insert(int val) {
  _add(_root, val);
}

bool BST::search(int val) {
  return _search(_root, val);
}

bool BST::_search(Node* node, int val) {
  if (!node) {
    return false;
  }
  if (val == node->data) {
    return true;
  }
  else if (val > node->data) {
    return _search(node->right, val);
  }
  else {
    return _search(node->left, val);
  }
}

int BST::max() {
  return _max(_root);
}

int BST::_max(Node* node) {
  if (!node) {
    return -1;
  }
  else if (! node->right) {
    return node->data;
  }
  else {
    return _max(node->right);
  }
}

int BST::min() {
  return _min(_root);
}

int BST::_min(Node* node) {
  if (!node) {
    return -1;
  }
  else if (! node->left) {
    return node->data;
  }
  else {
    return _min(node->left);
  }
}

int BST::findheight() {
  return _findheight(_root);
}

int BST::_findheight(Node* node) {
  if (!node) {
    return -1;
  }
  else { // non leaf node
    int l = _findheight(node->left);
    int r = _findheight(node->right);
    if (l > r) 
      return 1 + l;
    else
      return 1 + r;   
  }
}


void BST::remove(int val) {
  return _remove(_root, val);
}

void BST::_remove(Node* node, int val) {
  // case 1: no child
  // case 2: one child
  // case 3: 2 children
  if (!node) {
    return;
  }
  else if (!node->left && !node->right) { // no child) 

  }
  else if (node->left || node->right) { // one child

  }
  else { // 2 children

  }
}

int main() {
  BST bst(15);
  bst.insert(10);
  bst.insert(20);
  bst.insert(8);
  bst.insert(12);
  bst.insert(17);
  bst.insert(25);

  bst.printtree(); std::cout << std::endl;

  std::cout << "Searching 20 = " << bst.search(20) << std::endl;
  std::cout << "Searching 22 = " << bst.search(22) << std::endl;

  std::cout << "Min = " << bst.min() << std::endl;
  std::cout << "Max = " << bst.max() << std::endl;
  std::cout << "Height = " << bst.findheight() << std::endl;

  std::cout << "level order traversal:" << std::endl;
  bst.printLevelOrder(); std::cout << std::endl;

  std::cout << "is BST = " << bst.isBST() << std::endl;
  return 0;
}
