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
bool cycleDetection(node *head)
{
  node *fast = head;
  node *slow = head;
  while (fast != NULL && fast->next != NULL)
  {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow)
    {
      return true;
    }
  }
  return false;
}

int main()
{
  node *head = NULL;
  buildList(head);

  int ans = cycleDetection(head);
  if (ans)
  {
    cout << "Cycle Detected";
  }
  else
  {
    cout << "Cycle not present";
  }
  return 0;
}