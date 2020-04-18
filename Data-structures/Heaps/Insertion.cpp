#include <iostream>
#include <vector>
using namespace std;
void upheapify(vector<int> &heap, int index)
{
  if (index == 0)
  {
    return;
  }
  int parentIndex = (index - 1) / 2;
  if (heap[parentIndex] < heap[index])
  {
    swap(heap[parentIndex], heap[index]);
    upheapify(heap, parentIndex);
  }
  else
  {
    return;
  }
}
void insert(vector<int> &heap, int key)
{
  heap.push_back(key);
  upheapify(heap, heap.size() - 1);
}
void display(vector<int> &heap)
{
  for (int i = 0; i < heap.size(); i++)
  {
    cout << heap[i] << " ";
  }
  cout << endl;
}
int main()
{
  vector<int> heap;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    insert(heap, x);
  }
  display(heap);
  return 0;
}