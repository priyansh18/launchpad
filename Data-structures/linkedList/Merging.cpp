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
void insertionAtTail(node *&head, int data)
{
  if (head == NULL)
  {
    node *n = new node(data);
    head = n;
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

void buildList(node *&head)
{
  int data;
  cin >> data;
  while (data != -1)
  {
    insertionAtTail(head, data);
    cin >> data;
  }
}
node *merge(node *a, node *b)
{
  if (a == NULL)
  {
    return b;
  }
  else if (b == NULL)
  {
    return a;
  }
  node *c;
  if (a->data < b->data)
  {
    c = a;
    c->next = merge(a->next, b);
  }
  else
  {
    c = b;
    c->next = merge(a, b->next);
  }
  return c;
}

void print(node *head)
{
  while (head != NULL)
  {
    cout << head->data << " -> ";
    head = head->next;
  }
}

int main()
{
  node *head = NULL;
  node *head2 = NULL;
  buildList(head);
  buildList(head2);
  head = merge(head, head2);
  print(head);
  return 0;
}