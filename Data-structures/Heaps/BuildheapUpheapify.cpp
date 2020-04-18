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
void buildheap(vector<int> &heap)
{
  for (int i = 0; i < heap.size(); i++)
  {
    upheapify(heap, i);
  }
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
  // time take O(nlogn)
  vector<int> heap;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    heap.push_back(x);
  }
  buildheap(heap);
  display(heap);
  return 0;
}