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
void buildheapOptimised(vector<int> &heap)
{
  for (int i = heap.size() - 1; i >= 0; i--)
  {
    downheapify(heap, i);
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
  buildheapOptimised(heap);
  display(heap);
  return 0;
}