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
node *deleteInBST(node *root, int key)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (key > root->data)
  {
    root->right = deleteInBST(root->right, key);
    return root;
  }
  else if (key == root->data)
  {
    //1.root is having no childen
    if (root->right == NULL && root->left == NULL)
    {
      delete root;
      return NULL;
    }
    // 2.root is having 1 child
    if (root->right != NULL && root->left == NULL)
    {
      node *temp = root->right;
      delete root;
      return temp;
    }
    if (root->right == NULL && root->left != NULL)
    {
      node *temp = root->left;
      delete root;
      return temp;
    }
    //3.root is having both children
    node *replace = root->right;
    while (replace->left != NULL)
    {
      replace = replace->left;
    }
    root->data = replace->data;
    root->right = deleteInBST(root->right, replace->data);
    return root;
  }
  else
  {
    root->left = deleteInBST(root->left, key);
    return root;
  }
}
int main()
{
  node *root = build();
  bFS(root);
  int s;
  cin >> s;
  // if (search(root, s))
  // {
  //   cout << "Present";
  // }
  // else
  // {
  //   cout << "Not Present";
  // }
  deleteInBST(root, s);
  bFS(root);

  return 0;
}