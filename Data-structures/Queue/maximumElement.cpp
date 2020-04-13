#include <iostream>
#include <deque>
using namespace std;
void printMax(int *arr, int n, int k)
{
  deque<int> q;
  int i;
  for (i = 0; i < k; i++)
  {
    while (!q.empty() && arr[i] > arr[q.back()])
    {
      q.pop_back();
    }
    q.push_back(i);
  }
  for (; i < n; i++)
  {
    cout << arr[q.front()] << " ";
    while ((!q.empty()) && (q.front() <= i - k))
    {
      q.pop_front();
    }
    while ((!q.empty()) && (arr[i] >= arr[q.back()]))
    {
      q.pop_back();
    }
    q.push_back(i);
  }
  cout << arr[q.front()];
}

int main()
{
  int n;
  cin >> n;
  int arr[10000];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int k;
  cin >> k;
  printMax(arr, n, k);
  return 0;
}