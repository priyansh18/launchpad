#include <iostream>
#include <vector>
#include <map>
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

// 'hd' is horigontal distance of current node from root.
// 'hd' is initially passed as 0
void getVerticalOrder(node *root, int hd, map<int, vector<int>> &m)
{
  // Base case
  if (root == NULL)
    return;

  // Store current node in map 'm'
  m[hd].push_back(root->data);

  // Store nodes in left subtree
  getVerticalOrder(root->left, hd - 1, m);

  // Store nodes in right subtree
  getVerticalOrder(root->right, hd + 1, m);
}

void printVerticalOrder(node *root)
{
  map<int, vector<int>> m;
  int hd = 0;
  getVerticalOrder(root, hd, m);

  // Traverse the map and print nodes at every horigontal
  // distance (hd)
  map<int, vector<int>>::iterator it;
  for (it = m.begin(); it != m.end(); it++)
  {
    for (int i = 0; i < it->second.size(); ++i)
    {
      cout << it->second[i] << " ";
    }
    cout << endl;
  }
}

int main()
{
  int n;
  cin >> n;
  node *root = buildTreeLevelOrder();
  printVerticalOrder(root);
  return 0;
}