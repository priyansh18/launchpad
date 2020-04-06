#include <iostream>
using namespace std;
class node
{
public:
  int data;
  node *next;

  node(int d)
  {
    data = d;
    next = NULL;
  }
};
// Passing a pointer variable
void insertionAtHead(node *&head, int data)
{
  node *n = new node(data);
  n->next = head;
  head = n;
}
void print(node *head)
{
  // node *temp = head;
  while (head != NULL)
  {
    cout << head->data << "-->";
    head = head->next;
  }
}
int main()
{
  node *head = NULL;
  insertionAtHead(head, 5);
  insertionAtHead(head, 4);
  insertionAtHead(head, 3);
  insertionAtHead(head, 2);
  print(head);

  return 0;
}