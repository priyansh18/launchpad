#include <iostream>
#include <list>
using namespace std;
class Queue
{
private:
  int current_size;
  list<int> q;

public:
  Queue(int default_size = 7)
  {
    this->current_size = 0;
  }
  bool isEmpty()
  {
    return this->current_size == 0;
  }
  void enqueue(int data)
  {
    this->q.push_back(data);
    this->current_size += 1;
  }
  void dequeue()
  {
    if (!isEmpty())
    {
      this->current_size -= 1;
      this->q.pop_front();
    }
  }

  int getFront()
  {
    return this->q.front();
  }
};

int main()
{
  Queue q;
  for (int i = 0; i <= 6; i++)
  {
    q.enqueue(i);
  }
  q.dequeue();
  q.enqueue(8);
  while (!q.isEmpty())
  {
    cout << q.getFront() << " ";
    q.dequeue();
  }

  return 0;
}