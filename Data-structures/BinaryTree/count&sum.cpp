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
int count(node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  return 1 + count(root->left) + count(root->right);
}
int sum(node *root)
{
  int mySum;
  if (root == NULL)
  {
    mySum = 0;
    return 0;
  }
  int leftSum = sum(root->left);   // Solve smaller problem 1
  int rightSum = sum(root->right); // Solve smaller problem 2

  mySum = root->data + leftSum + rightSum;
  // Solve my problem using
  // solution of smaller problem

  return mySum; // Return solution
}

int main()
{
  node *root = buildTree();
  cout << count(root) << endl;
  cout << sum(root) << endl;
  return 0;
}