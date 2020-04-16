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
bool search(node *root, int key)
{
  if (root == NULL)
  {
    return false;
  }
  if (root->data == key)
  {
    return true;
  }
  if (key <= root->data)
  {
    search(root->left, key);
  }
  else
  {
    search(root->right, key);
  }
}
void bFS(node *root)
{
  queue<node *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty())
  {
    node *f = q.front();
    if (q.front() == NULL)
    {
      cout << endl;
      q.pop();
      if (!q.empty())
      {
        q.push(NULL);
      }
    }
    else
    {
      cout << f->data << ",";
      q.pop();

      if (f->left)
      {
        q.push(f->left);
      }
      if (f->right)
      {
        q.push(f->right);
      }
    }
  }
  return;
}
int main()
{
  node *root = build();
  bFS(root);
  int s;
  cin >> s;
  if (search(root, s))
  {
    cout << "Present";
  }
  else
  {
    cout << "Not Present";
  }

  return 0;
}