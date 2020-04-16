#include <iostream>
#include <vector>
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

void findPath(node *root, int a, vector<int> &v)
{
  if (root == NULL)
  {
    return;
  }

  if (root->data == a)
  {
    v.push_back(a);
  }

  vector<int> leftArr;
  vector<int> rightArr;
  findPath(root->left, a, leftArr);
  findPath(root->right, a, rightArr);

  if (leftArr.size() != 0)
  {
    v.push_back(root->data);
    for (int x : leftArr)
    {
      v.push_back(x);
    }
    return;
  }

  if (rightArr.size() != 0)
  {
    v.push_back(root->data);
    for (int x : rightArr)
    {
      v.push_back(x);
    }
    return;
  }
}

void lca(node *root, int a, int b)
{

  // path a

  vector<int> arra;
  vector<int> arrb;
  findPath(root, a, arra);
  findPath(root, b, arrb);

  for (int x : arra)
  {
    cout << x << " ";
  }
  cout << endl;
  for (int x : arrb)
  {
    cout << x << " ";
  }
  cout << endl;
  // common prefix
  // reutnr ans
}

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

int main()
{
  node *root = buildTreeLevelOrder();
  lca(root, 4, 7);
  return 0;
}