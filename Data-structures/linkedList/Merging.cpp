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

void buildList(node *&head, int m)
{
  int data;
  while (m > 0)
  {
    cin >> data;
    insertionAtTail(head, data);
    m--;
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
    cout << head->data << " ";
    head = head->next;
  }
}

int main()
{
  node *head = NULL;
  node *head2 = NULL;
  int m, n, t;
  cin >> t;
  while (t--)
  {
    cin >> m;
    buildList(head, m);
    cin >> n;
    buildList(head2, n);
  }
  head = merge(head, head2);
  print(head);
  return 0;
}