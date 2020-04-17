
#include <bits/stdc++.h>
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
// function to create a new node
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

void topView(node *root)
{
  // Base case
  if (root == NULL)
  {
    return;
  }

  // Take a temporary node
  node *temp = NULL;

  // Queue to do BFS
  queue<pair<node *, int>> q;

  // map to store node at each vartical distance
  map<int, int> mp;

  q.push({root, 0});

  // BFS
  while (!q.empty())
  {

    temp = q.front().first;
    int d = q.front().second;
    q.pop();

    // If any node is not at that vertical distance
    // just insert that node in map and print it
    if (mp.find(d) == mp.end())
    {
      cout << temp->data << " ";
      mp[d] = temp->data;
    }

    // Continue for left node
    if (temp->left)
    {
      q.push({temp->left, d - 1});
    }

    // Continue for right node
    if (temp->right)
    {
      q.push({temp->right, d + 1});
    }
  }
}

// Driver Program to test above functions
int main()
{
  node *root = buildTreeLevelOrder();
  cout << "Following are nodes in top view of Binary Tree\n";
  topView(root);
  return 0;
}