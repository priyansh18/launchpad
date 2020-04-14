#include <iostream>
using namespace std;
class node
{
public:
  int data;
  node *left;
  node *right;

  node(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};
class HBPair
{
public:
  int height;
  bool balance;
};

node *buildTree()
{
  int d;
  cin >> d;

  if (d == -1)
  {
    return NULL;
  }
  node *root = new node(d);
  root->left = buildTree();
  root->right = buildTree();
}
HBPair isBalanced(node *root)
{
  HBPair p;
  if (root == NULL)
  {
    p.height = 0;
    p.balance = true;
    return p;
  }
  HBPair left = isBalanced(root->left);
  HBPair right = isBalanced(root->right);

  p.height = max(left.height, right.height) + 1;

  if (abs(left.height - right.height) <= 1 && left.balance && right.balance)
  {
    p.balance = true;
  }
  else
  {
    p.balance = false;
  }
  return p;
}

int main()
{
  node *root = buildTree();
  if (isBalanced(root).balance)
  {
    cout << "Balanced";
  }
  else
  {
    cout << "Not Balanced";
  }

  return 0;
}