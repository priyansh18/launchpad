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
void BinaryTree2DoubleLinkedList(node *root, node **head)
{
  // Base case
  if (root == NULL)
  {
    return;
  }
  node *prev = NULL;
  // Recursively convert left subtree
  BinaryTree2DoubleLinkedList(root->left, head);

  if (prev == NULL)
    *head = root;
  else
  {
    root->left = prev;
    prev->right = root;
  }
  prev = root;

  // Finally convert right subtree
  BinaryTree2DoubleLinkedList(root->right, head);
}
void printList(node *node)
{
  while (node != NULL)
  {
    cout << node->data << " ";
    node = node->right;
  }
}
int main()
{
  node *root = buildTreeLevelOrder();
  // Convert to DLL
  node *head = NULL;
  BinaryTree2DoubleLinkedList(root, &head);

  // Print the converted list
  printList(head);

  return 0;
}