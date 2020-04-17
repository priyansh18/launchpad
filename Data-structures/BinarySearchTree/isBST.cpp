#include <iostream>
#include <queue>
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
bool isBST(node *root, int minV = INT8_MIN, int maxV = INT8_MAX)
{
  if (root == NULL)
  {
    return true;
  }
  if (root->data >= minV && root->data <= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV))
  {
    return true;
  }
  return false;
}
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
int main()
{
  node *root = buildTree();
  if (isBST(root))
  {
    cout << "BST";
  }
  else
  {
    cout << "Not a BST";
  }
  return 0;
}