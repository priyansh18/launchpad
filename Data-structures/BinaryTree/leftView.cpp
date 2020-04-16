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
node *buildTreeLevelOrder()
{
  queue<node *> q;
  int data, data2;
  cin >> data;
  node *root = new node(data);
  q.push(root);
  while (!q.empty())
  {
    node *temp = q.front();
    q.pop();
    cin >> data >> data2;

    if (data != -1)
    {
      temp->left = new node(data);
      q.push(temp->left);
    }
    else
    {
      temp->left = NULL;
    }

    if (data2 != -1)
    {
      temp->right = new node(data2);
      q.push(temp->right);
    }
    else
    {
      temp->right = NULL;
    }
  }
  return root;
}

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
  rightViewUtil(root->left, level + 1, max_level);
  rightViewUtil(root->right, level + 1, max_level);
}

// A wrapper over rightViewUtil()
void rightView(node *root)
{
  int max_level = 0;
  rightViewUtil(root, 1, &max_level);
}
int main()
{
  node *root = buildTreeLevelOrder();
  rightView(root);
  return 0;
}