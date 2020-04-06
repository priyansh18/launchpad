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
int length(node *head)
{
  int len = 0;
  while (head != NULL)
  {
    head = head->next;
    len = len + 1;
  }
  return len;
}
void insertionAtHead(node *&head, int data)
{
  node *n = new node(data);
  n->next = head;
  head = n;
}
void insertionAtTail(node *&head, int data)
{
  if (head == NULL)
  {
    node *n = new node(data);
    return;
  }
  node *tail = head;
  while (tail->next != NULL)
  {
    tail = tail->next;
  }
  node *n = new node(data);
  tail->next = n;
  return;
}
void insertionAtMiddle(node *&head, int data, int p)
{
  if (head == NULL || p == 0)
  {
    insertionAtHead(head, data);
  }
  else if (p > length(head))
  {
    insertionAtTail(head, data);
  }
  else
  {
    int jump = 1;
    node *temp = head;
    while (jump <= p - 1)
    {
      temp = temp->next;
      jump += 1;
    }
    node *n = new node(data);
    n->next = temp->next;
    temp->next = n;
  }
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
  insertionAtHead(head, 1);
  insertionAtTail(head, 6);
  insertionAtMiddle(head, 2, 1);

  print(head);

  return 0;
}