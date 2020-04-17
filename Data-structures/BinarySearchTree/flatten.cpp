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
node *insertInBST(node *root, int d)
{
  if (root == NULL)
  {
    return new node(d);
  }
  if (d >= root->data)
  {
    root->right = insertInBST(root->right, d);
  }
  else
  {
    root->left = insertInBST(root->left, d);
  }

  return root;
}
node *build()
{
  int d;
  cin >> d;
  node *root = NULL;
  while (d != -1)
  {
    root = insertInBST(root, d);
    cin >> d;
  }
  return root;
}
class LinkedList
{
public:
  node *head;
  node *tail;
};
LinkedList flatten(node *root)
{
  LinkedList l;
  if (root == NULL)
  {
    l.head = l.tail = NULL;
    return l;
  }
  // 1. Leaf Node
  if (root->left == NULL && root->right == NULL)
  {
    l.head = l.tail = root;
    return l;
  }
  // 2. left is not null
  if (root->left != NULL && root->right == NULL)
  {
    LinkedList leftLL = flatten(root->left);
    leftLL.tail->right = root;
    l.head = leftLL.head;
    l.tail = root;
    return l;
  }
  // 3. right is not null
  if (root->left == NULL && root->right != NULL)
  {
    LinkedList rightLL = flatten(root->right);
    root->right = rightLL.head;
    l.head = root;
    l.tail = rightLL.tail;
    return l;
  }
  LinkedList leftLL = flatten(root->left);
  LinkedList rightLL = flatten(root->right);
  leftLL.tail->right = root;
  root->right = rightLL.head;
  l.head = leftLL.head;
  l.tail = rightLL.tail;
  return l;
}
int main()
{
  node *root = build();
  LinkedList l = flatten(root);
  node *temp = l.head;
  while (temp != NULL)
  {
    cout << temp->data << "--> ";
    temp = temp->right;
  }
  cout << endl;
  return 0;
}