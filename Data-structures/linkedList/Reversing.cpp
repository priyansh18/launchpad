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

void reverse(node *&head)
{

  if (head == NULL)
  {
    return;
  }
  node *current = head;
  node *previous = NULL;
  node *n;
  while (current != NULL)
  {
    // Save the next node
    n = current->next;
    // Make the current node point to previous
    current->next = previous;
    // Update previous and current
    previous = current;
    current = n;
  }
  head = previous;
}
node *reverseRec(node *head)
{
  //Base case
  if (head->next == NULL || head == NULL)
  {
    return head;
  }
  // Recursive case
  node *smallhead = reverseRec(head->next);
  //making head as current
  node *c = head;
  c->next->next = c;
  c->next = NULL;
  return smallhead;
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
  buildList(head);
  print(head);
  cout << endl;
  reverse(head);
  print(head);
  cout << endl;
  head = reverseRec(head);
  print(head);
  return 0;
}