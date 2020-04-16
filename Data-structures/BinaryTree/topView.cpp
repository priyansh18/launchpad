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

// A wrapper over rightViewUtil()
void topView(node *root)
{
  node *temp1 = root;
  while (temp1->left != NULL)
  {
    temp1 = temp1->left;
  }
  cout << temp1->data;
  node *temp2 = root;
  while (temp2->right != NULL)
  {
    temp2 = temp2->right;
  }
  cout << temp2->data;
}
int main()
{
  node *root = buildTreeLevelOrder();
  topView(root);
  return 0;
}