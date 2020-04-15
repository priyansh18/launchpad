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
void rightViewUtil(node *root, int level, int *max_level)
{
  // Base Case
  if (root == NULL)
    return;

  // If this is the last Node of its level
  if (*max_level < level)
  {
    cout << root->data << " ";
    *max_level = level;
  }

  // Recur for right subtree first,
  // then left subtree
  rightViewUtil(root->right, level + 1, max_level);
  rightViewUtil(root->left, level + 1, max_level);
}

// A wrapper over rightViewUtil()
void rightView(node *root)
{
  int max_level = 0;
  rightViewUtil(root, 1, &max_level);
}
int main()
{
  node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);
  root->right->left->right = new node(8);
  rightView(root);

  return 0;
}