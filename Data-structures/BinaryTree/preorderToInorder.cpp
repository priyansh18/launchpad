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
node *preToIn(int in[], int pre[], int start, int end)
{
  static int i = 0;
  if (start > end)
  {
    return NULL;
  }
  node *root = new node(pre[i]);
  int index = -1;

  for (int j = start; j <= end; j++)
  {
    if (in[j] == pre[i])
    {
      index = j;
      break;
    }
  }
  i++;
  root->left = preToIn(in, pre, start, index - 1);
  root->right = preToIn(in, pre, index + 1, end);
  return root;
}
int main()
{
  int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
  int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
  int n = sizeof(in) / sizeof(int);

  node *root = preToIn(in, pre, 0, n - 1);
  bFS(root);
  return 0;
}