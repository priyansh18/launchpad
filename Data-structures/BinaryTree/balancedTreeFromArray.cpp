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
node *balanceTree(int a[], int start, int end)
{
  if (start > end)
  {
    return NULL;
  }
  int mid = (start + end) / 2;
  node *root = new node(a[mid]);
  root->left = balanceTree(a, start, mid - 1);
  root->right = balanceTree(a, mid + 1, end);

  return root;
}

int main()
{
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  node *root = balanceTree(a, 0, n - 1);
  bFS(root);
  return 0;
}