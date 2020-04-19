#include <iostream>
#include <vector>
using namespace std;
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
void display(vector<int> &heap)
{
  for (int i = 0; i < heap.size(); i++)
  {
    cout << heap[i] << " ";
  }
  cout << endl;
}
void downheapifyHelper(vector<int> &heap, int index, int heapSize)
{
  int childIndexleft = 2 * index + 1;
  int childIndexright = 2 * index + 2;
  if (childIndexleft >= heapSize && childIndexright >= heapSize)
  {
    return;
  }
  int largestIndex = index;
  if (childIndexleft < heapSize && heap[childIndexleft] > heap[largestIndex])
  {
    largestIndex = childIndexleft;
  }
  if (childIndexright < heapSize && heap[childIndexright] > heap[largestIndex])
  {
    largestIndex = childIndexright;
  }
  if (largestIndex == index)
  {
    return;
  }
  swap(heap[largestIndex], heap[index]);
  downheapifyHelper(heap, largestIndex, heapSize);
}
void buildheapOptimised(vector<int> &heap)
{
  for (int i = heap.size() - 1; i >= 0; i--)
  {
    downheapify(heap, i);
  }
}
void heapSort(vector<int> &arr)
{
  int heapSize = arr.size();
  buildheapOptimised(arr);
  for (int i = arr.size() - 1; i >= 0; i--)
  {
    swap(arr[0], arr[i]);
    heapSize -= 1;
    downheapifyHelper(arr, 0, heapSize);
  }
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
  //time complexity O(nlogn)
  heapSort(heap);
  display(heap);
  return 0;
}