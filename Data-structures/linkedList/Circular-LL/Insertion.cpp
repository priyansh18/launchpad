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
void print(node *head)
{
  node *temp = head;
  while (temp->next != head)
  {
    cout << temp->data << "-->";
    temp = temp->next;
  }
  cout << temp->data;
}
void insertionAtHead(node *&head, int data)
{
  node *n = new node(data);
  n->next = head;
  node *temp = head;
  if (head != NULL)
  {
    while (temp->next != head)
    {
      temp = temp->next;
    }
    temp->next = n;
  }
  else
  {
    n->next = n;
  }
  head = n;
}
int main()
{
  node *head = NULL;
  insertionAtHead(head, 5);
  insertionAtHead(head, 4);
  insertionAtHead(head, 3);
  insertionAtHead(head, 2);
  insertionAtHead(head, 1);
  print(head);

  return 0;
}