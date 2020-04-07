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
void print(node *head)
{
  while (head != NULL)
  {
    cout << head->data << " -> ";
    head = head->next;
  }
}
node *kthnode(node *head, int k)
{
  if (head->next == NULL || head == NULL)
  {
    return head;
  }
  node *slow = head;
  node *fast = head;
  while (k > 0)
  {
    fast = fast->next;
    k--;
  }
  while (fast != NULL)
  {
    fast = fast->next;
    slow = slow->next;
  }
  return slow;
}

int main()
{
  node *head = NULL;
  buildList(head);
  print(head);
  node *m = kthnode(head, 4);
  cout << endl;
  cout << "Kth node : " << m->data;
  cout << endl;
  return 0;
}