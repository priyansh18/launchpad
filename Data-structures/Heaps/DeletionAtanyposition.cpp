#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &heap)
{
  for (int i = 0; i < heap.size(); i++)
  {
    cout << heap[i] << " ";
  }
  cout << endl;
}

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
void downheapify(vector<int> &heap, int index)
{
  int childIndexleft = 2 * index + 1;
  int childIndexright = 2 * index + 2;
  if (childIndexleft >= heap.size() && childIndexright >= heap.size())
  {
    return;
  }
  int largestIndex = index;
  if (childIndexleft < heap.size() && heap[childIndexleft] > heap[largestIndex])
  {
    largestIndex = childIndexleft;
  }
  if (childIndexright < heap.size() && heap[childIndexright] > heap[largestIndex])
  {
    largestIndex = childIndexright;
  }
  if (largestIndex == index)
  {
    return;
  }
  swap(heap[largestIndex], heap[index]);
  downheapify(heap, largestIndex);
}

void deletePosition(vector<int> &heap, int key)
{
  for (int i = 0; i < heap.size(); i++)
  {
    if (heap[i] == key)
    {
      heap[i] = 1e9;

      upheapify(heap, i);
      swap(heap[0], heap[heap.size() - 1]);
      heap.pop_back();
      downheapify(heap, 0);
    }
  }
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

  int key;
  cin >> key;
  deletePosition(heap, key);
  display(heap);
  return 0;
}